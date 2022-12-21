#include <iostream>
using namespace std;

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertionSort(int arr[], int len)
{
    int i, j, key;
    for (i = 0; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {9, 8, 7, 3, 5, 2, 4, 1, 10, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Insertion Sort" << endl;
    cout << "Unsorted Array: ";
    printArray(arr, len);
    insertionSort(arr, len);
    cout << "Sorted Array: ";
    printArray(arr, len);
    return 0;
}