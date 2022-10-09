#include "Thong_ke.h"
#include"console.h"
#include<Windows.h>
void Chuongtrinh()
{
	switch (chon)
	{
	case 0: Capnhat(); break;
	case 1: Hienthi(); break;
	case 2: Sapxep(); break;
	case 3: Timkiem(); break;
	case 4: Thongke(); break;
	case 5: break;
	}
}

int main()
{
	system("chcp 850");//dinh dang lai bo ma
	SetConsoleTitle("POINTS MANAGEMENT"); //dat ten console
	resizeConsole(1280,780); //frame cua console
	DisableResizeWindow(); //ngan k cho thay doi man hinh console bang chuot
	DisableSelection(); //vo hieu hoa viec boi den
	DisableCtrButton(0,1,1); //vo hieu hoa cac phim chuc nang trong console

	drawBox(1,1,170,38);
	system("color 07");
	//batdau();
	control();
    Nhaptufile();
	control();
	Chuongtrinh();
}
