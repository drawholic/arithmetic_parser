#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP

class AbstractExpression
{
public:
	virtual int interpret() = 0;
	virtual ~AbstractExpression(){};
};

#endif