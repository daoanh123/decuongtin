#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct NODE
{
	char hoten[20];
	char que[40];
	float diemtb;
	struct NODE* next;
};
typedef struct NODE NODE;
NODE *dau,*cuoi,*p;
void hienthi()
{
	int i=1;
	if(dau==NULL)
	printf("lam deo gi co danh sach");
	else
	{p=dau;
		printf("--------------danh sach sinh vien---------------------------");
		while(p!=NULL)
		{ 
			printf("\n|stt %2d:| %-10s |%-25s |%f|",i,p->hoten,p->que,p->diemtb);
			i++;
			p=p->next;
		}
	}
}
void taods()
{
	float x;
	char c;
	do{
	p=(NODE*)malloc(sizeof(NODE));
	p->next=NULL;
	printf("nhap vao ho ten sv:");
	fflush(stdin);
	gets(p->hoten);
	printf("\n nhap vao quen quan sv:");
	gets(p->que);
	printf("\n nhap vao diemtb:");
	scanf("%f",&x);
	p->diemtb=x;
	if(dau==NULL)
	{
		dau=p;
		cuoi=p;
	}
	else
	{
		cuoi->next=p;
		cuoi=p;
	}
	printf("ban co muon tiep tuc ko(y/n)");
	fflush(stdin);
	c=getchar();
	}while( c=='y'|| c=='Y');
}
void suadiem()
{
	char t[20];
float x;
	int dem=0;
	printf("nhap vao ten sinh vien can sua diem");
	fflush(stdin);
	gets(t);
	while(p!=NULL  && dem==0)
	{
		if(strcmp(p->hoten,t)==0) dem=1;
		else{
			p=p->next;
			
			
		}
	
	if(dem==1)
	{
		printf("\nnhap vao diem tb: ");
		scanf("%f",&x);
			p->diemtb=x;
	}	
}
}
void menu()
{
	   printf("_________________BANG MENU______________________");
	printf("\n| 1.tao danh sach lien ket                      |");
	printf("\n| 2.sua diemtb trong lien ket                   |");
	printf("\n| 3.hien thi trong lien ket                     |");
	printf("\n| 4.thoat khoai chuong trinh                    |");
	printf("\n|_______________________________________________|");	
}
int main (int argc, char *argv[ ])
{
	int chon;
	while(1)
	{
		system("cls");
		menu();
		printf("\n chon chuc nang:");
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
					system("cls");
				taods();
				printf("\tan phim bat ki de quay lai mennu:");
				getch();
				break;
			case 2:
					system("cls");
				suadiem();
				printf("\tan phim bat ki de quay lai mennu:");
				getch();
				break;
			case 3:
					system("cls");
				hienthi();
				printf("\tan phim bat ki de quay lai mennu:");
				getch();
				break;
			case 4:
			system("cls");
				printf("\tBan da chon thoat khoi chuong trinh! Bye~");
				getch();
				exit(0);	
		}
		
	}
	
	}




