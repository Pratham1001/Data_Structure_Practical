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

int getMax(int arr[], int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int len, int place)
{
    const int max = 10;
    int output[len], count[max];
    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < len; i++)
        count[(arr[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = len - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < len; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int len)
{
    int max = getMax(arr, len);
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(arr, len, place);
        cout << place << " " << max << endl;
    }
}

int main()
{
    int arr[] = {121, 432, 564, 23, 1, 45, 788};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Counting Sort" << endl;
    cout << "Unsorted Array: ";
    printArray(arr, len);
    radixSort(arr, len);
    cout << "Sorted Array: ";
    printArray(arr, len);
    return 0;
}