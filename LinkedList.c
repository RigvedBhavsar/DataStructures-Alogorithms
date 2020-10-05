//Implement all types of Linked List in C
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct snode 
{
    int data;
    struct snode *next;
};

struct dnode 
{
    int data;
    struct dnode *next;
    struct dnode *prev;
};

//typedef for Singly LinkedList
typedef struct snode SNODE;
typedef struct snode *PSNODE;
typedef struct snode **PPSNODE;

//typedef for Doubly Linked list
typedef struct dnode DNODE;
typedef struct dnode *PDNODE;
typedef struct dnode **PPDNODE;

//
//  DOUBLY LINEAR LINKED LIST
//
void SinglyLinearInsertFirst(PPSNODE Head, int value)
{
    PSNODE newn = NULL;
    newn = (PSNODE)malloc(sizeof(SNODE));
    
    newn->data = value;
    newn->next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void SinglyLinearDisplay(PSNODE Head)
{
    printf("\n");
    while(Head != NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

int SinglyLinearCount(PSNODE Head)
{
    int iCnt = 0;
    
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    
    return iCnt;
}

void SinglyLinearInsertLast(PPSNODE Head, int value)
{
    PSNODE newn = NULL;
    PSNODE temp = NULL;
    
    newn = (PSNODE)malloc(sizeof(SNODE));
    
    newn->data = value;
    newn->next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else  
    {
        temp = *Head;     
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
    }
    
}

void SinglyLinearDeleteFirst(PPSNODE Head)
{
    PSNODE temp  = *Head;
    
    if(*Head != NULL)
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}

void SinglyLinearDeleteLast(PPSNODE Head)
{
    PSNODE temp = *Head;
    
    if(*Head == NULL)  
    {
        return;
    }
    else if((*Head) -> next == NULL) 
    {
        free(*Head);
        *Head = NULL;
    }
    else 
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
    
        free(temp->next);
        temp->next = NULL;
    }
}

void SinglyLinearInsertAtPos(PPSNODE Head, int value, int pos)
{
    int size = 0, i = 0;
    PSNODE temp = *Head;
    PSNODE newn = NULL;
    
    size = SinglyLinearCount(*Head);
    
    if((pos < 1) || (pos > (size + 1)))
    {
        return;
    }
    else if(pos == 1)
    {
        SinglyLinearInsertFirst(Head, value);
    }
    else if(pos == size + 1)
    {
        SinglyLinearInsertLast(Head, value);
    }
    else
    {
        newn= (PSNODE)malloc(sizeof(SNODE));
        newn->data = value;
        
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
    }
}
void SinglyLinearDeleteAtPos(PPSNODE Head, int pos)
{
    int size = 0,i = 0;
    size = SinglyLinearCount(*Head);
    PSNODE temp, temp2;
    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        SinglyLinearDeleteFirst(Head);
    }
    else if(pos == size)
    {
        SinglyLinearDeleteLast(Head);
    }
    else
    {
        temp = *Head;
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}
//
//  DOUBLY LINEAR LINKED LIST
//

void DoublyLinearInsertFirst(PPDNODE Head, int value)
{
    PDNODE newn = NULL;
    
    newn= (PDNODE)malloc(sizeof(DNODE));
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;            
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;     
        *Head = newn;
    }
}
void DoublyLinearDisplay(PDNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d |<-> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int DoublyLinearCount(PDNODE Head)
{
    int iCnt = 0;
    
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }   
    
    return iCnt;
}

void DoublyLinearInsertLast(PPDNODE Head, int value)
{
    PDNODE newn = NULL;

    newn = (PDNODE) malloc(sizeof(DNODE));
    PDNODE temp = *Head;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)      
        {
            temp = temp->next;
        }
        
        temp->next = newn;
        newn->prev = temp;          
    }
}

void DoublyLinearDeleteFirst(PPDNODE Head)
{
    if(*Head == NULL)           
    {
        return;
    }
    else if((*Head)->next  == NULL)     
    {
        free(*Head);
        *Head = NULL;
    }
    else                            
    {
        (*Head) = (*Head) -> next;
          free((*Head) -> prev);
        (*Head) -> prev = NULL;
    }
}

