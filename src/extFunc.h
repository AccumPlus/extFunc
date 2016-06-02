#ifndef EXTERNFUNCTIONS_H
#define EXTERNFUNCTIONS_H

#include <string>
#include <list>
#include <vector>
#include <ctime>

extern "C" std::vector<std::string> split (const std::string &temp, const char &separator);

extern "C" std::string get_curdate(const std::string& format = "%d%m%Y-%H%M%S");

extern "C" std::string unicodeToLower(const std::string &str);

extern "C" std::string unicodeToUpper(const std::string &str);

#endif
