
# coding: utf-8

# In[163]:


import os
import numpy as np
import pandas as pd
import copy
import itertools
from math import factorial

class Apriori(object): 
    
    def __init__(self,confidence,support):
        self.confidence=confidence
        self.support=support
    
    def read_data(self,pathname):# 传入data文件，返回数据list(二维)  [[][][]]
        global LEN
        file=open(pathname,"r")
        data=[]
        for line in file.readlines():
            line=line.strip('\n')
            data.append([int(i) for i in line.split()])
        file.close()
        self.LEN=len(data)
        self.data=data
    
    def list_to_str(self,li):# return 把列表中的数据转化成以‘，’分隔的字符串
        s=""
        for item in li:
            s+=str(item)
            s+=","
        return s.rstrip(",")
    
    def str_to_list(self,s):# return 把字符串按‘，’分割的列表
        li=[]
        for i in s.split(','):
            li.append(int(i))
        return li
    
    def combination_num(self,n,k):#求组合数
        return factorial(n)/(factorial(k)*factorial(n-k))
        
    def joint(self,Lk,k):# 将Lk作自连接
        mp={}
        for i in range(len(Lk)-1):
            for j in range(i+1,len(Lk)):
                if(not(len(list(set(Lk[i])|set(Lk[j])))>k+1)):#自连接后大于k+1，说明这一项不是候选集,否则加入mp
                    li=list(set(Lk[i])|set(Lk[j]))
                    tmp_str=self.list_to_str(li)
                    mp[tmp_str]=1 if tmp_str not in mp else int(mp[tmp_str])+1
        Cnk=self.combination_num(self.combination_num(k+1,k),2)# 产生的候选集数目必须达到C（k+1，k）中取2的组合数
        ret_li=[self.str_to_list(i) for i in mp if mp[i]==Cnk]
        return ret_li
    
    def frequent_item_generate(self,Lk):#扫描数据库，统计Lk中的每项在数据库中出现的次数，筛选Lk的子集（大于支持度）
        mp={}
        for i in self.data:
            for j in Lk:
                if set(j).issubset(set(i)):#set([1,2]).issubset(set([3,2,1]))
                    mp[self.list_to_str(j)]=1 if self.list_to_str(j) not in mp else int(mp[self.list_to_str(j)])+1
        ret_li=[]
        ret_li=[self.str_to_list(i) for i in mp.keys() if mp[i]/self.LEN>=self.support]
        return ret_li
        
    def L1_generate(self):#扫描数据库，产生L1（大于支持度）
        mp={}
        for line in self.data:
            for ele in line:
                if ele not in mp:
                    mp[ele]=1
                else:
                    mp[ele]=int(mp[ele])+1
        L1=[[int(x)] for x in mp.keys() if int(mp[x])/self.LEN>=self.support]
        return L1
    
    def apriori_frequentitem_generate(self):
        ret_li=[]
        Lk=self.L1_generate()
        k=1
        while len(Lk):
            ret_li.extend(Lk)
            #print(Lk)
            Ck=self.joint(Lk,k)#自连接产生的候选集
            #剪枝步
            Lk=self.frequent_item_generate(Ck)
            k=k+1
           
        return ret_li


# In[180]:


a=Apriori(0.2,0.1)


# In[181]:


a.read_data("retail.dat")


# In[183]:


a.apriori_frequentitem_generate()

