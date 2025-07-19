#include <iostream>
#include <vector>
#include "Arg_Parser.hpp"
#include "GTFS_Handler.hpp"


int main(int argc, char *argv[]) {
    Arg_Parser arguments;

    if(argc != 1) 
    {
        arguments = Parse_arguments(argc, argv);
        if(arguments.input_file.empty())
        {
            std::cerr << "ERROR: Please input a Zip file" << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "ERROR: GTFS Zip file required" << std::endl;
        return 1;
    }

    std::cout << "input folder: " << arguments.input_file << std::endl << "custom query: " << arguments.custom_query << std::endl 
    << "output location: " << arguments.output_location << std::endl << "export db: " << arguments.export_db << std::endl;

    return 0;
}
 