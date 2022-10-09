#include<Windows.h>
#include <iostream>
using namespace std;

void DisableResizeWindow()//ngan k cho thay doi man hinh console bang chuot
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void resizeConsole(int width, int height)//resize kich thuoc man hinh console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void DisableCtrButton(bool Close, bool Min, bool Max)//vo hieu hoa cac phim chuc nang trong console
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}


void DisableSelection()//vo hieu hoa viec boi den
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}


