#ifndef NON_TERMINAL_HPP
#define NON_TERMINAL_HPP

#include "AbstractExpression.hpp"


enum Operator
{
	ADD,
	SUB,
	DIV,
	POW,
	MUL,
	NEG
};

/**
 * Class for NonTerminal term in an expression.
 */
class NonTerminal: public AbstractExpression
{

	AbstractExpression* left;
	AbstractExpression* right;
	Operator op;

public:
	/**
	 * Constructor with children nodes and operator type
	 * 
	 * @param _left Node to represent a left in an expression
	 * @param _right Node to represent a right in an expression 
	 * @param _op Operator to define an operation on children nodes. Might be unary negate so null left child is provided 
	 */
	NonTerminal(AbstractExpression*, AbstractExpression*, Operator);

	/**
	 * Calculates a value of an expression based on an op attribute (might change the type to float with possible type conversion)
	 * 
	 * @return Result of evaluation of an expression 
	 */
	int interpret() override;
}
#endif