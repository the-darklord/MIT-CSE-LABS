class Power:
    def __init__(self):
        self.x = int(input("Enter x : "))
        self.n = int(input("Enter n : "))
        self.power = 1
        
    def calcPow(self):
        for i in range(self.n):
            self.power *= self.x
        print("Power Value : ",self.power)
            
power = Power()
power.calcPow()
