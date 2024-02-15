import pandas as pd

df = pd.read_csv("covid_19_data.csv")
one = "Country/Region"
two = "Confirmed"
df = df[[one,two]].astype(str)
df.dropna(axis=0,inplace=True)
for i in df.index:
	print(f"{df[one][i]}\t{df[two][i]}")