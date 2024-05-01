#include <iostream>

template <typename T>   //宣告一個模版資料型態命名命名為T
struct Node {
    T data;             //資料內容其資料型態宣告為T
    Node* prev;         //上一個Node的位址
    Node* next;         //下一個Node的位址
};

template <typename T>   //宣告一個模版資料型態命名命名為T
class DoublyLinkedList {
private:
    Node<T>* head;      //宣告head為List開頭位址

public:
    DoublyLinkedList() : head(nullptr) {}   //DoublyLinkedList的建構式並初始化head為nullptr

    void pushFront(T value) {
        Node<T>* newNode = new Node<T>;     //新建立一個Node節點命名為newNode
        newNode->data = value;              //將newNode中的data設為value
        newNode->prev = nullptr;            //將newNode中的prev設為空指標
        newNode->next = head;               //將newNode中的next設為head

        if (head != nullptr) {              //若head不等於空指標
            head->prev = newNode;           //head中的prev設為newNode
        }
        head = newNode;                     //將head用newNode取代
    }

    void pushBack(T value) {
        Node<T>* newNode = new Node<T>;     //新建立一個Node節點命名為newNode
        newNode->data = value;              //將newNode中的data設為value
        newNode->next = nullptr;            //將newNode中的next設為空指標

        if (head == nullptr) {              //如果head為空標
            newNode->prev = nullptr;        //將newNode中的prev設為空指標
            head = newNode;                 //將head設為newNode
        } else {
            Node<T>* temp = head;           //宣告一個Node指標命名為temp並初始化設定為head
            while (temp->next != nullptr) { //將temp 設定為temp中的next直到temp中的next為空指標則跳出
                temp = temp->next;
            }                               //此時temp為目前DoublyLinkedList的結尾
            temp->next = newNode;           //將目前結尾中的next設定為newNode使其變成新的結尾
            newNode->prev = temp;           //將newNode中的prev設為temp
        }
    }

    void deleteValue(T value) {
        if (head == nullptr) return;                            //若head為空指標則跳出
        Node<T>* current = head;                                //宣告Node型態指標名為current並初始化為head
        while (current != nullptr && current->data != value) {  //若current不為空指標且current中的data不為value則執行以下動作否則跳出
            current = current->next;                            //設定current為current中的next
        }

        if (current == nullptr) return;                         //若current為空指標則跳函式

        if (current->prev != nullptr) {                         //若current中的prev不為空指標
            current->prev->next = current->next;                //將current中的prev其中的next設為current中的next
        } else {
            head = current->next;                               //將head設為current中的next
        }

        if (current->next != nullptr) {                         //若current中的next不為空指標
            current->next->prev = current->prev;                //將current中的next其中的prev設為current中的prev
        }

        delete current;                                         //刪除current位址中的Node
    }

    void display() {
        Node<T>* temp = head;                   //宣告Node指標為temp並初始化為head
        while (temp != nullptr) {               //若temp為空指標則跳出迴圈
            std::cout << temp->data << " <-> "; //輸出temp中的data並以<->間隔
            temp = temp->next;                  //設定temp為temp中的next
        }
        std::cout << "nullptr" << std::endl;    //print出nullptr字串
    }

    ~DoublyLinkedList() {           //DoublyLinkedList的解構式
        Node<T>* temp;              //宣告Node指標名為temp
        while (head != nullptr) {   //若temp為空指標則跳出迴圈
            temp = head;            //設定temp為head;
            head = head->next;      //設定head為head中的next
            delete temp;            //刪除temp位址的Node
        }
    }
};

int main() {  
    DoublyLinkedList<int> list; //宣告名為list的DoublyLinkedList其引入資料型態int

    // Push front
    list.pushFront(3); //在串列前端插入數值為3的數值的Node
    list.pushFront(2); //在串列前端插入數值為2的數值的Node
    list.pushFront(1); //在串列前端插入數值為1的數值的Node

    std::cout << "Push front: ";
    list.display();//print出目前list中的內容

    // Push back
    list.pushBack(4); //在串列尾端插入數值為4的數值的Node
    list.pushBack(5); //在串列尾端插入數值為5的數值的Node
    list.pushBack(6); //在串列尾端插入數值為6的數值的Node

    std::cout << "Push back: "; 
    list.display();//print出目前list中的內容

    // Delete value
    list.deleteValue(1); //在串列中刪除數值為1的Node
    list.deleteValue(4); //在串列中刪除數值為4的Node
    list.deleteValue(6); //在串列中刪除數值為6的Node

    std::cout << "Delete values (1, 4, 6): ";
    list.display();//print出目前list中的內容

    return 0;  //回傳0
}
