#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr; 
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList() {
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

        void insert_at_tail(int data) {
            Node* new_node = new Node(data);
            if (tail == nullptr) {
                head = tail = new_node;
                return;
            }
            tail->next = new_node;
            tail = new_node;
        }

        void delete_node(int data) {
            if (head == nullptr) {
                return;
            }
            if (head->data == data) {
                head = head->next;
                return;
            }
            Node* current = head;
            while (current->next != nullptr) {
                if (current->next->data == data) {
                    current->next = current->next->next;
                    return;
                }
                current = current->next;
            }
        }

        void display() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

void menu() {
    cout << "1. Insert at head" << endl;
    cout << "2. Insert at tail" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    LinkedList ll;
    while (true) {
        menu();
        int choice;
        cout &#8203;`oaicite:{"index":0,"invalid_reason":"Malformed citation << \"Enter your choice: \";\n        cin >>"}`&#8203; choice;
        if (choice == 1) {
            int data;
            cout &#8203;`oaicite:{"index":1,"invalid_reason":"Malformed citation << \"Enter data: \";\n            cin >>"}`&#8203; data;
            ll.insert_at_head(data);
        } else if (choice == 2) {
            int data;
            cout &#8203;`oaicite:{"index":2,"invalid_reason":"Malformed citation << \"Enter data: \";\n            cin >>"}`&#8203; data;
            ll.insert_at_tail(data);
        } else if (choice == 3) {
            int data;
            cout &#8203;`oaicite:{"index":3,"invalid_reason":"Malformed citation << \"Enter data: \";\n            cin >>"}`&#8203; data;
            ll.delete_node(data);
        } else if (choice == 4) {
            ll.display();
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}
