#include <iostream>
#include <vector>
using namespace std;
class Tree
{
public:
    // ctor & destr
    ~Tree();
   
    // methods
    void insert(int key);
    void clear();
    const vector<int>& getDepths() const; 
private:
    // node struct
    struct Node
    {
        explicit Node(int value, int depth = 0) : key(value), depth(depth) {}
        int key;
        int depth = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        static int UpdateDepths(bool isNew = 0)
        {
            static int depth = 0;
            if(isNew)
                depth = 0;
            else  
                depth++;
            return depth;
        }
    };
    // elements
    Node* root = nullptr;
    vector<int> depths;

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
    {
        root = new Node(key);
        depths.push_back(1);
    }
    else
    {
        insert(key, root);
        Node::UpdateDepths(true);
    }
}

void Tree::clear()
{
    clear(root);
    root = nullptr;
}

const vector<int>& Tree::getDepths() const
{
    return depths; 
}

void Tree::insert(int key, Node* currRoot)
{
    Node::UpdateDepths();
    if (currRoot->key > key)
    {
        if (currRoot->left)
            insert(key, currRoot->left);
        else
        {
            currRoot->left = new Node(key, Node::UpdateDepths());
            depths.push_back(currRoot->left->depth);
        }
        
    }
    else if (currRoot->key < key)
    {
        if (currRoot->right)
            insert(key, currRoot->right);
        else
        {
            currRoot->right = new Node(key, Node::UpdateDepths());
            depths.push_back(currRoot->right->depth);
        }
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
    
    for(auto& d : tree.getDepths())
    {
        cout << d << " ";
    }
}