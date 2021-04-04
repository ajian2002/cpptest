# 枚举
from enum import Enum
class Suite(Enum):
    Int,Char,Double=0,1,2
for suite in Suite:
    print(suite , suite.value)
