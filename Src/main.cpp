#include <iostream>
#include <vector>
#include "../Include/Parser.hpp"


int main(int argc, char *argv[]) {
    if(argc != 1){ //there are arguments passed 
        std::vector<std::string> arguments_passed(argv + 1, argv + argc);
        Parser arguments = Parse_arguments(arguments_passed);
    }








    return 0;
}
 