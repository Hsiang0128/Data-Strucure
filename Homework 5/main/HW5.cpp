#include <iostream>
#include <string.h>
using namespace std;
class TreeInfo
{
	private:
		typedef struct Data
		{
			int value;
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
		void insert(int value,int deep)
		{
			Data *newData = new Data;
			newData->value = value;
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
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    void walk(TreeNode *nowNode,int deep,TreeInfo *v)
    {
        if(nowNode != nullptr)
        {
            v->insert(nowNode->value,deep);
            walk(nowNode->right,deep+1,v);
            walk(nowNode->left,deep+1,v);
        }
    }
    TreeNode *generate(TreeNode *now,int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if(now == nullptr)return newNode;
        else
        { 
            if(now->value > val)
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
    string postfix(TreeNode *nowNode)
    {
        if(nowNode == nullptr)return "";
        string left = postfix(nowNode->left);
        string right = postfix(nowNode->right);
        return (left + right +std::to_string(nowNode->value)+ " " );
    }
    string prefix(TreeNode *nowNode)
    {
        if(nowNode == nullptr)return "";
        string left = prefix(nowNode->left);
        string right = prefix(nowNode->right);
        return (std::to_string(nowNode->value)+" "+ left + right);
    }
    string infix(TreeNode *nowNode)
    {
        if(nowNode == nullptr)return "";
        string left = infix(nowNode->left);
        string right = infix(nowNode->right);
        return (left+std::to_string(nowNode->value)+" "+ right);
    }
public:
    TreeNode* root;
    BinaryTree() {
        root = nullptr;
    }
    void push(int val)
    {
        TreeNode *newNode = generate(root,val);
        if(root == nullptr)root = newNode;
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
            cout<<v.getData(i).value<<endl;
        }
    }
    void print_postfix()
    {
        std::cout<<"Postfix: "<<this->postfix(this->root)<<std::endl;
    }
    void print_prefix()
    {
        std::cout<<"Prefix: "<<this->prefix(this->root)<<std::endl;
    }
    void print_infix()
    {
        std::cout<<"Infix: "<<this->infix(this->root)<<std::endl;
    }
};
int main() {
    BinaryTree tree;
    int num[]={7,4,1,5,16,8,11,12,15,9,2};
    for(int i=0;i<(sizeof(num)/sizeof(*num));i++)tree.push(num[i]);
    cout<<"---------------------------Tree Map---------------------------"<<endl;
    tree.print();
    cout<<"--------------------------------------------------------------"<<endl;
    tree.print_postfix();
    tree.print_prefix();
    tree.print_infix();
	system("pause");
    return 0;
}

