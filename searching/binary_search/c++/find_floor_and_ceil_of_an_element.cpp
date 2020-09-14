#include <iostream>
using namespace std;

/*
    Program to find floor and ceil of an element in sorted array.
    -------------------------------------------------------------------------------
    Given array:    2 4 8 11 15 34 50
    -------------------------------------------------------------------------------
    Question: Find the floor & ceil elements of 12?
    Ans. Since both are not there in the array so floor will become element smaller 
    than 12 which is 11 & the ceil will become element larger than 12 which is 15.
    ------------------------------------------------------------------------------
    Find: 12
    --------
                Ceil:15
                 ||
        2 4 8 11 15 34 50
              ||
            Floor:11
    ------------------------------------------------------------------------------
*/

int find_floor(int arr[], int N, int srch)
{
    int beg=0, end=N-1, mid, res;
    while(beg<=end)
    {
        mid = beg + (end-beg)/2;
        if(arr[mid] == srch)
            return mid;
        else if(srch < arr[mid])
            end = mid - 1;
        else if(srch > arr[mid])
        {
            res = mid;
            beg = mid + 1;
        }
    }
    return res;
}

int find_ceil(int arr[], int N, int srch)
{
    int beg=0, end=N-1, mid, res;
    while(beg<=end)
    {
        mid = beg + (end-beg)/2;
        if(arr[mid] == srch)
            return mid;
        else if(srch < arr[mid])
        {
            res = mid;
            end = mid - 1;
        }
        else if(srch > arr[mid])
            beg = mid + 1;
    }
    return res;
}

int main()
{
    int nums[] = { 12, 15, 18, 21, 24, 29, 32, 35, 40}, size, search = 25;
    size = sizeof(nums)/sizeof(nums[0]);
    //          Search Floor of element
    int floor = find_floor(nums, size, search);
    if(floor != -1)
        cout<<"\nFloor of element "<<search<<" is "<<nums[floor]<<endl;
    else
        cout<<"\nFloor of element not found."<<endl;
    //          Search Ceil of element
    int ceil = find_ceil(nums, size, search);
    if(ceil != -1)
        cout<<"\nCeil of element "<<search<<" is "<<nums[ceil]<<"\n"<<endl;
    else
        cout<<"\nCeil of element not found.\n"<<endl;
    return 0;
}