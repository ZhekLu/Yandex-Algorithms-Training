#include <iostream>
using namespace std;

int LBinSearch(int l, int r, const int* checkParams, int checkValue)
{
    int m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(checkParams[m] >= checkValue)
            r = m;
        else  
            l = m + 1;
    }
    return l;
}

int NumOfLess(int num, const int* seq, const int& size)
{
    int less = LBinSearch(0, size - 1, seq, num);
    if(seq[less] < num)
        return size; 
    return less;
}

int NumOfGreater(int num, const int* seq, const int& size)
{
    return size - NumOfLess(num + 1, seq, size);
}

int LMedianOfMerge(const int* seq1, const int* seq2, const int& size)
{
    int l = min(seq1[0], seq2[0]);
    int r = max(seq1[size - 1], seq2[size - 1]);
    int m, less, greater;
    while(l < r)
    {
        m = (l + r) / 2;
        less = NumOfLess(m, seq1, size) + NumOfLess(m, seq2, size);
        greater = NumOfGreater(m, seq1, size) + NumOfGreater(m, seq2, size);

        if(less <= size - 1 && greater <= size)
            return m;
        if(greater > size)
            l = m + 1;
        else  
            r = m - 1;
    }
    return l;
}

int main()
{
    int N, L; //N - numb of seq, L - len of each seq
    cin >> N >> L;
    int** sequences = new int*[N];
    for(int i = 0; i < N; i++)
    {
        sequences[i] = new int[L];
        for(int j = 0; j < L; j++)
            cin >> sequences[i][j];
    }

    for(int i = 0; i < N - 1; i++)
        for(int j = i + 1; j < N; j++)
            cout << LMedianOfMerge(sequences[i], sequences[j], L) << endl;
    

    for(int i = 0; i < N; i++)
        delete[] sequences[i];
    delete[] sequences;
}