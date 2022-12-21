

#include <iostream>
using namespace std;

int linearSearch(int array[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "length of array : ";
    cin >> n;
    int arr[n];
    cout << "enter array elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "enter element to be searched : ";
    cin >> x;
    int result;
    result = linearSearch(arr, n, x);
    if (result == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element found at index " << result << endl;
    }
}