void DoublyLinearDeleteLast(PPDNODE Head)
{
    PDNODE temp = *Head;
    
    if(*Head == NULL)           
    {
        return;
    }
    else if((*Head)->next  == NULL)     
    {
        free(*Head);
        *Head = NULL;
    }
    else                           
    {
        while(temp->next->next != NULL)    
        {
            temp = temp->next;
        }
        
        free(temp->next);
        temp->next = NULL;
        
    }
}

void DoublyLinearInsertAtPos(PPDNODE Head, int value, int pos)
{
    int size = 0,i = 0;
    PDNODE newn = NULL;
    PDNODE temp = *Head;
    
    size = DoublyLinearCount(*Head);
    
    if((pos < 1) || (pos > size+1))
    {
        return;
    }
    
    if(pos == 1)
    {
        DoublyLinearInsertFirst(Head,value);
    }
    else if(pos == size + 1)
    {
        DoublyLinearInsertLast(Head, value);
    }
    else
    {
        newn= (PDNODE)malloc(sizeof(DNODE));
        newn->data = value;
        newn->next = NULL;
        newn->prev = NULL;
        
        for(i = 1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        
        temp->next = newn;
        newn->prev = temp;
    }
}

void DoublyLinearDeleteAtPos(PPDNODE Head , int pos)
{
    int size = 0, i = 0;
    PDNODE temp = NULL;
    
    size = DoublyLinearCount(*Head);
    
    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        DoublyLinearDeleteFirst(Head);
    }
    else if(pos == size)
    {
        DoublyLinearDeleteLast(Head);
    }
    else
    {
        temp = *Head;
        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }
        temp->next =  temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}
//
//  SINGLY CIRCULAR LINKED LIST
//

void SinglyCircularInsertFirst(PPSNODE Head,PPSNODE Tail,int No)
{
	PSNODE newn= NULL;

	newn=(PSNODE)malloc(sizeof(SNODE));

	newn -> data=No;
	newn -> next=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		newn ->next =*Head;
		*Head=newn;
	}
	(*Tail)->next=(*Head);
}
void SinglyCircularInsertLast(PPSNODE Head, PPSNODE Tail, int No)
{
	PSNODE newn=NULL;

	newn=(PSNODE)malloc(sizeof(SNODE));
	newn->data=No;
	newn->next=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		(*Tail)->next=newn;
		(*Tail)=(*Tail)->next;     
	}
	(*Tail)->next=(*Head);        
}

void SinglyCircularDisplay(PSNODE Head, PSNODE Tail)
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return;	
	}

	do
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}while(Head != Tail->next);
}

int SinglyCircularCount(PSNODE Head,PSNODE Tail)
{
	int iCnt=0;

	if((Head==NULL)&&(Tail==NULL))
	{
		return 0;
	}

	do
	{
		iCnt++;
		Head=Head->next;
	}while(Head != Tail->next);

	return iCnt;
}

void SinglyCircularDeleteFirst(PPSNODE Head , PPSNODE Tail)
{
	if((*Head==NULL)&&(*Tail==NULL))
	{
		return ;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		(*Head)=(*Head)->next;
		free((*Tail)->next);
		(*Tail)->next=(*Head);
	}
}

void SinglyCircularDeleteLast(PPSNODE Head,PPSNODE Tail)
{
	PSNODE temp =NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		return ;
	}
	else if(*Head==*Tail)
	{
		free(*Tail);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		temp=*Head;

		while (temp->next!=(*Tail))
		{
			temp=temp->next;
		}
		free(*Tail);
		*Tail=temp;
		(*Tail)->next=(*Head);
	}
}

void SinglyCircularInsertAtPos(PPSNODE Head, PPSNODE Tail, int No, int iPos)
{
	int i=0,iSize=0;
	PSNODE temp=NULL;
	PSNODE newn =NULL;
	iSize=SinglyCircularCount(*Head,*Tail);

	if((iPos<1)|| (iPos>iSize+1))
	{
		return;
	}
	if(iPos==1)
	{
		SinglyCircularInsertFirst(Head,Tail,No);
	}
	else if(iPos==iSize+1)
	{
		SinglyCircularInsertLast(Head,Tail,No);
	}
	else
	{
		temp=*Head;

		for (i=1; i<iPos-1; i++)
		{
			temp=temp->next;
		}

		newn=(PSNODE)malloc(sizeof(SNODE));

		newn->data=No;
		newn->next=NULL;

		newn->next=temp->next;
		temp->next=newn;
	}
}
void SinglyCircularDeletAtPos(PPSNODE Head, PPSNODE Tail,int iPos)
{
	PSNODE temp1=NULL,temp2=NULL;
	int i=0,iSize=0;
	iSize=SinglyCircularCount(*Head,*Tail);

	if((iPos<1)||(iPos>iSize+1))
	{
	return;
	}
	if(iPos==1)
	{
		SinglyCircularDeleteFirst(Head,Tail);
	}
	else if(iPos==iSize)
	{
		SinglyCircularDeleteLast(Head,Tail);
	}
	else
	{
		temp1=*Head;
		for(i=1;i<iPos-1;i++)
		{
			temp1=temp1->next;
		}
		temp2=temp1->next;

		temp1->next=temp2->next;
		free(temp2);
	}
}
//
// DOUBLY CIRCULAR LINKED LIST
//

