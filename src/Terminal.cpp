#include "Terminal.hpp"

Terminal::Terminal(int v)
{
	value = v;
}

int Terminal::interpret() const
{
	return value;
};

Terminal::~Terminal()
{

};

void Terminal::print()
{
	std::cout << "Terminal: " << value << std::endl; 

};