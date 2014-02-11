#include "options.h"

#include <iostream>
#include <boost/program_options/parsers.hpp>

using namespace std;
using namespace z_pack;

namespace po = boost::program_options;

Options::Options(int argc, char* argv[])
{
    description_.add_options()
        (kHelp.c_str(), "produce help message")
        (kInFile.c_str(), po::value<string>(), "input file name")
        (kOutFile.c_str(), po::value<string>(), "output file name")
		(kUnzip.c_str(), "unzip the archive");

    try
    {
        po::store(po::parse_command_line(argc, argv, description_),
                  options_);
    }
    catch(...)
    {
        cout << GetDescription() << "\n";
		exit(1);
    }
}

string Options::GetString(string option_name)
{
    if ( options_.count(option_name) == 0 )
        return string();

    return options_[option_name].as<string>();
}

bool Options::IsComplete()
{
    if ( options_.count(kHelp) != 0 )
        return false;

    if ( GetString(kInFile).empty() )
        return false;

    if ( GetString(kOutFile).empty() )
        return false;

    return true;
}

bool Options::IsUnzip()
{
    if ( options_.count(kUnzip) != 0 )
        return true;
	else
		return false;
}

po::options_description& Options::GetDescription()
{
    return description_;
}
