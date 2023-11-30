#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
using namespace std;
typedef struct Node
{
    char index;
    char ch;
    int weight;
    char left;
    char right;
    char parent;
} Node;
int num = 0;
// 遍历树，得到哈夫曼编码
void dfs(Node *nodes, int index, string *code, string codes[])
{
    string copy = *code;
    if (index == -1)
    {
        return;
    }
    if (nodes[index].left == -1 && nodes[index].right == -1)
    {
        codes[num] += nodes[index].ch;
        codes[num] += copy;
        num++;
    }
    string copy1 = copy + "0";
    string copy2 = copy + "1";
    dfs(nodes, nodes[index].left, &copy1, codes);
    dfs(nodes, nodes[index].right, &copy2, codes);
}
// 编码
string encoder(char c, map<char, string> hufcode)
{
    auto it = hufcode.find(c);
    if (it != hufcode.end())
    {
        return it->second;
    }
    return "";
}
// 解码
char decoder(string code, map<string, char> hufcode)
{
    auto it = hufcode.find(code);
    if (it != hufcode.end())
    {
        return it->second;
    }
    return '\0';
}
int main()
{
    // 打开文件
    ifstream f_src("E:/projects/cpp/data_structure/chapter6_6/src.txt");
    // 统计字频
    int freq[128]{};
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
    int count = 0; // 叶子数
    for (int i = 0; i < 128; i++)
    {
        if (freq[i] != 0)
            count++;
    }
    // 建节点
    Node *nodes = new Node[2 * count - 1];
    for (int i = 0; i < 2 * count - 1; i++)
    {
        nodes[i].index = -1;
        nodes[i].ch = -1;
        nodes[i].weight = -1;
        nodes[i].left = -1;
        nodes[i].right = -1;
        nodes[i].parent = -1;
    }
    int count2 = 0;
    for (int i = 0; i < 128; i++)
    {
        if (freq[i] != 0)
        {
            nodes[count2].index = count2;
            nodes[count2].ch = i;
            nodes[count2].weight = freq[i];
            count2++;
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
            if (nodes[j].weight < min1 && nodes[j].parent == -1)
            {
                min2 = min1;
                min2_index = min1_index;
                min1 = nodes[j].weight;
                min1_index = j;
            }
            else if (nodes[j].weight < min2 && nodes[j].parent == -1)
            {
                min2 = nodes[j].weight;
                min2_index = j;
            }
        }
        // 合并最小的两个节点
        nodes[count + i].index = count + i;
        nodes[count + i].weight = min1 + min2;
        nodes[count + i].left = nodes[min1_index].index;
        nodes[count + i].right = nodes[min2_index].index;
        nodes[min1_index].parent = nodes[count + i].index;
        nodes[min2_index].parent = nodes[count + i].index;
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
    // 读树
    ifstream readhf("Huftree.dat", ios::binary);
    int n;

    readhf.read((char *)&n, sizeof n);
    Node *nodes_2 = new Node[n];
    for (int i = 0; i < n; i++)
    {
        readhf.read((char *)&nodes_2[i], sizeof nodes_2[0]);
    }
    readhf.close();

    string code{};
    string codes[count];
    // 输出哈夫曼编码
    dfs(nodes_2, n - 1, &code, codes);
    ofstream codef("HufCode.txt");
    if (codef.is_open())
    {
        for (int i = 0; i < count; i++)
        {

            codef << codes[i] << endl;
        }
        codef.close();
    }
    delete[] nodes_2;
    // 读取哈夫曼编码
    map<char, string> hufcode;
    map<string, char> hufcode2;
    ifstream ihufcode("HufCode.txt");
    if (ihufcode.is_open())
    {
        char character, last_character = 0;

        string hcode;
        while (ihufcode.get(character))
        {
            if (character == '\n' && last_character != '\n')
            {
                last_character = '\n';
                character = 0;
                continue;
            }

            ihufcode >> hcode;
            hufcode[character] = hcode;
            hufcode2[hcode] = character;
            if (character == '\n')
            {
                last_character = 0;
            }
            else
            {
                last_character = character;
            }
        }
        ihufcode.close();
    }
    // 编码
    ifstream src("E:/projects/cpp/data_structure/chapter6_6/src.txt");
    ofstream codefile("CodeFile.dat", ios::binary);
    if (src.is_open() && codefile.is_open())
    {
        char c;
        string encoded;
        while (src.get(c))
        {
            encoded = encoder(c, hufcode);
            codefile.write(encoded.c_str(), encoded.length());
        }
        src.close();
        codefile.close();
    }

    // 解码
    ifstream codefile2("CodeFile.dat", ios::binary);
    ofstream decodefile("DecodeFile.txt");
    if (codefile2.is_open() && decodefile.is_open())
    {
        string code;
        char c;
        while (codefile2.get(c))
        {
            code += c;
            if (hufcode2.find(code) != hufcode2.end())
            {
                decodefile << hufcode2[code];
                code = "";
            }
        }
        codefile2.close();
        decodefile.close();
    }

    return 0;
}
