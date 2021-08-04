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
        root = new Node(key);
    else
        insert(key, root);
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

int Tree::getHeight() const
{
    return root->height;
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
