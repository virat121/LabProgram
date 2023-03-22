/* Create a class BOOK with members ISBN, Title, Author and Price. Write a
C++ program to construct a stack data structure for N BOOK objects and
write member functions to perform the following operations on it:
a) PUSH-To add a new BOOK object to the stack
b) POP- To remove a BOOK object from the stack */
#include <iostream>
using namespace std;
class Book
{
    int ISBN;
    string title;
    string author;
    int price;

public:
    void input()
    {
        cout << "Enter the BookName: ";
        getline(cin, title);
        cout << "Enter the Book's Author Name: ";
        getline(cin, author);
        cout << "Enter the ISBN: ";
        cin >> ISBN;
        cout << "Enter the price of Book: ";
        cin >> price;
    }
    void display()
    {
        cout << "Book ISBN: " << ISBN << endl;
        cout << "Book Title: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "Book Price: " << price << endl;
    }
};
class Stack
{
    Book *stck;
    int size;
    int top;

public:
    Stack(int n)
    {
        this->size = n;
        stck = new Book[n];
        top = -1;
    }
    void push(Book);
    void pop();
};
void Stack::push(Book b1)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
        cout << "Book can't be pushed" << endl;
    }
    else
    {
        stck[++top] = b1;
        cout << "Book Pushed Successfully" << endl;
    }
}
void Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        cout << "Book can't pop from empty stack" << endl;
    }
    else
    {
        Book poped = stck[top--];
        poped.display();
        cout << "Book poped successfully!" << endl;
    }
}
int main()
{
    int size;
    cout << "Enter the size of Stack: " << endl;
    cin >> size;
    Stack *st = new Stack(size);
    cout << "**Stack Operation on Book Objet\n";
    cout << "1.push  2.Pop  3.Exit " << endl;
    while (1)
    {
        int choice;
        // char ch;
        cout << "Enter Your Choice: ";
        cin >> choice;
        // scanf("%c", &ch); // dummy vairable to handle enter character
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            Book newBook;
            newBook.input();
            st->push(newBook);
            break;
        }
        case 2:
        {
            st->pop();
            break;
        }
        case 3:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
