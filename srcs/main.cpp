#include "../inc/Lexer.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Interpreter.hpp"
#include "../inc/IOperand.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Factory.hpp"

void	initClass(std::vector<std::string>	array, std::vector<std::string> array_time) {
	Lexer 	lex;
	lex.validation(array, array_time);
	Parser 	pars;
	pars.parser(lex.getToken());
}

void	readFromStdIn(void) {
	std::string					buffer;
	std::vector<std::string>	array;
	std::vector<std::string>	array_time;
	time_t						now;
	char*						dt;
	std::string					times;

	while (std::getline(std::cin, buffer) && buffer.compare(";;") != 0) {
		array.push_back(buffer);
		now = time(0);
		dt = ctime(&now);
		times = dt;
		array_time.push_back(times);
	}
	initClass(array, array_time);
}

void	readFromFile(std::string filename) {
	std::string					buffer;
	std::vector<std::string>	array;
	std::vector<std::string>	array_time;
	time_t						now;
	char*						dt;
	std::string					times;

	std::ifstream   readFile(filename);
	if (readFile.fail())
	{
		std::cout << "Error opening file" << std::endl;
		exit(1);
	}
	while (std::getline(readFile, buffer)) {
		array.push_back(buffer);
		now = time(0);
		dt = ctime(&now);
		times = dt;
		array_time.push_back(times);
	}
	initClass(array, array_time);
}

int		main(int argc, char **argv) {
	if (argc == 1 || argc == 2) {
		try {
			if (argc == 1)
				readFromStdIn();
			else
				readFromFile(argv[1]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: ./avm [file]" << std::endl;
	return (0);
}