fib1 = 1
fib2 = 2

sumN = 0

while (fib1 <= 4000000 and fib2 <= 4000000):
    if (fib2 % 2 == 0):
        sumN += fib2

    temporary = fib1
    fib1 = fib2
    fib2 += temporary

print (sumN)