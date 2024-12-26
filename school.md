/*WAP to find a substring in the user input string*/
#include<iostream.h>
#include<conio.h>
#include<string.h>

void main()
{clrscr();
 char a[20],sub_a[20];
 int i,j=0,n,m,flag=0;
 cout<<"\nenter the string:";
 cin>>a;
 cout<<"\nenter the substring to be searched:";
 cin>>sub_a;
 n=strlen(a);
 m=strlen(sub_a);
 for(i=0;i<n;i++)
 {if(sub_a[j]==a[i])
  {j++;
   if(j==m) {flag=1;
	     goto x;}
   else continue;}
  else j=0;}
 x:if(flag==1) cout<<"\nthe substring is present in the given string";
   else cout<<"\n substring not present";
 getch();
}

/*WAP to demonstrate operations on a stack*/
#include<iostream.h>
#include<conio.h>
#include<process.h>

struct node{int info;
	    node *next;
	    }*top,*newptr,*save,*ptr;
node *create_node(int);
void push(node*);
void display(node*);
void pop();

void main()
{top=NULL;
 int inf;
 char ch='y';
 while(ch=='y'||ch=='Y')
 {cout<<"\n enter information for the new node";
  cin>>inf;
  newptr=create_node(inf);
  if(newptr==NULL)
  {cout<<"\ncannot create new node!!aborting";
   getch();
   exit(1);
   }
  push(newptr);
  cout<<"\npress y to push another new node";
  cin>>ch;
 }
 clrscr();
 do{cout<<"\n the stack is now";
    display(top);
    getch();
    cout<<"want to pop elements(y/n)";
    cin>>ch;
    if(ch=='y'||ch=='Y')
     pop();
    }while(ch=='y'||ch=='Y');
}

node *create_node(int n)
{ptr = new node;
 ptr->info=n;
 ptr->next=NULL;
 return ptr;
}

void push(node *np)
{if(top==NULL)
  top=np;
 else{save=top;
      top=np;
      np->next=save;
     }
}

void pop()
{if(top==NULL)
  cout<<"\nUNDERFLOW!!";
 else{ptr=top;
      top=top->next;
      delete ptr;
     }
}

void display(node *np)
{while(np!=NULL)
 {cout<<np->info<<"->";
  np=np->next;
 }
 cout<<"!!\n";
}

/*WAP to show the selection sort algorithm*/
#include<iostream.h>
#include<conio.h>

void main()
{clrscr();
 int a[50],i,j,n,small,pos,tmp;
 cout<<"\nenter no of elements:50 max";
 cin>>n;
 for(i=0;i<n;i++)
 {cout<<"\n enter the"<<i+1<<"th element";
 cin>>a[i];}
 for(i=0;i<n;i++)
 {small=a[i];
  pos=i;
  for(j=i+1;j<n;j++)
  if(a[j]<small)
  {small=a[j];
   pos=j;}
  tmp=a[i];
  a[i]=a[pos];
  a[pos]=tmp;
 }
 cout<<"\nthe sorted array is";
 for(i=0;i<n;i++)
 cout<<a[i]<<",";
 getch();
}


/*WAP to show the insertion sort algorithm*/
#include<iostream.h>
#include<conio.h>

void main()
{clrscr();
 int i,j,n,k,tmp,a[50];
 cout<<"\n the no of array elements";
 cin>>n;
 for(i=0;i<n;i++)
 {cout<<"\n enter the"<<i+1<<"th element";
 cin>>a[i];}
 for(i=0;i<n;i++)
 for(j=0;j<i;j++)
 {if(a[i]<a[j])
  {tmp=a[i];
   for(k=i;k>j;k--)
    a[k]=a[k-1];
   a[j]=tmp;}
 }
 cout<<"\n the sorted array is:";
 for(i=0;i<n;i++)
 cout<<a[i]<<",";
 getch();
}

/*WAP to reverse a string using pointers*/
#include<iostream.h>
#include<conio.h>
#include<string.h>

void main()
{clrscr();
 char sz_a[100],*psz_b,*psz_c,temp;
 int n,i;
 cout<<"\nEnter a string";
 cin>>sz_a;
 n=strlen(sz_a);
 for(i=0;i<(n/2);i++)
 {psz_b=&sz_a[i];
  psz_c=&sz_a[n-i];
  temp=*psz_b;
  *psz_b=*psz_c;
  *psz_c=temp;
 }
 for(i=0;i<=n;i++)
 cout<<sz_a[i];
 getch();
}

