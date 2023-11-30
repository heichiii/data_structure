#include <iostream>
#include <fstream>

using namespace std;
class Node
{
public:
  char c;
  int weight;
  Node *left;
  Node *right;
  Node *parent;
  Node(char c, int weight, Node *left = nullptr, Node *right = nullptr, Node *parent = nullptr) : c(c), weight(weight), left(left), right(right), parent(parent) {}
  Node() : c(0), weight(0), left(nullptr), right(nullptr), parent(nullptr) {}
};
int main()
{
  // 读文件统计字频
  int freq[128]{};
  fstream fs("src.txt");
  if (fs.is_open())
  {
    char c;
    while ((c = fs.get()) != EOF)
    {
      freq[c]++;
    }
  }
  // 获取总字符种类数
  int count = 0;
  for (int i = 0; i < 128; i++)
  {
    if (freq[i] != 0)
    {
      count++;
    }
  }
  // 构建哈夫曼树
  Node *nodes = new Node[2 * count - 1];
  // 前count个节点存储叶子节点
  int index = 0;
  for (int i = 0; i < 128; i++)
  {
    if (freq[i] != 0)
    {
      nodes[index++] = Node(i, freq[i]);
    }
  }
  // 后count-1个节点存储非叶子节点
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
    nodes[count + i].weight = min1 + min2;
    nodes[count + i].left = &nodes[min1_index];
    nodes[count + i].right = &nodes[min2_index];
    nodes[min1_index].parent = &nodes[count + i];
    nodes[min2_index].parent = &nodes[count + i];
  }
  // 存储哈夫曼树到bat文件
  ofstream ofss("huffman.bat");
  if (ofss.is_open())
  {
    for (int i = 0; i < 2 * count - 1; i++)
    {
      ofss << nodes[i].c << " " << nodes[i].weight << " ";
      if (nodes[i].left != nullptr)
      {
        ofss << nodes[i].left->c << " ";
      }
      else
      {
        ofss << "null ";
      }
      if (nodes[i].right != nullptr)
      {
        ofss << nodes[i].right->c << " ";
      }
      else
      {
        ofss << "null ";
      }
      if (nodes[i].parent != nullptr)
      {
        ofss << nodes[i].parent->c << " ";
      }
      else
      {
        ofss << "null ";
      }
      ofss << endl;
    }
  }
  ofss.close();

  // 根据bat文件构建哈夫曼编码

  // 读bat文件
  ifstream ifs("huffman.bat");
  string *codes = new string[count];
  if (ifs.is_open())
  {
    char c;
    int weight;
    string left, right, parent;
    index = 0;
    while (ifs.get(c))
    {
      ifs >> weight >> left >> right >> parent;
      if (parent == "null")
      {
        while ()
      }
    }
  }
  ifs.close();

  // 输出压缩文件
  fs.clear();
  fs.seekg(0, ios::beg);
  ofstream ofs("CodeFile.bat");
  if (fs.is_open() && ofs.is_open())
  {
    char c;
    string code;
    while ((c = fs.get()) != EOF)
    {
      for (int i = 0; i < count; i++)
      {
        if (c == nodes[i].c)
        {
          code = codes[i];
          break;
        }
      }
      ofs << code;
    }
  }
  fs.close();
  ofs.close();
  delete[] nodes;
  delete[] codes;
  // 根据huffman.bat解码CodeFile.bat
  ifstream ifs2("huffman.bat");
  string *codes2 = new string[count];
  if (ifs2.is_open())
  {
    char c;
    int weight;
    char left, right, parent;
    while (ifs2 >> c >> weight >> left >> right >> parent)
    {
      if (left == 'n' && right == 'n')
      {
        codes2[index++] = "";
      }
      else
      {
        codes2[index++] = "";
      }
    }
  }
  ifs2.close();
  ifstream ifs3("CodeFile.bat");
  ofstream ofs2("DecodeFile.txt");
  if (ifs3.is_open() && ofs2.is_open())
  {
    char c;
    string code;
    Node *p = &nodes[2 * count - 2];
    while ((c = ifs3.get()) != EOF)
    {
      if (c == '0')
      {
        p = p->left;
      }
      else
      {
        p = p->right;
      }
      if (p->left == nullptr && p->right == nullptr)
      {
        ofs2 << p->c;
        p = &nodes[2 * count - 2];
      }
    }
  }
  ifs3.close();
  ofs2.close();
  delete[] codes2;

  return 0;
}