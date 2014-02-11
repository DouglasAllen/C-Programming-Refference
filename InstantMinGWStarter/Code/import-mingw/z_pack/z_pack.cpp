#include <iostream>

#include "options.h"
#include "packer.h"

using namespace std;
using namespace z_pack;

int main(int argc, char* argv[])
{
	Options options(argc, argv);

    if ( ! options.IsComplete() )
    {
        cout << options.GetDescription() << "\n";
        return 1;
    }

	if ( options.IsUnzip() )
		Packer::Decompress(options.GetString(kInFile), options.GetString(kOutFile));
	else
		Packer::Compress(options.GetString(kInFile), options.GetString(kOutFile));

	return 0;
}

