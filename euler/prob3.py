num = 600851475143
big = 0

for i in range(2, 775147):
    while (num % i == 0 and num != 0):
        big = max(big, i)
        num = num / i

big = max(big, num)
print(big)