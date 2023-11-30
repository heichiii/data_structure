#include <iostream>
using namespace std;

class LineJoseph
{

public:
    int n, m = 0;
    // 构造函数
    LineJoseph(int n, int m)
    {
        this->n = n;
        this->m = m;
    }
    void joseph_out()
    {
        int *p = new int[n];
        for (int i = 0; i < n; i++)
        {
            p[i] = i + 1;
        }
        int index = 0;
        int count = n;
        for (int i = 0; i < n; i++)
        {
            index = (index + m - 1) % count;
            cout << p[index] << " ";
            for (int j = index; j < count - 1; j++)
            {
                p[j] = p[j + 1];
            }
            count--;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    // int *p = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     p[i] = i + 1;
    // }
    int m;
    cin >> m;
    // int index = 0;
    // int count = n;
    // for (int i = 0; i < n; i++)
    // {
    //     index = (index + m - 1) % count;
    //     cout << p[index] << " ";
    //     for (int j = index; j < count - 1; j++)
    //     {
    //         p[j] = p[j + 1];
    //     }
    //     count--;
    // }
    LineJoseph line(n, m);
    line.joseph_out();

    return 0;
}