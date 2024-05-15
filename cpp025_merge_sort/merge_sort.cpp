/*
 * @description 
 * @date   2024/5/14 20:00
 * @author zhc
 */
#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int help[r - l + 1];
    int k = 0;
    // 此处的 i 使用l初始化
    int i = l, j = m + 1;
    while(i <= m && j <= r)
    {
        help[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }

    while(i <= m)
    {
        help[k++] = arr[i++];
    }

    while(j <= r)
    {
        help[k++] = arr[j++];
    }

    for(int x = l; x <= r; ++x)
    {
        arr[x] = help[x - l];
    }
}

/**
 * 归并排序的递归实现
 * @param arr 待排序数组
 * @param l   左边界
 * @param r   右边界
 */
void merge_sort1(int arr[], int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int m = l + ((r - l) >> 1);
    // 左组有序
    merge_sort1(arr, l, m);
    // 右组有序
    merge_sort1(arr, m + 1, r);
    // 归并
    merge(arr, l, m, r);
}

bool min(int a, int b)
{
    return a < b;
}

/**
 * 归并排序的迭代实现
 * @param arr 待排序数组
 * @param l   左边界
 * @param r   右边界
 */
void merge_sort2(int arr[], int length)
{
    int l, m, r;
    for(int i = 1; i < length; i *= 2)
    {
        l = 0;
        while(l < length)
        {
            m = l + i - 1;
            // 当前没有右组，而左组又是有序的姿态，直接返回当前左组即可
            if(m + 1 >= length)
            {
                break;
            }
            if((l + 2*i - 1) < (length - 1))
            {
                r = l + 2*i - 1;
            } else
            {
                r = length - 1;
            }
            merge(arr,l,m,r);
            // 来到下一个左组，继续merge
            l = r + 1;
        }
    }
}


int main()
{
    int arr[] = {2, 3, 7, 7, 3, 6, 2, 3, 1, 0};
//    merge_sort1(arr, 0, sizeof(arr)/sizeof(int) - 1);
    merge_sort2(arr, sizeof(arr)/sizeof(int));
    for(int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}
