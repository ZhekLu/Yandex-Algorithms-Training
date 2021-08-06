#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <deque>
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
    unordered_map<string, Person*> people;
    unordered_map<string, string> child_parent;  
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
    child_parent[child] = parent;
}

void FamilyTree::TraverseInorderChildrenCount()
{
    vector<string> BFS = [&]
    {
        string ancestor; 
        for(auto&[person, data] : people)
        {
            if(!child_parent.count(person))
            {
                ancestor = person;
                break;
            }
        }

        deque<string> toCheck;
        vector<string> bfs; 
        toCheck.push_back(ancestor);

        while(!toCheck.empty())
        {
            bfs.push_back(toCheck.front());
            for(const auto& child : people[bfs.back()]->children)
                toCheck.push_back(child->name);
            toCheck.pop_front();
        }

        return bfs;
    }();

    unordered_map<string, int> person_childrenNum;

    for(auto it = BFS.rbegin(); it != BFS.rend(); it++)
        for(const auto& child : people[*it]->children)
            person_childrenNum[*it] += person_childrenNum[child->name] + 1;
    
    sort(BFS.begin(), BFS.end());

    for(const auto& person : BFS)
        cout << person << ' ' << person_childrenNum[person] << '\n';
}