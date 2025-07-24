#include <iostream>
#include <vector>

#include "GTFS_makeTables.hpp"


int create_gtfs_tables(sqlite3* db)
{
    //given these GTFS files follow a standardized format inside their csvs it is safe to hardcode the essential 7 files 
    const std::vector<std::string> schemas = {
        R"(CREATE TABLE agency (
            agency_id TEXT,
            agency_name TEXT,
            agency_url TEXT,
            agency_timezone TEXT,
            agency_lang TEXT,
            agency_phone TEXT,
            agency_fare_url TEXT,
            agency_email TEXT
        );)",

        R"(CREATE TABLE routes (
            route_id TEXT,
            agency_id TEXT,
            route_short_name TEXT,
            route_long_name TEXT,
            route_desc TEXT,
            route_type INTEGER,
            route_url TEXT,
            route_color TEXT,
            route_text_color TEXT,
            route_sort_order INTEGER
        );)",

        R"(CREATE TABLE trips (
            route_id TEXT,
            service_id TEXT,
            trip_id TEXT,
            trip_headsign TEXT,
            direction_id INTEGER,
            shape_id TEXT,
            wheelchair_accessible INTEGER,
            bikes_allowed INTEGER
        );)",

        R"(CREATE TABLE stops (
            stop_id TEXT,
            stop_code TEXT,
            stop_name TEXT,
            stop_desc TEXT,
            stop_lat REAL,
            stop_lon REAL,
            zone_id INTEGER,
            stop_url TEXT,
            location_type INTEGER,
            stop_timezone TEXT,
            wheelchair_boarding INTEGER,
            stp_has_shelter INTEGER
        );)",

        R"(CREATE TABLE stop_times (
            trip_id TEXT,
            arrival_time TEXT,
            departure_time TEXT,
            stop_id TEXT,
            stop_sequence INTEGER,
            stop_headsign TEXT,
            pickup_type INTEGER,
            drop_off_type INTEGER,
            shape_dist_traveled REAL,
            timepoint INTEGER
        );)",

        R"(CREATE TABLE calendar (
            service_id TEXT,
            monday INTEGER,
            tuesday INTEGER,
            wednesday INTEGER,
            thursday INTEGER,
            friday INTEGER,
            saturday INTEGER,
            sunday INTEGER,
            start_date TEXT,
            end_date TEXT
        );)",

        R"(CREATE TABLE calendar_dates (
            service_id TEXT,
            date TEXT,
            exception_type INTEGER
        );)"
    };

    try
    {
       for(const auto& sql : schemas)
        {
            char* error;
            int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error);
            if(rc != SQLITE_OK)
            {
                std::cerr << "failed to create table: " << error << std::endl;
                sqlite3_free(error);
                return 1;
            }
        } 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}