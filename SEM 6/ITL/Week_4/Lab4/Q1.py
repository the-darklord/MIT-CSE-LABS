class SubSetGen:
    def __init__(self):
        self.l = []
    
    def getInput(self):
        self.l = list(map(int,input("Enter csv of numbers : ").split(',')))
        
    def genSubSet(self):
        NoofSubSet = pow(2,len(self.l))
        self.subsets=[[]]
        for i in range(NoofSubSet):
            temp = []
            for j in range(len(self.l)):
                if i & 1<<j:
                    temp.append(self.l[j])
            self.subsets.append(temp)
        self.subsets.sort(key=len)
        print(self.subsets)

gen = SubSetGen()
gen.getInput()
gen.genSubSet()

