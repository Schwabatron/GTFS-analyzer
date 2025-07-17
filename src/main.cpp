#include <iostream>
#include <vector>
#include "Arg_Parser.hpp"


int main(int argc, char *argv[]) {
    Arg_Parser arguments;

    if(argc != 1){ //there are arguments passed 
        arguments = Parse_arguments(argc, argv);
    }

    std::cout << "parsed arguments: " << arguments.custom_query << " " << arguments.export_db << " " << arguments.input_file << " " << arguments.output_location << std::endl;

    

  








    return 0;
}
 