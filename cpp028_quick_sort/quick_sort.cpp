/*
 * @description 快速排序
 * @date   2024/5/16 12:59
 * @author zhc
 */
#include <iostream>
#include<random>
#include<ctime>

using namespace std;

double random(double l, double r)
{
    // 使用mersenne_twister_engine作为随机数生成引擎
    std::random_device rd;
    // 获取一个真正的随机数作为种子
    std::mt19937 gen(rd());
    // 使用Mersenne Twister算法生成随机数  在[l, r]之间的均匀分布  [l,r+1) => [l,r]
    std::uniform_real_distribution<> dis(l, r + 1);
    return dis(gen); // 生成并返回一个在[0, 1)范围内的随机浮点数
}


// 返回arr中 <= x 的最后一个数字的下标 同时最后一个数必须是x
int partition(int arr[], int l, int r, int x)
{
    // x = 3
    // 1    6    2    3     5    4
    //  < x 的越界位置
    int e = l;
    int x_idx = 0;
    for(int i = l; i <= r; ++i)
    {
        if(arr[i] <= x)
        {
            swap(arr[e], arr[i]);

            if(arr[e] == x)
            {
                x_idx = e;
            }
            e++;
        }
    }
    swap(arr[e - 1], arr[x_idx]);

    return e - 1;
}

void quick_sort1(int arr[], int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int x = arr[(int) (random(l, r))];
    int m = partition(arr, l, r, x);
    quick_sort1(arr, l, m - 1), quick_sort1(arr, m + 1, r);
}


int* partition2(int arr[], int l, int r, int x)
{
    int* ret = new int[2];
    ret[0] = l, ret[1] = r;
    int i = l;
    while(i <= ret[1])
    {
        if(arr[i] < x)
        {
            // 区域扩大
            swap(arr[ret[0]++], arr[i++]);
        } else if(arr[i] > x)
        {
            // 交换之后，一个新的数据来到 i 位置，但是 i 位置的数据还没分区，所以 i 不变
            swap(arr[ret[1]--], arr[i]);
        } else
        {
            i++;
        }
    }
    return ret;
}

void quick_sort2(int arr[], int l, int r)
{
    if(l >= r)
    {
        return;
    }

    int x = arr[(int) (random(l, r))];
    int* pairs = partition2(arr, l, r, x);
    // 防止递归时覆盖pairs，使用局部变量记录
    int left = pairs[0];
    int right = pairs[1];
    quick_sort2(arr, l, left - 1), quick_sort2(arr, right + 1, r);
    delete pairs;
}

int main()
{
    int arr[] = {2, 3, 7, 7, 3, 6, 2, 3, 1, 0};
//    quick_sort1(arr, 0, sizeof(arr)/sizeof(int) - 1);
    quick_sort2(arr, 0, sizeof(arr)/sizeof(int) - 1);
    for(int x: arr) cout << x << " ";
    cout << endl;
    return 0;
}