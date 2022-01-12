#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int size=0;

struct Book
{
	int id;
	char name[15];
	struct Book* next;
}*head=NULL;

void insert(int bid,char bname[15],int pos)
{
	int i;
	struct Book* newnode=(struct Book*)malloc(sizeof(struct Book));
	struct Book* temp=head;
	
	if(pos>(size+1))
	{
		printf("\nThere are Only %d Books in the List!!\nPlease Enter Appropriate Position!!\n",size);
		return;
	}
	while(temp!=NULL && size>0)
	{
		if(temp->id==bid)
		{
			printf("\nThe Id Already Exists!!\nPlease Enter a Unique Id!!\n");
			return;
		}
		temp=temp->next;
	}
	temp=head;
		
	newnode->id=bid;
	strcpy(newnode->name,bname);
	newnode->next=NULL;
	
	if(pos==1)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		for(i=2;i<pos;i++)
			temp=temp->next;
				
		newnode->next=temp->next;		
		temp->next=newnode;
	}
	size++;
}

void search()
{
	int count=0,id1;
	//char name[20];
	struct Book* current=head;
	
	if(current==NULL)
	{
		printf("\nThere are no Books to Search!!!\n");
		return;
	}
	
	printf("\nEnter the Id of the Book: ");
	scanf("%d",&id1);
	
	while(current!=NULL)
	{
		count++;
		if(current->id==id1)
		{
			printf("\nBook Found at %d Position!!!\n",count);
			return;
		}
		current=current->next;
	}
	printf("\nBook Does not Exist!!!\n");
}

void removebook(int pos)
{
	int i;
	struct Book* prev;
	struct Book* temp=head;
	
	if(pos>size)
	{
		printf("\nThere are Only %d Books in the List!!\nPlease Enter Appropriate Position!!\n",size);
		return;
	}
	else
	{
		if(pos==1)
		{
			head=temp->next;
			free(temp);
		}
		else
		{
			for(i=1;i<pos;i++)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
			free(temp);
		}
		size--;
	}
}

void display()
{
	struct Book* temp;
	if(head==NULL)
		printf("\nThere are no Books to Display!!!");
	else
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("\n===========================================================");
			printf("\nBook ID: %d\nBook Name: %s\n",temp->id,temp->name);
	    }
	}
}

int main()
{
	head=NULL;
	int opt,bid,pos;
	char bname[15];
		
	while(1)
	{
		printf("\n1.Insert Book\n2.Remove Book\n3.Display Books\n4.Search\n5.Exit\n\nPlease Enter your Choice:  ");
		scanf("%d",&opt);
			
		switch(opt)
		{
			default:printf("\nPlease Enter Appropriate Option!!!");
					break;
				
			case 1: printf("\nEnter the Id of the Book: ");
				    scanf("%d",&bid);
				    
				    printf("\nEnter the Name of the Book: ");
				    scanf("%s",bname);
				    
				    printf("\nEnter the Position to Enter: ");
				    scanf("%d",&pos);
					
					insert(bid,bname,pos);
					break;
					
			case 2: printf("\nEnter the Position to Delete: ");
				    scanf("%d",&pos);
					removebook(pos);
					break;
			
			case 3: display();
					break;
					
			case 4: search();
					break;
			
			case 5:exit(0);
		}
    } 
    return 0;
}
