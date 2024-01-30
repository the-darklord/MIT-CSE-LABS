class Something:
    def getInput(self):
        self.str = input("Enter Something : \n")
        
    def printString(self):
        print(self.str.upper())
        
s = Something()
s.getInput()
s.printString()
        
