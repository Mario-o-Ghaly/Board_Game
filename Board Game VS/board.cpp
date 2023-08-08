#include "board.h"

board::board() {
	boardSize = 5;
	for (int i = 0; i < boardSize; i++)
		Board = new string* [boardSize];
	for (int i = 0; i < boardSize; i++)
		*(Board + i) = new string[boardSize];

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++)
			*(*(Board + i) + j) = "-";
	}
}

board::board(int c1r, int c1c, int c2r, int c2c, int size) {
	boardSize = size; 
	for (int i = 0; i < boardSize; i++)
		Board = new string* [boardSize];
	for (int i = 0; i < boardSize; i++)
		*(Board + i) = new string[boardSize];
	EnterCats(c1r, c1c, c2r, c2c);
}

board::~board() {
	for (int i = 0; i < boardSize; i++)
		delete[] * (Board + i);
	delete[] Board;
}

void board::EnterCats(int c1r, int c1c, int c2r, int c2c) {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			*(*(Board + i) + j) = "-";
			if (i == c1r && j == c1c)
				*(*(Board + i) + j) = "C";
			if (i == c2r && j == c2c)
				*(*(Board + i) + j) = "C";
			if (i == boardSize / 2 && j == boardSize - 1)
				*(*(Board + i) + j) = "B";
		}
	}
}

void board::printBoard(int width)
{
    for(int i=0; i<boardSize; ++i){
		for(int j=0; j<boardSize; ++j){
			cout<<setw(width)<<Board[i][j];
		}
		cout<<"\n";
	}
}

void board::addAnimal(int r, int c, string name) {
	if(Board[r-1][c-1] == "-")
		Board[r-1][c-1] = name;
}

bool board::validator(int r, int c) {
	r--; c--;
	if(row_check(r) && column_check(c) && occupation(r, c))
		return true;	
	else return false;
}

bool board::occupation(int r, int c)
{
	if(getBoardCell(r, c) != "-"){
		cout<<"This position("<<r+1<<","<<c+1<<") is occupied\n";
		return false;
	}
    return true;
}

bool board::row_check(int r)
{
	if(r<0 || r>boardSize-1){
		cout<<"Row location= "<<r+1<<" is beyond limits\n";
		return false;
	}
    return true;
}

bool board::column_check(int c)
{
	if(c<0 || c>boardSize-1){
		cout<<"Column location= "<<c+1<<" is beyond limits\n";
		return false;
	}
    return true;
}

string board::getBoardCell(int r, int c) { return (*(*(Board + r) + c)); }