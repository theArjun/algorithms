/*
Title : Selection Sort
Author :  Arjun Adhikari
Approach Used : Selecting position and fitting correct element for the selected position.
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int k = i;

        while (j != n)
        {
            j++;
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);

        /*
        2020 Mar 04 Wed  20:28:07 - Arjun Adhikari
        For printing Passes.  
        */
        cout << "Pass  " << i + 1 << " : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {8, 6, 3, 2, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    return 0;
}