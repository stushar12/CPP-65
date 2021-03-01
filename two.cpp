#include<iostream>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted is lesser, insert in left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert in right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

int maximum_in_bst(Node* root)
{
    if(root==NULL)
    return INT32_MIN;

    else
    {
        return max(root->data,max(maximum_in_bst(root->left),maximum_in_bst(root->right)));
    }
}

int minimum_in_bst(Node* root)
{
    if(root==NULL)
    return INT32_MAX;

    else
    {
        return min(root->data,min(minimum_in_bst(root->left),minimum_in_bst(root->right)));
    }
}



int main() 
{
	Node* root = NULL;  // Creating an empty tree

	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

    cout<<"Maximum in BST: "<<maximum_in_bst(root)<<endl;
    cout<<"Minimum in BST: "<<minimum_in_bst(root)<<endl;
}
