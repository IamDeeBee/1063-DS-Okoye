#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	//Variable declerarion
	int  i = 0, j = 0, k = 0;
	int Nums[15][15];


	//Creation of Array
	for (i = 0; i<15; i++) {
		for (j = 0; j<15; j++) {
			Nums[i][j] = k;
			k++;
		}
	}
	//Outputing the array
	for (j = 0; j<15; j++) {
		for (i = 0; i<15; i++) {
			cout <<setw(5)<< Nums[i][j]+1;
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}
