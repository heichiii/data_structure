#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // 构造函数
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Circular
{
private:
    Node *head;

public:
    // 构造函数
    Circular()
    {
        head = nullptr;
    }
    // 创建循环链表
    void create(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            Node *newNode = new Node(i);
            // 第一个节点
            if (head == nullptr)
            {
                head = newNode;
                head->next = head;
            }
            else
            {
                Node *temp = head;
                // temp不是最后一个节点时，temp后移
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                // temp是最后一个节点时，将新节点插入到最后一个节点后面
                temp->next = newNode;
                newNode->next = head;
            }
        }
    }
    // 密码为m
    void joseph(int m)
    {
        Node *current = head;
        Node *prev = nullptr;
        // 当链表中只有一个节点时，退出循环，输出最后一个节点
        while (current->next != current)
        {
            for (int i = 1; i < m; i++)
            {
                prev = current;
                current = current->next;
            }
            // 输出第m个节点
            prev->next = current->next;
            Node *temp = current;
            current = current->next;
            cout << temp->data << " ";
            delete temp;
        }

        cout << current->data << endl;
        delete current;
    }
};

int main()
{
    int n, k;
    cout << "请输入总人数 n：";
    cin >> n;
    cout << "请输入密码 k：";
    cin >> k;

    Circular cll;
    cll.create(n);
    cll.joseph(k);

    return 0;
}