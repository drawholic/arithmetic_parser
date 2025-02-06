#include "NonTerminal.hpp"


NonTerminal::NonTerminal(AbstractExpression* left = NULL, AbstractExpression* right = NULL, Operator op = ADD){};

NonTerminal::NonTerminal(std::string& _op)
{
	switch(_op[0])
	{
	case '+':
		op = ADD;
	case '-':
		op = SUB;
	case '*':
		op = MUL;
	case '/':
		op = DIV;
	case '^':
		op = POW;
	};
	right = NULL;
	left = NULL;

};

int NonTerminal::evaluate(int left_res, int right_res) const
{
	switch(op)
	{
	case ADD:
		return left_res + right_res;
	case SUB:
		return left_res - right_res;
	case MUL:
		return left_res * right_res;
	case DIV:
		return left_res / right_res;
	case POW:
		return std::pow(left_res, right_res);
	case NEG:
		return (- right_res);
	}
};

int NonTerminal::interpret() const
{
	int res;
	int left_res = left == NULL ? 0 : left->interpret();
	int right_res = right == NULL ? 0 : right->interpret();
	res = evaluate(left_res, right_res);
	return res;
};

void NonTerminal::print()
{
	std::cout << "NonTerminal: ";
	switch(op)
	{
	case ADD:
		std::cout << "+";
		break;
	case SUB: 
		std::cout << "-";
		break;
	case DIV:
		std::cout << "/";
		break;
	case MUL:
		std::cout << "*";
		break;
	case POW:
		std::cout << "^";
		break;
	case NEG:
		std::cout << "-";
		break;
	};
	std::cout << std::endl;
};