#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "AbstractExpression.hpp"
#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;
typedef std::string::iterator str_iter;

class Scanner
{
	std::string buffer;
	vec_str str_tokens;
	str_iter get_number_end(str_iter, str_iter);

public:
	Scanner(std::string& buf);
	void remove_whitespaces();
	void split_tokens();
};


#endif