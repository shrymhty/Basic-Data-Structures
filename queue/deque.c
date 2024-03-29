# include<stdio.h>
# define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

/*Begin of insert_right*/
void insert_right()
{
	int item;
	if((left==0&&right==MAX-1)||left==right+1)
	{
		printf("Queue overflow\n");
		return;
	}
	if(left==-1)
	{
		left=right=0;
	}
	else 
	{
		if(right==MAX-1)
		{
			right=0;
		}
		else 
		{
			right=right+1;
		}
	}
	printf("Enter the vlue to be inserted in the right: ");
	scanf("%d",&item);
	deque_arr[right]=item;
}
/*End of insert_right*/

/*Begin of insert_left*/
void insert_left()
{	int item;
	if((left==0&&right==MAX-1)||left==right+1)
	{
		printf("\nQueue Overflow\n");
		return;
	}	 
	if(left==-1)
	{
		right=left=0;
	}
	else 
	{
		if(left==0)
		{
			left=MAX-1;
		}
		else 
		{
			left=left-1;
		}
	}
	printf("Enter a value to be inserted at the left : ");
	scanf("%d",&item);
	deque_arr[left]=item;
}
/*End of insert_left*/

/*Begin of delete_left*/
void delete_left()
{	
	int item=deque_arr[left];
	if(left==-1)
	{
		printf("Queue underflow\n");
		return;
	}
	if(left==right)
	{
		left=right=-1;
	}
	else 
	{
		if(left==MAX-1)
		{
			left=0;
		}
		else 
		{
			left=left+1;
		}
	}
	printf("\nThe value deleted is: %d\n",deque_arr[left]);
}
/*End of delete_left*/

/*Begin of delete_right*/
void delete_right()
{if (left == -1)
	{printf("Queue Underflow\n");
		return ;	 }
	printf("Element deleted from queue is : %d\n",deque_arr[right]);
	if(left == right) /*queue has only one element*/
	{	left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;	
}
/*End of delete_right*/
/*Begin of input_que*/
void display_queue()
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	printf("Queue is empty\n");
		return;	 }
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
	{	while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}	}
	else
	{	while(front_pos <= MAX-1)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}
/*End of display_queue*/
/*Begin of input_que*/
void input_que()
{	int choice;
	do
	{	printf("1.Insert at right\n");
		printf("2.Delete from left\n");
		printf("3.Delete from right\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{	case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display_queue();
			break;
		 case 5:
            break;
		 default:
			printf("Wrong choice\n");
		}
	}while(choice!=5);
}
/*End of input_que*/

/*Begin of output_que*/
void output_que()
{	int choice;
	do
	{
		printf("Output restricted queue: \n");
		printf("1.\tInput at left end\n");
		printf("2.\tInsert at the right end\n");
		printf("3.\tDelete at the right end\n");
		printf("4.\tDisplay\n");
		printf("5.\tExit\n");
		printf("Enter a valid option: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
			{
				insert_left();
				break;
			}
			case 2:
			{
				insert_right();
				break;
			}
			case 3:
			{
				delete_right();
				break;
			}
			case 4:
			{
				display_queue();
				break;
			}
			case 5:
			{
				return;
				break;
			}
			default:
			{
				printf("Please enter valid option!\n\n");
			}
		}
	}while(choice!=5);	
}
/*End of output_que*/

/*Begin of main*/
int main()
{	int choice;
	printf("1.Input restricted dequeue\n");
	printf("2.Output restricted dequeue\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
	 case 1 :
		input_que();
		break;
	 case 2:
		output_que();
		break;
	 default:
		printf("Wrong choice\n");
	}
}
/*End of main*/
