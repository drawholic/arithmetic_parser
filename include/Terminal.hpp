#include "AbstractExpression.hpp"
#include <iostream>

class Terminal: public AbstractExpression
{
	int value;
public:
	Terminal(int);
	~Terminal();
	int interpret() const override ;
	void print() override;
};