#include<stdio.h>


struct process
{
 int time;
 char name[10];
 int priority;
 struct process *link;
};
typedef struct process *process;

process head;
int a[10];
int p[10];

process get_process();
void get_pro(process head,int n);
void display_list(process head);
void display(process head);
void first_come_first_serve(process head);
void shortest_job_first(process head,int n);
void copy(process head,int n);
void priority(process head,int n);
void round_robin(process head,int n);

process get_process()
{
 process x;
 x=(process)malloc(sizeof(struct process));
 x->link=NULL;
 return x;
}

void get_pro(process head,int n)
{
 int i,t,p;
 char str[10];
 process temp,cur,prev;
// printf("Enter the process name and it's time\n");
 for(i=1;i<=n;i++)
 {
   temp=get_process();
   printf("Name:");
   scanf("%s",str);
   strcpy(temp->name,str);
   printf("Time:");
   scanf("%d",&t);
   temp->time=t;
   printf("Priority:");
   scanf("%d",&p);
   temp->priority=p;
   if(head->link==NULL)
   {
      head->link=temp;
      
   }
   else
   {
     cur=head;
     prev=NULL;
     while(cur!=NULL)
     {
       prev=cur;
       cur=cur->link;
     }
     prev->link=temp;
   }
 }
}

void display_list(process head)
{
 int i;
 process cur;
 printf("The list of processes and thier time is\n");
 printf("\n__________________________________________\n");
 cur=head->link;
 printf("NAME    TIME   PRIORITY\n");
 while(cur!=NULL)
 {
   printf("%s      ",cur->name);
   printf("%d      ",cur->time);
   printf("%d      ",cur->priority);
   printf("\n");
   cur=cur->link;
 }
 printf("\n__________________________________________\n");
}


void display(process head)
{
 int i;
 process cur;
 cur=head->link;
 while(cur!=NULL)
 {
   printf("%s",cur->name);
   for(i=1;i<=cur->time;i++)
   {
    printf("-");
   }
   printf("  ");
   cur=cur->link;
 }
 printf("\n");
}

void first_come_first_serve(process head)
{
 display(head);
}

void shortest_job_first(process head,int  n)
{
 process cur;
 cur=head->link;
 int temp,i,j,key,k;
 for(i=1;i<=n;i++)
 {
  for(j=i+1;j<=n;j++)
  {
  if(a[i]>a[j])
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
  }
 }
 for(i=1;i<=n;i++)
 {
  printf("%d ",a[i]);
 }
 printf("\n");
 for(i=1;i<=n;i++)
 {
  key=a[i];
  while(cur!=NULL)
  {
    if(cur->time==key)
    {
      printf("%s",cur->name);
      for(k=1;k<=key;k++)
      {
        printf("-");
      }
      printf(" ");
    }
   cur=cur->link;
  }
  cur=head->link;
 }
 printf("\n");
}

void copy(process head,int n)
{
  process cur;
  cur=head->link;
  int i;
  for(i=1;i<=n;i++)
  {
   a[i]=cur->time;
   p[i]=cur->priority;
   cur=cur->link;
  // strcpy(b[i],cur->name);
  } 
  for(i=1;i<=n;i++)
  {
   printf("%d ",a[i]);
  }
  printf("\n");
}

void priority(process head,int n)
{
 process cur;
 cur=head->link;
 int temp,i,j,key,k;
 for(i=1;i<=n;i++)
 {
  for(j=i+1;j<=n;j++)
  {
  if(p[i]>p[j])
  {
   temp=p[i];
   p[i]=p[j];
   p[j]=temp;
  }
  }
 }
 for(i=1;i<=n;i++)
 {
  printf("%d ",p[i]);
 }
 printf("\n");
 for(i=1;i<=n;i++)
 {
  key=p[i];
  while(cur!=NULL)
  {
    if(cur->priority==key)
    {
      printf("%s",cur->name);
      for(k=1;k<=cur->time;k++)
      {
        printf("-");
      }
      printf(" ");
    }
   cur=cur->link;
  }
  cur=head->link;
 }
 printf("\n");
}

void round_robin(process head,int n)
{
 int min=999,sum=0,i,j;
 process cur;
 cur=head->link;
 while(cur!=NULL)
 {
  sum+=cur->time;
  if(cur->time<min)
  {
   min=cur->time;
  }
  cur=cur->link;
 }
 cur=head->link;
// printf("%d",sum);
 for(i=1;i<=sum;i++)
 {
   if(cur->time>=min)
   {
   printf("%s",cur->name);
   for(j=1;j<=min;j++)
   {
     printf("-");
     cur->time-=1;
   }
   }
   printf(" ");
   cur=cur->link;
   if(cur==NULL)
   {
    cur=head->link;
   }
 }
 printf("\n");
}
int main()
{
 int n;
 head=get_process();
 printf("Enter the number of processes:\n");
 scanf("%d",&n);
 get_pro(head,n);
 display_list(head);
 //display(head);
 printf("\nFIRST COME FIRST SERVE\n");
 first_come_first_serve(head);
 copy(head,n);
 printf("\nSHORTEST JOB FIRST\n");
 shortest_job_first(head,n);
 printf("\nPRIORITY JOB SCHEDULING\n");
 priority(head,n);
 //display(head);
 printf("\nROUND ROBIN\n");
 round_robin(head,n);
 return 0;
}
