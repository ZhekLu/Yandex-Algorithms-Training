#include <iostream>
using namespace std;
class Tree
{
public:
    // ctor & destr
    ~Tree();
   
    // methods
    void insert(int key);
    void clear();
    void TraverseInorder();
private:
    // node struct
    struct Node
    {
        explicit Node(int value) : key(value) {}
        int key;
        Node* left = nullptr;
        Node* right = nullptr;
        void TraverseInorder();
    };
    // elements
    Node* root = nullptr;

    // func methods
    void insert(int key, Node* currRoot);
    void clear(Node* currRoot);
};

Tree::~Tree()
{
    this->clear();
}

void Tree::insert(int key)
{
    if (!root)
        root = new Node(key);
    else
        insert(key, root);
}

void Tree::clear()
{
    clear(root);
    root = nullptr;
}

void Tree::TraverseInorder()
{
    root->TraverseInorder();
}

void Tree::Node::TraverseInorder()
{

    if(this->left)
        this->left->TraverseInorder();

    cout << this->key << endl;

    if(this->right)
        this->right->TraverseInorder();

}

void Tree::insert(int key, Node* currRoot)
{
    if (currRoot->key > key)
    {
        if (currRoot->left)
            insert(key, currRoot->left);
        else
            currRoot->left = new Node(key);
    }
    else if (currRoot->key < key)
    {
        if (currRoot->right)
            insert(key, currRoot->right);
        else
            currRoot->right = new Node(key);
    }
}

void Tree::clear(Node* currRoot)
{
    if (!currRoot)
        return;
    if (currRoot->left)
        clear(currRoot->left);
    if (currRoot->right)
        clear(currRoot->right);
    delete currRoot;
}


int main()
{
    Tree tree;
    int value;
    cin >> value;
    while(value)
    {
        tree.insert(value);
        cin >> value;
    }
    tree.TraverseInorder();
}