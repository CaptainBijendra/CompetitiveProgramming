def gcd(x, y):
   while(y): 
       x, y = y, x % y 
  
   return x  

def lcm(a, b):
    return (a * b / gcd(a, b))

num = 1

for i in range (1, 21):
    num = lcm(num, i)

print (num)