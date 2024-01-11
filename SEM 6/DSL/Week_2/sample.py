import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# pip3 install lxml html5lib openpyxl

# s = pd.Series([3,9,-2,10,5])
# print(s.sum(),s.min(),s.max())

# data = [['Dinesh',10],['Nithya',12],['Raji',13]]
# df = pd.DataFrame(data,columns=['Name','Age'])
# print(df)

# data = {'Name':['Kavitha', 'Sudha', 'Raju','Vignesh'],'Age':[28,34,29,42]}
# df = pd.DataFrame(data, index=['rank1','rank2','rank3','rank4'])
# print(df)

# df1=pd.DataFrame({'A':pd.Timestamp('20130102'),'B':np.array([3]*4,dtype='int32'),
# 'C':pd.Categorical(['Male','Female','Male','Female'])})
# print(df1)

# print(df1.shape)
# print(df1.dtypes)

# print(df1.head())
# print(df1.tail())
# print(df1.describe())

# dates=pd.date_range('20130101', periods=100)
# print(dates)

# print(df.head())
# print(df.tail())
# print(df.index)
# print(df.columns)
# print(df.T)
# print(df.sort_index(axis=1,ascending=False))
# print(df.sort_values(by='Name'))
# print(df[0:3])
# print(df.iloc[0:2])

# print(df[df['Age']>30])
# df['Gender']=['Male','Female','Female','Male']
# print(df)

# df.drop('Gender',axis=1,inplace=True)
# print(df)
# df.drop('rank1',axis=0,inplace=True)
# print(df)

# df = pd.read_csv('Lab2-files/xyz.csv',header=None)
# df.columns=['preg','glu','bp','sft','ins','bmi','dpf','age','class']

# print(df.head())
# print(df.tail())

# plt.scatter(df['bmi'],df['glu'])
# plt.xlabel('bmi')
# plt.ylabel('Glucose')

# plt.hist(df['preg'])

# plt.boxplot(df)

# plt.show()

# W = pd.read_csv('Lab2-files/wine_for_Week2.xls',header=None)
# print(W.head())

# D = np.loadtxt('Lab2-files/xyz.txt',delimiter=',')
# print(D[:5,:])

# G=pd.read_excel('Lab2-files/German_Credit_for_Week2.xlsx',sheet_name='Sheet1')
# print(G.head())

# B = pd.read_html('Lab2-files/Test runs-1.html')
# print(B)

# H = pd.read_table('Lab2-files/HR.txt')
# print(H.head())

# f = H['Department'].value_counts()
# print(f)

# f.plot(kind='bar')

# f.plot(kind='pie')

# plt.show()