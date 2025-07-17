#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <string>
#include <vector>

struct Arg_Parser
{
    std::string input_file;
    std::string output_location;
    std::string custom_query;
    std::string export_db;
};


Arg_Parser Parse_arguments(const std::vector<std::string>& args);


#endif
