class MyError(RuntimeError):
    def __init__(self, argv):
        self.argv=argv


try:
    raise MyError("hello")

except MyError as e:
    print(e.argv)
    