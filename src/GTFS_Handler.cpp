#include <iostream>
#include <filesystem>
#include "GTFS_Handler.hpp"
#include "GTFS_makeTables.hpp"
#include "GTFS_parseCSV.hpp"
#include "sqlite3.h"

static sqlite3* createDB(const std::string& db_path);

sqlite3* processGTFSFolderToDB(const std::string& path_to_folder, const std::string& db_path) {

    sqlite3* db = createDB(db_path);

    std::cout << "Handling GTFS folder at: " << path_to_folder << std::endl;

    if(db == nullptr)
    {
        std::cerr << "failed to connect to SQLite database" << std::endl;
        return nullptr;
    }
    
    std::cout << "Database path: " << db_path << std::endl; 

    
    if(create_gtfs_tables(db) != 0) return nullptr; //call gtfs make tables
    if(parse_gtfs_files(path_to_folder, db) != 0) return nullptr; //call parsecsv
    
    
    return db; //pass the connection back to main to have the data worked with 
}


static sqlite3* createDB(const std::string& db_path) {
    sqlite3* db;

    if(db_path != ":memory:")//if the db will NOT be stored in RAM
    {
        //This code checks if the parent path exists for the GTFS db file to be placed in. if it does not exist it will create it
        std::filesystem::path parent_directory = std::filesystem::path(db_path).parent_path();
        if(!std::filesystem::exists(parent_directory))
        {
            std::filesystem::create_directories(parent_directory);
        }
    }

    int rc = sqlite3_open(db_path.c_str(), &db);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }

    std::cout << "Database opened successfully." << std::endl;
    return db;
}

