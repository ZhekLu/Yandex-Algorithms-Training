#include <iostream>
using namespace std;

int main()
{
    int N, M, K;
    const int sidesq = 8;
    int checkX[sidesq] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int checkY[sidesq] = {-1, 0, 1, -1, 1, -1, 0, 1};
    cin >> N >> M >> K;
    N+= 2; M +=2; 
    int** field = new int*[N];
    for(int i = 0; i < N; i++)
    {
        field[i] = new int[M];
        for(int j = 0; j < M; j++)
            field[i][j] = 0;
    }

    for(int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        field[x][y] = -1;
        for(int k = 0; k < sidesq; k++)
            if(field[x + checkX[k]][y + checkY[k]] != -1) 
                field[x + checkX[k]][y + checkY[k]]++;
            
                
    }
    for(int i = 1; i < N - 1; i++)
    {
        for(int j = 1; j < M - 1; j++)
        {
            if(field[i][j] == -1) 
                cout << "* " ;
            else 
                cout << field[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < N; i++)
        delete[] field[i];
    delete[] field; 
}