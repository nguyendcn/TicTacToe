#include "game.h"

void inIt(vector<int> &GameBoard)
{
	for (int i = 0; i < 9; i++)
	{
		GameBoard.push_back(NO_VAL); // full NO_VAL
	}
}

void setX(vector<int> &GameBoard, int value/*, int h, int w*/)
{
	//GameBoard[h * maxBoxHeightGame + w] = X;
	GameBoard[value] = X_VAL;
}

void setO(vector<int> &GameBoard, int value/*, int h, int w*/)
{
	//GameBoard[h * maxBoxHeightGame + w] = O;
	GameBoard[value] = O_VAL;
}

bool isTaken(vector<int> GameBoard, int value/*, int h, int w*/)
{
	//return GameBoard[h * maxBoxHeightGame + w] == NO_VAL;
	return GameBoard[value] == NO_VAL;
}

bool isFull(vector<int> GameBoard)
{
	for (int i = 0; i < GameBoard.size(); i++)
	{
		if (GameBoard[i] == NO_VAL)
			return false;
	}
	return true;
}

SquareState checkVictory(vector<int> &GameBoard)
{
	if (GameBoard[0] == X_VAL && GameBoard[1] == X_VAL && GameBoard[2] == X_VAL)
		return X_VAL;
	if (GameBoard[0] == O_VAL && GameBoard[1] == O_VAL && GameBoard[2] == O_VAL)
		return O_VAL;
	if (GameBoard[3] == X_VAL && GameBoard[4] == X_VAL && GameBoard[5] == X_VAL)
		return X_VAL;
	if (GameBoard[3] == O_VAL && GameBoard[4] == O_VAL && GameBoard[5] == O_VAL)
		return O_VAL;
	if (GameBoard[6] == X_VAL && GameBoard[7] == X_VAL && GameBoard[8] == X_VAL)
		return X_VAL;
	if (GameBoard[6] == O_VAL && GameBoard[7] == O_VAL && GameBoard[8] == O_VAL)
		return O_VAL;

	if (GameBoard[0] == X_VAL && GameBoard[3] == X_VAL && GameBoard[6] == X_VAL)
		return X_VAL;
	if (GameBoard[0] == O_VAL && GameBoard[3] == O_VAL && GameBoard[6] == O_VAL)
		return O_VAL;
	if (GameBoard[1] == X_VAL && GameBoard[4] == X_VAL && GameBoard[7] == X_VAL)
		return X_VAL;
	if (GameBoard[1] == O_VAL && GameBoard[4] == O_VAL && GameBoard[7] == O_VAL)
		return O_VAL;
	if (GameBoard[2] == X_VAL && GameBoard[5] == X_VAL && GameBoard[8] == X_VAL)
		return X_VAL;
	if (GameBoard[2] == O_VAL && GameBoard[5] == O_VAL && GameBoard[8] == O_VAL)
		return O_VAL;

	if (GameBoard[0] == X_VAL && GameBoard[4] == X_VAL && GameBoard[8] == X_VAL)
		return X_VAL;
	if (GameBoard[0] == O_VAL && GameBoard[4] == O_VAL && GameBoard[8] == O_VAL)
		return O_VAL;
	if (GameBoard[2] == X_VAL && GameBoard[4] == X_VAL && GameBoard[6] == X_VAL)
		return X_VAL;
	if (GameBoard[2] == O_VAL && GameBoard[4] == O_VAL && GameBoard[6] == O_VAL)
		return O_VAL;

	for (int i = 0; i < 9; i++)
	{
		if(GameBoard[i] == NO_VAL)
			return NO_VAL;
	}
	return TIE_VAL;
}

void player(vector<int> &GameBoard, string player)
{
	int value;

	while(true)
	{
		if (_kbhit())
		{
			char key = _getch();

			if (key == 27)// ESC => exit
				exit(0);
			if (player.compare("I") == 0) // player 1
			{
				if ((key == 'Q' || key == 'q') && isTaken(GameBoard, 0))
					{value = 0;  break; }
				else if ((key == 'W' || key == 'w') && isTaken(GameBoard, 1))
					{value = 1;  break; }
				else if ((key == 'E' || key == 'e') && isTaken(GameBoard, 2))
					{value = 2;  break; }
				else if ((key == 'A' || key == 'a') && isTaken(GameBoard, 3))
					{value = 3;  break; }
				else if ((key == 'S' || key == 's') && isTaken(GameBoard, 4))
					{value = 4;  break; }
				else if ((key == 'D' || key == 'd') && isTaken(GameBoard, 5))
					{value = 5;  break; }
				else if ((key == 'Z' || key == 'z') && isTaken(GameBoard, 6))
					{value = 6;  break; }
				else if ((key == 'X' || key == 'x') && isTaken(GameBoard, 7))
					{value = 7;  break; }
				else if ((key == 'C' || key == 'c') && isTaken(GameBoard, 8))
					{value = 8;  break; }
			}
			else if (player.compare("II") == 0) // player 2
			{
				if ((key == 'T' || key == 't') && isTaken(GameBoard, 0))
					{value = 0;  break; }
				else if ((key == 'Y' || key == 'y') && isTaken(GameBoard, 1))
					{value = 1;  break; }
				else if ((key == 'U' || key == 'u') && isTaken(GameBoard, 2))
					{value = 2;  break; }
				else if ((key == 'G' || key == 'g') && isTaken(GameBoard, 3))
					{value = 3;  break; }
				else if ((key == 'H' || key == 'h') && isTaken(GameBoard, 4))
					{value = 4;  break; }
				else if ((key == 'J' || key == 'j') && isTaken(GameBoard, 5))
					{value = 5;  break; }
				else if ((key == 'B' || key == 'b') && isTaken(GameBoard, 6))
					{value = 6;  break; }
				else if ((key == 'N' || key == 'n') && isTaken(GameBoard, 7))
					{value = 7;  break; }
				else if ((key == 'M' || key == 'm') && isTaken(GameBoard, 8))
					{value = 8;  break; }
			}
		}
	}

	if (player.compare("I") == 0) // player 1
	{
		setX(GameBoard, value);
		drawXO(GameBoard, value);
		PlaySoundA("data\\Tic.Wav", NULL, 0x0000);
	}
	else if (player.compare("II") == 0) // player 2
	{
		setO(GameBoard, value);
		drawXO(GameBoard, value);
		PlaySoundA("data\\Toe.Wav", NULL, 0x0000);
	}
}


void playGame()
{
	system("cls");
	resizeConsole(WidthConsoleGame, HeightConsoleGame);
	AnConTro();

	vector<int> gb;

	inIt(gb);

	drawGame();

	while (checkVictory(gb) == NO_VAL)
	{
		drawPlayer(1, 10);
		drawPlayer(2, 7);
		player(gb, "I");

		if (checkVictory(gb) == X_VAL)
		{
			gotoxy(10, 20); ColorText("Player 1 win.", 12);
			PlaySoundA("data\\Win.wav", NULL, 0x0000);
			Sleep(1000);
			return;
		}
		if (isFull(gb))
		{
			gotoxy(10, 20);  ColorText("Ties", 12);
			PlaySoundA("data\\Lost.wav", NULL, 0x0000);
			Sleep(1000);
			break;
		}

		drawPlayer(1, 7);
		drawPlayer(2, 10);

		player(gb, "II");

		if (checkVictory(gb) == O_VAL)
		{
			gotoxy(10, 20); ColorText("Player 2 win.", 12);
			PlaySoundA("data\\Win.wav", NULL, 0x0000);
			Sleep(1000);
			break;
		}
	}
}

