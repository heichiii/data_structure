#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m;
    cout << "Enter the size of a magic square: ";
    cin >> m;
    if (m % 2 == 0)
    {
        cout << "Error: m is even" << endl;
        return 0;
    }
    vector<vector<int>> magic(m, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            magic[i][j] = 0;
        }
    }
    int row = 0, col = m / 2, num = 1;
    while (num <= m * m)
    {
        magic[row][col] = num;
        num++;
        int new_row = (row - 1 + m) % m;
        int new_col = (col + 1) % m;
        if (magic[new_row][new_col] == 0)
        {
            row = new_row;
            col = new_col;
        }
        else
        {
            row = (row + 1) % m;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << magic[i][0];
        for (int j = 1; j < m; j++)
        {
            cout << " " << magic[i][j];
        }
        cout << endl;
    }

    return 0;
}