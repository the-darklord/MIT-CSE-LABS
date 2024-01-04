#1

# counter = 100
# miles = 1000.0
# name = "Mihir"
# print(counter,miles,name)

# 100 1000.0 Mihir


#2

# a = b = c = 1
# a,b,c = 1,2,"john"

# a = 5
# b = 4.56
# print(5*a)
# print(a/2)
# print(a**2)

# 25
# 2.5
# 25


#3

# import numpy as np

# str = 'Hello World!'
# print (str) 
# print (str[0]) 
# print (str[2:5]) 
# print (str[2:]) 
# print (str * 2) 
# print (str + "TEST") 

# Hello World!
# H
# llo
# llo World!
# Hello World!Hello World!
# Hello World!TEST


#4

# var1 = 'Hello World!'
# print ("Updated String :", var1[:6] + 'Python')
# print( "My name is %s and weight is %d kg!" % ('Abay', 55))
# str = "this is string example wow!!!";
# print (str.capitalize())
# str = "this is string example ... wow!!!";
# str.count('s')
# str.find('example')
# str = "this is string example ... wow!!! this is really string";
# print (str.replace("is", "was"))
# str = "this is string example ... wow!!!";
# print (str.swapcase())
# str = "this is string example ... wow!!!";
# print (str.title())

# Updated String : Hello Python
# My name is Abay and weight is 55 kg!
# This is string example wow!!!
# thwas was string example ... wow!!! thwas was really string
# THIS IS STRING EXAMPLE ... WOW!!!
# This Is String Example ... Wow!!!


#5

# list = [ 'abcd', 786 , 2.23, 'john', 70.2 ]
# tinylist = [123, 'john']
# print (list)
# print (list[0])
# print (list[1:3])
# print (list[2:])
# print (tinylist * 2)
# print (list + tinylist)
# list = ['physics', 'chemistry', 1997, 2000];
# list.append('maths')
# del list[2]
# len(list)
# list.count('physics')
# list.pop()
# print(list)
# list.insert(2, 'maths')
# print(list)
# list.remove('chemistry')
# print(list)
# list.reverse()
# print(list)

# ['abcd', 786, 2.23, 'john', 70.2]
# abcd
# [786, 2.23]
# [2.23, 'john', 70.2]
# [123, 'john', 123, 'john']
# ['abcd', 786, 2.23, 'john', 70.2, 123, 'john']
# ['physics', 'chemistry', 2000]
# ['physics', 'chemistry', 'maths', 2000]
# ['physics', 'maths', 2000]
# [2000, 'maths', 'physics']


#6

# tuple = ( 'abcd', 786 , 2.23, 'john', 70.2 )
# list = [ 'abcd', 786 , 2.23, 'john', 70.2 ]
# tuple[2] = 1000
# list[2] = 1000

# Traceback (most recent call last):
#   File "sample.py", line 112, in <module>
#     tuple[2] = 1000
# TypeError: 'tuple' object does not support item assignment

#7

# num=float(input('Enter a number:'))
# if num>0:
#     print('pos number')
# elif num==0:
#     print('zero')
# else:
#     print('Neg number')
    
# Enter a number:5
# pos number


#8 

# x=42
# if x>1:
#     print('above one')
#     if x<100:
#         print('less than 100')
# print('All done')

# above one
# less than 100
# All done


#9

# age=15
# b=('kid' if age<18 else 'adult')
# print(b)

# kid

#10

# stud=['Ram','Vijay','Nithya','Anu','Ramesh','suja']
# for k in stud:
#     print('Hello:', k)
# print('done')

# Hello: Ram
# Hello: Vijay
# Hello: Nithya
# Hello: Anu
# Hello: Ramesh
# Hello: suja
# done