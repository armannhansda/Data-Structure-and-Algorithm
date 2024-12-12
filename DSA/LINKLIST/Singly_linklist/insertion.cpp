#include<iostream>
using namespace std;

//implemetation
class Node{
  public:
  int data;
  Node* next;

  //constructor
  Node(int data ){
    this->data = data;
    this->next = NULL;
  }
};

// insert at start
void insertAtHead(Node* &head, int data){
  //create new temp node
  Node* temp = new Node(data);
  temp -> next = head;
  head = temp;
}

//insert at end
void insertAtTail(Node* &tail, int data){
  //create new node
  Node* temp = new Node(data);
  tail->next = temp;
  tail= tail->next;

}

//insert at middle
void insertAtposition(Node* &tail, Node* &head, int position , int data){

// condition for insert at start
  if(position==1){
    insertAtHead(head, data);
    return;
  }

  
  Node* temp = head;
  int cnt = 1;
  while(cnt < position -1){
    temp = temp->next;
    cnt++;
  }
  //create new node
  Node* nodetoinsert = new Node(data);
  nodetoinsert->next = temp->next;
  temp->next = nodetoinsert;

//condition for insert at end
  if(temp->next == NULL){
    insertAtTail(tail, data);
    return;
  }
}
//traverse
void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;

}


int main(){
  //create a new node
  Node* node1 = new Node(10);
  cout<<node1->data<<endl;

  // head & tail pointed to node1
  Node* head = node1;
  Node* tail = node1;
  
  // insertAtStart(head, 20);
  // print(head);

  // insertAtStart(head, 30);
  // print(head);

  insertAtTail(tail, 20);
  insertAtTail(tail, 30);
  print(head);
  insertAtposition(tail, head, 3, 40);
  print(head);
  

  return 0;
}