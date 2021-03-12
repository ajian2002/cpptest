from abc import ABCMeta, abstractmethod

class Pet(object, metaclass=ABCMeta):
    def __init__(self,name):
        self.name=name
     @abstractmethod   #
    def voice(self):
        # pass
        print('嘤嘤嘤')
class Dog(Pet):
    def voice(self):
        print('汪汪汪')
class Cat(Pet):
    def voice(self):
        print('喵喵喵')


def main():
    pets=[Dog("猫"),Cat('狗'),Pet("lsp")]
    for p in pets:
        print(p.name,end=':')
        p.voice()
        
    
    
if __name__ == '__main__':
    main()