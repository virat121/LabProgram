#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
private:
    char queue[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }
    bool isfull()
    {
        if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)))
            return true;
        else
            return false;
    }
    void enqueue(char x)
    {
        if (isfull())
        {
            cout << "Circular Queue is full. Overflow condition!" << endl;
            return;
        }

        else if (front == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = x;
        }

        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = x;
        }

        else
        {
            rear++;
            queue[rear] = x;
        }
    }

    char dequeue()
    {
        if (front == -1)
        {
            cout << "Circular Queue is empty. Underflow condition!" << endl;
            return '\0';
        }

        char x = queue[front];
        queue[front] = '\0';

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (front == MAX - 1)
        {
            front = 0;
        }

        else
        {
            front++;
        }

        return x;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        cout << "Circular Queue elements are: ";

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        }

        else
        {
            for (int i = front; i < MAX; i++)
                cout << queue[i] << " ";

            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    cout << "\t\t***Menu Driven Program of Circular List***" << endl;
    cout << "1. Insert a character in the Circular queue" << endl;
    cout << "2. Delete a Character from the Circular queue" << endl;
    cout << "3. Display Circular queue " << endl;
    cout << "4. Exit " << endl;
    while (1)
    {
        cout << "Enter the choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Character to be inserted : ";
            char x;
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
            cout << "Please enter valid choice." << endl;
            // break;
        }
    }

    return 0;
}
