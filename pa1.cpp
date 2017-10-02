#include "stdafx.h"
#include <iostream>

// creates a class for magic squares
class MagicSquare {
private:
	int size;
	int **matrix;
public:
	MagicSquare(int size);
	void makeSquare();
	void print();
	void sum();
	void swapLR();
	void swapTB();
	void swapDiag();
	void deleteMatrix();
};

// creates a constructor for magic squares
MagicSquare::MagicSquare(int size) {
	this->size = size;
}

// creates a 2d array with pointers
void MagicSquare::makeSquare() {
	// allocates an array of pointers, that also point to arrays
	matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	// sets all values to 0
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}

	// determines starting position
	int y = 0;
	int x = size / 2;
	matrix[y][x] = 1;

	// siamese method algorithm
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

// prints square
void MagicSquare::print() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%4d", matrix[i][j]);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// checks the sums
void MagicSquare::sum() {
	// Sum of every row
	std::cout << "Checking the sums of every row:      ";
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += matrix[i][j];
		}
		printf("%5d", sum);
	}
	std::cout << "\n";

	// Sum of every column
	std::cout << "Checking the sums of every column:   ";
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < size; j++) {
			sum += matrix[j][i];
		}
		printf("%5d", sum);
	}
	std::cout << "\n";

	// Sum of diagonal case one
	std::cout << "Checking the sums of every diagonal: ";
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += matrix[i][i];
	}
	printf("%5d", sum);

	// Sum of diagonal case two
	sum = 0;
	for (int i = 0; i < size; i++) {
		int j = 2;
		sum += matrix[i][j];
		j--;
	}
	printf("%5d", sum);
	std::cout << "\n";
}

// swaps horizontally (left and right)
void MagicSquare::swapLR() {
	for (int i = 0; i < size; i++) {
		std::swap(matrix[0][i], matrix[size-1][i]);
	}
}

// swaps vertically (top and bottom)
void MagicSquare::swapTB() {
	for (int i = 0; i < size; i++) {
		std::swap(matrix[i][0], matrix[i][size-1]);
	}
}

// swaps diagonally
void MagicSquare::swapDiag() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (size - 1) - i; j++) {
			std::swap(matrix[i][j], matrix[size -1 - j][size - 1 - i]);
		}
	}
}

// deletes allocated memory for matrix and it's elements
void MagicSquare::deleteMatrix() {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// checks input
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

	std::cout << "\nMagic Square #1 is:\n" << std::endl;
	// magic square 1
	MagicSquare mainSquare(size);
	mainSquare.makeSquare();
	mainSquare.print();
	mainSquare.sum();

	std::cout << "\nMagic Square #2 is:\n" << std::endl;
	// magic square variation 2
	mainSquare.swapLR();
	mainSquare.print();
	mainSquare.sum();

	std::cout << "\nMagic Square #3 is:\n" << std::endl;
	// magic square variation 3
	mainSquare.swapTB();
	mainSquare.print();
	mainSquare.sum();

	std::cout << "\nMagic Square #4 is:\n" << std::endl;
	// magic square variation 4
	mainSquare.swapTB();
	mainSquare.print();
	mainSquare.sum();

	std::cout << "\nMagic Square #5 is:\n" << std::endl;
	// magic square variation 5
	mainSquare.swapDiag();
	mainSquare.print();
	mainSquare.sum();

	// delete magic square instance
	mainSquare.deleteMatrix();
}