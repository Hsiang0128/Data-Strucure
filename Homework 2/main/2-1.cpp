#include <iostream>

using namespace std;

class Node {    //建立名為Node類型 
public:         //宣告公有變數 
    int data;   //宣告data 
    Node* prev; //宣告prev指標，指向上個節點
    Node* next; //宣告next指標，指向下個節點
};

class LinkedList {        //建立名為LinkedList的類型 
public:				      //宣告公有變數 
    LinkedList() {		  //定義LinkedList函式
        head = nullptr;	  //頭節點為空 
        tail = nullptr;	  //尾節點為空 
    }

    void add(int value) {             //定義add函式，初始化參數為value 
        Node* new_node = new Node();  //新增Node指標，名為new_node 
        new_node->data = value;       //new_node成員變數為value 
        new_node->prev = nullptr;     //new_node上個節點為空 
        new_node->next = nullptr;     //new_node下個節點為空 

        if (head == nullptr) {     //判斷頭節點為空 
            head = new_node;       //頭節點為new_node
            tail = new_node;       //尾節點為new_node
        } else {  
            tail->next = new_node; //尾節點下個節點為new_node 
            new_node->prev = tail; //new_node前個節點為尾節點 
            tail = new_node;	   //尾節點為new_node 
        }
    }

    void display() {                      //宣告display函式 
        Node* current = head;             //建立current節點為頭節點 
        while (current != nullptr) {      //當current不為空 
            cout << current->data << " "; //輸出current節點的data數值
            current = current->next;      //current的下個節點為current
        }
        cout << endl;                     //換行 
    }

private:        //宣告私有變數 
    Node* head; //建立頭節點 
    Node* tail; //建立尾節點 
};

int main() {         //主程式 
    LinkedList list; //宣告名為LinkedList的串列 

    list.add(1);     //在串列中新增數值為1的節點
    list.add(2);     //在串列中新增數值為2的節點
    list.add(3);     //在串列中新增數值為3的節點 

    list.display();  //呼叫display函式 

    return 0;        //回傳0 
}

