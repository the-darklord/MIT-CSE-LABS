import sys

for line in sys.stdin:
 words = line = line.strip().split()
 for word in words:
    print(word, '\t', 1)