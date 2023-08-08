#pragma once
#include <bits/stdc++.h>
using namespace std;
class board {
private:
	int boardSize;
	string** Board;

public:
	board();
	board(int c1r, int c1c, int c2r, int c2c, int size);
	~board();
	
	void EnterCats(int c1r, int c1c, int c2r, int c2c);

	void printBoard(int width);

	void addAnimal(int r, int c, string name);

	bool validator(int r, int c);

	bool occupation(int r, int c);
	bool row_check(int r);
	bool column_check(int c);

	string getBoardCell(int r, int c);
};