def a_new_decorator(a_func):

    def wrapTheFunction():
        print("1")

        a_func()

        print("2")

    return wrapTheFunction


def a_function_requiring_decoration():
    print("3")


a_function_requiring_decoration()
#outputs: "I am the function which needs some decoration to remove my foul smell"

a_function_requiring_decoration = a_new_decorator(
    a_function_requiring_decoration)
#now a_function_requiring_decoration is wrapped by wrapTheFunction()

a_function_requiring_decoration()
#outputs:I am doing some boring work before executing a_func()
#        I am the function which needs some decoration to remove my foul smell
#        I am doing some boring work after executing a_func()


3 1 3 2 