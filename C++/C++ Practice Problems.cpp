// C++ HW Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map> 
#include <string>
#include <vector>

using namespace std;

void problem1();
void problem2();
int findMaxEvents(vector<int> startTimes, vector<int> endTimes);

int main()
{
	while (true)
	{
		int selection;
		cout << "Welcome to my practice problems tester in C++" << endl << endl;
		cout << "1. User inputs 2 groups of integers with duplicates -> display common numbers between them" << endl;
		cout << "2. User inputs a number of events w/ start and end times -> display max concurrent events " << endl << endl;
		cout << "Please enter the number for the one you would like to run: ";
		cin >> selection;
		cout << endl;
		if (selection == 1)
		{
			problem1();
		}
		else if (selection == 2)
		{
			problem2();
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

	//Integer inputted by user for how many items in group
	cout << "Please enter how many items in first group:\n";
	cin >> mySize;

	//First group is inputed in the form of an unordered map
	cout << "Group 1: " << endl;
	for (int i = 0; i < mySize; i++)
	{
		cin >> input;
		cout << input << endl;
		groupMap1[input] = i;
	}

	//Integer inputted by user for how many items in group
	cout << "Please enter how many items in second group:\n";
	cin >> mySize;

	//Second group is inputted in the form of a vector
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

/*
1. Write a C++ program that reads the time information of events in a
   convention center and displays the maximum number of concurrent events
   in the convention center
*/
void problem2()
{
	int eventNum;
	string myEvent;
	vector<int> startTimes;
	vector<int> endTimes;
	
	//User enters number of events
	cout << "Please enter number of events: ";
	cin >> eventNum;
	cout << endl;

	//User inputs events in particular form (given by problem)
	//Ex. 14 20 -> Start: 2pm End: 8pm
	cout << "Events:" << endl;
	for (int i = 0; i < eventNum; i++)
	{
		cin >> myEvent;
		startTimes.push_back(stoi(myEvent));
		cin >> myEvent;
		endTimes.push_back(stoi(myEvent));
		cout << "Start: " << startTimes[i] << " End: " << endTimes[i] << endl;
	}

	cout << "Max number of events is: " << findMaxEvents(startTimes, endTimes) << endl << endl;
}

//Case 1: Start time is between ( 6:00am < startTime < 11:00am)
//Case 2: End time is between  ( 6:00am < endTime < 11:00am)
//Only thoughts so far is a brute force approach:
//Check for these cases to be true for each event
int findMaxEvents(vector<int> startTimes, vector<int> endTimes)
{
	int currentEvent = 0;
	int tempConcurrent = 1;
	int maxConcurrent = 1;
	int j = 0;
	while (currentEvent < startTimes.size())
	{
		for (int i = 0; i < startTimes.size(); i++)
		{
			//Check if indexed event's start is between currentEvent's start and end
			if ( (startTimes[currentEvent] <= startTimes[i]) && (startTimes[i] <= endTimes[currentEvent]) && i != currentEvent)
			{
				cout << "Start: " << startTimes[currentEvent] << " CurrentS: " << startTimes[i] << " End: " << endTimes[currentEvent] << endl;
				tempConcurrent++;
				continue;
			}
			//Check if indexed event's end is between currentEvent's start and end
			else if ((startTimes[currentEvent] <= endTimes[i]) && (endTimes[i] <= endTimes[currentEvent]) && i != currentEvent)
			{
				cout << "Start: " << startTimes[currentEvent] << " CurrentE: " << endTimes[i] << " End: " << endTimes[currentEvent] << endl;
				tempConcurrent++;
			}
		}
		//If tempConcurrent is higher, it is new max
		if (maxConcurrent < tempConcurrent)
		{
			maxConcurrent = tempConcurrent;
		}
		tempConcurrent = 1;
		currentEvent++;
	}
	return maxConcurrent;
}