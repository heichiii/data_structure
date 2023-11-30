#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int INF = 1e9;

class Graph
{
    int num_v;
    vector<vector<int>> adj_matrix;
    vector<vector<int>> floyd();
    void swap(int& a, int& b );
    void permutate(int begin, int end, int a[],,vector<vector<int>> &order);
public:
    Graph();
    Graph(int vertices);
    void update(int vertices);
    void add_edge(int src, int dest, int wei);
    int shortest_path();
};
Graph::Graph() {}
Graph::Graph(int vertices)
{
    num_v = vertices;
    adj_matrix.resize(num_v, vector<int>(num_v, INF));
}
void Graph::update(int vertices)
{
    num_v = vertices;
    adj_matrix.resize(num_v, vector<int>(num_v, INF));
}
void Graph::add_edge(int src, int dest, int wei)
{
    adj_matrix[src][dest] = wei;
    adj_matrix[dest][src] = wei;
}
vector<vector<int>> Graph::floyd()
{

    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            adj_matrix[i][j] = adj_matrix[i][j];
        }
    }

    vector<vector<int>> path(num_v, vector<int>(num_v, -1));
    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            for (int k = 0; k < num_v; k++)
            {
                if (j == k)
                {
                    continue;
                }
                if (adj_matrix[j][i] != INF && adj_matrix[i][k] != INF && adj_matrix[j][i] + adj_matrix[i][k] < adj_matrix[i][j])
                {
                    adj_matrix[j][k] = adj_matrix[j][i] + adj_matrix[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
    return path;
}
void Graph::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Graph::permutate(int begin, int end, int *a, vector<vector<int>> &order)
{

    if (begin == end)//已经到了最后一个位置，进行输出
    {
        vector<int> order_t;
        for (int i = 0; i < end; i++) {
            order_t.push_back;
        }
        cout << endl;
    }
    for (int i = begin; i < end; i++) {
        swap(a[begin], a[i]);
        permutate(begin + 1, end, a);//递归下一个位置
        swap(a[i], a[begin]);        //回溯
    }
}
int Graph::shortest_path()
{
    vector<int> odds;
    for (int i = 0; i < num_v; i++)
    {
        int count = 0;
        for (int j = 0; j < num_v; j++)
        {
            if (adj_matrix[i][j] < INF)
            {
                count++;
            }
        }
        if (count % 2 != 0)
        {
            odds.push_back(i);
        }
    }
    vector<vector<int>> path = floyd();
    vector<int> add;
    int shortest = INF;
    for (int i = 0; i < odds.size(); i++)
    {
        for (int j = 0; j < odds.size(); j++)
        {
            if (adj_matrix[odds[i]][odds[j]] < shortest)
            {
                shortest = adj_matrix[odds[i]][odds[j]];
                add.clear();
                add.push_back(odds[i]);
                add.push_back(odds[j]);
            }
        }
    }
    int res = 0;
    int ods = odds.size() - 1;
    vector<int> dp((1 << ods), -1);
    dp[0] = 0;
    for (int i = 0; i < (1 << ods); ++i)
    {
        int x = 1;
        while ((1 << (x - 1)) & i)
        {
            ++x;
        }
        for (int y = x + 1; y <= ods; ++y)
        {
            if ((1 << (y - 1)) & i)
            {
                continue;
            }
            int mask = i | (1 << (x - 1)) | (1 << (y - 1));
            if (dp[i] != -1 && adj_matrix[odds[x]][odds[y]] != -1)
            {
                if (dp[mask] == -1)
                {
                    dp[mask] = dp[i] + adj_matrix[odds[x]][odds[y]];
                }
                else
                {
                    dp[mask] = min(dp[mask], dp[i] + adj_matrix[odds[x]][odds[y]]);
                }
            }
            else
            {
                dp[mask] = dp[i];
            }
        }
    }
    cout << dp[7];
    return dp[(1 << ods) - 1];
}
int main()
{
    int res = 0;
    int flag;
    Graph area;
    cout << "please enter your input form:1.from keyboard 2.from file \"src.txt\"" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "please enter the number of the blocks:";
        int n_block;
        cin >> n_block;
        area.update(n_block);
        cout << endl
             << "please enter the number of the streets:";
        int n_street;
        cin >> n_street;
        cout << endl
             << "please enter the beginning,the destination,and the length of every street:(split with space)";
        int beg, des, len;
        for (int i = 0; i < n_street; i++)
        {
            cin >> beg >> des >> len;
            area.add_edge(beg, des, len);
            res += len;
        }
        int head;
        cout << "please enter the point of post office" << endl;
        cin >> head;
    }
    else
    {
        ifstream fs("src.txt");
        if (fs.is_open())
        {
            int n_block;
            fs >> n_block;
            area.update(n_block);
            int n_street;
            fs >> n_street;
            int beg, des, len;
            for (int i = 0; i < n_street; i++)
            {
                fs >> beg >> des >> len;
                area.add_edge(beg, des, len);
                res += len;
            }
            int head;
            fs >> head;
        }
    }
    res += area.shortest_path();
    cout << res;
    return 0;
}
