class TwoSum:
    def __init__(self):
        self.arr = list(map(int,input("Enter csv of numbers : \n").split(',')))
        self.target = int(input("Enter Target Sum : "))
        
    def getPairs(self):
        n = len(self.arr)
        for i in range(n-1):
            for j in range(i+1,n):
                if self.arr[i]+self.arr[j]==self.target:
                    print([i+1,j+1])
                    
gen = TwoSum()
gen.getPairs()
