#include "AbstractExpression.hpp"


class Terminal: public AbstractExpression
{
	int value;
public:
	Terminal(int);
	int interpret() override const;
};