#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
struct NODE
{
	char hoten[20];
	int tuoi;
	float diemtb;
	struct NODE * next;
	
};
typedef struct NODE NODE;
NODE *dau;
NODE *cuoi;
NODE *p;


typedef struct
{char hoten[20];
	int tuoi;
	float diemtb;
}data;
void taods()
{char c;
int t;
float diem;


	do{
p=(NODE *)malloc(sizeof(NODE));
	p->next=NULL;
	printf("nhap vao ho ten:");
fflush(stdin);
gets(p->hoten);
printf("\n nhap vao tuoi ");
scanf("%d",&t);
p->tuoi=t;
printf("\n nhap vao diem tb ");
scanf("%f",&diem);
p->diemtb=diem;
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
printf("\nban co muon tiep tuc(y/n):");
fflush(stdin);
c=getchar();

}while(c=='Y' || c=='y');
}
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
			printf("\n|stt %2d:| %-10s |%-25d |%f|",i,p->hoten,p->tuoi,p->diemtb);
			i++;
			p=p->next;
		}
	}
}
void them()
{
	char t[20];
	int found=0;
	NODE *q;
	int tuoi;
	float diem;
	printf("\nnhap vao ho ten sinh vien de chen vao sau:");
	fflush(stdin);
	gets(t);
	p=dau;
	if(dau!=NULL)
	while(p!=NULL && found==0)
	{
		if(strcmp(p->hoten,t)==0) found=1 ;else p=p->next;
	} 
	else
	printf(" \nco cai gi dau ma tim");
	if(found==1)
	{
		q=(NODE*)malloc(sizeof(NODE));
			printf("nhap vao ho ten:");
fflush(stdin);
gets(q->hoten);
printf("\n nhap vao tuoi ");
scanf("%d",&tuoi);
q->tuoi=tuoi;
printf("\n nhap vao diem tb ");
scanf("%f",&diem);
q->diemtb=diem;
q->next=p->next;// nôi p voi q
p->next=q;

	}
	else
	printf("ko co sinh vien ten nhu vay");
}
void search()
{
	char t[20];
	printf("nhap vao ten can tim kiem:");
	fflush(stdin);
	gets(t);
	int dem=0;
	p=dau;
	if(dau!=NULL)
	{
		while(p!=NULL && dem==0)
		{
			if(strcmp(p->hoten,t)==0) dem=1;
			else p=p->next;
			
		}
		if(dem==1)
		{
		printf("ho ten sv la: %s",p->hoten);
		printf("\ntuoi sv la %d",p->tuoi);
		printf("\nho ten sv la %f",p->diemtb);
		}
		else
		printf("deo co nha may");
	}
	else
	printf("chua co danh sach");
}
void menu()
{
	
	printf("\n ----------------------bang menu-----------------");
	printf("\n|                                               |");
	printf("\n|1.nhap vao danh sach sinh vien                 |");
	printf("\n|2.hien thi danh sach sinh vien                 |");
	printf("\n|3.chen vao danh sach sinh vien                 |");
	printf("\n|4.tim kiem danh sach sinh vien                 |");
	printf("\n|5.sua trong danh sach sinh vien                |");
	printf("\n|6.xoa trong danh sach sinh vien                |");
	printf("\n|8.ghi file danh sach sinh vien                 |");
	printf(" \n--------------------------------------------------");
	
	
}
void xoa()
{
	char t[20];
	NODE* q;
	printf("nhap vao ten sv can xoa:");
	fflush(stdin);
	gets(t);
	int dem=0;
	p=dau;
	while(p!=NULL && dem==0)
	{
		if(strcmp(p->hoten,t)==0) dem=1;
		else
		{
			q=p;
			p=p->next;
		}
		 
			if(dem==1)
		{
		
			if(p==dau)
			{ dau=p->next;}
			
			else if(p !=dau && p!=cuoi)
		q->next=p->next;
			
			else if(p== cuoi)
			cuoi=q;
			cuoi->next=NULL;
			free(p);
		}
	
	
	}
	
}
void edit()
{
	char t[20];
	int tu;
float diem;
	printf("nhap vao ten can sua:");
	fflush(stdin);
	gets(t);
	int dem=0;
	p=dau;
	if(dau!=NULL)
	{
		while(p!=NULL && dem==0)
		{
			if(strcmp(p->hoten,t)==0) dem=1;
			else p=p->next;
			
		}
		if(dem==1)
		{
			printf("\nnhap vao ho ten:");
fflush(stdin);
gets(p->hoten);
printf("\n nhap vao tuoi ");
scanf("%d",&tu);
p->tuoi=tu;
printf("\n nhap vao diem tb ");
scanf("%f",&diem);
p->diemtb=diem;
		}
		else
		printf("deo co nha may");
	}
	else
	printf("chua co danh sach");
}
void swap(NODE *a, NODE *b)
{
	NODE temp;
	temp=*a;
	*a=*b;
	*b=temp;
	temp.next=a->next;
	a->next=b->next;
	b->next=temp.next;
}
void sapxep()
{
	NODE*q;
	p=dau;
	while(p!=NULL)
	{
		if(p->next != NULL) q=p->next;
		while(q!=NULL)
		{
			if(p->diemtb>q->diemtb)
			swap(p,q);
			q=q->next;
		}
		p=p->next;
	}
	printf("\n danh sach da duoc sap xep theo diem tb");
}
void ghifile()
{
	data x;
	char tentep[20];
	FILE *f;
	fflush(stdin);
	printf("nhap vao ten tep:");
	gets(tentep);
f=fopen(tentep,"wb");
	for(p=dau;p!=NULL;p=p->next)
	{
		strcpy(x.hoten,p->hoten);
		x.tuoi=p->tuoi;
		x.diemtb=p->diemtb;
		fwrite(&x,1,sizeof(data),f);
	}
	fclose(f);
	printf("\n da ghi xong file");
	
}
void docfile()
{
	
}
int main (int argc, char *argv[ ])
{int chon;

	while(1)
	{
		system("cls");
		menu();
		printf("\nchon chu nang");
	scanf("%d",&chon);
	switch(chon)
	{
	
		case 1:
		system("cls");
		taods();
			printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
		case 2:system("cls");
		hienthi();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
		case 3:system("cls");
		them();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
					case 4:system("cls");
	search();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
				case 5:system("cls");
	edit();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
							case 6:system("cls");
sapxep();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
										case 7:system("cls");
xoa();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
													case 8:system("cls");
ghifile();
		printf("\tBam phim bat ky de tro ve menu");
				getch();
				break;
		case 9:
				system("cls");
				printf("\tBan da chon thoat khoi chuong trinh! Bye~");
				getch();
				exit(0);
		
	}}
return 0;

}

