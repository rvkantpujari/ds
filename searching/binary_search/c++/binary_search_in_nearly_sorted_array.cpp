#include <iostream>
using namespace std;

/*
    Find smallest alphabet or next alphabet greater than a given character.
*/

int search_nearly_sorted_array(int arr[], int N, int srch)
{
    int beg=0, end=N-1, mid;
    while(beg<=end)
    {
        mid = beg + (end-beg)/2;
        if(arr[mid] == srch)
            return mid;
        else if(mid-1 >= beg && arr[mid - 1] == srch)
            return mid - 1;
        else if(mid+1 <= end && arr[mid + 1] == srch)
            return mid + 1;
        else if(srch < arr[mid])
            end = mid - 2;
        else if(srch > arr[mid])
            beg = mid + 2;
    }
    return -1;
}

int main()
{
    int nums[] = { 12, 15, 18, 21, 24, 29, 38, 35, 40}, size, search = 18;
    size = sizeof(nums)/sizeof(nums[0]);
    int pos = search_nearly_sorted_array(nums, size, search);
    if(pos != -1)
        cout<<"\nElement found at index "<<pos<<endl;
    else
        cout<<"\nElement not found."<<endl;
    return 0;
}