#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
struct hanghoa
{
	char ten[20];
	int dongia;
	int soluong;
	int thanhtien;
};
typedef struct hanghoa hanghoa;
FILE *f;
char *tentep ="SO_LIEU_C";
void ghifile(int *n)
{
	hanghoa x;
	char c;
	*n=0;
	f=fopen(tentep,"wb");
	while(1)
	{
		(*n)++;
		printf("\nnhap vao ten hang hoa:");
		fflush(stdin);
		gets(x.ten);
		printf("\nnhap vao don gia:");
		scanf("%d",&x.dongia);
		printf("\nnhap vao so luong:");
		scanf("%d",&x.soluong);
		x.thanhtien=x.dongia*x.soluong;
		fwrite(&x,sizeof(hanghoa),1,f);
		printf("\nban co muon tiep tuc (y/n)");
		fflush(stdin);
		c=getchar();
		if(c=='N' || c=='n')
		break;
	}
	fclose(f);
}
void bosungfile(int *n)
{
	hanghoa x;
	(*n)++;
	f=fopen(tentep,"ab");
	printf("\n nhap vao ten hang hoa:");
	fflush(stdin);
	gets(x.ten);
		printf("\nnhap vao don gia:");
		scanf("%d",&x.dongia);
		printf("\nnhap vao so luong:");
		scanf("%d",&x.soluong);
		x.thanhtien=x.dongia*x.soluong;
		fwrite(&x,sizeof(hanghoa),1,f);
		fclose(f);
	
}
void hienthi(int n)
{
	hanghoa x;
	int tong=0;
	int i = 1;
    printf("\t\tDANH SACH HANG HOA\n");
    printf("\t|%3s|%25s|%8s|%12s|%14s|\n","STT", "Ten hang", "So luong", "Don gia", "Thanh tien");
    printf("\t|---|-------------------------|--------|------------|--------------|\n");
    f=fopen(tentep,"rb");
    for(i=0;i<n;i++)
    {
    	fread(&x,sizeof(hanghoa),1,f);
    	printf("\t|%3d|%25s|%8d|%12d|%14d|\n",i,x.ten,x.soluong,x.dongia,x.thanhtien);
    	tong+=x.thanhtien;
	}
	printf("\t%48s|%d","tongtien",tong);
	fclose(f);
}
void menu()
{
	printf("\t_______________menu_________________________\n");
	printf("\t|1.ghi vao file                            |\n");
	printf("\t|2.bo sung file                            |\n");
	printf("\t|3.hien thi file                           |\n");
	printf("\t|__________________________________________|\n");
}
int main()
{
	int chon;
	int n=0;
	while(1)
	{
		system("cls");
		menu();
		printf("\n nhap vao lua chon");
		scanf("%d",&chon);
		switch(chon)
		{
		case 1:
			system("cls");
			ghifile(&n);
			printf("\t\tan phim ban ki de ve menu");
			getch();
			break;
			case 2:
				system("cls");
		bosungfile(&n);
		
			printf("\t\tan phim ban ki de ve menu");
			getchar();
			break;
			case 3:
				system("cls");
				hienthi(n);
		
			printf("\t\tan phim ban ki de ve menu");
			getch();
				break;
			case 4:
				system("cls");
			
		
			printf("\tbye bye");
			getch();
			exit(0);	
		}	
	}
}
