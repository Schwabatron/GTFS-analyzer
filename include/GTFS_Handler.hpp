#ifndef GTFS_HANDLER_HPP
#define GTFS_HANDLER_HPP

#include <string>

class GTFS_Handler {
public:
    static bool processGTFSFolderToDB(const std::string& path_to_folder, const std::string& db_path);

};

#endif