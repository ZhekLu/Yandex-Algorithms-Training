#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class FamilyTree
{
public:
    void TraverseInorderChildrenCount();
    void insert(const string& parent, const string& child);
private:
    struct Person
    {
        Person(const string& name) : name(name) {}
        string name;
        vector<Person*> children;
    };
    map<string, Person*> people; 
};


int main()
{
    int persNum;
    cin >> persNum;
    FamilyTree familyTree;
    {
        string child, parent;
        for (int i = 1; i < persNum; i++)
        {
            cin >> child >> parent;
            familyTree.insert(parent, child);
        }
        
    }
    familyTree.TraverseInorderChildrenCount();
}

void FamilyTree::insert(const string& parent, const string& child)
{
    if(!people[parent])
        people[parent] = new Person(parent);

    if(!people[child])
        people[child] = new Person(child);

    people[parent]->children.push_back(people[child]);
}

void FamilyTree::TraverseInorderChildrenCount()
{
    unsigned childrenNum;
    Person* child;
    for(auto&[name, persData] : people)
    {
        childrenNum = 0; 
        stack<Person*> toCheck;
        toCheck.push(persData);
        while(!toCheck.empty())
        {
            child = toCheck.top();
            toCheck.pop();

            childrenNum += child->children.size();
            for(auto& ch : child->children)
            {
                if(!ch->children.empty())
                    toCheck.push(ch);
            }
        }
        cout << name << ' ' << childrenNum << '\n';
    }
}