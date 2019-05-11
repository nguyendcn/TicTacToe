#include "Draw.h"

void drawGame()
{
	for (int i = 0; i <= HeightGame; i++)
	{
		for (int j = 0; j <= WidthGame; j++)
		{
			if (i == 0 || i == (HeightGame / 3)|| i == (HeightGame / 3) * 2 || i == HeightGame || j == 0 || j == (WidthGame / 3) || j == (WidthGame / 3) * 2 || j == WidthGame)
			{
				gotoxy(j, i); cout << (char)219;
			}
		}
	}
}

void drawPlay( int key, int x, int y)
{
	if (key == X_VAL)
	{
		gotoxy(x, y); cout << (char)219;
		gotoxy(x - 1, y - 1); cout << (char)219;
		gotoxy(x - 1, y + 1); cout << (char)219;
		gotoxy(x + 1, y - 1); cout << (char)219;
		gotoxy(x + 1, y + 1); cout << (char)219;
	}
	else if (key == O_VAL)
	{
		for (int i = y - 1; i <= y + 1; i++)
		{
			for (int j = x - 1; j <= x + 1; j++)
			{
				if (i == y - 1 || i == y + 1 || j == x - 1 || j == x + 1)
				{
					gotoxy(j, i); cout << (char)219;
				}
			}
		}
	}
}

void drawXO(vector<int> gb,int index)
{
	int x, y;
	if (index >= 0 && index <= 2)
		y = 3;
	else if (index > 2 && index <= 5)
		y = 9;
	else if (index > 5 && index <= 8)
		y = 15;

	if (index == 0 || index == 3 || index == 6)
		x = 4;
	else if (index == 1 || index == 4 || index == 7)
		x = 12;
	else if (index == 2 || index == 5 || index == 8)
		x = 20;

	drawPlay(gb[index], x, y);
}

void drawPlayer(int player, int color)
{
	int rowPlayer1 = 5;
	int rowPlayer2 = 12;
	string player2[] = { "|      ", "|.===. ", "{}o o{}", "--(_)--" };
	string player1[] = { "     . ", " ,-_-| ", "([o o])", "--(_)--" };
	if (player == 1)
	{	
		gotoxy(WidthGame + 3, rowPlayer1 - 2); cout << "PLAYER 1:  X";

		for (int i = 0; i < 4; i++)
		{
			gotoxy(WidthGame + 3, rowPlayer1++); ColorText(player1[i], color);
		}
	}
	else if (player == 2)
	{
		gotoxy(WidthGame + 3, rowPlayer2 - 2); cout << "PLAYER 2:  O";


		for (int i = 0; i < 4; i++)
		{
			gotoxy(WidthGame + 3, rowPlayer2++); ColorText(player2[i], color);
		}
	}
}

void drawMenu()
{
	resizeConsole(WidthConsoleMenu, HeightConsoleMenu);
	AnConTro();

	char dmap = 219;
	// vẽ khung viền
	for (int height = 0; height <= HeightMenu; height++)
	{
		for (int width = 0; width <= WidthMenu; width++)
		{
			if (height == 0 || height == HeightMenu || width == 0 || width == WidthMenu)
			{
				gotoxy(width, height);   cout << dmap;
			}
		}
	}
}

void drawTextGame()
{
	ifstream FileIn("data\\Text.IN", ios::in);
	if (FileIn.fail())
	{
		cout << "ERROR file data.";
		Sleep(5000);
		exit(0);
	}

	int line = 2;
	while (!FileIn.eof())
	{
		gotoxy(15, line++);
		string text;
		getline(FileIn, text);
		cout << text << endl;
	}
	FileIn.close();
}