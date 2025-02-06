#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "AbstractExpression.hpp"
#include "NonTerminal.hpp"
#include "Terminal.hpp"
#include <algorithm>
#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;
typedef std::string::iterator str_iter;
typedef std::vector<AbstractExpression*> v_tokens;

class Scanner
{
	std::string buffer;
	vec_str str_tokens;
	v_tokens tokens;
	str_iter get_number_end(str_iter, str_iter);
	void convert_to_tokens();
	void print_tokens();

public:
	Scanner(std::string& buf);
	void remove_whitespaces();
	void split_tokens();
};


#endif