//
// Created by 14477 on 2023/12/2.
//
#include <iostream>
#include <vector>

using namespace std;
class Exam
{
public:
    vector<int> css;
};
class Class
{
public:
    vector<int> ess;
    void update(int a, int b, int c)
    {
        ess.resize(3);
        ess[0] = a;
        ess[1] = b;
        ess[2] = c;
    }
};
int main()
{
    Class *cs = new Class[10];
    cs[0].update(5,8,6);
    cs[1].update(1, 4, 5);
    cs[2].update(4, 3, 7);
    cs[3].update(3, 9, 6);
    cs[4].update(2, 5, 8);
    cs[5].update(5, 6, 9);
    cs[6].update(6, 7, 10);
    cs[7].update(7, 8, 1);
    cs[8].update(8, 9, 2);
    cs[9].update(9, 3, 1);
    Exam *es = new Exam[10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            es[(cs[i].ess[j])-1].css.push_back(i);
        }
    }
    vector<vector<int>> calendar(10,vector<int>(10,-1));
    for(int i=0;i<10;i++)//课
    {
        for(int j=0;j<10;j++)//时间
        {
            int flag=0;
            for(int k=0;k<es[i].css.size();k++)
            {
                if(calendar[j][es[i].css[k]]!=-1)
                {
                    flag++;
                    break;
                }
            }
            if(flag==0)
            {
                for(int k=0;k<es[i].css.size();k++)
                {
                    calendar[j][es[i].css[k]]=i+1;
                }
                break;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<calendar[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}