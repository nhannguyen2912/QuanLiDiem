#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;
////////////////////Khung menu///////////////////////

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
void Chuongtrinh();
int sort[6][100];
int n[] = {11,11,11,11,11,11 };
int chon = 0, chon1 = 0, chon2 = 0;    //chon cac muc trong menu cap 0, 1, 2
int x1 = 0;
int done[] = {0, 0, 0, 0, 0};

//////////////Cac lenh dieu khien///////////////
void control2(int chon);
void control3(int chon);
void control4(int chon);


///////////////ham to mau//////////////////
void textColor (int c)
{
	SetConsoleTextAttribute(Console, c);
}


////////////Di chuyen con tro chuot den toa do x,y////////////////
void gotoXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(Console, pos);
}
/////////////Ham hien con tro////////////////
void Hien_contro()
{
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(Console, &info);
	info.bVisible = true;
	SetConsoleCursorInfo(Console, &info);
}

//////////////Ham an con tro/////////////////////
void An_contro()
{
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(Console, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(Console, &info);
}
///////////////Ve khung/////////////////////




/////////Lenh thoat chuong trinh bang hop thoai/////////////////
void thoat()
{
 	 /* int msgboxID = MessageBox(NULL, "Thoat chuong trinh?", "THOAT", MB_OKCANCEL);
	switch (msgboxID)
	{
	case IDCANCEL:
		break;
	case IDOK:
	textColor(12);
	system("cls");
	textColor(11);
	gotoXY(55,3);
	printf("HY VONG BAN HAI LONG VOI CHUONG TRINH NAY!!!");
	Sleep(500);
	gotoXY(75,5);
	printf("Good bye!!");
	Sleep(500);
	gotoXY(72,7);
	printf("SEE YOU AGAIN!!!");
	Sleep(1000);*/
	exit(0);
}
void drawBox(int x, int y, int w, int h)
{
	if (h<=1||w<=1)
	   return;
	   
	   //khung ngang
	for (int ix=x; ix<=x+w; ix++)
	{
		gotoXY(ix,y);
		cout<<char(176);
		gotoXY(ix,y+h);
		cout<<char(176);
	}
	//khung ngang chia doi
	for (int x=1; x<171; x++)
	{
		gotoXY(x,10);
		cout<<char(176);
	}
	//khung doc duoi
	for (int y=10; y<40; y++)
	{
		gotoXY(50,y);
		cout<<char(176);
	}
	//gotoXY(50,9);
	//cout<<char(194);

	//gotoXY(50,25);
	//cout<<char(193);

	//khung doc
	for (int iy=y; iy<=y+h; iy++)
	{
		gotoXY(x,iy);
		cout<<char(176);
		gotoXY(x+w,iy);
		cout<<char(176);
	}
	
	/*gotoXY(x,y);
	cout<<char(218);
	gotoXY(x+w,y);
	cout<<char(191);
	gotoXY(x,y+h);
	cout<<char(192);
	gotoXY(x+w,y+h);
	cout<<char(217);*/
}

void ve(char *s, int c, int i, int j)
{
 textColor(c);
	gotoXY(i, j);
	for (int a = 2; a<=60 ;a++)
	printf("%c",205); //42, 196, 205

	gotoXY(i, j + 1);
    printf("%-40s\n", s);

	gotoXY(i, j + 2);
	for (int a = 2; a<=60 ;a++)
	printf("%c", 205);
}

void draw(const char *s, int c, int i, int j)
{
 textColor(c);
	gotoXY(i, j);
	for (int a = 2; a<=30;a++)
		printf("%c", 205); //42, 196, 205
	gotoXY(i, j + 1);
		printf("%c%-28s%c\n", 186, s, 186);
	gotoXY(i, j + 2);
	for (int a = 2; a<=30;a++)
		printf("%c", 205);
	//

	//goc duoi phai
	for (int b=14; b<=30;b+=3)
	{
		gotoXY(39,b);
		textColor(6);
		cout<<char(188);

	}
	//goc tren trai
	for (int d=12; d<=27; d+=3)
	{
		gotoXY(10,d);
		textColor(6);
		cout<<char(201);
	}
	
	//  goc duoi trai
	for (int e=14; e<=30; e+=3)
	{
		gotoXY(10,e);
		textColor(6);
		cout<<char(200);
	}
	
	// day mui ten
	for (int z=13;z<=30;z+=3)
	{
	 	gotoXY(12,z);
		textColor(6);
		cout<<char(16);
	}
	
	for (int z=13;z<=30;z+=3)
	{
	 	gotoXY(37,z);
  		textColor(6);
		cout<<char(17);
	}
	
	//tren phai
	for (int i=12;i<=27;i+=3)
	{
		gotoXY(39,i);
		textColor(6);
		cout<<char(187);
	}
}
void drawBox2()
{
	//goc tren trai
	for (int d=12; d<=17; d+=3)
	{
		gotoXY(58,d);
		textColor(6);
		cout<<char(201);
	}
	//  goc duoi trai
	for (int e=14; e<=17; e+=3)
	{
		gotoXY(58,e);
		textColor(6);
		cout<<char(200);
	}

	//tren phai
	for (int i=12;i<=17;i+=3)
	{
		gotoXY(87,i);
		textColor(6);
		cout<<char(187);
	}
	//duoi phai
	for (int b=14; b<=17;b+=3)
	{
		gotoXY(87,b);
		textColor(6);
		cout<<char(188);
		}
}
void drawBox3()
{
	//goc tren trai
	for (int d=12; d<=26; d+=3)
	{
		gotoXY(58,d);
		textColor(12);
		cout<<char(201);
	}
	//  goc duoi trai
	for (int e=14; e<=26; e+=3)
	{
		gotoXY(58,e);
		textColor(12);
		cout<<char(200);
	}

	//tren phai
	for (int i=12;i<=26;i+=3)
	{
		gotoXY(87,i);
		textColor(12);
		cout<<char(187);
	}
	//duoi phai
	for (int b=14; b<=26;b+=3)
	{
		gotoXY(87,b);
		textColor(12);
		cout<<char(188);
		}
}
void drawBox4()
{
	for (int y=10; y<40; y++)
	{
		gotoXY(95,y);
		cout<<char(176);
	}
	//goc tren trai
	for (int d=12; d<=23; d+=3)
	{
		gotoXY(100,d);
		textColor(12);
		cout<<char(201);
	}
	//  goc duoi trai
	for (int e=14; e<=23; e+=3)
	{
		gotoXY(100,e);
		textColor(12);
		cout<<char(200);
	}

	//tren phai
	for (int i=12;i<=23;i+=3)
	{
		gotoXY(129,i);
		textColor(12);
		cout<<char(187);
	}
	//duoi phai
	for (int b=14; b<=23;b+=3)
	{
		gotoXY(129,b);
		textColor(12);
		cout<<char(188);
		}
}
void drawBox5()
{
	//goc tren trai
	for (int d=12; d<=17; d+=3)
	{
		gotoXY(100,d);
		textColor(6);
		cout<<char(201);
	}
	//  goc duoi trai
	for (int e=14; e<=17; e+=3)
	{
		gotoXY(100,e);
		textColor(6);
		cout<<char(200);
	}

	//tren phai
	for (int i=12;i<=17;i+=3)
	{
		gotoXY(129,i);
		textColor(6);
		cout<<char(187);
	}
	//duoi phai
	for (int b=14; b<=17;b+=3)
	{
		gotoXY(129,b);
		textColor(6);
		cout<<char(188);
	}
	
	for (int y=10; y<40; y++)
	{
		gotoXY(95,y);
		textColor(6);
		cout<<char(176);
	}
}
void drawBox6()
{
	//	goc tren trai
		gotoXY(137,12);
		textColor(6);
		cout<<char(201);
	//  goc duoi trai
		gotoXY(137,14);
		textColor(6);
		cout<<char(200);
	//	tren phai
		gotoXY(166,12);
		textColor(6);
		cout<<char(187);

		gotoXY(166,14);
		textColor(6);
		cout<<char(188);
}
//////////////menu cap 1 gom 6 muc/////////////////////
void level1(int color)
{
	int x = 10, y = 9, m = 0;
	int c=6;
	n[x1] = 15;
	n[color] = 12;
	An_contro();
	gotoXY(60, 5);
	{
	textColor(12);
	gotoXY(10,2);
	cout<<" _______   _______   ___   __    _   _______         __   __   _______   __    _   _______   _______   _______   __   __   _______   __    _   _______ "<<"\n"; gotoXY(10,3);
	cout<<"|       | |       | |   | |  |  | | |       |       |  |_|  | |   _   | |  |  | | |   _   | |       | |       | |  |_|  | |       | |  |  | | |       |"<<"\n"; gotoXY(10,4);
	cout<<"|    _  | |   _   | |   | |   |_| | |_     _|       |       | |  |_|  | |   |_| | |  |_|  | |    ___| |    ___| |       | |    ___| |   |_| | |_     _|"<<"\n"; gotoXY(10,5);
	cout<<"|   |_| | |  | |  | |   | |       |   |   |         |       | |       | |       | |       | |   | __  |   |___  |       | |   |___  |       |   |   |  "<<"\n"; gotoXY(10,6);
	cout<<"|    ___| |  |_|  | |   | |  _    |   |   |         |       | |       | |  _    | |       | |   ||  | |    ___| |       | |    ___| |  _    |   |   |  "<<"\n"; gotoXY(10,7);
	cout<<"|   |     |       | |   | | | |   |   |   |         | ||_|| | |   _   | | | |   | |   _   | |   |_| | |   |___  | ||_|| | |   |___  | | |   |   |   |  "<<"\n"; gotoXY(10,8);
	cout<<"|___|     |_______| |___| |_|  |__|   |___|         |_|   |_| |__| |__| |_|  |__| |__| |__| |_______| |_______| |_|   |_| |_______| |_|  |__|   |___|  "<<"\n";
	}
	gotoXY(101,37);
	cout<<"#POWERED BY NGUYEN THIEN NHAN - SECURITY OF INFORMATION SYSTEM - 56"<<endl;
	draw("     DATABASE UPDATE    ", n[0], x, y + 3 * (m+=1));
	draw("     DATABASE DISPLAYING  ", n[1], x, y + 3 * (m+=1));
	draw("     DATABASE SORTING  ", n[2], x, y + 3 * (m+=1));
	draw("     DATABASE SEARCHING ", n[3], x, y + 3 * (m+=1));
	draw("     DATABASE ANALYSIST ", n[4], x, y + 3 * (m+=1));
	draw("            EXIT           ", n[5], x, y + 3 * (m+=1));
	x1 = color;
}

void Loading()
{
	char a=178, b=219;
	gotoXY(80,4);
	textColor(4);
	cout<<"Loading...\n";
	Sleep(1000);

	gotoXY(65,4);
	
	for (int i=0; i < 50; i++)
		cout<<a;
	gotoXY(65,4);
	textColor(2);
	for (int j=0; j < 50; j++)
		{
			cout<<b;
			Sleep(50);
		}
	gotoXY(80,6);
	Sleep(250);
		textColor(3);
	cout<<"LOADING SUCCESSFUL !!!";
}
void batdau(){
	system("cls");
	gotoXY(0,0);
	textColor(3);
	gotoXY(55,2);
	string s ="W E L C O M E   T O   G R A D E 'S   C O U R S E   M A N A G E M E N T";
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i];
		Sleep(50);
	}
	textColor(6);
	gotoXY(3,3);
	cout<<"Press button ENTER to continue";
	Sleep(10);
	cin.ignore();
	Loading();
	cout<<"\n\n";
	//in hinh
	ifstream file1;
	file1.open("mta.txt", ios_base::in);
	string line1;
	while (!file1.eof())
	{
		getline(file1, line1);
		textColor(7);
		cout << line1 << endl;
		Sleep(90);
	}
	file1.close();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	textColor(6);
	gotoXY(20,12);
	cout<<"B O    Q U O C    P H O N G";
	gotoXY(25,15);
	cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)
	<<char(219)<<char(219)<<char(219);
	gotoXY(17,18);
	cout<<"H O C   V I E N   K Y   T H U A T";
	gotoXY(27,20);
	cout<<"Q U A N   S U";
	gotoXY(18,22);
	cout<<" ( MILITARY TECHNICAL ACADEMY )";
	gotoXY(118,11);
	cout<<char(16)<<" STUDENT'S NAME : NGUYEN THIEN NHAN";
	gotoXY(118,13);
	cout<<char(16)<<" STUDENT'S CLASS: SECURITY OF INFORMATION SYSTEM";
	gotoXY(118,16);
	cout<<"* USER GUIDE:";
	gotoXY(121, 18);
	cout<<char(175)<<" USING THE BUTTON "<<char(24)<<" "<<char(25)<<" TO MOVE";
	gotoXY(121, 20);
	cout<<char(175)<<" USING THE BUTTON 'ENTER' TO CHOOSE";
	gotoXY(121, 22);
	cout<<char(175)<<" USING THE BUTTON "<<char(27)<<" "<<char(25)<<" TO BACK OR DO THIS PATH";
	gotoXY(121, 24);
	cout<<char(175)<<" USING THE BUTTON 'ESC' TO EXIT";
	gotoXY(123, 27);
	cout<<char(3)<<" THANKS YOU FOR USING OUR PRODUCT "<<char(3);
	
	getch();
	
	system("cls");
}
///////////Ham dieu khien toan bo chuong trinh///////////////////
void control()
{
	An_contro();
	drawBox(1,1,170,38);
	int c;
	while (1)
	{
		if (chon < 0) chon = 5; if (chon > 5) chon = 0;
		level1(chon);
		c = getch();
		if (c == 13)
		{
			if (chon != 5) control2(chon);
				else thoat();
		}
		if (c == 27) thoat();
		if (c == 224)
		{
			c = getch();
			switch (c)
			{
			case 72: chon--; break;                                     //Up
			case 80: chon++; break;                                     //Down
			case 77: if (chon != 5)
			{
			 	control2(chon); break; 									//Right
			}
				else {thoat(); break;}
			}
		}
	}
}
//////////menu cap 2/////////////////
void level2(int color)
{
	int x = 33, y = 12, m = 0;
	n[x1] = 15; n[color] = 12;
	An_contro();
	switch (chon)
	{
	case 0:
		drawBox(1,1,170,38);
		
		draw("       INPUT DEVICE   ", n[0], x + 25, y + 3 * (m++));
		draw("       FROM FILE     ", n[1], x + 25, y + 3 * (m++));
		drawBox2();
		break;
	case 1:
		drawBox(1,1,170,38);
		draw("     DISPLAY ON CONSOLE     ", n[0], x + 25, y + 3 * (m++));
		draw("     EXTRACT INTO FILES     ", n[1], x + 25, y + 3 * (m++));
		drawBox2();
		break;
		
	case 2:
		drawBox(1,1,170,38);
		draw("     BY CLASS      ", n[0], x + 25, y + 3 * (m++));
		draw("     BY ID    ", n[1], x + 25, y + 3 * (m++));
		draw("     BY NAME       ", n[2], x + 25, y + 3 * (m++));
		draw("     BY BORN DATE     ", n[3], x + 25, y + 3 * (m++));
		draw("     BY AVERAGE     ", n[4], x + 25, y + 3 * (m++));
		drawBox3();
		break;
	
	case 3:
		drawBox(1,1,170,38);
		draw("     BY CLASS      ", n[0], x + 25, y + 3 * (m++));
		draw("     BY ID    ", n[1], x + 25, y + 3 * (m++));
		draw("     BY NAME       ", n[2], x + 25, y + 3 * (m++));
		draw("     BY BORN DATE     ", n[3], x + 25, y + 3 * (m++));
		draw("     BY AVERAGE     ", n[4], x + 25, y + 3 * (m++));
		drawBox3();
		break;
		

	case 4:
		drawBox(1,1,170,38);
		draw("     BY CLASS      ", n[0], x + 25, y + 3 * (m++));
		draw("     BY ID    ", n[1], x + 25, y + 3 * (m++));
		draw("     BY NAME       ", n[2], x + 25, y + 3 * (m++));
		draw("     BY BORN DATE     ", n[3], x + 25, y + 3 * (m++));
		draw("     BY AVERAGE     ", n[4], x + 25, y + 3 * (m++));
		drawBox3();
		break;
		
	}
	x1 = color;
}
////////////menu cap 3//////////////
void level3(int color)
{
	int x = 50 , y = 12, m = 0;
	n[x1] = 15; n[color] = 12;
	An_contro();
	switch (chon)
	{
	case 2:
		drawBox(1,1,170,38);
		draw("     BURBLE SORT    ", n[0], x + 50, y + 3 * (m++) );
		draw("     SELECT SORT       ", n[1], x + 50, y + 3 * (m++) );
		draw("     INSERT SORT      ", n[2], x + 50, y + 3 * (m++) );
		draw("     QUICK SORT       ", n[3], x + 50, y + 3 * (m++) );
		drawBox4();
		break;
	case 3:
		//drawBox(1,1,170,38);
		draw("     SEQUENTIAL SEARCH  ", n[0], x + 50, y + 3 * (m++) );
		draw("     BINARY SEARCH  ", n[1], x + 50, y + 3 * (m++) );
		drawBox5();
		break;
	}
	x1 = color;
}
//=================================================================================
void control2(int chon)
{
	int c;
	level1(chon);
	while (5)
	{
		switch (chon)
		{
		case 0: {if (chon1 < 0) chon1 = 1; if (chon1 > 1) chon1 = 0; break;}//them SV
		case 1: {if (chon1 < 0) chon1 = 1; if (chon1 > 1) chon1 = 0; break;}//in SV
		case 2: {if (chon1 < 0) chon1 = 4; if (chon1 > 4) chon1 = 0; break;}//ND sap xep
		case 3: {if (chon1 < 0) chon1 = 4; if (chon1 > 4) chon1 = 0; break;}//ND tim kiem
		case 4: {if (chon1 < 0) chon1 = 4; if (chon1 > 4) chon1 = 0; break;}//ND thong ke
		}
		level2(chon1);
		c = getch();
		if (c == 13)
		{
			if ( chon == 0 || chon == 2 || chon == 3) control3(chon1);
			else Chuongtrinh();
		}
		if (c == 27) thoat();
		if (c == 224)
		{
			c = getch();
			switch (c)
			{
			case 72: chon1--; break;                                   //Up
			case 80: chon1++; break;                                   //Down
			case 75: system("cls");
			drawBox(1,1,170,38);
		 	chon1 = 5; control(); break;       //left
			case 77:                                                   //Right
				if (chon == 2 || chon == 3) control3(chon1);
				else Chuongtrinh(); break;
			}
		}
	}
}
//===========================================================================
void control3(int chon1)
{
	int c;
	while (5)
	{
		switch (chon)
		{
		case 2: {if (chon2 < 0) chon2 = 3; if (chon2 > 3) chon2 = 0; break;}     //cach sap xep
		case 3: {if (chon2 < 0) chon2 = 1; if (chon2 > 1) chon2 = 0; break;}     //cach tim kiem
		}
		level1(chon);
		level2(chon1);
		level3(chon2);
		c = getch();
		if (c == 13) {
		Chuongtrinh();
		}     //phim enter
		if (c == 27) ;             //phim ESC
		if (c == 224)
		{
			c = getch();
			switch (c)
			{
			case 72: chon2--; break;
			case 80: chon2++; break;
			case 75: system("cls");  chon2 = 4; control2(chon) ; break;
			case 77: Chuongtrinh();  break;
			}
		}
	}
}
