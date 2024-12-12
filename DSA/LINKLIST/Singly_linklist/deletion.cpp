#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  //constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }

  //destructor
  ~Node(){
    int value = this->data;
    //memory free..
    if (this->next != NULL){
      delete next;
      next = NULL;
    }
    cout<<"memory is free for node with data "<< value<<endl;
  }
};

void deletion(Node* & head, int position){
  //deleting first or start
  if (position== 1){
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    //memory free start node
    delete temp;
  }
  else{
    //deleting any middle or last node
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt < position){
      prev= curr;
      curr= curr->next;
      cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }

  //study about how to handle tail position when we delete last node
}

void insertAtHead(Node* &head, int data ){

  Node* temp = new Node(data);
  temp->next = head;
  head= temp;
}

void insertAtTail(Node* &tail, int data){
  Node* temp = new Node(data);
  tail->next = temp;
  tail = tail->next;
}

void insertataPosition(Node* &tail, Node* &head, int position, int data){
  //conditon for inset at start
  if(position==1){
    insertAtHead(head, data);
    return;
  }

  Node* temp = head;
  int cnt = 1;
  while(cnt<position-1){
    temp = temp->next;
    cnt++;
  }

  Node* nodetoinsert = new Node(data);
  nodetoinsert->next = temp->next;
  temp->next = nodetoinsert;

  //condition fro insert at end
  if (temp->next == NULL){
    insertAtTail(tail, data);
    return;
  }

}

void print(Node* &head){

  Node* temp = head;
  while(temp != NULL){
    cout << temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}


int main(){

  Node* node1= new Node(10);

  Node* head = node1;
  Node* tail= node1;

  insertAtHead(head, 20);
  insertAtTail(tail, 30);
  print(head);
  insertataPosition(tail,head,2,40);
  print(head);

  deletion(head, 1);
  print(head);

  return 0;
}