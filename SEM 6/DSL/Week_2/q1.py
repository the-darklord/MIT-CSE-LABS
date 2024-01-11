n = int(input("Enter the number:"))
while(n > 0):
	if n%3 == 0:
		print("Divisible by three")
	else:
		print("Number",n)
	n -= 1
else:
	print("While ended")
