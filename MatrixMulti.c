#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int mat1[5][5],mat2[5][5],sol[5][5],r1,c1,r2,c2;

void accept(int mat[5][5],int num1,int num2)
{
	int i,j;
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			printf("Enter Element%d of Row%d: ",j+1,i+1);
			scanf("%d",&mat[i][j]);
		}
	}
}

void display(int mat[5][5],int num1,int num2)
{
	int i,j;
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

void multi()
{
	int i,j,k;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			for(k=0;k<c1;k++)
			{
				sol[i][j]+=(mat1[i][k]*mat2[k][j]);
			}
	    }
	}
	printf("\nFinal Matrix:\n\n");
	display(sol,r1,c2);
}


int main()
{
	do
	{
		printf("\nEnter the Number of Rows and Columns of First Matrix: ");
		scanf("%d%d",&r1,&c1);
		if(r1<1 || c1<1)
			printf("\nRows and Columns Should both be greater than 0!!!\n");
	}while(r1<1 || c1<1);
	
	accept(mat1,r1,c1);
	printf("\nFirst Matrix:\n\n");
	display(mat1,r1,c1);
	
	do
	{
		printf("\nEnter the Number of Rows and Columns of Second Matrix: ");
		scanf("%d%d",&r2,&c2);
		if(r2<1 || c2<1)
			printf("\nRows and Columns Should both be greater than 0!!!\n");
	}while(r2<1 || c2<1);
	
	while(c1!=r2)
	{
		printf("\nNumber of rows of 2nd Matrix and Number of Columns of 1st Matrix should be same!!!\nPlease Re-Enter the Number of Rows!!");
		scanf("%d",&r2);
	}
	accept(mat2,r2,c2);
	printf("\nSecond Matrix:\n\n");
	display(mat2,r2,c2);
	
	multi();
	return 0;
}
