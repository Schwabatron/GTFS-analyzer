
#include <iostream>
#include <string>
#include "Arg_Parser.hpp"
#include "cxxopts.hpp"




Arg_Parser Parse_arguments(int argc, char* argv[])
{
    Arg_Parser result; //parser struct to return 

    try
    {
        cxxopts::Options options("gtfs-analyzer", "CLI tool for GTFS analysis");
        options.add_options()
            ("i,input", "Input File", cxxopts::value<std::string>())
            ("o,output", "Output location", cxxopts::value<std::string>())
            ("query", "Custom query", cxxopts::value<std::string>())
            ("export-db", "Export DB path", cxxopts::value<std::string>())
            ("h,help", "Print usage");

        auto parsed = options.parse(argc, argv);

        if (parsed.count("help"))
        {
            std::cout << options.help() << std::endl;
            exit(0);
        }

        if (parsed.count("input")) result.input_file = parsed["input"].as<std::string>();
        if (parsed.count("output")) result.output_location = parsed["output"].as<std::string>();
        if (parsed.count("query")) result.custom_query = parsed["query"].as<std::string>();
        if (parsed.count("export-db")) result.export_db = parsed["export-db"].as<std::string>();
    } 
    catch (const cxxopts::OptionException& e)
    {
        std::cerr << "Error Parsing Options: " << e.what() << std::endl;
        exit(1);
    }


    return result;
    
}

