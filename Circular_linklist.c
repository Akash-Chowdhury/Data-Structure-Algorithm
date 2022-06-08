#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*head;

void create(int);
void insert_1st(int);
void insert_last(int);
void delete_1st();
void delete_last();
void display();

void create(int n)
{
    struct node *newnode, *temp;
    int d;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory!");
    }
    else{
        printf("Enter the data: ");
        scanf("%d",&d);
        head->data=d;
        head->next=head;
        temp=head;
    }
    for(int i=1; i<n; i++)
		{ 
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==NULL)
			{
				printf("Unable to allocate memory!");
				break;
			}
		else{
				printf("Enter the data: ");
				scanf("%d",&d);
				newnode->data=d;
				newnode->next=head;
				temp->next=newnode;
				temp=newnode;
			}
		}
		printf("List Created succceddfully :) \n");
}

void insert_1st(int d)
{
    struct node *newnode1, *temp;
    newnode1=(struct node*)malloc(sizeof(struct node));
    temp=head;
    newnode1->data=d;
    newnode1->next=newnode1;
    if(temp==NULL)
    {
        head=newnode1;
    }
    else{
        while (temp->next != head)
        {
            temp=temp->next;
        }
        newnode1->next=head;
        temp->next=newnode1;
        head=newnode1;
    }
    printf("List Updated succceddfully :) \n");

}

void insert_last(int l)
{
struct node *newnode2, *temp;
newnode2=(struct node*)malloc(sizeof(struct node));
temp=head;
newnode2->data=l;
newnode2->next=newnode2;
if(temp==NULL)
{
    head=newnode2;
}
else
{
    while(temp->next != head)
    {
        temp=temp->next;
    }
    temp->next=newnode2;
    newnode2->next=head;
}
}

void delete_1st()
{
 struct node *current, *temp;
 current=head;
 temp=head;
 if(head==NULL)
 {
     printf("List is empty..");
 }
 else{
     while(current->next != head)
     {
         current=current->next;
     }
     current->next=temp->next;
     head=temp->next;
     free(temp);
 }
}

void delete_last()
{
    struct node *temp, *last;
    temp=head;
    last=head;
    if(head==NULL)
    {
        printf("List is empty..");
    }
    else{
        while(last->next != head)
        {
            temp=last;
            last=last->next;
        }
        temp->next=last->next;
        free(last);  
    }
}

void display()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("Unable to Display!");
	}
	else{
        printf("Data= %d\n", head->data);
		temp=head->next;
		while(temp!=head)
		{
			printf("Data= %d\n", temp->data);
			temp=temp->next;
		}
	}
}

int main()
{
    int n,d,l;
    printf("Enter total no of nodes: ");
	scanf("%d",&n);
	create(n);
	display();
    printf("Enter the data to insert in 1st: ");
	scanf("%d",&d);
    insert_1st(d);
    display();
    printf("Enter the data to insert in last: ");
	scanf("%d",&l);
    insert_last(l);
    display();

    //delete func..
    printf("\nAfter deleting 1st node updated list is: \n");
    delete_1st();
    display();
    printf("\nAfter deleting last node updated list is: \n");
    delete_last();
    display();

    return 0;
}