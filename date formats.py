import re
import sys

Months = (
    {'Month':'January', 'Days':31},
    {'Month':'February', 'Days':28},
    {'Month':'March', 'Days':31},
    {'Month':'April', 'Days':30},
    {'Month':'May', 'Days':31},
    {'Month':'June', 'Days':30},
    {'Month':'July', 'Days':31},
    {'Month':'August', 'Days':31},
    {'Month':'September', 'Days':30},
    {'Month':'October', 'Days':31},
    {'Month':'November', 'Days':30},
    {'Month':'December', 'Days':31}
)

Culture = (
    {'Format':'yyyy-MM-dd', 'Regex':'^\d{4}\-0?([2-9]|1[0-2]?)\-(0?(3[01]|[12][0-9]|[1-9]))$'},
    {'Format':'yyyy/MM/dd', 'Regex':'^\d{4}\/0?([2-9]|1[0-2]?)\/(0?(3[01]|[12][0-9]|[1-9]))$'},
    {'Format':'MM/dd/yyyy', 'Regex':'^0?([2-9]|1[0-2]?)\/(0?(3[01]|[12][0-9]|[1-9]))\/\d{4}$'},
    {'Format':'MMM dd, yyyy', 'Regex':'^[A-Za-z]{3} (0?(3[01]|[12][0-9]|[1-9])), \d{4}$'},
    {'Format':'dd MMM, yyyy', 'Regex':'^(0?(3[01]|[12][0-9]|[1-9])) [A-Za-z]{3}, \d{4}$'},
    {'Format':'MMMM dd, yyyy', 'Regex':'^[A-Za-z]{3,9} (0?(3[01]|[12][0-9]|[1-9])), \d{4}$'},
    {'Format':'dd MMMM, yyyy', 'Regex':'^(0?(3[01]|[12][0-9]|[1-9])) [A-Za-z]{3,9}, \d{4}$'},
    {'Format':'yyyy, MMM dd', 'Regex':'^\d{4}, [A-Za-z]{3} (0?(3[01]|[12][0-9]|[1-9]))$'},
    {'Format':'yyyy, MMMM dd', 'Regex':'^\d{4}, [A-Za-z]{3,9} (0?(3[01]|[12][0-9]|[1-9]))$'}
)

Decider = [
    ('-', '0,1,2'), ('/', '0,1,2'), ('/', '2,0,1'), (' ', '2,0,1'), (' ', '2,1,0'), (' ', '2,0,1'), (' ', '2,1,0'), (' ', '0,1,2'), (' ', '0,1,2')
]

def splitter(date, x, y):
    date = date.replace(',','').split(x)
    y = list(map(int, y.split(',')))
    year = int(date[y[0]])
    month = date[y[1]]
    if not re.match('^\d+$', month):
        for i in Months:
            if re.match('{}'%month,i['Month']): month = Months.index(i) + 1
    month = int(month)
    day = int(date[y[2]])
    return {'Year': year, 'Month': month, 'Day': day}

def parsedate(date):
    for a in range(len(Culture)):
        if re.match('%s' % Culture[a]['Regex'], date): i = a; break
    if i == 0: return splitter(date, '-', '0,1,2')
    elif i == 1: return splitter(date, '/', '0,1,2')
    elif i == 2: return splitter(date, '/', '2,0,1')
    elif i == 3: return splitter(date, ' ', '2,0,1')
    elif i == 4: return splitter(date, ' ', '2,1,0')
    elif i == 5: return splitter(date, ' ', '2,0,1')
    elif i == 6: return splitter(date, ' ', '2,1,0')
    elif i == 7: return splitter(date, ' ', '0,1,2')
    elif i == 8: return splitter(date, ' ', '0,1,2')

def totaldays(date):
    ye = date['Year']
    y = ye
    mon = date['Month']
    d = date['Day']
    if mon <= 2: y -= 1
    leaps = y // 4 - y // 100 + y // 400
    m = 0
    for b in range(mon - 1): m += int(Months[b].get('Days'))
    days = (ye - 1) * 365 + m + d + leaps
    return days

def diffdate(start, end):
    date1 = totaldays(parsedate(start))
    date2 = totaldays(parsedate(end))
    ddate = date2 - date1
    print(ddate)

#start = sys.argv[1]
#end = sys.argv[2]
#diffdate(start, end)

print splitter("07/24/1990", *Decider[2])
