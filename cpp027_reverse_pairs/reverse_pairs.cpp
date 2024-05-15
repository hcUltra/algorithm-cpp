/*
 * @description 翻转对
 * @date   2024/5/15 18:35
 * @author zhc
 */
#include <iostream>

using namespace std;

int merge(int arr[], int l, int m, int r)
{
    int ans = 0;
    // 统计答案
    for(int wi = l, wj = m + 1; wi <= m; ++wi)
    {
        while(wj <= r && (long long) arr[wi] > (long long) (2*arr[wj]))
        {
            wj++;
        }
        ans += wj - m - 1;
    }

    // 归并有序数组
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

    for(int x = l; x <= r; ++x)
    {
        arr[x] = help[x - l];
    }

    return ans;
}

int reverse_pairs(int arr[], int l, int r)
{
    if(l >= r)
    {
        return 0;
    }
    int m = (l + r)/2;
    return reverse_pairs(arr, l, m) + reverse_pairs(arr, m + 1, r) + merge(arr, l, m, r);

}

int main()
{
    int arr[] = {2, 4, 3, 5, 1};
    cout << reverse_pairs(arr, 0, sizeof(arr)/sizeof(int) - 1) << endl;
    return 0;
}
