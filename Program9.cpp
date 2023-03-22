/* Design a menu driven Program in C++ for the following operations on Singly Linked List of
Student Data with the fields: USN, Name, Branch, Sem, PhNo. Perform the following
operations on the linked list.
a. Insert a student at the front of the list.
b. Delete a node with specified student name.
c. Display the list and count the number of nodes in it. */
#include <iostream>
using namespace std;
class Student
{
    string name;
    string usn;
    string branch;
    string sem;
    string phone_no;

public:
    Student();
    Student(string name, string usn, string branch, string sem, string phone_no)
    {
        this->name = name;
        this->usn = usn;
        this->branch = branch;
        this->sem = sem;
        this->phone_no = phone_no;
    }
    void display()
    {
        cout << "Studen Name: " << name << endl;
        cout << "Student Usn: " << usn << endl;
        cout << "Student Branch: " << branch << endl;
        cout << "Semester: " << sem << endl;
        cout << "Phone Number: " << phone_no << endl;
    }
    friend class Node;
    friend class LinkedList;
};
class Node
{
    Student *s_data;
    Node *next;

public:
    Node();
    Node(Student *data)
    {
        this->s_data = data;
        next = NULL;
    }
    friend class LinkedList;
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insert_at_front(Student *data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            newNode->next = temp;
            head = newNode;
        }
    }
    void display_count()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "\t**Details of Student-" << (count + 1) << endl;
            temp->s_data->display();
            temp = temp->next;
            count++;
        }
        cout << "\tThere are " << count << " students in Student LinkedList" << endl;
        cout << "---------------------------------------------------" << endl;
    }
    void delete_student(string name)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "No Student data in the List.";
            return;
        }
        if (head->s_data->name == name) // for the head Node
        {
            head = temp->next;
            delete temp;
            temp = NULL;
            cout << "Student " << name << " is deleted successfully!" << endl;
            return;
        }
        Node *del_node;
        while (temp != NULL && temp->s_data->name != name)
        {
            del_node = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            del_node->next = temp->next;
            delete temp;
            temp = NULL;
            cout << "Student " << name << " is deleted successfully!" << endl;
        }
        else
        {
            cout << "Student with name " << name << " is not present in the list" << endl;
        }
    }
};
int main()
{
    LinkedList list;
    cout << "\t**Menu Driven Program of Student Data**" << endl;
    cout << "1.Insert a student at the front of the list" << endl;
    cout << "2.Delete a node with specified student name" << endl;
    cout << "3.Display the list and count the number of nodes in it" << endl;
    cout << "4.Exit" << endl;
    while (1)
    {
        cout << "Enter a choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {

            string name, usn, branch, sem, phone_no;
            cout << "Enter the Student USN: ";
            getline(cin, usn);
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the branch: ";
            getline(cin, branch);
            cout << "Enter the phone_np: ";
            getline(cin, phone_no);
            cout << "Enter the semester: ";
            getline(cin, sem);
            Student *s = new Student(name, usn, branch, sem, phone_no);
            list.insert_at_front(s);
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter the name of student to be deleted from list: ";
            getline(cin, name);
            list.delete_student(name);
            break;
        }
        case 3:
        {
            list.display_count();
            break;
        }
        case 4:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
