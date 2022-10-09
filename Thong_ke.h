#include "Search.h"

///// Ve bang thong ke theo ma lop
void Bang_MaLop()
{
	textColor(14);
	system("cls");
	gotoXY(75,2); printf("THONG KE THEO MA LOP");
	gotoXY(45, 5);
	for (int i = 0; i < 70; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 218);            break;
		case 19: case 50: printf("%c", 194);   break;
		case 69: printf("%c", 191);            break;
		default: printf("%c", 196);            break;
		}
	}
	gotoXY(45, 6);                printf("%c", 179);
	canchinh("MA LOP", 18);       printf("%c", 179);
	canchinh("TEN LOP", 30);      printf("%c", 179);
	canchinh("SO SINH VIEN", 18); printf("%c", 179);
	gotoXY(45, 7);
	for (int i = 0; i < 50; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 192);             break;
		case 19: case 50: printf("%c", 193);   break;
		case 69: printf("%c", 217);            break;
		default: printf("%c", 196);            break;
		}
	}
}

//////Dien thong tin van bang ma lop************//
void Theo_MaLop(int m, char s1[], char s2[], int y)
{
	textColor(14);
	gotoXY(45, 5 + y * 2);
	for (int i = 0; i < 70; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 195);             break;
		case 19: case 50: printf("%c", 197);   break;
		case 69: printf("%c", 180);            break;
		default: printf("%c", 196);            break;
		}
	}
	gotoXY(45, 6 + y * 2); printf("%c", 179);
	canchinh(s1, 18);
	gotoXY(64, 6 + y * 2); printf("%c", 179);
	canchinh(s2, 30);
	gotoXY(95, 6 + y * 2);
	printf("%c        %d", 179, m);
	gotoXY(114, 6 + y * 2); printf("%c", 179);
	gotoXY(45, 7 + y * 2);
	for (int i = 0; i < 70; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 192);             break;
		case 19: case 50: printf("%c", 193);   break;
		case 69: printf("%c", 217);            break;
		default: printf("%c", 196);            break;
		}
	}
}

////////Ve bang thong ke hoc luc/////////////
void Bang_HocLuc()
{
	textColor(14);
	system("cls");
	gotoXY(72,2); cout<<"THONG KE THEO HOC LUC";
	gotoXY(20, 5);
	for (int i = 0; i < 130; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 218);    break;
		case 19: case 41: case 63: case 85: case 107:
			printf("%c", 194);   break;
		case 129: printf("%c", 191);   break;
		default: printf("%c", 196);   break;
		}
	}
	gotoXY(20, 6); printf("%c", 179);
	gotoXY(39, 6); printf("%c", 179);
	canchinh("XUAT SAC", 21); printf("%c", 179);
	canchinh("GIOI", 21); printf("%c", 179);
	canchinh("KHA", 21); printf("%c", 179);
	canchinh("TRUNG BINH", 21); printf("%c", 179);
	canchinh("YEU", 21); printf("%c", 179);
	gotoXY(20, 7);
	for (int i = 0; i < 130; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 218);    break;
		case 19: printf("%c", 195); break;
		case 30: case 52: case 74: case 96: case 118:
			printf("%c", 194);   break;
		case 41: case 63: case 85: case 107:
			printf("%c", 197);   break;
		case 129: printf("%c", 180);   break;
		default: printf("%c", 196);   break;
		}
	}
	gotoXY(20, 7); printf("%c", 179);
	canchinh("MA LOP", 18);
	gotoXY(20, 8); printf("%c", 179);
	gotoXY(39, 8); printf("%c", 179);
	canchinh("SL", 10);     printf("%c", 179);
	canchinh("%", 10);      printf("%c", 179);
	canchinh("SL", 10);     printf("%c", 179);
	canchinh("%", 10);      printf("%c", 179);
	canchinh("SL", 10);     printf("%c", 179);
	canchinh("%", 10);      printf("%c", 179);
	canchinh("SL", 10);     printf("%c", 179);
	canchinh("%", 10);      printf("%c", 179);
	canchinh("SL", 10);     printf("%c", 179);
	canchinh("%", 10);      printf("%c", 179);
	gotoXY(20, 9);
	for (int i = 0; i < 130; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 192);    break;
		case 19: case 30: case 41: case 52: case 63: case 74: case 85: case 96: case 107: case 118:
			printf("%c", 193);   break;
		case 129: printf("%c", 217);   break;
		default: printf("%c", 196);   break;
		}
	}
}

