#ifndef GTFS_HANDLER_HPP
#define GTFS_HANDLER_HPP

#include <string>
#include "sqlite3.h"

sqlite3* processGTFSFolderToDB(const std::string& path_to_folder, const std::string& db_path);

#endif