void DoublyCircularInsertLast(PPDNODE Head, PPDNODE Tail, int value)
{
    PDNODE newn = NULL;
    
    newn = (PDNODE)malloc(sizeof(DNODE));
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((*Head ==NULL) && (*Tail == NULL))       
    {
        *Head = newn;
        *Tail = newn;
    }
    else           
    {
        (*Tail)->next = newn;
        newn->prev = *Tail;
        *Tail = (*Tail) ->next;   
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

void DoublyCircularInsertFirst(PPDNODE Head, PPDNODE Tail, int value)
{
    PDNODE newn = NULL;
    
    newn = (PDNODE)malloc(sizeof(DNODE));
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((*Head ==NULL) && (*Tail == NULL))       
    {
        *Head = newn;
        *Tail = newn;
    }
    else            
    {
        newn->next = *Head;
        (*Head)->prev = newn;
        *Head = (*Head)->prev;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

void DoublyCircularDisplay(PDNODE Head, PDNODE Tail)
{
        if((Head == NULL) && (Tail == NULL))
        {
            return;
        }
        do
        {
            printf("|%d| <-> ",Head->data);
            Head = Head->next;
        }while(Head != Tail->next);
}

int DoublyCircularCount(PDNODE Head, PDNODE Tail)
{
    int iCnt = 0;
    
        if((Head == NULL) && (Tail == NULL))
        {
            return 0;
        }
    
        do
        {
            iCnt++;
            Head = Head->next;
        }while(Head != Tail->next);

    return iCnt;
}

void DoublyCircularDeleteFirst(PPDNODE Head, PPDNODE Tail)
{
    if(*Head == NULL && *Tail == NULL)  
    {
        return;
    }
    
    if(*Head == *Tail)  
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else    
    {
        *Head = (*Head)->next;
        free((*Tail)->next);    
    
        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}

void DoublyCircularDeleteLast(PPDNODE Head, PPDNODE Tail)
{
    if(*Head == NULL && *Tail == NULL)  
    {
        return;
    }
    
    if(*Head == *Tail) 
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else   
    {
        *Tail  = (*Tail )->prev;
        free((*Tail)->next);      
        
        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}

void DoublyCircularInsertAtPos(PPDNODE Head, PPDNODE Tail, int value, int pos)
{
    int count = 0, i= 0;
    PDNODE temp = *Head;
    PDNODE newn = NULL;
    
    count = DoublyCircularCount(*Head, *Tail);
    
    if((pos < 1) || (pos > (count + 1)))
    {
        return;
    }
    if(pos == 1)
    {
        DoublyCircularInsertFirst(Head, Tail, value);
    }
    else if(pos == count + 1)
    {
        DoublyCircularInsertLast(Head,Tail,value);
    }
    else
    {
        newn= (PDNODE)malloc(sizeof(DNODE));
        
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = value;
        
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        
        temp->next = newn;
        newn->prev = temp;
    }
}

void DoublyCircularDeleteAtPos(PPDNODE Head,PPDNODE Tail, int pos)
{
    int cnt = 0,i = 0;
    PDNODE temp = *Head;
    
    cnt = DoublyCircularCount(*Head, *Tail);
    
    if((pos < 1) || (pos > cnt))
    {
        return;
    }
    if(pos == 1)
    {
        DoublyCircularDeleteFirst(Head, Tail);
    }
    else if(pos == cnt)
    {
        DoublyCircularDeleteLast(Head, Tail);
    }
    else
    {
        for(i = 1; i<pos-1; i++)
        {
            temp =temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}


int main()
{
    int choice=0;
    int operation=0;
    int Data=0;
    int Position=0;
    int elements=0;

    PSNODE first=NULL;
    PSNODE last=NULL;

    PDNODE dfirst=NULL;
    PDNODE dlast=NULL;


    printf("\t\tWelcome to STL\n\n");

    while(1)
    {
        printf("Enter the choice\n \t1. Singly Liner LinkedList\n\t2. Doubly Linear Linkedlist\n\t3. Singly Circular LinkedList\n\t4. Doubly Circular LinkedList\n\t5. Exit\n\n");
        printf("-->");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Singly Linear LinkedList\n");
                while(1)
                {
                    printf("Enter Operation to be performed\n");
                    printf("\n\t1.Insert At First\n\t2.Insert At Last\n\t3.Delete First\n\t4.Delete Last\n\t5.Insert At Position\n\t6.Delete At postion\n\t7.Display Linked List\n\t8.Count Nodes\n");
                    printf("\n\t-->");
                    scanf("%d",&operation);

                    switch(operation)
                    {
                        case 1:
                            printf("Enter Data To Be Inserted At First");
                            scanf("%d", &Data);
                            SinglyLinearInsertFirst(&first,Data);
                            break;
                        case 2:
                            printf("Enter Data To Be Inserted At Last");
                            scanf("%d",&Data);
                            SinglyLinearInsertLast(&first,Data);
                            break;
                        case 3:
                            printf("Deleting First Node");
                            SinglyLinearDeleteFirst(&first);
                            break;
                        case 4:
                            printf("Deleting Last Node");
                            SinglyLinearDeleteLast(&first);
                            break;
                        case 5:
                            printf("Enter Value to Add at Position");
                            scanf("%d",&Data);
                            printf("Enter Position");
                            scanf("%d",&Position);
                            SinglyLinearInsertAtPos(&first,Data,Position);
                            break;
                        case 6:
                            printf("Enter Postion To Be Deleted");
                            scanf("%d",&Position);
                            SinglyLinearDeleteAtPos(&first,Position);
                            break;
                        case 7:
                            printf("Singly Linear Linked List \n\n");
                            SinglyLinearDisplay(first);
                            break;
                        case 8:
                            printf("Number of Nodes in Singly Linear Linked List are:\t");
                            elements=SinglyLinearCount(first);
                            printf("%d\n",elements);
                            break;
                        default:
                            printf("Please Enter valid choice");
                    }
                }
                break;

            case 2:
                printf("Doubly Linear LinkedList");
                while(1)
                {
                    printf("Enter Operation to be performed\n");
                    printf("\n\t1.Insert At First\n\t2.Insert At Last\n\t3.Delete First\n\t4.Delete Last\n\t5.Insert At Position\n\t6.Delete At postion\n\t7.Display Linked List\n\t8.Count Nodes\n");
                    printf("\n\t-->");
                    scanf("%d",&operation);

                    switch(operation)
                    {
                        case 1:
                            printf("Enter Data To Be Inserted At First");
                            scanf("%d", &Data);
                            DoublyLinearInsertFirst(&dfirst,Data);
                            break;
                        case 2:
                            printf("Enter Data To Be Inserted At Last");
                            scanf("%d",&Data);
                            DoublyLinearInsertLast(&dfirst,Data);
                            break;
                        case 3:
                            printf("Deleting First Node");
                            DoublyLinearDeleteFirst(&dfirst);
                            break;
                        case 4:
                            printf("Deleting Last Node");
                            DoublyLinearDeleteLast(&dfirst);
                            break;
                        case 5:
                            printf("Enter Value to Add at Position");
                            scanf("%d",&Data);
                            printf("Enter Position");
                            scanf("%d",&Position);
                            DoublyLinearInsertAtPos(&dfirst,Data,Position);
                            break;
                        case 6:
                            printf("Enter Postion To Be Deleted");
                            scanf("%d",&Position);
                            DoublyLinearDeleteAtPos(&dfirst,Position);
                            break;
                        case 7:
                            printf("Doubly Linear Linked List \n\n");
                            DoublyLinearDisplay(dfirst);
                            break;
                        case 8:
                            printf("Number of Nodes in Doubly Linear Linked List are:\t");
                            elements=DoublyLinearCount(dfirst);
                            printf("%d\n",elements);
                            break;
                        default:
                            printf("Please Enter valid choice");
                    }
                }
                break;

            case 3:
                printf("Singly Circular LinkedList\n");
                while(1)
                {
                    printf("Enter Operation to be performed\n");
                    printf("\n\t1.Insert At First\n\t2.Insert At Last\n\t3.Delete First\n\t4.Delete Last\n\t5.Insert At Position\n\t6.Delete At postion\n\t7.Display Linked List\n\t8.Count Nodes\n");
                    printf("\n\t-->");
                    scanf("%d",&operation);

                    switch(operation)
                    {
                        case 1:
                            printf("Enter Data To Be Inserted At First");
                            scanf("%d", &Data);
                            SinglyCircularInsertFirst(&first,&last,Data);
                            break;
                        case 2:
                            printf("Enter Data To Be Inserted At Last");
                            scanf("%d",&Data);
                            SinglyCircularInsertLast(&first,&last,Data);
                            break;
                        case 3:
                            printf("Deleting First Node");
                            SinglyCircularDeleteFirst(&first,&last);
                            break;
                        case 4:
                            printf("Deleting Last Node");
                            SinglyCircularDeleteLast(&first,&last);
                            break;
                        case 5:
                            printf("Enter Value to Add at Position");
                            scanf("%d",&Data);
                            printf("Enter Position");
                            scanf("%d",&Position);
                            SinglyCircularInsertAtPos(&first,&last,Data,Position);
                            break;
                        case 6:
                            printf("Enter Postion To Be Deleted");
                            scanf("%d",&Position);
                            SinglyCircularDeletAtPos(&first, &last,Position);
                            break;
                        case 7:
                            printf("Singly Circular Linked List \n\n");
                            SinglyCircularDisplay(first,last);
                            break;
                        case 8:
                            printf("Number of Nodes in Singly Circular Linked List are:\t");
                            elements=SinglyCircularCount(first,last);
                            printf("%d\n",elements);
                            break;
                        default:
                            printf("Please Enter valid choice");
                    }
                }
                break;

            case 4:
                printf("Doubly Circular LinkedList");
                while(1)
                {
                    printf("Enter Operation to be performed\n");
                    printf("\n\t1.Insert At First\n\t2.Insert At Last\n\t3.Delete First\n\t4.Delete Last\n\t5.Insert At Position\n\t6.Delete At postion\n\t7.Display Linked List\n\t8.Count Nodes\n");
                    printf("\n\t-->");
                    scanf("%d",&operation);

                    switch(operation)
                    {
                        case 1:
                            printf("Enter Data To Be Inserted At First");
                            scanf("%d", &Data);
                            DoublyCircularInsertFirst(&dfirst,&dlast,Data);
                            break;
                        case 2:
                            printf("Enter Data To Be Inserted At Last");
                            scanf("%d",&Data);
                            DoublyCircularInsertLast(&dfirst, &dlast, Data);
                            break;
                        case 3:
                            printf("Deleting First Node");
                            DoublyCircularDeleteFirst(&dfirst, &dlast);
                            break;
                        case 4:
                            printf("Deleting Last Node");
                            DoublyCircularDeleteLast(&dfirst,&dlast);
                            break;
                        case 5:
                            printf("Enter Value to Add at Position");
                            scanf("%d",&Data);
                            printf("Enter Position");
                            scanf("%d",&Position);
                            DoublyCircularInsertAtPos(&dfirst, &dlast, Data,Position);
                            break;
                        case 6:
                            printf("Enter Postion To Be Deleted");
                            scanf("%d",&Position);
                            DoublyCircularDeleteAtPos(&dfirst, &dlast, Position);
                            break;
                        case 7:
                            printf("Doubly Circular Linked List \n\n");
                            DoublyCircularDisplay(dfirst, dlast);
                            break;
                        case 8:
                            printf("Number of Nodes in Doubly Circular Linked List are:\t");
                            elements=DoublyCircularCount(dfirst, dlast);
                            printf("%d\n",elements);
                            break;
                        default:
                            printf("Please Enter valid choice");
                    }
                }
                break;

            case 5:
                printf("Terminating the program....!\n");
                exit(1);
                break;
            
            default:
                printf("Enter the Correct choice..!!\n");
        }
    }
    return 0;
}

