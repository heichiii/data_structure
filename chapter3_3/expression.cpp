#include "expression.h"
#include <string>
#include <stack>
#include <list>
#include <iostream>
Mid_expression::Mid_expression(std::string str)
{
    exp = str;
}
long long Mid_expression::calculate(void)
{
    std::stack<long long> num;
    std::list<int> temp;
    std::stack<char> op;
    int count = 0;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            op.push(exp[i]);
        }
        else if (isdigit(exp[i]))
        {
            temp.push_back(exp[i] - '0');
            if (!isdigit(exp[i + 1]))
            {
                long long sum = 0;
                while (!temp.empty())
                {
                    sum = sum * 10 + temp.front();
                    temp.pop_front();
                }
                num.push(sum);
            }
        }
        else if (exp[i] == ')')
        {
            while (op.top() != '(')
            {
                long long b = num.top();
                num.pop();
                long long a = num.top();
                num.pop();
                num.push(cal(a, b, op.top()));
                op.pop();
            }
            op.pop();
        }
        else if (is_operator(exp[i]))
        {
            while (!op.empty() && op.top() != '(' && priority(op.top()) >= priority(exp[i]))
            {
                long long b = num.top();
                num.pop();
                long long a = num.top();
                num.pop();
                num.push(cal(a, b, op.top()));
                op.pop();
            }
            op.push(exp[i]);
        }
    }
    while (!op.empty())
    {
        long long b = num.top();
        num.pop();
        long long a = num.top();
        num.pop();
        num.push(cal(a, b, op.top()));
        op.pop();
    }
    return num.top();
}
int Mid_expression::priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return 0;
}
bool Mid_expression::is_operator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
        return true;
    else
        return false;
}
long long Mid_expression::cal(long long a, long long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            std::cout << "Divided by zero!" << std::endl;
            exit(1);
        }
        return a / b;
    case '%':
        if (b == 0)
        {
            std::cout << "Divided by zero!" << std::endl;
            exit(1);
        }
        return a % b;
    default:
        std::cout << "Invalid operator!" << std::endl;
        return 2;
    }
}
