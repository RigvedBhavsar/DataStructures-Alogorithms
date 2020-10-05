//Create an Employye management System 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

struct employee
{
    int Emp_id ;
    char Emp_name[20];
    char Emp_address[30];
    char Emp_project[20];
    char Emp_gender;
    float Emp_salary;
    int Emp_age;
    struct employee *next;
    struct employee *prev;

};

typedef struct employee EMPLOY;
typedef struct employee *PEMPLOY;

class Employee
{
public:
    PEMPLOY Head;
    PEMPLOY Tail;
    int Size;

public:
    Employee();     //Constructor
  //  ~Employee();    //Destructor
    
    
    void InsertEmpFirst(int , char* , char* , char * , char , float ,int);
    void InsertEmpLast(int , char* , char* , char * , char , float ,int);
    void InsertEmpAtPos(int, int , char* , char* , char * , char , float ,int);
    void DisplayEmployee();
    int CountEmployee();
    void DeleteEmpFirst();
    void DeleteEmpLast();
    void DeleteEmpAtPos(int);

    void SearchEmpByName(char*);
    void SearchEmpById(int);
    void SeachEmpByProName(char*);
    void IncrementEmpSal(int , int);
    void ChangeEmpProject (int , char*);

};
//Constructor
Employee :: Employee()
{
    this->Head=NULL;
    this->Tail=NULL;
    this->Size=0;
}

void Employee::InsertEmpFirst(int id , char *name , char *Addr,char *project ,
                                char gender ,float sal , int age)
{

    PEMPLOY newemp = new EMPLOY;
    newemp->Emp_id=id;
    strcpy(newemp->Emp_name,name);
    strcpy(newemp->Emp_address,Addr);
    strcpy(newemp->Emp_project,project);
    newemp->Emp_gender=gender;
    newemp->Emp_salary=sal;
    newemp->Emp_age=age;
    newemp->next=NULL;
    newemp->prev=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {   
        Head=newemp;
        Tail=newemp;
    }
    else
    {
        newemp->next=Head;
        Head->prev=newemp;
        Head=newemp;
    }
    Tail->next=Head;
    Head->prev=Tail;
    Size++;
}

void Employee::InsertEmpLast(int id , char *name , char *Addr,char *project ,
                                char gender ,float sal , int age)
{
    PEMPLOY newemp = new EMPLOY;
    newemp->Emp_id=id;
    strcpy(newemp->Emp_name,name);
    strcpy(newemp->Emp_address,Addr);
    strcpy(newemp->Emp_project,project);
    newemp->Emp_gender=gender;
    newemp->Emp_salary=sal;
    newemp->Emp_age=age;
    newemp->next=NULL;
    newemp->prev=NULL;

    if((Head==NULL)&&(Tail==NULL))
    {
        Head=newemp;
        Tail=newemp;
    }
    else
    {
        Tail->next=newemp;
        newemp->prev=Tail;
        Tail=newemp;
    }
    Tail->next=Head;
    Head->prev=Tail;
    Size++;
}

