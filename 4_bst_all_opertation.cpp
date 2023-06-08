/*
Beginning with an empty binary search tree. Construct a binary search tree by inserting the values in the order given. After constructing a binary tree -
1 - insert new node
2 - Find number of nodes in longest path from root - basically just height
3 - Minimum data value found in the tree
4 - Change a tree so that the roles of the left and right pointers are swapped at every node
5 - Search a value (with recursion)
*/

#include <iostream>
using namespace std;
#define SPACE 10;

class TreeNode
{
public:
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}

	TreeNode(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	TreeNode *root;
	int lheight = 0, rheight = 0;

	BST()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		if (root == NULL)
			return true;

		else
			return false;
	}

	void insert(TreeNode *newNode)
	{
		if (root == NULL)
		{
			root = newNode;
			cout << "Value Inserted at Root" << endl;
		}
		else
		{
			TreeNode *temp = root;
			while (temp != NULL)
			{
				if (newNode->value == temp->value)
				{
					cout << "value already exist, Insert another value" << endl;
					return;
				}
				else if ((newNode->value < temp->value) && (temp->left == NULL))
				{
					temp->left = newNode;
					cout << "value inserted(left)" << endl;
					break;
				}
				else if (newNode->value < temp->value)
				{
					temp = temp->left;
				}

				else if ((newNode->value > temp->value) && (temp->right == NULL))
				{
					temp->right = newNode;
					cout << "value inserted(right)" << endl;
					break;
				}
				else if (newNode->value > temp->value)
				{
					temp = temp->right;
				}
			}
		}
	}

	int height(TreeNode *heightNode)
	{
		if (heightNode == NULL)
		{
			return -1;
		}
		else
		{
			lheight = height(heightNode->left);
			rheight = height(heightNode->right);
			if (lheight > rheight)
			{
				return lheight + 1;
			}
			else
				return rheight + 1;
		}
	}

	int minimum_val()
	{

		TreeNode *temp = root;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return (temp->value);
	}

	void swap(TreeNode *node)
	{
		if (node == NULL)
			return;
		else
		{
			// swap left and right pointers of the node
			TreeNode *temp = node->left;
			node->left = node->right;
			node->right = temp;

			// call swap recursively on the left and right children
			swap(node->left);
			swap(node->right);
		}
	}

	void print2D(TreeNode *r, int space)
	{
		int i;
		if (r == NULL)
			return;
		space += SPACE;
		print2D(r->right, space);
		cout << endl;
		for (i = 10; i < space; i++)
			cout << " ";
		cout << r->value << "\n";
		print2D(r->left, space);
	}

	TreeNode *recursiveSearch(TreeNode *r, int val)
	{
		if (r == NULL || r->value == val)
			return r;

		else if (val < r->value)
			return recursiveSearch(r->left, val);

		else
			return recursiveSearch(r->right, val);
	}
};

int main()
{
	int ch, val, searched_val;
	int a;
	BST B;

	do
	{
		cout << "Select the operation you want to perform" << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Display" << endl;
		cout << "3. Minimum Data Value" << endl;
		cout << "4. Number of nodes in the longest branch" << endl;
		cout << "5. Swap" << endl;
		cout << "6. Search Recursive " << endl;
		cout << "7. Clear Screen" << endl;
		cout << "0. Exit Program" << endl;

		cin >> ch;

		switch (ch)
		{
		case 0:
			cout << "Exiting Program" << endl;
			break;

		case 1:
			do
			{
				TreeNode *newNode = new TreeNode();
				cout << "Enter the value of tree node to insert in BST (enter -1 to stop entering) :- " << endl;
				cin >> val;
				if (val != -1)
				{
					newNode->value = val;
					B.insert(newNode);
					cout << endl;
				}
			} while (val != -1);
			break;

		case 2:
			cout << "BST :" << endl;
			B.print2D(B.root, 5);
			cout << endl;
			break;

		case 3:
			a = B.minimum_val();
			cout << "The minimum data value in the tree is : " << a << endl;
			break;

		case 4:
			int height;
			height = B.height(B.root);
			cout << "Number of nodes in the longest branch is" << height + 1 << endl;
			break;
			break;

		case 5:
			B.swap(B.root);
			cout << "BST after swapping:" << endl;
			B.print2D(B.root, 5);
			cout << endl;
			break;

		case 6:
			TreeNode *return_s;
			cout << "Enter the value to be searched :" << endl;
			cin >> searched_val;
			return_s = B.recursiveSearch(B.root, searched_val);
			if (return_s != NULL)
			{

				cout << "The Searched Value is " << return_s->value << endl;
				if (return_s->left != NULL)
					cout << "left node - :" << return_s->left->value << endl;

				if (return_s->right != NULL)
					cout << "right node - :" << return_s->right->value << endl;
			}
			else
			{
				cout << "Searched Value is not present in the tree" << endl;
			}
			break;

		case 7:
			system("clear");
			break;

		default:
			cout << "Invalid Option" << endl;
			break;
		}

	} while (ch != 0);

	return 0;
}