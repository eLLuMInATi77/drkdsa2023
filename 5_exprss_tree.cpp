#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class Tree
{
	typedef struct node
	{
		char data[10];
		struct node *left, *right;
	} btree;

public:
	btree *root, *New;
	Tree();
	bool flag = false;
	void create();
	void insert(btree *root, btree *New);
	void display();
	void recursive();
	void rec_postorder(btree *root);
	void nonrecursive();
	void nonrec_postorder(btree *root);
	void deleteTree(btree *root);
	void del();
};

Tree::Tree()
{
	root = NULL;
}

void Tree::recursive()
{
	rec_postorder(root);
}

void Tree::rec_postorder(btree *root)
{
	if (root != NULL)
	{

		rec_postorder(root->left);
		rec_postorder(root->right);
		cout << "\t" << root->data;
	}
}
void Tree::nonrecursive()
{
	nonrec_postorder(root);
}

void Tree::nonrec_postorder(btree *root)
{
	if (!root)
	{
		cout << "\n Tree empty";
		return;
	}
	stack<btree *> s;
	stack<btree *> op;
	s.push(root);
	while (!s.empty())
	{
		btree *curr = s.top();
		op.push(curr);
		s.pop();
		if (curr->left)

			s.push(curr->left);
		if (curr->right)
			s.push(curr->right);
	}

	while (!op.empty())
	{
		cout << op.top()->data << "\t";
		op.pop();
	}
}

void Tree::deleteTree(btree *root)
{
	if (root == NULL)
		return;

	deleteTree(root->left);
	deleteTree(root->right);

	cout << "\n Deleting node: " << root->data;
	delete root;
}

void Tree::del()
{
	deleteTree(root);
	flag = true;
}

void Tree::create()
{

	New = new btree;
	cout << "\n Enter the data which you want :- ";
	cin >> New->data;
	New->left = NULL;
	New->right = NULL;

	if (root == NULL)
	{
		root = New;
	}
	else
	{
		insert(root, New);
	}
}

void Tree::insert(btree *root, btree *New)
{
	char ans;

	cout << "\n\n You wnat to insert " << New->data << " at left or right child of " << root->data << " : ";

	cin >> ans;
	if (ans == 'l' || ans == 'L')
	{
		if (root->left == NULL)
		{
			root->left = New;
		}
		else
		{
			insert(root->left, New);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = New;
		}
		else
		{
			insert(root->right, New);
		}
	}
}

int main()
{

	Tree tr;
	int ch;
	char ans;

	do
	{
		cout << "\n\tExpression Tree ";
		cout << "\n\t1. Create\n\t2. Display\n\t3.cLEAR SCREEN\n\t4. Exit\n\t.....Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			do
			{
				tr.create();
				cout << "\n\t Do You Want to Insert More Elements: ";

				cin >> ans;
			} while (ans == 'y' || ans == 'Y');

			break;

		case 2:
			if (tr.flag == true)
				cout << "\t\t### Tree has no Nodes ###" << endl;
			else
			{
				cout << "\n\t\t*****Display \n\t\t1.Recursive\n\t\t2. Non Recursive";

				cout << "\n\t\t....Enter Your Choice: ";
				cin >> ch;
				switch (ch)
				{
				case 1:
					cout << "\n\tRecursive Postorder Traversal\n";

					tr.recursive();
					break;

				case 2:
					cout << "\n\tNon Recursive Postorder Traversal\n";

					tr.nonrecursive();
					break;
				}
			}
			break;

		case 3:
			tr.del();
			break;

		case 4:
			cout << "That's All";
			return (0);
		}
		cout << "\n\t..... Do You Want to Continue: ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	cout << "Thats all!";
	return (0);
}
