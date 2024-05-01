#include <iostream>
template<typename T>
class Stack
{
    private:
        typedef struct Node 
        {
            T Val;
            Node *next;
            Node *prev;
        };
        Node *head;
    public:
    Stack()
    {
        head = nullptr;
    }
    void push(T val)
    {
        Node *newNode = new Node;
        newNode->prev = nullptr;
        newNode->Val = val;
        if(head != nullptr)
        {
            head->prev = newNode;
            newNode->next = head;
        }
        else  newNode->next = nullptr;
        head = newNode;
    }
    bool pop(T *val) 
    {
        if(head != nullptr)
        {
            Node *tmp = head;
            T tmpVal = tmp->Val;
            head = tmp->next;
            delete tmp;
            *val = tmpVal;
            return 1;
        }
        else return 0;
    }
    void display()
    {
        std::cout <<'[';
        Node *tmp = head;
        while(tmp!=nullptr)
        {
            std::cout << tmp->Val << ((tmp->next!=nullptr)?" ":"");
            tmp = tmp->next;
        }
        std::cout<<']'<<std::endl;
    }
};
int main()
{
    Stack<int> s;
    printf("Create Stack ...\n");
	s.display();
	int key=0;
	while(key != 2)
	{
		printf("----------------------------------------\n{Menu of Function}\n\n0:PUSH(data)\n1:POP(&val)\n2:Exit\n----------------------------------------\n");
		printf("Please Select Function (0~2):");
		std::cin>>key;
		system("cls");
		s.display();
		int a,b;
		switch(key)
		{
			case 0:
				printf("Enter parameter of push(data):");
				std::cin>>a;
				s.push(a);
				break;
			case 1:
                int tmpVal;
                if(s.pop(&tmpVal))printf("Pop value is:%d\n",tmpVal);
                else printf("Error the stack is empty!\n");
				system("pause");
				break;
		}
		system("cls");
		s.display();
    }
}