#include <iostream>
using namespace std;
class Node {    //宣告Node型態
public:
    int data;   //資料內容
    Node* next; //下一個Node的位址
};
class LinkedList {
public:
    LinkedList() {	        //LinkedList的建構式
        head = nullptr;     //初始化head為nullptr
    }
    void add(int value) {	            //添加新的Node到LinkedList中
        Node* new_node = new Node();    //產生一個新Node位址是new_node
        new_node->data = value;         //透過new_node位址初始化新Node的data為value
        new_node->next = nullptr;       //透過new_node位址初始化新Node的next為nullptr

        if (head == nullptr) {                  //若LinkedList還是空的把新的Node設定為開頭head
            head = new_node;
        } 
		else {                                  //否則
            Node* current = head;               //宣告位址current來表示當前執行到的list位置
            while (current->next != nullptr) {  //檢查當前的Node的next是否為空，若為空則代已表找到List最後一位了並跳出迴圈
                current = current->next;        //把當前的Node位址設位當前Node的next的位址
            }
            current->next = new_node;           //在當前List結尾的next添加剛剛宣告的new_node
        }
    }

    void display() {                        //print出list中所有Node的Data
        Node* current = head;               //宣告位址current來表示當前執行到的list位置
        while (current != nullptr) {        //一直檢查當前的Node的next是否為空，若為空則代已表找到List最後一位了並跳出迴圈
            cout << current->data << " ";   //print出當前Node的data並用空白分隔
            current = current->next;        //把當前的Node位址設位當前Node的next的位址
        }
        cout << endl;                       //換行
    }

private:
    Node* head; //宣告head為List開頭位址
};

int main() {
    LinkedList list;//宣告一個LinkedList名稱為list

    list.add(1);//List中添加一個data為1的Node
    list.add(2);//List中添加一個data為2的Node
    list.add(3);//List中添加一個data為3的Node

    list.display();//print出lsit中所有Node的data

    return 0;
}
