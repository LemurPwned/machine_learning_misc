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
          'RidgeCV': linear_model.RidgeCV(alphas = [0.01, 0.001, 0.1, 2, 3]),
          'Lasso'  : linear_model.Lasso(),
          'LassoLars' : linear_model.LassoLars(),
          'ElasticNet' : linear_model.ElasticNet()
        }
for name, model in models.items():
    model.fit(x_train, y_train)
    print  "%s score : %f " %(name, model.score(x_test, y_test))

#just lasso
print "\n\n"
scores = []
lasso = linear_model.Lasso(random_state = 0)
for alpha in alphas:
    lasso.alpha = alpha
    lasso.fit(x_train, y_train)
    score = lasso.score(x_test, y_test)
    scores.append(score)
    #print "alpha %f score : %f " %(alpha, score)

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
scores_r = []
ridgeCV = linear_model.RidgeCV()
for alpha in alphas:
    ridgeCV.alpha = alpha
    ridgeCV.fit(x_train, y_train)
    score = ridgeCV.score(x_test, y_test)
    scores_r.append(score)

plt.figure()
plt.semilogx(alphas, scores_r)
plt.ylabel('score')
plt.xlabel('alpha')
plt.xlim([alphas[0], alphas[-1]])
plt.title('RidgeCV')
plt.show()

   
print max(scores_r)
