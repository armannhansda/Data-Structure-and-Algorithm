#include<iostream>
#include<queue>

using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

void preorderTraversal(Node* root){ //follows "NLR"
  if(root == NULL){
    return;
  }

  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inordertraversal(Node* root){ // follows "LNR"
    if(root == NULL){
      return;
    }

    inordertraversal(root->left);
    cout <<root->data<<" ";
    inordertraversal(root->right);
}

void postordertraversal(Node* root){
  if (root == NULL){
    return;
  }
  postordertraversal(root->left);
  postordertraversal(root->right);
  cout<<root->data<<" ";
}

void levelOrdertraversal(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

int height(Node* root){
  if(root == NULL){
    return 0;
  }
  int Lheight = height(root->left);
  int Rheight = height(root->right);

  return max(Lheight, Rheight) + 1;
}

void printCurrentLevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void reverseOrdertraversal(Node* root){
    int h = height(root);
    for(int i = h; i >= 1; i--){
        printCurrentLevel(root, i);
        cout << endl;
    }
}

Node* builtTree(Node* root){
  cout << "Enter the data (-1 for NULL): "<<endl;
  int data;
  cin >> data;

  if(data == -1){
    return NULL;
  }
    
  root = new Node(data);

  cout << "Enter the data to insert in left of " << data << endl;
  root->left = builtTree(root->left);
  cout << "Enter the data to insert in right of " << data << endl;
  root->right = builtTree(root->right);
    
  return root;
}

int main(){
  Node* root = NULL;

  cout << "Creating tree..." << endl;
  root = builtTree(root);
  // data-> 1 3 5 -1 -1 -1 2 -1 -1
  
  cout << "\nLevel Order traversal: \n";
  levelOrdertraversal(root);
  
  cout << "\nPreorder traversal: ";
  preorderTraversal(root);
  cout<<endl;
  
  cout << "Inorder traversal: ";
  inordertraversal(root);
  cout<<endl;
  
  cout << "Postorder traversal: ";
  postordertraversal(root);
  cout<<endl;

  cout<<"\nreverse order traversal:\n";
  reverseOrdertraversal(root);

  return 0;
}