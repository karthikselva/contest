#include<stdio.h>
#include<string.h>
int H=0,W=0;

int return_data(int pos,char * data)
{
	if(pos>=strlen(data)||pos<=0)
		
		return '1';
	else 
		return data[pos];
}


void Tdisplay(char *t)
	{
		printf("\n\n");
		char *temp=t;
		int i,j;
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				printf("%c",*(temp+i*W+j));
				
			}
			printf("\n");
		}
	}
	
void assigner(int i,int j,char *val)
{
	if(i>=0&&j>=0&&i<W&&j<H)
	{
		if(*(val+(i*W)+j)=='0')
		{
			*(val+(i*W)+j)='2';
		}
	}
}
int whitener(int i,int j,char *data)
{
	int x,y;
	while(strchr(data,'2')!=NULL){
	
		for(x=0;x<H;x++)
		{
			for(y=0;y<W;y++)
			{
			if(((data+(x*W)+y)!=NULL)||(*(data+(x*W)+y)=='2'))
			{
			*(data+(x*W)+y)='1';
			i=x;
			j=y;
			Tdisplay(data);
			 assigner(i+1,j,data);
			 assigner(i+1,j-1,data);
			 assigner(i+1,j+1,data);
			 assigner(i-1,j,data);
			 assigner(i-1,j-1,data);
			 assigner(i-1,j+1,data);
			 assigner(i,j-1,data);
			 assigner(i,j+1,data);
			
			}
			}
		}
	}

		
}
int main(int argc , char *argv[])
{
	FILE *fp,*fp1;
	fp=fopen(argv[1],"r");
	fp1=fopen("a.out","w");
	char a;
	int clicks=0,i,j;
	
	while((a=fgetc(fp))!=' ')
			H=H*10+(a-48);
	while((a=fgetc(fp))!='\n')
			W=W*10+(a-48);

	char *data=(char *)malloc(H*W*sizeof(char *)),*head;
	head=data;
	printf("\n");
	i=0,j=0;
	while((a=fgetc(fp))!=EOF)
	{
		if(a=='0'||a=='1')
			{
				*data=a;
				data++;
			}
	}
	*data='\0';
	//Tdisplay(head);
	char *black;
	do
	{
		black=strchr(head,'0');
		if(black==NULL)
			break;
		*black='2';
		Tdisplay(head);
		whitener((black-head)/W,(black-head)%W,head);
		clicks++;
		printf(" \n\n");
	
	}while(black!=NULL);
	printf("%d",clicks);
	fprintf(fp1,"%d",clicks);
	fclose(fp);
	fclose(fp1);
	return 1;

}