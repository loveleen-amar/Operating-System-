#include<stdio.h>
void reader_enter();
void reader_exit();
void writer();
void writer_exit();

int rc=0,mutex=1,db=1,wr=0;

void reader_enter()
{
	char o;
	while(true)
	{
		mutex--;
		rc++;
		if(rc==1)
			db--;
		mutex++;
		printf("Reader inside\n");
		printf("Enter more readers-Y/N?");
		scanf("%s",&o);
		if(o=='N'||o=='n')
			break;	
	}
	reader_exit();
}

void reader_exit()
{
	int i,flag=100;
	char o;
	while(rc>0)
	{
		mutex--;
		rc--;
		printf("Reader exited\n");
		if(rc==0)
		{
			db++;
			flag=0;
			break;
		}
		mutex++;
		printf("Exit more readers-Y/N?");
		scanf("%s",&o);
		if(o=='n'||o=='N')
			break;
	}
	if(flag==0)
	{
		printf("1-Read or 2-Write?\n");
		scanf("%d",&i);
		if(i==1)
			reader_enter();
		else
			writer();
	}
	else
		writer();
}

void writer()
{
	int flag=100;
	char o,p;

	while(true)
	{
		if(wr!=0)
		{
			printf("Can't enter as writer already present\n'");
			flag=2;
			break;
		}
		if(db==0)
		{
			printf("Writer can't enter as reader already present\n");
			flag=1;
			break;
		}		
		else
		{
			db--;
			printf("Writer entered\n");
			wr++;
			printf("Want more writers to enter\n");
			scanf("%s",&p);
			if(p=='Y'||p=='y')
			{
				continue;
			}
		}
	}
	
	if(flag==1)
	{
		printf("Calling reader_exit()\n");
		//printf("%d\n",flag);
		reader_exit();
	}
	else if(flag==2)
	{
		printf("Calling writter exit\n");
			writer_exit();
	}
	else
		reader_enter();
	
}

void writer_exit()
{
	char o;
	db++;
	wr--;
	printf("Writer exited\n");
	printf("Enter more writers-Y/N?");
	scanf("%s",&o);
	if(o=='N'||o=='n')
		reader_enter();
	else
		writer();

}

int main()
{
	int i;
	
	printf("1-Read or 2-Write?\n");
	scanf("%d",&i);
	
	switch(i)
	{
		case 1:
			reader_enter();
			break;
		case 2:
			writer();
			break;
		default:
			printf("Wrong option entered\n");
	}
	
	return 0;
}