///////////////Dien so lieu vao bang hoc luc
void Theo_HocLuc(int m,char s[], int SX, int G, int K, int TB, int Y, int y)
{
	textColor(14);
	gotoXY(20, 7 + y * 2);
	for (int i = 0; i < 130; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 195);    break;
		case 19: case 30: case 41: case 52: case 63: case 74: case 85: case 96: case 107: case 118:
			printf("%c", 197); break;
		case 129: printf("%c", 180);   break;
		default: printf("%c", 196);   break;
		}
	}
	gotoXY(20, 8 + y * 2); printf("%c", 179);
		canchinh(s, 18);
	gotoXY(39, 8 + y * 2);  printf("%c    %d", 179, SX);//so xuat sac cua 1 lop
	gotoXY(50, 8 + y * 2);  printf("%c   %0.2f", 179, (float)SX*100/(float)m); //Ti le sinh vien SX
	gotoXY(61, 8 + y * 2);  printf("%c    %d", 179, G); //So luong SV gioi
	gotoXY(72, 8 + y * 2);  printf("%c   %0.2f", 179, (float)G*100/(float)m);  //ti le SV gioi
	gotoXY(83, 8 + y * 2);  printf("%c    %d", 179, K); //SO luong SV kha
	gotoXY(94, 8 + y * 2);  printf("%c   %0.2f", 179, (float)K*100/(float)m);  //Ti le SV kha
	gotoXY(105, 8 + y * 2); printf("%c    %d", 179, TB); //So luong SV TB
	gotoXY(116, 8 + y * 2); printf("%c   %0.2f", 179, (float)TB*100/(float)m); //Ti le SV TB
	gotoXY(127, 8 + y * 2); printf("%c    %d", 179, Y); //So luong SV yeu
	gotoXY(138, 8 + y * 2); printf("%c   %0.2f", 179, (float)Y*100/(float)m); // Ti le SV yeu
	gotoXY(149, 8 + y * 2); printf("%c", 179);
	gotoXY(20, 9 + y * 2);
	for (int i = 0; i < 130; i++)
	{
		switch (i)
		{
		case 0: printf("%c", 192);    break;
		case 19: case 30: case 41: case 52: case 63: case 74: case 85: case 96: case 107: case 118:
			printf("%c", 193);   break;
		case 129: printf("%c", 217);   break;
		default: printf("%c", 196);   break;
		}
	}
}
void Thongke()
{
	system("cls");
	int m = 0, y = 1;
	int i, j, k;
	for(i=0; i<N-1; i++) {
		k = i;
		for(j=i+1; j<N; j++)
			if(strcmp(SV[k].MaLop, SV[j].MaLop) == 1) k = j;
		if(k != i) swap(SV + k, SV + i);
	}
	switch (chon1)
	{
	case 0:
		Bang_MaLop();
		for (i = 0; i < N-1; i++)
		{
			SinhVien x = SV[i];
			int j = i;
			while (j < N && strcmp(SV[j + 1].MaLop, x.MaLop) == 0)
			{
				j ++;
			}
			m = j - i + 1;
			Theo_MaLop(m, SV[i].MaLop, SV[i].MaLop, y);
			i = i + m - 1;
			y ++;
			m = 0;
		}
		if(strcmp(SV[N-1].MaLop, SV[N-2].MaLop) != 0)
			Theo_MaLop(1, SV[N-1].MaLop, SV[N-1].MaLop, y);
		Theo_MaLop(N," ", "Tong", y);
		getch(); system("cls"); level1(chon); level2(chon1);
		break;
	case 1:
		int TSX = 0, TG = 0, TK = 0, TTB = 0, TY = 0;
		int SX = 0, G = 0, K = 0, TB = 0, Y = 0;

		Bang_HocLuc();
		for (i = 0; i < N-1; i++)
		{
			SinhVien x = SV[i];
			int j = i;
			while (j < N && strcmp(SV[j + 1].MaLop, x.MaLop) == 0)
			{
				j ++;
			}
			m = j - i + 1;
			for (k = i; k<=j; k++)
			{
				if (SV[k].TB>= 9)   SX ++;
				if (SV[k].TB >= 8 && SV[k].TB < 9)       G ++;
				if (SV[k].TB >= 6.5 && SV[k].TB< 8)        K ++;
				if (SV[k].TB >= 5 && SV[k].TB < 6.5) TB ++;
				if (SV[k].TB < 5)        Y ++;
			}
			Theo_HocLuc(m, SV[i].MaLop, SX, G, K, TB, Y, y);
			TSX += SX; TG += G; TK += K; TTB += TB; TY += Y;
			i = i + m - 1;
			y ++;
			m = 0;
			SX = 0, G = 0, K = 0, TB = 0, Y = 0;
		}
		if(strcmp(SV[N-1].MaLop, SV[N-2].MaLop) != 0)
		{
			if (SV[N-1].TB >=9)   { SX ++; TSX ++;}
			if (SV[N-1].TB < 9 && SV[N-1].TB >= 8)       { G ++; TG ++;}
			if (SV[N-1].TB < 8 && SV[N-1].TB >= 6.5)        { K ++; TK ++;}
			if (SV[N-1].TB < 6.5 && SV[N-1].TB >= 5) { TB ++; TTB ++;}
			if (SV[N-1].TB < 5)        { Y ++; TY ++;}
			Theo_HocLuc(1, SV[N-1].MaLop, SX, G, K, TB, Y, y);
		}
		Theo_HocLuc(N, "Tong", TSX, TG, TK, TTB, TY, y);
		getch(); system("cls"); level1(chon); level2(chon1);
		break;
	}
	getch();
}
