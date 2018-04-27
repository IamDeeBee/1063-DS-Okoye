/*
*@ProgramName - LuckyOnes
*@Author - Nodebechukwu Okoye
*@E-mail - okoyemartino@yahoo.com

*@Files
*      main.cpp
*      LuckyOnes.cpp
*      LuckyOnes.h
*      eliminated.txt
*
*@Description
*      This program  eliminates items at random in a list till one item remains

*@Course - 1063 Data Structure
*@Semester - Spring 2018
*@Date - 21 04 2018
*/
#include <fstream>
#include <iostream>
#include <string>

#include "LuckyOnes.h"

using namespace std;

int main() {
	int multi, rand;

	cout << "How many times do you want to go round the list(1 - 13)?\n";
	cin >> multi;
	while (multi < 1 || multi > 13) {
		cout << "How many times do you want to go round the list(1 - 13)?\n";
		cin >> multi;
	}

	cout << "How random do you want the elimination ?\n ";
	cin >> rand;
	while (rand < 1 || rand > 32678) {
		cout << "How random do you want the elimination ?\n";
		cin >> rand;
	}

	LuckyOnes L2;
	L2.header();
	L2.readFile();


	L2.cull(multi, rand);

}