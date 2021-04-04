def countn(n):
    if n <= 0:
        return 0
    if n == 3:
        return 4
    if n == 2:
        return 2
    if n == 1:
        return 1

    return countn(n-1)+countn(n-2)+countn(n-3)


n = int(input())
print(countn(n))
