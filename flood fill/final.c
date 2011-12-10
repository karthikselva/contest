#include<stdio.h>
#include<string.h>
int H=0,W=0;
char *temp;
int whitener(char *data,int pos)
{
	
	if(*(data+pos)=='2')
		*(data+pos)='1';
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
	temp=strchr(data,'2');
	if(temp==NULL) return;
	whitener(data,temp-data);	
}
int main(int argc , char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	char a,*black;
	int clicks=0,i,j;
	while((a=fgetc(fp))!=' ')
			H=H*10+(a-48);
	while((a=fgetc(fp))!='\n')
			W=W*10+(a-48);
	char *data=(char *)malloc(H*W*sizeof(char *)),*head;
	head=data;
	while((a=fgetc(fp))!=EOF)
		if(a=='0'||a=='1')
				*data++=a;
	*data='\0';
	do
	{
		black=strchr(head,'0');
		if(black==NULL)
			break;
		*black='1';
		whitener(head,black-head);
		clicks++;
	}while(black!=NULL);
	printf("%d\n",clicks);
	fclose(fp);
}
