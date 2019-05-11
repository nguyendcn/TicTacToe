#pragma once
#include "game.h"

struct AIMove
{
	AIMove() {};
	AIMove(int Score) : score(Score) {};
	int index;
	int score;
};

void performMove(vector<int> &gameBoard);
void playWithAI();