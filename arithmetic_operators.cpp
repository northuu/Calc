#include "arithmetic_operators.h"

arithmetic_operators::arithmetic_operators()
{
    //ctor
}

arithmetic_operators::~arithmetic_operators()
{
    //dtor
}

std::string arithmetic_operators::add_int(std::string a, std::string b)
{
    int length;
    int leftover = 0;
    std::string c; //c will be flipped, so it has to be flipped back before return
    if(!check_number_int(a) or !check_number_int(b))
    {
        std::cout << "One of the strings can't be converted to integer, it contains illegal characters";
        return "error";
    }
    if(a.size() >= b.size())
    {
        length = a.size();
    }
    else
    {
        length = b.size();
    }
    a = flip(a);
    b = flip(b);
    for(int i = 0; i < length; i++)
    {
        int int_a = int(a[i]) - 48;
        int int_b = int(b[i]) - 48;
        int int_c = leftover;
        if(int_a < 0 or int_a > 9)
        {
            int_a = 0;
        }
        if(int_b < 0 or int_b > 9)
        {
            int_b = 0;
        }
        int_c += int_a + int_b;

        leftover = 0;
        while(int_c > 9)
        {
            int_c -= 10;
            leftover += 1;
        }
        //std::cout << int_a << " + " << int_b << " = " << int_c << std::endl;
        c.push_back(static_cast<char>(int_c + 48));
        if(i == length - 1 && leftover > 0)
        {
            c.push_back(static_cast<char>(leftover + 48));
        }
    }
    return flip(c);
}

std::string arithmetic_operators::add(std::string a, std::string b)
{
    int a_dot = find_dot(a);
    int b_dot = find_dot(b);
    std::string a_left, a_right, b_left, b_right;
    //prepare for addition - phase 1 (converting to "float")
    if(a_dot == a.size() && b_dot == b.size())
        return add_int(a,b);
    else if(a_dot == a.size() && b_dot < b.size())
    {
        a.push_back('.');
        a.push_back('0');
    }
    else if(a_dot < a.size() && b_dot == b.size())
    {
        b.push_back('.');
        b.push_back('0');
    }
    //prepare for addition - phase 2 (dividing into 2 parts)
    for (int i = 0; i<a_dot; i++)
    {
        a_left.push_back(a[i]);
    }
    for(int i = a_dot + 1; i < a.size(); i++)
    {
        a_right.push_back(a[i]);
    }
    for (int i = 0; i<b_dot; i++)
    {
        b_left.push_back(b[i]);
    }
    for(int i = b_dot + 1; i < b.size(); i++)
    {
        b_right.push_back(b[i]);
    }
    //if parts are not integers, there is an error
    if(!check_number_int(a_left) or !check_number_int(a_right) or !check_number_int(b_left) or !check_number_int(b_right))
    {
        std::cout << "Some parts of the numbers are not integers, can't convert.";
        return "Error";
    }
    //prepare for addition - phase 3 (normalizing size of the right parts)
    int a_right_size = a_right.size();
    int b_right_size = b_right.size();
    if(a_right_size >= b_right_size)
    {
        for(int i=b_right_size; i< a_right_size;i++)
        {
            b_right.push_back('0');
        }
    }
    else
    {
        for(int i=a_right_size; i< b_right_size;i++)
        {
            a_right.push_back('0');
        }
    }
    //actual addition
    std::string c, c_left, c_right;
    c_left = add_int(a_left, b_left);
    c_right = add_int(a_right, b_right);

    //deleting unnecessary zeros from the tail
    while(c_right[c_right.size()-1] == '0' && c_right.size() != 1)
    {
        c_right.pop_back();
    }
    //if sum of the tails >= 1, then add one to int part and delete 1 from the beginning of the tail
    if(c_right.size() > a_right.size())
    {
        std::string c_right2;
        c_left = add_int(c_left, "1");
        for(int i=1; i<c_right.size();i++)
        {
            c_right2.push_back(c_right[i]);
        }
        return c_left + '.' + c_right2;
    }
    return c_left + '.' + c_right;
}


bool arithmetic_operators::check_number(std::string a)
{
    for(int i = 0; i< a.size(); i++)
    {
        if( (int(a[i]) < 48 or int(a[i]) > 57) and (int(a[i] != 46)))
        {
            return 0;
        }
    }
    return 1;
}

bool arithmetic_operators::check_number_int(std::string a)
{
    for(int i = 0; i< a.size(); i++)
    {
        if(int(a[i]) < 48 or int(a[i]) > 57)
        {
            return 0;
        }
    }
    return 1;
}

std::string arithmetic_operators::flip(std::string a)
{
    std::string b = a;
    if(a.size() == 0)
    {
        return a;
    }
    for(int i = 0;i < a.size();i++)
    {
        b[i] = a[a.size() - i - 1];
    }
    return b;
}

int arithmetic_operators::find_dot(std::string a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i] == '.')
        {
            return i;
        }
    }
    return a.size();
}
