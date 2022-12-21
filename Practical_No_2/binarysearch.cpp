

#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int x)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] > x)
        return binarySearch(arr, start, mid - 1, x);
    return binarySearch(arr, mid + 1, end, x);
}

int main()
{
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "Enter the element to be searched : ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found" << endl;
    else
    {
        cout << "Element found at index " << result << endl;
        return 0;
    }
}