#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * ------------- -------------*
    | Binary Search using VECTOR |
    * ------------- -------------*
*/

template <typename T>
void printVector(vector<T> nums)
{
    cout << "\n\nVector elments: ";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int binarySearch(vector<int> nums, int search)
{
    int beg = 0, mid = 0, end=nums.size()-1;
    while (beg <= end)
    {
        // Should not use below statement because it overflows when the size of elements is very large.
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
    int search, pos, size;
    
    cout<<"Please enter the number of elements: ";
    cin>>size;

    vector<int> nums(size, 0);
    
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "Please enter number " << i + 1 << " : ";
        cin >> nums[i];
    }

    // Using STL algorithm - sort()
    sort(nums.begin(), nums.end());

    cout << "\nPlease enter the number you want to search: ";
    cin >> search;
    
    // Print the vector elements
    printVector(nums);

    // UDF
    pos = binarySearch(nums, search);
    
    if (pos != -1)
        cout << "\nElement found at index "<<pos<< endl;
    else
        cout << "\nElement not found." << endl;
    return 0;
}