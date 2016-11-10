#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;

namespace z_pack
{

static const std::string kHelp = "help";
static const std::string kInFile = "in";
static const std::string kOutFile = "out";
static const std::string kUnzip = "unzip";

class Options
{
public:
    Options(int argc, char* argv[]);

	std::string GetString(std::string option_name);
	po::options_description& GetDescription();
	bool IsUnzip();
	bool IsComplete();

private:
    po::variables_map options_;
    po::options_description description_;
};

}

#endif