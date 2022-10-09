#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <malloc.h>
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 2000
/* Ma mau
0	BLACK
1	BLUE
2	GREEN
3	AQUA
4	RED
5	PURPLE
6	YELLOW
7	WHITE
8	GRAY
9	LIGHT BLUE
*/
////Cau truc SinhVien
struct SinhVien {
	char MaSV[20];
	char MaLop[30];
	char HoTen[30];
	char NgaySinh[20];
	char QueQuan[50];
	char GioiTinh[10];
	float DiemToan;
	float DiemLy;
	float DiemHoa;
	float TB;
	char Phanloai[20];
	char XepLoai[20];
};


///// chuan hoa ngay thang nam
bool test (char *date)
{
	for (int i=0; i<10; i++) {
    if (date[i]<45 || date[i]>57) return false;
		return true;
	}
}
/////////kiem tra ngay sinh/////////////
bool testDate(char *date) {
	int kq;
	if (test(date)==1 && (strlen(date)==10)){
		int ngay = (date[0]-48)*10 + (date[1]-48); //Tinh ngay
		int thang = (date[3]-48)*10 + (date[4]-48); //Tinh thang
		int nam = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)*10 + (date[9]-48); //Tinh nam
		if (ngay < 1 || ngay > 31 || thang < 1 || thang > 12 || nam > 2018)
			return false; //Kiem tra ngay
		if(ngay > 29 && thang == 2) return false;

		//ktra thang
		switch (thang)
		{
			case 4: case 6: case 9: case 11: if (ngay>30)
				return false; break;
			case 2: if ((nam % 4 == 0 && nam % 100 != 0 ) && ngay>29) return false;
				else if (ngay>28) return false;
				break;
		}
		return true;
	}
}

