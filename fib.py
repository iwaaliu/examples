def fib(n):
     a,b=0,1
     while a<n:
             print(a,end=' ')
             a,b=b,a+b
n=int(raw_input("Input an integer number: "))
fib(n)
