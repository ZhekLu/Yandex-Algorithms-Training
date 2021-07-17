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

int* MakeSequence(int params[], const int& size)
{
    int* seq = new int[size];
    for(int i = 0; i < size; i++)
    {
        seq[i] = params[0];
        params[0] += params[1];
        params[1] = (params[1] * params[2] + params[3]) % params[4];
    }
    return seq;
}

int main()
{
    int N, L; //N - numb of seq, L - len of each seq
    cin >> N >> L;
    int** sequences = new int*[N];
    int params[5]; // x1, d1, a, c, m
    for(int i = 0; i < N; i++)
    {
        for(int p = 0; p < 5; p++)
            cin >> params[p]; 
        sequences[i] = MakeSequence(params, L);
    }


    for(int i = 0; i < N - 1; i++)
        for(int j = i + 1; j < N; j++)
            cout << LMedianOfMerge(sequences[i], sequences[j], L) << endl;
    

    for(int i = 0; i < N; i++)
        delete[] sequences[i];
    delete[] sequences;
}