

#include "Sort.h"

int t[1000];
SinhVien tmp[MAX];


//chuyen thanh chu in hoa het
char* toUpwer(char* a) {
	for (int i = 0; i <= strlen(a); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] = a[i] - 32;
		}
	}
	return a;
}
////////Tim kiem chinh xac//////////////
void Chinhxac() {
	int  j = 0, t[1000];
	int dem = 0;
	char s[30];
	float diem;
	switch (chon1)
	{
	case 0:
		system("cls");
		gotoXY(1,3); cout<< "Ma lop can tim"; Box(2);
	    gotoXY(22, 3);Hien_contro();
		fflush(stdin); gets(s); toUpwer(s);
		for (int i = 0; i < N; i++)
		{
			if (strstr(SV[i].MaLop, s) != NULL)
			{
				t[j] = i;
				tmp[j] = SV[i];
				j++; dem++;
			}
		}
		break;
	case 1:
		system("cls");
		gotoXY(1,3); cout<< "Ma SV can tim"; Box(2);
	    gotoXY(22,3); Hien_contro();
		fflush(stdin); gets(s);
		for (int i = 0; i < N; i++)
		{
			if (strstr(SV[i].MaSV, s) != NULL)
			{
				t[j] = i;
				tmp[j] = SV[i];
				j++; dem ++;
			}
		}
		break;
	case 2:
		system("cls");
		gotoXY(1,3); cout<< "Ho ten can tim"; Box(2);
	    gotoXY(22,3); Hien_contro();
		fflush(stdin); gets(s);
		Chuanhoa_ten(s);
		for (int i = 0; i < N; i++)
		{
			if (strstr(SV[i].HoTen, s) != NULL)
			{
				t[j] = i;
				tmp[j] = SV[i];
				j++; dem++;
			}
		}
		break;
	case 3:
		system("cls");
		gotoXY(1,3); cout<< "Ngay sinh can tim"; Box(2);
	    gotoXY(22, 3); Hien_contro();
		fflush(stdin); gets(s);
		for (int i = 0; i < N; i++)
		{
			if (strstr(SV[i].NgaySinh, s) != NULL)
			{
				t[j] = i;
				tmp[j] = SV[i];
				j++; dem++;
			}
		}
		break;
	case 4:
		system("cls");
		gotoXY(1,3); cout<< "Diem TB can tim"; Box(2);
	    gotoXY(22, 3); Hien_contro();
		cin>>diem;
		for (int i = 0; i < N; i++)
		{
			if (SV[i].TB == diem)
			{
				t[j] = i;
				tmp[j] = SV[i];
				j++; dem++;
			}
		}
		break;
	default: break;
	}

	//in ra danh sach sinh vien tim kiem duoc
if (dem != 0)
	{
		textColor(15);
	int stt_trang = 0, sotrang = dem/10 + 1;
	int cot = 1, hang = 0;
	int x = 10, y = 7;         //Toa do in sinh vien
	tieude(stt_trang +1);
	An_contro();
    if(sotrang == 1)
	{
		for (int i = stt_trang*10; i < dem; i++)
		{
			y = y + 2;
			Output(i, &tmp[i], x, y);
		}
	}
	else
		for (int i = stt_trang*10; i < (stt_trang+1)*10; i++)
		{
			y = y + 2;
			Output(i, &tmp[i], x, y);
		}
    while (1)
	{
		int c;
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

		}
		int last;                        //Danh dau dong cuoi trang
		if(stt_trang == sotrang  - 1) last = dem;
		else last = (stt_trang + 1) * 10;
		x = 10, y = 7;
		system("cls");
		tieude(stt_trang +1);
		for (int i = stt_trang*10; i < last; i++)
		{
			y = y + 2;
			Output(i, &tmp[i], x, y);
		}
		if (c == 27)
		{
			system("cls"); level1(chon); level2(chon1);
			break;
		}
		getch();

    }
	}
};
void Test(int mid, int n, char* s, float diem)
{
	if (n)
	{
		int i, j, k = 0;
		i = j = mid;
		switch (chon1)
		{
		case 0:
			while (strstr(SV[i].MaLop, s)) i++;
			while (strstr(SV[j].MaLop, s)) j--;
			break;
		case 1:
			while (strstr(SV[i].MaSV, s)) i++;
			while (strstr(SV[j].MaSV, s)) j--;
			break;
		case 2:
			while (strstr(SV[i].HoTen, s)) i++;
			while (strstr(SV[j].HoTen, s)) j--;
			break;
		case 3:
			while (strstr(SV[i].NgaySinh, s)) i++;
			while (strstr(SV[j].NgaySinh, s)) j--;
			break;
		case 4:
			while (SV[i].TB < diem) i++;
			while (SV[j].TB > diem) j--;
			break;
		}
		for (int t = j + 1; t < i; t++)
		{
			tmp[k] = SV[t];
			k++;
		}
		system("cls");
	}
}


