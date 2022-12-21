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

void shellSort(int arr[], int len)
{
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[] = {9, 8, 7, 3, 5, 2, 4, 1, 10, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Shell Sort" << endl;
    cout << "Unsorted Array: ";
    printArray(arr, len);
    shellSort(arr, len);
    cout << "Sorted Array: ";
    printArray(arr, len);
    return 0;
}