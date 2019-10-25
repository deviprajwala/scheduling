#include<stdio.h>


struct process
{
 int time;
 char name[10];
 struct process *link;
 struct process *l_link;
};
typedef struct process *process;

process head;

process get_process();
void get_pro(process head,int n);
void display_list(process head);
void display(process head);
void first_come_first_serve(process head);
void shortest_job_first(process head);


process get_process()
{
 process x;
 x=(process)malloc(sizeof(struct process));
 x->link=NULL;
 x->l_link=NULL;
 return x;
}

void get_pro(process head,int n)
{
 int i,t;
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
   if(head->link==NULL)
   {
      head->link=temp;
      temp->l_link=head;
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
     temp->l_link=head;
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
 printf("NAME    TIME\n");
 while(cur!=NULL)
 {
   printf("%s      ",cur->name);
   printf("%d      ",cur->time);
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

void shortest_job_first(process head)
{
 process cur,prev,next;
 prev=head;
 cur=prev->link;
 next=cur->link;
 while(next!=NULL)
 {
 while(cur!=NULL)
 {
   if(cur->time>next->time)
   {
    prev->link=next;
    next->link=prev;
   }
  cur=cur->link;
  next=cur->link;
 }
 prev=prev->link;
 cur=prev->link;
 next=cur->link;
 }
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
 printf("\nSHORTEST JOB FIRST\n");
 shortest_job_first(head);
 display(head);
 return 0;
}
