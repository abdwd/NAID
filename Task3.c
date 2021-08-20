#include <stdio.h>
#include "header.h"

void swap(uint32* x, uint32* y)
{
    uint32 temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(uint32* arr, uint8 size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ( arr[j] > arr[j + 1] )
            {
                swap( &arr[j], &arr[j + 1]);
            }
        }
    }
}


int BinarySearch(uint32* arr, uint8 size, uint32 number)
{
    uint8 sorted = 1;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            sorted = 0;
            break;
        }
    }
    /*So We Need to Sort it First*/
    if (sorted == 0)
    {
        BubbleSort(arr, size);
    }

    /*Binary Search*/
    int left = 0;
    int right = size - 1;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == number)
        {
            return mid;
        }
        if (arr[mid] < number)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;


}
int main()
{
    uint32 arr[256];
    uint8 size;
    uint32 input;
    uint32 number;

    printf("Please Enter Array Size\n");
    scanf_s("%d", &size);

    printf("Please Enter The Elements Separated by a space\n");
    for (int i = 0; i < size; i++)
    {
        scanf_s("%d", &input);
        arr[i] = input;
    }

    printf("Please Enter The Number That You Want to Search For\n");
    scanf_s("%d", &number);

    int result = BinarySearch(arr, size, number);
    if (result == -1)
    {
        printf("NOT FOUND\n");
    }
    else
    {
       // printf("FOUND AT %d", result);
        printf("FOUND at %d \n",result);
    }
    
    return 0;
}


