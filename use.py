def fact(n):
    fact = 1
    for i in range(2,n+1): 
        fact *= i
    return str(fact)

print(fact(50))