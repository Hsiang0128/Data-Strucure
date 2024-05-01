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
    std::string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string value) {
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
    double evaluate(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return std::stod(node->value);
        }

        double leftVal = evaluate(node->left);
        double rightVal = evaluate(node->right);
        if (node->value == "+") {
            return leftVal + rightVal;
        }
        else if (node->value == "-") {
            return leftVal - rightVal;
        }
        else if (node->value == "*") {
            return leftVal * rightVal;
        }
        else if (node->value == "%") {
            return (int)leftVal % (int)rightVal;
        }
        else {
            return leftVal / rightVal;
        }
    }
    string postfix(TreeNode *nowNode)
    {
        if(nowNode == nullptr)return "";
        string left = postfix(nowNode->left);
        string right = postfix(nowNode->right);
        return (left + right + nowNode->value);
    }
    string prefix(TreeNode *nowNode)
    {
        if(nowNode == nullptr)return "";
        string left = prefix(nowNode->left);
        string right = prefix(nowNode->right);
        return (nowNode->value + left + right);
    }
};

int main() {
    BinaryTree a_tree,b_tree;
    TreeNode* a_node1 = new TreeNode("6");
    TreeNode* a_node2 = new TreeNode("3");
    TreeNode* a_node3 = new TreeNode("*");
    TreeNode* a_node4 = new TreeNode("9");
    TreeNode* a_node5 = new TreeNode("5");
    TreeNode* a_node6 = new TreeNode("%");
    TreeNode* a_node7 = new TreeNode("+");
    a_tree.root 	= a_node7;
    a_node7->left 	= a_node3;
    a_node7->right 	= a_node6;
    a_node6->left 	= a_node4;
    a_node6->right 	= a_node5;
    a_node3->left 	= a_node1;
    a_node3->right 	= a_node2;
	TreeNode* b_node1 = 	new TreeNode("1");
    TreeNode* b_node2 = 	new TreeNode("*");
    TreeNode* b_node3 = 	new TreeNode("2");
    TreeNode* b_node4 = 	new TreeNode("+");
    TreeNode* b_node5 = 	new TreeNode("3");
    TreeNode* b_node6 = 	new TreeNode("%");
    TreeNode* b_node7 = 	new TreeNode("2");
	TreeNode* b_node8 = 	new TreeNode("+");
	TreeNode* b_node9 = 	new TreeNode("6");
	TreeNode* b_node10 =	new TreeNode("/");
	TreeNode* b_node11 = 	new TreeNode("3");
	TreeNode* b_node12 = 	new TreeNode("+");
	TreeNode* b_node13 = 	new TreeNode("2");
	TreeNode* b_node14 = 	new TreeNode("*");
	TreeNode* b_node15 = 	new TreeNode("2");
	b_node2->left	= b_node1;
	b_node2->right	= b_node3;
	b_node6->left	= b_node5;
	b_node6->right	= b_node7;
	b_node10->left	= b_node9;
	b_node10->right	= b_node11;
	b_node14->left	= b_node13;
	b_node14->right	= b_node15;
	b_node12->left	= b_node10;
	b_node12->right	= b_node14;
	b_node4->left	= b_node2;
	b_node4->right	= b_node6;
	b_node8->left	= b_node4;
	b_node8->right	= b_node12;
	b_tree.root 	= b_node8;
    cout<<"-----------------------------------------------Tree of A-----------------------------------------------\n";
    a_tree.print();
    cout<<"\nInfix : 6*3+9%5"<<endl;
    cout<<"Prefix : "<<a_tree.prefix(a_tree.root)<<endl;
    cout<<"Postfix : "<<a_tree.postfix(a_tree.root)<<endl;
    std::cout << "The A result of the expression is: " << a_tree.evaluate(a_tree.root) << std::endl;
    cout<<"\n-----------------------------------------------Tree of B-----------------------------------------------\n";
    b_tree.print();
    cout<<"\nInfix : 1*2+3%2+6/3+2*2"<<endl;
    cout<<"Prefix : "<<b_tree.prefix(b_tree.root)<<endl;
    cout<<"Postfix : "<<b_tree.postfix(b_tree.root)<<endl;
	std::cout << "The B result of the expression is: " << b_tree.evaluate(b_tree.root) << std::endl;
	system("pause");
    return 0;
}

