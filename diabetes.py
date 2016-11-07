import time
from sklearn import datasets
from sklearn import linear_model
from sklearn.cross_validation import train_test_split
import numpy as np
import matplotlib.pyplot as plt

diabetes = datasets.load_diabetes()

Y = diabetes.target
X = diabetes.data

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size = 0.33, random_state = 1)

alphas = np.logspace(-4, 0.5, 30)

models = {'LinReg' : linear_model.LinearRegression(),
          'Ridge'  : linear_model.Ridge(),
          'RidgeCV': linear_model.RidgeCV(),
          'Lasso'  : linear_model.Lasso(),
          'LassoCV': linear_model.LassoCV(),
         # 'LassoLarsCV': linear_model.LassoLarsCV(),
          'LassoLarsIC_AIC': linear_model.LassoLarsIC(criterion ='aic'),
          'LassoLarsIC_BIC': linear_model.LassoLarsIC(criterion ='bic'),
          'LassoLars' : linear_model.LassoLars(),
          'ElasticNet' : linear_model.ElasticNet()          
        }

scores = {}
t_check = []
t2 = 0
for name, model in models.items():
    for alpha in alphas:
        model.alpha = alpha
        if 'CV' in name:
            model.cv = 20
        #check time of training
        t1 = time.time()
        model.fit(x_train, y_train)
        t2 = time.time() - t1
        t_check.append((model.score(x_test, y_test), t2))
    scores[name] = (max(t_check))
    t_check = []

for key in scores:
    print "%s scored: %f ; training time : %f \n" %(key, scores[key][0], scores[key][1])

'''
plt.figure()
plt.semilogx(alphas, scores)
plt.ylabel('score')
plt.xlabel('alpha')
plt.xlim([alphas[0], alphas[-1]])
plt.show()
'''
#quite unreasonable, low, accuracy and huge standard deviaton
#reject this method

