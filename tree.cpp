#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *left;
    tree *right;
};

struct tree* CreateTree(int d){
    struct tree *temp=0;
    temp=(struct tree *)malloc(sizeof(struct tree *));
    temp->data=d;temp->left=0;temp->right=0;
    return temp;
}
struct tree* CreateNode(struct tree *temp,int d){
    temp=(struct tree*)malloc(sizeof(struct tree*));
    temp->data=d;temp->left=0;temp->right=0;
}/*
struct tree* CreateRightNode(struct tree *temp,int d){
    temp->right=(struct tree*)malloc(sizeof(struct tree*));
    temp->right->data=d;temp->left->left=0;temp->left->right=0;
}*/
void printPostorder(struct tree* temp) 
{ 
    if (temp == NULL) 
        return; 
    printPostorder(temp->left); 
    printPostorder(temp->right); 
    cout << temp->data << " "; 
} 
void printInorder(struct tree* temp) 
{ 
    if (temp == NULL) 
        return; 
    printInorder(temp->left); 
    cout << temp->data << " "; 
    printInorder(temp->right); 
} 
void printPreorder(struct tree* temp) 
{ 
    if (temp == NULL) 
        return; 
    cout << temp->data << " "; 
    printPreorder(temp->left);  
    printPreorder(temp->right); 
}  
void deleteTree(struct tree* temp){
    if(!temp)   return;
    deleteTree(temp->left);
    deleteTree(temp->right);
    free(temp);
}
int main(){
    struct tree *root=CreateTree(1);
    root->left=CreateNode(root,2);
    root->right=CreateNode(root,3);
    root->left->left=CreateNode(root,4);
    root->left->right=CreateNode(root,5);
    root->right->left=CreateNode(root,6);
    root->right->right=CreateNode(root,7);
    printPreorder(root);cout<<"\n";
    printInorder(root);cout<<"\n";
    printPostorder(root);cout<<"\n";
    deleteTree(root);
    return 0;
}