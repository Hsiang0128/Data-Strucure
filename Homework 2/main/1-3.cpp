#include <iostream>
template <typename T>   //宣告一個模版資料型態命名命名為T
class Node {            //宣告Node型態
public:
    T data;             //資料內容其資料型態宣告為T
    Node* next;         //下一個Node的位址
};
template <typename T>   //宣告一個模版資料型態命名命名為T
class LinkedList {
private:
    Node<T>* head;      //宣告head為List開頭位址
public:
    LinkedList() : head(nullptr) {}     //LinkedList的建構式並初始化head為nullptr

    void pushFront(T value) {
        Node<T>* newNode = new Node<T>; //新建立一個Node節點命名為newNode
        newNode->data = value;          //將newNode中的data設為value
        newNode->next = head;           //將newNode中的next設為head
        head = newNode;                 //將head用newNode取代
    }

    void pushBack(T value) {
        Node<T>* newNode = new Node<T>;     //新建立一個Node節點命名為newNode
        newNode->data = value;              //將newNode中的data設為value
        newNode->next = nullptr;            //將newNode中的next設為空指標

        if (head == nullptr) {              //如果head為空的將newNode設為head
            head = newNode;
        } else {
            Node* temp = head;              //宣告一個Node指標命名為temp並初始化設定為head
            while (temp->next != nullptr) { //將temp 設定為temp中的next直到temp中的next為空指標則跳出
                temp = temp->next;
            }                               //此時temp為目前LinkList的結尾
            temp->next = newNode;           //將目前結尾中的next設定為newNode使其變成新的結尾
        }
    }

    void deleteValue(T value) {
        if (head == nullptr) return;    //若head為空指標則跳出

        if (head->data == value) {      //若head中的data為value
            Node<T>* temp = head;       //宣告一個Node指標命名為temp並初始化設定為head
            head = head->next;          //將head設為head中的next
            delete temp;                //刪掉temp位址的Node
            return;
        }

        Node<T>* current = head;                                //宣告一個Node指標命名為current並初始化設定為head
        Node<T>* previous = nullptr;                            //宣告一個Node指標命名為previous並初始化設定為nullptr
        while (current != nullptr && current->data != value) {  //若current不為空指標且current中的data不為value則執行以下動作否則跳出
            previous = current;                                 //設定previous為current
            current = current->next;                            //設定current為current中的next
        }

        if (current != nullptr) {                               //若current不為空指標
            previous->next = current->next;                     //pervious中的next設為current中的next
            delete current;                                     //刪除current位址中的Node
        }
    }

    void display() {
        Node<T>* temp = head;                   //宣告Node指標為temp並初始化為head
        while (temp != nullptr) {               //若temp為空指標則跳出迴圈
            std::cout << temp->data << " -> ";  //輸出temp中的data並以->間隔
            temp = temp->next;                  //設定temp為temp中的next
        }
        std::cout << "nullptr" << std::endl;    //print出nullptr字串
    }

    ~LinkedList() {                 //LinkedList的解構式
        Node<T>* temp;              //宣告Node指標名為temp
        while (head != nullptr) {   //若temp為空指標則跳出迴圈
            temp = head;            //設定temp為head;
            head = head->next;      //設定head為head中的next
            delete temp;            //刪除temp位址的Node
        }
    }
};

int main() {
    LinkedList<int> list;//宣告LinkList名為list並將int資料型態傳入其中

    // Push front
    list.pushFront(3);//在list中的開頭Push value為3的Node
    list.pushFront(2);//在list中的開頭Push value為2的Node
    list.pushFront(1);//在list中的開頭Push value為1的Node

    std::cout << "Push front: ";
    list.display();//print出目前list中的內容

    // Push back
    list.pushBack(4);//在list中的結尾Push value為4的Node
    list.pushBack(5);//在list中的結尾Push value為5的Node
    list.pushBack(6);//在list中的結尾Push value為6的Node

    std::cout << "Push back: ";
    list.display();//print出目前list中的內容

    // Delete value
    list.deleteValue(1);//刪除list中value為1的Node
    list.deleteValue(4);//刪除list中value為4的Node
    list.deleteValue(6);//刪除list中value為6的Node

    std::cout << "Delete values (1, 4, 6): ";
    list.display();//print出目前list中的內容

    return 0;
}
