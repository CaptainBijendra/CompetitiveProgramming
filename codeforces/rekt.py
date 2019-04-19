def prime(x):
    for d in range(2, int(x**0.5)+1):
        if x%d==0:
            return False
    return True
n = 0
for i in range(2, 1000001):
    if prime(i):
        n+=1
 
print(n)