#include "extFunc.h"

extern "C" std::vector<std::string> split(const std::string &str, const char &delim)
{
	std::vector<std::string> res;
	
	int pos = 0;
	int size = 0;
	while ((size = str.find(delim, pos)) != std::string::npos)
	{
		size = size - pos;
		res.push_back(str.substr(pos, size));
		pos = pos + size + 1;
	}

	size = str.length();
	size -= pos;
	res.push_back(str.substr(pos, size));
	return res;
}

extern "C" std::string get_curdate(const std::string& format)
{
    time_t tp = time(NULL);
    struct tm *_tm = localtime(&tp);
    char dt[30];
    strftime(dt, 30, format.c_str(), _tm);
    return std::string(dt);
}

extern "C" std::string unicodeToLower(const std::string &str)
{
	std::string rString = str;
	unsigned short i = 0;
	while (i < str.length())
	{
		if ((unsigned short)str[i] == 0xffd0) // Русские буквы и некоторые символы
		{
			unsigned short s;
			s = (unsigned short)((unsigned short)str[i] << 8) | ((unsigned short)str[i+1] & 0x00FF );

			if (s >= 0xd090 && s <= 0xd095 || s >= 0xd096 && s <= 0xd09f) // А - Е и Ж - П
			{
				rString[i] = str[i];
				rString[i+1] = str[i+1] + 0x20;
			}
			else if (s >= 0xd0a0 && s <= 0xd0af) // Р - Я
			{
				rString[i] = str[i] + 0x01;
				rString[i+1] = str[i+1] + 0xe0;
			}
			else if (s == 0xd081) // Ё
			{
				rString[i] = str[i] + 0x01;
				rString[i+1] = str[i+1] + 0x10;
			}

			++i;
		}
		else if (str[i] >= 0x41 && str[i] <= 0x5a) // Английские буквы
		{
			rString[i] = str[i] + 0x20;
		}
		++i;
	}

	return rString;
}

extern "C" std::string unicodeToUpper(const std::string &str)
{
	std::string rString = str;
	unsigned short i = 0;
	while (i < str.length())
	{
		if ((unsigned short)str[i] == 0xffd0 || (unsigned short)str[i] == 0xffd1) // Русские буквы и некоторые символы
		{
			unsigned short s;
			s = (unsigned short)((unsigned short)str[i] << 8) | ((unsigned short)str[i+1] & 0x00FF );

			if (s >= 0xd0b0 && s <= 0xd0b5 || s >= 0xd0b6 && s <= 0xd0bf) // а - е и ж - п
			{
				rString[i] = str[i];
				rString[i+1] = str[i+1] - 0x20;
			}
			else if (s >= 0xd180 && s <= 0xd18f) // Р - Я
			{
				rString[i] = str[i] - 0x01;
				rString[i+1] = str[i+1] + 0x20;
			}
			else if (s == 0xd191) // Ё
			{
				rString[i] = str[i] - 0x01;
				rString[i+1] = str[i+1] - 0x10;
			}

			++i;
		}
		else if (str[i] >= 0x61 && str[i] <= 0x7a) // Английские буквы
		{
			rString[i] = str[i] - 0x20;
		}
		++i;
	}

	return rString;
}
