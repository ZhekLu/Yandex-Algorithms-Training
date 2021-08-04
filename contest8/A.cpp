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
    int getHeight() const;
private:
    // node struct
    struct Node
    {
        explicit Node(int value) : key(value) {}
        int key;
        int height = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        void UpdateHeight()
        {
            int hleft = (this->left) ? this->left->height : -1;
            int hright = (this->right) ? this->right->height : -1;
            this->height = (hleft > hright ? hleft : hright) + 1;
        }
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

int Tree::getHeight() const
{
    return root->height + 1;
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
    currRoot->UpdateHeight();
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
    cout << tree.getHeight();
}