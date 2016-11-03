import pandas as pd
import numpy as np
import seaborn as sns
import scipy.stats as st
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split


death = pd.read_csv('D:/Dokumenty/Datasets/DeathRecords/DeathRecords.csv',
                    usecols = ['MannerOfDeath', 'MaritalStatus', 'DayOfWeekOfDeath'], 
                    nrows = 10000)
                    
print "What is the most popular weekday?"
print np.mean(death['DayOfWeekOfDeath'][death['DayOfWeekOfDeath'] < 8])
print np.std(death['DayOfWeekOfDeath'][death['DayOfWeekOfDeath']< 8])
print st.mode(death['DayOfWeekOfDeath'][death['DayOfWeekOfDeath']< 8])
print st.mode(death['MaritalStatus'])
singles = 0
divorced = 0
married = 0
death['MS'] = pd.Series(np.random.randn(len(death['MaritalStatus'])), index=death.index)

death.loc[death['MaritalStatus'] == 'S', 'MS'] = 1
death.loc[death['MaritalStatus'] == 'M', 'MS'] = 2
death.loc[death['MaritalStatus'] == 'D', 'MS'] = 3
death.loc[death['MaritalStatus'] == 'W', 'MS'] = 4
death.loc[death['MaritalStatus'] == 'U', 'MS'] = 0
'''
for person_id, person in death.iterrows():
    print person_id
    if person['MaritalStatus'] == 'S':
        singles += 1
        death.loc[death['MaritalS 
    if person['MaritalStatus'] == 'D':
        divorced += 1
        persons[person_id] = 3
    if person['MaritalStatus'] == 'M':
        married += 1
        persons[person_id] = 2
    else:
        persons[person_id] = 0
        '''
#print singles, divorced, married
kd = death['MannerOfDeath'][(death['MannerOfDeath'] != 4)][(death['MannerOfDeath'] != 5)][
                  (death['MannerOfDeath'] != 0)]
X_train, X_test, y_train, y_test = train_test_split(
     X, y, test_size=0.33, random_state=42)
                  
#sns.distplot(death['DayOfWeekOfDeath'], kde = False, rug = False)
f,(ax1, ax2, ax3) = plt.subplots(3)
sns.distplot(death['MS'], kde = False, rug = False, ax = ax1)
sns.distplot(death['DayOfWeekOfDeath'][death['DayOfWeekOfDeath']<8], kde = False, rug = False, ax = ax2)
sns.distplot(death['MannerOfDeath'], kde = False, rug = False, ax = ax3)
plt.show()


'''
print "What is the average marital status?"
print np.mean(death['MaritalStatus'])
print np.std(death['MaritalStatus'])

print "What is the average death cause?"
print np.mean(death['MannerOfDeath'][death['MannerOfDeath'] != 0][death['MannerOfDeath'] != 4])
print np.std(death['MannerOfDeath'])
'''