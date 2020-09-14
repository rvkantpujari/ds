#include <iostream>
using namespace std;

/*
    Program to find next alphabetic element in sorted array.
*/

int find_next_alphabet(char arr[], int N, char srch)
{
    int beg=0, end=N-1, mid, res;
    while(beg<=end)
    {
        mid = beg + (end-beg)/2;
        if(arr[mid] == srch)
        {
            return (mid + 1) % N;
        }
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
    char nums[] = { 'a', 'e', 'i', 'o', 'u' }, search = 'g';
    int size;
    size = sizeof(nums)/sizeof(nums[0]);
    //          Search Ceil of element
    int pos = find_next_alphabet(nums, size, search);
    cout<<"\nNext alphabetic element of '"<<search<<"' is '"<<nums[pos]<<"'"<<endl;
    return 0;
}