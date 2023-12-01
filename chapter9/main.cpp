#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void Sequential(const vector<int> &arr)
{
    cout << "-----------------Sequential--------------------" << endl;
    int v1 = arr[1], v2 = 0;
    vector<int> index1;
    vector<int> index2;
    index1.push_back(1);
    for (int i = 2; i < 513; i++)
    {
        if (arr[i] > v2)
        {
            if (arr[i] > v1)
            {
                v2 = v1;
                index2 = index1;
                v1 = arr[i];
                index1.clear();
                index1.push_back(i);
            }
            else if (arr[i] == v1)
            {
                index1.push_back(i);
            }
            else
            {
                v2 = arr[i];
                index2.clear();
                index2.push_back(i);
            }
        }
        else if (arr[i] == v2)
        {
            index2.push_back(i);
        }
    }
    cout << "the highest score is " << v1 << endl;
    cout << "The person with the highest score is(are) ";
    for (int i : index1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "the Sub-high score is " << v2 << endl;
    cout << "The person with the Sub-high score is(are) ";
    for (int i : index2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "-----------------Sequential--------------------" << endl;
}
int compare(int a, int b)
{
    return (a > b) ? a : b;
}
void Tournament(const vector<int> &arr)
{
    int v1, v2;
    vector<int> index1, index2;

    int n = arr.size() - 1;
    int treeSize = 2 * n - 1;
    std::vector<int> tournamentTree(treeSize, 0);

    // 将叶节点初始化为数组中的元素
    for (int i = 1; i < n + 1; i++)
    {
        tournamentTree[n - 1 + i - 1] = arr[i];
    }

    // 从最后一个非叶节点开始构建锦标赛树
    for (int i = n - 2; i >= 0; i--)
    {
        tournamentTree[i] = compare(tournamentTree[2 * i + 1], tournamentTree[2 * i + 2]);
    }

    v1 = tournamentTree[0]; // 最大值
    // 删去最大值找次大值
    vector<int> copy = arr;
    for (int i = 1; i < 513; i++)
    {
        if (copy[i] == v1)
        {
            index1.push_back(i);
            copy[i] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        tournamentTree[n - 1 + i - 1] = copy[i];
    }

    // 从最后一个非叶节点开始构建锦标赛树
    for (int i = n - 2; i >= 0; i--)
    {
        tournamentTree[i] = compare(tournamentTree[2 * i + 1], tournamentTree[2 * i + 2]);
    }

    v2 = tournamentTree[0]; // 次大值
    // index
    for (int i = 1; i < 513; i++)
    {
        if (copy[i] == v2)
        {
            index2.push_back(i);
        }
    }
    cout << "------------------Tournament-----------------" << endl;
    cout << "the highest score is " << v1 << endl;
    cout << "The person with the highest score is(are) ";
    for (int i : index1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "the Sub-high score is " << v2 << endl;
    cout << "The person with the Sub-high score is(are) ";
    for (int i : index2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "------------------Tournament-----------------" << endl;
}
void Heap(const vector<int> &arr)
{
    int v1,v2;
    vector<int> index1,index2;
    vector<int> copy;
    for(int i=1;i<513;i++)
    {
        copy.push_back(arr[i]);
    }
    int n=copy.size();
    //建堆(自下向上)
    for(int i=n/2;i>=0;i--)
    {
        if(2*i+1<n)
        {
            if(2*i+2<n)
            {
                if(copy[i]<copy[2*i+2])
                {
                    swap(copy[i],copy[2 * i + 2]);
                }
            }
            if (copy[i] < copy[2 * i + 1])
            {
                swap(copy[i],copy[2 * i + 1]);
            }
        }
    }
    v1=copy[0];
    copy[0]=copy[n-1];
    copy.pop_back();
    n=copy.size();
    //堆调整
    for(int i=n/2;i>=0;i--)
    {
        if(2*i+1<n)
        {
            if(2*i+2<n)
            {
                if(copy[i]<copy[2*i+2])
                {
                    swap(copy[i],copy[2 * i + 2]);
                }
            }
            if (copy[i] < copy[2 * i + 1])
            {
                swap(copy[i],copy[2 * i + 1]);
            }
        }
    }
    v2=copy[0];
    for(int i=1;i<n+2;i++)
    {
        if(arr[i]==v1)
            index1.push_back(i);
        else if(arr[i]==v2)
            index2.push_back(i);
    }

    cout << "-----------------------Heap----------------------" << endl;
    cout << "the highest score is " << v1 << endl;
    cout << "The person with the highest score is(are) ";
    for (int i : index1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "the Sub-high score is " << v2 << endl;
    cout << "The person with the Sub-high score is(are) ";
    for (int i : index2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "-----------------------Heap----------------------" << endl;

}
int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 999);

    // 生成随机数数组
    int arraySize = 513;
    vector<int> randomArray;
    for (int i = 0; i < arraySize; ++i)
    {
        int randomNumber = dis(gen);
        randomArray.push_back(randomNumber);
        if (i == 0)
            continue;
        cout << i << " " << randomArray[i] << endl;
    }
    Sequential(randomArray);
    Tournament(randomArray);
    Heap(randomArray);
    return 0;
}