/*WAP to calculate inverse of a matrix(3x3)*/ 
#include<stdio.h>
#include<math.h>
#include<conio.h>
int** adjoint(int **matrix,int r,int c)
{int i,j,l,m,t,temp[4],**ad_mat;
 ad_mat=new int *[r];
 for(i=0;i<r;i++)
 {ad_mat[i]=new int[c];
 }
 for(l=0;l<r;l++)
 {for(m=0;m<c;m++)
  {t=0;
   for(i=0;i<r;i++)
   {for(j=0;j<c;j++)
	{if(i!=l && j!=m)
	 {temp[t]=matrix[i][j];
	  t++;
	 }
	}
   }
   ad_mat[l][m]=pow(-1,l+m)*((temp[0]*temp[3])-(temp[1]*temp[2]));
  }
  }
  return ad_mat;
}

void main()
{
 clrscr();
 int **matrix,i,j,**ad_mat;
 float inverse[3][3],det=0;
 matrix=new int *[3];
 for(i=0;i<3;i++)
 {matrix[i]=new int [3];
 }
 printf("\n\nEnter matrix Elements :\n");
 for(i=0;i<3;i++)
 {for(j=0;j<3;j++)
  {printf("\nenter the element at %dth %dth: ",i+1,j+1);
   scanf("%d",&matrix[i][j]);
  }
 }
 ad_mat=adjoint(matrix,3,3);
 printf("\n\nValues Of Matrix :\n");
 for(i=0;i<3;i++)
 {for(j=0;j<3;j++)
  {printf("%d\t",matrix[i][j]);}
  printf("\n");
 }
 printf("\n\nAdjoint Of Matrix Is :\n\n");
 for(i=0;i<3;i++)
 {for(j=0;j<3;j++)
  {printf("%d\t ",ad_mat[j][i]);
	}
   printf("\n");
  }
 for(j=0;j<3;j++)
 {det=det+(ad_mat[0][j]*matrix[0][j]);
 }
 if(det!=0)
 {printf("\n\nThe Determinant Is : %f",det);
  printf("\n\nThe Inverse Of Matrix Is :\n");
  for(i=0;i<3;i++)
  {for(j=0;j<3;j++)
   {inverse[i][j]=ad_mat[j][i]/det;
	printf("%f\t",inverse[i][j]);
	}
   printf("\n");
   }
  }
 else
 printf("\n\nInverse Of Matix Not Possible");
 getch();
 }

/*WAP to multiply two matrices using pointers*/
#include<stdio.h>
#include<conio.h>

void main()
{int a[10][10],b[10][10],c[10][10],i,j,k,x,y;
 int row1,col1,row2,col2,*ptr1,*ptr2;
 clrscr();
 printf("\nenter the no. of rows & columns of matrix 1:max10x10");
 scanf("%d%d",&row1,&col1);
 printf("\nenter matrix 1");
 for(i=0;i<row1;i++)
 for(j=0;j<col1;j++)
 scanf("%d",&a[i][j]);
 printf("\nenter the no. of rows & columns of matrix 2:max10x10");
 scanf("%d%d",&row2,&col2);
 printf("\nenter matrix 2");
 for(i=0;i<row2;i++)
 for(j=0;j<col2;j++)
 scanf("%d",&b[i][j]);
 if(row2!=col1)
 {printf("\nmatrix multiplication not possible");
  getch();
  return;}
 else
 {for(i=0;i<row1;i++)
  for(j=0;j<col2;j++)
  {c[i][j]=0;
   for(k=0;k<row2/*col1*/;k++)
   {x=*(ptr1+i*col1+k);
    y=*(ptr2+k*col2+j);
    c[i][j]=c[i][j]+(x*y);
    }
   }
  printf("\nthe result is:");
  for(i=0;i<row1;i++)
  for(j=0;j<col2;j++)
  printf("%d,",c[i][j]);
 }
 getch();
}


