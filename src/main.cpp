#include <iostream>
#include <vector>
#include "Arg_Parser.hpp"


int main(int argc, char *argv[]) {
    std::vector<std::string> arguments_passed;
    Arg_Parser arguments;

    if(argc != 1){ //there are arguments passed 
        arguments_passed = std::vector<std::string>(argv + 1, argv + argc);
        arguments = Parse_arguments(arguments_passed);
    }

    std::cout << "parsed arguments: " << arguments.custom_query << " " << arguments.export_db << " " << arguments.input_file << " " << arguments.output_location << std::endl;

    

  








    return 0;
}
 