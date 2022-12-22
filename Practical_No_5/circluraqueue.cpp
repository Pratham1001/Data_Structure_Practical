#include <iostream>
using namespace std;
const int LEN = 100;

class queue
{
protected:
    int arr[LEN];
    int front = -1;
    int rear = -1;

public:
    void display()
    {
        if (front == -1 || rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void enqueue(int x)
    {
        if (rear == LEN - 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        else if (front == rear)
            front = rear = -1;
        else
            front++;
    }
};

int main()
{
    int ip;
    int op;
    bool run = true;
    queue q = queue();
    while (run)
    {
        cout << "1. Insert Element\n2. Remove Element\n3. Display Queue\n4. Exit" << endl;
        cin >> ip;

        switch (ip)
        {
        case 1:
            cout << "Enter element to enter queue : ";
            cin >> ip;
            q.enqueue(ip);
            break;
        case 2:

            q.dequeue();

            break;
        case 3:
            q.display();
            break;

        default:
            cout << "Queue Exited\n";
            run = false;
            break;
        }
    }
}