#ifndef PACKER_H
#define PACKER_H

#include <string>

namespace z_pack
{

class Packer
{
public:
	static void Compress(std::string in_file, std::string out_file);
	static void Decompress(std::string in_file, std::string out_file);
};

}

#endif