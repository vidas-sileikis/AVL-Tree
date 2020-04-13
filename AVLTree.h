template <class elemT>
class AVLNode
{
public:
	AVLNode(const elemT& newItem);
	elemT info;
	int bfactor; //balance factor
	AVLNode* left; //left node
	AVLNode* right; //right node
};

template <class elemT>
class AVLTreeType
{
public:
	void insertIntoAVL(AVLNode<elemT>*& root, const elemT& newItem);
	void insert(const elemT& newItem);
	void rotateToLeft(AVLNode<elemT>*& root);
	void rotateToRight(AVLNode<elemT>*& root);
	void balanceFromLeft(AVLNode<elemT>*& root, const elemT& newItem);
	void balanceFromRight(AVLNode<elemT>*& root, const elemT& newItem);
	int height(AVLNode<elemT>* t); //To figure out the height of the tree
	void checkBalance(AVLNode<elemT>*& root, const elemT& newItem);
	void inorderTraversal();
	void preorderTraversal();
	AVLTreeType(); //default constructor

private:
	AVLNode<elemT>* root;

	void inorder(AVLNode<elemT>* p);
	void preorder(AVLNode<elemT>* p);
};