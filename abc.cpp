#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    
    Node (int val){
        data=val;
        next = nullptr;
    }
};


class LinkedList{
    private:
    Node *head;
    Node *temp;
    
    public:
    LinkedList(){
        head=nullptr;
        temp=nullptr;
    }
    
    void insertBeginning(int val){
    Node *newnode = new Node(val);
    
    if (!head){
        head= newnode;
        temp=newnode;
        
    } 
    else{
        newnode->next=head;
        head=newnode;
    }
    }
    
    void insertEnd(int val){
        Node *newnode= new Node(val);
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
    void insertMid(int val, int pos) {
        if (pos <= 1) {
            insertBeginning(val);
            return;
        }
        else {
            Node* newnode = new Node(val);
            temp = head;
            int count = 1; // Start count at 1 for the first node

            while (count < pos - 1 && temp != nullptr) {
                temp = temp->next;
                count++;
            }

            if (temp != nullptr) {
                newnode->next = temp->next;
                temp->next = newnode;
            }
            else {
                insertEnd(val); // If pos is out of bounds, insert at the end
            }
        }
    }
    
    void deleteBeginning(){
        if(head && head->next!=NULL){
            temp=head;
            head=head->next;
            delete(temp);
        }
        else cout <<"Not Possible"<<endl;
    }
    
    
    void display(){
    temp=head;
    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}
};




int main() {
    // Write C++ code here
    LinkedList A;
    A.insertBeginning(10);
    A.insertMid(15,3);
    A.insertEnd(20);
    A.insertEnd(30);
    A.insertEnd(40);
    A.insertEnd(50);
    A.deleteBeginning();
    //A.deleteEnd();
    A.display();
    

    return 0;
}