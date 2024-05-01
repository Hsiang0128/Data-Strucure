#include <iostream>
using namespace std;
class TreeInfo
{
	private:
		typedef struct Data
		{
			int val;
			int deep;
			Data *next;
		}Data;
		Data *head;
		int length;
	public:
		TreeInfo()
		{
			this->head = nullptr;
			this->length = 0;
		}
		void insert(int val,int deep)
		{
			Data *newData = new Data;
			newData->val = val;
			newData->deep = deep;
			newData->next = nullptr;
			if(head == nullptr)head = newData;
			else
			{
				Data *tmp = this -> head;
				while(tmp->next != nullptr)tmp = tmp->next;
				tmp->next = newData;
			}
			this->length++;
		}
		int end()
		{
			return this->length;
		}
		Data getData(int index)
		{
			Data *tmp = this -> head;
			for(int i = 0; i <index ; i++)tmp = tmp->next;
			return *tmp;
		}
		bool searchDeep(int index,int deep)
		{
			Data *tmp = this -> head;
			for(int i = 0; i <index ; i++)tmp = tmp->next;
			while(tmp != nullptr)
			{
				if(tmp->deep == deep)return  true;
				else if(tmp->deep <deep)return false;
				tmp = tmp->next;
			}
			return false;
		}
};
class Tree
{
	private:
		typedef struct Node
		{
			int val;
			Node *left;
			Node *right;
		}Node;
		Node *generate(Node *now,int val)
		{
			Node *newNode = new Node;
			newNode->val = val;
			newNode->left= nullptr;
			newNode->right= nullptr;
			if(now == nullptr)return newNode;
			else
			{ 
				if(now->val > val)
				{
					if(now->left == nullptr)
					{
						now->left = newNode;
						return newNode;
					}
					else
					{
						delete newNode;
						return generate(now->left,val);
					}
				} 
				else
				{
					if(now->right == nullptr)
					{
						now->right = newNode;
						return newNode;
					}
					else
					{
						delete newNode;
						return generate(now->right,val);
					}
				}
			} 
		}
		int deepTest(Node *node,int val,int i)
		{
			if(node->val == val)
			{
				return i;
			}
			else if(node->val>val)
			{ 
				if(node->left != nullptr)return deepTest(node->left,val,i+1);
				return -1;
			}
			else
			{
				if(node->right != nullptr)return deepTest(node->right,val,i+1);
				return -1;
			}
		}
		void walk(Node *nowNode,int deep,TreeInfo *v)
		{
			if(nowNode != nullptr)
			{
				v->insert(nowNode->val,deep);
				walk(nowNode->right,deep+1,v);
				walk(nowNode->left,deep+1,v);
			}
		}
	public:
		Node *root;
		Tree(){
			root = nullptr;
		}
		void push(int val)
		{
			Node *newNode = generate(root,val);
			if(root == nullptr)root = newNode;
		}
		bool search(int val)
		{
			int result = deepTest(this->root,val,1);
			if(result == -1)cout<<"Not fond!\n";
			else cout<<"Find it in "<<result<<" times\n";
			return (result != -1);
		}
		void print()//¢z ¢{ ¢| ¢} ¢u ¢w ¢x ¢s
		{
			TreeInfo v;
			this->walk(this->root,0,&v);
			for(int i=0;i<v.end();i++)
			{
				for(int j=0;j<v.getData(i).deep;j++)
				{
					if(v.getData(i).deep-1 == j)cout<<(v.searchDeep(i+1,v.getData(i).deep)?"¢u":"¢|")<<"¢w¢w¢w¢w¢w¢w ";
					else if(v.searchDeep(i,j+1))cout<<"¢x\t";
					else cout<<"\t";
				}
				cout<<v.getData(i).val<<endl;
			}
		}
};
int main()
{
	int num[]={7,1,4,2,8,13,12,11,15,9,5};
	int val;
	Tree tree;
	for(int i=0;i<(sizeof(num)/sizeof(*num));i++)tree.push(num[i]);
	cout<<"\n------------------------ Current ------------------------\n";
	tree.print();
	cout<<"\n---------------------------------------------------------\n";
	cout<<"Enter value you want find:";
	cin>>val;
	if(!tree.search(val))
	{
		cout<<"Inserting........";
		tree.push(val);
		cout<<"\n------------------------- After -------------------------\n";
		tree.print();
	}
	system("pause");
	return 0;
} 
