
#include "Graphics.h"

void gotoxy(int x, int y)
{
	COORD co = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}
void TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void setBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void AnConTro()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void HienConTro()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void TextBT(int xGoc, int yGoc, int xDich, int yDich, char *InPut, int Delay, int Color, int Space)
{
	int i, j = 0;
	TextColor(Color);
	if (xGoc == xDich && yGoc > yDich && Space == 1)
	{
		for (j = 0; j <= strlen(InPut); j++)
		{
			if (InPut[j] != 32)
				for (i = yGoc; i >= yDich; i--)
				{
					gotoxy(xGoc, i);       _putch(InPut[j]);
					gotoxy(xGoc, i + 1);   _putch(' ');
					Sleep(Delay);
				}
			else
			{
				gotoxy(xGoc, yDich);       _putch(' ');
			}
			xGoc++;
		}
	}

	if (yDich == yGoc && xGoc > xDich && Space == 1)
	{
		for (j = 0; j <= strlen(InPut); j++)
		{
			if (InPut[j] != 32)
				for (i = xGoc; i >= xDich; i--)
				{
					gotoxy(i, yGoc);     cout << InPut[i];
					Sleep(Delay);
				}
			else { gotoxy(xGoc, yDich);     _putch(' '); }
			xDich++;
		}

	}
}

void ColorText(int number, int Color)
{
	TextColor(Color);
	cout << number;
	TextColor(7);
}
void ColorText(char Text, int Color)
{
	TextColor(Color);
	cout << Text;
	TextColor(7);
}
void ColorText(string Text, int Color)
{
	TextColor(Color);
	cout << Text;
	TextColor(7);
}

