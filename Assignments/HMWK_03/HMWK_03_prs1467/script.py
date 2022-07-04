import os

os.system('gcc -Wall -Wextra -o hmwk_03 hmwk_03.c heapsort.c')

for x in range(1, 31):
    os.system('./hmwk_03 '+str(x*10000000))

os.system('gcc -Wall -Wextra -Ofast -o hmwk_03 hmwk_03.c heapsort.c')

for x in range(1, 31):
    os.system('./hmwk_03 '+str(x*10000000))
