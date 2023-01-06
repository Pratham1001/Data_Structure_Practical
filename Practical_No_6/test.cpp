#include <iostream>

using namespace std;

class Node
{
protected:
    char data;
    Node *next;

public:
    Node(char data)
    {
        this->data = data;
    }
    Node(char data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    void setData(char data)
    {
        this->data = data;
    }
    char getData()
    {
        return this->data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    Node *getNext()
    {
        return this->next;
    }
};
class Stack
{
protected:
    Node *top;
    int size;

public:
    Stack()
    {
        this->top = NULL;
        this->size = 0;
    }
    void push(char data)
    {
        Node *new_node = new Node(data);
        new_node->setNext(top);
        top = new_node;
        this->size++;
    }
    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return '`';
        }
        Node *temp = top;
        char chr = this->top->getData();
        top = top->getNext();
        this->size--;
        delete temp;
        return chr;
    }
    char head()
    {
        if (top == NULL)
        {
            // cout << "Stack Underflow" << endl;
            return NULL;
        }
        return top->getData();
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
    int getSize()
    {
        return this->size;
    }
    void clear()
    {
        Node *temp = this->top;
        Node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->getNext();
            delete prev;
        }
        top = NULL;
        this->size = 0;
    }
};
class Postfix
{
protected:
    string output;
    Stack *stack;

public:
    Postfix(string infix)
    {
        this->stack = new Stack();
        for (int i = 0; i < infix.size(); i++)
        {
            switch (infix[i])
            {
            case '(':
                this->stack->push('(');
                break;
            case ')':
                while (this->stack->head() != '(' && this->stack->head() != NULL)
                {
                    char c = this->stack->pop();
                    output.append(1, c);
                }
                this->stack->pop();
                break;
            case '+':
                popTillPrecedence(infix[i]);
                this->stack->push('+');
                break;
            case '-':
                popTillPrecedence(infix[i]);
                this->stack->push('-');
                break;
            case '*':
                popTillPrecedence(infix[i]);
                this->stack->push('*');
                break;
            case '/':
                popTillPrecedence(infix[i]);
                this->stack->push('/');
                break;
            case '^':
                popTillPrecedence(infix[i]);
                this->stack->push('^');
                break;
            case '%':
                this->stack->push('%');
                break;
            default:
                this->output.append(1, infix[i]);
                break;
            }
        }
        if (this->stack->getSize() != 0)
        {
            cout << "Equation is not balanced.\n";
            exit(0);
        }
    }
    int precedence(char op)
    {
        switch (op)
        {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '^':
            return 4;
        case '%':
            return 5;
        default:
            return -1;
        }
    }
    void popTillPrecedence(char op)
    {
        while (precedence(this->stack->head()) > precedence(op) && this->stack->head() != NULL)
        {
            this->output.append(1, this->stack->pop());
        }
    }
    void display()
    {
        cout << output << endl;
    }
};

int main()
{
    string str = "(A/(B-C)*D+E)";
    Postfix pf = Postfix(str);
    pf.display();
    return 0;
}