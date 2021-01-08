
x, y = map(int, input().split())
z = ((x-y)/y*100)
if(z < 10):
    print("OK")
elif(z >= 50):
    print("Exceed %.0f%%. License Revoked" % (z))
else:
    print("Exceed %.0f%%. Ticket 200" % (z))
