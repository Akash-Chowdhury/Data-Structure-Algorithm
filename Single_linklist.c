#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*head;

void create(int);
void insert_1st(int);
void insert_last(int);
void insert_loc(int, int);
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
	else{
		printf("Enter the data: ");
		scanf("%d", &d);
		head->data=d;
		head->next=NULL;
		temp=head;
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
				newnode->next=NULL;
				temp->next=newnode;
				temp=newnode;
			}
		}
		printf("List Created succceddfully :) \n");
	}
}

void insert_1st(int d)
{
	struct node* newnode1;
	newnode1=(struct node*)malloc(sizeof(struct node));
	if(newnode1==NULL)
	{
		printf("Unable to allocate memory");
	}
	else{
		newnode1->data=d;
		newnode1->next=head;
		head=newnode1;
	}
	printf("List updated successfully..\n");
}

void insert_last(int m)
{
	struct node* newnode2, *temp;
	newnode2 = (struct node*)malloc(sizeof(struct node));
	newnode2->data=m;
	newnode2->next=NULL;
	temp=head;
	if(temp==NULL)
	{
		head=newnode2;
	}
	else
	{ 
		while(temp->next!=NULL)
		{
			temp=temp->next;
			
		}
		temp->next=newnode2;
		printf("List Updated succceddfully :) \n");
	}                      
}

void insert_loc(int loc, int a)
{
	struct node *newnode3, *temp;
	newnode3=(struct node*)malloc(sizeof(struct node));
	newnode3->data=a;
	temp=head;
	if(loc==0)
	{
		newnode3->next=temp;
		head=newnode3;
	}
	else{
		for (int i = 1; i < loc; i++)
		{
			temp=temp->next;
		}
		
		newnode3->next=temp->next;
		temp->next=newnode3;
	}
}

void delete_1st()
{
	struct node* temp;
	temp=head;
	if(head==NULL)
	{
		printf("Unable to delete..");
	}
	else{
		head=head->next;
		free(temp);
	}
}

void delete_last()
{
	struct node *temp1, *temp2;
	temp1=head;
	temp2=head->next;
	if(head==NULL)
	{
		printf("Unable to delete..");
	}
	else{
		while(temp2->next != NULL)
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
		temp1->next=NULL;
		free(temp2);
	}
}

void delete_loc(int del_loc)
{
	struct node *temp1, *temp2;
	temp1=head;
	temp2=head->next;
	if(temp1==NULL)
	{
		printf("Unable to delete..");
	}
	else{
		for(int i=1; i<del_loc; i++)
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
		temp1->next=temp2->next;
		free(temp2);
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
		temp=head;
		while(temp!=NULL)
		{
			printf("Data= %d\n", temp->data);
			temp=temp->next;
		}
	}
}


int main()
{
	int n,d,l,loc,a,del_loc;
	printf("Enter total no of nodes: ");
	scanf("%d",&n);
	create(n);
	display();
	printf("Enter the data you Want to insert in 1st position: ");
	scanf("%d", &d);
	insert_1st(d);
	display();
	printf("Enter the data you Want to insert in last position: ");
	scanf("%d", &l);
	insert_last(l);
	display();
	printf("Enter the location: ");
	scanf("%d", &loc);
	printf("Enter the data you Want to insert : ");
	scanf("%d", &a);
	insert_loc(loc,a);
	display();

	//delete func..

	printf("\nAfter deleting 1st node..\n");
	delete_1st();
	display();
	printf("\nAfter deleting last node..\n");
	delete_last();
	display();
	printf("Enter the location: ");
	scanf("%d", &del_loc);
	printf("\nAfter deleting Updated list is... :\n ");
	delete_loc(del_loc);
	display();
	return 0;
}