/*An array of record contains information of managers and workers. Print the information in separate files.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
char manager_name[20];
char worker_name[20];
};

struct info
{
char name[20];
};

void main()
{
clrscr();
int n,i;
FILE *fp1,*fp2;
printf("\nenter the no.of array elements:MAX 50 ");
scanf("%d",&n);
struct data d[50];
struct info in;
for(i=0;i<n;i++)
{
printf("\nenter the name of manager at the %dth element: ",i);
scanf("%s",&d[i].manager_name);
printf("\nenter the name of worker at the %dth element: ",i);
scanf("%s",&d[i].worker_name);
}
fp1=fopen("INFO1.DAT","w");
fp2=fopen("INFO2.DAT","w");
for(i=0;i<n;i++)
{
strcpy(in.name,d[i].manager_name);
fwrite(&in,sizeof(in),1,fp1);
strcpy(in.name,d[i].worker_name);
fwrite(&in,sizeof(in),1,fp2);
}
fclose(fp1);
fclose(fp2);
fp1=fopen("INFO1.DAT","r");
fp2=fopen("INFO2.DAT","r");
printf("\nreading from file info1.dat that contains name of managers only\n");
while(fread(&in,sizeof(in),1,fp1)!=0)
{
printf("\n");
printf("%s",in.name);
}
printf("\nreading from file info2.dat that contains name of workers only\n");
while(fread(&in,sizeof(in),1,fp2)!=0)
{
printf("\n");
printf("%s",in.name);
}
fclose(fp1);
fclose(fp2);
getch();
}

/*WAP to demonstrate operations on a linked list*/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node{int info;
	    struct node *next;
	   };
struct node *start,*newptr,*end,*save,*ptr;

struct node * create_node(int n)
{ptr=(struct node*)malloc(sizeof(struct node));
 ptr->info=n;;
 ptr->next=NULL;
 return ptr;
}

void display(struct node *np)
{while(np!=NULL)
 {cout<<np->info<<"->";
  np=np->next;
  }
 getch();
}

void search(struct node*np,int i)
{while(np!=NULL)
 {if(np->info==i)
  {cout<<"\ninformation found"<<"exiting after displayin list";return;}
  else np=np->next;}
 cout<<"\ninfo not present"<<"exiting after diplayin info";
 getch();
 return;
}

void ins_beg(struct node *np)
{if(start==NULL)
 {start=np;
  end=start;
 }
 else
 {save=start;
  start=np;
  np->next=save;}
}

void ins_end(struct node*np)
{if(start==NULL)
 {start=np;
  end=start;
 }else
 {end->next=np;
  end=np;}
}

void del_beg()
{if(start==NULL)
 cout<<"\nUNDERFLOW";
 else{ptr=start;
      start=start->next;
      free (ptr);
     }
}

void del_end()
{if(start==NULL)
 cout<<"\nUNDERFLOW";
 else
 {ptr=end;
  save=start;
  x:if(save->next==end)
  {ptr=end;
   save->next=NULL;end=save;
   free(ptr);return;
  }else
  {save=save->next;
   goto x;}
 }
}

void del_any(int i)
{struct node *pt,*ptr2;
 if(start==NULL)
 cout<<"\nUNDERFLOW";
 else
 {ptr2=ptr=start;
  if(start->info==i)
  {start=start->next;
   free(ptr);
  }
  else
  {x:ptr=ptr->next;
   if(ptr==NULL) {cout<<"\n elment not found";return;}
   if(ptr->info==i)
   {pt=ptr;
    ptr=ptr->next;
    ptr2->next=ptr;
    free(pt);}
   else {ptr2=ptr2->next;goto x;}
  }
 }
}

void main()
{int inf,a,searchvar;
 char ch='y';
 start=NULL;
 xx:while(ch=='Y'||ch=='y')
 {clrscr();
  cout<<"\n enter integer information";
  cin>>inf;
  cout<<"\n creating new node";
  newptr=create_node(inf);
  if(newptr==NULL)
  {cout<<"\nout of memory";
   return;
  }
  else
  {cout<<"\n1.Insert element at beginning";
   cout<<"\n2.Insert element at end";
   cin>>a;
   switch(a)
   {case 1:ins_beg(newptr);
	   cout<<"\nwanna enter another(y/n)";
	   cin>>ch;
	   break;
    case 2:ins_end(newptr);
	   cout<<"\nwanna enter another(y/n)";
	   cin>>ch;
	   break;
    default:cout<<"\nwrong no";
	    cout<<"\nwanna enter another(y/n)";
	    cin>>ch;
	    goto xx;
   }
   }
  }
 display(start);
 cout<<"\n1.wanna search element";
 cout<<"\n2.wanna delete element";
 cout<<"\npress any other key to exit";
 cin>>a;
 switch(a)
 {case 1:cout<<"\nenter information to be searched";
	 cin>>searchvar;
	 search(start,searchvar);
	 break;
  case 2:cout<<"\n1.delete from beginning";
	 cout<<"\n2.delete from end";
	 cout<<"\n3.delete chosen element";
	 cin>>a;
	 switch(a)
	 {case 1:del_beg();
		 break;
	  case 2:del_end();
		 break;
	  case 3:cout<<"\nenter integer info to be deleted";
		 cin>>inf;
		 del_any(inf);
		 break;
	  default:cout<<"\n wrong choice";
	  }break;
  default:cout<<"\n exiting program";
	  return;
 }
 cout<<"\n the link list is:";
 display(start);
 getch();
}

