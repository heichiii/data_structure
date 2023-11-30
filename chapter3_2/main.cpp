#include <iostream>
#include <string>
#include "expression.h"
#include <list>
#include <stack>
int main()
{
    std::cout << "Please input the expression: ";
    std::string s;
    std::cin >> s;
    Mid_expression mid(s);
    std::cout << mid.calculate() << std::endl;
    return 0;
}