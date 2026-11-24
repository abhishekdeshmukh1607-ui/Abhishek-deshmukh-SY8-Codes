#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[5];
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    void insert(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Full.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << "Element Inserted Successfully.\n";
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return;
        }

        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }

    void peek()
    {
        if (front == -1)
        {
            cout << "Queue is Empty.\n";
            return;
        }

        cout << "Front Element: " << queue[front] << endl;
    }
};

int main()
{
    Queue obj;
    int choice, value;

    do
    {
        cout << "\n----- Queue Menu -----\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            obj.insert(value);
            break;

        case 2:
            obj.display();
            break;

        case 3:
            obj.peek();
            break;

        case 4:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}