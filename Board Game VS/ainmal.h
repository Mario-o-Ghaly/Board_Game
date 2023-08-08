#pragma once
#include <iostream>
#include <string>
using namespace std;

class animal {
private:
	int rowPosition, columnPosition;
	string name;

public:
	animal();
	animal(int row, int column, string name1);

	bool boundaries(int position, int size);
	string names();

	bool move(char c, int size);
	int getRow();
	int getColumn();
};