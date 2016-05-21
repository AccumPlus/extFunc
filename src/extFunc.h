#ifndef EXTERNFUNCTIONS_H
#define EXTERNFUNCTIONS_H

#include <string>
#include <list>
#include <vector>
#include <ctime>

extern "C" std::vector<std::string> split (const std::string &temp, const char &separator);

extern "C" std::string get_curdate();

#endif
