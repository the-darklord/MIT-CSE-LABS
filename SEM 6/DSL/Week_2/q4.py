import pandas as pd   

data = {"Name":["JJ","JEN","ANJ"],"Height":["176cm","165cm","162cm"],"Qualification":["BTECH","MBBS","MBA"]}

df = pd.DataFrame(data)

print(df.head())

l = ["2/3,Welcome Street","2715 Calder Street","5432 Sun City"]

df.insert(len(df),'Address',l)

print(df.head())