#include "Scanner.hpp"

Scanner::Scanner(std::string& buf): buffer(buf) {};


void Scanner::remove_whitespaces()
{
	std::string temp(buffer);
	str_iter new_end = std::remove(temp.begin(), temp.end(), ' ');
	buffer.assign(temp.begin(), new_end);
};

str_iter Scanner::get_number_end(str_iter start, str_iter buf_end)
{
	char c = *start;
	while(std::isdigit(c) == 0 && start != buf_end)
	{
		start = std::next(start, 1);
		c = *start;
	};
	return start;
};

void Scanner::split_tokens()
{
	str_iter it = buffer.begin();
	str_iter pend = buffer.end();
	str_iter num_end;
	std::string temp;

	char c;
	while(it != pend)
	{
		c = *it;
		if(std::isdigit(c))
		{
			num_end = get_number_end(it, pend);
			temp.assign(it, num_end);
			str_tokens.push_back(temp);
			it = num_end;
		}else
		{
			temp.assign(it, std::next(it));
			str_tokens.push_back(temp);
			it++;
		};
	};
};

void Scanner::convert_to_tokens()
{
	int temp_num;
	for(auto i : str_tokens)
	{
		if(std::isdigit(i[0]) == 0)
		{
			temp_num = std::stoi(i);
			tokens.push_back(new Terminal(temp_num));
		}else
		{
			tokens.push_back(new NonTerminal(i));
		}
	};
};