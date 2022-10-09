#include "Input_Output.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
/////// Ham doi  cho///////////
void swap(SinhVien *x, SinhVien *y) {
	SinhVien temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

////Ham so sanh ngay/////////
int sosanh_ngay(char *date1, char *date2)
{
	int kq;
	char *ngay1, *thang1, *nam1, *ngay2, *thang2, *nam2;
	char a[255], b[255];
	strcpy(a, date1);
	strcpy(b, date2);
	ngay1 = strtok (a, "/"); thang1 = strtok(NULL, "/"); nam1 = strtok(NULL, "/");
	ngay2 = strtok (b, "/"); thang2 = strtok(NULL, "/"); nam2 = strtok(NULL, "/");
	kq = strcmp(nam1, nam2);
	if (kq != 0) return kq;
	kq = strcmp(thang1, thang2);
	if (kq != 0) return kq;
	kq = strcmp(ngay1, ngay2);
	return kq;
}


void Dao_ten(char hoten[], char ten[])
{
	int i, j;
	char ho_dem[255] = "";
	for(i=strlen(hoten)-1; i>=0; i--)
	{
		if(hoten[i] == ' ')
		{
			strcpy(ten, hoten + 1 + i);
			for(j=0; j<=i; j++)
				ho_dem[j] = hoten[j];
			strcat(ten, " ");
			strcat(ten, ho_dem);
			break;
		}
	}
}

int sosanh_ten(char name1[], char name2[]) {
	int kq;
	char ten1[255] = "", ten2[255] = "";
	Dao_ten(name1, ten1);
	Dao_ten(name2, ten2);
	kq = strcmp(ten1, ten2);
	return kq;
}


void Bubblesort() {
	int i, j;
	switch (chon1) {
	case 0:
		for(i=0; i<N-1; i++)
			for(j=N-1; j>i; j--)
				if(strcmp(SV[j-1].MaLop, SV[j].MaLop) == 1) swap(SV + j, SV + j-1);
		break;
	case 1:
		for(i=0; i<N-1; i++)
			for(j=N-1; j>i; j--)
				if(strcmp(SV[j-1].MaSV, SV[j].MaSV) == 1) swap(SV + j, SV + j-1);
		break;
	case 2:
		for(i=0; i<N-1; i++)
			for(j=N-1; j>i; j--)
				if(sosanh_ten(SV[j-1].HoTen, SV[j].HoTen) == 1) swap(SV + j, SV + j-1);
		break;
	case 3:
		for(i=0; i<N-1; i++)
			for(j=N-1; j>i; j--)
				if(sosanh_ngay(SV[j-1].NgaySinh, SV[j].NgaySinh) == 1) swap(SV + j, SV + j-1);
		break;
	case 4:
		for(i=0; i<N-1; i++)
			for(j=N-1; j>i; j--)
				if(SV[j-1].TB > SV[j].TB) swap(SV + j, SV + j-1);
		break;
	}
};

void Selectionsort() {
	int i, j, k;
	switch (chon1) {
	case 0:
		for(i=0; i<N-1; i++) {
			k = i;
			for(j=i+1; j<N; j++)
				if(strcmp(SV[k].MaLop, SV[j].MaLop) == 1) k = j;
			if(k != i) swap(SV + k, SV + i);
		}
		break;
	case 1:
		for(i=0; i<N-1; i++) {
			k = i;
			for(j=i+1; j<N; j++)
				if(strcmp(SV[j-1].MaSV, SV[j].MaSV) == 1) k = j;
			if(k != i) swap(SV + k, SV + i);
		}
		break;
	case 2:
		for(i=0; i<N-1; i++) {
			k = i;
			for(j=i+1; j<N; j++)
				if(sosanh_ten(SV[k].HoTen, SV[j].HoTen) == 1) k = j;
			if(k != i) swap(SV + k, SV + i);
		}
		break;
	case 3:
		for(i=0; i<N-1; i++) {
			k = i;
			for(j=i+1; j<N; j++)
				if(sosanh_ngay(SV[k].NgaySinh, SV[j].NgaySinh) == 1) k = j;
			if(k != i) swap(SV + k, SV + i);
		}
		break;
	case 4:
		for(i=0; i<N-1; i++) {
			k = i;
			for(j=i+1; j<N; j++)
				if(SV[j-1].TB > SV[j].TB) k = j;
			if(k != i) swap(SV + k, SV + i);
		}
		break;
	}
}

void Insertionsort() {
	SinhVien tg;
	int i, j;
	switch (chon1) {
	case 0:
		for( i=1; i<N-1; i++) {
			tg = SV[i];
			j = i - 1;
			while(j>=0 && strcmp(SV[j].MaLop, tg.MaLop) == 1) {
				SV[j+1] = SV[j];
				j--;
			}
			SV[j+1] = tg;
		}
		break;
	case 1:
		for(i=1; i<N-1; i++) {
			tg = SV[i];
			j = i - 1;
			while(j>=0 && strcmp(SV[j].MaSV, tg.MaSV) == 1) {
				SV[j+1] = SV[j];
				j--;
			}
			SV[j+1] = tg;
		}
		break;
	case 2:
		for(i=1; i<N-1; i++) {
			tg = SV[i];
			j = i - 1;
			while(j>=0 && sosanh_ten(SV[j].HoTen, tg.HoTen) == 1) {
				SV[j+1] = SV[j];
				j--;
			}
			SV[j+1] = tg;
		}
		break;
	case 3:
		for(i=1; i<N-1; i++) {
			tg = SV[i];
			j = i - 1;
			while(j>=0 && sosanh_ngay(SV[j].NgaySinh, tg.NgaySinh) == 1) {
				SV[j+1] = SV[j];
				j--;
			}
			SV[j+1] = tg;
		}
		break;
	case 4:
		for(i=1; i<N-1; i++) {
			tg = SV[i];
			j = i - 1;
			while(j>=0 && SV[j].TB > tg.TB) {
				SV[j+1] = SV[j];
				j--;
			}
			SV[j+1] = tg;
		}
		break;
	}
};


void Quicksort(int left, int right) {
	SinhVien key = SV[(left + right)/2];
	int i = left, j = right;
	while (i < j)
	{

		switch (chon1)
		{
		case 0:
			while (strcmp(SV[i].MaLop, key.MaLop) == -1) i++;
			while (strcmp(SV[j].MaLop, key.MaLop) == 1) j--;
			if (i <= j) {
				swap(SV + i, SV + j);
				i++;
				j--;
			}
			break;
		case 1:
			while (strcmp(SV[i].MaSV, key.MaSV) == -1) i++;
			while (strcmp(SV[j].MaSV, key.MaSV) == 1) j--;
			if (i <= j) {
				swap(SV + i, SV + j);
				i++;
				j--;
			}
			break;
		case 2:
			while (sosanh_ten(SV[i].HoTen, key.HoTen) == -1) i++;
			while (sosanh_ten(SV[j].HoTen, key.HoTen) == 1) j--;
			if (i <= j) {
				swap(SV + i, SV + j);
				i++;
				j--;
			}
			break;
		case 3:
			while (sosanh_ngay(SV[i].NgaySinh, key.NgaySinh) == -1) i++;
			while (sosanh_ngay(SV[j].NgaySinh, key.NgaySinh) == 1) j--;
			if (i <= j) {
				swap(SV + i, SV + j);
				i++;
				j--;
			}
			break;
		case 4:
			while (SV[i].TB < key.TB) i++;
			while (SV[j].TB > key.TB) j--;
			if (i <= j) {
				swap(SV + i, SV + j);
				i++;
				j--;
			}
			break;
		}
	}
	if (left < j) Quicksort(left, j);
	if (i < right) Quicksort(i, right);
}

void Sapxep()
{
	switch (chon2)
	{
	case 0:
		system("cls");
		Bubblesort();
		gotoXY(10, 5);
		DanhSach(SV,N);
		getch();
		break;
	case 1:
		system("cls");
		Selectionsort();
		gotoXY(10, 5);
		DanhSach(SV,N);
		getch();
		break;
	case 2:
		system("cls");
		Insertionsort();
		gotoXY(10, 5);
		DanhSach(SV,N);
		getch();
		break;
	case 3:
		system("cls");
		Quicksort(0,N-1);
		gotoXY(10, 5);
		DanhSach(SV,N);
		getch();
		break;
	}
	done[chon1] = 1;
}

