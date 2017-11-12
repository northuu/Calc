#include "arithmetic_operators.h"



int main()
{
    arithmetic_operators opers;
    //std::cout << int('.') << std::endl;
    std::string a = "9065456456.10000000000";
    std::string b = "945634233478760.2230000000000000000";
    std::cout << a << " + " << b << " = " << opers.add(a,b);
    return 0;
}
