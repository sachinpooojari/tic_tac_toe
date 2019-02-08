#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>                                             
#include <unistd.h>                                         

int n=3;
void  show(int (*a)[n]);
int m=0;
void zero(int (*a)[n] )
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=m;


}


void Read1(int (*a)[9],int loc,int data  )
{
l2:
	if(a[0][loc-1]==2 ||a[0][loc-1]==1)
	{
		printf("invalid move ..reEntr.\n");
		//exit(0);
		scanf("%d",&loc);
	
		goto l2;
	}
	a[0][loc-1]=data;

	//	scanf("%d",&a[0][loc-1]);
}

void Read2(int (*a)[9],int data  )
{
	unsigned int loc=0;
l1:  loc=rand()%9;
     if(a[0][loc]==1 || a[0][loc]==2)
     {
	     printf("%d loc del\n",loc);	
	     goto l1;
     }
     else
	     a[0][loc]=data;

     printf("%d loc\n",loc);	
     return ;
}
void     show(int (*a)[n])
{
	int i,j;

	printf("\n\n");
	for(i=0;i<n;i++)
	{		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
			if(j!=2)
				printf(" | ");
		}
		printf("\n");
		if(i!=2)
			printf("-------------");
		printf("\n");
	}



}
unsigned char  scan_row(int (*a)[n],int num,int C)
{
	int i,j;
	int flag=0;
	for(i=0;i<n;i++)
	{	

		if(a[num][i]==C)
			flag++;
	}

	if(flag==3)
		return 1;
	else 
		return 0;

}


unsigned char  scan_col(int (*a)[n],int num,int C)
{
	int i,j;
	int flag=0;
	for(i=0;i<n;i++)
	{	

		if(a[i][num]==C)
			flag++;
		//	printf("(%d %d)",a[num][i],a[num][i+1]);
	}

	if(flag==3)
		return 1;
	else 
		return 0;

}



unsigned char  scan_diagR(int (*a)[n],int C )
{
	int i,j;
	int flag=0;
	for(i=0;i<n;i++)
	{	

		if(a[i][i]==C)
			flag++;
		//	printf("(%d %d)",a[num][i],a[num][i+1]);
	}

	if(flag==3)
		return 1;
	else 
		return 0;

}



unsigned char  scan_diagL(int (*a)[n],int C)
{
	int i,j;
	int flag=0;
	for(i=n-1;i>=0;i--)
	{	

		if(a[n-1-i][i]==C)
			flag++;
		//	printf("(%d %d)",a[n-1-i][i],a[n-i][i-1]);
	}

	if(flag==3)
		return 1;
	else 
		return 0;

}


int check(int (*a)[n],int num)
{
	//	int num=1;
	int count=0;
	if(scan_row(a,0,num))
	{		count++;
		printf("R1 ");
	}
	if(scan_row(a,1,num))
	{
		count++;
		printf("R2 ");
	}
	if(scan_row(a,2,num))
	{
		count++;
		printf("R3 ");

	}
	if(scan_col(a,0,num))
	{
		count++;
		printf("C1 ");
	}
	if(scan_col(a,1,num))
	{
		count++;
		printf("C2 ");
	}
	if(scan_col(a,2,num))
	{
		count++;
		printf("C3 ");
	}
	if(scan_diagR(a,num))
	{
		count++;
		printf("R " );
	}
	if(scan_diagL(a,num))
	{		count++;
		printf("L ");
	}
	printf("\n");


	if(count>0)
		return 1;
	else
		return 0;	
}



void main()
{
	system("clear");							

	int a[n][n];
	unsigned char status=0;
	zero(a);
	show(a);

	int i,j;

	int data=1;
	srand(getpid());

	int counter=0;
	while(1)
	{
		unsigned int loc;


		if(data==1)
		{
			printf("Enter loc \n");
			scanf("%d",&loc);
			Read1(a,loc,data);
			data =2;
		}
		else
		{	printf("computer turn \n");
			sleep(2);

			Read2(a,data);
			data=1;

		}	
		system("clear");							
		show(a);
		
		if(check(a,1))
		{
			printf("you won\n");
			exit(0);
		}	
		else if(check(a,2))
		{
			printf("computer won\n");

			exit(0);

		}
		
		counter++;
		if(counter>8)
		{
			printf("Draw Game\n");
			exit(0);
		}

	}	


}	
