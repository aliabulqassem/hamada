#include <stdio.h>
#include <stdlib.h>

void swap (int *ptr1, int *ptr2);
void bubble_sort (int *ptrbub,int size);
void binary_search (int *ptrbin);
void selection_sort (int *ptrsel,int size);
void linear_search (int *ptrlin,int size);

int main()
{
    int arr[6]= {13,25,4,11,12,2};
    bubble_sort (arr,6);
    selection_sort(&arr,6);
    binary_search(&arr);
    linear_search(&arr,6);
}
void swap (int *ptr1, int *ptr2)
{
    int temp=0;
    temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
void bubble_sort (int *ptrbub,int size)
{
    int i=0,j=0;
    //int arr[6]= {13,25,4,11,12,2};
    for (i=0; i<size-1; i++)
    {
        for (j=0; j<size-1-i; j++)
        {
            if (ptrbub[j]>ptrbub[j+1])
            {
                swap(&ptrbub[j],&ptrbub[j+1]);
            }
        }
    }
    printf("The array after bubble sort is : ");
    for (i=0; i<size; i++)
    {
        printf("%d\t",ptrbub[i]);
    }
    printf("\n");
}
void binary_search (int *ptrbin)
{
    int start = 0, end = 6,middle = 0;      // start & end like Lift & right
    int index,num,flag=1;                          // index to save the position of the number in array
    printf("please enter the value to search : ");
    scanf("%d",&num);
    while (start<=end)
    {
        middle = (start+end)/2;
        if (num==ptrbin[middle])
        {
            index=middle;
            flag=0;          // assignation of the position in index
            break;
        }
        else if (num>ptrbin[middle])
        {
            start=middle+1;
        }
        else
        {
            end=middle-1;
        }
    }
    if (start>end)
    {
        printf("not found :) ");
    }
    else
    {
        printf("the number is founded in position %d",index+1);
    }
    printf("\n");
}
void selection_sort (int *ptrsel,int size)
{
    int i=0,j=0,min_index;

    for (i=0; i<size-1; i++)
    {
        min_index=i;
        for (j=i+1; j<size; j++)
            if (ptrsel[j]<ptrsel[min_index])
                min_index=j;

        swap(&ptrsel[i],&ptrsel[min_index]);
    }
    printf("The array after selection sort : ");
    for (i=0; i<size; i++)
    {
        printf("%d\t",ptrsel[i]);
    }
    printf("\n");
}
void linear_search (int *ptrlin,int size)
{
    int i=0,j=0,num=0,index=0,flag=1;
    printf("please enter the value to search : ");
    scanf("%d",&num);
    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            if (ptrlin[j]==num)
            {
                index=j;
                flag=0;
                break;
            }
        }
    }
    if (flag==1)
    {
        printf("not found :) ");
    }
    else
    {
        printf("the number is founded in position %d",index+1);
    }
}
