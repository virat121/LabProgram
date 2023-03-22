/* Design a menu driven Program in C++ for the following operations on Doubly Linked List
(DLL) of Employee Data with the fields: SSN, Name, Dept,Designation and salary. Perform
the following operations.
a. Create a double linked list of employees data.
b. Insert a new employee to the left of the node whose key value (employee name) is read
as an input.
c. Delete a node with given data, if it is found. Otherwise display appropriate error message */
#include <iostream>
using namespace std;
class Employee
{
    string ssn;
    string name;
    string dept;
    string design;
    int salary;

public:
    Employee(string ssn, string name, string dept, string design, int salary)
    {
        this->ssn = ssn;
        this->name = name;
        this->dept = dept;
        this->design = design;
        this->salary = salary;
    }
    friend class Node;
    friend class DlinkedList;
};
class Node
{
    Employee *emp;
    Node *next;
    Node *prev;

public:
    Node(Employee *emp)
    {
        this->emp = emp;
        next = prev = NULL;
    }
    friend class DlinkedList;
};
class DlinkedList
{
    Node *head;

public:
    DlinkedList()
    {
        head = NULL;
    }
    void create()
    {
        char choice;
        do
        {
            string ssn, name, dept, desgn;
            int salary;
            cout << "Enter the  SSN: ";
            getline(cin, ssn);
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the department: ";
            getline(cin, dept);
            cout << "Enter the designation: ";
            getline(cin, desgn);
            cout << "Enter the salary: ";
            cin >> salary;
            Employee *emp_data = new Employee(ssn, name, dept, desgn, salary);
            Node *newNode = new Node(emp_data);
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
            cout << "Enter 'y' for next data: ";
            cin >> choice;
            cin.ignore();
        } while (choice == 'y');
        display();
    }
    void insert_at_key(Employee *emp, string key)
    {
        if (head == NULL)
        {
            cout << "No Employee data";
        }
        else
        {
            Node *temp = head;
            Node *flag_node;
            while (temp != NULL && temp->emp->name != key)
            {
                flag_node = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Employee " << key << " is not present.";
            }
            else if (temp == head)
            {
                Node *newNode = new Node(emp);
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
                cout << "Employee is Added Successfully!" << endl;
            }
            else
            {
                Node *newNode = new Node(emp);
                newNode->next = flag_node->next;
                newNode->prev = flag_node;
                flag_node->next->prev = newNode;
                flag_node->next = newNode;
                cout << "Employee is Added Successfully!" << endl;
            }
        }
    }
    void delete_node(string key)
    {
        if (head == NULL)
        {
            cout << "No Employee Data" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->emp->name != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Employee with name " << key << " is not found" << endl;
        }
        else
        {
            if (temp == head)
            {
                // if only one node in a list and if it is to be deleted
                if (head->next == NULL)
                {
                    delete head;
                    head = NULL;
                }
                // if we have more nodes but want to delete head
                else
                {
                    head = head->next;
                    delete (head->prev);
                    head->prev = NULL;
                }
            }
            else
            {
                // if temp is the middle node
                if (temp->next && temp->prev)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                // if temp is last node
                else
                {
                    temp->prev->next = NULL;
                }
                delete temp;
            }
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "No Employee List" << endl;
            return;
        }
        cout << "Employee in list are: ";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->emp->name << "<<--->>";
            temp = temp->next;
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
};
int main()
{
    DlinkedList list;
    cout << "\t**Menu Driven Program of Student Data**" << endl;
    cout << "1.Create a double linked list of employees data" << endl;
    cout << "2.Insert a node before specified employee name" << endl;
    cout << "3.Delete a node with given data" << endl;
    cout << "4.Display the employee list" << endl;
    cout << "5.Exit" << endl;
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
            list.create();
            break;
        }
        case 2:
        {
            string ssn, name, dept, desgn;
            int salary;
            cout << "Enter the  SSN: ";
            getline(cin, ssn);
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the department: ";
            getline(cin, dept);
            cout << "Enter the designation: ";
            getline(cin, desgn);
            cout << "Enter the salary: ";
            cin >> salary;
            cin.ignore();
            cout << "Enter the name of employee before which a new employee is to be added: ";
            string key;
            getline(cin, key);
            Employee *emp_data = new Employee(ssn, name, dept, desgn, salary);
            list.insert_at_key(emp_data, key);
            break;
        }
        case 3:
        {
            cout << "Enter the name of the employee that is to be removed: ";
            string name;
            getline(cin, name);
            list.delete_node(name);
            break;
        }
        case 4:
            list.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
