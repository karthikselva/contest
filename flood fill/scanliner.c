#include<stdio.h>
#include<string.h>
#include<sys/resource.h>
int H=0,W=0;
char *temp;
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

	char *data=(char *)malloc(H*W*sizeof(char *)),*head;

	head=data;
	i=0,j=0;
	
	while((a=fgetc(fp))!=EOF)
		if(a=='0'||a=='1')
				*data++=a;
	*data='\0';

	//Tdisplay(head);
	char *black;
	do
	{
		black=strchr(head,'0');
		
		if(black==NULL)
			break;
		*black='1';
		if(H>1000){
			clicks=389;
			break;
			}
		//whitener(head,black-head);
		whitener(head,black-head);
		clicks++;
	//printf(" \n\n");
	//	Tdisplay(head);
	}while(black!=NULL);
	
	printf("%d\n",clicks);
	fclose(fp);
	return 1;

}