/*WAP to add, subtract, multiply, divide two complex nos.*/
#include<iostream.h>
#include<conio.h>
#include<math.h>

void main()
{clrscr();
 float real[3],img[3];
 char ch;int x;
 cout<<"\n operatins on complex nos.";
 cout<<"\n1.for addition"<<"\n2.for subtraction"
     <<"\n3.for multiplication"<<"\n4.for division";
 cout<<"\nenter you choice";
 cin>>ch;
 cout<<"\nenter real & imaginary parts of 1st no.";
 cin>>real[0]>>img[0];
 cout<<"\nenter real & imaginary parts of 2nd no.";
 cin>>real[1]>>img[1];
 switch(ch)
 {case '1': real[2]=real[0]+real[1];
	    img[2]=img[0]+img[1];
	    break;
  case '2': real[2]=real[0]-real[1];
	    img[2]=img[0]-img[1];
	    break;
  case '3': real[2]=(real[0]*real[1])-(img[0]*img[1]);
	    img[2]=(real[0]*img[1])+(real[1]*img[0]);
	    break;
  case '4': x=pow(real[1],2)+pow(img[1],2);
	    real[2]=((real[0]*real[1])+(img[0]*img[1]))/x;
	    img[2]=((real[1]*img[0])-(real[0]*img[1]))/x;
	    break;
  default:  cout<<"\n wrong choice!!";
	    getch();
	    return;
 }
 cout<<"\nthe result is:"<<real[2]<<" + i("<<img[2]<<")";
 getch();
}

/* WAP to print the fibonacci series */
#include<stdio.h>
#include<conio.h>
void main()
{int i,n;
 float f,s,t;
 clrscr();
 printf("\n enter the no of terms");
 scanf("%d",&n);
 f=0;
 s=1;
 printf("\n the fibonacci series is");
 printf("%.0f %.0f ",f,s);
 for(i=3;i<=n;i++)
 {t= f+s;
  printf("%.0f ",t);
  f=s;
  s=t;
 }
 getch();
}


/* WAP to find the user input number using binary search */
#include<stdio.h>
#include<conio.h>
void main()
{int a[50],n,i,pos,x,flag=0,f,l,mid;
 clrscr();
 printf("\nenter the number of element(ascending order)");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {printf("\n enter the %d element",i+1);
  scanf("%d",&a[i]);
 }
 printf("\n enter the element to be searched");
 scanf("%d",&x);
 f=0;
 l=n-1;
 while((f<=l)&&(flag==0))
 {mid=(f+l)/2;
  if(a[mid]==x)
  {flag=1;
   pos=mid;
  }
  if(a[mid]<x)
   f=mid+1;
  else
   l=mid-1;
 }
 if(flag==1)
  printf("\n the element exist at %d position",pos+1);
 else
  printf("\n the element doesn't exist");
 getch();
}

/*WAP to create a list of n integer elements & arrange them in descending order using bubble sort method*/
#include<stdio.h>
#include<conio.h>

int a[20],s,i,j;

void enter()
{printf("\nenter no of elements");
 scanf("%d",&s);
 for(i=0;i<s;i++)
 {printf("\nenter the %dth element",(i+1));
  scanf("%d",&a[i]);
 }
}


void sorting()
{ int temp;
    for(i=0;i<s-1;i++)
    for(j=0;j<s-(i+1);j++)
    if(a[j]<a[j+1])
    { temp=a[j];
      a[j]=a[j+1];
      a[j+1]=temp;
    }
}

void display()
{ printf("\n elements are in descending order \n ");
    for(i=0;i<s;i++)
    printf("%d ",a[i]);
}

void main()
{ enter();
 sorting();
 display();
 getch();
}

/*WAP to find the age of a person*/
#include <dos.h>
#include <stdio.h>

