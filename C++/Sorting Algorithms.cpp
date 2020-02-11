#include <iostream>
#include <array>

void bubbleSort(int numbers[], int size);

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
	int numbers[10] = { 5 ,1 , 17, 40 ,31, 16, 41, 9 ,10, 37 };
	//Sizeof gives size in terms of bytes -> divide by 4 since each integer
	//takes up 4 bytes (gives number of array elements)
	bubbleSort(numbers, (sizeof(numbers)/4) );
    return 0;
}

void bubbleSort(int numbers[], int size)
{
	int temp;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				swapped = true;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
}
