#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define MAX 100
typedef struct 
{
	int top;
	int data[MAX];
}STACK;

void tao(STACK *stack)
{
	stack->top=0;
}
void nhap(STACK *stack,int x )
{
	stack->data[stack->top]=x;
	stack->top++;
	
}
void hienthi(STACK *stack)
{
	int i;
	for(i=stack->top-1;i>=0;i--)
	printf("%d",stack->data[i]);
}
void coso_2(STACK *stack,int n)
{
	while(n>0)
	{
		nhap(stack,n%2);
		n/=2;
	}
}
void coso_8(STACK *stack,int n)
{
	while(n>0)
	{
		nhap(stack,n%8);
		n/=8;
	}
}
void menu()
{
	printf("menu");
	printf("\n 1.nhap vao so n\n");
	printf("2.doi sang co so 2");
	printf("\n3.doi sang co so 8");
	printf("\n4.doi sang co so 16 ");
	
}
int main()
{
	int chon;
	int n;
	STACK stack;
	 tao(&stack);
	while (1)
    {
        menu();
        scanf("%d",&chon);
        system("cls");
        switch (chon)
        {
            case 1:
                printf("\tBan da chon nhap n \n");
                while (1)
                {
                    printf("\t\tNhap n: ");
                    scanf("%d",&n);
                    if (n<=0)
                        printf("\tVui long nhap so nguyen duong\n");
                    else
                        break;
                }

                break;
            case 2:
                if (n<=0)
                {
                    printf("\tNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon doi sang co so 2\n");

                coso_2(&stack,n);
                printf("\t\t%d(10) = ",n);
               hienthi(&stack);
                printf("(2)\n");

                //Xoa Stack di
                tao(&stack);
                break;
            case 3:
                if (n<=0)
                {
                    printf("\tNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon doi sang co so 8\n");

                coso_8(&stack,n);
                printf("\t\t%d(10) = ",n);
                hienthi(&stack);
                printf("(8)\n");

                tao(&stack);
                break;

            case 4:
                if (n<=0)
                {
                    printf("\tNhap n truoc!!!\n");
                    break;
                }
                printf("\tBan da chon doi sang co so 16\n");
                printf("\t\t%d(10) = 0X%x(16)\n",n,n);
                break;
            case 0:
                exit(0);
            default:
                printf("\tBan da chon sai, vui long chon lai\n\a");
                break;
        }
        printf("\tBam phim bat ki de ve menu\n");
        getch();
        system("cls");
    }
    return 0;
}
