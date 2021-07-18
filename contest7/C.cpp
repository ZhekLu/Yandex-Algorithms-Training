#include <iostream>
#include <stack>
#include <tuple>
#include <set>
using namespace std;

enum Events : int
{
    STUDENT_BEGIN, STUDENT_END
};

int* MinNumOfVariants(const set<tuple<int, int, int>>& students, int stNum, int minSpacing, int& answer)
{
    int* result = new int[stNum];
    answer = 0; //maxVariantsNum;

    stack<int> variants;
    for(int i = stNum + 1; i > 0; i--)
        variants.push(i);

    for(auto&[coordinate, type, index] : students)
    {
        if(type == STUDENT_END)
        {
            variants.push(result[index]);
        }
        else
        {
            result[index] = variants.top();
            answer = max(answer, result[index]);
            variants.pop();
        }
    }
    
    return result;
}

int main()
{
    int studentsNum, minSpacing; 
    cin >> studentsNum >> minSpacing;
    set<tuple<int, int, int>> studentsLocation;
    for(int i = 0, coo; i < studentsNum; i++)
    {
        cin >> coo; 
        studentsLocation.insert(make_tuple(coo, STUDENT_BEGIN, i));
        studentsLocation.insert(make_tuple(coo + minSpacing, STUDENT_END, i));
    }
    int variantsNum;
    int* resultLocation = MinNumOfVariants(studentsLocation, studentsNum, minSpacing, variantsNum);
    
    cout << variantsNum << endl;
    for(int i = 0; i < studentsNum; i++)
        cout << resultLocation[i] << " ";

    delete[] resultLocation; 
}