// linear queue
// 20-Jan-2023
#include <iostream>
using namespace std;
class Queue
{
    int capacity;
    int *arr;
    int data;
    int rear;
    int front;
    int size;  //current size

public:
    Queue(int);
    void enqueue(int data);
    void dequeue();
    bool isFull();
    bool isEmpty();
    int getsize();
};
Queue::Queue(int capacity)
{
    this->capacity = capacity;
    arr = new int[capacity];
    front = rear = -1;
    size = 0;
}
bool Queue::isFull()
{
    if (rear == capacity - 1)
        return true;
    else
        return false;
}
bool Queue::isEmpty()
{
    if (front == -1 || front == capacity)
        return true;
    else
        return false;
}
void Queue::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = data;
        size++;
    }
}
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
    }
    else
    {
        int res = arr[front];
        arr[front] = INT8_MIN;
        front++;
        cout << "Element " << res << " is dequeued succesfully!" << endl;
        size--;
    }
}
int Queue::getsize()
{
    return size;
}
int main()
{
    int capacity;
    cout << "Enter the capacity of queue: ";
    cin >> capacity;
    Queue q(capacity);
    cout << "\t***Queue Operation" << endl;
    cout << "1.enqueue(insertion) 2.dequeue(deletion) 3.statusOfQueue 4.Exit" << endl;
    while (1)
    {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the data to be inserted: ";
            cin >> data;
            q.enqueue(data);
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        case 3:
        {
            if (q.isFull() && q.getsize()!=0)
            {
                cout << "Queue is full" << endl;
            }  
            cout << "Current size of queue: " << q.getsize() << endl;
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
