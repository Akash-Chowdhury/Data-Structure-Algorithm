#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head;

void create(int);
void insrt_1st(int);
void insrt_last(int);
void insrt_loc(int,int);
void delete_1st();
void delete_last();
void delete_loc(int);
void display();

void create(int n)
{
    struct node* newnode, *temp;
    int d;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory!");
    }
    else
    {
        printf("Enter the data: ");
        scanf("%d",&d);
        head->data=d;
        head->prev=NULL;
        head->next=NULL;
        temp=head;
    }
    for(int i=1; i<n; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Unable to allocate memory!");
        }
        else{
            printf("Enter the data: ");
			scanf("%d",&d);
			newnode->data=d;
            newnode->prev=temp;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
        }
    }
    printf("List Created succceddfully :) \n");
}

void insrt_1st(int d)
{
    struct node *newnode1;
    newnode1=(struct node*)malloc(sizeof(struct node));
    if(newnode1==NULL)
    {
        printf("Unable to allocate memory!");
    }
    else{
        newnode1->data=d;
        newnode1->prev=NULL;
        newnode1->next=head;
        head->prev=newnode1;
        head=newnode1;
        printf("List Updated succceddfully :) \n");
    }
}

void insrt_last(int l)
{
    struct node* newnode2, *temp;
    newnode2=(struct node*)malloc(sizeof(struct node));
    newnode2->data=l;
    newnode2->prev=NULL;
    newnode2->next=NULL;
    if(newnode2==NULL)
    {
         printf("Unable to allocate memory!");
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode2;
        newnode2->prev=temp;
        temp=newnode2;
    }
    printf("List Updated succceddfully :) \n");
}

void insrt_loc(int loc, int a)
{
    struct node* newnode3, *temp;
    newnode3=(struct node*)malloc(sizeof(struct node));
    newnode3->data=a;
    newnode3->prev=NULL;
    newnode3->next=NULL;
    temp=head;
    if(newnode3==NULL)
    {
        printf("Unable to allocate memory!");
    }
    else
    {
        if(loc==0)
        {
            newnode3->next=temp;
            temp->prev=newnode3;
            temp=newnode3;
        }
        else{
            for(int i=1; i<loc; i++)

            {
                temp=temp->next;
            }
            newnode3->next=temp->next;
            temp->next=newnode3;
            newnode3->prev=temp;
        }
        
    }
    printf("List Updated succceddfully :) \n");
}

void display()
{
    struct node * tmp;
    int n = 1;
    if(head == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = head;
        printf("\n\n Data entered on the list are :\n");
 
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->data);
            n++;
            tmp = tmp->next;
        }
    }
}

//delete func
void delete_1st()
{
    struct node* temp;
    temp=head;
    if(head==NULL)
    {
        printf("\nUnable to delete\n");
    }
    else{
        head=head->next;
        free(temp);
    }
    printf("List Updated succceddfully :) \n");
}

void delete_last()
{
    struct node *temp1, *temp2;
    temp1=head;
    temp2=head->next;
    if(head==NULL)
    {
        printf("\nUnable to delete\n");
    }
    else
    {
        while(temp2->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=NULL;
        free(temp2);
    }
    printf("List Updated succceddfully :) \n");
}

void delete_loc(int x)
{
    struct node *temp1, *temp2;
	temp1=head;
	temp2=head->next;
	if(head==NULL)
	{
		printf("Unable to delete..");
	}
	else{
		for(int i=1; i<x; i++)
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
		temp1->next=temp2->next;
		free(temp2);
	}
    printf("List Updated succceddfully :) \n");
}

int main()
{
    int n,d,l,a,loc,x;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);
    create(n);
    display();
    printf("Enter the data to insert in 1st: ");
    scanf("%d", &d);
    insrt_1st(d);
    display();
    printf("Enter the data to insert in last: ");
    scanf("%d", &l);
    insrt_last(l);
    display();
    printf("Enter the location: ");
    scanf("%d", &loc);
    printf("Enter the data to insert in location: ");
    scanf("%d", &a);
    insrt_loc(loc,a);
    display();
    delete_1st();
    display();
    delete_last();
    display();
    printf("Enter the location: ");
    scanf("%d", &x);
    delete_loc(x);
    display();
    return 0;
}