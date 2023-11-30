#include <iostream>
#include <string>

class Mid_expression
{
private:
    std::string exp;
    long long cal(long long a, long long b, char op);
    bool is_operator(char op);
    int priority(char op);

public:
    Mid_expression(std::string str);
    long long calculate(void);
};
class Pre_expression
{
private:
    std::string exp;
    long long cal(long long a, long long b, char op);
    bool is_operator(char op);
    int priority(char op);

public:
    Pre_expression(std::string str);
    long long calculate(void);
};
class Post_expression
{
private:
    std::string exp;
    long long cal(long long a, long long b, char op);
    bool is_operator(char op);
    int priority(char op);

public:
    Post_expression(std::string str);
    long long calculate(void);
};
