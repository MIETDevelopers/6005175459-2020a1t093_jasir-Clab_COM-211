#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int insert_in_list_at(int *arr, int item, int size,int insert_at)
{
    if(size!=0){
        arr = realloc(arr,sizeof(int));              
    }
    int current;                                          
    current=arr[insert_at];                               
    arr[insert_at] = item;
    for(int i=insert_at+1;i<=size;i++){                          
        arr[i+1] = current;
        arr[i]=current;                                     
        current = arr[i+1];                                
    }
    int new_size_of_list=++size;
    return new_size_of_list;                        
}
int search(int *arr, int item, int size)
{
    int i, search_element = 0;
    for (i = 0; i < size; ++i){
        if (arr[i] == item){
            search_element = 1;
            break;
        }
    }
    if (search_element == 1){
        return i;
    }

    return -1;
}

int deletion(int *arr, int item, int size){
    int final;
    final = search(arr, item, size);
    if (final == -1){
        return -1;
    }
    for (int i = final + 1; i < size; i++){
        arr[i - 1] = arr[i];
    }
    int new_size_of_list=size;
    return new_size_of_list - 1;
}

int print_array(int *arr, int size){
    int count;
    for (count=0; count<size; ++count){
        printf("\narr[%d]=%d",count, *(arr+count));
    }
    return (count+1);
}  
int new_array(int*arr, int size){
    int i;
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int new_size_of_list=size;
    return new_size_of_list;
}
int main()
{
    int choice, size_of_listA = 0, item, final,insert_at;
    int *listA =  (int *)calloc(1,sizeof(int));
     printf("\nEnter the size of array:");
            scanf("%d",&size_of_listA);
            printf("\nEnter %d items in array:\n",size_of_listA);
            size_of_listA=new_array(listA, size_of_listA);
            print_array(listA,size_of_listA);
            printf("\n");

    do{
        printf("\nchoose operation\n");
        printf("\n1. Insert an item\n");
        printf("\n2. Delete an item\n");
        printf("\n3. Search An item\n");
        printf("\n4. Exit \n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("Enter the item you want to insert\n");
            scanf("%d", &item);
            printf("Enter te index where you want to insert\n");
            scanf("%d", &insert_at);
            if(insert_at>size_of_listA){
                printf("!!WRONG INPUT!!\n");
            }
            size_of_listA = insert_in_list_at(listA, item, size_of_listA,insert_at);
            printf("\nItem Added at : %d\n",insert_at);
            printf("Updated array is :\n");
            print_array(listA, size_of_listA);
            break;
        case 2:
            printf("Enter the item you want to delete\n");
            printf("Current array is :\n");
            print_array(listA, size_of_listA);
            printf("\n");
            scanf("%d", &item);
            final = deletion(listA, item, size_of_listA);
            if (final == -1 || size_of_listA == 0){
                printf("Element not found\n");
                break;
            }
            else{
                size_of_listA = final;
                printf("Element is deleted\n");
            }
            printf("Updated array:\n");
            print_array(listA, size_of_listA);
            break;
        case 3:
            printf("Enter the item you want to search:");
            scanf("%d", &item);
            final = search(listA, item, size_of_listA);
            if (final == -1 || size_of_listA == 0)
                printf("Element not found");
            else
                printf("Element found at: %d", final);
            break;
        case 4:
            printf("\npress enter to exit from this program:)");
            getch();
            free(listA);
            exit(0);
            break;
        default:
            printf("!!Wrong input!!");
            break;
        }
        printf("\nPress Enter to continue\n");
        getch();
    } while (1);
    return 0;
}