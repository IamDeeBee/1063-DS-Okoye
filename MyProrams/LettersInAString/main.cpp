/*
*@ProgramName : LettersInAstring
*@Author : Nodebechukwu Okoye
*@Description:
	  This program counts how many letters are in a string and compares them
*/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void charVersion(char *c, char *c2) {
	// Prints out the words
	cout << c << endl;
	cout << c2 << endl;

	// Counts the charactersin the words
	cout << char_traits<char>::length(c) << endl;
	cout << char_traits<char>::length(c2) << endl;

  //Comapres the number of characters in each word
  if ( char_traits<char>::length(c)==char_traits<char>::length(c2)) {
		cout << "They have the same number of letters"<<endl;
	} else {
		cout << "They do not have the same number of letters"<<endl<<endl;
	}
  //Comapres the characters in each word
	/*
	*@FunctionName - strcmp
	*@Description:
		  Compares two array of characters(string)
		  Doesn't work with string datatype directly
	*Parameters:
		  c -string sotred as array of characters
		  c2- -string sotred as array of characters
	*@Returns:
		True or False
	*/
	if (strcmp(c, c2)) {
		cout << "They are not the same"<<endl;
	} else {
		cout << "They are  the same"<<endl;
	}
}
void stringVersion(string w, string w2) {
	// prints out the word
	cout << w << endl;
	cout << w2 << endl;

	// Counts the characters in the words
	cout << w.length() << endl;
	cout << w2.length() << endl;

//Comapres the number of characters in each word
if (w.length()==w2.length()) {
		cout << "They have the same number of letters"<<endl<<endl<<endl<<endl<<endl;
	} else {
		cout << "They do not have the same number of letters"<<endl<<endl<<endl<<endl;
	}
	
	//Comapres the characters in each word
	// Both comparism work but the second is more effective
	/*for (int i = 0; i < w.length(); i++) {
		if ((int)w[i] != (int)w2[i]) {
			cout << "they are not the same"<<endl<<endl<<endl;
			break;
		}
	}
	/*
	*
	*
	*         OR
	*
	*
	*
	*/
	if (w.compare(w2)) {
		cout << "They are not the same"<<endl<<endl;
	} else {
		cout << "They are the same"<<endl;
	}
}
int main() {
	string w = "HELLOS";
	string w2 = "HELLOS";

	char c[] = "HELLS";
	char c2[] = "HELLOS";

	charVersion(c, c2);
	cout << endl;
	stringVersion(w, w2);

	// system("pause");
	return 0;
}
