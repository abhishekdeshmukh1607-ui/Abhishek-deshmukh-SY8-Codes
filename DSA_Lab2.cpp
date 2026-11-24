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
cout << "\nQueue is Full.\n";
return;
}

if (front == -1)

{
front = 0;
}

rear++;
queue[rear] = value;

cout << "\nElement Inserted Successfully.\n";
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
cout << queue[i] ;
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

cout << "Peak Elements: ";
for (int i = front; i <= rear; i++)
{
cout << queue[front] ;
}
cout << endl;
}

};

int main()
{
Queue obj;
int value;
for(int i=0;i<5;i++)
{
cout << "Enter the element: ";
cin >> value;
obj.insert(value);

}

obj.display();
obj.peek();

return 0;
}