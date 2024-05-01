#include <iostream>
using namespace std;
class TreeInfo
{
	private:
		typedef struct Data
		{
			string value;
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
		void insert(string value,int deep)
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
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }
    void walk(TreeNode *nowNode,int deep,TreeInfo *v)
    {
        if(nowNode != nullptr)
        {
            v->insert(nowNode->value,deep);
            walk(nowNode->right,deep+1,v);
            walk(nowNode->left,deep+1,v);
        }
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
};

int main() {//A/B**C+D*E-A*C
    BinaryTree tree;
    TreeNode* node1 = new TreeNode("A");
    TreeNode* node2 = new TreeNode("/");
    TreeNode* node3 = new TreeNode("B");
    TreeNode* node4 = new TreeNode("**");
    TreeNode* node5 = new TreeNode("C");
    TreeNode* node6 = new TreeNode("+");
    TreeNode* node7 = new TreeNode("D");
    TreeNode* node8 = new TreeNode("*");
    TreeNode* node9 = new TreeNode("E");
    TreeNode* node10 = new TreeNode("-");
    TreeNode* node11 = new TreeNode("A");
    TreeNode* node12 = new TreeNode("*");
    TreeNode* node13 = new TreeNode("C");
    node4->left     = node3;
    node4->right    = node5;
    node2->left     = node1;
    node2->right    = node4;
    node8->left     = node7;
    node8->right    = node9;
    node12->left    = node11;
    node12->right   = node13;
    node10->left    = node8;
    node10->right   = node12;
    node6->left     = node2;
    node6->right    = node10;
    tree.root = node6;
    cout<<"Infix : A/B**C+D*E-A*C"<<endl<<"----------------------------------------"<<endl;
    tree.print();
	system("pause");
    return 0;
}

