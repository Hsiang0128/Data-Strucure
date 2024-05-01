#include <iostream>
class List{
	private:
		struct Node
		{
			int data;
			Node *next;	
		};
		Node *head;
	public:
		List()
		{
			this->head = nullptr;
		}
		void insertHead(int data){
			this->insert(0,data);
		}
		void insertEnd(int data)
		{
			this->insert(-1,data);
		}
		void insert(int index,int data)
		{
			Node *newNode = new Node;
			newNode->data = data;
			if(index == 0 || (head == nullptr && index == -1) )
			{
				newNode->next = head;
				this->head = newNode;
			}
			else
			{
				Node *ptr = head;
				while(ptr->next != nullptr)
				{
					if(index-- == 1)break;
					ptr = ptr->next;
				}
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
		}
		bool delData(int data)
		{
			int index = search(data);
			if(index != -1)return delNode(index);
			else return 1;
		}
		bool delNode(int index)
		{
			if(head == nullptr)return 1;
			else if(index == 0)
			{
				Node *tmp = this->head;
				this->head = this->head->next;
				delete tmp;
			}
			else
			{ 
				Node *ptr = head;
				while(ptr->next != nullptr)
				{
					if(index-- == 1)break;
					ptr = ptr->next;
				}
				if(ptr->next != nullptr)
				{	
					Node *tmp = ptr->next;
					ptr->next = ptr->next->next;
					delete tmp;
				}
				else return 1;
			} 
			return 0;
		}
		int search(int data)
		{
			int index = 0;
			Node *ptr = head;
			while(ptr!=nullptr)
			{
				if(ptr->data == data)return index;
				ptr = ptr->next;
				index++;
			}
			return -1;
		}
		void display()
		{
			bool flag = 0;
			Node *ptr = head;
			printf("Now List State => [");
			while(ptr!=nullptr)
			{
				printf(((flag)?",%d":"%d"),ptr->data);
				ptr = ptr->next;
				flag = 1;
			}
			printf("]\n");
		}
};
int main(){
	List s;
	printf("Create List ...\n");
	s.display();
	int key=0;
	while(key != 6)
	{
		printf("----------------------------------------\n{Menu of Function}\n\n0:insertHead(data)\n1:insertEnd(data)\n2:insert(index,data)\n3:delNode(index)\n4:delData(data)\n5:search(data)\n6:Exit\n----------------------------------------\n");
		printf("Please Select Function (0~6):");
		std::cin>>key;
		system("cls");
		s.display();
		int a,b;
		switch(key)
		{
			case 0:
				printf("Enter parameter of insertHead(data):");
				std::cin>>a;
				s.insertHead(a);
				break;
			case 1:
				printf("Enter parameter of insertEnd(data):");
				std::cin>>a;
				s.insertEnd(a);
				break;
			case 2:
				printf("Enter parameter of insert(index,data):");
				std::cin>>a>>b;
				s.insert(a,b);
				break;
			case 3:
				printf("Enter parameter of delNode(index):");
				std::cin>>a;
				if(s.delNode(a))
				{
					printf("Error! node is no exist\n");
					system("pause");
				}
				break;
			case 4:
				printf("Enter parameter of delData(data):");
				std::cin>>a;
				if(s.delData(a))
				{
					printf("Error! data is no exist\n");
					system("pause");
				}
				break;
			case 5:
				printf("Enter parameter of search(data):");
				std::cin>>a;
				int result = s.search(a);
				if(result<0)printf("Error! data is no exist\n");
				else printf("Find it at index:%d\n",result);
				system("pause");
				break;
		}
		system("cls");
		s.display();
	}
	printf("The End");
} 
