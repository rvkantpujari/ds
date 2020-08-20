#include <iostream>
#include <vector>
using namespace std;

/*
    Linear Search | Using STL container - vector
*/

int linearSearch(vector<int> nums, int search)
{
    int i = 0;
    for (; i < nums.size(); i++)
    {
        if (nums[i] == search)
            return i;
    }
    return -1;
}

int main()
{
    int search, pos, size;
    cout<<"Please enter the total number of elements: ";
    cin>>size;

    vector<int> nums(size, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << "Please enter number " << i + 1 << " : ";
        cin >> nums[i];
    }
    
    cout << "\nPlease enter the number you want to search: ";
    cin >> search;

    pos = linearSearch(nums, search);

    if (pos != -1)
        cout << "\nElement found at index " << pos << endl;
    else
        cout << "\nElement not found." << endl;
    return 0;
}