#include <iostream>

using namespace std;  

// Node class for the linked list
class Node {     //建立名為Node的類型
public:          //宣告公有變數
    int data;    //宣告data
    Node* next;  //宣告next指標，指向下個節點
    Node* prev;  //宣告prev指標，指向上個節點

    Node(int d) {        //定義Node類型初始化的節點數值成員data
        data = d;        //data數值為d
        next = nullptr;  //下一個節點為空指針
        prev = nullptr;  //上一個節點為空指針
    }
};

// Circularly Doubly Linked List class
class CircularDoublyLinkedList {  //定義名為CircularDoublyLinkedList的類型
private:                          //宣告私有變數
    Node* head;                   //宣告head指標指向第一個節點
    Node* tail;                   //宣告tail指標指向最後一個節點

public:                           //宣告公有變數
    CircularDoublyLinkedList() {  //定義CircularDoublyLinkedList類型初始化的節點數值成員
        head = nullptr;           //初始化時head指標的成員變數為空指針，頭節點為空 
        tail = nullptr;           //初始化時tail指標的成員變數為空指針，尾節點為空 
    }

    // Insert a new node at the end of the linked list
    void insert(int data) {              //定義insert函式，初始化參數為data
        Node* new_node = new Node(data); //建立新節點，成員為data 

        if (head == nullptr) {           //判斷頭節點為空 
            head = new_node;             //頭節點為new_node 
            tail = new_node;             //尾節點為new_node
        } else {                         
            tail->next = new_node;       //尾節點得下個節點為new_node節點 
            new_node->prev = tail;       //new_node節點前個節點為尾節點 
            tail = new_node;             //尾節點為new_node 
        }
                                         
        tail->next = head;               //尾節點下個節點為頭節點
        head->prev = tail;               //頭節點前個節點為尾節點
    }

    // Traverse and print the linked list
    void print() {                                      //宣告print函式 
        if (head == nullptr) {                          //判斷頭節點為空 
            cout << "Empty list" << endl;               //輸出Empty list  
        } else {
            Node* current = head;                       //建立current指標為頭節點 
            cout << "Circularly Doubly Linked List: ";  //輸出Circularly Doubly Linked List: 
            do {                                        //在while迴圈執行前重複執行 
                cout << current->data << " ";           //輸出current節點的data數值 
                current = current->next;                //current的下個節點為current
            } while (current != head);                  //當current不為頭節點 
            cout << endl;                               //換行 
        }
    }
};

// Main function to test the Circularly Doubly Linked List
int main() {                                    //主程式
    CircularDoublyLinkedList list;              //宣告名為list的CircularDoublyLinkedList

    // Insert some nodes into the linked list
    list.insert(10);                            //在串列插入值為10的節點
    list.insert(20);                            //在串列插入值為20的節點
    list.insert(30);                            //在串列插入值為30的節點 

    // Print the linked list
    list.print();                               //呼叫print函式，將節點數值印出 

    return 0;                                   //回傳0 
}


