#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, querry, extend,i;

    printf("Enter n\n");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    for ( i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Enter the element you want to search\n");
    scanf("%d", &querry);
    for ( i = 0; i < n; ++i)
    {
        if (arr[i] == querry)
        {
            break;
        }
    }
    if (i<n+1)
    {
        printf("element found on index %d \n", i);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Enter the number of  elements you want to increase:\n");
    scanf("%d", &extend);
    arr = realloc(arr, extend * sizeof(int));
    for ( i = 0; i < n + extend; i++)
    {
        arr[i] = i + 1;
    }
    for ( i = 0; i < n + extend; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}