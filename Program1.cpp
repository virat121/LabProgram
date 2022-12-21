// Write a program for different array Operation(Insertion and Deletion)
// 25-NOV-2022
#include <iostream>
using namespace std;
class ArrayOperation
{
    int *arr;
    int size;     // current size
    int capacity; // total capacity of an array

public:
    ArrayOperation(int);      // constructor
    void read();              // reading an array from keyword
    void insertion(int, int); // insertion operation at pos by data
    void deleteAtPos(int);    // deletion operation at pos
    void display();           // displaying an array
};
ArrayOperation::ArrayOperation(int size)
{
    this->capacity = size;
    this->size = 0; // current size
    arr = new int[capacity];
}
void ArrayOperation::read()
{
    for (int i = 0; i < capacity - 1; i++)
    {
        cin >> arr[i];
        size++;
    }
    // intiliasation the last index value as INT_MIN
    arr[capacity - 1] = INT16_MIN;
}
void ArrayOperation::insertion(int pos, int data)
{
    int i = 0;
    if (size == capacity)
    {
        cout << "Array is full" << endl;
        return;
    }
    else if (pos > capacity || pos > (size + 1))
    {
        cout << "position is out of range" << endl;
        return;
    }
    else
    {
        for (i = size; i >= pos - 1; i--)
        {
            if (i == pos - 1)
                arr[pos - 1] = data;
            else
                arr[i] = arr[i - 1];
        }
        size++;
    }
}
void ArrayOperation::deleteAtPos(int pos)
{
    int i = 0;
    if (size < 0)
    {
        cout << "Array is empty " << endl;
        return;
    }
    else if (pos > size)
    {
        cout << "Invalid position" << endl;
        return;
    }
    else
    {
        for (i = pos - 1; i < capacity - 1; i++)
            arr[i] = arr[i + 1];
        arr[capacity - 1] = INT16_MIN;
        size--;
    }
}
void ArrayOperation::display()
{
    cout << "Array Elemnts: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    cout << "\t\t ***Menu Driven Program for Array Operation\n";
    cout << "1.Insertion 2.Deletion 3.Exit " << endl;
    int size;
    cout << "Enter array size: ";
    cin >> size;
    ArrayOperation obj(size);
    cout << "Enter Array elements: ";
    obj.read();
    do
    {
        int choice;
        int data, pos;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the position and data to be inserted: ";
            cin >> pos >> data;
            obj.insertion(pos, data);
            obj.display();
            break;
        case 2:
            cout << "Enter the postion to be deleted: ";
            cin >> pos;
            obj.deleteAtPos(pos);
            obj.display();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (1);
    return 0;
}
// if this code does not satisfies any condtion then just write their in issue section
