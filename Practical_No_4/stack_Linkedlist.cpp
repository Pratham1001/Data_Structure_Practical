#include <iostream>
using namespace std;
const int LEN = 100;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
        }
        Node(int data, Node *next){
            this->data = data;
            this->next = next;
        }
        
};
class Stack{
    protected:
        Node* top=NULL;
    public:
        void push(int x) {
            Node* n = new Node(x,this->top);
            this->top = n;
        }
        int pop() {
            if(this->top == NULL){
                return -1;
            }
            Node* n = this->top;
            this->top = n->next;
            return n->data;
        }
        void display(){
            Node* n = this->top;
            cout << " Stack from top to bottom";
            while(n!= NULL){
                cout<<n->data<<" ";
                n = n->next;
            }
            cout<<"\n";
        }
};

int main() {
    int ip;
    int op;
    bool run = true;
    Stack s =  Stack();
    while (run) {
        cout << "1. Push element\n2. Pop element\n3. Display\n4.Exit"<< endl;
        cin>>ip;

        switch (ip) {
            case 1:
                cout << "Enter element to push : ";
                cin>>ip;
                s.push(ip);
                break;
            case 2:
                op = s.pop();
                if (op == -1) {
                    cout << "Stack is empty "<<endl;
                }
                else {
                    cout << "Element popped: "<<op<<endl;
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
                break;
        }
    }
}