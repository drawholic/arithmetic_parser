#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP

class AbstractExpression
{
public:
	virtual int interpret() const = 0;
	virtual ~AbstractExpression(){};
	virtual void print() = 0;
};

#endif