//Xu ly ten
void Chuanhoa_ten(char name[]) {
	string s; s= string(name);

	//xoa ki tu dau
	while(s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}

	//xoa ki tu cuoi
	while(s[s.length() - 1] == ' ')
	{
		s.erase(s.begin() + s.length() -1);
	}
	//xoa ki tu o giua
	for(int i = 0;i<s.length(); i++)
	{
		if(s[i] == ' '&& s[i+1] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
	strcpy(name, (char*)s.c_str());
	strlwr(name); // ham chuyen chuoi thanh mang so de thuc hien thao tac chuyen ten hoa
	if(name[0]!= 0)
	{
	   name[0] = name[0] - 32;
	}
	for(int i =1; i< strlen(name) -1; i++)
	{
		if(name[i-1] == ' '&& name[i]!=' ')
		    name[i] = name[i]-32; //chuyen cac chu cai sau dau cach thanh chu in hoa
	}
}
//Xy ly Que quan
void Chuanhoa_QueQuan(char quequan[]) {
	string s;
	s= string(quequan);

	//xoa ki tu dau
	while(s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}

	//xoa ki tu cuoi
	while(s[s.length() - 1] == ' ')
	{
		s.erase(s.begin() + s.length() -1);
	}
	//xoa ki tu o giua
	for(int i = 0;i<s.length(); i++)
	{
		if(s[i] == ' '&& s[i+1] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
	strcpy(quequan, (char*)s.c_str());
	strlwr(quequan); // ham chuyen chuoi thanh mang so de thuc hien thao tac chuyen que quan
	if(quequan[0]!= 0)
	{
	   quequan[0] = quequan[0] - 32;
	}
	for(int i =1; i< strlen(quequan) -1; i++)
	{
		if(quequan[i-1] == ' '&& quequan[i]!=' ')
		    quequan[i] = quequan[i]-32; //chuyen cac chu cai sau dau cach thanh chu in hoa
	}
}
void frame(){
	 //vien cua o nhap
    int i ;
    gotoXY(24,0);
		printf("%c",218);
		for(int i=0;i<42;i++) printf("%c",196);	printf("%c\n",191);
    for(i=1;i<18;i++)
	{
	 	gotoXY(24,i);
	    printf("%c%43c\n",179,179);
	}
	gotoXY(24,i);
		printf("%c",192);
	    for(int i=0;i<42;i++)
			printf("%c",196);
			printf("%c",217);

}
void Box(int y)
{
 	//box o chu nhat dai

	gotoXY(57,y+1);
	printf("%c",218);
	
	for(int i=0;i<60;i++) printf("%c",196);
	printf("%c\n",191);
	
    gotoXY(57,y+2);
	printf("%c%61c\n",179,179);
	
    gotoXY(57,y+3);
	printf("%c",192);
	
	for(int i=0;i<60;i++) printf("%c",196);
	printf("%c",217);
}


/*void boxAdd(){
    frame();
   
	Box(1);
	gotoXY(26,1+1);         printf("Ma Lop");
	Box(4);
	gotoXY(26,4+1);         printf("Ma SV");
	Box(7);
	gotoXY(26,7+1);         printf("Ten SV");
	Box(10);
	gotoXY(26,10+1);        printf("Ngay Sinh");
	Box(13);
	gotoXY(26,13+1);        printf("Diem TB");
}*/
void board()
{
	drawBox(1,1,170,38);
	gotoXY(35,4);
	cout<<"\t\t +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ "<<endl;
	gotoXY(35,5);
	cout<<"\t\t |	   S  T  U  D  E  N  T           I  N  F  O  R  M  A  T  I  O  N   |"<<endl;
	gotoXY(35,6);
	cout<<"\t\t +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ "<<endl;
	gotoXY(10,12);
	cout<<char(16)<<" COURSE NAME:"; Box(10);
	gotoXY(10,15);
	cout<<char(16)<<" STUDENT ID NUMBER:"; 	Box(13);
	gotoXY(10,18);
	cout<<char(16)<<" NAME:";	Box(16);
	gotoXY(10,21);
	cout<<char(16)<<" BORN:"; Box(19);
	gotoXY(10,24);
	cout<<char(16)<<" ORIGIN:"; Box(22);
	gotoXY(10,27);
	cout<<char(16)<<" GENDER:"; Box(25);
	gotoXY(10,30);
	cout<<char(16)<<" MATHS'S POINT':"; Box(28);
	gotoXY(10,33);
	cout<<char(16)<<" PHYSICS'S POINT':"; Box(31);
	gotoXY(10,36);
	cout<<char(16)<<" CHEMISTRY'S POINT':"; Box(34);

}


SinhVien SV[20000], temp[20000]; //mang SinhVien
int N = 0;

//Kiem tra ma sinh vien
bool testMaSV (char *id)
{
	if(strlen(id) != 8) return false;   //Neu maSV khong dung 8 ki tu thi sai
	for (int i=0; i<8; i++) {
		if (id[i]<48 || id[i]>57) return false;  // MaSV la chu so
	}
	//MaSV truoc khong trung voi ma SV sau
	for (int i=0; i<N; i++)
		if(strcmp(id, SV[i].MaSV) == 0) {
			return false;
			break;
		}
	return true;
}

////////////////NHap thong tin sinh vien tu ban phim////////////////////////

void Nhaptubanphim() {
	Hien_contro();
	int c, i, j;
	for ( i = N; ; i++)
	{
	system("cls"); // xoa man hinh
	board();

	//Nhap ma lop thuoc 1 trong 7 lop :
	//CNTT, BDATTT, ANHTT, PTDL, MMT, HTTT, KTPM
	
	gotoXY(59,12); cout<<"                        ";
	gotoXY(59,12); fflush(stdin); gets(SV[i].MaLop);
	while(strstr(SV[i].MaLop, "CNTT1") == NULL && strstr(SV[i].MaLop, "MMT") == NULL && strstr(SV[i].MaLop, "HTTT") == NULL && strstr(SV[i].MaLop, "PTDL") == NULL && strstr(SV[i].MaLop, "KTPM") == NULL && strstr(SV[i].MaLop, "ANHTTT") == NULL && strstr(SV[i].MaLop, "BDATTT") == NULL)
	{
	    gotoXY(120,12); cout<< "STUDENT CLASS IS NOT AVAILABLE, PLEASE ENTER AGAIN";
		gotoXY(59,12); cout<<"                        ";
	    gotoXY(59,12); fflush(stdin); gets(SV[i].MaLop);
	    gotoXY(120,12); cout<< "                                                  ";
	}
	//Nhap ma sinh vien
	gotoXY(59,15); fflush(stdin); gets(SV[i].MaSV);
	while(strlen(SV[i].MaSV) != 8)
	{
	    gotoXY(120,15); cout<< "STUDENT ID ISN'T AVAILABLE, PLEASE ENTER AGAIN";
		gotoXY(59,15);  cout<<"                                             ";
	    gotoXY(59,15); fflush(stdin); gets(SV[i].MaSV);
	    gotoXY(120,15); cout<< "                                              ";
	}
	for( j = 0; j<i; j++ )
	{
		if(strstr(SV[i].MaSV, SV[j].MaSV) != NULL)
		{
        gotoXY(120,15); cout<< "STUDENT ID IS ALREADY, PLEASE ENTER AGAIN";
		gotoXY(59,15); cout<<"                        				      ";
	    gotoXY(59,15); fflush(stdin); gets(SV[i].MaSV);
	    gotoXY(120,15); cout<< "                					      ";
	}
	}

	//Nhap ho ten sinh vien
	gotoXY(59,18); fflush(stdin); gets(SV[i].HoTen);
	Chuanhoa_ten(SV[i].HoTen);
	gotoXY(59,18); cout<<"                                  ";
	gotoXY(59,18); cout<<SV[i].HoTen;

	//Nhap ngay sinh BORN
	gotoXY(59, 21); fflush(stdin); gets(SV[i].NgaySinh);
	while (testDate(SV[i].NgaySinh) != 1)
	{
       gotoXY(120,21); cout<< "DATE IS NOT AVAILABLE, PLEASE ENTER AGAIN";
	   gotoXY(59,21); cout<<"                                           ";
	   gotoXY(59, 21); fflush(stdin); gets(SV[i].NgaySinh);
	   gotoXY(120,21); cout<< "                                           ";
	}

	//Nhap que quan sinh vien ORIGIN
	gotoXY(59,24); fflush(stdin); gets(SV[i].QueQuan);
	Chuanhoa_QueQuan(SV[i].QueQuan);
	gotoXY(59,24); cout<<"                                     ";
	gotoXY(59,24); cout<<SV[i].QueQuan;
	
	//Gioi tinh
	gotoXY(59,27);
	fflush(stdin);
	gets(SV[i].GioiTinh); //INPUT
	while(strstr(SV[i].GioiTinh, "Male") == NULL && strstr(SV[i].GioiTinh, "Female") == NULL)
	{
	    gotoXY(120,27); cout<< "GENDER IS NOT AVAILABLE, PLEASE ENTER AGAIN";
		gotoXY(59,27); cout<<"                                               ";
	    gotoXY(59,27); fflush(stdin); gets(SV[i].GioiTinh);
	    gotoXY(120,27); cout<<"                                             ";
	}
	
	
	//Nhap diem Toan
	gotoXY(59,30); cin>>SV[i].DiemToan;
	while(SV[i].DiemToan<0||SV[i].DiemToan > 10)
	{
	    gotoXY(120,30); cout<< "THE POINT IS NOT AVAILABLE, PLEASE ENTER AGAIN";
		gotoXY(59,30); cout<<"                                      ";
	    gotoXY(59,30); cin>>SV[i].DiemToan;
	    gotoXY(120,30); cout<<"                                               ";

	}
	//Nhap diem Ly
	gotoXY(59,33); cin>>SV[i].DiemLy;
	while(SV[i].DiemLy<0||SV[i].DiemLy > 10)
	{
	    gotoXY(120,33); cout<< "THE POINT IS NOT AVAILABLE, PLEASE ENTER AGAIN";
		gotoXY(59,33); cout<<"                                                 ";
	    gotoXY(59,33); cin>>SV[i].DiemLy;
		gotoXY(120,33); cout<<"                                                ";
	}
	//Nhap diem Ly
	gotoXY(59,36); cin>>SV[i].DiemHoa;
	while(SV[i].DiemHoa<0||SV[i].DiemHoa > 10)
	{
	    gotoXY(120,36); cout<< "THE POINT IS NOT AVAILABLE, PLEASE ENTER AGAIN";
		gotoXY(59,36); cout<<"                                                 ";
	    gotoXY(59,36); cin>>SV[i].DiemHoa;
		gotoXY(120,36); cout<<"                                                ";
	}


    //Moi sinh vien nhap tu ban phim deu ghi vao file
	    FILE *f;
		f = fopen("input.dat","ab");
		fwrite(&SV[i], sizeof(SinhVien) , 1 , f);
		fclose(f);
		gotoXY(123,20);
		cout<<"Press ESC to exit";
		gotoXY(123,22);
		cout<<"Press any key to continue enter information"<<endl;
		fflush(stdin);
		c = getch();
		if (c == 27) break;
	}
	N = i+1;
}

//////Nhap sinh vien tu file da cho
void Nhaptufile()
{
	FILE *f;
	f  = fopen("Input.dat","rb");
	while(!feof(f))
	{
		SinhVien temp;
		bool ok = fread(&temp, sizeof(SinhVien), 1, f);
		if(ok)
		{
			SV[N] = temp;
			N ++;
		}
	}
	fclose(f);
}


//==============================================================================
////Can giua xau trong 1 pham vi rong n////////////////
void canchinh(const char s[], int n)
{
	int a, b;
	a = strlen(s);
	b = (n - a) / 2 + (n - a) % 2;
	if (b > 0)
	{
		for (int i = 0; i < n - (a + b); i++) printf(" ");
		printf("%s", s);
		for (int i = 0; i < b; i++) printf(" ");
	}
	else printf("%s", s);
}

void Ve_bang(int x, int y)
{
	gotoXY(x, y);
	for (int i = 0; i < 168; ++i)
	{
		switch (i)
		{
		case 9: case 22: case 33: case 59: case 72: case 98: case 109:
		case 118: case 129: case 142: case 153: printf("%c", 197); break;
		case 0: printf("%c", 195);                                      break;
		case 167: printf("%c", 180);                                    break;
		default: printf("%c", 196 );
		}
	}
	gotoXY(x, y + 1);
	for (int i = 0; i < 168; ++i)
	{
		switch (i)
		{
		case 0: case 9: case 22: case 33: case 59: case 72: case 98: case 109:
		case 118: case 129: case 142: case 153: case 167:
			printf("%c", 179); break;
		default: printf(" ");
		}
	}
	gotoXY(x, y + 2);
	for (int i = 0; i < 168; ++i)
	{
		switch (i)
		{
		case 9: case 22: case 33: case 59: case 72: case 98: case 109:
		case 118: case 129: case 142: case 153: printf("%c", 193); break;
		case 0: printf("%c", 192);                                      break;
		case 167: printf("%c", 217);                                    break;
		default: printf("%c", 196 );
		}
	}
}

////Cac tieu de cua bang
void tieude(int pg)
{

	system("cls");
	int x = 3, y = 7;
    gotoXY(73,3); cout<< "STUDENT'S DATABASE";

	textColor(15);
	Ve_bang(x, y);
	gotoXY(x, y);
	for (int i = 0; i < 168; ++i)
	{
		switch (i)
		{
		case 9: case 22: case 33: case 59: case 72: case 98: case 109:
		case 118: case 129: case 142: case 153:
		 printf("%c", 194); break;
		case 0: printf("%c", 218); break;
		case 167: printf("%c", 191); break;
		default: printf("%c", 196 );
		}
	}
	gotoXY(3, 8);
	printf("%c", 179);
	canchinh("NUMBER", 8);              printf("%c", 179);
	canchinh("CLASS",12);          printf("%c", 179);
	canchinh("ID",10);    printf("%c", 179);
	canchinh("NAME",25);       printf("%c", 179);
	canchinh("BORN",12);       printf("%c", 179);
	canchinh("ORIGIN",25); printf("%c", 179);
	canchinh("GENDER",10); printf("%c",179);
	canchinh("MATHS", 8); printf("%c", 179);
	canchinh("PHYSICS",10);printf("%c", 179);
	canchinh("CHEMISTRY",12);printf("%c", 179);
	canchinh("AVERAGE",10);printf("%c", 179);
	canchinh("CLASSIFY",13); printf("%c",179);
	gotoXY(78, 40);                 printf("Trang: %d", pg);
}
void xeploai(SinhVien *p)
{
    if(p->TB >= 9 && p->TB<=10)
	strcpy(p->XepLoai, "Xuat Sac");
	else if (p->TB>=8 && p->TB<9)
	strcpy(p->XepLoai, "Gioi");
	else if (p->TB>=7 && p->TB<8)
	strcpy(p->XepLoai, "Kha");
	else if (p->TB>=5 && p->TB<7)
	strcpy(p->XepLoai, "Trung Binh");
	else if (p->TB>=4 && p->TB<5)
	strcpy(p->XepLoai, "Yeu");
	else if (p->TB<4)
	strcpy(p->XepLoai, "Kem");

}
/////// In ra thong tin cua 1 sinh vien  /////////////
void Output(int i, SinhVien *p, int x, int y)
{
 	p->TB=(p->DiemHoa+p->DiemLy+p->DiemToan)/3;
	textColor(15);
	Ve_bang(x, y);
	xeploai(p);
	gotoXY(x + 4, y + 1);   cout << i + 1; //(7,8)
	gotoXY(x + 12, y + 1);   cout << p->MaLop;               fflush(stdin); //(15,8)
	gotoXY(x + 24, y + 1);  cout << p->MaSV;                fflush(stdin);
	gotoXY(x + 35, y + 1);  cout << p->HoTen;               fflush(stdin);
	gotoXY(x + 61, y + 1);  cout << p->NgaySinh;            fflush(stdin);
	gotoXY(x + 75, y + 1);  cout << p->QueQuan;            fflush(stdin);
	gotoXY(x + 101, y + 1);  cout << p->GioiTinh;            fflush(stdin);
	gotoXY(x + 111, y + 1);  cout << p->DiemToan;            fflush(stdin);
	gotoXY(x + 122, y + 1);  cout << p->DiemLy;            fflush(stdin);
	gotoXY(x + 135, y + 1);  cout << p->DiemHoa;            fflush(stdin);
	gotoXY(x + 145, y + 1);  cout << p->TB;            fflush(stdin);
	gotoXY(x + 156, y + 1);  cout << p->XepLoai;            fflush(stdin);

}


///////Sua thong tin sinh vien****************////////
void Thaydoi(int k, SinhVien *p, int i, int j)
{
	
	
	int x = 3, y = 7, m;
	Ve_bang(x, y);
	switch (i)
	{
		case 1: m = 9;   gotoXY(x + m, y + j * 2); printf("%-22s", " "); break; 
		case 2: m = 22;  gotoXY(x + m, y + j * 2); printf("%-25s", " "); break;
		case 3: m = 33;  gotoXY(x + m, y + j * 2); printf("%-33s", " "); break;
		case 4: m = 59;  gotoXY(x + m, y + j * 2); printf("%-20s", " "); break;
		case 5: m = 72; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 6: m = 98; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 7: m = 109; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 8: m = 118; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 9: m = 129; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 10: m = 149; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 11: m = 153; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
		case 12: m = 167; gotoXY(x + m, y + j * 2); printf("%-30s", " "); break;
	}
	switch (i)
	{
		case 1: gotoXY(x + m, y + j * 2); gets(p->MaLop);
			strupr(p->MaLop); break;
		case 2: gotoXY(x + m, y + j * 2); gets(p->MaSV);
			while(strlen(p->MaSV) != 8)
			{
				gotoXY(x + m, y + j * 2); printf("%-25s", " ");
				gotoXY(x + m, y + j * 2); gets(p->MaSV);
			}
			for (int i=0; i<N; i++)
		    if(strcmp(p->MaSV, SV[i].MaSV) == 0)
                {
                    gotoXY(x + m, y + j * 2); printf("%-25s", " ");
                    gotoXY(x + m, y + j * 2); gets(p->MaSV);
                }
			break;
		case 3: gotoXY(x + m, y + j * 2); gets(p->HoTen);
			Chuanhoa_ten(p->HoTen); break;
		case 4: gotoXY(x + m, y + j * 2); gets(p->NgaySinh);
			while(!testDate(p->NgaySinh))
			{
				gotoXY(x + m, y + j * 2); printf("%-20s", " ");
				gotoXY(x + m, y + j * 2); gets(p->NgaySinh);
			}
			break;
		case 5: gotoXY(x + m, y + j * 2); gets(p->QueQuan);
			Chuanhoa_QueQuan(p->QueQuan); break;
 		case 6: gotoXY(x + m, y + j * 2); gets(p->GioiTinh);
 			strupr(p->GioiTinh); break;
 		case 7: gotoXY(x + m, y + j * 2); cin >> p->DiemToan;
			while(p->TB > 10 || p->TB < 0)
			{
				gotoXY(x + m, y + j * 2); printf("%-30s", " ");
				gotoXY(x + m, y + j * 2); cin >> p->DiemToan;
			}
			break;
		case 8: gotoXY(x + m, y + j * 2); cin >> p->DiemLy;
			while(p->TB > 10 || p->TB < 0)
			{
				gotoXY(x + m, y + j * 2); printf("%-30s", " ");
				gotoXY(x + m, y + j * 2); cin >> p->DiemLy;
			}
			break;
		case 9:	gotoXY(x + m, y + j * 2); cin >> p->DiemHoa;
			while(p->TB > 10 || p->TB < 0)
			{
				gotoXY(x + m, y + j * 2); printf("%-30s", " ");
				gotoXY(x + m, y + j * 2); cin >> p->DiemHoa;
			}
			break;
		case 10: gotoXY(x + m, y + j * 2); cin >> p->TB;
			while(p->TB > 10 || p->TB < 0)
			{
				gotoXY(x + m, y + j * 2); printf("%-30s", " ");
				gotoXY(x + m, y + j * 2); cin >> p->TB;
			}
			break;
		case 11:  gotoXY(x + m, y + j * 2); cin >> p->XepLoai;
	}

}

///////Xoa 1 sinh vien//////////////
void Xoa(SinhVien *p, int j)
{
	for (int i = j; i < N - 1; i++)
	{
		p[i] = p[i + 1];
	}
	N --;
}

////////In ra danh sach toan bo sinh vien kem chuc nang sua thong tin SV/////////
void DanhSach(SinhVien *p, int n)
{
	textColor(15);
	int stt_trang = 0, sotrang = n/15 + 1;
	int cot = 1, hang = 0;
	int x = 3, y = 7;         //Toa do in sinh vien
	int A = 6, B = 10;       //Toa do sua thong tin sinh vien
	tieude(stt_trang +1);
	An_contro();
    if(sotrang == 1)
	{
		
		for (int i = stt_trang*15; i < n; i++)
		{
			y = y + 2;
			Output(i, &p[i], x, y);
		}
	}
	else
		for (int i = stt_trang*15; i < (stt_trang+1)*15; i++)
		{
			y = y + 2;
			Output(i, &p[i], x, y);
		}

	while (1)
	{
		int c, m;

		//Xac dinh vi tri can sua

		textColor(14);   //Danh dau vi tri can sua bang mau vang
		switch (cot)
		{
			case 1: m = 9;   gotoXY(A + m, B + hang * 2);
				printf("%s", p[stt_trang*15 + hang].MaLop);
				break;
			case 2: m = 19;  gotoXY(A + m, B + hang * 2);
				printf("%s", p[stt_trang*15 + hang].MaSV);
				break;
			case 3: m = 33;  gotoXY(A + m, B + hang * 2);
				printf("%s", p[stt_trang*15 + hang].HoTen);
				break;
			case 4: m = 57;  gotoXY(A + m, B + hang * 2);
				printf("%s", p[stt_trang*15 + hang].NgaySinh);
				break;
			case 5: m = 72; gotoXY(A + m, B + hang * 2);
				printf("%s", p[stt_trang*15 + hang].QueQuan);
				break;
			case 6: m = 98; gotoXY(A + m, B + hang * 2);
				printf("%s", p[stt_trang*15 + hang].GioiTinh);
				break;
			case 7: m = 109; gotoXY(A + m, B + hang * 2);
				printf("%0.2f", p[stt_trang*15 + hang].DiemToan);
				break;
			case 8: m = 118; gotoXY(A + m, B + hang * 2);
				printf("%0.2f", p[stt_trang*15 + hang].DiemLy);
				break;
			case 9: m =129; gotoXY(A + m, B + hang * 2);
				printf("%0.2f", p[stt_trang*15 + hang].DiemHoa);
				break;
			case 10: m = 149; gotoXY(A + m, B + hang * 2);
				printf("%0.2f", p[stt_trang*15 + hang].TB);
				break;
			case 11: m = 156; gotoXY(A + m, B + hang * 2);
				printf("%0.2f", p[stt_trang*15 + hang].XepLoai);
				break;
		}
		c = getch();
		switch (c)
		{
			case 97: stt_trang--;      // a - chuyen toi trang truoc
				if(stt_trang < 0) stt_trang = sotrang  - 1;
				cot = 1, hang = 0;
				break;
			case 122: stt_trang ++;     // z - chuyen toi trang sau
				if(stt_trang == sotrang ) stt_trang = 0;
				cot = 1, hang = 0;
				break;
			case 13: Hien_contro();
				Thaydoi(stt_trang*15 + hang, &p[stt_trang*15 + hang], cot, hang);
				break;
			case 224:
			{
				c = getch();
				switch (c)
				{
					case 72: hang--; break;	case 80: hang++; break; //chuyen con tro toi hang tren, duoi de sua
					case 77: cot ++; break;	case 75: cot --; break; //chuyen con tro len tren, xuong duoi de sua
					case 83: Xoa(p, stt_trang*15 + hang);
						system("cls");
						break;
				}
				if (cot > 11) cot = 0; if (cot < 1) cot = 11;
				if (hang > 14) hang = 0; if (hang < 0) hang = 14;
			}
		}
		int last;                        //Danh dau dong cuoi trang
		if(stt_trang == sotrang  - 1) last = n;
		else last = (stt_trang+1) * 15;
		x = 10, y = 7;
		system("cls");
		tieude(stt_trang +1);
		for (int i = stt_trang*15; i < last; i++)
		{
			y = y + 2;
			Output(i, &p[i], x, y);
		}
		if (c == 27)
		{
			system("cls"); level1(chon); level2(chon1);
			break;
		}
	}
}


void In_file()
{
	FILE *f;
	f = fopen("output.dat","wb");
	for(int i = 0;i < N;i++)
	{
		fwrite(&SV[i], sizeof(SinhVien) , 1 , f);
	}
	fclose(f);
}
/*
//Xu ly file
void openFileWrite(SinhVien strData){
	ofstream fileOut;
	fileOut.open("output.txt",ios::app);

	int i=0;
	fileOut<<strData.MaSV<<'|'<<strData.HoTen<<'|'<<strData.NgaySinh<<'|'<<strData.QueQuan<<'|'
	<<strData.MaLop<<'|'<<strData.GioiTinh<<'|'<<strData.DiemToan<<'|'<<strData.DiemLy<<'|'
	<<strData.DiemHoa<<'|'<<strData.TB<<'|'<<strData.XepLoai<<'|';
	fileOut.close();
}
void docTungSV(ifstream &fileIn, SinhVien &SV){
	char temp;
	fileIn>>SV.MaSV;
	fileIn>>temp;
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	getline(fileIn,SV.MaLop,'|');
	fileIn>>SV.DiemToan;
	fileIn>>temp;
	fileIn>>SV.DiemLy;
	fileIn>>temp;
	fileIn>>SV.DiemHoa;
	fileIn>>temp;
	fileIn>>SV.TB;
	fileIn>>temp;
	getline(fileIn,SV.XepLoai,'|');
}
void openFileRead(){
	ifstream fileIn;
	fileIn.open("output.txt",ios::in);
	char temp;
	fileIn>>temp;
	while(!fileIn.eof())
	{
		SinhVien temp;
		docTungSV(fileIn,temp);
		addSinhVien(temp, &dataSinhVien);
	}
	fileIn.close();
}
*/

//======================
void Capnhat()
{
	switch (chon1)
	{
	case 0: Nhaptubanphim(); system("cls"); level1(chon); level2(chon1); break;
	case 1: Nhaptufile(); MessageBox(NULL, "Done", "System", MB_OK); break;
	default: break;
	}
}

void Hienthi()
{
	switch (chon1)
	{
		case 0: DanhSach(SV, N); break;
		case 1: In_file(); MessageBox(NULL, "Done", "System", MB_OK); break;
	}
}
