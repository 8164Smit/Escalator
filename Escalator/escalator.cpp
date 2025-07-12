#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot add more items." << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " added to the stack." << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Nothing to remove." << endl;
        }
        else
        {
            cout << "Removed: " << arr[top] << endl;
            top--;
        }
    }

    void topElement()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element." << endl;
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;

    Stack s(n);
    int choice, value;

    cout << "Simple Stack Program" << endl;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Add to Stack" << endl;
        cout << "2. Remove from Stack" << endl;
        cout << "3. Show Top Element" << endl;
        cout << "4. Check if Stack is Empty" << endl;
        cout << "5. Check if Stack is Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option (1-6): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter number to add: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2)
        {
            s.pop();
        }
        else if (choice == 3)
        {
            s.topElement();
        }
        else if (choice == 4)
        {
            if (s.isEmpty())
                cout << "Yes, the stack is empty." << endl;
            else
                cout << "No, the stack has items." << endl;
        }
        else if (choice == 5)
        {
            if (s.isFull())
                cout << "Yes, the stack is full." << endl;
            else
                cout << "No, you can still add items." << endl;
        }
        else if (choice == 6)
        {
            cout << "Exiting program. Thank you!" << endl;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
