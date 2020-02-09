// C++ Practice Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map> 
#include <string>
#include <vector>

void problem1();

using namespace std;

int main()
{
	while (true)
	{
		int selection;
		cout << "Welcome to my practice problems tester in C++" << endl << endl;
		cout << "1. User inputs 2 groups of integers with duplicates -> display common numbers between them" << endl;
		cout << "Please enter the number for the one you would like to run: ";
		cin >> selection;
		cout << endl;
		if (selection == 1)
		{
			problem1();
		}
	}
}
/*
1. Write a C++ program that reads two groups of numbers in which each group has
   random integer numbers with possible duplicates. Your program should display
   the common numbers without any duplicates in the ascending order. 
*/
void problem1()
{
	int mySize;
	int input;
	bool found;
	unordered_map<int, int> groupMap1;
	vector<int> group2Vector;

	//First group is inputed in the form of an unordered map
	cout << "Please enter how many items in first group:\n";
	cin >> mySize;
	cout << "Group 1: " << endl;
	for (int i = 0; i < mySize; i++)
	{
		cin >> input;
		cout << input << endl;
		groupMap1[input] = i;
	}

	//Second group is inputted in the form of a vector
	cout << "Please enter how many items in second group:\n";
	cin >> mySize;

	cout << "Group 2: " << endl;
	for (int i = 0; i < mySize; i++)
	{
		cin >> input;
		cout << input << endl;
		group2Vector.push_back(input);
	}

	//Checks for duplicates by seeing if values of the group2 vector
	//are present in the group1 map. (Key find is usually faster then looping)
	found = false;
	for (int i = 0; i < group2Vector.size(); i++)
	{
		//Number is common between two groups
		unordered_map<int, int>::iterator mapIterator = groupMap1.find(group2Vector[i]);
		if (mapIterator != groupMap1.end())
		{
			found = true;
			cout << mapIterator->first << " has been found " << endl;
		}
		else
		{
			cout << groupMap1[i] << " Not found" << endl;
		}
	}

	//If no values are common, print NONE
	if (!found)
	{
		cout << "NONE" << endl;
	}
}