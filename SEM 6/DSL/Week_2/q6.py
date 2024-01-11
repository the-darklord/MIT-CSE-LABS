import pandas as pd  

data = {"Name":["Annie","Diya","Charles","James","Emily"],"Quiz_1/10":[8.0,9.0,7.5,8.5,6.5],"In-Sem_1/15":[11,14,14.5,13,12.5],"Quiz_2/10":[9.5,6.5,8.5,9.0,9.0],"In-Sem_2/15":[12.5,13.5,14.5,15,13]}

df1 = pd.DataFrame(data)

print(df1)

df1['Total'] = df1.iloc[:,1:].sum(1)

df = list(df1.iloc[:,1:].sum(0)/5)
df.insert(0,"Mean")

df1.loc[len(df1)] = df
print(df1)