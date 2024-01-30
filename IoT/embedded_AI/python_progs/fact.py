def fact_iter(n):
    'iterative factorial function'
    res=1
    if n <= 1:
        return 1
    else:
        for i in range(1,n+1):
            res= res * i 
    return res

def fact_rec(n):
    'recusive factorial function'

    if n <= 1:
        return 1
    else:
        return n * fact_rec(n-1)