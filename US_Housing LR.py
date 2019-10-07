import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

def normalize(x):
    l1 = []
    for i in range(x.shape[1]):
        l1.append((x[:,i] - np.mean(x[:,i]))/np.std(x[:,i]))
    l1 = np.array(l1).T
    return l1

def grad_desc(x,y,m = -100,b = 100,learning_rate = 0.001, epochs = 1000):
    n = len(y)
    for i in range(0,epochs):
        y_current = (m*x) + b
        m_grad = -(2/n) * np.sum(x * (y-y_current))
        b_grad = -(2/n) * np.sum(y-y_current)
        m = m - (learning_rate * m_grad)
        b = b - (learning_rate * b_grad)
    return m,b
    
df = pd.read_csv(r'D:\Data set\USA_Housing.csv')
df.columns
df.drop(['Avg. Area Number of Bedrooms','Address'],inplace=True,axis=1)
df.columns
X = df.iloc[:,0:4]
Y = df.iloc[:,4:5]
X
X_train,X_test,Y_train,Y_test = train_test_split(X,Y,test_size = 0.2,random_state = 42)
x = X_train
y = Y_train
x1 = normalize(np.array(x))
y1 = normalize(np.array(y))
#m=np.linalg.inv(x1.T.dot(x1)).dot(x1.T).dot(y1)
m,c = grad_desc(x1,y1)

m
m = [m,m,m,m]
m = np.array(m).T
#c = np.median(y1 - x1.dot(m))
m
c
X_pred = normalize(np.array(X_test))
Y_pred = X_pred.dot(np.array(m)) + c
Y_pred = np.array(Y_pred)
Y_test = np.array(Y_test)
Y_test = normalize(Y_test)

error = np.sqrt(np.mean((Y_pred - Y_test)**2))
error
