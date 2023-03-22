/* Design a C++ program that uses functions to perform the following:
a. Create a binary search tree of characters.
b. Traverse the above Binary search tree recursively in preorder, in order and
post order */
#include <iostream>
using namespace std;
class Node // creating a node of tree that may have left and right child
{
    char key;      // key contains data
    Node *l_child; // left child of tree
    Node *r_child; // right child of tree

public:
    Node(char data)
    {
        this->key = data;
        l_child = r_child = NULL;
    }
    friend class BinarySearchTree;
};
class BinarySearchTree
{
    Node *root; //ROOT node of binary tree(level-0)

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    Node *insert(Node *node, char data)
    {
        if (node == NULL)
        {
            node = new Node(data);
        }
        else if (data < node->key)
        {
            node->l_child = insert(node->l_child, data);
        }
        else if (data > node->key)
        {
            node->r_child = insert(node->r_child, data);
        }
        else
        {
            cout << "Element already exists in the tree." << endl;
        }
        return node;
    }
    Node *create()
    {
        cout << "Enter the elements to be added: ";
        char data;
        cin >> data;
        bool flag = false;
        while (data != '0')
        {
            flag = true;
            root = insert(root, data);
            cout << "Enter the elements to be added:";
            cin >> data;
        }
        return root;
    }
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->l_child);
        cout << temp->key << " ";
        inorder(temp->r_child);
    }
    void preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->key << " ";
        preorder(node->l_child);
        preorder(node->r_child);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
            return;
        postorder(node->l_child);
        postorder(node->r_child);
        cout << node->key << " ";
    }
};

int main()
{
    BinarySearchTree Bst;
    Node *helper;
    cout << "\t**Binary Search Tree Menu Card**" << endl;
    cout << "1.Creating a tree and adding Node(untill u press 0)" << endl;
    cout << "2.Inorder Traversal" << endl;
    cout << "3.Preorder Traversal" << endl;
    cout << "4.Postorder Traversal" << endl;
    cout << "5.Exit" << endl;
    while (1)
    {
        cout << "Enter a Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            helper = Bst.create();
            break;
        case 2:
            if (helper)
            {
                cout << "Inorder Traversal: ";
                Bst.inorder(helper);
                cout << endl;
            }
            else
                cout << "Tree Does Not Exit!" << endl;
            break;
        case 3:
            if (helper)
            {
                cout << "Preorder Traversal: ";
                Bst.preorder(helper);
                cout << endl;
            }
            else
                cout << "Tree Does Not Exit!" << endl;
            break;
        case 4:
            if (helper)
            {
                cout << "Postorder Traversal: ";
                Bst.postorder(helper);
                cout << endl;
            }
            else
                cout << "Tree Does Not Exit!" << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Please Enter valid Choice" << endl;
        }
    }
    return 0;
}
