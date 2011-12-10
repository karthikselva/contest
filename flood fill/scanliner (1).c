#include<stdio.h>
#include<string.h>
#include<sys/resource.h>
int H=0,W=0;
char *temp;
struct point
{
	long x,y;
	struct point *next;
}*root,*end;

void remover(struct point *p,long a,long b)
{
	struct point *temp;
	
	while(p->x!=a&&p->y!=b)
	{
		temp=p;		
		p=p->next;
	}
	if(p!=NULL&&p->next!=NULL)
	{
		temp->next=p->next;
		free(p);
	}
	else 
		free(p);
		
}

struct *point add(struct point *p,long a,long b)
{
	struct *point 
		
}

int whitener(char *data,int pos)
{
	
	if(*(data+pos)=='2')
		*(data+pos)='1';
		//printf(" changed ");
	// Add code for '2' here

		if((pos-W-1)>0&&(pos%W!=0)&&*(data+pos-W-1)=='0')
			*(data+pos-W-1)='2';
		if((pos-1)>0&&*(data+pos-1)=='0'&&(pos%W!=0))
			*(data+pos-1)='2';
		if(*(data+pos+W-1)=='0'&&(pos%W!=0)&&((pos+W-1)/W)<H)
			*(data+pos+W-1)='2';
	
		if((pos-W+1)>0&&*(data+pos-W+1)=='0'&&((pos+1)%W)!=0)
			*(data+pos-W+1)='2';
		if((pos-W)>0&&*(data+pos-W)=='0')
			*(data+pos-W)='2';

		if((((pos+1)/W)<H)&&((pos+1)%W)!=0&&*(data+pos+1)=='0')
			*(data+pos+1)='2';

		if(((pos+W)/W<H)&&*(data+pos+W)=='0')
			*(data+pos+W)='2';
		if(((pos+W+1)/W<H)&&((pos+1)%W)!=0&&*(data+pos+W+1)=='0')
			*(data+pos+W+1)='2';
	//Tdisplay(data);
	temp=strchr(data,'2');
	if(temp==NULL) return;
	whitener(data,temp-data);	
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
	long s1,s2;
	
	while((a=fgetc(fp))!=EOF)
		if(a=='0')end=add(end,s1,s2);
	*data='\0';


	
	printf("%d\n",clicks);
	fclose(fp);
	return 1;

}
