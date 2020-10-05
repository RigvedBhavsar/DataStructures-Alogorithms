#include<iostream>          // input output stream header file

using namespace std;        // standard namespace

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class Stack
{
public:                     // Access specifier
    PNODE Head;      		// Characteristics
    
    Stack()               	// Default constructor
    {
        Head = NULL;
    }
    
    void Push(int value)
    {
        PNODE newn = NULL;

        newn = new NODE;        // like malloc in c++ use new operator
        newn->data = value;
        newn->next = NULL;
        
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
        }
    }
    
    int Pop()
    {
        if(Head == NULL)        // stack is empty
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        else                        // Stack conrtains atleast one node
        {
            int no = 0;
            no = Head->data;
            PNODE temp = Head;
            Head = Head ->next;
        
            delete temp;        //delete is llike a free in c
            return no;
        }
    }
    
    void Display()
    {
        PNODE temp = Head;
        
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
};

int main()
{
    int choice = 1;
    int no = 0;
    
    Stack obj1;       	// Object of stack class
   
    while(choice != 0)
    {
        cout<<"Enter your choice\n";
        cout<<"1: Push the element\n";
        cout<<"2: Pop the element\n";
        cout<<"3: Display the elements\n";
        cout<<"0: Terminate the application\n";
        
        cin>>choice;            // cin is like scanf of C
        
        switch(choice)
        {
            case 1:
                cout<<"Enter the element\n";
                cin>>no;
                obj1.Push(no);
                break;
            
            case 2:
                no = obj1.Pop();
                cout<<"Poped element is : "<<no<<"\n";
                break;
            
            case 3:
                cout<<"Elements of stack are\n";
                obj1.Display();
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Wrong choice\n";
        }
    }
    
    return 0;
}

