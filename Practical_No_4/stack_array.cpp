#include <iostream>
using namespace std;
const int LEN = 100;
class Stack
{
protected:
    int arr[LEN];
    int top = -1;

public:
    int push(int x)
    {
        this->top++;
        this->arr[top] = x;
        return this->top;
    }
    int pop()
    {
        if (this->top == -1)
            return -1;
        this->top--;
        return this->arr[top + 1];
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << ", ";
        cout << "end\n";
    }
};

int main()
{
    int ip;
    int op;
    bool run = true;
    Stack s = Stack();
    while (run)
    {
        cout << "1. Push element\n2. Pop element\n3. Display\n4.Exit" << endl;
        cin >> ip;

        switch (ip)
        {
        case 1:
            cout << "Enter element to push : ";
            cin >> ip;
            s.push(ip);
            break;
        case 2:
            op = s.pop();
            if (op == -1)
            {
                cout << "Stack is empty " << endl;
            }
            else
            {
                cout << "Element popped: " << op << endl;
            }
            break;
        case 3:
            s.display();
            break;
        case 4:
            run = false;
            break;
        default:
            cout << "Invalid input" << endl;
            run = false;
            break;
        }
    }
}