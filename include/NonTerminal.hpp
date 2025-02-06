#ifndef NON_TERMINAL_HPP
#define NON_TERMINAL_HPP

#include "AbstractExpression.hpp"
#include <cmath>
#include <string>
#include <iostream>

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


	NonTerminal(std::string&);


	/**
	 * Calculates a value of an expression based on an op attribute (might change the type to float with possible type conversion)
	 * 
	 * @return Result of evaluation of an expression 
	 */
	int interpret() const override;

	/***
	 * Calculate value of expression choosing the right operator based on op field.
	 * @param left value returned by left child interpret method.
	 * @param right value returned by right child interpret method.
	 * 
	 * @return result of evaluation
	 */
	int evaluate(int, int) const;

	void print() override;

	~NonTerminal();

};
#endif