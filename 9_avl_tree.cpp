#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for AVL Tree
struct Node
{
    string keyword;
    string meaning;
    int height;
    Node *left;
    Node *right;
};

// AVL Dictionary class
class AVLDictionary
{
private:
    Node *root;

public:
    // Constructor
    AVLDictionary()
    {
        root = nullptr;
    }

    // Function to get the height of a node
    int getHeight(Node *node)
    {
        if (node == nullptr)
            return -1;
        return node->height;
    }

    // Function to get the balance factor of a node
    int getBalanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    void displayTree(Node *node, int level)
    {
        if (node == nullptr)
            return;

        displayTree(node->right, level + 1);

        for (int i = 0; i < level; i++)
            cout << "    ";

        cout << node->keyword << ": " << node->meaning << endl;

        displayTree(node->left, level + 1);
    }
    // Function to update the height of a node
    void updateHeight(Node *node)
    {
        if (node == nullptr)
            return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Function to perform left rotation
    Node *leftRotate(Node *node)
    {
        Node *newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Function to perform right rotation
    Node *rightRotate(Node *node)
    {
        Node *newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Function to perform left-right double rotation
    Node *leftRightRotate(Node *node)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Function to perform right-left double rotation
    Node *rightLeftRotate(Node *node)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Function to insert a keyword with its meaning
    Node *insert(Node *node, string keyword, string meaning)
    {
        if (node == nullptr)
        {
            Node *newNode = new Node;
            newNode->keyword = keyword;
            newNode->meaning = meaning;
            newNode->height = 0;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (keyword < node->keyword)
        {
            node->left = insert(node->left, keyword, meaning);
        }
        else if (keyword > node->keyword)
        {
            node->right = insert(node->right, keyword, meaning);
        }
        else
        {
            // Keyword already exists, update the meaning
            node->meaning = meaning;
            return node;
        }

        updateHeight(node);

        // Perform balancing
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1)
        {
            if (keyword < node->left->keyword)
            {
                return rightRotate(node);
            }
            else
            {
                return leftRightRotate(node);
            }
        }
        else if (balanceFactor < -1)
        {
            if (keyword > node->right->keyword)
            {
                return leftRotate(node);
            }
            else
            {
                return rightLeftRotate(node);
            }
        }

        return node;
    }

    // Function to delete a keyword
    Node *remove(Node *node, string keyword)
    {
        if (node == nullptr)
            return nullptr;

        if (keyword < node->keyword)
        {
            node->left = remove(node->left, keyword);
        }
        else if (keyword > node->keyword)
        {
            node->right = remove(node->right, keyword);
        }
        else
        {
            // Found the keyword to delete

            // Case 1: No child or only one child
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                // Case 2: Two children
                Node *successor = getMinimum(node->right);
                node->keyword = successor->keyword;
                node->meaning = successor->meaning;
                node->right = remove(node->right, successor->keyword);
            }
        }

        if (node == nullptr)
            return nullptr;

        updateHeight(node);

        // Perform balancing
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1)
        {
            if (getBalanceFactor(node->left) >= 0)
            {
                return rightRotate(node);
            }
            else
            {
                return leftRightRotate(node);
            }
        }
        else if (balanceFactor < -1)
        {
            if (getBalanceFactor(node->right) <= 0)
            {
                return leftRotate(node);
            }
            else
            {
                return rightLeftRotate(node);
            }
        }

        return node;
    }

    // Function to find the minimum node in a subtree
    Node *getMinimum(Node *node)
    {
        if (node == nullptr || node->left == nullptr)
            return node;
        return getMinimum(node->left);
    }

    // Function to search for a keyword and return its meaning
    string search(Node *node, string keyword, int &comparisons)
    {
        if (node == nullptr)
            return "";

        comparisons++;

        if (keyword < node->keyword)
        {
            return search(node->left, keyword, comparisons);
        }
        else if (keyword > node->keyword)
        {
            return search(node->right, keyword, comparisons);
        }
        else
        {
            return node->meaning;
        }
    }

    // Function to traverse the tree in ascending order and display the data
    void displayAscending(Node *node)
    {
        if (node == nullptr)
            return;

        displayAscending(node->left);
        cout << node->keyword << ": " << node->meaning << endl;
        displayAscending(node->right);
    }

    // Function to traverse the tree in descending order and display the data
    void displayDescending(Node *node)
    {
        if (node == nullptr)
            return;

        displayDescending(node->right);
        cout << node->keyword << ": " << node->meaning << endl;
        displayDescending(node->left);
    }

    // Function to calculate the maximum comparisons required for finding a keyword
    int getMaxComparisons(Node *node, string keyword)
    {
        if (node == nullptr)
            return 0;

        if (keyword < node->keyword)
        {
            return 1 + getMaxComparisons(node->left, keyword);
        }
        else if (keyword > node->keyword)
        {
            return 1 + getMaxComparisons(node->right, keyword);
        }
        else
        {
            return 1;
        }
    }

    // Function to display the menu
    void displayMenu()
    {
        cout << "\nDictionary Operations Menu:\n";
        cout << "1. Add a keyword\n";
        cout << "2. Delete a keyword\n";
        cout << "3. Update the meaning of a keyword\n";
        cout << "4. Display the data in ascending order\n";
        cout << "5. Display the data in descending order\n";
        cout << "6. Find the maximum comparisons for a keyword\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
    }
    // Function to run the dictionary program
    void run()
    {
        int choice;
        string keyword, meaning;
        int comparisons;

        while (true)
        {
            displayMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = insert(root, keyword, meaning);
                cout << "Keyword added successfully.\n";
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = remove(root, keyword);
                cout << "Keyword deleted successfully.\n";
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cout << "Enter new meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = remove(root, keyword);
                root = insert(root, keyword, meaning);
                cout << "Meaning updated successfully.\n";
                break;
            case 4:

                cout << "Data in AVL tree:\n";
                displayTree(root, 0);

                cout << "\n\nData in ascending order:\n";
                displayAscending(root);
                break;
            case 5:
                cout << "Data in descending order:\n";
                displayDescending(root);
                break;
            case 6:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                comparisons = 0;
                meaning = search(root, keyword, comparisons);
                if (meaning != "")
                {
                    cout << "Meaning: " << meaning << endl;
                    cout << "Maximum comparisons required: " << comparisons << endl;
                }
                else
                {
                    cout << "Keyword not found.\n";
                }
                break;
            case 7:
                cout << "Exiting the program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
                break;
            }
        }
    }
};

int main()
{
    AVLDictionary dictionary;
    dictionary.run();
    return 0;
}
