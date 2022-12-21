#include <iostream>
using namespace std;

void printArray(int arr[],int len){
    for(int i=0;i<len;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void bubbleSort(int arr[], int len) {
    bool sorted = false;
    int temp;
    while (!sorted)
    {
        sorted = true;
        for (int j = 0; j < len-1; j++)
        {
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted=false;
            }
        }
    }
}

int main()
{
    int arr[] = {9,8,7,3,5,2,4,1,10,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Bubble Sort" << endl;
    cout << "Unsorted Array: ";
    printArray(arr, len);
    bubbleSort(arr,len);
    cout << "Sorted Array: ";
    printArray(arr,len);
    return 0;
}