#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//typedef struct Node
//{
//    char ch;
//    int v;
//    Node *left;
//} Node;
int main()
{

/*    Node *nodes = new Node[2];
    nodes[0].ch = 'a';
    nodes[0].v = 0;
    nodes[1].ch = 'b';
    nodes[1].v = 1;
    nodes[0].left = &nodes[1];
    nodes[1].left = &nodes[0];
    ofstream of("tof.dat", ios::binary);
    if (of.is_open())
    {
        for (int i = 0; i < 2; i++) {

            of.write((const char *) &nodes[i], sizeof(nodes[0]));
        }
        of.close();
    }
    delete[] nodes;
    Node *back=new Node[2];
    ifstream ifs("tof.dat",ios::binary);
    if(ifs.is_open())
    {
        for(int i=0;i<2;i++)
        {
            ifs.read((char*)&back[i],sizeof(back[0]));
        }

    }
    delete[] back;*/

    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    cout<<*(test.end()-1);
    return 0;
}
