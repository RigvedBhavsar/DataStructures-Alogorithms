#include<stdio.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;

void BubbleSort(int Arr[] , int Size)
{
    int pass =0 , i=0 , temp=0;

    for(pass=1 ; pass<Size ; pass++)
    {
        for(i=0 ; i<(Size-pass) ; i++)
        {
            if(Arr[i] > Arr[i+1])
            {
                temp= Arr[i];
                Arr[i]=Arr[i+1];
                Arr[i+1]=temp;
            }
        }
    }
}

void UpdatedBubbleSort(int Arr[] , int Size)
{
    int pass =0, i=0, temp=0;
    BOOL sort=FALSE; 

    for(pass=1 ; pass < Size ; pass++)
    {
        sort=FALSE;
        for(i =0 ; i< (Size-pass) ; i++)
        {
            if(Arr[i] > Arr[i+1])
            {
                temp=Arr[i];
                Arr[i]=Arr[i+1];
                Arr[i]=temp;
                sort=TRUE;
            }
        }
        if(sort==FALSE)
        {
            break;
        }
    } 
}

void SelectionSort(int Arr[] ,int Size )
{
    int i=0,j=0 ,iMin=0, temp=0;

    for(i=0 ; i<Size-1 ; i++)
    {
        iMin=i;
        for(j=i+1 ; j<Size ; j++)
        {
            if(Arr[j] < Arr[iMin])
            {
                iMin=j;
            }
        }
        if(i != iMin)
        {
            temp=Arr[i];
            Arr[i]=Arr[iMin];
            Arr[iMin]=temp;
        }
    }
}

void InsertionSort(int Arr[], int Size )
{
    int i=0 , j=0 , key=0;

    for(i=1 ; i<Size ;i++)
    {
        key=Arr[i];
        j=i-1;

        while((j>=0)&&(Arr[j]>key))
        {
            Arr[j+1]=Arr[j];
            j--;
        }
        Arr[j+1]=key;
    }
}

void merge(int Arr[], int p , int q , int r)
{
    int Brr[5]={0};
    int i=0 , j=0 ,k=0;

    j=q+1;

    while( (i<=q) && (j<=r) )
    {
        if(Arr[i] < Arr[j])
        {
            Brr[k]=Arr[i];
            k++;
            i++;
        }
        else
        {
            Brr[k]=Arr[j];
            k++;
            j++;
        }
    }

    while (i<=q)
    {
        Brr[k++]=Arr[i++];
    }

    while (j<=r)
    {
        Brr[k++]=Arr[j++];
    }

    for(i=r ; i>=p ; i--)
    {
        Arr[i]=Brr[--k];
    }
}

void MergeSort(int Arr[] , int p , int r )
{
    int q=0;
    if(p < r)
    {
        q=(p+r)/2;
        MergeSort(Arr, p , q);
        MergeSort(Arr, p+1 , r);
        merge(Arr, p , q ,r);
    }
} 

int main()
{

    int Arr1[] = { 12, 11, 13, 5, 6, 7 };
    int Arr2[] = { 12, 11, 13, 5, 6, 7 };
    int Arr3[] = { 12, 11, 13, 5, 6, 7 };
    int Arr4[] = { 12, 11, 13, 5, 6, 7 };
    int Arr5[] = { 12, 11, 13, 5, 6, 7 };
    
    int Size =6;
    int i=0;


    BubbleSort(Arr1,Size);
    printf("After Bubble Sort\n");
    for(int i=0;i<Size;i++)
    {
        printf("%d\t",Arr1[i]);
    }
    printf("\n");

    UpdatedBubbleSort(Arr2,Size);
    printf("After Compact Bubble Sort\n");
    for(int i=0;i<Size;i++)
    {
        printf("%d\t",Arr2[i]);
    }
    printf("\n");

    SelectionSort(Arr3,Size);
    printf("After Selection Sort\n");
    for(int i=0;i<Size;i++)
    {
        printf("%d\t",Arr3[i]);
    }
    printf("\n");

    InsertionSort(Arr4,Size);
    printf("After Insertion Sort\n");
    for(int i=0;i<Size;i++)
    {
        printf("%d\t",Arr4[i]);
    }
    printf("\n");

    MergeSort(Arr5 , 0 , Size-1);
    printf("After Merge Sort Sort\n");
    for(int i=0;i<Size;i++)
    {
        printf("%d\t",Arr5[i]);
    }
    printf("\n");

    return 0;
}
