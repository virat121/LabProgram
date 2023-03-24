/* Design a C++ program using Circular single linked list with header nodes to
perform the following operations
a. To create a circular linked list to represent unsigned long integers
b. To add two long integers represented by circular linked list and store the
result in another circular linked list.
c. Display the resultant circular linked list.
 */
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    unsigned long data;
    Node *next;
};

class CircularList
{
private:
    Node *head;

public:
    CircularList()
    {
        head = new Node();
        head->next = head;
    }

    void insert(unsigned long x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        Node *ptr = head->next;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    void display()
    {

        Node *ptr = head->next;
        string str = ""; // we can also do it with reversing of list
        while (ptr != head)
        {
            str = str + to_string(ptr->data);
            ptr = ptr->next;
        }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }

    void add(CircularList list1, CircularList list2)
    {
        Node *ptr1 = list1.head->next;
        Node *ptr2 = list2.head->next;
        unsigned long carry = 0;
        while (ptr1 != list1.head || ptr2 != list2.head)
        {
            unsigned long sum = carry;
            if (ptr1 != list1.head)
            {
                sum += ptr1->data;
                ptr1 = ptr1->next;
            }
            if (ptr2 != list2.head)
            {
                sum += ptr2->data;
                ptr2 = ptr2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            insert(sum);
        }
        if (carry > 0)
        {
            insert(carry);
        }
    }
};

int main()
{
    CircularList list1, list2, result;
    unsigned long num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    while (num1 > 0)
    {
        list1.insert(num1 % 10);
        num1 = num1 / 10;
    }

    cout << "Enter the second number: ";
    cin >> num2;
    while (num2 > 0)
    {
        list2.insert(num2 % 10);
        num2 = num2 / 10;
    }

    result.add(list1, list2);
    cout << "The sum of the two numbers is: ";
    result.display();
    return 0;
}