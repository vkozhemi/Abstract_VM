#include <iostream>
#include <string>
#include <fstream>
#include "../inc/Parsing.hpp"
// #include "../inc/IOperand.hpp"
// #include "../inc/Operand.hpp"
// #include "../inc/Factory.hpp"

void	read_from_std_in(void)
{
	std::string					buffer;
	std::vector<std::string>	array;

	while (std::getline(std::cin, buffer) && buffer.compare(";;") != 0) // 
		array.push_back(buffer);

	Parsing p(array);
}

void	read_from_file(std::string filename)
{
	std::string					buffer;
	std::vector<std::string>	array;

	std::ifstream   readFile(filename);
	if (readFile.fail())
	{
		std::cout << "Error opening file" << std::endl;
		exit(1);
	}
	while (std::getline(readFile, buffer))
		array.push_back(buffer);

	Parsing p(array);
}

int		main(int argc, char **argv)
{
	// Lexer *lexer = new Lexer();
	// Parser *parser = new Parser();

	if (argc == 1 || argc == 2) {
		try {
			if (argc == 1)
				read_from_std_in();
			else
				read_from_file(argv[1]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: ./avm [file]" << std::endl;
	return (0);
}