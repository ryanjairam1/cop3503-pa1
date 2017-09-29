#include "stdafx.h"
#include <iostream>

// Class
class MagicSquare {
private:
	int size;
	int **matrix;
public:
	MagicSquare(int size);
	void makeSquare();
	void magic();
	void print();
	void sum();
	void alternate();
};

// Contructor
MagicSquare::MagicSquare(int size) {
	this->size = size;
}

// Creates square
void MagicSquare::makeSquare() {
	matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	// Sets everything to 0
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
}

// Siamese method
void MagicSquare::magic() {
	// [y][x] from top
	int y = 0;
	int x = size / 2;
	matrix[y][x] = 1;

	for (int i = 1; i <= size*size; i++) {
		matrix[y][x] = i;
		x = x + 1;
		y = y - 1;
		if (y == -1 && x <= size - 1) {
			y = size - 1;
		}
		else if (y > -1 && x > size - 1) {
			x = 0;
		}
		else if ((y == -1 && x > size - 1) || (matrix[y][x] != 0)) {
			x = x - 1;
			y = y + 2;
		}
	}
}

// Print square
void MagicSquare::print() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%4d", matrix[i][j]);
		}
		std::cout << "\n";
	}
}

// Check sums
void MagicSquare::sum() {
	// Sum of every row
	std::cout << "Checking the sums of every row: ";
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += matrix[i][j];
		}
		printf("%4d", sum);
	}
	std::cout << "\n";

	// Sum of every column
	std::cout << "Checking the sums of every column: ";
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += matrix[j][i];
		}
		printf("%4d", sum);
	}
	std::cout << "\n";

	// Sum of diagonal case one
	std::cout << "Checking the sums of every diagonal: ";
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix[i][i];
	}
	printf("%4d", sum);

	// Sum of diagonal case two
	sum = 0;
	for (int i = 0; i < size; i++) {
		int k = 2;
		sum += matrix[i][k];
		k--;
	}
	printf("%4d", sum);
	std::cout << "\n";
}

void MagicSquare::alternate() {

}

// Checks input
void isLegal(int &size, bool isValid) {
	do {
		isValid = true;
		std::cout << "Enter the size of a magic square: ";
		std::cin >> size;
		if ((size < 3) || (size > 15) || (size % 2 == 0)) {
			isValid = false;
			std::cout << "Your size is not valid, please re-enter a value." << std::endl;
		}
	} while (isValid == false);
}

int main() {
	// Check if valid
	int size = 0;
	bool isValid = true;
	isLegal(size, isValid);

	// Magic square 1
	MagicSquare mainSquare(size);
	mainSquare.makeSquare();
	mainSquare.magic();
	mainSquare.print();
	mainSquare.sum();


}