#include "../inc/Parsing.hpp"
#include "../inc/Factory.hpp"
#include <regex>
#include <fstream>
#include <iostream>
#include <cmath>
// #include "../inc/IOperand.hpp"
// #include "../inc/Operand.hpp"


Parsing::Parsing() { }

Parsing::~Parsing() { }

// std::string	Parsing::getStr(void) {
// 	return this->_str;
// }

void	Parsing::validation_size(std::string str)
{
	std::cmatch		result;
	std::regex rgx_int8("^\\s*(push|assert)\\s*(int8)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_int16("^\\s*(push|assert)\\s*(int16)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_int32("^\\s*(push|assert)\\s*(int32)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_fl("^\\s*(push|assert)\\s*(float)\\((-?[0-9]+.?[0-9]*)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_db("^\\s*(push|assert)\\s*(double)\\((-?[0-9]+.?[0-9]*)\\)\\s*((?=;).*|\\s*)");

	try
	{
		if (std::regex_match(str.c_str(), result, rgx_int8))
		{
			long long int int8 = std::stol(result[3]);
			if (int8 < -128 || int8 > 127)
			{
				std::cout << "Error: Line: " << i + 1 << ". int8: out of range " << std::endl;
				_error = true;
				throw (Factory::OutOfRange());
			}
		}
		else if (std::regex_match(str.c_str(), result, rgx_int16))
		{
			long long int int16 = std::stol(result[3]);
			if (int16 < -327683 || int16 > 32767)
			{
				std::cout << "Error: Line: " << i + 1 << ". int16: out of range " << std::endl;
				_error = true;
				throw (Factory::OutOfRange());
			}
		}
		else if (std::regex_match(str.c_str(), result, rgx_int32))
		{
			long long int int32 = std::stol(result[3]);
			if (int32 < -2147483648 || int32 > 2147483647)
			{
				std::cout << "Error: Line: " << i + 1 << ". int32: out of range  "<< std::endl;
				_error = true;
				throw (Factory::OutOfRange());
			}
		}
		else if (std::regex_match(str.c_str(), result, rgx_fl))
		{
			try
			{
				std::stof(result[3]);
			}
			catch (std::exception &e)
			{
				_error = true;
				std::cout << "Error: Line: " << i + 1 << ". " << e.what() << std::endl;
			}
		}
		else if (std::regex_match(str.c_str(), result, rgx_db))
		{
			try
			{
				std::stod(result[3]);
			}
			catch (std::exception &e)
			{
				_error = true;
				std::cout << "Error: Line: " << i + 1 << ". " << e.what() << std::endl;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error: line: " << i + 1 << ". "<< e.what() << std::endl;
		return ;
	}
	
}

eOperandType getType(std::string str) 
{
	if (str == "int8")			{
		return Int8;
	}
	else if (str == "int16")	{
		return Int16;
	}
	else if (str == "int32")	{
		return Int32;
	}	
	else if (str == "float")	{
		return Float;
	}
	else if (str == "double")	{
		return Double;
	}
	return Int8;
}

Parsing::Parsing(std::vector<std::string> array)
{
	_size = -1;
	int vector_size = array.size();
	_error = false;
	std::cmatch		result;

//  if (int || fl_db)
//	else if (command)

	std::regex rgx_int("^\\s*(push|assert)\\s*(int8|int16|int32)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_fl_db("^\\s*(push|assert)\\s*(float|double)\\((-?[0-9]+.?[0-9]*)\\)\\s*((?=;).*|\\s*)");
	
	std::regex rgx_command("^\\s*(add|sub|mul|div|mod|pop|dump|print|exit|;.*|;;)\\s*"); //((?=;).*|\\s*) 

	// std::regex rgx_push("^(push)\\s*((?=;).*|\\s*)");
	// std::regex rgx_assert("^(assert)\\s*((?=;).*|\\s*)");

	// std::regex rgx_push_int8("^(push)\\s*(int8)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_push_int16("^(push)\\s*(int16)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_push_int32("^(push)\\s*(int32)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_push_fl("^(push)\\s*(float)\\((-?[0-9]+.?[0-9]*)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_push_db("^(push)\\s*(double)\\((-?[0-9]+.?[0-9]*)\\)\\s*((?=;).*|\\s*)");

	// std::regex rgx_assert_int8("^(assert)\\s*(int8)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_assert_int16("^(assert)\\s*(int16)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_assert_int32("^(assert)\\s*(int32)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_assert_fl("^(assert)\\s*(float)\\((-?[0-9]+\\.?[0-9]*)\\)\\s*((?=;).*|\\s*)");
	// std::regex rgx_assert_db("^(assert)\\s*(double)\\((-?[0-9]+\\.?[0-9]*)\\)\\s*((?=;).*|\\s*)");

	// std::regex rgx_push_assert("^((push)|(assert))\\s*((int8)|(int16)|(int32)|(float)|(double))\\((-?[0-9]+)|(-?[0-9]+.?[0-9]*)\\)\\s*((?=;).*|\\s*)");

	Factory *factory = new Factory();

	for (i = 0; i < vector_size; i++)
	{
		std::cout << "i = " << i << std::endl;
		if ((std::regex_match(array[i].c_str(), result, rgx_int)) || (std::regex_match(array[i].c_str(), result, rgx_fl_db)))
		{
			validation_size(array[i]);
			if (_error == true)
				break ;
			if (result[1] == "push")
			{
				//std::cout << "result[0] = " << result[0] <<std::endl;
				// std::cout << "result[1] = " << result[1] <<std::endl; //push
				// std::cout << "result[2] = " << result[2] <<std::endl; //int8 int16 int32 float double
				// std::cout << "result[3] = " << result[3] <<std::endl; // 42


				_stack.push_back(factory->createOperand(getType(result[2]), result[3]));
				_size++;

	 			
			}
			else if (result[1] == "assert")
			{
				if (_size < 0)
				{
					std::cout << "Error: Line: " << i + 1 << ". Empty stack, can't compare values" << std::endl;
					return ;
				}
				//std::cout << "result[0] = " << result[0] <<std::endl;
				// std::cout << "result[1] = " << result[1] <<std::endl;
				// std::cout << "result[2] = " << result[2] <<std::endl;
				// std::cout << "result[3] = " << result[3] <<std::endl;

				if (std::stod(result[3]) != std::stod(_stack[_size]->toString()) || (getType(result[2]) != _stack[_size]->getType()))
				{
					std::cout << "Error: Line: " << i + 1 << ". This values aren't equal." << std::endl;
				 	break ; // ????????????????????? type = 3   value = 42.200001
				}

			}

			

	
		}
	// 	if (std::regex_match(array[i].c_str(), result, rgx_push_int8))
	// 	{
	// 		validation_size(array[i]); 
	// 		if (_error == true)
	// 			break ;
	// 		_stack.push_back(factory->createOperand(Int8, result[3]));
	// 		_size++;
	// 	}
	// 	else if (std::regex_match(array[i].c_str(), result, rgx_assert_int8))
	// 	{
	// 		validation_size(array[i]);
	// 		if (_size < 0)
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". Empty stack, can't compare values" << std::endl;
	// 			return ;
	// 		}
	// 		/*
			
	// 		eOperandType getType(std::string str){
	// 			switch (str) {
			// case "int8"
			// return Int8;
	// 			}
	// 		}
	// 		*/
	// 		std::cout << "_stack[_size]->getType() = " << _stack[_size]->getType()<< std::endl; // 0
	// 		std::cout << "result[2] = " << result[2] <<std::endl; // int8

	// 		std::cout << "_stack[_size]->toString() = " << _stack[_size]->toString()<< std::endl;
	// 		std::cout << "result[3] = " << result[3] <<std::endl;
			
	// 		if (std::stoi(result[3]) != std::stoi(_stack[_size]->toString())) //result[2] != 0
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". This values aren't equal." << std::endl;
	// 		 	break ;
	// 		}
			
	// 	}
	// 	else if (std::regex_match(array[i].c_str(), result, rgx_assert_int16))
	// 	{
	// 		validation_size(array[i]);
	// 		if (_size < 0)
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". Empty stack, can't compare values" << std::endl;
	// 			return ;
	// 		}
	// 		std::cout << "_stack[_size]->getType() = " << _stack[_size]->getType()<< std::endl; // 0
	// 		std::cout << "result[2] = " << result[2] <<std::endl; // int8

	// 		std::cout << "_stack[_size]->toString() = " << _stack[_size]->toString()<< std::endl;
	// 		std::cout << "result[3] = " << result[3] <<std::endl;
			
	// 		if (std::stoi(result[3]) != std::stoi(_stack[_size]->toString())) //result[2] != 0
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". This values aren't equal." << std::endl;
	// 		 	break ;
	// 		}
	// 	}
	// 	else if (std::regex_match(array[i].c_str(), result, rgx_assert_int32))
	// 	{
	// 		validation_size(array[i]);
	// 		if (_size < 0)
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". Empty stack, can't compare values" << std::endl;
	// 			return ;
	// 		}
	// 		std::cout << "_stack[_size]->getType() = " << _stack[_size]->getType()<< std::endl; // 0
	// 		std::cout << "result[2] = " << result[2] <<std::endl; // int8

	// 		std::cout << "_stack[_size]->toString() = " << _stack[_size]->toString()<< std::endl;
	// 		std::cout << "result[3] = " << result[3] <<std::endl;
			
	// 		if (std::stoi(result[3]) != std::stoi(_stack[_size]->toString())) //result[2] != 0
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". This values aren't equal." << std::endl;
	// 		 	break ;
	// 		}
	// 	}
	// 	else if (std::regex_match(array[i].c_str(), result, rgx_assert_fl))
	// 	{
	// 		validation_size(array[i]);
	// 		if (_size < 0)
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". Empty stack, can't compare values" << std::endl;
	// 			return ;
	// 		}
			
	// 		if (std::stoi(result[3]) != std::stoi(_stack[_size]->toString())) //result[2] != 0
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". This values aren't equal." << std::endl;
	// 		 	break ;
	// 		}
	// 	}
	// 	else if (std::regex_match(array[i].c_str(), result, rgx_assert_db))
	// 	{
	// 		validation_size(array[i]);
	// 		if (_size < 0)
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". Empty stack, can't compare values" << std::endl;
	// 			return ;
	// 		}
			
	// 		if (std::stoi(result[3]) != std::stoi(_stack[_size]->toString())) //result[2] != 0
	// 		{
	// 			std::cout << "Error: Line: " << i + 1 << ". This values aren't equal." << std::endl;
	// 		 	break ;
	// 		}
	// 	}
		else if (std::regex_match(array[i].c_str(), result, rgx_command))
		{
			//std::cout << array[i] << std::endl;
			std::cout << "commands = " << array[i] << std::endl;
		}
		else
			std::cout << "wrong command " << std::endl;
	}

	vector_size = _stack.size();
	for (int j = 0; j < vector_size; j++)
	{
		std::cout << "type = " << _stack[j]->getType() << "   value = "<< _stack[j]->toString() << std::endl;
	}
}
