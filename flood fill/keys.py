#!/usr/bin/python	
import sys
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
for i in range(H):
	for j in range(W):
		if arr[i][j]=='0':  
			blackie.append([i,j])	
clicks=0


print 'read'
while len(blackie)>0:
	print len(blackie)
	del_blackie(blackie[0][0],blackie[0][1])
	clicks=clicks+1
print clicks

f1.close()
