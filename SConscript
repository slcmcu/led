
from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c') + Glob('*.cpp')
CPPPATH = [cwd]

group = DefineGroup('led', src, depend = [''], CPPPATH = CPPPATH)

Return('group')
