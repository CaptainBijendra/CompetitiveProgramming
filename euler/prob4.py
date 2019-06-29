def reverse(s): 
    return s[::-1] 

def isPalin(n):
    st = str(n)
    st_rev = reverse(st)
    
    return (st_rev == st)

big = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        num = i * j
        
        if (isPalin(num)):
            big = max(big, num)
            
print (big)