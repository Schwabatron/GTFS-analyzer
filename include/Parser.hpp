#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

struct Parser
{
    std::string input_file;
    std::string output_location;
    std::string custom_query;
    std::string export_db;
};


Parser Parse_arguments(const std::vector<std::string>& args);


#endif
