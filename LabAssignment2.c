//Write a C program to compare the running times (in milliseconds) of Bubble Sort and Merge Sort for the following array:{1,3,42,2,41,66,66,33,98,0}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//function for priting the array
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }
}
//function for bubble sort
void bubbleSort(int arr[], int size)
{
 int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The sorted array is\n");
    printArray(arr, size);
}
//Function for merge sort
void merge(int arr[], int left, int m, int right)
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    // create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[left..right]*/
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Copy the remaining elements of L[], if there are any 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  // Copy the remaining elements of R[], if thereare any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// left is for left index and right is right index of the sub-array of arr to be sorted 
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and h
        int m = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        merge(arr, left, m, right);
    }
}
int main()
{
    int maxsize = 10, choice;
    int arrBubble[10] = {1, 3, 42, 2, 41, 66, 66, 33, 98, 0},arrMerge[10] = {1, 3, 42, 2, 41, 66, 66, 33, 98, 0};
    double timeTakenByBubbleSort, timeTakenByMergeSort;
    clock_t t;
    printf("\n\nCompare sorting Algorithms\n\n");
    printf("Given unsorted array:{1, 3, 42, 2, 41, 66, 66, 33, 98, 0}\n\n");
    do
    {
        printf("\n*Operations*\n1:Sorting the array elements using Bubble Sort\n2:Sorting the array elements using Merge Sort\n3:To compare & check Which algorithm is faster and why?\n4:To exit\n");
        printf("Enter your choice\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            t = clock();
            bubbleSort(arrBubble, maxsize);
            sleep(1);
            t = clock() - t;
            timeTakenByBubbleSort = ((double)t) / CLOCKS_PER_SEC;
            printf("\nTime Taken by Bubble Sort(*in milliseconds):%f\n",(double)timeTakenByBubbleSort);
            break;
        case 2:
            t = clock();
            mergeSort(arrMerge, 0, (maxsize - 1));
            printf("The sorted array is\n");
            printArray(arrMerge, maxsize);
            sleep(1);
            t = clock() - t;
            timeTakenByMergeSort = ((double)t) / CLOCKS_PER_SEC;
            printf("\nTime Taken by Merge Sort(*in milliseconds):%f\n",(double)timeTakenByMergeSort);
            break;
        case 3:
            printf("\n\nMerge Sort is faster than Bubble sort by %f milliseconds\n", (timeTakenByBubbleSort - timeTakenByMergeSort));
            printf("\n\nMerge Sort is faster than Bubble sort because Bubble sort is a simpler algorithm to construct, but far less efficient/much slower than merge sort as merge Sort is a recursive algorithm that is used in most of the servers and applications that require sorting procedures. It is one of the fastest methods to sort a data set and more importantly, it requires minimum time to do so. For large data sets, which is actually our main concern, the merge sort is definitely more effective than most other algorithms in terms of time.Merge Sort is considered to be one of the fastest sorting algorithms, it is a bit more complex than Bubble Sort but its more efficient. The idea of Merge Sort is to divide the data-set into smaller data-sets, sort those smaller data-sets and then join them (merge them) together. The way this algorithm behaves is by sorting the left side of the data- set first then the right part and them merging them. Merge sort will divide in two the data-set until all the elements are separate then it will start joining from left to right in pairs then those pairs will merge from left to right until there are only two bigger pairs to join. If we think about it, this makes it easy to merge because if we have to parts of a data-set that are both sorted we can then compare the first element in one data-set with the other and determine which one is smaller, therefore, pushing that smaller element first into a new data-set.\n");
            break;
        case 4:
            printf("To Exit\n");
            break;
         default:
            printf("Enter from above options\n");
            break;
        }
    } while (choice != 4);
     return 0;
}