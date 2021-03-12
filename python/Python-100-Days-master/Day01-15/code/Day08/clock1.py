import os
import time


class CLOCK (object):

    def __init__(self, hours=0, minutes=0, seconds=0):
        self.hours = hours
        self.minutes = minutes
        self.seconds = seconds

    def run(self):
        self.seconds += 1
        if self.seconds == 60:
            self.seconds = 0
            self.minutes += 1
            if self.minutes == 60:
                self.minutes = 0
                self.hours += 1
                if self.hours == 24:
                    self.hours = 0

    def show(self):
        print("%02d:%02d:%02d" % (self.hours, self.minutes, self.seconds))


def main():
    clock = CLOCK()
    while True:
        os.system("clear")
        clock.show()
        time.sleep(1)
        clock.run()


if __name__ == '__main__':
    main()
