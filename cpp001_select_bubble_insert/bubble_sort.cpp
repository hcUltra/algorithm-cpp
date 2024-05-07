#include<iostream>

using namespace std;

void InsertSort(int arr[], int length)
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < length - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void PrintArray(int arr[], int length)
{
    for(int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {2, 3, 7, 7, 3, 6, 2, 3, 1, 0};
    int size = sizeof(arr)/sizeof(int);

    cout << "排序前：";
    PrintArray(arr, size);

    InsertSort(arr, size);

    cout << "排序后：";
    PrintArray(arr, size);
    return 0;
}