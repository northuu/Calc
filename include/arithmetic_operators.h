#ifndef ARITHMETIC_OPERATORS_H
#define ARITHMETIC_OPERATORS_H
#include <iostream>

class arithmetic_operators
{
    public:
        arithmetic_operators();
        virtual ~arithmetic_operators();
        std::string add_int(std::string a, std::string b);
        std::string add(std::string a, std::string b);

    protected:

    private:

        bool check_number_int(std::string a);
        int find_dot(std::string a);
        bool check_number(std::string a);
        std::string flip(std::string a);
};

#endif // ARITHMETIC_OPERATORS_H
