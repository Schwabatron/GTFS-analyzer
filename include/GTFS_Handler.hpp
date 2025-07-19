#ifndef GTFS_HANDLER_HPP
#define GTFS_HANDLER_HPP

#include <string>

class GTFS_Handler {
public:
    static bool HandleGTFSZip(const std::string& path_to_zip);
};

#endif