#!/usr/bin/python	
import sys
import math
blackie=[]
arr=[]
def del_blackie(x,y):
	try:
		blackie.remove([x,y])
		del_blackie(x+1,y)
		del_blackie(x+1,y+1)
		del_blackie(x+1,y-1)
		del_blackie(x-1,y)
		del_blackie(x-1,y-1)
		del_blackie(x,y-1)
		del_blackie(x,y+1)
		del_blackie(x-1,y+1)
	except:
		return
	
if len(sys.argv)>0: f1=open(sys.argv[1],'r')
H,W=(f1.readline()).split(' ')
arr=f1.readlines()
sys.setrecursionlimit(100000)
count,clicks,H1,W1,H,W=0,0,0,0,int(H),int(W)
bit=int(arr[0][0])
br=[]
count=0
for i in range(H):
	for j in range(W):
		bit=bit^int(arr[i][j])
	br.append(bit)
print br
print abs(br.count(1)-br.count(0))
	
f1.close()
