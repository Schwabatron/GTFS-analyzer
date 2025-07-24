#include <iostream>
#include <vector>
#include "Arg_Parser.hpp"
#include "GTFS_Handler.hpp"


int main(int argc, char *argv[]) {
    Arg_Parser arguments;

    if(argc != 1) // the user passed more than the program itself as an argument 
    {
        arguments = Parse_arguments(argc, argv); //parse the arguments provided by the user 
        if(arguments.input_file.empty()) 
        {
            std::cerr << "ERROR: Please input a GTFS folder" << std::endl;
            return 1;
        }
    }
    else //no arguments given
    {
        std::cerr << "ERROR: GTFS Folder required" << std::endl;
        return 1;
    }

    std::string db_path = (arguments.export_db.empty()) ? ":memory:" : arguments.export_db; //if the user did not specify an output path save to RAM to be destroyed when the program is over
    sqlite3* db = processGTFSFolderToDB(arguments.input_file, db_path); 
    if (!db) return 1; 

    sqlite3_close(db); //close the db connection 
    return 0;
}
 