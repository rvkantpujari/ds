#include <iostream>
using namespace std;

/*
    Linear Search
*/

int linearSearch(int nums[], int size, int search)
{
    int i = 0;
    for (; i < size; i++)
    {
        if (nums[i] == search)
            return i;
    }
    return -1;
}

int main()
{
    int nums[5] = { 0 }, search, pos, n = 5;
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter number " << i + 1 << " : ";
        cin >> nums[i];
    }
    cout << "\nPlease enter the number you want to search: ";
    cin >> search;
    pos = linearSearch(nums, n, search);
    if (pos != -1)
        cout << "\nElement found at index " << pos << endl;
    else
        cout << "\nElement not found." << endl;
    return 0;
}