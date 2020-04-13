
#include <iostream>
#include "AVLTree.cpp"

using namespace std;

int main()
{
	AVLTreeType<int> treeRoot;
	int num;

	cout << "Enters numbers ending with -999" << endl;
	cin >> num;
	while (num != -999)
	{
		treeRoot.insert(num);
		cin >> num;
	}

	cout << endl << "Tree nodes in inorder\n";
	treeRoot.inorderTraversal();

	cout << endl;
	cout << endl << "Tree nodes in preorder\n";
	treeRoot.preorderTraversal();
	cout << endl;

	return 0;
}