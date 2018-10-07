# -*- coding: utf-8 -*-
"""
Created on Sat Oct  6 09:10:13 2018

@author: kaimo
"""

def factorial(n): 
    return 1 if (n==1 or n==0) else n * factorial(n - 1);


casos = input()
for i in range(0,int(casos)):
    N = int(input())
    print(factorial(N))    
