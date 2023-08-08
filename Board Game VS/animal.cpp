#include "ainmal.h"
animal::animal() { rowPosition = 0, columnPosition = 0; }
animal::animal(int row, int column, string name1) { rowPosition = row-1; columnPosition = column-1; name += name1; }

bool animal::boundaries(int position, int size) { if (position > size - 1 || position < 0) return false; else return true; }
string animal::names() { return name; }
bool animal::move(char c, int size) {
	if (c == 'U') {
		return (boundaries(--rowPosition, size));
	}
	if (c == 'D') {
		return (boundaries(++rowPosition, size));
	}
	if (c == 'R') {
		return (boundaries(++columnPosition, size));
	}
	if (c == 'L') {
		return (boundaries(--columnPosition, size));
	}
	return true;
}
int animal::getRow() { return rowPosition; }
int animal::getColumn() { return columnPosition; }