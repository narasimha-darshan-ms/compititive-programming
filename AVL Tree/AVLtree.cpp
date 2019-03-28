#include<iostream>
using namespace std; 
struct AVLtree 
{ 
	int data; 
	struct AVLtree *left; 
	struct AVLtree *right; 
	int balance; 
}; 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
struct AVLtree* newAVLtree(int data) 
{ 
	struct AVLtree* root = (struct AVLtree*) malloc(sizeof(struct AVLtree)); 
	root->data = data; 
	root->left = NULL; 
	root->right = NULL; 
	root->balance = 0;  
	return(root); 
} 

int getHeight(struct AVLtree *root){
	int leftHeight=0,rightHeight=0;
	if(root == NULL)
		return 0;
	else{
		leftHeight = getHeight(root->left);
		rightHeight = getHeight(root->right);
		return(1 + max(leftHeight , rightHeight));
	}

}


int getBalance(struct AVLtree *N) 
{ 
	if (N == NULL) 
		return 0; 
	return getHeight(N->left) - getHeight(N->right); 
} 

struct AVLtree* rightRotate(struct AVLtree *y) 
{ 
	struct AVLtree *x = y->left; 
	struct AVLtree *T2 = x->right;  
	x->right = y; 
	y->left = T2; 
	y->balance = getBalance(y); 
	x->balance = getBalance(x);  
	return x; 
} 
 
struct AVLtree* leftRotate(struct AVLtree *x) 
{ 
	struct AVLtree *y = x->right; 
	struct AVLtree *T2 = y->left;  
	y->left = x; 
	x->right = T2; 
	x->balance = getBalance(x); 
	y->balance = getBalance(y);  
	return y; 
} 


struct AVLtree* insert(struct AVLtree* root, int data) 
{ 
	if (root == NULL) 
		return(newAVLtree(data)); 

	if (data < root->data) 
		root->left = insert(root->left, data); 
	else if (data > root->data) 
		root->right = insert(root->right, data); 
	else  
		return root; 
	//root->height = 1 + max(height(root->left), height(root->right)); 
	root->balance =getBalance(root); 
	//int balance = getBalance(root);  
	if (root->balance > 1 && data < root->left->data) 
		return rightRotate(root); 
	if (root->balance < -1 && data > root->right->data) 
		return leftRotate(root); 
	if (root->balance > 1 && data > root->left->data) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	}  
	if (root->balance < -1 && data < root->right->data) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 
	return root; 
} 
void preOrder(struct AVLtree *root) 
{ 
	if(root != NULL) 
	{ 
       if(root->left !=NULL){cout<<root->data<<"->"<<root->left->data<<endl; preOrder(root->left);}
        if(root->right != NULL){cout<<root->data<<"->"<<root->right->data<<endl; preOrder(root->right);} 
	} 
} 
void deleteTree(struct AVLtree* root){
    if(root==NULL)  return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int main() 
{ 
struct AVLtree *root = NULL; 
int n,data;
cin>>n;
for(int i=0;i<n;i++){
	cin>>data;
	root = insert(root, data);
} 
preOrder(root); 
deleteTree(root);
return 0; 
} 
