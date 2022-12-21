#include <iostream>
using namespace std;

void printArray(int arr[],int len){
    for(int i=0;i<len;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int arr[],int len){
    int tmpIdx,temp;
    for ( int i = 0; i < len-1; i++ ){
        tmpIdx = i;
        for ( int j = i+1; j < len; j++ )
            if (arr[j]<arr[tmpIdx])
                tmpIdx = j;
        if (tmpIdx!=i){
            temp = arr[tmpIdx];
            arr[tmpIdx] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[] = {9,8,7,3,5,2,4,1,10,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Selection Sort" << endl;
    cout << "Unsorted Array: ";
    printArray(arr, len);
    selectionSort(arr,len);
    cout << "Sorted Array: ";
    printArray(arr,len);
    return 0;
}