import numpy as np

# Q1

num = int(input("Enter a Number : "))

for i in range(1,num+1):
    if num%i==0:
        print(i)


# Q2

A = np.arange(12).reshape((3,4))
print(A)
print("Row Sum : ",A.sum(axis=1))
print("Col Sum : ",A.sum(axis=0))


# Q3 & Q4

A = np.array([1.2,2.3,3.4,4.5,5.6,6.7])
print(A)
B = np.array((1,2,3,4,5,6))
print(B)
C = np.zeros((3,4))
print(C)
D = np.arange(0,20,5)
print(D)
E = C.reshape((2,2,3))
print(E)
F = np.arange(0,15).reshape((3,5))
print(F)

for row in F:
    print(row)
    print("Max : ",max(row))
    print("Min : ",min(row))
    print("Sum : ",sum(row))
    
F = F.T

for col in F:
    print(col)
    print("Max : ",max(col))
    print("Min : ",min(col))
    print("Sum : ",sum(col))


# Q5 & Q6

a = np.arange(0,9).reshape((3,3))
b = np.arange(10,19).reshape((3,3))
print(a,"    +",b,"    =",a+b,sep="\n",end="\n\n")
print(a,"    *",b,"    =",a*b,sep="\n",end="\n\n")