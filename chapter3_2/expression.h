
#include <iostream>
#include <string>

class Mid_expression
{
private:
    std::string exp;
    // Pre_expression pre;
    // Post_expression post;
    long long cal(long long a, long long b, char op);
    bool is_operator(char op);
    int priority(char op);

public:
    Mid_expression(std::string str);
    long long calculate(void);
    // void trans_to_pre(void);
    // void trans_to_post(void);
    // void print_all(void);
};

// class Pre_expression
// {
// private:
//     std::string str;

// public:
//     long long calculate();
// };

// class Post_expression
// {
// private:
//     std::string str;

// public:
//     long long calculate();
// };
