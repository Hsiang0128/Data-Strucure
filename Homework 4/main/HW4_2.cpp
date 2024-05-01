#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
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
int pop(Stack *stack)
{
	int tmp = stack->array[0];
	if(stack->length>0)stack->length--; 
	for(int i=0;i<MAXSIZE-1;i++)
		stack->array[i]=stack->array[i+1];
	stack->array[MAXSIZE-1] = 0;
	return tmp;
}
void display(Stack stack)
{
	for(int i=0;i<stack.length;i++)
	{
        char TMP[4] = {'S','H','D','C'};
		char color = TMP[(stack.array[i]/13)];
		std::string num;
		if(stack.array[i]%13<=8)num=stack.array[i]%13+0x31;
		else if(stack.array[i]%13 ==9)num="10";
		else if(stack.array[i]%13 == 10)num = "J";
		else if(stack.array[i]%13 == 11)num = "Q";
		else num = "K";
		std::cout<<color<<num<<((i==stack.length-1)?"\n":"\t"); 
	}
}
int selectPlayer(int i,Stack *p1,Stack *p2,Stack *p3,Stack *p4)
{
	switch(i)
	{
		case 0:if(p1->length<13)return 0;
		case 1:if(p2->length<13)return 1;
		case 2:if(p3->length<13)return 2;
		case 3:if(p4->length<13)return 3;
	}
	if(p1->length<13)return 0;
	if(p2->length<13)return 1;
	if(p3->length<13)return 2;
	if(p4->length<13)return 3;
}
void dispenser(Stack *p1,Stack *p2,Stack *p3,Stack *p4)
{
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<4;j++)
		{
			srand(clock());
			srand(time(NULL)^rand());
			int select = rand()%4;
			Sleep(rand()%53+97);
            system("cls");
			if((i+i*j) != 51)
			{
            	std::cout<<"Running....";
            	if(j==0)std::cout<<"\\\n";
            	if(j==1)std::cout<<"|\n";
            	if(j==2)std::cout<<"/\n";
            	if(j==3)std::cout<<"-\n";
			}
            std::cout<<"\n----------------------------------------------------------------\n";
			select = selectPlayer(select,p1,p2,p3,p4);
			if(select==0)push(p1,i+i*j);
			if(select==1)push(p2,i+i*j);
			if(select==2)push(p3,i+i*j);
			if(select==3)push(p4,i+i*j);
            std::cout<<"Player1: ";
            display(*p1);
            std::cout<<"\nPlayer2: ";
            display(*p2);
            std::cout<<"\nPlayer3: ";
            display(*p3);
            std::cout<<"\nPlayer4: ";
            display(*p4);
            std::cout<<"\n----------------------------------------------------------------\n";
		}
	}
    std::cout<<"Finished !\n";
}
int main()
{
	Stack p1,p2,p3,p4;
	dispenser(&p1,&p2,&p3,&p4);
    std::cout<<"<COLOR>\n\tS : Spade\n\tH : Heart\n\tD : Diamond\n\tC : Club\n";
    system("pause");
}