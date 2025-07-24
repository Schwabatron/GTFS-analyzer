#ifndef GTFS_PARSECSV_HPP
#define GTFS_PARSECSV_HPP

#include <string>
#include "sqlite3.h"

int parse_gtfs_files(const std::string& path_to_folder, sqlite3* db);

#endif