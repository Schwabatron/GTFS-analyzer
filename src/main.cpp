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
    
    GTFS_Handler handler;

    std::string db_path = (arguments.export_db.empty()) ? ":memory:" : arguments.export_db;

    handler.processGTFSFolderToDB(arguments.input_file, db_path);


    return 0;
}
 