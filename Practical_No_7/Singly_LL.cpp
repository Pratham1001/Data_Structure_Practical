#include <iostream>
using namespace std;

class Node
{

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = next;
    }
};

class Linkedlist
{

private:
    Node *head;

public:
    Linkedlist()
    {
        this->head = nullptr;
    }

    void insertatEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
    }
};