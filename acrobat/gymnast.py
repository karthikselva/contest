import sys
f=open(sys.argv[1],'r')
lines=f.readlines()
dict,count={},0
pos,min=0,0
def return_min(height):
	tempx,tempy=int(0),int(0)
	keys=dict.keys()
	pos=0
	print ' Iteration : '+str(height)+'\n'

	for i in keys:
		x,y=min
		if x==0 and y==0: continue
		print tempx,tempy,' Compared to ',x,y
		if x>tempx and y>tempy:
			tempx,tempy=x,y
			pos=i
	if tempx==65535 and tempy==65535:
		return height
	else: 
		dict[pos]=(65535,65535)
		return return_min(height+1)
	
for line in lines:
	line=line.split('(')
	for entry in line:
		entry=entry.replace(')','')
		entry=entry.split(',')
		if count >1: dict[count]=(int(entry[0].strip()),int(entry[1].strip()))
		count=count+1
		
keys=dict.keys()
tempx,tempy=65536,65535
for i in keys:
	x,y=dict[i]
	if x==65535 and y==65535: continue
	print tempx,tempy,' Compared to ',x,y
	if x<tempx and y<tempy:
		tempx,tempy=x,y
		pos=i
	min=dict[pos]
print dict
print return_min(0)
print dict

f.close()