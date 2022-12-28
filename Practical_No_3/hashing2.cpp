#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 7;
int midSquare(int number)
{
    int s = number * number;
    string str = to_string(s);
    int len = str.length();
    if (len % 2 == 0)
    {
        int a = ((int)str[len / 2] - 48) + ((int)str[(len / 2) - 1] - 48);
        return a / 2;
    }
    else
    {
        return (int)str[(len / 2)] - 48;
    }
}
int linearCollision(int arr[], int j)
{
    for (int h = 0; h < SIZE; h++)
    {
        if (arr[j] == 0)
        {
            return j;
        }
        j = (j + 1) % SIZE;
    }
    return -1;
}
void insert(int arr[], int number)
{
    int j = midSquare(number);
    if (j < 0 || j >= SIZE)
    {
        j = linearCollision(arr, abs(j) % SIZE);
    }
    else if (arr[j] == 0)
    {
        arr[j] = number;
    }
    else
    {
        j = linearCollision(arr, j);
        if (j >= 0)
        {
            arr[j] = number;
        }
    }
    if (j == -1)
    {
        cout << "Error: Array is full. Cannot insert element." << endl;
    }
}
void search(int arr[], int number)
{
    int j = midSquare(number);
    if (j < 0 || j >= SIZE)
    {
        for (int h = 0; h < SIZE; h++)
        {
            if (arr[h] == number)
            {
                cout << "Element found at index " << h << endl;
                return;
            }
        }
    }
    else
    {
        if (arr[j] == number)
        {
            cout << "Element found at index " << j << endl;
            return;
        }
        else
        {
            for (int h = 0; h < SIZE; h++)
            {
                if (arr[h] == number)
                {
                    cout << "Element found at index " << h << endl;
                    return;
                }
            }
        }
    }
    cout << "Error: Element not found." << endl;
}
void display(int arr[])
{
    cout << "Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[SIZE] = {0};
    int choice;
    int number;
    do
    {
        cout << "Menu: (1) Insert element\n (2) Search for element\n (3) Display\n(4)Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number to be inserted: ";
            cin >> number;
            insert(arr, number);
            break;
        case 2:
            cout << "Enter the number to search for: ";
            cin >> number;
            search(arr, number);
            break;
        case 3:
            display(arr);
            break;
        case 4:
            break;
        default:
            cout << "Error: Invalid choice." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}