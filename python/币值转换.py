x = input()
length = len(x)
for i in range(0, length, 1):
    if x[i] != '0':
        print(chr(ord(x[i])-ord('0')+ord('a')), end="")

        if length-i >= 9:
            print("Y", end="")
        if length-i >= 5 and length-i < 9:
            if length-i-5 == 1:
                print("S", end="")
            if length-i - 5 == 2:
                print("B", end="")
            if length-i - 5 == 3:
                print("Q", end="")
            if length-i - 5 == 0:
                print("W", end="")
        if length-i == 4:
            print("Q", end="")
        if length-i == 3:
            print("B", end="")
        if length-i == 2:
            print("S", end="")
        
    elif (x[i-1] != '0'):
            print("a", end="")

