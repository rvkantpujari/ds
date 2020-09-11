#include <iostream>
using namespace std;

// Program to find how many times a sorted array is rotated.

int findRotations(int arr[], int N)
{
    int beg=0, end=N-1, mid, next, prev;
    if(arr[0] <= arr[N-1])
        return 0;
    while(beg<=end)
    {
        mid = beg + (end-beg)/2;
        next = (mid + 1) % N;
        prev = (mid + N - 1) % N;
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            break;
        else if(arr[0] <= arr[mid])
            beg = mid + 1;
        else if(arr[mid] <= arr[end])
            end = mid - 1;
    }
    return mid;
}

int main()
{
    int nums[] = { 12, 15, 18, 2, 4, 6, 8}, size;
    size = sizeof(nums)/sizeof(nums[0]);
    cout<<"\nTotal Rotations: "<<findRotations(nums, size)<<endl;
    return 0;
}