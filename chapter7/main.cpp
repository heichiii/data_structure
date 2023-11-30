#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Graph
{
    int num_v;
    vector<vector<pair<int,int>>> adj_list;

public:
    Graph();
    Graph(int vertices);
    void add_edge(int src, int dest, int weight);
    void BFS(int s);
};
Graph::Graph() {}
Graph::Graph(int vertices)
{
    num_v=vertices;
    adj_list.resize(num_v);
}
void Graph::add_edge(int src, int dest,int weight)
{
    adj_list[src].push_back(make_pair(dest,weight));
    adj_list[dest].push_back(make_pair(src,weight));
}
int main()
{
    int flag;
    cout<<"please enter your input form:1.from keyboard 2.from file \"src.txt\""<<endl;
    cin>>flag;
    if(flag==1)
    {
        cout << "please enter the number of the blocks:";
        int n_block;
        cin >> n_block;
        Graph area(n_block);
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
        }
    }
    else
    {
        ifstream fs("src.txt");
        if(fs.is_open())
        {
            int n_block;
            fs >> n_block;
            Graph area(n_block);
            int n_street;
            fs >> n_street;
            int beg, des, len;
            for (int i = 0; i < n_street; i++)
            {
                fs >> beg >> des >> len;
                area.add_edge(beg, des, len);
            }
        }
    }
    return 0;
}
