
#include <iostream>
#include "AVLTree.h"

using namespace std;

template <class elemT>
AVLNode<elemT>::AVLNode(const elemT& newItem)
{
	info = newItem;
	left = NULL;
	right = NULL;
}
template<class elemT>
void AVLTreeType<elemT>::insert(const elemT& newItem)
{
	insertIntoAVL(root, newItem); //Access private function
}
template<class elemT>
void AVLTreeType<elemT>::insertIntoAVL(AVLNode<elemT>*& root, const elemT& newItem) {
	if (root == NULL) //If empty tree
	{
		AVLNode<elemT>* newNode = new AVLNode<elemT>(newItem);
		root = newNode;
	}
	else if (newItem <= root->info) //If value is less than or equal to root value then it goes to left subtree
	{
		if (root->left != NULL) //Recurse if left child is not null
		{
			insertIntoAVL(root->left, newItem);
		}
		else //Otherwise, make a new node
		{
			AVLNode<elemT>* newNode = new AVLNode<elemT>(newItem);
			root->left = newNode;
		}
	}
	else if (newItem > root->info)//If value is greater than root value then it goes to right subtree
	{
		if (root->right != NULL) //Recurse if right child is not null
		{
			insertIntoAVL(root->right, newItem);
		}
		else //Otherwise, make a new node
		{
			AVLNode<elemT>* newNode = new AVLNode<elemT>(newItem);
			root->right = newNode;
		}
	}
	checkBalance(root, newItem); //Check to see if balance is needed for AVL Tree
}
template<class elemT>
void AVLTreeType<elemT> ::rotateToLeft(AVLNode<elemT>*& root) {
	AVLNode<elemT>* temp = root->right; //Temp = grandparents right child
	root->right = temp->left; // Grandparents right child = temp left child
	temp->left = root; // temp left child = grandparent
	root = temp; //new grandparent is temp

}
template<class elemT>
void AVLTreeType<elemT> ::rotateToRight(AVLNode<elemT>*& root) {
	AVLNode<elemT>* temp = root->left; //Temp = grandparents left  child
	root->left = temp->right; // Grandparents left child = temp right child
	temp->right = root; // temp right child = grandparent
	root = temp; //new grandparent is temp
}
template<class elemT>
int AVLTreeType<elemT>::height(AVLNode<elemT>* t) //calculate the height of the tree
{
	if (t == NULL) //If we hit a NULL then we return 0
	{
		return 0;
	}
	return (height(t->left), height(t->right)) + 1; //We return height so left and right functions get added by +1 
}
template<class elemT>
void AVLTreeType<elemT> ::balanceFromLeft(AVLNode<elemT>*& root, const elemT& newItem) { //Balance the left subtree
	if (newItem < root->left->info) //Check if new value is less than left child value
	{
		rotateToRight(root); //Rotate grandparent right
	}
	else if (newItem > root->left->info) //Check if new value is greater than left child value
	{
		rotateToLeft(root->left); //Rotate parent left
		rotateToRight(root); //Rotate grandparent right
	}
}
template<class elemT>
void AVLTreeType<elemT> ::balanceFromRight(AVLNode<elemT>*& root, const elemT& newItem) { //Balance the right subtree
	if (newItem > root->right->info) //Check if new value is greater than right child value
	{
		rotateToLeft(root); //Rotate grandparent left
	}
	else if (newItem < root->right->info) //Check if new value is less than right child value
	{
		rotateToRight(root->right); //Rotate parent right
		rotateToLeft(root); //Rotate grandparent left
	}
}
template<class elemT>
void AVLTreeType<elemT> ::checkBalance(AVLNode<elemT>*& root, const elemT& newItem)
{
	if ((height(root->left) - height(root->right)) > 1) //Check if height difference for left subtree is greater than 1 causing an imbalance
	{
		balanceFromLeft(root, newItem); //Rebalance left subtree
	}


	if ((height(root->right) - height(root->left)) > 1)//Check if height difference for right subtree is greater than 1 causing an imbalance
	{
		balanceFromRight(root, newItem); //Rebalance right subtree
	}
}


template<class elemT>
void AVLTreeType<elemT>::inorderTraversal() {
	inorder(root); //Access private function
}
template<class elemT>
void AVLTreeType<elemT>::preorderTraversal() {
	preorder(root); //Access private function
}

template<class elemT>
AVLTreeType<elemT>::AVLTreeType() //default constructor
{
	root = NULL; //Empty list
}

template<class elemT>
void AVLTreeType<elemT>::inorder(AVLNode<elemT>* p) {
	if (p == NULL) //Base case for recursion, return on NULL tree
	{
		return;
	}
	else { //Otherwise,
		if (p->left != NULL) //If left subtree is not NULL
		{
			inorder(p->left); //Call function again with tree->left as parameter
		}
		cout << p->info << " "; //Print out the value in tree
		if (p->right != NULL) //If right subtree is not NULL
		{
			inorder(p->right);//Call function again with tree->right as parameter
		}
	}
}

template<class elemT>
void AVLTreeType<elemT> ::preorder(AVLNode<elemT>* p) {
	if (p == NULL) //Base case for recursion, return on NULL tree
	{
		return;
	}
	else { //Otherwise,

		cout << p->info << " "; //Print out the value in tree
		if (p->left != NULL) //If left subtree is not NULL
		{
			preorder(p->left); //Call function again with tree->left as parameter
		}
		if (p->right != NULL) //If right subtree is not NULL
		{
			preorder(p->right);//Call function again with tree->right as parameter
		}
	}

}