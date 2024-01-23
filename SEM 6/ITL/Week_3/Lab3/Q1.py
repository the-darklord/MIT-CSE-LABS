a = int(input("Enter Number 1 : "))
b = int(input("Enter Number 2 : "))
print("""
		1> Addition
		2> Substraction
		3> Multiplication
		4> Division
	""")
choice = int(input("Enter Choice : "))
ans = 0
switch = {
	1:a+b,
	2:a-b,
	3:a*b,
	4:a/b
}
print("Result : ",switch[choice])