#include "packer.h"

#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>

using namespace std;
using namespace z_pack;

namespace io = boost::iostreams;

void Packer::Compress(string in_file, string out_file)
{
	io::filtering_ostreambuf out;
	out.push(io::zlib_compressor());
	out.push(io::file_sink(out_file.c_str(), ios::binary));
	io::copy(io::file_source(in_file.c_str(), ios::binary), out);
}

void Packer::Decompress(std::string in_file, std::string out_file)
{
	io::filtering_istreambuf in;
	in.push(io::zlib_decompressor());
	in.push(io::file_source(in_file.c_str(), ios::binary));
	io::copy(in, io::file_sink(out_file.c_str(), ios::binary));
}
