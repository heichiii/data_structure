#include <iostream>
#include <fstream>
using namespace std;
typedef struct Node
{
    int index;
    char ch;
    int weight;
    Node *left;
    Node *right;
    Node *parent;

} Node;

void dfs(Node *nodes, string code, string *str, int num)
{
    if (nodes == nullptr)
    {
        return;
    }
    if (!nodes->left && !nodes->right)
    {
        str[num] = nodes->ch;
        str[num] += " ";
        str[num] += code;
        str[num] += '\n';
        num++;
    }
    dfs(nodes->left, code + "0", str, num);
    dfs(nodes->right, code + "1", str, num);
}

int main()
{
    // 打开文件
    ifstream f_src("E:/projects/cpp/data_structure/chapter6_2/src.txt");
    // 统计字频
    char freq[128]{};
    if (f_src.is_open())
    {
        char c;
        while ((c = f_src.get()) != EOF)
        {
            freq[c]++;
        }
    }
    f_src.close();
    // 统计需要的节点数
    int count = 0;
    for (int i = 0; i < 128; i++)
    {
        if (freq[i] != 0)
            count++;
    }
    // 建节点
    Node *nodes = new Node[2 * count - 1];
    int count2 = 0;
    for (int i = 0; i < 128; i++)
    {
        if (freq[i] != 0)
        {
            nodes[count2].index = count2;
            nodes[count2].ch = i;
            nodes[count2].weight = freq[i];
            nodes[count2].left = nullptr;
            nodes[count2].right = nullptr;
            nodes[count2].parent = nullptr;
        }
    }
    // 建树
    for (int i = 0; i < count - 1; i++)
    {
        int min1 = 0x7fffffff, min2 = 0x7fffffff;
        int min1_index = 0, min2_index = 0;
        // 寻找最小的两个节点
        for (int j = 0; j < count + i; j++)
        {
            if (nodes[j].weight < min1 && nodes[j].parent == nullptr)
            {
                min2 = min1;
                min2_index = min1_index;
                min1 = nodes[j].weight;
                min1_index = j;
            }
            else if (nodes[j].weight < min2 && nodes[j].parent == nullptr)
            {
                min2 = nodes[j].weight;
                min2_index = j;
            }
        }
        // 合并最小的两个节点
        nodes[count + i].index = count + i;
        nodes[count + i].weight = min1 + min2;
        nodes[count + i].left = &nodes[min1_index];
        nodes[count + i].right = &nodes[min2_index];
        nodes[min1_index].parent = &nodes[count + i];
        nodes[min2_index].parent = &nodes[count + i];
    }
    // 存树
    ofstream tree("Huftree.dat", ios::binary);
    if (tree.is_open())
    {
        int number = 2 * count - 1;
        tree.write((const char *)&number, sizeof number);
        for (int i = 0; i < number; i++)
        {
            tree.write((const char *)&nodes[i], sizeof nodes[0]);
        }
        delete[] nodes;
        tree.close();
    }
    ifstream readhf("Huftree.dat", ios::binary);
    int n;
    Node *nodes_2 = new Node[n];

    readhf.read((char *)&n, sizeof n);

    for (int i = 0; i < n; i++)
    {
        readhf.read((char *)&nodes_2[i], sizeof nodes_2[0]);
    }
    readhf.close();

    string code{};
    string codes[count];
    dfs(nodes, code, codes, 0);
    ofstream codef("HufCode.txt");
    if (codef.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            codef.write((const char *)&codes[i], size(codes[i]));
        }
    }
    codef.close();

    delete[] nodes_2;
    return 0;
}

// void dfs(Node*nodes ,string str)
//{
//
//     if(nodes->parent== nullptr)
//     {
//         dfs(nodes->left,str);
//     }
//     else
//     {
//         if(nodes->parent->left==nodes)
//         {
//             string temp = str;
//             temp+='0';
//         }
//         else
//         {
//             string temp = str;
//             temp+='1';
//         }
//         if()
//     }
//
// }
