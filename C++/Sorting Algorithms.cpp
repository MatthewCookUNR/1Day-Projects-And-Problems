#include <iostream>
#include <chrono>
#include <array>

void bubbleSort(int numbers[], int size);
void insertionSort(int numbers[], int size);
using namespace std;
using namespace std::chrono;


int main()
{
    cout << "Hello world!" << endl;
	int numbers[10] = { 5 ,1 , 17, 40 ,31, 16, 41, 9 ,10, 37 };
	//Sizeof gives size in terms of bytes -> divide by 4 since each integer
	//takes up 4 bytes (gives number of array elements)

	//Bubble Sort
    auto start = high_resolution_clock::now();
    bubbleSort(numbers, (sizeof(numbers)/4) );
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    //Insertion Sort
    start = high_resolution_clock::now();
    insertionSort(numbers, (sizeof(numbers)/4) );
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
//Bubble Sort:
//One of the simplest sorting algorithms that works
//by repeatedly swapping adjacent elements if they
//are in the incorrect order
void bubbleSort(int numbers[], int size)
{
	int temp;
	bool swapped = true;

	//Breaking condition is that you loop through
	//entire array and nothing needs to be swapped
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
		    //Incorrect order -> swap
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				swapped = true;
			}
		}
	}

    cout << "Bubble Sort Result: ";
    for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}

//Insertion Sort:
//A simple sorting algorithm that builds the final, sorted
//array one element at a time. It finds the correct spot for
//in the sorted part of the array and places it there while
//shifting all other elements.
void insertionSort(int numbers[], int size)
{
    int key, index, index2;

    //Once loop reaches end, array is sorted
    for( index = 1; index < size; index++)
    {
        key = numbers[index];
        index2 = index - 1;

        //Shift all elements to the right until the
        //correct spot for the key is found
        while(index2 >= 0 && numbers[index2] > key)
        {
            numbers[index2 + 1] = numbers[index2];
            index2 = index2 - 1;
        }
        numbers[index2 + 1] = key;
    }

    cout << "Insertion Sort Result: ";
    for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

}
