import pandas as pd
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-c','--choice')
args = parser.parse_args()


# 1.Heart Disease Data
# 2.Covid 19 Data
# 3.German Credit
# 4.Example Data

files = ['heart_disease_data.csv','covid_19_data.csv','German_Credit.xlsx','example.txt']
columns = []
choice = int(args.choice)

if(choice - 1 == 3):
	df= pd.read_csv(files[choice-1],sep='\t',names=['Date','Time','City','Category','Price','Card'])
	columns = ['Category','Price']
elif(choice - 1 == 2):
	df = pd.read_excel(files[choice-1])
	columns = ['DurationOfCreditInMonths','CreditAmount']
else:
	if choice - 1 == 1:
		columns = ['Province/State','Confirmed']
	else:
		columns = ['target','chol']
	df = pd.read_csv(files[choice-1])

one = columns[0]
two = columns[1]

df = df[[one,two]]
df.dropna(axis=0,inplace=True)

for i in df.index:
	print(f"{df[one][i]}\t{df[two][i]}")