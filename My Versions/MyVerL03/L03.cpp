/*
*This is my version of the code 
*from lecture L03
*
*/
#include <iostream>
#include <ctime>

using namespace std;

/**
* Function: printArray
* Params:
*    int A[] : array of ints to print
*    int size: size of array so we know when to stop looping
* Returns:
    void
*/
void printArray(int A[], int size) {
	for (int i = 0; i<size; i++) {
		cout<<A[i]<<" ";
	}
}
/**
* Function: countItem
* Description:
*    Counts the number of times an integer (< size) occurs in the array.
*    In class we capped it at ints less than 10.
* Params:
*    int A[] : array of values to count
*    int size  : size of array so we know when to stop looping
*	 int index : the element to be checked during each iteration
* Returns:
*    int count per element.
*/

int countItem(int A[], int size, int index) {
	int count=0;
	for (int j = 0; j < size; j++) {
		if (A[j] == index) {
			count++;
		}
	}
	return count;
}
/**
* Function: findMax
* Description: finds the max int value in an array of int's
* Params:
*     int []   : array of integers
*     int max : size of the array
* Returns:
*     int
* */
int findMax(int c[], int max) {
	int first = c[0]; //init max to first item in array
	int index = 0;
	for (int i = 1; i<max; i++) {
		if (c[i] > first) {
			first = c[i];
			index = i;
		}
	}

	return index;
}



int main() {
	srand(time(0));

	//Declared some variables
	const int size =100;	// size of array to count
	int max = 10;             // max value to place in array
	int A[100] = { 0 };         // declare array of size 100 (dynamic allocation later) init to 0's
	int counts[10] = { 0 };     // declare array of "max" size. 

	// loaded up an array with random nums
	// between 0 and max-1
	for (int i = 0; i<size; i++) {
		A[i] = rand() % size/10;
	}

	//Print Array
	printArray(A, size);

	cout << "\n\n";
	//Check for the number of each elementin the array
	//Store it in an array
	for (int i = 0; i<max; i++) {
		counts[i] = countItem(A, size, i);
	}

	//Print items and variables in tabular form
	for (int i = 0; i<max; i++) {
		cout << i << " \t\t " << counts[i] << "\n";
	}

	cout << "The range of the array is " << findMax(counts, max)<<endl;
	

	system("pause");
	return 0;
}
