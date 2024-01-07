#1

a = int(input('Enter Length : '))
b = int(input('Enter Breadth : '))
print('Area : ',a*b)


#2

a = int(input('Enter Number 1 : '))
b = int(input('Enter Number 2 : '))
a,b = b,a
print('a : ',a,' b: ',b)


#3

a = int(input('Enter a Number : '))
if a%2==0:
    print('Even')
else:
    print('Odd')


#4

a = int(input('Enter Number 1 : '))
b = int(input('Enter Number 2 : '))
c = int(input('Enter Number 3 : '))
if a>b and a>c:
    print(a,' is greater')
elif b>a and b>c:
    print(b,' is greater')
else:
    print(c,' is greater')


#5

a = []
for i in range(0,4):
    a.append(int(input('Enter Number : ')))
print(a)
a.pop()
print(a)
a.reverse()
print(a)


#6

t = (1,3,5,7,9,2,4,6,8,10)
print(t[0:len(t)//2])
print(t[len(t)//2:])


#7

t1 = (12, 7, 38, 56, 78)
t2 = tuple(x for x in t1 if x%2==0)
print(t2)


#8

l = [11, -21, 0, 45,66, -93]
for i in l:
    if i<0:
        print(i)


#9

oC = 0
eC = 0
for i in l:
    if i%2==0:
        eC += 1
    else:
        oC += 1
print('Even Count : ',eC,' Odd Count : ',oC)


#10

l = [1,2,3,4,5,6,7,8,9,10]
for i in l:
    if i%2==0:
        l.remove(i)
print(l)