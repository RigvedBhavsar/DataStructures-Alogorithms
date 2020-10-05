#include<stdio.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL LinearSearch(int Arr[] , int Size , int Value)
{
    int i=0;
    for(i=0;i<Size;i++)
    {
        if(Arr[i]==Value)
        {
            break;
        }
    }

    if(i==Size)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

BOOL LinearSearchBi(int Arr[] , int Size , int value)
{
    int iStart = 0, iEnd=Size-1;
    int i=0;

    while (iStart <= iEnd)
    {
        if((Arr[iStart]==value) || (Arr[iEnd]==value))
        {
            break;
        }
        iStart++;
        iEnd--;
    }
    if(iStart < iEnd)
    {
        return TRUE ;
    }
    else
    {
        return FALSE;
    }
}

BOOL CheckSorted(int Arr[], int Size)
{
    int i=0;
    
    for(i=0 ;i<Size-1;i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            break;
        }
    }
    if(i==Size-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL BinaarySearch(int Arr[] , int Size , int Value)
{
    int iStart =0  ,iEnd=Size-1 ,iMid=0;
    BOOL bRet=FALSE;
    
    bRet = CheckSorted(Arr, Size);
    
    if(bRet==FALSE)
    {
        return(LinearSearch(Arr,Size,Value));
    }
    else
    {
        while (iStart <= iEnd)
        {
            iMid=(iStart+iEnd)/2;

            if(Arr[iMid]==Value)
            {
                break;
            }
            else if(Value < Arr[iMid])
            {
                iEnd=iMid-1;
            }
            else if(Value > Arr[iMid])
            {
                iStart= iMid+1;
            }
        }
    }
    
    if(Arr[iMid]==Value)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    int Arr[] = { 2, 3, 4, 10, 40 };
    int Size = 5;
    int Value =13;
    BOOL bRet=FALSE;

    bRet=LinearSearch(Arr,Size,Value);
    if(bRet==TRUE)
    {
        printf("Linear Search : \t Element Found\n");
    }
    else 
    {
        printf("Linear Search : \t Element Not Found\n");
    }

    bRet=FALSE;
    bRet=LinearSearchBi(Arr,Size,Value);
    if(bRet==TRUE)
    {
        printf("Linear Bi-Directional Search : \t Element Found\n");
    }
    else 
    {
        printf("Linear Bi-Directional Search : \t Element Not Found\n");
    }

    bRet=FALSE;
    bRet=BinaarySearch(Arr,Size,Value);
    if(bRet==TRUE)
    {
        printf("Binary Search : \t Element Found\n");
    }
    else 
    {
        printf("Binary Search : \t Element Not Found\n");
    }

    return 0;   
}