def isrun(year):
    if year % 4 == 0 and year % 100 != 0:
        return 1
    elif year % 400 == 0 and year % 100 == 0:
        return 1
    else:
        return 0


s = input()
year, month = s.split(" ")
year = int(year)
month = int(month)
m = 0
x = [1, 3, 5, 7, 8, 10, 12]
if month in x:
    m = 31
else:
    m = 30
if month == 2:
    m = 28
if (isrun(year) == 1 and month == 2):
    m = 29
print(m)
