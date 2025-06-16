#include "Include/Parser.hpp"
#include <iostream>



Parser Parse_arguments(const std::vector<std::string>& arguments)
{
    Parser result; //parser struct to return 

    for (size_t i = 0; i < arguments.size(); ++i) {
        const std::string& arg = arguments[i];

        if (arg == "-i" && i + 1 < arguments.size()) {
            result.input_file = arguments[i + 1];
            ++i; // skip value
        } else if (arg == "-o" && i + 1 < arguments.size()) {
            result.output_location = arguments[i + 1];
            ++i;
        } else if (arg == "--query" && i + 1 < arguments.size()) {
            result.custom_query = arguments[i + 1];
            ++i;
        } else if (arg == "--export-db" && i + 1 < arguments.size()) {
            result.export_db = arguments[i + 1];
            ++i;
        } else {
            std::cerr << "Unknown or incomplete flag: " << arg << std::endl;
        }
    }
    return result;
    
}

