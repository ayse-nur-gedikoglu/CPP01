#include <string>
#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";

    //stringPTR: a pointer to the string.
    std::string *stringPTR = &str;
    //stringREF: a reference to the string.
    std::string &stringREF = str;

    std::cout<< "The memory address of the string variable: " << &str << std::endl;
    std::cout<< "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout<< "The memory address held by stringREF: " << &stringREF << std::endl;

    std::cout<< "The value of the string variable: " << str << std::endl;
    std::cout<< "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout<< "The value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
