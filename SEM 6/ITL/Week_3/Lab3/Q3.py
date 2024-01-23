def binarySearch(ll,l,r,ele):
	if l<=r:
		m = l + (r-l)//2
		if ll[m]==ele:
			return True,m
		elif ll[m] > ele:
			return binarySearch(ll,l,m-1,ele)
		else:
			return binarySearch(ll,m+1,r,ele)
	else:
		return False,-1

def main():
	ll = [3,5,6,2,1,7,8,9]
	ll.sort()
	num = int(input("Enter Number to Search : "))
	flag,pos = binarySearch(ll,0,len(ll)-1,num)
	if flag:
		print("Number Found at Position ",pos+1)
	else:
		print("Number not found")

if __name__ == "__main__":
	main()
