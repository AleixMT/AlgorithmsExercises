from datetime import datetime


def fileReader():
    fh = open("dates.txt", "r")
    cntnt = fh.read()
    words = cntnt.split(" ")
    if len(words) == 0:
        print("exit: empty file")
        exit(1)
    if len(words) % 3 != 0:
        print("exit: incoherent total number of dates")
        exit(1)

    dateslist = []
    cont = 0
    date = []
    for i in range(len(words)):
        if cont == 0:
            date.append(int(words[i]))
            cont = cont + 1
        elif cont == 1:
            date.append(int(words[i]))
            cont = cont + 1
        elif cont == 2:
            date.append(int(words[i]))
            dateslist.append(date)
            date = []
            cont = 0
    return dateslist


def isDateCorrect(year, month, day):
    month_list = [31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31]

    if month_list[month - 1] < month:
        return False
    else:
        if month == 2 and day == 29 and not isLeapYear(year):
           return False
        if month > 13 or month <1:
            return False
        else:
            if year < 1:
                return False
            else:
                return True

def isLeapYear(year):
    if (year < 1583):
        return year % 4 == 0
    else:
        return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

def dayDigit(day):
    return day % 7

def monthDigit(month):
    return month_digits[month - 1]

def centuryDigit(year):
    print(str(year) + " " + str(int(year / 100)))
    return century_digits[int(year / 100) % 4]

def yearDigit(year):
    return year_digits[year % 100]

def alternativeYearDigit(year):
    lastyeardigits = year % 100
    firstyeardigits = int(year / 100)
    lastyeardigitsquarter = int(lastyeardigits / 4)
    centurydigit = centuryDigit(firstyeardigits)
    return (lastyeardigits + lastyeardigitsquarter + centurydigit) % 7

month_digits = [0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5]
century_digits = [6, 4, 2, 0]
weekdays = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']
year_digits = [0, 1, 2, 3, 5, 6, 0, 1, 3, 4,
               5, 6, 1, 2, 3, 4, 6, 0, 1, 2,
               4, 5, 6, 0, 2, 3, 4, 5, 0, 1,
               2, 3, 5, 6, 0, 1, 3, 4, 5, 6,
               1, 2, 3, 4, 6, 0, 1, 2, 4, 5,
               6, 0, 2, 3, 4, 5, 0, 1, 2, 3,
               5, 6, 0, 1, 3, 4, 5, 6, 1, 2,
               3, 4, 6, 0, 1, 2, 4, 5, 6, 0,
               2, 3, 4, 5, 6, 1, 2, 3, 5, 6,
               0, 1, 3, 4, 5, 6, 1, 2, 3, 4]

dateslist = fileReader()
print(dateslist)
for date in dateslist:
    year, month, day = date

    print(date)
    if isDateCorrect(int(year), int(month), int(day)):
        print("The date " + str(date) + " is valid.")
        print (str(dayDigit(day)) + " " + str(monthDigit(month)) + " " + str(yearDigit(year)) + " " + str(centuryDigit(year)))
        print("The day of the week in " + str(date) + "s was a: " + weekdays[(dayDigit(day) + monthDigit(month) + yearDigit(year) + centuryDigit(year) - isLeapYear(year)) % 7])
    else:
        print("The date " + str(date) + " is invalid.".format(date))
        exit(1)