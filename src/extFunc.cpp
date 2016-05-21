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

extern "C" std::string get_curdate()
{
    time_t tp = time(NULL);
    struct tm *_tm = localtime(&tp);
    char dt[30];
    strftime(dt, 30, "%d%m%Y-%H%M%S", _tm);
    return std::string(dt);
}
