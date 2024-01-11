import pandas as pd  

data = ["Ram","Diya","Chandan","James","Alice"]

df1 = pd.DataFrame(data,columns=['Name'])

data = {"Maths":[80,90,77.5,87.5,86.5],"Physics":[81,94,74.5,83,82.5],"Chemistry":[91.5,86.5,85.5,90,91],"Biology":[82.5,83.5,84.5,85,93]}

df2 = pd.DataFrame(data)

df1 = pd.concat((df1,df2),axis=1)

print(df1.head())

df1['Total'] = df1.iloc[:,1:].sum(1)

print(df1)