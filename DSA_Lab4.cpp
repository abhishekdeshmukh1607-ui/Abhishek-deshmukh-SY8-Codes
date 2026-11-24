#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Binary
{
private:
    Node *root;

public:
    Binary()
    {
        root = NULL;
    }

    Node* create()
    {
        int value;

        cout << "\nEnter node value (-1 for no Node): ";
        cin >> value;

        if(value == -1)
            return NULL;

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter Left Child of " << value << ": ";
        newNode->left = create();

        cout << "Enter Right Child of " << value << ": ";
        newNode->right = create();

        return newNode;
    }

    void build()
    {
        cout << "\nCreate Binary Tree\n";
        root = create();
    }

    void inorder(Node *temp)
    {
        if(temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void preorder(Node *temp)
    {
        if(temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(Node *temp)
    {
        if(temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    void display(int choice)
    {
        if(root == NULL)
        {
            cout << "\nTree is Empty.\n";
            return;
        }

        switch(choice)
        {
            case 1:
                cout << "\nInorder Traversal: ";
                inorder(root);
                break;

            case 2:
                cout << "\nPreorder Traversal: ";
                preorder(root);
                break;

            case 3:
                cout << "\nPostorder Traversal: ";
                postorder(root);
                break;

            default:
                cout << "\nInvalid Choice!";
        }

        cout << endl;
    }
};

int main()
{
    Binary b;
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                b.build();
                break;

            case 2:
                b.display(1);
                break;

            case 3:
                b.display(2);
                break;

            case 4:
                b.display(3);
                break;

            case 5:
                cout << "\nProgram Ended.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}