////// Tim kiem gan dung//////////////

void Gan_dung(){
	SinhVien ListNearly[1000];
    int j = 0, dem = 0;
    switch(chon1)
    {
	 case 2:
	     char name[30];
         draw("       Nhap tu khoa :    ", 12, 137, 12);
		 drawBox6();
         gotoXY(137,17);
			cout<<char(16); 
			gotoXY(139,17);
           Hien_contro(); fflush(stdin); gets(name); Chuanhoa_ten(name);
		for (int i = 0; i < N; i++)
		{

			char *pdest;
			pdest = strstr(SV[i].HoTen , name);
			if(pdest != NULL )
            {
                t[j] = i;
				ListNearly[j] = SV[i];
				j++; dem++;
            }
		}
         break;
     case 0:
         char className[30];
		    draw("       Nhap tu khoa     ", 12, 137, 12);
		    drawBox6();
         gotoXY(137,17);
			cout<<char(16); 
			gotoXY(139,17); Hien_contro(); fflush(stdin); gets(className);  toUpwer(className);
            for (int i = 0; i < N; i++)
            {
			char *pdest;
			pdest = strstr(SV[i].MaLop , className);
			if(pdest != NULL )
            {
                t[j] = i;
				ListNearly[j] = SV[i];
				j++; dem++;
            }
	        }
	        break;
	    case 1:
	        char id[20];
	        draw("       Nhap tu khoa     ", 12, 137, 12);	drawBox6();
         	gotoXY(137,17);
			cout<<char(16); 
			gotoXY(139,17); Hien_contro(); fflush(stdin); gets(id);
        for (int i = 0; i < N; i++)
            {
			char *pdest;
			pdest = strstr(SV[i].MaSV , id);
			if(pdest != NULL )
            {
                t[j] = i;
				ListNearly[j] = SV[i];
				j++; dem++;
            }
		}
		break;
	    case 3:
            char ngay[20];
	        draw("       Nhap tu khoa     ", 12, 137, 12);	drawBox6();
            gotoXY(137,17);
			cout<<char(16); 
			gotoXY(139,17);  Hien_contro(); fflush(stdin); gets(ngay);
        for (int i = 0; i < N; i++)
            {
			char *pdest;
			pdest = strstr(SV[i].NgaySinh, ngay);
			if(pdest != NULL )
            {
                t[j] = i;
				ListNearly[j] = SV[i];
				j++; dem++;
            }
		}
		break;
		case 4:
            float diem;
            draw("       Nhap tu khoa     ", 12, 137, 12); 	drawBox6();
            gotoXY(137,17);
			cout<<char(16); 
			gotoXY(139,17);  Hien_contro(); cin>>diem;
            for (int i = 0; i < N; i++)
            {
			if(diem == SV[i].TB)
            {
                t[j] = i;
				ListNearly[j] = SV[i];
				j++; dem++;
            }
		}
		break;
    }
		if (dem != 0)
	{
	    system("cls");
		textColor(15);
	int stt_trang = 0, sotrang = dem/10 + 1;
	int cot = 1, hang = 0;
	int x = 10, y = 7;         //Toa do in sinh vien
	tieude(stt_trang +1);
	An_contro();
    if(sotrang == 1)
	{
		for (int i = stt_trang*10; i < dem; i++)
		{
			y = y + 2;
			Output(i, &ListNearly[i], x, y);
		}
	}
	else
		for (int i = stt_trang*10; i < (stt_trang+1)*10; i++)
		{
			y = y + 2;
			Output(i, &ListNearly[i], x, y);
		}
    while (1)
	{
		int c;
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

		}
		int last;                        //Danh dau dong cuoi trang
		if(stt_trang == sotrang  - 1) last = dem;
		else last = (stt_trang + 1) * 10;
		x = 10, y = 7;
		system("cls");
		tieude(stt_trang +1);
		for (int i = stt_trang*10; i < last; i++)
		{
			y = y + 2;
			Output(i, &ListNearly[i], x, y);
		}
		if (c == 27)
		{
			system("cls"); level1(chon); level2(chon1);
			break;
		}
		getch();

    }
	}
}

