#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "GTFS_Handler.hpp"
#include "sqlite3.h"

static sqlite3* createDB(const std::string& db_path);

static int create_table(const std::string& table_name, sqlite3* db);


bool GTFS_Handler::processGTFSFolderToDB(const std::string& path_to_folder, const std::string& db_path) {

    sqlite3* db = createDB(db_path);

    std::cout << "Handling GTFS folder at: " << path_to_folder << std::endl;

    if(db == nullptr)
    {
        std::cerr << "failed to connect to SQLite database" << std::endl;
        return false;
    }
    
    
    std::cout << "Database path: " << db_path << std::endl;

    sqlite3_close(db);
    return true;
}


static sqlite3* createDB(const std::string& db_path) {
    sqlite3* db;

    std::filesystem::path parent_directory = std::filesystem::path(db_path).parent_path();

    if(!std::filesystem::exists(parent_directory))
    {
        std::filesystem::create_directories(parent_directory);
    }

    int rc = sqlite3_open(db_path.c_str(), &db);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }

    std::cout << "Database opened successfully." << std::endl;
    return db;
}

static int create_table(const std::string& table_name, sqlite3* db)
{
    
}