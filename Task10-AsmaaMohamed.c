/*******************************************
* Project-5-Create linked list
* It is a project which :
*   -create a linked list includes 5 members
*   -loop the linked list to know no of elements 
*	-scan the elements from the user
*	-print the elements 
*********************************************/

/* include standard data types file*/
#include"../../StdTypes.h"

/*include needed libraries*/
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
 
/*functions prototyping*/
struct Node* new_node(void);

/*define struct for general node in linked list */
struct Node
{
	u16 data;
	struct Node* link;
};

void main(void)
{
	u8 i;                              /*counter for scanning and printing*/
	u8 counter=1;                      /*counter for counting list elements*/
	
	/*pointer points to address of first element*/
	struct Node* start= NULL;
	
	/*creating 5 nodes using pointers & dynamic memory allocation*/
	struct Node* first_node =new_node();
	struct Node* second_node =new_node();
	struct Node* third_node =new_node();
	struct Node* fourth_node =new_node();
	struct Node* fifth_node =new_node();
	
	
	/*linking nodes with each other*/
	start=first_node;                  /*start pointer points to first node address*/
	first_node-> link = second_node;   /*each node points to the next node*/
	second_node->link = third_node;
	third_node->link = fourth_node;
	fourth_node->link = fifth_node;
	fifth_node->link = NULL;           /*last node points to null*/
	
	
	/*calculating the number of elements*/
	struct Node* ptr=first_node;       /*new pointer initialized by first node address*/
	
	while(ptr->link != NULL)           /*repeat until reaching last node which has a link address of NULL*/
	{
		counter++;                     /*increment counter*/
		ptr=ptr->link;                 /*update pointer with the link address of current node which points to next node*/
	}
	printf("\nNo of list elements is : %d ", counter);
	
	
	/*scanning elements from user*/
	printf("\nplease enter %d elements for the list\n",counter);
	
	ptr=first_node;                    /*initialize ptr again with first node address*/
	for(i=0;i<counter;i++)
	{
		scanf("%d",&(ptr->data));      /*scanning data of current node using pointer*/
		ptr=ptr->link;                 /*update pointer with the link address of current node which points to next node*/
	}
	
	
	/*printing scanned elements*/
	printf("\nthe list is: \n");
	
	ptr=first_node;                    /*initialize ptr again with first node address*/
	for(i=0;i<counter;i++)
	{
		printf("%d\n",ptr->data);      /*printing data of current node using pointer*/
		ptr=ptr->link;                 /*update pointer with the link address of current node which points to next node*/
	}
}


/* this function creates a node using dynamic memory allocation then return its address*/
struct Node* new_node(void)
{
	struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
	return ptr;
}
