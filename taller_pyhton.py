# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import numpy as np
##import math as m
#dominio = np.linspace(-5,5,11)
#print(dominio)
#imagen = dominio**2
#print(imagen)
#dominio2 = np.linspace(-100,100,201)
#imagen2 = dominio2*3 +2
#print(dominio2)
#print(imagen2)
#tiempo = np.linspace(0,200,201)
#vel_inicial=1000
#acel=-10
#posicion = (acel/2)*tiempo**2 + vel_inicial*tiempo
#print(posicion)

#matriz01 = np.arange(0,256,1)
#print(matriz01)

# GRAFICOS
from matplotlib import pyplot as plt

#%matplotlib inline

f= lambda x, A, T, C: A*np.exp(-x/T)+C

A = 1
T = 10
C = 5

# Definimos dominio e imagen
x = np.linspace(-20,20,100)
y = f(x,A,T,C)

# Creamos un ruido y lo agregamos a los datos
ruido = (2*(np.random.random(len(y)))-1)*0.2*y
y_data = y + ruido

#Proponemos un error
error_y = 0.1*y

# Ploteamos
plt.plot(x, y, '-b', label = 'Modelo')
plt.plot(x, y_data, 'r.', label = 'Datos')
plt.errorbar(x,y_data, error_y, linestyle = 'None')

# Detalles del grafico
plt.grid(True) # Para que quede en hoja cuadriculada
plt.title('Grafico ejemplo')
plt.xlabel('Valores en X')
plt.ylabel('Valores en Y')
plt.legend(loc = 'best')

# Muestra en una ventana el grafico:
plt.show()

# Guardamos y cargamos, a modo de ejemplo
np.savetxt('/home2/clinux01/Desktop/Datos_taller.txt', [x,y_data, error_y], delimiter = '\t')
Data = np.loadtxt('/home2/clinux01/Desktop/Datos_taller.txt', delimiter = '\t')
plt.plot(Data[0],Data[1],'r.') # Se tiene que ver que son los mismos datos
plt.errorbar(Data[0],Data[1],Data[2], linestale = 'None')
plt.show()

from scipy.optimize import curve_fit

#Ajustamos
popt, pconv = curve_fit(f, x, y_data, sigma = error_y)
sigmas = [pconv[0,0],pconv[2,2]]
print(popt, sigmas)
# Esto no lo entendi!

plt.plot(x, y, 'b-', label = 'modelo')
plt.plot(x, y_data, 'r.', label = 'Datos')
plt.plot(x,f(x, popt[0], popt[1], popt[2]), 'g-', label = 'Ajuste')

plt.errorbar(x, y_data, error_y, linestyle = 'None')

# Detalles del grafico
plt.grid(True)
plt.title('Grafico ejemplo')
plt.xlabel('Valores en x')
plt.ylabel('Valores en y')
plt.legend(loc = 'best')

plt.show()

#Hacer ejercios de histogramas.