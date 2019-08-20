//
//  main.cpp
//  Selection_sort
//
//  Created by JF Zhou on 2019/8/15.
//  Copyright © 2019 JF Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a, int *b)//交换两数
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//选择排序
//void selection_sort(int arr[], int size)
//{
//    int i,j;
//    for(i = 0; i < size - 1; i++)//一共要排序size-1次
//    {
//        int min = i;
//        for(j = i + 1; j < size; j++)//走访未排序的元素
//        {
//            if(arr[j] < arr[min])//找到目前最小值
//            {
//                min = j;//记录最小值
//            }
//        }
//        swap(&arr[min], &arr[i]);//交换
//    }
//}

//选择排序优化
void selection_sort(int arr[], int size)
{
    int min,max,left = 0,right = size - 1;//min存储最小值的下标,max存储最大值的下标
    for(min = left, max = left; left <= right; left++, right--)
    {
        min = left;
        max = left;
        for(int i = left; i <= right; i++)
        {
            if(arr[i] < arr[min])//找到最小值的下标
            {
                min = i;
            }
            if(arr[i] > arr[max])//找到最大值的下标
            {
                max = i;
            }
        }
        swap(arr[left], arr[min]);
        if(left == max)
        //代码中，第一次交换结束后，如果left那个位置原本放置的就是最大数，交换之后，需要将最大数的下标还原
        {
            max = min;
        }
        swap(arr[right], arr[max]);
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = {89,22,-3,32,82,55,22,50,37,5,64,35,9,70};
    int size = (int) sizeof(arr)/sizeof(*arr);
    int i;
    cout<<"初始顺序为: ";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    selection_sort(arr, size);
    
    cout << "选择排序后顺序为：";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

