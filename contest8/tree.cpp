#include <vector>
#include <iostream>
class Tree
{
public:
    // ctor & destr
    ~Tree();
   
    // methods
    void insert(int key);
    void remove(int key);
    void clear();
    int getHeight() const;
    bool isBalanced() const;
    int getMax(int num);
    const std::vector<int>& getDepths() const; 
private:
    // node struct
    struct Node
    {
        explicit Node(int value, int depth = 0) : key(value), depth(depth) {}
        int key;
        int height = 0;
        int depth;
        Node* left = nullptr;
        Node* right = nullptr;
        void UpdateHeight()
        {
            int hleft = (this->left) ? this->left->height : -1;
            int hright = (this->right) ? this->right->height : -1;
            this->height = (hleft > hright ? hleft : hright) + 1;
        }
        static int UpdateDepths(bool isNew = 0)
        {
            static int depth = 0;
            if(isNew)
                depth = 0;
            else  
                depth++;
            return depth;
        }
        
        int balanceFactor();
        bool TraversePostorderBalance(bool balance = true);
        void TraverseInorder(int num, int* answ = nullptr);
        void TraverseInorder();
    };
    // elements
    Node* root = nullptr;
    std::vector<int> depths;

    // func methods
    void insert(int key, Node* currRoot);
    Node* remove(int key, Node* currRoot);
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

void Tree::remove(int key)
{
    root = remove(key, root);  
}

void Tree::clear()
{
    clear(root);
    root = nullptr;
}
const std::vector<int>& Tree::getDepths() const
{
    return depths; 
}

int Tree::getHeight() const
{
    return root->height;
}

bool Tree::isBalanced() const
{
    return root->TraversePostorderBalance();
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

void Tree::Node::TraverseInorder()
{

    if(this->left)
        this->left->TraverseInorder();

    std::cout << this->key << std::endl;

    if(this->right)
        this->right->TraverseInorder();

}

bool Tree::Node::TraversePostorderBalance(bool balance)
{
    if(!balance)
        return balance;
    if(this->left)
        balance = this->left->TraversePostorderBalance();
    if(balance && this->right)
        balance = this->right->TraversePostorderBalance();
    if(balance)
        balance = abs(this->balanceFactor()) < 2;
    return balance;
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
    currRoot->UpdateHeight();
}

Tree::Node* Tree::remove(int key, Node* currRoot)
{
    if (!currRoot)
        return nullptr;

    if (currRoot->key > key)
        currRoot->left = remove(key, currRoot->left);
    else if (currRoot->key < key)
        currRoot->right = remove(key, currRoot->right);
    else
    {
        if (!currRoot->left && !currRoot->right)
        {
            delete currRoot;
            currRoot = nullptr;
        }
        else if (!currRoot->right)
        {
            Node* temp = currRoot;
            currRoot = currRoot->left;
            delete temp;
        }
        else if (!currRoot->left)
        {
            Node* temp = currRoot;
            currRoot = currRoot->right;
            delete temp;
        }
        else
        {
            Node* temp = currRoot->right;
            while (temp->left)
                temp = temp->left;
            currRoot->key = temp->key; 
            currRoot->right = remove(temp->key, currRoot->right);
        }
    }
    
    if (currRoot)
        currRoot->UpdateHeight();
    
    return currRoot;
}

int Tree::Node::balanceFactor()
{
    int hleft = (this->left) ? this->left->height : -1;
    int hright = (this->right) ? this->right->height : -1;
    return hright - hleft;
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
