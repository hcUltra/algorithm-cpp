/*
 * @description 
 * @date   2024/5/17 13:21
 * @author zhc
 */
#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

/**
 * 向上调整,将 i 位置的数字插入到合适的位置，使得堆保持住大根堆的结构
 * @param arr
 * @param i
 */
void heapInsert(int arr[], int i)
{
    // i == 0   ->   arr[0] > arr[0] equal false
    while(arr[i] > arr[(i - 1)/2])
    {
        swap(arr[i], arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

/**
 * 向下调整
 * @param arr
 * @param i
 */
void heapify(int arr[], int i, int size)
{
    // left child index
    int l_idx = 2*i + 1;
    while(l_idx < size)
    {
        int max_idx = (l_idx + 1 < size) && (arr[l_idx] < arr[l_idx + 1]) ? l_idx + 1 : l_idx;
        if(arr[max_idx] <= arr[i])
        {
            break;
        }
        swap(arr[i], arr[max_idx]);
        i = max_idx;
        l_idx = 2*i + 1;
    }
}

void heap_sort1(int arr[], int length)
{
    // 建堆时间复杂度：O(log n)
    for(int i = 0; i < length; ++i)
    {
        heapInsert(arr, i);
    }
    // 排序时间复杂度: O(log n)
    int size = length;
    while(size > 1)
    {
        swap(arr[0], arr[--size]);
        heapify(arr, 0, size);
    }
}

void heap_sort2(int arr[], int length)
{
    // 建堆时间复杂度：O(n)
    for(int i = length - 1; i >= 0; --i)
    {
        heapify(arr, i, length);
    }
    // 排序时间复杂度: O(log n)
    int size = length;
    while(size > 1)
    {
        swap(arr[0], arr[--size]);
        heapify(arr, 0, size);
    }
}

int main()
{
    int arr[] = {2, 3, 7, 7, 3, 6, 2, 3, 1, 0};
//    heap_sort1(arr, sizeof(arr)/sizeof(int));
    heap_sort2(arr, sizeof(arr)/sizeof(int));
    for(int x: arr)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
