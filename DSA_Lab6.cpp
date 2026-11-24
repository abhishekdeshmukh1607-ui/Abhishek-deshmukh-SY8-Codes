#include <iostream>
using namespace std;

class Node
{
public:
int data;
Node *left, *right;


Node(int value)
{
    data = value;
    left = NULL;
    right = NULL;
}


};

class BST
{
private:
Node *root;


Node* insert(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate value " << value << " is not inserted.\n";

    return root;
}

Node* copyTree(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *newNode = new Node(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

int Height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    return (leftHeight > rightHeight)
               ? leftHeight + 1
               : rightHeight + 1;
}

void displayLeaves(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    displayLeaves(root->left);
    displayLeaves(root->right);
}


public:
BST()
{
root = NULL;
}


void createBST()
{
    int n, value;

    cout << "\nEnter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBST created successfully.\n";
}

// FIX: createNewTree() is now public
BST* createNewTree()
{
    BST *newTree = new BST();
    newTree->root = copyTree(root);
    return newTree;
}

void displayLevelWise()
{
    if (root == NULL)
    {
        cout << "\nTree is empty.\n";
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    cout << "\nLevel-Wise BST:\n";
    
    while (front < rear)
    {
        int nodesAtLevel = rear - front;

        cout << "Level: ";

        for (int i = 0; i < nodesAtLevel; i++)
        {
            Node *current = queue[front++];
            cout << current->data << " ";

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }

        cout << endl;
    }
}

void displayHeight()
{
    cout << "\nHeight of BST = " << Height(root) << endl;
}

void displayLeafNodes()
{
    if (root == NULL)
    {
        cout << "\nTree is empty.\n";
        return;
    }

    cout << "\nLeaf Nodes: ";
    displayLeaves(root);
    cout << endl;
}


};

int main()
{
BST originalTree;
BST *newTree = NULL;


int choice;

do
{
    cout << "\n========================================";
    cout << "\n       BINARY SEARCH TREE MENU";
    cout << "\n========================================";
    cout << "\n1. Create Original BST";
    cout << "\n2. Display Original BST Level-Wise";
    cout << "\n3. Create New BST by Copying Original BST";
    cout << "\n4. Display New BST Level-Wise";
    cout << "\n5. Find Height of Original BST";
    cout << "\n6. Display Leaf Nodes of Original BST";
    cout << "\n7. Exit";
    cout << "\n========================================";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        originalTree.createBST();
        break;

    case 2:
        cout << "\nOriginal BST";
        originalTree.displayLevelWise();
        break;

    case 3:
        delete newTree;
        newTree = originalTree.createNewTree();
        cout << "\nNew BST created successfully.\n";
        break;

    case 4:
        if (newTree == NULL)
            cout << "\nFirst create the New BST using option 3.\n";
        else
        {
            cout << "\nNew BST";
            newTree->displayLevelWise();
        }
        break;

    case 5:
        originalTree.displayHeight();
        break;

    case 6:
        originalTree.displayLeafNodes();
        break;

    case 7:
        cout << "\nProgram terminated.\n";
        break;

    default:
        cout << "\nInvalid choice. Please try again.\n";
    }

} while (choice != 7);

delete newTree;
return 0;


}
