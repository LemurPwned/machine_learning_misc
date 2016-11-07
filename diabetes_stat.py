import numpy as np
import pandas as pd
form sklearn import datasets
import seaborn as sns
import matplotlib.pytplot as plt

diabetes = datasets.load_diabetes()

index = ['age' ,'sex','bmi', 'avbp' , 's1', 's2', 's3', 's4', 's5', 's6']
#avbp is average blood pressure
#s1 - s6 is blood serum
#target is response of a subject, a quantative indicator
#of the 'disease' progress (I'm positive they meant condition
#instead of 'disease')
#taken from http://www4.stat.ncsu.edu/%7Eboos/var.select/diabetes.html
#also, already standarized

df = pd.DataFrame(diabetes['data'], columns=index)
dfy = pd.DataFrame(diabetes['target'], columns=['y'])

diab = pd.concat([df, dfy], axis=1)

print df.shape, dfy.shape, diab.shape
print diab.head()

sns.distplot(df['age'], rug=True)
sns.jointplot(x="age", y="y", data=diab)



 
