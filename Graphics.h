#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <MMSystem.h>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

#define text_Key                "NguyenPTIT"
#define maxTextQuestion         56
#define maxTextAnswer           18
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define WidthConsole            950
#define HeightConsole           400
#define WidthMenu               80
#define HeightMenu              20
#define WidthConsoleMenu        700
#define HeightConsoleMenu       400
#define WidthGame               24
#define HeightGame              18
#define WidthConsoleGame        400
#define HeightConsoleGame       400
#define maxBoxHeightGame        3
#define maxBoxWidthGame         3

void gotoxy(int x, int y);
void TextColor(WORD color);
void setBGColor(WORD);
void resizeConsole(int width, int height);
void clrscr();
void AnConTro();
void HienConTro();
void TextBT(int xGoc, int yGoc, int xDich, int yDich, char *InPut, int Delay, int Color, int Space);
void ColorText(int, int);
void ColorText(char, int);
void ColorText(string, int);
