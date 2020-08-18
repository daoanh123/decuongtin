#include<stdio.h>
#include<math.h>
#include<windows.h>
#define MAX 100

/* tinh tich hai ma tran*/
void nhap(int a[][MAX], int n, int p,char c)
{ int i;
int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("nhap vao phan tu thu %c[%d][%d] ",c,i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuat(int a[][MAX],int n,int p)
{int i;
int j;
		for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	
}
int tichmatran(int a[][MAX],int b[][MAX],int c[][MAX],int n,int p, int m)
{

	int i,j;
	int k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			
			for(k=0;k<p;k++)
			c[i][j]+=a[i][k]*b[k][j];
		}
	}
}
int main (int argc, char *argv[ ])
{
	int n,p,m;
	
	int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
	printf("nhap vao cac so n p m:\n");
	scanf("%d %d %d",&n,&p,&m);
	
	nhap(a,n,p,'a');
	
	nhap(b,p,m,'b');
	printf("ma tran A\n");
	xuat(a,n,p);
		printf("ma tran B\n");
	xuat(b,p,m);
	printf("tich hai ma tran la\n");
	tichmatran(a,b,c,n,p,m);
	xuat(c,n,m);
	

return 0;

}

