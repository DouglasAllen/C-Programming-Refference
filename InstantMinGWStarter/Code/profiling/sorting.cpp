#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<char> gData;

void ReadData()
{
	ifstream in_file("source.txt", ios::in | ios::binary);
	
	copy(istream_iterator<char>(in_file), istream_iterator<char>(), 
		 back_inserter(gData));
}

void SortData()
{
  char temp;
  size_t size = gData.size();
 
  for (int i = (size - 1); i > 0; i--)
  {
    for (int j = 1; j <= i; j++)
    {
		if (gData[j-1] > gData[j])
		{
			temp = gData[j-1];
			gData[j-1] = gData[j];
			gData[j] = temp;
		}
    }
  }
}

void WriteResult()
{
	ofstream out_file("result.txt", ios::out | ios::binary);
	out_file.write(&gData[0], gData.size());
}

int main()
{
	ReadData();
	
	SortData();
	
	WriteResult();
	
	return 0;
}
