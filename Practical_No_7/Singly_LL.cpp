#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class linkedlist
{
private:
    Node *head;
    Node *tail;

public:
    linkedlist()
    {
        head = tail = nullptr;
        }

     void insert_at_head(int data) {
            Node* new_node = new Node(data);
            new_node->next = head;
            head = new_node;
            if (tail == nullptr) {
                tail = new_node;
            }
        }
        
};