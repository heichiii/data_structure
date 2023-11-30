#include <iostream>
#include <string>
#include <list>
#include <stack>
#include "expression.h"
#include <algorithm>
int main()
{
    std::cout << "Please input the expression: ";
    std::string s;
    std::cin >> s;
    std::cout << s << std::endl;
    s[s.length()] = 0;
    Mid_expression mid(s);
    std::cout << mid.calculate() << std::endl;
    std::string s1{};
    std::string s2{};
    std::string &ss1 = s1;
    std::string &ss2 = s2;
    mid.trans_pre(ss1);
    std::reverse(s1.begin(), s1.end());
    mid.trans_post(ss2);
    std::cout << "The prefix expression is: " << s1 << std::endl;
    std::cout << "The postfix expression is: " << s2 << std::endl;
    Pre_expression pre(s1);
    std::cout << "The result of prefix expression is: " << pre.calculate() << std::endl;
    Post_expression post(s2);
    std::cout << "The result of postfix expression is: " << post.calculate() << std::endl;

    return 0;
}