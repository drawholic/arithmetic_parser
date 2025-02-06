#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP

class AbstractExpression
{
public:
	virtual int interpret() const;
	virtual ~AbstractExpression(){};
	virtual void print();
};

#endif