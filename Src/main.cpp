#include <iostream>
#include <vector>
#include "../Include/Parser.hpp"


int main(int argc, char *argv[]) {
    //Checking if there are no command line arguments  (valid but will not be calling the parse function)
    if(argc == 1){ //there are no arguments passed 
        std::cout << "No command line arguments passed" << std::endl; 
    } else{ // There are arguments passed call to parsing function
        std::cout << "Call to the parse function to get arguments" << std::endl;
        std::vector<std::string> arguments_passed(argv + 1, argv + argc);
        Parser arguments = Parse_arguments(arguments_passed);
    }








    return 0;
}
 