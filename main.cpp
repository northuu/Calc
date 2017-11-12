#include "arithmetic_operators.h"



int main()
{
    arithmetic_operators opers;
    //std::cout << int('.') << std::endl;
    std::string a = "1111111111111111111111.11111111111111111111";
    std::string b = "0.9999999999999999999999999";
    std::cout << opers.add(a,b);
    return 0;
}
