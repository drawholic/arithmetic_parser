#include "AbstractExpression.hpp"


class Terminal: public AbstractExpression
{
	int value;
public:
	Terminal(int);
	~Terminal();
	int interpret() const override ;
};