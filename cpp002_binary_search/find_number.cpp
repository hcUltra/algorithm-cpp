#include <iostream>

using namespace std;

int BinarySearch(int arr[], int length, int target)
{
    int l = 0, r = length - 1, mid = 0;
    while(l <= r)
    {
        mid = l + ((r - l) >> 1);
        if(arr[mid] > target)
        {
            r = mid - 1;
        } else if(arr[mid] < target)
        {
            l = mid + 1;
        } else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    cout << "查找到的下标：" << (BinarySearch(arr, sizeof(arr)/sizeof(int), 6)) << endl;
    return 0;
}