void DrawingText(int Text, int x, int y, int delay)
{
	if (Text == 65 || Text == 97)
	{
		gotoxy(x, y);     cout << "   00  ";       Sleep(delay);
		gotoxy(x, y + 1); cout << " 00  00";     Sleep(delay);
		gotoxy(x, y + 2); cout << " 00  00";     Sleep(delay);
		gotoxy(x, y + 3); cout << " 000000";     Sleep(delay);
		gotoxy(x, y + 4); cout << " 00  00";     Sleep(delay);
	}
	else if (Text == 66 || Text == 98)
	{
		gotoxy(x, y);     cout << "000000 ";     Sleep(delay);
		gotoxy(x, y + 1); cout << "00    0";     Sleep(delay);
		gotoxy(x, y + 2); cout << "000000 ";     Sleep(delay);
		gotoxy(x, y + 3); cout << "00    0";     Sleep(delay);
		gotoxy(x, y + 4); cout << "000000 ";     Sleep(delay);
	}
	else if (Text == 67 || Text == 99)
	{
		gotoxy(x, y);     cout << " 00000 ";    Sleep(delay);
		gotoxy(x, y + 1); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 2); cout << "00     ";    Sleep(delay);
		gotoxy(x, y + 3); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 4); cout << " 00000 ";    Sleep(delay);
	}
	else if (Text == 68 || Text == 100)
	{
		gotoxy(x, y);     cout << "00000  ";    Sleep(delay);
		gotoxy(x, y + 1); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 2); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 3); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 4); cout << "00000  ";    Sleep(delay);
	}
	else if (Text == 69 || Text == 101)
	{
		gotoxy(x, y);     cout << " 000000";     Sleep(delay);
		gotoxy(x, y + 1); cout << " 00    ";     Sleep(delay);
		gotoxy(x, y + 2); cout << " 000000";     Sleep(delay);
		gotoxy(x, y + 3); cout << " 00    ";     Sleep(delay);
		gotoxy(x, y + 4); cout << " 000000";     Sleep(delay);
	}
	else if (Text == 70 || Text == 102)
	{
		gotoxy(x, y);     cout << "000000";     Sleep(delay);
		gotoxy(x, y + 1); cout << "00    ";     Sleep(delay);
		gotoxy(x, y + 2); cout << "000000";     Sleep(delay);
		gotoxy(x, y + 3); cout << "00    ";     Sleep(delay);
		gotoxy(x, y + 4); cout << "00    ";     Sleep(delay);
	}

	else if (Text == 71 || Text == 103)
	{
		gotoxy(x, y);     cout << " 00000  ";   Sleep(delay);
		gotoxy(x, y + 1); cout << "00    ' ";   Sleep(delay);
		gotoxy(x, y + 2); cout << "00   000";   Sleep(delay);
		gotoxy(x, y + 3); cout << "00    0 ";   Sleep(delay);
		gotoxy(x, y + 4); cout << " 00000  ";   Sleep(delay);
	}

	else if (Text == 72 || Text == 104)
	{
		gotoxy(x, y);     cout << "00   00";    Sleep(delay);
		gotoxy(x, y + 1); cout << "00   00";    Sleep(delay);
		gotoxy(x, y + 2); cout << "0000000";    Sleep(delay);
		gotoxy(x, y + 3); cout << "00   00";    Sleep(delay);
		gotoxy(x, y + 4); cout << "00   00";    Sleep(delay);
	}
	else if (Text == 73 || Text == 105)
	{
		gotoxy(x, y);     cout << "000000 ";    Sleep(delay);
		gotoxy(x, y + 1); cout << "  00   ";    Sleep(delay);
		gotoxy(x, y + 2); cout << "  00   ";    Sleep(delay);
		gotoxy(x, y + 3); cout << "  00   ";    Sleep(delay);
		gotoxy(x, y + 4); cout << "000000 ";    Sleep(delay);
	}
	else if (Text == 75 || Text == 107)
	{
		gotoxy(x, y);     cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 1); cout << "00   00 ";   Sleep(delay);
		gotoxy(x, y + 2); cout << "00 0 0  ";   Sleep(delay);
		gotoxy(x, y + 3); cout << "0  00  ";   Sleep(delay);
		gotoxy(x, y + 4); cout << "00    00";   Sleep(delay);
	}
	else if (Text == 76 || Text == 108)
	{
		gotoxy(x, y);     cout << "00     ";    Sleep(delay);
		gotoxy(x, y + 1); cout << "00     ";    Sleep(delay);
		gotoxy(x, y + 2); cout << "00     ";    Sleep(delay);
		gotoxy(x, y + 3); cout << "00     ";    Sleep(delay);
		gotoxy(x, y + 4); cout << "0000000";    Sleep(delay);
	}
	else if (Text == 77 || Text == 109)
	{
		gotoxy(x, y);     cout << "00     00"; Sleep(delay);
		gotoxy(x, y + 1); cout << "00 0 0 00"; Sleep(delay);
		gotoxy(x, y + 2); cout << "00  0  00"; Sleep(delay);
		gotoxy(x, y + 3); cout << "00     00"; Sleep(delay);
		gotoxy(x, y + 4); cout << "00     00"; Sleep(delay);
	}
	else if (Text == 78 || Text == 110)
	{
		gotoxy(x, y);     cout << "00     00";  Sleep(delay);
		gotoxy(x, y + 1); cout << "00 0   00";  Sleep(delay);
		gotoxy(x, y + 2); cout << "00  0  00";  Sleep(delay);
		gotoxy(x, y + 3); cout << "00   0 00";  Sleep(delay);
		gotoxy(x, y + 4); cout << "00     00";  Sleep(delay);
	}
	else if (Text == 79 || Text == 111)
	{
		gotoxy(x, y);     cout << "  0000  ";   Sleep(delay);
		gotoxy(x, y + 1); cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 2); cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 3); cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 4); cout << "  0000  ";   Sleep(delay);
	}
	else if (Text == 80 || Text == 112)
	{
		gotoxy(x, y);     cout << "000000 ";    Sleep(delay);
		gotoxy(x, y + 1); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 2); cout << "00 0 0 ";    Sleep(delay);
		gotoxy(x, y + 3); cout << "00     ";    Sleep(delay);
		gotoxy(x, y + 4); cout << "00     ";    Sleep(delay);
	}
	else if (Text == 81 || Text == 113)
	{
		gotoxy(x, y);     cout << "  0000   ";     Sleep(delay);
		gotoxy(x, y + 1); cout << "00    00 ";   Sleep(delay);
		gotoxy(x, y + 2); cout << "00    00 ";   Sleep(delay);
		gotoxy(x, y + 3); cout << "00  0.00 ";   Sleep(delay);
		gotoxy(x, y + 4); cout << " 00000 00";  Sleep(delay);
	}
	else if (Text == 82 || Text == 114)
	{
		gotoxy(x, y);     cout << "000000 ";    Sleep(delay);
		gotoxy(x, y + 1); cout << "00    0";    Sleep(delay);
		gotoxy(x, y + 2); cout << "00 0 0 ";    Sleep(delay);
		gotoxy(x, y + 3); cout << "00  00 ";    Sleep(delay);
		gotoxy(x, y + 4); cout << "00   00";    Sleep(delay);
	}
	else if (Text == 83 || Text == 115)
	{
		gotoxy(x, y);     cout << "  0000 ";     Sleep(delay);
		gotoxy(x, y + 1); cout << " 00   0";     Sleep(delay);
		gotoxy(x, y + 2); cout << "   00  ";     Sleep(delay);
		gotoxy(x, y + 3); cout << "0   00.";     Sleep(delay);
		gotoxy(x, y + 4); cout << " 0000  ";     Sleep(delay);
	}
	else if (Text == 84 || Text == 116)
	{
		gotoxy(x, y);     cout << "00000000";   Sleep(delay);
		gotoxy(x, y + 1); cout << "   00   ";   Sleep(delay);
		gotoxy(x, y + 2); cout << "   00   ";   Sleep(delay);
		gotoxy(x, y + 3); cout << "   00   ";   Sleep(delay);
		gotoxy(x, y + 4); cout << "   00   ";   Sleep(delay);
	}
	else if (Text == 85 || Text == 117)
	{
		gotoxy(x, y);     cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 1); cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 2); cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 3); cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 4); cout << "  0000  ";   Sleep(delay);
	}
	else if (Text == 86 || Text == 118)
	{
		gotoxy(x, y);     cout << "00      00"; Sleep(delay);
		gotoxy(x, y + 1); cout << " 00    00 "; Sleep(delay);
		gotoxy(x, y + 2); cout << "  00  00  "; Sleep(delay);
		gotoxy(x, y + 3); cout << "   0000   "; Sleep(delay);
		gotoxy(x, y + 4); cout << "    00    "; Sleep(delay);
	}
	else if (Text == 87 || Text == 119)
	{
		gotoxy(x, y);     cout << "0   00      00"; Sleep(delay);
		gotoxy(x, y + 1); cout << " 0   00    00 "; Sleep(delay);
		gotoxy(x, y + 2); cout << "  0   00  00  "; Sleep(delay);
		gotoxy(x, y + 3); cout << "   0 0 0000   "; Sleep(delay);
		gotoxy(x, y + 4); cout << "    0   00    "; Sleep(delay);
	}
	else if (Text == 88 || Text == 120)
	{
		gotoxy(x, y);     cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 1); cout << " 00  00 ";   Sleep(delay);
		gotoxy(x, y + 2); cout << "   00   ";   Sleep(delay);
		gotoxy(x, y + 3); cout << " 00  00 ";   Sleep(delay);
		gotoxy(x, y + 4); cout << "00    00";   Sleep(delay);
	}
	else if (Text == 89 || Text == 121)
	{
		gotoxy(x, y);     cout << "00    00";   Sleep(delay);
		gotoxy(x, y + 1); cout << " 00  00 ";   Sleep(delay);
		gotoxy(x, y + 2); cout << "   00   ";   Sleep(delay);
		gotoxy(x, y + 3); cout << "   00   ";   Sleep(delay);
		gotoxy(x, y + 4); cout << "  .00.  ";   Sleep(delay);
	}
}