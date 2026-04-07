
import numpy as np
import matplotlib.pyplot as plt
# gasta O(n) operacoes
def potencia(x,n):
    res=1
    for i in range(n):
        res*=x
    return res

def polinomioA(x,a):
    res = 0
    for i in range(len(a)):
        res+=a[i]*potencia(x,i)
    return res

def polinomioB(x,a):
    res = 0
    rn = 1
    for i in range(len(a)):
        res+=a[i] * x
        rn *= res;
    return res

def polinomioC(x,a):
    if len(a) == 1:
        return a[0]
    return polinomioC(x , a[:-1]) + a[-1]*potencia(x,len(a)-1) 

def polinomioD(x,a):
    if len(a) == 1:
        return a[0]
    n = len(a)
    a2 =  a[:-1]
    res = polinomioD(x,a2)
    return res + a[-1]*potencia(x,n-1) 

def polinomioD(x,a):
    if len(a) == 1:
        return a[0]
    n = len(a)
    a2 =  a[1:]
    res = polinomioD(x,a2)
    return res + x*potencia(x,n-1) 



print(polinomioA(1,a))

X = np.linspace(0,4,41)
print(X)

a = [2,-3,1]
Y = []
for x in X:
    y = polinomioC(x,a)
    Y.append(y)
plt.plot(X,Y,'o')
plt.grid(True)
plt.show()
