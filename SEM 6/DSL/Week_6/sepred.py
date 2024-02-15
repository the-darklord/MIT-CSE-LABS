from itertools import groupby
from operator import itemgetter
import sys

def read_input(file,separator='\t'):
    for line in file:
        yield line.rstrip().split(separator,1)
        
def main(separator='\t'):
    data = read_input(sys.stdin,separator=separator)
    for current_word,group in groupby(data,itemgetter(0)):
        try:
            total_count = sum(int(count) for current_word,count in group)
            print(f'{current_word}{separator}{total_count}')
        except ValueError:
            pass
        
if __name__=="__main__":
    main()