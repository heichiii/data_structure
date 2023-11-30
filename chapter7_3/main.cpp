#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int INF = 1e9;

class Graph
{
private:
    int num_v;
    int num_s;
    vector<vector<int>> adj_matrix;
    vector<vector<int>> floyd();
    void swap(int &a, int &b);
    void permutate(int begin, int end, int a[], vector<vector<int>> *order);
    void get_path(int a, int b, vector<vector<int>> path);

public:
    Graph();
    Graph(int vertices);
    void update(int vertices);
    void add_edge(int src, int dest, int wei);
    int shortest_path(vector<int> *shortest_order, vector<vector<int>> *path);
    vector<vector<int>> get_adj();
    void DFS(int x, vector<vector<int>> *adj, vector<int> *path);
    void final_time(vector<vector<int>> *time_edge);
    void get_ood_path(vector<int> *oods, const vector<vector<int>> &flo);
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
    num_s++;
}
vector<vector<int>> Graph::floyd()
{

    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            adj_matrix[i][j] = adj_matrix[j][i];
        }
    }

    vector<vector<int>> path(num_v, vector<int>(num_v, -1));
    for (int k = 1; k < num_v; k++)
    {
        for (int v = 1; v < num_v; v++)
        {
            for (int w = 1; w < num_v; w++)
            {
                if (adj_matrix[v][w] > (adj_matrix[v][k] + adj_matrix[k][w]))
                {
                    if (v == w)
                    {
                        continue;
                    }
                    adj_matrix[v][w] = adj_matrix[v][k] + adj_matrix[k][w]; // 更新最小路径
                    path[v][w] = k;                                         // 更新最小路径中间顶点
                    path[w][v] = k;
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
void Graph::permutate(int begin, int end, int *a, vector<vector<int>> *order)
{

    if (begin == end) // 已经到了最后一个位置，进行输出
    {

        vector<int> order_t;
        for (int i = 0; i < end; i++)
        {
            order_t.push_back(a[i]);
        }
        order->push_back(order_t);
        order_t.clear();
    }
    for (int i = begin; i < end; i++)
    {
        swap(a[begin], a[i]);
        permutate(begin + 1, end, a, order); // 递归下一个位置
        swap(a[i], a[begin]);                // 回溯
    }
}
int Graph::shortest_path(vector<int> *shortest_order, vector<vector<int>> *path)
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
    *path = floyd();
    vector<int> add;
    int shortest = INF;
    vector<vector<int>> order;
    int size_t = odds.size();

    if (!odds.empty())
    {
        permutate(0, size_t, &odds[0], &order);
        int n = size_t / 2;
        int shortest = INF;
        int index;
        for (int i = 0; i < size_t; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                temp += adj_matrix[order[i][2 * j]][order[i][2 * j + 1]];
            }
            if (temp < shortest)
            {
                shortest = temp;
                index = i;
            }
        }
        *shortest_order = order[index];
        return shortest;
    }
    return 0;
}
vector<vector<int>> Graph::get_adj()
{
    return adj_matrix;
}
void Graph::DFS(int x, vector<vector<int>> *adj, vector<int> *path)
{

    for (int i = 1; i < num_v; i++)
    {
        if ((*adj)[x][i] > 0)
        {
            (*adj)[x][i]--;
            (*adj)[i][x]--;
            DFS(i, adj, path);
        }
    }

    path->push_back(x);
}
void Graph::get_path(int a, int b, vector<vector<int>> path)
{
    if (adj_matrix[a][b] == -1)
    {
    }
    else
    {
        get_path(path[a][b], b, path);
    }
}
void Graph::get_ood_path(vector<int> *oods, const vector<vector<int>> &flo)
{

    if (flo[*(oods->end() - 2)][*(oods->end() - 1)] != -1)
    {
        oods->insert(oods->end() - 1, flo[*(oods->end() - 2)][*(oods->end() - 1)]);
        get_ood_path(oods, flo);
    }
}
void Graph::final_time(vector<vector<int>> *time_edge)
{
    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            if (adj_matrix[i][j] != INF)
            {
                (*time_edge)[i][j] = 1;
            }
        }
    }
}
int main()
{
    int res = 0; // 路径长度
    int flag;    // 输入模式选择
    Graph area;
    int head; // 邮局
    int n_block;
    int n_street;
    int count = 0;
    cout << "please enter your input form:1.from keyboard 2.from file \"src.txt\"" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "please enter the number of the blocks:";

        cin >> n_block;
        area.update(n_block);
        cout << endl
             << "please enter the number of the streets:";

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
        cout << "please enter the point of post office" << endl;
        cin >> head;
    }
    else
    {
        ifstream fs("E:\\projects\\cpp\\data_structure\\chapter7_3\\src.txt");
        if (fs.is_open())
        {
            fs >> n_block;
            area.update(n_block);
            fs >> n_street;
            int beg, des, len;
            for (int i = 0; i < n_street; i++)
            {
                fs >> beg >> des >> len;
                area.add_edge(beg, des, len);
                res += len;
            }
            fs >> head;
        }
    }
    Graph copy = area;
    vector<int> path;           // DFS路径
    vector<int> shortest_order; // 最短的奇度点组合
    vector<vector<int>> path_f; // floyd路径
    res += area.shortest_path(&shortest_order, &path_f);
    if (!shortest_order.empty())
    {
        vector<vector<int>> odd_path; // 奇度点组合 以对的形式
        odd_path.resize(shortest_order.size() / 2);
        for (int i = 0; i < shortest_order.size() / 2; i++)
        {
            odd_path[i].push_back(shortest_order[2 * i]);
            odd_path[i].push_back(shortest_order[2 * i + 1]);
        }
        vector<vector<int>> time_edge(n_block, vector<int>(n_block, 0));
        copy.final_time(&time_edge);
        for (int i = 0; i < odd_path.size(); i++)
        {
            area.get_ood_path(&odd_path[i], path_f);
        }
        for (int i = 0; i < odd_path.size(); i++)
        {
            for (int j = 0; j < odd_path[i].size() - 1; j++)
            {
                time_edge[odd_path[i][j]][odd_path[i][j + 1]] = 2;
                time_edge[odd_path[i][j + 1]][odd_path[i][j]] = 2;
            }
        }

        copy.DFS(head, &time_edge, &path);
        cout << "shortest length is:" << res << endl;
        cout << "the path is:" << endl;
        for (int i : path)
        {
            cout << i << " ";
        }
        return 0;
    }
}