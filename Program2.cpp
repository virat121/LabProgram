// Write a c++ program to search an element in a sorted array using Binary search(recursive algorithm)
// 2-Dec-2022
#include <iostream>
using namespace std;
class BinarySearch
{
public:
    int Bsearch(int *arr, int low, int high, int key)
    {
        int mid = low + (high - low) / 2;
        if (low > high)
            return -1;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return Bsearch(arr, low, mid - 1, key);
        else
            return Bsearch(arr, mid + 1, high, key);
    }
};
int main()
{
    cout << "Enter the size of array:";
    int size;
    cin >> size;
    int arr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int key;
    cout << "Enter the Key element: ";
    cin >> key;
    BinarySearch obj;
    int res = obj.Bsearch(arr, 0, size - 1, key);
    if (res == -1)
        cout << "Element not Found!" << endl;
    else
        cout << "Elememt is found at index " << res << endl;
    ;
    return 0;
}
// if this code does not satisfies any condtion then just write their in issue section
