# expr parser
import re

class Expr():
    def __init__(self):
        pass

##    def validXZ(self, val):
##        return all([i in 'xXzZ?' for i in val])
##
##    def validDigit(self, val, imin, imax):
##        return all([(imin <= i <= imax) or self.validXZ(i) for i in val])
##
##    def validSize(self, val):
##        return all(['1' <= i <= '9' for i in val])
##
##    def validHexBase(self, val):
##        return all([i in "'sShH" for i in val])
##
##    def validBinBase(self, val):
##        return all([i in "'sSbB" for i in val])
##
##    def validOctBase(self, val):
##        return all([i in "'sSoO" for i in val])
##
##    def validDecBase(self, val):
##        return all([i in "'sSdD" for i in val])
##
##    def validHexDigit(self, val):
##        return all(['0' <= i <= '9' or 'a' <= i <= 'f' or 'A' <= i <= 'F' or self.validXZ(i) for i in val])
##
##    def validBinDigit(self, val):
##        return self.validDigit(val, '0', '1')
##
##    def validOctDigit(self, val):
##        return self.validDigit(val, '0', '7')
##
##    def validDecDigit(self, val):
##        return all(['0' <= i <= '9' for i in val])

    def sanitizeVal(self, val):
        tmp = val.replace('_', '')
        return tmp

    def validValRE(self, val):
        # remove '_' for easy regex
        val = self.sanitizeVal(val)
        if not val: return False
        value = re.compile(r"""
                      (?P<decplain>^[1-9][0-9]*$)                          # plain dec number
                    | (?P<decxz>^([1-9][0-9]*)?'[sS]?[dD][xXzZ?]$)         # dec number dont care
                    | (?P<dec>^([1-9][0-9]*)?'[sS]?[dD][0-9]+$)            # dec number
                    | (?P<bin>^([1-9][0-9]*)?'[sS]?[bB][xXzZ?01]+$)        # bin number
                    | (?P<oct>^([1-9][0-9]*)?'[sS]?[oO][xXzZ?0-7]+$)       # oct number
                    | (?P<hex>^([1-9][0-9]*)?'[sS]?[hH][xXzZ?a-fA-F0-9]+$) # hex number
                """, re.VERBOSE)
        return value.match(val)

    def validSigRE(self, val):
        value = re.compile(r"""
                      (?P<simpleveri>^[a-zA-Z_][a-zA-Z0-9_$]*$)     # plain verilog identifier
                    | (?P<escapedveri>^\\[^ ]*[ ]$)                 # escaped verilog identifier
                    | (?P<simplevhdl>^[a-zA-Z][a-zA-Z0-9_]$)        # plain vhdl identifier
                    | (?P<extendedvhdl>^\\.*\\$)                    # escaped vhdl identifier
                """, re.VERBOSE)
        return value.match(val)


# test regex for 'value'
for i in ["32'hC800", "8'b1010_0001", "100279", "8'b101?_????", "32'h????0001"]:
    m = Expr().validValRE(i)
    print m.group('decplain'), m.group('decxz'), m.group('dec'), m.group('bin'), m.group('oct'), m.group('hex')

for i in ["hC800", "b10$0_0001", "\\jskfsf\\anf ", "\\8'b101?_???? ", "\\h?? ??0001\\", "\\a\\\\b\\"]:
    #["\\sjkadfn .\\skfmsfd\\.\\sdflkmd ", "sjkadfn.\\skfmsfd\\.\\sdflkmd ", "sjkadfn.\\skfmsfd .\\sdflkmd\\", "\\sjkadfn\\.\\skfmsfd .\\sdflkmd\\"]:
    m = Expr().validSigRE(i)
    print m.group('simpleveri'), m.group('escapedveri'), m.group('simplevhdl'), m.group('extendedvhdl')

import ply.lex
import ply.yacc

# Create grammar


# -----------------------------------------------------------------------------
# calc.py
#
# A simple calculator with variables -- all in one file.
# -----------------------------------------------------------------------------

tokens = (
    'NAME','NUMBER',
    'PLUS','MINUS','TIMES','DIVIDE','EQUALS',
    'LPAREN','RPAREN',
    )

# Tokens

t_PLUS    = r'\+'
t_MINUS   = r'-'
t_TIMES   = r'\*'
t_DIVIDE  = r'/'
t_EQUALS  = r'='
t_LPAREN  = r'\('
t_RPAREN  = r'\)'
t_NAME    = r'[a-zA-Z_][a-zA-Z0-9_]*'

def t_NUMBER(t):
    r'\d+'
    try:
        t.value = int(t.value)
    except ValueError:
        print("Integer value too large %d", t.value)
        t.value = 0
    return t

# Ignored characters
t_ignore = " \t"

def t_newline(t):
    r'\n+'
    t.lexer.lineno += t.value.count("\n")
    
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)
    
# Build the lexer
import ply.lex as lex
lexer = lex.lex()

# Parsing rules

precedence = (
    ('left','PLUS','MINUS'),
    ('left','TIMES','DIVIDE'),
    ('right','UMINUS'),
    )

# dictionary of names
names = { }

def p_statement_assign(t):
    'statement : NAME EQUALS expression'
    names[t[1]] = t[3]

def p_statement_expr(t):
    'statement : expression'
    print(t[1])

def p_expression_binop(t):
    '''expression : expression PLUS expression
                  | expression MINUS expression
                  | expression TIMES expression
                  | expression DIVIDE expression'''
    if t[2] == '+'  : t[0] = t[1] + t[3]
    elif t[2] == '-': t[0] = t[1] - t[3]
    elif t[2] == '*': t[0] = t[1] * t[3]
    elif t[2] == '/': t[0] = t[1] / t[3]

def p_expression_uminus(t):
    'expression : MINUS expression %prec UMINUS'
    t[0] = -t[2]

def p_expression_group(t):
    'expression : LPAREN expression RPAREN'
    t[0] = t[2]

def p_expression_number(t):
    'expression : NUMBER'
    t[0] = t[1]

def p_expression_name(t):
    'expression : NAME'
    try:
        t[0] = names[t[1]]
    except LookupError:
        print("Undefined name '%s'" % t[1])
        t[0] = 0

def p_error(t):
    print("Syntax error at '%s'" % t.value)

import ply.yacc as yacc
parser = yacc.yacc()

while True:
    try:
        s = raw_input('calc > ')   # Use raw_input on Python 2
    except EOFError:
        break
    parser.parse(s)
