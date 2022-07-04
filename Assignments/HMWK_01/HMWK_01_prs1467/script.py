import os

os.system('gcc -Ofast -Wall -Wextra -o hmwk_01b hmwk_01b.c selection.c')

for x in range(1, 21):
    os.system('./hmwk_01b '+str(x*50000))
