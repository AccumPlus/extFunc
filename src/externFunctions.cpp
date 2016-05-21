#include "externFunctions.h"

std::vector<std::string> split (const std::string temp, const char separator)
{
    std::vector<std::string> res;

    int pos = 0;
    int size = 0;
    while ((size = temp.find (separator, pos)) != std::string::npos)
    {
        size = size - pos;
        res.push_back(temp.substr(pos, size));
        pos = pos + size + 1;
    }
    size = temp.length();
    size -= pos;
    res.push_back(temp.substr(pos, size));
    return res;
}

std::string get_curdate()
{
    time_t tp = time(NULL);
    struct tm *_tm = localtime(&tp);
    char dt[30];
    strftime(dt, 30, "%d%m%Y-%H%M%S", _tm);
    return std::string(dt);
}
