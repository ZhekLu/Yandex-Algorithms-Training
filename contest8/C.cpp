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
    int getMax(int num);
private:
    // node struct
    struct Node
    {
        explicit Node(int value) : key(value) {}
        int key;
        Node* left = nullptr;
        Node* right = nullptr;
        void TraverseInorder(int num, int* answ = nullptr);
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

int Tree::getMax(int num)
{
    if(!root)
        return INT32_MIN;
    int answ;
    root->TraverseInorder(num, &answ);

    root->TraverseInorder(-1);
    return answ;
}

void Tree::Node::TraverseInorder(int num, int* answ)
{
    static int count = 0;
    if(num == -1)
    {
        count = 0;
        return;
    }

    if(this->right)
        this->right->TraverseInorder(num, answ);

    count++;
    if(count == num)
        *answ = this->key;

    if(this->left)
        this->left->TraverseInorder(num, answ);

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
    cout << tree.getMax(2);
}