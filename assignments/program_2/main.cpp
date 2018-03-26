/*
* @ProgramName: StringCaseChange
* @Author: Nodebechukwu Okoye
* @Description:
*     This program changes the case of a string
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 24 03 2018
*/
#include <iostream>
#include <string>

using namespace std;

/*
*@FunctionName: toUpper
*@Description:
*     changes all characters in the string to its uppercase
*@Params:
*      string w - string to be converted
*@Returns:
	  uppercase string
*/
string toUpper(string w) {
	for (int i = 0; i < w.length(); i++) {
		if ((int)w[i] >= 97 && (int)w[i] <= 122) {
			w[i] = w[i] - 32;
		}
	}
	return w;
}

int main() {
	string x = "ANTELOPE";
	cout << x << endl;

	cout << toUpper(x) << endl;
  }
