#include <iostream>
#define MAXSIZE 100 
typedef struct Stack
{
	int array[MAXSIZE]; 
	int length = 0;
};
void push(Stack *stack,int val)
{
	if(stack->length<MAXSIZE)stack->length++; 
	for(int i=MAXSIZE-1;i>0;i--)
		stack->array[i]=stack->array[i-1];
	stack->array[0]=val;
}
bool pop(Stack *stack,int *val)
{
    if(stack->length > 0)
    {
        int tmp = stack->array[0];
        if(stack->length>0)stack->length--; 
        for(int i=0;i<MAXSIZE-1;i++)
            stack->array[i]=stack->array[i+1];
        stack->array[MAXSIZE-1] = 0;
        *val = tmp;
        return 1;
    }
    else return 0;
}
void display(Stack stack)
{
    std::cout<<'[';
	for(int i=0;i<stack.length;i++)
		std::cout<<stack.array[i]<<((i==stack.length-1)?"":","); 
    std::cout<<']'<<std::endl;
}
int main() 
{
	Stack s;
    printf("Create Stack ...\n");
	display(s);
	int key=0;
	while(key != 2)
	{
		printf("----------------------------------------\n{Menu of Function}\n\n0:PUSH(&Stack,data)\n1:POP(&Stack,&val)\n2:Exit\n----------------------------------------\n");
		printf("Please Select Function (0~2):");
		std::cin>>key;
		system("cls");
		display(s);
		int a,b;
		switch(key)
		{
			case 0:
				printf("Enter parameter of push(data):");
				std::cin>>a;
				push(&s,a);
				break;
			case 1:
                int tmpVal;
                if(pop(&s,&tmpVal))printf("Pop value is:%d\n",tmpVal);
                else printf("Error the stack is empty!\n");
				system("pause");
				break;
		}
		system("cls");
		display(s);
	}
	printf("The End");
	
} 