def isrun(year):
    if year % 4 != 0:
        return 0
    else:
        if year % 100 != 0:
            return 1
        else:
            if year % 400 == 0:
                return 1
            else:
                return 0


string = input()
year = int(string[:4])
month = int(string[5:])
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
months[1] += isrun(year)
print(months[month - 1])