#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <string>

class expression
{
public:
    std::string exp;
    long long cal(long long a, long long b, char op);
    bool is_operator(char op);
    int priority(char op);
};

class Mid_expression : public expression
{
public:
    long long calculate(void);
    void trans_pre(std::string &pre_exp);
    void trans_post(std::string &post_exp);
    Mid_expression(std::string str)
    {
        exp = str;
    }
};

class Pre_expression : public expression
{
public:
    long long calculate(void);
    Pre_expression(std::string str)
    {
        exp = str;
    }
};

class Post_expression : public expression
{
public:
    long long calculate(void);
    Post_expression(std::string str)
    {
        exp = str;
    }
};
#endif
