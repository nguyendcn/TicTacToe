#pragma once
#include "Graphics.h"
#include "Draw.h"
#include "AIPlayer.h"

enum SquareState { NO_VAL = ' ', X_VAL = 'X', O_VAL = 'O', TIE_VAL};
//int maxHightGame = 3, maxWidthGame = 3;

struct gameBoard
{
	const int width;
	const int height;
	int GameBoard[9];
};

void inIt(vector<int> &GameBoard);

void setX(vector<int> &GameBoard, int value /*int h, int w*/);

void setO(vector<int> &GameBoard, int value /*int h, int w*/);

bool isTaken(vector<int> GameBoardint, int value /*int h, int w*/);

bool isFull(vector<int> GameBoard);

SquareState checkVictory(vector<int> &GameBoard);

void player(vector<int> &GameBoard, string player);

void playGame();