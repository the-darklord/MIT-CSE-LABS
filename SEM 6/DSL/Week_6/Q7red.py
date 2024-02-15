import sys

esum = 0
osum = 0
for line in sys.stdin:
    data = line.strip().split("\t")
    current_key, current_value = data
    if int(current_key)%2==0:
        esum += int(current_value)
    else:
        osum += int(current_value)

print("Number of even numbers is : ", esum)
print("Number of odd numbers is : ", osum)