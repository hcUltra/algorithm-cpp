/*
 * @description 小和问题 https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
 * @date   2024/5/15 15:56
 * @author zhc
 */
#include <iostream>

using namespace std;

bool min(int x, int y)
{
    return x < y;
}

long long merge(int arr[], int l, int m, int r)
{
    // 统计小和
    long long ans = 0;
    int merge_sum = 0;
    int wi = l;
    for(int wj = m + 1; wj <= r; ++wj)
    {
        while(wi <= m && arr[wi] <= arr[wj])
        {
            merge_sum += arr[wi++];
        }
        ans += merge_sum;
    }

    // 归并过程 -> 产生小和的过程
    int help[r - l + 1];
    int k = 0;
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

    for(int x = l; x <= r; x++)
    {
        arr[x] = help[x - l];
    }
    return ans;
}

long long small_sum(int arr[], int l, int r)
{
    if(l >= r)
    {
        return 0;
    }
    int m = l + ((r - l) >> 1);
    return small_sum(arr, l, m) + small_sum(arr, m + 1, r) + merge(arr, l, m, r);
}

int main()
{
    int arr[] = {1, 3, 5, 2, 4, 6};
    cout << small_sum(arr, 0, sizeof(arr)/sizeof(int) - 1) << " ";
    return 0;
}