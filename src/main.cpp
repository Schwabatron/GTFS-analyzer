#include <iostream>
#include <vector>
#include "../Include/Parser.hpp"


int main(int argc, char *argv[]) {
    std::vector<std::string> arguments_passed;
    Parser arguments;

    if(argc != 1){ //there are arguments passed 
        arguments_passed = std::vector<std::string>(argv + 1, argv + argc);
        arguments = Parse_arguments(arguments_passed);
    }

    

  








    return 0;
}
 