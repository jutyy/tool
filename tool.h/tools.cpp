


#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

#include <stdio.h>
#include <math.h>


using namespace std;

//string ToHexString(char* buf, size_t len, std::string separator)
//{
//	std::string str;
//
//	char tmp[3];
//	for (size_t i = 0; i < len; i++)
//	{
//		sprintf(tmp, "%.2x", (unsigned char)buf[i]);
//		str.append(tmp, 2);
//		str.append(separator);
//	}
//	return str;
//}

std::string binToHex(const unsigned char *data, size_t size)
{
	std::ostringstream strHex;
	strHex << std::hex << std::setfill('0');
	for (size_t i = 0; i < size; ++i) {
		strHex << std::setw(2) << static_cast<unsigned int>(data[i]);
	}
	return strHex.str();
}

std::vector<unsigned char> hexToBin(const std::string &hex)
{
	std::vector<unsigned char> dest;
	auto len = hex.size();
	dest.reserve(len / 2);
	for (decltype(len) i = 0; i < len; i += 2)
	{
		unsigned int element;
		std::istringstream strHex(hex.substr(i, 2));
		strHex >> std::hex >> element;
		dest.push_back(static_cast<unsigned char>(element));
	}
	return dest;
}
std::string hexStringToUnsignedInt(const std::string &hex)
{
	std::vector<unsigned char> dest;
	unsigned int intda;
	auto len = hex.size();
	dest.reserve(len / 2);
	for (decltype(len) i = 0; i < len; i += 2)
	{
		unsigned int element;
		std::istringstream strHex(hex.substr(i, 2));
		strHex >> std::hex >> element;
		dest.push_back(static_cast<unsigned char>(element));
	}
	intda = dest[3]; intda <<= 8; intda |= dest[2]; intda <<= 8; intda |= dest[1]; intda <<= 8; intda |= dest[0];
	return to_string(intda);
}

int main()
{
	std::string iccard1 = "87FA368D"; //2369190535
	std::string iccard2 = "2F213844"; //1144529119
	std::string intcard1 = "2369190535";
	std::string intcard2 = "1144529199";

	vector<unsigned char> dat = hexToBin(iccard1);
	unsigned int intda;
	intda = dat[3]; intda <<= 8;
	intda |= dat[2]; intda <<= 8;
	intda |= dat[1]; intda <<= 8;
	intda |= dat[0];
	string sintda = to_string(intda);
	string sing = hexStringToUnsignedInt(iccard2);
	if (intcard2 == sing)printf("\n icok");

	if (sintda == intcard1)printf("\n ok");
	//int intda = dat[0] << 24 + dat[1] << 16 + dat[2] << 8 + dat[3];
	printf("\n intdat =%d,%s", intda, sintda);
	while (1)
	{


	}
	return 1;
}