#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * ------------- *
    | Binary Search |
    * ------------- *
*/

template <typename T>
void printVector(vector<T> nums)
{
    cout << "\n\nVector elments: ";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main()
{
    int search, result, size;
    
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
    
    // ---- STL Algorithm "binary_search(itr_beg, itr_end, srch);" ----

    result = binary_search(nums.begin(), nums.end(), search); // return 1 if found, otherwise -1.
    
    // ---------------------------------------------------------------
    
    // Print the vector elements
    printVector(nums);
    
    if (result == 1)
        cout << "\nElement found"<< endl;
    else
        cout << "\nElement not found." << endl;
    return 0;
}