#include "Menu.h"

void mButton()
{
	AnConTro();
	int Check;
	do {
		setBGColor(15);
		TextColor(0);
		gotoxy(70, 18);
		cout << " 1: Back ";
		if (_kbhit())
		{
			Check = _getch();
			if (Check == 49)
				break;
		}
	} while (true);
	setBGColor(0);
	TextColor(7);
	HienConTro();
}

bool rePlay()
{
	system("cls");
	resizeConsole(700, 400);
	AnConTro();

	drawTextGame();

	gotoxy(30, 15); cout << "Do you want replay?";

	listSelect list[2];
	list[0].data = "N0"; list[0].x = 30; list[0].y = 17;
	list[1].data = "YES"; list[1].x = 45; list[1].y = 17;

	int Choose = 0;
	while (true)
	{
		gotoxy(list[Choose].x, list[Choose].y); TextColor(10); cout << list[Choose].data; TextColor(7);
		gotoxy(list[-(Choose - 1)].x, list[-(Choose - 1)].y); cout << list[-(Choose - 1)].data;

		if (_kbhit())
		{
			int key = _getch();

			if (key == 75) //LEFT
			{
				Choose = -(Choose - 1);
			}
			else if (key == 77) // RIGHT
			{
				if (Choose == 0)
					Choose++;
				else if (Choose == 1)
					Choose--;
			}
			else if (key == 13) // Enter
			{
				return Choose;
			}
		}
	}
}

void rules()
{
	clrscr();
	drawMenu();
	drawTextGame();

	ifstream FileIn("data\\TextGame.dll", ios::in);
	int line = 9;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		if (text == "**")
			break;
		gotoxy(10, line); ColorText(text, 10);
		line++;
	}
	FileIn.close();

	mButton();
}

void info()
{
	clrscr();
	drawMenu();
	drawTextGame();

	ifstream FileIn("data\\TextGame.dll", ios::in);
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		if (text == "**")
		{
			break;
		}
	}
	int line = 10;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		gotoxy(20, line); ColorText(text, 10);
		line++;
	}
	FileIn.close();

	mButton();
}

int menuSelect()
{
	// khởi tạo menu
	vector<listSelect> menu;
	int next = 0;
	for (int count = 0; count < 5; count++)
	{
		listSelect mSelect;
		if (count == 0)
			mSelect.data = "One Play";
		else if (count == 1)
			mSelect.data = "Two Play";
		else if (count == 2)
			mSelect.data = " Rules";
		else if (count == 3)
			mSelect.data = " Info";
		else
			mSelect.data = " Quit";
		mSelect.x = 38;
		mSelect.y = 10 + next;

		menu.push_back(mSelect);
		next += 2;
	}

	while (true)
	{
		drawMenu();

		drawTextGame();

		// in menu bỏ qua Play Game
		for (int i = 1; i < menu.size(); i++)
		{
			gotoxy(menu[i].x, menu[i].y);
			cout << menu[i].data;
		}

		int count = 0, sizeOfListMenu = menu.size();
		char dChoose = 175;

		// KHởi tạo vị trí chọn ban đầu //Play Game
		gotoxy(menu[count].x - 3, menu[count].y);
		TextColor(10); cout << dChoose << " " << menu[count].data;  TextColor(7);

		// Menu

		while (true)
		{
			// Bắt key và xử lý.
			if (_kbhit())
			{
				int key = _getch();

				if (key == 80) // DOWN
				{
					gotoxy(menu[count].x - 3, menu[count].y);  	cout << "               ";
					gotoxy(menu[count].x, menu[count].y); cout << menu[count].data;

					if (count == sizeOfListMenu - 1)
						count = 0;
					else
						count++;

					gotoxy(menu[count].x, menu[count].y);     cout << "               ";
					gotoxy(menu[count].x - 3, menu[count].y);
					TextColor(10); cout << dChoose << " " << menu[count].data;  TextColor(7);
				}
				else if (key == 72) // UP
				{
					gotoxy(menu[count].x - 3, menu[count].y);  cout << "               ";
					gotoxy(menu[count].x, menu[count].y);        cout << menu[count].data;

					if (count == 0)
						count = sizeOfListMenu - 1;
					else
						count--;

					gotoxy(menu[count].x, menu[count].y);      cout << "               ";
					gotoxy(menu[count].x - 3, menu[count].y);
					TextColor(10); cout << dChoose << " " << menu[count].data;   TextColor(7);
				}
				else if (key == 13) // Enter
				{
					break;
				}
			}
		}
		return count;
	}
}