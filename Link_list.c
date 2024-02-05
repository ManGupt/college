//Code to do various operation on Linked Lists.

#include<stdio.h>
//#include<conio.h>
typedef struct node{
int data;
struct node *next;        
}NODE;
NODE *head,*tail,*temp;
static int length=0;
void main_menu();
void add_start(int value);
void add_bw(int value,int location);
void add_end(int data);
void delete_start();
void delete_bw();
void delete_end();
void print_list();
void reverse_list();
void sort_list();

int main()
{
tail=head=(NODE *)0;
/*tail=*head=(struct node *)0;
*tail=*head=NULL;
is also fine as?
*/
main_menu();
getchar();
return 0;
}

void main_menu()
{
int data,option,loc;
char ch;
do
{
//clrscr();
printf("\n1). Add an element in start of Link List.\n");
printf("2). Add an element in between Link List.\n");
printf("3). Add an element in end of Link List.\n");
printf("4). Remove an element from start of Link List.\n");
printf("5). Remove an element from start of Link List.\n");
printf("6). Remove an element from start of Link List.\n");
printf("7). Print Link list.\n");
printf("8). Reverse Link List.\n");
printf("9). Sort Link List in increasing order.\n");
printf("0). EXIT..!!!!!!!");
printf("\n\nEnter your choice..\n");
scanf("%d",&option);
switch(option)
{
case 0:
       exit(1);
case 1:
       {
       printf("Enter the Data to be entered...\n");
       scanf("%d",&data);
       add_start(data);
       }
       break;
case 2:
       {
       if(head==tail)
       printf("Insertion is not possible in between Link List..\n");
       else
	{
	 printf("Enter the Data to be entered...\n");
	 scanf("%d",&data);
	 printf("Enter the no of element after start where data to be inserted\n");
	 scanf("%d",&loc);
	 if(loc<length)
	 add_bw(data,loc);
	}
       }
       break;
case 3:
       {
       printf("Enter the Data to be entered...\n");
       scanf("%d",&data);
       add_start(data);
       }
       break;
case 4:
       delete_start();
       break;
case 5:
       printf("Enter the no of element after start where data to be deleted\n");
       scanf("%d",&loc);
       if(loc<length)
       delete_bw();
       else
       printf("Deletion is not possible in between Link List..\n");
case 6:
       delete_end();
       break;
case 7:
       print_list();
       break;
case 8:
       reverse_list();
       break;
case 9:
       sort_list();
       break;
}
}while(option>0&&option<=9);
}

// All FUNCTIONS DEFINITIONS starts from here...

void add_start(int value)
{
 //clrscr();
 temp=malloc(sizeof(NODE));
 temp->data=value;
 if(head==NULL)
  {
  temp->next=NULL;
  tail=head=temp;
  }
 else
  {
  temp->next=head;
  head=temp;
  }
length++;
}
void add_bw(int value,int location)
{

length++;
}

void add_end(int value)
{
 //clrscr();
 temp=malloc(sizeof(NODE));
 temp->data=value;
 if(tail==NULL)
  {
  temp->next=NULL;
  head=tail=temp;
  }
  else
  {
  temp->next=NULL;
  tail->next=temp;
  }
length++;
}

void delete_start()
{
//clrscr();
if(head)
{
 temp=head;
 if(head!=tail)
 {
  head=temp->next;
  printf("Data deleted is %d .",(temp->data));
  free(temp);
 }
 else
 {
 printf("Data deleted is %d .",(temp->data));
 tail=head=NULL;
 free(temp);
 }
length--;
}
else
printf("Unable ot delete.!!!\n List is empty..!!!\n");
}

void delete_bw()
{
length--;
}

void delete_end()
{
//clrscr();
if(tail)
{
temp=head;
if(head!=tail)
 {
  while(temp->next!=tail)
  temp=temp->next;
  tail=temp;
  temp=temp->next;
  printf("Data deleted is %d .",(temp->data));
  free(temp);
 }
 else
 {
 printf("Data deleted is %d .",(temp->data));
 tail=head=NULL;
 free(temp);
 }
length--;
}
else
printf("Unable ot delete.!!!\n List is empty..!!!\n");
}

void print_list()
{
 printf("\nLink list is \n");
 for(temp=head; temp!=(NODE *)0; temp=temp->next)
 {
  printf("%d-->",(temp->data));
 }
printf("NULL");
fflush(stdin);
getchar();
}

void reverse_list()
{
//clrscr();
char ch;
NODE *p, *q, *r;
printf("This action cannot be undone..!!\nWant to continue(Y/N)..??\n");
fflush(stdin);
ch=getchar();
if(ch=='Y'||ch=='y')
{
printf("\nBefore Reversing ");
print_list();
printf("\nAfter Reversing ");
if(head ==NULL)
return;
p=head;
q=p->next;
tail=p;
p->next=(NODE *)0;
while (q!=(NODE *)0)
{
r=q->next;
q->next=p;
p=q;
q=r;
}
head=p;
print_list();
}
else
main_menu();
}

void sort_list()
{

}

