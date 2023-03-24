/* Design a C++ program that uses functions to perform the following:
a. Create a binary search tree of integers.
b. Search for an integer key in the above binary search tree non recursively.
c. Search for an integer key in the above binary search tree recursively.
 */
#include <iostream>
using namespace std;
class Node // creating a node of tree that may have left and right child
{
    int key;       // key contains data
    Node *l_child; // left child of tree
    Node *r_child; // right child of tree

public:
    Node(int data)
    {
        this->key = data;
        l_child = r_child = NULL;
    }
    friend class BinarySearchTree;
};
class BinarySearchTree
{
    Node *root; // ROOT node of binary tree(level-0)

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    Node *insert(Node *node, int data)
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
        int data;
        cin >> data;
        bool flag = false;
        while (data != -1)
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
    bool recursive_search(Node *root, int x)
    {
        if (root == NULL)
            return false;
        if (root->key == x)
            return true;
        else if (root->key > x)
            return recursive_search(root->l_child, x);
        else
            return recursive_search(root->r_child, x);
    }
    bool search(Node *root, int x)
    {
        while (root != NULL)
        {
            if (root->key == x)
                return true;
            else if (root->key < x)
                root = root->r_child;
            else
                root = root->l_child;
        }
        return false;
    }
};

int main()
{
    BinarySearchTree Bst;
    Node *helper;
    cout << "\t**Binary Search Tree Menu Card**" << endl;
    cout << "1.Creating a tree and adding Node(untill u press -1)" << endl;
    cout << "2.Inorder Traversal" << endl;
    cout << "3.Search Recursively" << endl;
    cout << "4.Search Non-recursively" << endl;
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
                cout << "Enter the Elements to be searched: ";
                int s_data;
                cin >> s_data;
                if (Bst.recursive_search(helper, s_data))
                    cout << "Element is found " << endl;
                else
                    cout << "Element is not found!" << endl;
            }
            else
                cout << "Tree Does Not Exit!" << endl;
            break;
        case 4:
            if (helper)
            {
                cout << "Enter the Elements to be searched: ";
                int s_data;
                cin >> s_data;
                if (Bst.search(helper, s_data))
                    cout << "Element is found " << endl;
                else
                    cout << "Element is not found!" << endl;
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