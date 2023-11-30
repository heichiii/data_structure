#include "expression.h"
#include <string>
#include <stack>
#include <list>
#include <iostream>

// expression
int expression::priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return 0;
}
bool expression::is_operator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
        return true;
    else
        return false;
}
long long expression::cal(long long a, long long b, char op)
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
// Mid_expression
long long Mid_expression::calculate(void)
{
    std::stack<long long> num;
    std::list<int> temp;
    std::stack<char> op;
    int count = 0;
    for (int i = 0; i < Mid_expression::exp.length(); i++)
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
void Mid_expression::trans_pre(std::string &pre_exp)
{
    std::stack<char> op;
    std::string temp;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (exp[i] == ')')
        {
            op.push(exp[i]);
        }
        else if (isdigit(exp[i]))
        {
            pre_exp += exp[i];
            // temp += exp[i];
            if (!isdigit(exp[i - 1]))
            {
                // for (int j = temp.length() - 1; j >= 0; j--)
                // {
                //     pre_exp += temp[j];
                // }
                pre_exp += ' ';
                // temp.clear();
            }
        }
        else if (exp[i] == '(')
        {
            while (op.top() != ')')
            {
                pre_exp += op.top();
                op.pop();
            }
            op.pop();
        }
        else if (is_operator(exp[i]))
        {
            while (!op.empty() && op.top() != ')' && priority(op.top()) > priority(exp[i]))
            {
                pre_exp += op.top();
                op.pop();
            }
            op.push(exp[i]);
        }
    }
    while (!op.empty())
    {
        pre_exp += op.top();
        op.pop();
    }
}
void Mid_expression::trans_post(std::string &post_exp)
{
    std::stack<char> op;
    std::string temp;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            op.push(exp[i]);
        }
        else if (isdigit(exp[i]))
        {
            temp += exp[i];
            if (!isdigit(exp[i + 1]))
            {
                post_exp += temp;
                post_exp += ' ';
                temp.clear();
            }
        }
        else if (exp[i] == ')')
        {
            while (op.top() != '(')
            {
                post_exp += op.top();
                op.pop();
            }

            op.pop();
        }
        else if (is_operator(exp[i]))
        {
            while (!op.empty() && op.top() != '(' && priority(op.top()) >= priority(exp[i]))
            {
                post_exp += op.top();
                op.pop();
            }
            op.push(exp[i]);
        }
    }
    while (!op.empty())
    {
        post_exp += op.top();
        op.pop();
    }
}
// Pre_expression
long long Pre_expression::calculate(void)
{
    std::stack<long long> num;
    // std::stack<char> op;
    std::stack<int> temp;
    for (int i = Pre_expression::exp.length() - 1; i >= 0; i--)
    {
        if (isdigit(exp[i]))
        {
            temp.push(exp[i] - '0');
            if (!isdigit(exp[i - 1]))
            {
                long long sum = 0;
                while (!temp.empty())
                {
                    sum = sum * 10 + temp.top();
                    temp.pop();
                }
                long long testt = sum;
                num.push(sum);
                while (!temp.empty())
                {
                    temp.pop();
                }
            }
        }
        else if (is_operator(exp[i]))
        {
            long long a = num.top();
            num.pop();
            long long b = num.top();
            num.pop();

            num.push(cal(a, b, exp[i]));
        }

        else if (exp[i] == ' ')
        {
            continue;
        }
    }
    // while (!op.empty())
    // {
    //     long long a = num.top();
    //     num.pop();
    //     long long b = num.top();
    //     num.pop();
    //     num.push(cal(a, b, op.top()));
    //     op.pop();
    // }

    return num.top();
}
// Post_expression
long long Post_expression::calculate(void)
{
    std::stack<long long> num;
    std::stack<char> op;
    std::list<int> temp;
    for (int i = 0; i < Post_expression::exp.length(); i++)
    {
        if (isdigit(exp[i]))
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
                temp.clear();
            }
        }
        else if (is_operator(exp[i]))
        {
            // if (!op.empty())
            // {
            //     while (!op.empty() && priority(op.top()) >= priority(exp[i]))
            //     {
            //         long long b = num.top();
            //         num.pop();
            //         long long a = num.top();
            //         num.pop();
            //         num.push(cal(a, b, op.top()));
            //         op.pop();
            //     }
            // }
            // op.push(exp[i]);
            long long a = num.top();
            num.pop();
            long long b = num.top();
            num.pop();
            num.push(cal(b, a, exp[i]));
        }
        else if (exp[i] == ' ')
        {
            continue;
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