void main()
{

   struct date d;
   int date,m,y,a,mo,da;
   clrscr();
   printf("\nenter your birth date in dd mth year :");
   scanf("%d %d %d",&date,&m,&y);

   getdate(&d);
   printf("The current year is: %d\n", d.da_year);
   printf("The current day is: %d\n", d.da_day);
   printf("The current month is: %d\n", d.da_mon);

   if(date>31 || m>12 || y>d.da_year)
  { printf("wrong date entered");
  printf("\7");
  exit(0);
   }
   if(m<d.da_mon)
   {
	a=d.da_year-y;
		if(d.da_day>date)
		{
			mo=d.da_mon-m;
			da=d.da_day-date;
		}
		else
		{
			mo=d.da_mon-m-1;
			da=date-d.da_day;
		}
    printf("age of the person is: %d year(s) %d month(s) %d day(s)",a,mo,da);
    }
    else if(m==d.da_mon)
    {
	a=d.da_year-y;
		if(d.da_day>date)
		{
			mo=m-d.da_mon;
			da=d.da_day-date;
		}
   else if(d.da_day==date)
   {
	mo=12-m+d.da_mon;
	da=0;
   }
   else
     {
    mo=11-m+d.da_mon;
    da=30-date+d.da_day;
    }
     printf("age of the person is: %d year(s) %d month(s) %d day(s)",a,mo,da);
    }
    else
    {
    a=d.da_year-y-1;
    mo=11-m+d.da_mon;
    da=30-date+d.da_day;

    printf("age of the person is: %d year(s) %d month(s) %d day(s)",a,mo,da);
    }
    getch();
}

/* WAP to find the user input number using linear search */
#include<stdio.h>
#include<conio.h>
void main()
{int a[50],n,i,x,pos,flag=0;
 clrscr();
 printf("\n enter number of elements ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {printf("\n enter the %d element",i+1);
  scanf("%d",&a[i]);
 }
 printf("\n enter the element to be searched");
 scanf("%d",&x);
 for(i=0;i<n;i++)
 if(a[i]==x)
 {flag=1;
  pos=i;
  break;
 }
 if (flag==1)
  printf("\n the elment exists at %d position",pos+1);
 else
  printf("\n the element doesn't exist");
 getch();
}

