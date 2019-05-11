#include "AIPlayer.h"

AIMove getBestMove(vector<int> &GameBoard, int player)
{
	SquareState rv = checkVictory(GameBoard);
	if (rv == O_VAL)
		return AIMove(10);
	else if (rv == X_VAL)
		return AIMove(-10);
	else if (rv == TIE_VAL)
		return AIMove(0);

	vector<AIMove> moves;

	for (int i = 0; i < maxBoxHeightGame * maxBoxWidthGame; i++)
	{
		if (GameBoard[i] == NO_VAL)
		{
			AIMove items;
			items.index = i;
			GameBoard[i] = player;

			if (player == X_VAL)
				items.score = getBestMove(GameBoard, O_VAL).score;
			else if (player == O_VAL)
				items.score = getBestMove(GameBoard, X_VAL).score;

			moves.push_back(items);
			GameBoard[i] = NO_VAL;
		}
	}

	int bestMove = 0;
	if (player == O_VAL)
	{
		int bestScore = INT_MIN;
		int size = moves.size();
		for (int i = 0; i < size; i++)
		{
			if (moves[i].score > bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	else if (player == X_VAL)
	{
		int bestScore = INT_MAX;
		int size = moves.size();
		for (int i = 0; i < size; i++)
		{
			if (moves[i].score < bestScore)
			{
				bestMove = i;
				bestScore = moves[i].score;
			}
		}
	}
	return moves[bestMove];
}

void performMove(vector<int> &gameBoard)
{
	AIMove bestMove = getBestMove(gameBoard, O_VAL);
	gameBoard[bestMove.index] = O_VAL;

	drawXO(gameBoard, bestMove.index);
	PlaySoundA("data\\Toe.Wav", NULL, 0x0000);
}

void playWithAI()
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
				PlaySoundA("data\\Lose.wav", NULL, 0x0000);
				Sleep(1000);
				break;
			}

			drawPlayer(1, 7);
			drawPlayer(2, 10);

			performMove(gb);

			if (checkVictory(gb) == O_VAL)
			{
				gotoxy(10, 20); ColorText("AI win.", 12);
				PlaySoundA("data\\Win.wav", NULL, 0x0000);
				Sleep(1000);
				break;
			}
		}
}