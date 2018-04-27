#include <fstream>
#include <iostream>
#include <string>

#include "LuckyOnes.h"

using namespace std;

/*
	 * @FunctionName :LuckyOnes
	 *
	 * @Description:
	 *       This is the constructor
	 * @Params:
	 *       None
	 * @Returns:
	 *      None
	 */
LuckyOnes::LuckyOnes() {
	Head = NULL;
	Tail = NULL;
	Current = NULL;
	word = " ";
}

void LuckyOnes::header() {
	fout.open("eliminated.txt");
	fout << "//////////////////////////////////////////////////////////////////"
			"/////////////////////////\n ";
	fout << "ProgramName: LuckyOnes\n";
	fout << "Author: Nodebechukwu Okoye\n";
	fout << "Description: \n";
	fout << "    This program eliminates items at random in a list till one "
			"item remains\n";
	fout << "Course: 1063 Data Structures\n";
	fout << "Semester: Spring 2018\n";
	fout << "Date: 21 04 2018\n";
	fout << "//////////////////////////////////////////////////////////////////"
			"///////////////////////////\n";
}

/*
	* @FunctionName :readFile
	*
	* @Description:
	*       Reads names from  a given file and stores in a list
	* @Params:
	*      None
	* @Returns:
	*      None
	*/
void LuckyOnes::readFile() {
	fin.open("Mini.txt");

	while (!fin.eof()) {
		fin >> word;
		Load(word); // Loading the file into a doubly linked list
	}
	fin.clear();
	fin.close();
}

/*
	* @FunctionName :Load
	*
	* @Description:
	*       Inserts a value at the rear of the list
	* @Params:
	*      Node*& : node to be appended to rear
	* @Returns:
	*      None
	*/
void LuckyOnes::Load(Node *&Temp) {
	if (!Head) {
		Head = Temp;
		Tail = Temp;
		Tail->Next = Head;
		Current = Temp;
		Head->Prev = Tail;
		;
	} else {
		Tail->Next = Temp;
		Temp->Prev = Tail;
		Temp->Next = Head;
		Head->Prev = Temp;
		Tail = Temp;
	}
}

/*
	* @FunctionName :Load
	*
	* @Description:
	*        Inserts a value at the rear of the list by calling actual insert
 * with a node.
	* @Params:
	*        string : data element to be inserted
	* @Returns:
	*      None
	*/
void LuckyOnes::Load(string Data) {
	Node *Temp = new Node(Data);
	Load(Temp);
}

/*
	* @FunctionName :print
	*
	* @Description:
	*        Inserts a value at the rear of the list by calling actual insert
 * with a node.
	* @Params:
	*        string : data element to be inserted
	* @Returns:
	*      None
	*/
void LuckyOnes::print(int columns) {
	Node *Temp = Head;
	int count = 1;

	while (Temp != Tail) {
		Temp = Temp->Next;
		cout << Temp->data << " ";

		if (columns && count % columns == 0) {
			cout << endl;
		}
		count++;
	}
}

/*
	* @FunctionName :countItems
	*
	* @Description:
	*        This counts all the items that are currently in the list
	*
	* @Params:
	*        none
	* @Returns:
	*        int : returns the number of items in the list
	*/
int LuckyOnes::countItems() {
	Node *Temp = Head;
	int count = 1;

	while (Temp != Tail) {
		Temp = Temp->Next;
		count++;
	}
	return count;
}

/*
	* @FunctionName :getLeng
	*
	* @Description:
	*        This gets the lenth of an item in the file
	*
	* @Params:
	*        int : position of the item
	* @Returns:
	*      int : the length of an item
	*/
int LuckyOnes::getLeng(int num, int multi) {
	fin.open("Mini.txt");
	int count = 1;

	while (!fin.eof() && count != num) {
		fin >> word;
		count++;
	}
	fin.close();
	return word.length() * multi;
}

/*
	* @FunctionName :cull
	*
	* @Description:
	*        Decides wheter to eliminate items left or right
	*
	* @Params:
	*        int :  number of times the current node shoould be moved
	*        int :
	* @Returns:
	*       none
	*/
void LuckyOnes::cull(int multi, int rand) {
	int countCull = 1; // it is used to pick a  word
	while (countItems() != 1) {
		if (getLeng(countCull, multi) % 2 == 0) {
			moveRight(getLeng(countCull, multi), countCull);
		} else {
			moveLeft(getLeng(countCull, multi), countCull);
		}

		countCull++;
		countItems();
	}
	fout << endl;
	fout << "Winner : " << Current->data;
}
/*
	* @FunctionName :moveRight
	*
	* @Description:
	*        This is to find  item to be deleted
	 *
	* @Params:
	*        int :  number of times the current node shoould be moved
	* @Returns:
	*       none
	*/
void LuckyOnes::moveRight(int num, int check) {
	int count = 0;
	while (count != num) {
		Current = Current->Next;
		count++;
	}

	aniRem(Current->data, check);
	fout << endl;
}

/*
	* @FunctionName :moveLeft
	*
	* @Description:
	*        This is to find  item to be deleted
	 *
	* @Params:
	*        int :  number of times the current node shoould be moved
	* @Returns:
	*       none
	*/
void LuckyOnes::moveLeft(int num, int check) {
	int count = 0;
	while (count != num) {
		Current = Current->Prev;
		count++;
	}

	aniRem(Current->data, check);
}

/*
	* @FunctionName :aniRem
	*
	* @Description:
	*        This is deletes the item in the current node
	 *
	* @Params:
	*        none
	* @Returns:
	*       none
	*@Error:
	*       The items not displayed on the output are indicated by a blank lines so i
	*       manually deleted it fromte output file  
	*/
void LuckyOnes::aniRem(string x, int i) {
	// if Current == Head
	if (x == Head->data) {
		if (i % 11 == 0) {
			fout << "At"<<i <<", Deleted " << Current->data << endl;
		}	

		Node *temp = Head;
		Head = Head->Next;
		Head->Prev = temp->Prev;
		delete temp;
		Current = Head;
		Tail->Next = Head;
	}

	// if Current == Tail
	else if (x == Tail->data) {
		if (i % 11 == 0) {
			fout << "At"<<i <<", Deleted " << Current->data << endl;
		}
		Node *temp = Tail;
		Tail = Tail->Prev;
		Tail->Next = temp->Next;
		delete temp;
		Current = Tail;
		Head->Prev = Tail;
	}

	// if Head & Tail != Current
	else {
		if (i % 11 == 0) {
			fout << "At"<<i <<", Deleted " << Current->data << endl;
		}

		Node *temp = Head;
		while (temp != Current) {
			temp = temp->Next;
		}
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;
		Current = Current->Next;
		delete temp;
	}
}