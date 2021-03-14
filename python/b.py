def A(a_func):

    def wrap():
        print("1")

        a_func()

        print("2")

    return wrap


def C():
    print("3")


C()
# 3


C = A(C)
#now C is wrapped by wrapTheFunction()

C()
# 1 3 2 



#3 1 3 2 