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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        this->head = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }

    void deleteNode(int data)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == data)
        {
            head = head->next;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
    }
};

int main()
{
    LinkedList linkedList;
    int choice, data;

    while (true)
    {
        std::cout << "1. Insert node at end" << std::endl;
        std::cout << "2. Insert node at start" << std::endl;
        std::cout << "3. Delete node" << std::endl;
        std::cout << "4. Print list" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter data: ";
            std::cin >> data;
            linkedList.insertAtEnd(data);
            break;
        case 2:
            std::cout << "Enter data: ";
            std::cin >> data;
            linkedList.insertAtStart(data);
            break;
        case 3:
            std::cout << "Enter data: ";
            std::cin >> data;
            linkedList.deleteNode(data);
            break;
        case 4:
            linkedList.printList();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    return 0;
}
