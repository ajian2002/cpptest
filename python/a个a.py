while(1):
    try:
        s=0
        n,a=map(int,input().split())
        for i in range(n):
            s+=a
            #print(a)
            a=10*a+a%10
            
        print(s)
    except:
        break
