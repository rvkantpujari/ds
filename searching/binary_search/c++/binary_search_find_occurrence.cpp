#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int size, int search)
{
    int beg = 0, end = size-1, mid, result;
    while(beg<=end)
    {
        mid = beg + (end - beg)/2;
        if(search == arr[mid])
        {
            result = mid;
            end = mid - 1;
        }
        else if(search < arr[mid])
            end = mid - 1;
        else if(search > arr[mid])
            beg = mid + 1;
    }
    return result;
}

int findLastOccurrence(int arr[], int size, int search)
{
    int beg = 0, end = size-1, mid, result;
    while(beg<=end)
    {
        mid = beg + (end - beg)/2;
        if(search == arr[mid])
        {
            result = mid;
            beg = mid + 1;
        }
        else if(search < arr[mid])
            end = mid - 1;
        else if(search > arr[mid])
            beg = mid + 1;
    }
    return result;
}


int main()
{
    int nums[] = { 2, 4, 6, 10, 10, 10, 23, 99}, first, last;
    first = findFirstOccurrence(nums, 8, 10);
    cout<<"\nFirst occurrence: "<<first<<endl;
    last = findLastOccurrence(nums, 8, 10);
    cout<<"\nLast occurrence: "<<last<<endl;
    // -------- To find total occurrence or Count ---------
    cout<<"\nCount: "<<last - first + 1<<endl;
    return 0;
}