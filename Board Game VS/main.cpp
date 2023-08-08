#include "ainmal.h"
#include "board.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	int c1r, c1c, c2r, c2c;
	int size, animalsNum, row, column, max;
	string animalName, movements;
	cout << "The board size is N*N dimension, where N ranges between 9 and 12\nPlease enter N: ";
	cin >> size;
	while (size != 9 && size != 10 && size != 11 && size != 12) {
		cout << "The size has to be an integer between 9 and 12" << endl << "Enter the size again: ";
		cin >> size;
	}
	board game(-1, -1, -1, -1, size);

	cout<<"The board looks like this: \n";
	game.printBoard(2);

	cout << "For the position of the cats>> ";
	while(true){
		cout << "\n\tEnter cat 1 row: ";
		cin >> c1r;
		cout << "\tEnter cat 1 column: ";
		cin >> c1c;
		cout << "\n\tEnter cat 2 row: ";
		cin >> c2r;
		cout << "\tEnter cat 2 column: ";
		cin >> c2c;
		c1r--; c1c--; c2r--; c2c--;
		game.EnterCats(c1r, c1c, c2r, c2c);
		cout<<"\n";
		if(c1r == c2r && c1c == c2c){
			cout<<"The two cats cannot be on the same position\n";
			continue;
		}

		if(game.row_check(c1r) && game.column_check(c1c) && game.row_check(c2r) && game.column_check(c2c))
			break;
		
	}
		cout<<"After entering the cats positions, the board now looks like this: \n";
		game.printBoard(2);

	cout << "\nEnter the number of animals: ";
	max = 0;
	cin >> animalsNum;
	animal* animals = new animal[animalsNum];
	string* read = new string[animalsNum];
	for (int i = 0; i < animalsNum; i++) {
		cout << "For animal " << i + 1 << ">> " << endl;
		cout << "\tEnter the name: ";
		cin >> animalName;
		while(true){
			cout << "\tEnter row location: ";
			cin >> row;
			cout << "\tEnter column location: ";
			cin >> column;
			if(game.validator(row, column))
				break;
		}
		(*(animals + i)) = animal(row, column, animalName);
		game.addAnimal(row, column, animalName);

		if(animalName.length()>max) 
			max = animalName.length();
	}
	cout<<"After entering the animals positions, the board now looks like this: \n";
	game.printBoard(max+1);

	ofstream out_file;
	out_file.open("File.txt");
	cout<<"You have 4 movements for every animal, and it should be written as this (RULD) R for right, U for up, L for left, D for down\n";
	for (int i = 0; i < animalsNum; i++) {
		cout << "Enter the movements of the " << (*(animals + i)).names() << ": ";
		cin >> movements;
		out_file << movements << " ";
	}
	out_file.close();

	ifstream in_file;
	in_file.open("File.txt");
	if (in_file.fail()) {
		cout << "Error opening the file";
		return 1;
	}
	for (int i = 0; i < animalsNum; i++) {
		in_file>>(*(read + i));
	}
	in_file.close();
	cout << endl;

	for (int i = 0; i < animalsNum; i++) {
		for (int j = 0; j < 4; j++) {
			if ((*(animals + i)).move((*(read + i))[j], size) == false)
				break;
			if (game.getBoardCell((*(animals + i)).getRow(), (*(animals + i)).getColumn()) == "C")
				break;
			if (game.getBoardCell((*(animals + i)).getRow(), (*(animals + i)).getColumn()) == "B")
				break;
		}
	}
	for (int i = 0; i < animalsNum; i++) {
		if ((*(animals + i)).boundaries((*(animals + i)).getRow(), size) == false)
			cout << (*(animals + i)).names() << ": Drowned outside the island." << endl;
		
		else if ((*(animals + i)).boundaries((*(animals + i)).getColumn(), size) == false)
			cout << (*(animals + i)).names() << ": Drowned outside the island." << endl;

		else if (game.getBoardCell((*(animals + i)).getRow(), (*(animals + i)).getColumn()) == "C")
			cout << (*(animals + i)).names() << ": Eaten by the cat." << endl;

		else if (game.getBoardCell((*(animals + i)).getRow(), (*(animals + i)).getColumn()) == "B")
			cout << (*(animals + i)).names() << ": Escaped through the bridge." << endl;

		else cout << (*(animals + i)).names() << ": Starved... Stuck inside the board." << endl;
	}

	system("pause"); // This is Windows-specific
	return 0;
}