void  BinarySearch()
{
	char s[255], p[255];
	float diem;

	if (done[chon1] == 0)
	{
		system("cls");
		gotoXY(70, 20);
		printf("Danh sach chua duoc sap xep!!!");
		gotoXY(70, 21);
		printf("Ban co muon sap xep? (y/n)" );
		char c = getch();
		if (c == 'y') {
			Selectionsort();
			for(int i =0; i<= 5; i++) done[i] = 0;
			done[chon1] = 1;
		}
		else {
			system("cls");
			return ;
		}
	}
	int find = 0;
	int left = 0;
	int right = N - 1;
	draw("       Tu khoa:        ", 11, 60, 30);
	gotoXY(88, 31); Hien_contro();
	switch (chon1)
		{
		case 0:
			fflush(stdin); gets(s);
			strupr(s);
			while (left <= right)
			{
				int mid = (left + right) / 2;
//				if (strcmp(SV[mid].MaLop, s) == 0) { find = 1; Test(mid, s, diem); break;}
				if (strcmp(SV[mid].MaLop, s) == 1) right = mid - 1;
				if (strcmp(SV[mid].MaLop, s) == -1) left = mid + 1;
			}
			if (find == 0)
			{
				system("cls");
				gotoXY(70, 20);
				printf("Khong tim thay!" );
				getch(); system("cls");
			}
			break;
		case 1:
			fflush(stdin); gets(s);
			while (left <= right)
			{
				int mid = (left + right) / 2;
//				if (strcmp(SV[mid].MaSV, s) == 0) { find = 1; Test(mid, s, diem); break;}
				if (strcmp(SV[mid].MaSV, s) == 1) right = mid - 1;
				if (strcmp(SV[mid].MaSV, s) == -1) left = mid + 1;
			}
			if (find == 0)
			{
				system("cls");
				gotoXY(70, 20);
				printf("Khong tim thay!" );
				getch(); system("cls");
			}
			break;
		case 2:
			fflush(stdin); gets(s);
			while (left <= right)
			{
				int mid = (left + right) / 2;
//				if (sosanh_ten(SV[mid].HoTen, s) == 0) { find = 1; Test(mid, s, diem); break;}
				if (sosanh_ten(SV[mid].HoTen, s) == 1) right = mid - 1;
				if (sosanh_ten(SV[mid].HoTen, s) == -1) left = mid + 1;
			}
			if (find == 0)
			{
				system("cls");
				gotoXY(70, 20);
				printf("Khong tim thay!" );
				getch(); system("cls");
			}
			break;
		case 3:
			fflush(stdin); gets(s);
			while (left <= right)
			{
				int mid = (left + right) / 2;
//				if (sosanh_ngay(SV[mid].NgaySinh, s) == 0) { find = 1; Test(mid, s, diem); break;}
				if (sosanh_ngay(SV[mid].NgaySinh, s) == 1) right = mid - 1;
				if (sosanh_ngay(SV[mid].NgaySinh, s) == -1) left = mid + 1;
			}
			if (find == 0)
			{
				system("cls");
				gotoXY(70, 20);
				printf("Khong tim thay!" );
				getch(); system("cls");
			}
			break;
		case 4:
			cin>>diem;
			while (left <= right)
			{
				int mid = (left + right) / 2;
//				if (SV[mid].TB == diem) { find = 1; Test(mid, s, diem); break;}
				if (SV[mid].TB > diem) right = mid - 1;
				if (SV[mid].TB < diem) left = mid + 1;
			}
			if (find == 0)
			{
				system("cls");
				gotoXY(70, 20);
				printf("Khong tim thay!" );
				getch(); system("cls");
			}
			break;
		}
}
void Timkiem()
{
	switch (chon2)
	{
    case 0: Gan_dung(); system("cls"); break;
	case 1: Chinhxac(); system("cls"); break;
	}
}