void Employee::InsertEmpAtPos( int pos ,int id , char *name , char *Addr,char *project ,
                                char gender ,float sal , int age )
{
    if((pos < 1 )||(pos > Size+1))
    {
        cout<<"Invalid postion";
        return;
    }

    if(pos==1)
    {
        InsertEmpFirst(id,name,Addr,project,gender,sal,age);
    }
    else if(pos==(Size+1))
    {
        InsertEmpLast(id,name,Addr,project,gender,sal,age);
    }
    else
    {
        PEMPLOY temp =Head;

        PEMPLOY newemp = new EMPLOY;
        newemp->Emp_id=id;
        strcpy(newemp->Emp_name,name);
        strcpy(newemp->Emp_address,Addr);
        strcpy(newemp->Emp_project,project);
        newemp->Emp_gender=gender;
        newemp->Emp_salary=sal;
        newemp->Emp_age=age;
        newemp->next=NULL;
        newemp->prev=NULL;

         for(int i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        //Right side joining
        newemp->next=temp->next;
        temp->next->prev=newemp;
        //left side Joinig
        temp->next=newemp;
        newemp->prev=temp;
        Size++;
    }
}  
void Employee::DisplayEmployee()
{
    if((Head==NULL)&&(Tail==NULL))
    {
        cout<<"!!!No Employess!!!\n";
        return;
    }
    PEMPLOY temp = Head;

   do
    {
        cout<<"-----------------------------------------------------\n";
        cout<<"Emp ID    \t:\t"<<temp->Emp_id<<endl;
        cout<<"Emp Name\t:\t"<<temp->Emp_name<<endl;
        cout<<"Emp Address\t:\t"<<temp->Emp_address<<endl;
        cout<<"Emp Project\t:\t"<< temp->Emp_project<<endl;
        cout<<"Emp Gender\t:\t"<<temp->Emp_gender<<endl;
        cout<<"Emp Salary\t:\t"<<temp->Emp_salary<<endl;
        cout<<"Emp Age    \t:\t"<<temp->Emp_age<<endl;
        cout<<endl;
       temp = temp->next;
    }while(temp != Tail->next);
}

int Employee ::CountEmployee()
{
    return Size;
}

void Employee :: DeleteEmpFirst()
{
    if((Head==NULL)&&(Tail==NULL))
    {
        cout<<"\n!!!No Employees!!!\n";
        return;
    }
    else if(Head==Tail)
    {
        delete(Head);
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete(Head->prev);

        Tail->next=Head;
        Head->prev=Tail;
    }
    Size--;
}

void Employee::DeleteEmpLast()
{
    if((Head==NULL)&&(Tail==NULL))
    {
        printf("No Employess");
        return;
    }
    else if(Head==Tail)
    {
        delete(Tail);
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Tail=Tail->prev;
        delete(Tail->next);

        Tail->next=Head;
        Head->prev=Tail;
    }
    Size--;
}

void Employee::DeleteEmpAtPos(int pos)
{
    PEMPLOY temp =Head;

    if((pos<1)||(pos>Size+1))
    {
        cout<<"Invalid Position";
        return ;
    }

    if(pos==1)
    {
        return DeleteEmpFirst();
    }
    else if(pos==Size)
    {
        return DeleteEmpLast();
    }
    else
    {
        for(int i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;
        Size--;
    }
}

void Employee :: SearchEmpByName(char *name)
{
    PEMPLOY temp=Head;
    int i=0;
    
    for(i=0;i<Size;i++)
    {
        if(strcmp(name,(temp->Emp_name))==0)
        {
            break;
        }
        temp=temp->next;
    }
    if(i==Size)
    {
        cout<<"\nRECORD NOT FOUND.!!\n"<<endl;
    }
    else
    {
        cout<<"-----------------------------------------------------\n";
        cout<<"\nRECORD FOUND..!!\n"<<endl;
        cout<<"Emp ID    \t:\t"<<temp->Emp_id<<endl;
        cout<<"Emp Name\t:\t"<<temp->Emp_name<<endl;
        cout<<"Emp Address\t:\t"<<temp->Emp_address<<endl;
        cout<<"Emp Project\t:\t"<< temp->Emp_project<<endl;
        cout<<"Emp Gender\t:\t"<<temp->Emp_gender<<endl;
        cout<<"Emp Salary\t:\t"<<temp->Emp_salary<<endl;
        cout<<"Emp Age    \t:\t"<<temp->Emp_age<<endl;
        cout<<endl;
    }
}

void Employee :: SearchEmpById(int id)
{
    PEMPLOY temp=Head;
    int i=0;

    for(i=0;i<Size;i++)
    {
        if(id==(temp->Emp_id))
        {
            break;
        }
        temp=temp->next;
    }
    if(i==Size)
    {
        cout<<"\nRECORD NOT FOUND.!!\n"<<endl;
    }
    else
    {
        cout<<"-----------------------------------------------------\n";
        cout<<"\nRECORD FOUND..!!\n"<<endl;
        cout<<"Emp ID    \t:\t"<<temp->Emp_id<<endl;
        cout<<"Emp Name\t:\t"<<temp->Emp_name<<endl;
        cout<<"Emp Address\t:\t"<<temp->Emp_address<<endl;
        cout<<"Emp Project\t:\t"<< temp->Emp_project<<endl;
        cout<<"Emp Gender\t:\t"<<temp->Emp_gender<<endl;
        cout<<"Emp Salary\t:\t"<<temp->Emp_salary<<endl;
        cout<<"Emp Age    \t:\t"<<temp->Emp_age<<endl;
        cout<<endl;
    }
}


void Employee::SeachEmpByProName(char *pname)
{
    int i=0;
    PEMPLOY temp=Head;

    for(i=0;i<Size;i++)
    {
        if(strcmp(pname,(temp->Emp_project))==0)
        {
            cout<<"-----------------------------------------------------\n";
            cout<<"Emp ID    \t:\t"<<temp->Emp_id<<endl;
            cout<<"Emp Name\t:\t"<<temp->Emp_name<<endl;
            cout<<"Emp Address\t:\t"<<temp->Emp_address<<endl;
            cout<<"Emp Project\t:\t"<< temp->Emp_project<<endl;
            cout<<"Emp Gender\t:\t"<<temp->Emp_gender<<endl;
            cout<<"Emp Salary\t:\t"<<temp->Emp_salary<<endl;
            cout<<"Emp Age    \t:\t"<<temp->Emp_age<<endl;
            cout<<endl;    
        }
        temp=temp->next;
    }
}

void Employee::IncrementEmpSal(int id , int increment )
{
    PEMPLOY temp=Head;

    for(int i=0;i<Size;i++)
    {
        if(id == (temp->Emp_id))
        {
            (temp->Emp_salary)=(temp->Emp_salary)+increment;
            cout<<"Employee salary Incremented\n";
        }
        temp=temp->next;
    }
}

void Employee ::ChangeEmpProject(int id , char *newname)
{
    PEMPLOY temp=Head;
    for(int i=0 ; i<Size ; i++)
    {
        if(id==(temp->Emp_id))
        {
            strcpy((temp->Emp_project),(newname));
            cout<<"Project Assigned\n";
        }
        temp=temp->next;
    }
}
int main()
{
    Employee emp;       // Object creation
        
    int choice = 1;
    int id=0;
    char name[20];
    char address[30];
    char project[20];
    char gender;
    float salary;
    int age;    
    int position = 0;
    char proName[20];
    char isname[20];
    float increment;
    char newproject[20];


    while(choice)
    {
        cout<<"\tEnter choice\n";
        cout<<"\t1 : Insert at first: \n";
        cout<<"\t2 : Insert at last: \n";
        cout<<"\t3 : Insert at position: \n";
        cout<<"\t4 : Delete first: \n";
        cout<<"\t5 : Delete last: \n";
        cout<<"\t6 : Delete at position: \n";
        cout<<"\t7 : Display contents: \n";
        cout<<"\t8 : Count number of node: \n";
        cout<<"\t9 : Search record by Employee name: \n";
        cout<<"\t10 : Search record by Employee Id: \n";
        cout<<"\t11 : Search Employees by project name \n";
        cout<<"\t12 : Increment Employees Salary \n";
        cout<<"\t13 : Change Employees Project \n";

        cout<<"\t0 : Exit the application: \n";
        cout<<"~$: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter Employee At the First place \n";
                
                cout<<"Enter Employee Id\n";
                cin>>id;
                getchar(); 
    
                cout<<"Enter Employee name\n";
                cin.getline(name,sizeof(name));
            
                cout<<"Enter Employee Address\n";
                cin.getline(address,sizeof(address));
            
                cout<<"Enter Employee Project name\n";
                cin.getline(project,sizeof(project));
            
                cout<<"Enter Employee gender\n";
                cin>>gender;
            
                cout<<"Enter Employee Salary\n";
                cin>>salary;
            
                cout<<"Enter Employee Age\n";
                cin>>age;
                //Inserting the Employe at First
                emp.InsertEmpFirst(id,name,address,project,gender,salary,age);
            break;
            
            case 2:
                cout<<"Enter Employee At the Last place \n";
                
                cout<<"Enter Employee Id\n";
                cin>>id;
                getchar(); 
    
                cout<<"Enter Employee name\n";
                cin.getline(name,sizeof(name));
            
                cout<<"Enter Employee Address\n";
                cin.getline(address,sizeof(address));
            
                cout<<"Enter Employee Project name\n";
                cin.getline(project,sizeof(project));
            
                cout<<"Enter Employee gender\n";
                cin>>gender;
            
                cout<<"Enter Employee Salary\n";
                cin>>salary;
            
                cout<<"Enter Employee Age\n";
                cin>>age;
                //Inserting the Employe at the End
                emp.InsertEmpLast(id,name,address,project,gender,salary,age);
            break;
            
            case 3:
                cout<<"Enter Employee At Position \n";
                
                cout<<"Enter Position to Add Employee\n";
                cin>>position;

                cout<<"Enter Employee Id\n";
                cin>>id;
                getchar(); 
    
                cout<<"Enter Employee name\n";
                cin.getline(name,sizeof(name));
            
                cout<<"Enter Employee Address\n";
                cin.getline(address,sizeof(address));
            
                cout<<"Enter Employee Project name\n";
                cin.getline(project,sizeof(project));
            
                cout<<"Enter Employee gender\n";
                cin>>gender;
            
                cout<<"Enter Employee Salary\n";
                cin>>salary;
            
                cout<<"Enter Employee Age\n";
                cin>>age;
                //Inserting the Employe at Postion
                emp.InsertEmpAtPos(position,id,name,address,project,gender,salary,age);
                break;
            
            case 4:
                emp.DeleteEmpFirst();
                cout<<"First Employee deleted\n";                
                break;
            
            case 5:
                emp.DeleteEmpLast();
                cout<<"Last Employee deleted\n";
                break;
            
            case 6:
                cout<<"Enter position  to be deleted\n";
                cin>>position;
                emp.DeleteEmpAtPos(position);
                break;
            
            case 7:
                emp.DisplayEmployee();
                break;
            
            case 8:
                cout<<"Number of elements are : "<<emp.CountEmployee()<<"\n";
                break;
            
            case 9:
                cout<<"Enter the name of the Employee\n";
                getchar();
                //memset(name,'\0',sizeof(name));
                cin.getline(isname,sizeof(isname));
                emp.SearchEmpByName(isname);
                break;
            case 10:
                cout<<"Enter Emp id \n";
                cin>>id;
                emp.SearchEmpById(id);
                break;
            case 11:
                cout<<"Enter Project name\n";
                getchar();
                cin.getline(proName,sizeof(proName));
                emp.SeachEmpByProName(proName);
                break;
            case 12:
                cout<<"Enter Employee ID\n";
                cin>>id;
                cout<<"Enter Increment in Salary\n";
                cin>>increment;
                emp.IncrementEmpSal(id,increment);
                break;

            case 13:
                cout<<"Enter Employee ID\n";
                cin>>id;
                getchar();
                cout<<"Assign new Project to Employee\n";
                cin.getline(newproject, sizeof(newproject));
                emp.ChangeEmpProject(id,newproject);
                break;

            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Wrong choice\n";
                break;
        }// End of swirch
    }   // End of while
    return 0;
}// End of main

/*
//1.change project Name to Employee
//2.Search emp by id
//3.Sarch Emp by name
    In both the seaching cases you have to implement the logic where you can travel linked list 
    from both the end so fast access mechanism..
//4.Search by project name
//5.update salary by emp id
6.All Sql Function
7.Aggregate Function
*/