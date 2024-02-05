#argparse
import sys
import os
import argparse

from gettext import gettext as _

class my(argparse.ArgumentParser):
    def exit(self, status=0, message=None):
        print "continue with code: {}\ncustom message: {}".format(status, message)
    def error(self, message):
        print "continue on error: {}".format(message)
        self.exit(2, _('%s: error: %s') % (self.prog, message))

p = my(prog='Test1')
#p = argparse.ArgumentParser(prog='Test')
p.add_argument('-m')

sp = p.add_subparsers()

sp1 = sp.add_parser('request')
sp1.add_argument('-a')
sp1.add_argument('host',nargs='?')

sp2 = sp.add_parser('status')
sp2.add_argument('--host')

sp3 = sp.add_parser('kill')
sp3.add_argument('--host')

print p.parse_args(['request', '-a', '12'])
print p.parse_args(['request', 'hood-host:9900', '-a', '12'])
print p.parse_args(['-a'])
print p.parse_args(['status', '--host', '12'])
print p.parse_args(['kill', '--host', '12'])
print p.parse_args(['request', '-a', '12', '--host'])
print p.parse_args(['-h'])

##
##pp1 = my(prog="Test2", add_help=False, conflict_handler='resolve')
##grp1 = pp1.add_mutually_exclusive_group()
##grp1.add_argument('--status')
##grp1.add_argument('--kill')
##pp1.add_argument('host')
##
##pp2 = my(parents=[pp1])
##grp2 = pp2.add_mutually_exclusive_group()
##grp2.add_argument('--request')
##grp1.add_argument('--status')
##grp1.add_argument('--kill')
##
##
##print pp2.parse_args(['--kill', '12', '23'])
##print "$$$$$$$$$$$$$$$"
##print pp2.parse_args(['--request', '12', '23'])
##print "$$$$$$$$$$$$$$$"
##try:
##    print pp2.parse_args(['12', '--kill', '12'])
##except:
##    pass
##print "$$$$$$$$$$$$$$$"
##print pp2.parse_args(['12', '--request', '12'])
##print "$$$$$$$$$$$$$$$"
##


