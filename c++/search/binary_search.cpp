#include <iostream>
using namespace std;

/*
    * ------------- -------------*
    | Binary Search using VECTOR |
    * ------------- -------------*
*/

template <typename T>
void printElements(T nums, int size)
{
    cout << "\n\nArray elments: ";
    for (int i = 0; i < size; i++)
        cout << nums[i] << " ";
    cout << endl;
}

int binarySearch(int nums[], int search, int size)
{
    int beg = 0, mid = 0, end=size-1;
    while (beg <= end)
    {
        // Should not use below statement because it overflows when the size of input is very large.
        // mid = (beg + end) / 2;  
        mid = beg + (end - beg) / 2;
        if (search == nums[mid])
            return mid;
        else if (search > nums[mid])
            beg = mid + 1;
        else if (search < nums[mid])
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int nums[10], search, pos, size=10;
    
    // Assuming that user will input elements in ascending order.
    for (int i = 0; i < size; i++)
    {
        cout << "Please enter number " << i + 1 << " : ";
        cin >> nums[i];
    }

    cout << "\nPlease enter the number you want to search: ";
    cin >> search;

    // Print the array elements
    printElements(nums, size);

    // UDF
    pos = binarySearch(nums, search, size);
    
    if (pos != -1)
        cout << "\nElement found at index "<<pos<< endl;
    else
        cout << "\nElement not found." << endl;
    return 0;
}