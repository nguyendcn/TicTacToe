#include "Menu.h"
#include "AIPlayer.h"



//enum SquareState { blank = ' ', X = 'X', O = 'O' };
//
//class gameBoard
//{
//private:
//	const int WIDTH;
//	const int HEIGHT;
//	int* GameBoard;
//public:
//	gameBoard() : WIDTH(3), HEIGHT(3)
//	{
//		GameBoard = new int[9];
//		for (int i = 0; i < 9; i++)
//			*(GameBoard + i) = blank;
//	}
//	~gameBoard() { delete[] GameBoard; }
//	void setX(int h, int w);
//	void setO(int h, int w);
//	bool isTaken(int h, int w);
//	SquareState isLine();
//	void draw();
//};
//void gameBoard::setX(int h, int w)
//{
//	*(GameBoard + h*HEIGHT + w) = X;
//}
//void gameBoard::setO(int h, int w)
//{
//	*(GameBoard + h*HEIGHT + w) = O;
//}
//bool gameBoard::isTaken(int h, int w)
//{
//	return *(GameBoard + h*HEIGHT + w) != ' ';
//}
//
//SquareState gameBoard::isLine()
//{
//	if (*GameBoard == X && *(GameBoard + 1) == X && *(GameBoard + 2) == X)
//		return X;
//	if (*GameBoard == O && *(GameBoard + 1) == O && *(GameBoard + 2) == O)
//		return O;
//	if (*(GameBoard + 3) == X && *(GameBoard + 4) == X && *(GameBoard + 5) == X)
//		return X;
//	if (*(GameBoard + 3) == O && *(GameBoard + 4) == O && *(GameBoard + 5) == O)
//		return O;
//	if (*(GameBoard + 6) == X && *(GameBoard + 7) == X && *(GameBoard + 8) == X)
//		return X;
//	if (*(GameBoard + 6) == O && *(GameBoard + 7) == O && *(GameBoard + 8) == O)
//		return O;
//
//	if (*GameBoard == X && *(GameBoard + 3) == X && *(GameBoard + 6) == X)
//		return X;
//	if (*GameBoard == O && *(GameBoard + 3) == O && *(GameBoard + 6) == O)
//		return O;
//	if (*(GameBoard + 1) == X && *(GameBoard + 4) == X && *(GameBoard + 7) == X)
//		return X;
//	if (*(GameBoard + 1) == O && *(GameBoard + 4) == O && *(GameBoard + 7) == O)
//		return O;
//	if (*(GameBoard + 2) == X && *(GameBoard + 5) == X && *(GameBoard + 8) == X)
//		return X;
//	if (*(GameBoard + 2) == O && *(GameBoard + 5) == O && *(GameBoard + 8) == O)
//		return O;
//
//	if (*GameBoard == X && *(GameBoard + 4) == X && *(GameBoard + 8) == X)
//		return X;
//	if (*GameBoard == O && *(GameBoard + 4) == O && *(GameBoard + 8) == O)
//		return O;
//	if (*(GameBoard + 2) == X && *(GameBoard + 4) == X && *(GameBoard + 6) == X)
//		return X;
//	if (*(GameBoard + 2) == O && *(GameBoard + 4) == O && *(GameBoard + 6) == O)
//		return O;
//
//	return blank;
//}
//
//
//void gameBoard::draw()
//{
//	cout << endl;
//	for (int i = 0; i < HEIGHT; i++)
//	{
//		cout << (char)*(GameBoard + i*HEIGHT);
//		for (int c = 1; c < WIDTH; c++)
//			cout << " | " << (char)*(GameBoard + i*WIDTH + c);
//		cout << endl << "______" << endl;
//	}
//}
//class Game
//{
//public:
//	gameBoard* doInput(string player, gameBoard* gb);
//	bool inRange(int test);
//};
//
//gameBoard* Game::doInput(string player, gameBoard* gb)
//{
//	gb->draw();
//	string letter;
//	if (player.compare("I") == 0)
//		letter = "X";
//	else if (player.compare("II") == 0)
//		letter = "O";
//	else return gb;
//	int input1, input2;
//	do
//	{
//		do
//		{
//			cout << "\nPlayer " << player.c_str()
//				<< ", please enter a row number to put an "
//				<< letter.c_str() << ": ";
//			cin >> input1;
//		} while (!inRange(input1));
//
//		do
//		{
//			cout << "\nPlease enter a column number to put an "
//				<< letter.c_str() << ": ";
//			cin >> input2;
//		} while (!inRange(input2));
//
//	} while (gb->isTaken(input1, input2));
//
//	if (player.compare("one") == 0)
//		gb->setX(input1, input2);
//	else gb->setO(input1, input2);
//	return gb;
//}
//
//bool Game::inRange(int test)
//{
//	return test > -1 && test < 3;
//}


int main(void)
{

	while (true)
	{
		system("cls");
		AnConTro();

		int index = menuSelect();

		if (index == 0) // one play
		{
			bool rp;
			do
			{
				playWithAI();

				rp = rePlay();
			} while (rp);
		}
		else if (index == 1) //two play
		{
			bool rp;
			do
			{
				playGame();

				rp = rePlay();
			} while (rp);
		}
		else if (index == 2) //rules
		{
			rules();
		}
		else if (index == 3)//info
		{
			info();
		}
		else if (index == 4)// exit
		{
			exit(0);
		}
	}

	system("pause");
	return 0;
}