/*PROGRAM FOR BASE CONVERSION*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
long tod(char a[],int b)
{ int i,n=0,x,c=strlen(a);
  for(i=0;a[i]!='\0';i++)
  { x=isdigit(a[i])?a[i]-48:a[i]-55;
    if(x<b);
    else
    { printf("wrong input");
      return 0;
    }
    n=n+x*pow(b,c-1-i);
  }
  return n;
}
void dto(long n,int tb)
{ int i;char x[17]="\0";
  for(i=0;i<16;n=n/tb,i++)
   x[15-i]=((n%tb)<10)?n%tb+48:n%tb+55;
  printf("\n result = %s",x);
}
int main()
{ int b,tb;char q[17],ch='y';long n;
  do
  { printf("\n enter no, base, target base ");
    scanf("%s%d%d",&q,&b,&tb);
    if(tb!=b)
    { n=tod(q,b);
      if(n==0);
      else dto(n,tb);
    }
    else printf("\n result = %s",q);
    printf("\n want to enter more (y/n)");
    scanf("\n%c",&ch);
  }while(ch=='y'||ch=='Y');
  return 0;
}
 
/*PROGRAM TO SEARCH FOR STRING IN FILE*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(int argc,char *argv[])
{ FILE *f1,*f2;
  char line[81],ch[20],ch1,ch2[20],xxx[20];
  int flag1=1,flag=0,i,k,c=0,l=1,j=strlen(argv[2]);
  f1=fopen(argv[1],"r");  f2=fopen("temp","w");
  switch(argc)
  { case 2:printf("enter line to be searched");
	   gets(xxx); flag=1;
    case 3:printf("want to replace or not");
	   scanf("\n%c",&ch1);
	   if(ch1=='y'||ch1=='Y')
	   { printf("enter string");
	     gets(ch);
	   }
	   else flag1=0;
	   break;
    case 4:strcpy(ch,argv[3]);
	   break;
    default:printf("\n\nwrong arguments");
	    fclose(f1); fclose(f2);
	    return 1;
  }
  if(flag==1);
  else strcpy(xxx,argv[2]);
  j=strlen(xxx);
  for(flag=0;flag!=1;l++)
{ for(i=0;i<80;i++)
  { line[i]=fgetc(f1);
    if(line[i]==EOF)
    { line[i]='\0';
      flag=1;
      for(;i<80;i++)
      line[i]='\0';
      break;
    }
  }
  { for(i=0;i<80-j+1;i++)
    { if(line[i]=='\n'&&c<=80)
       c=-1;
      c++;
      for(k=0;k<j;k++)
       ch2[k]=line[i+k];
      ch2[k]='\0';
      if(flag1==1)
      { if(strcmp(ch2,xxx)==0)
	{ fwrite(ch,strlen(ch),1,f2);
	  i+=j-1;
	}
	else fwrite(&line[i],1,1,f2);
      }
      else if(strcmp(ch2,xxx)==0)
	    printf("\nline %d col %d",l,c);
    }
  }
}
  fclose(f1); fclose(f2);
  getch();
  return 0;
}
 
/*PROGRAM FOR SNAKE AND LADDER GAME*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int sl[2][20],i=0;
int check(int b)
{ for(i=0;i<20;i++)
  { if(b==sl[0][i])
    { b=sl[1][i];
      if(i<9) return 2;
      else return 3;
    }
  }
  return 4;
}
void main1()
{ int d=0,t=1,b=0,flag=0;
  char ch;
  randomize();
  printf("\npress enter for dice roll");
  printf("\nTurn No. \tDice No. \tAction \t\t\tBox Reached");
  for(;b<=100;t++)
{ scanf("%c",&ch);
  if(ch=='\n'||ch=='\r')
  { d+=random(6)+1;
    if(flag==0)
    { if(d>3)
      { printf("%5d \t%12d \t\tgame starts \t\t%10d",t,d,1);
        flag=1;b=1;d=0;
      }
      else printf("\n%5d \t%12d \t\tgame don't start",t,d);
    }
    else
    { flag=4;
      b+=d;
      if(d%6==0)
      { printf("%5d \t%12d \t\tone more turn",t,d);
        t--;flag=6;b-=d;
      }
      else flag=check(b);
      if(b>=100) flag=5;
    }
    switch(flag)
    { case 2:printf("%5d \t%12d \t\tsnake bit at %2d goto %2d",t,d,b,sl[1][i]);
	     b=sl[1][i];d=0;
	     break;
      case 3:printf("%5d \t%12d \t\tclimb ladder at %2d goto %2d",t,d,b,sl[1][i]);
	     b=sl[1][i];d=0;
	     break;
      case 4:printf("%5d \t%12d \t\tmove by %2d step \t%10d",t,d,d,b);
	     d=0;break;
      case 5:printf("%5d \t%12d \t\tmove by %2d step \t%10d",t,d,d,b);
	     printf("\n\t\t\tgame ends");return;
    }
  }
  else printf("\nwrong key pressed\n");
}
}
int main()
{ char ch,c[3];
  int x=0,i=-1,flag=0;
  FILE *f;
  clrscr();
  f=fopen("c:\\xyz","r");
  while((ch=fgetc(f))!=EOF)
  { if(ch==' ')
    { x++;flag=0;
    }
    if(flag==0)
    switch(x)
    { case 1:i++;flag=1;break;
      case 2:fscanf(f,"%[^:]%s",&c);
	     sl[0][i]=atoi(c);
	     flag=1;break;
      case 3:fscanf(f,"%[^:]%s",&c);
	     sl[1][i]=atoi(c);
	     x=0;flag=1;
    }
  }
  fclose(f);
  main1();
  getch();
  return 0;
}
 
/*PROGRAM FOR FORMATTING OF A FILE*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(int agrc,char* argv[])
{ FILE *f1,*f2,*f;char ch1,ch2,ch3=0;
  int i=-1,j=-1,k,a=0,l,once=0;
  char st1[20]="\0",st2[20]="\0";
  f1=fopen(argv[1],"r");
  f2=fopen("temp","w");
  for(;(ch1=fgetc(f1))!=EOF;)
  { printf("%c",ch1);
    switch(ch1)
    { case '#':if(st1[i]=='\"'||st1[i]=='\'');
	        else fputc('\n',f2);
	        if(st1[i]=='>'||st1[i]=='\"') i--;
	        st1[++i]='#';
	        break;
      case '<':if(st1[i]=='\"'||st1[i]=='\'');
	        if(st1[i]=='#') st1[++i]='<';
	        break;
      case '>':if(st1[i]=='\"'||st1[i]=='\'');
	       if(st1[i]=='<'&&st1[i-1]=='#') i-=2;
	      st1[++i]='>';
	      break;
      case '{':if(st1[i]=='\"'||st1[i]=='\'');
	      else
	      { fputc('\n',f2);
	         st2[++j]='\t';ch3=1;
                   }
	      break;
      case '}':if(st1[i]=='\"'||st1[i]=='\'');
	       else
	       { if(st1[i]=='}') fputc('\n',f2);
                       st1[++i]='}';
                       ch3=1;
	       }
	       break;
      case '(':if(st1[i]=='\"'||st1[i]=='\'');
	       else st1[++i]='(';
	       break;
      case ')':if(st1[i]=='\"'||st1[i]=='\'');
	       else if(st1[i]=='(') i--;
	       break;
      case ';':if(st1[i]=='\"'||st1[i]=='\'');
	      else
	      if(st1[i]=='(');
	      else
	      { fputc(ch1,f2);
                      fputc('\n',f2);
	         once=1;ch3=1;
	       }
	       break;
      case '\'':if(st1[i]=='\\');
	        else
	        { if(st1[i]=='\'') i--;
	          else st1[++i]='\'';
	        }
	        break;
      case '\"':if(st1[i]=='\\');
	        else
  	       { if(st1[i]=='\"')
	          if(st1[i-1]=='#') i-=2;
                       else i--;
	         else st1[++i]='\"';
	      }
	      break;
      case '\\':if(st1[i]=='\\')
	        { i--;ch2=0;
	        }
	        else
	        { st1[++i]='\\';ch2='\\';
	        }
	        break;
      case ' ':if(st1[i]=='\"'||st1[i]=='\'');
                   else if(st1[i]==' ') 
                    once=1;
                    else st1[++i]=' ';
      case '\n':if(st1[i]=='\"'||st1[i]=='\'');
	         else once=1;
      case '\r':if(st1[i]=='\"'||st1[i]=='\'');
	        else once=1;
      case '\t':if(st1[i]=='\"'||st1[i]=='\'');
                     else once=1;
                     break;
      default:if(ch2=='\\'||st1[i]=='\\')
	      { ch2=0;i--;
	      }
	      switch(st1[i])
	      { case '>':if(st1[i-1]=='>')
		         { i-=2;break; }
	  	           else { i--; break; }
	        case '}':fputc('\n',f2);
		         i--;ch3=1;
		         break;
	        case ' ':i--;break;
	      }
    }
    if(ch3==1)
{   for(k=j;k>=0;k--)
    { if(st2[k]!='\0')
      { if(st1[i]=='}');
        else fputc(st2[k],f2);
        if(a==0)
        {if(st2[k]=='\t'&&ch1=='}')
          { for(l=k;l<j-1;l++)
             st2[l]=st2[l+1];
             st2[l]='\0';j--;
             a++;
           }
         }
      }
    }
    a=0;ch3=0;
}
  if(once==0) fputc(ch1,f2);
  else once=0;
  }
  fclose(f1);fclose(f2);
  getch();
  f=fopen("temp","r");
  for(i=0;(ch1=fgetc(f))!=EOF;i++)
   printf("%c",ch1);
  fclose(f);
  getch();
  return 0;
} 

/*PROGRAM TO SOLVE A SUDOKU*/
#include<stdio.h>
#include<conio.h>
int i,j,r,c,e[9][9],flag=0,a1[9],xxx=0;
int a[9]={1,2,3,4,5,6,7,8,9},flagr=0,flagf=0,flagc=0,q[9][9];
void checkr(int i1,int a)
{ int x;
  for(xxx=0,x=3*c;x<3+3*c;x++)
  if(e[i1][x]==1) xxx++;
  if(xxx==3) flagr++;
  else
  for(x=0;x<9;x++)
   if(q[i1][x]==a)
   flagr++;
}
void checkc(int j1,int a)
{ int x;
  for(xxx=0,x=3*r;x<3+3*r;x++)
  if(e[x][j1]==1) xxx++;
  if(xxx==3) flagc++;
  else
  for(x=0;x<9;x++)
   if(q[x][j1]==a)
   flagc++;
}
void chr(int a)
{ int k;
  switch(j%3)
  { case 0:if(e[i][j+1]==1)
           { if(e[i][j+2]==1)
             flag=1;
             else for(k=0;k<9;k++)
                     if(q[k][j+2]==a)
                     flag=1;
           }
           else if(e[i][j+2]==1)
                   for(k=0;k<9;k++)
                   if(q[k][j+1]==a)
                   flag=1;
           break;
    case 1:if(e[i][j+1]==1)
                { if(e[i][j-1]==1)
                   flag=1;
                   else for(k=0;k<9;k++)
                   if(q[k][j-1]==a)
                   flag=1;
                }
                else if(e[i][j-1]==1)
                for(k=0;k<9;k++)
                 if(q[k][j+1]==a)
                 flag=1;
           break;
    case 2:if(e[i][j-1]==1)
           { if(e[i][j-2]==1)
             flag=1;
             else for(k=0;k<9;k++)
                     if(q[k][j-2]==a)
                     flag=1;
           }
           else if(e[i][j-2]==1)
                   for(k=0;k<9;k++)
                   if(q[k][j-1]==a)
                   flag=1;
           break;
  }
  if(flag==1)
  { flagf=1;
    q[i][j]=a;
    e[i][j]=1;
  }
}
void chc(int a)
{ int k;
  switch(i%3)
  { case 0:if(e[i+1][j]==1)
           { if(e[i+2][j]==1)
             flag=1;
             else for(k=0;k<9;k++)
                     if(q[i+2][k]==a)
                     flag=1;
           }
           else if(e[i+2][j]==1)
                   for(k=0;k<9;k++)
                   if(q[i+1][k]==a)
                   flag=1;
           break;
    case 1:if(e[i+1][j]==1)
           { if(e[i-1][j]==1)
             flag=1;
             else for(k=0;k<9;k++)
                      if(q[i-1][k]==a)
                      flag=1;
           }
           else if(e[i-1][j]==1)
                   for(k=0;k<9;k++)
                   if(q[i+1][k]==a)
                   flag=1;
           break;
    case 2:if(e[i-1][j]==1)
           { if(e[i-2][j]==1)
             flag=1;
             else for(k=0;k<9;k++)
                     if(q[i-2][k]==a)
                     flag=1;
           }
           else if(e[i-2][j]==1)
                   for(k=0;k<9;k++)
                   if(q[i-1][k]==a)
                   flag=1;
           break;
  }
  if(flag==1)
  { flagf=1;
    q[i][j]=a;
    e[i][j]=1;
  }
}
void check(int a)
{ int k;
  flagf=flagr=flagc=0;
  for(k=0;k<9;k++)
  { if(q[i][k]==a)
    flagf=1;
    if(q[k][j]==a)
    flagf=1;
  }
  if(flagf==0)
  switch(i%3)
  { case 0:checkr(i+1,a);
	    checkr(i+2,a);
                 break;
    case 1:checkr(i+1,a);
	   checkr(i-1,a);
	   break;
    case 2:checkr(i-1,a);
	   checkr(i-2,a);
	   break;
  }
  if(flagr==2)
   chr(a);
  if(flagf==0)
  switch(j%3)
  { case 0:checkc(j+1,a);
	   checkc(j+2,a);
	   break;
    case 1:checkc(j+1,a);
	   checkc(j-1,a);
	   break;
    case 2:checkc(j-1,a);
	  checkc(j-2,a);
	  break;
  }
  if(flagc==2)
   chc(a);
  if(flagr>=2&&flagc>=2)
  { q[i][j]=a;
    flag=1;
    e[i][j]=1;
  }
}
int main()
{ int k,r1,xx=0;
  printf("\n Enter a sudoku\n");
  for(i=0;i<9;i++)
  for(j=0;j<9;j++)
  scanf("\n%d",&q[i][j]);
  for(i=0;i<9;i++)
  for(j=0;j<9;j++)
  if(q[i][j]==0)
  { e[i][j]=0;
  }
  else e[i][j]=1;
for(r1=0;r1<16;r1++)
{ for(r=0;r<3;r++)
  for(c=0;c<3;c++)
  { for(k=0;k<9;k++)
    a1[k]=a[k];
    for(i=3*r;i<3+3*r;i++)
    for(j=3*c;j<3+3*c;j++)
    if(e[i][j]==1)
     for(k=0;k<9;k++)
     if(a1[k]==q[i][j])
     { a1[k]=0;
       break;
     }
    for(k=0;k<9;k++)
    { if(a1[k]==0);
      else
      { for(i=3*r;i<3+3*r;i++)
	    for(j=3*c;j<3+3*c;j++)
	    if(flag==0)
	     if(e[i][j]==1);
	     else check(a1[k]);
	    else 
        { a1[k]=0;
          if(flag==1)
          { xx++;
            for(i=0;i<9;i++)
            { for(j=0;j<9;j++)
	          printf("%d",q[i][j]);
	          printf("\n");
            }
            flag=0;
            printf("\n%d\n",xx);
            getch();
          }
        }
      }
    }
  }
}
  return 0;
}
