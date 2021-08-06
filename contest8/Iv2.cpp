#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

class FamilyTree
{
public:
    void insert(const string& parent, const string& child);
    void TraverseInorderChildrenCount();
private:
    unordered_map<string, string> child_parent; 
    unordered_map<string, vector<string>> parent_children; 
};

int main()
{
    int persNum;
    cin >> persNum;
    FamilyTree ftree;
    {
        string parent, child; 
        for(int i = 1; i < persNum; i++)
        {
            cin >> child >> parent;
            ftree.insert(parent, child);
        }   
    }
    ftree.TraverseInorderChildrenCount();
}

void FamilyTree::insert(const string& parent, const string& child)
{
    child_parent[child] = parent;
    parent_children[parent].push_back(child);
}

void FamilyTree::TraverseInorderChildrenCount()
{
    vector<string> BFS = [&]
    {
        string ancestor; 
        for(auto&[parent, children] : parent_children)
        {
            if(!child_parent.count(parent))
            {
                ancestor = parent;
                break;
            }
        }
        vector<string> bfs; 
        deque<string> toCheck;
        toCheck.push_back(ancestor);

        while(!toCheck.empty())
        {
            bfs.push_back(toCheck.front());
            for(auto& child : parent_children[bfs.back()])
            {
                toCheck.push_back(child);
            }
            toCheck.pop_front();
        }

        return bfs;
    }();

    unordered_map<string, int> person_childrenNum;
    for(auto it = BFS.rbegin(); it != BFS.rend(); it++)
        for(const auto& child : parent_children[*it])
            person_childrenNum[*it] += person_childrenNum[child] + 1;
    
    sort(BFS.begin(), BFS.end());

    for(const auto& person : BFS)
        cout << person << ' ' << person_childrenNum[person] << '\n';
}