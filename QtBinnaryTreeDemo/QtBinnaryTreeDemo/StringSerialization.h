#pragma once
#ifndef __STRING_SERIALIZATION__
#define __STRING_SERIALIZATION__
#include <iostream>
#include <sstream>


template<typename T>
std::string toString(T const& t)
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}


#endif
