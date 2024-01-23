words = ["hi","Hi","dark","lord","Vader","Voldemort","lucifer"]
print("Before Sort : ",words)
for i in range(len(words)):
	minI = i
	for j in range(i+1,len(words)):
		if words[minI].lower() > words[j].lower():
			minI = j
	words[minI],words[i] = words[i],words[minI]
print("After Sort : ",words)