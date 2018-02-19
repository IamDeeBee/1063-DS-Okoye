/* *
*  **
*  *** 
*  ****
*  Write a function that will print stars N times
*  in the above format
*/
#include<string>
#include<iostream>

using namespace std;

void printStars(int num) {
    string star = "*";
	string star1 = "*";
	for (int i = 0; i < 5; i++) {
		cout << star<<endl;
		star = star + " " + star1;
	}
}
int main() {
	int num;
	cout << "Input A Number : ";
	cin >> num;
	printStars(num);
system("pause");
return 0;
}
