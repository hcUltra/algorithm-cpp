#include <iostream>

using namespace std;

/*
 * 在有序数组中，找到最后一个 <= target 的位置并返回，如果没有满足条件的位置则返回-1
 * */
int BinarySearch(int arr[], int length, int target)
{
    int l = 0, r = length - 1, mid, ans = -1;
    while(l <= r)
    {
        mid = l + ((r - l) >> 1);
        if(arr[mid] <= target)
        {
            l = mid + 1;
            ans = mid;
        } else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    cout << "查找到的首个>= " << arr[3] << "下标：" << (BinarySearch(arr, sizeof(arr)/sizeof(int), arr[3])) << endl;
    return 0;
}