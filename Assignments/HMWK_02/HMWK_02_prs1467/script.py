import os

os.system('gcc -Wall -Wextra -Ofast -o hmwk_02b hmwk_02b.c quicksort.c')

for x in range(1, 21):
    os.system('./hmwk_02b '+str(x*5000000))
for x in range(3, 21):
    os.system('./hmwk_02b '+str(x*50000000))
