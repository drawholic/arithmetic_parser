#include "Terminal.hpp"

Terminal::Terminal(int v)
{
	value = v;
}

int Terminal::interpret() const
{
	return value;
};