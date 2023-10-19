#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;


int main() {
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите размер квадратной матрицы: " << endl;
	int size;
	cin >> size;

	int** matrix = new int* [size];
	for (int count = 0; count < size; count++) {
		matrix[count] = new int[size];
	}

	int tmp;

	for (int count_row = 0; count_row < size; count_row++) {
		for (int count_column = 0; count_column < size; count_column++) {
			cin >> tmp;
			matrix[count_row][count_column] = tmp;
		}
		cout << endl;
	}
	int sumrow = 0;
	int sumcol = 0;
	int sumdiag1 = 0;
	int sumdiag2 = 0;
	std::vector<int> check;
	for (int count_row = 0; count_row < size; count_row++) {
		for (int count_column = 0; count_column < size; count_column++) {
			sumrow += matrix[count_row][count_column];
			sumcol += matrix[count_column][count_row];
		}
		sumdiag1 += matrix[count_row][count_row];
		check.push_back(sumrow);
		check.push_back(sumcol);
		sumrow = 0;
		sumcol = 0;
	}
	check.push_back(sumdiag1);
	int ctr = 0;

	for (int count_row = (size - 1); count_row >= 0; count_row--) {
		sumdiag2 += matrix[count_row][ctr];
		ctr++;


	}
	check.push_back(sumdiag2);

	bool flg = 1;

	for (vector<int>::iterator it = check.begin(); it != check.end(); it++) {
		cout << *it << " ";
	}


	if (equal(check.begin() + 1, check.end(), check.begin())) {
		cout << endl << "Hooray! your matrix is miraculous...";
	}


}