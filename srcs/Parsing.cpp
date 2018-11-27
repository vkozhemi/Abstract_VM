#include "../inc/Parsing.hpp"
#include "string.h"
#include "../inc/Factory.hpp"
#include "../inc/IOperand.hpp"


Parsing::Parsing() { }

Parsing::~Parsing() { }

// std::string	Parsing::getStr(void) {
// 	return this->_str;
// }

void	validation_size(std::vector<std::string> stack)
{
	int vector_size = stack.size();
	std::regex rgx_int8("^(push)\\s*(int8)\\(-?[0-9]+\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_int16("^(push)\\s*(int16)\\(-?[0-9]+\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_int32("^(push)\\s*(int32)\\(-?[0-9]+\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_fl("^(push)\\s*(float)\\(-?[0-9]+.?[0-9]*\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_db("^(push)\\s*(double)\\(-?[0-9]+.?[0-9]*\\)\\s*((?=;).*|\\s*)");

	try
	{
		for (int i = 0; i < vector_size; i++)
		{
			if (std::regex_match(stack[i], rgx_int8))
			{

				long long int int8 = std::stol(stack[i].c_str() + 10);
				//std::cout  << int8 << std::endl;
				if (int8 < -128 || int8 > 127)
				{
					std::cout << int8 << " out of range int8" << std::endl;
					throw (Factory::OutOfRange());
				}
				else
					std::cout  << "int8 = " << int8 << std::endl;

				//push int8(23)
			}
			else if (std::regex_match(stack[i], rgx_int16))
			{
				long long int int16 = std::stol(stack[i].c_str() + 11);
				//std::cout  << int16 << std::endl;
				if (int16 < -327683 || int16 > 32767)
				{
					std::cout << int16 << " out of range int16" << std::endl;
					//throw ();
				}
				else
					std::cout  << "int16 = " << int16 << std::endl;
			}
			else if (std::regex_match(stack[i], rgx_int32))
			{
				long long int int32 = std::stol(stack[i].c_str() + 11);
				//std::cout  << int16 << std::endl;
				if (int32 < -2147483648 || int32 > 2147483647)
				{
					std::cout << int32 << " out of range int32" << std::endl;
					//throw ();
				}
				else
					std::cout  << "int32 = " << int32 << std::endl;
			}
			// else if (std::regex_match(stack[i], rgx_fl))
			// {
				
			// }
			// else if (std::regex_match(stack[i], rgx_db))
			// {
				
			// }
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error: line: " << e.what() << std::endl;
		return ;
	}
	
}


void	Parsing::pars(std::vector<std::string> array)
{
	std::vector<std::string>	stack;
	std::string					str;
	int vector_size = array.size();

	std::regex rgx_push_int("^(push)\\s*(int(8|16|32))\\(-?[0-9]+\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_push_fl_db("^(push)\\s*(float|double)\\(-?[0-9]+.?[0-9]*\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_assert_int("^(assert)\\s*(int(8|16|32))\\(-?[0-9]+\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_assert_fl_db("^(assert)\\s*(float|double)\\(-?[0-9]+.?[0-9]*\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_command("^(add|sub|mul|div|mod|pop|dump|print|exit|;;)\\s*"); //((?=;).*|\\s*) 

	for (int i = 0; i < vector_size; i++)
	{
		if (std::regex_match(array[i], rgx_push_int))
		{
			str = array[i];
			//std::cout  << array[i] << std::endl;
			stack.push_back(str);
			validation_size(stack);
			//std::cout << "int " << array[i] << std::endl;
		}
		else if (std::regex_match(array[i], rgx_push_fl_db))
		{
			str = array[i];
			//std::cout << array[i] << std::endl;
			stack.push_back(str);
			//std::cout << "fl_db " << array[i] << std::endl;
		}
		else if (std::regex_match(array[i], rgx_assert_int))
		{
			//std::cout  << array[i] << std::endl;
			//std::cout << "int " << array[i] << std::endl;
		}
		else if (std::regex_match(array[i], rgx_assert_fl_db))
		{
			//std::cout << array[i] << std::endl;
			//std::cout << "fl_db " << array[i] << std::endl;
		}
		else if (std::regex_match(array[i], rgx_command))
		{
			//std::cout << array[i] << std::endl;
			//std::cout << "commands " << array[i] << std::endl;
		}
		else
			std::cout << "wrong command " << std::endl;
	}

	// vector_size = stack.size();
	// for (int i = 0; i < vector_size; i++)
	// {
	// 	std::cout  << stack[i] << std::endl;
	// }
}
