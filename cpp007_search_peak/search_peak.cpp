/*
 * @description 在无序数组中，找到山峰,数组中相邻两数不相等可以认为最左侧、最右侧都是无穷小
 * @author zhc
 */
#include <iostream>

using namespace std;

int BinarySearchPeak(int arr[], int length)
{
    if(arr == nullptr || length < 0)
    {
        return -1;
    }
    if(length < 2)
    {
        return 0;
    }
    if(arr[0] > arr[1])
    {
        return 0;
    }

    if(arr[length - 2] > arr[length - 1])
    {
        return length - 1;
    }

    int l = 1, r = length - 2, mid = 0;
    while(l <= r)
    {
        mid = l + ((r - l) >> 1);
        if(arr[mid - 1] > arr[mid])
        {
            r = mid - 1;
        } else if(arr[mid] < arr[mid + 1])
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
    int arr[] = {1, 2, 3, 4, 5, 6, 2, 4};
    cout << "查找到的下标：" << (BinarySearchPeak(arr, sizeof(arr)/sizeof(int))) << endl;
    return 0;
}