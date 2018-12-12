#ifndef PARSING_H
# define PARSING_H
# include <string>
# include <iostream>
# include <regex>
# include <vector>
# include "Operand.hpp"

class Parsing
{
private:
	// std::vector<std::string>	_v;
	// Factory						_f;
	std::vector<const IOperand*> _stack;
	bool						_error;
	int							i;
	int							_size;
	//std::string _str;

	void	validation_size(std::string str);
public:
	Parsing();
	Parsing(std::vector<std::string>);
	Parsing(Parsing const &obj);
	Parsing &operator=(Parsing const &hrs);
	~Parsing();
};

#endif