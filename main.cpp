#include "arithmetic_operators.h"



int main()
{
    arithmetic_operators opers;
    //std::cout << int('.') << std::endl;
    std::string a = "0.00000000000";
    std::string b = "0.000000000000000";
    std::cout << opers.add(a,b);
    return 0;
}
