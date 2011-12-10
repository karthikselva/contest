#include<stdio.h>
#include<string.h>
int H=0,W=0;
char *temp;
struct point
{
	long x,y;
	struct point *next;
}*root,*end;

int remover(struct point *p,long a,long b)
{
	struct point *temp=p;
	int c=0;
	while(p!=NULL)
	{
		if((p->x==a)&&(p->y==b))
		{
		if(p->next!=NULL)temp->next=p->next;
		if(c==0)root=p->next;
		if(p->next==NULL)temp->next=NULL;
		free(p);
		return 1;
		}

		temp=p;		
		p=p->next;
		c++;
	}

	return -1;
		
}

void add(struct point *p,long a,long b)
{
	struct point *temp=(struct point*)malloc(sizeof(struct point));
	temp->x=a;
	temp->y=b;
	p->next=temp;
	end=temp;
	temp->next=NULL;
}

void display(struct point *p)
{
	while(p!=NULL)
	{
		printf(" (%lu,%lu) \n",p->x,p->y);	
		p=p->next;
	}
}

int del_blackie(long x,long y)
{
	if(remover(root,x,y)==-1) return;
	del_blackie(x+1,y);
	del_blackie(x+1,y+1);
	del_blackie(x+1,y-1);
	del_blackie(x-1,y);
	del_blackie(x-1,y-1);
	del_blackie(x,y-1);
	del_blackie(x,y+1);
	del_blackie(x-1,y+1);
}



int main(int argc , char *argv[])
{

	FILE *fp;
	fp=fopen(argv[1],"r");
	char a;
	int clicks=0,i,j;
	while((a=fgetc(fp))!=' ')
			H=H*10+(a-48);
	while((a=fgetc(fp))!='\n')
			W=W*10+(a-48);
	long s1=0,s2=0;
	root=(struct point*)malloc(sizeof(struct point));
	root->x=2147483647;
	root->y=2147483647;
	end=root;
	char buf[1024];
	int val;
	while(val=fread(buf,sizeof(char),1024,fp))
	{
	i=0;
	while(i<val)
	{
		if(buf[i]=='0')
		{
			add(end,s2,s1);
		}
	if(buf[i]=='0'||buf[i]=='1')
	{
		s1++;
		if(s1%(W)==0){
			s1=0;
			s2++;
		}
		
	}
	i++;
	}
	}
	remover(root,2147483647,2147483647);
	//display(root);
	
	
	while(root!=NULL)
	{
		del_blackie(root->x,root->y);
		clicks++;
	}
			printf("%d\n",clicks);

	
	fclose(fp);
	return 1;

}
