#include "../inc/Lexer.hpp"

Lexer::Lexer() {
	_error = false;
	_stop = false;
	_exit = false;
}

Lexer::~Lexer() { }

eOperandType Lexer::getType(std::string str) {
	if (str == "int8")
		return Int8;
	if (str == "int16")
		return Int16;
	if (str == "int32")
		return Int32;
	if (str == "float")
		return Float;
	if (str == "double")
		return Double;
	return Double;
}

std::string Lexer::getValue(std::string str) {
	return str;
}

eOperation Lexer::getOperation(std::string str) {
	if (str == "push")
		return Push;
	if (str == "assert")
		return Assert;
	if (str == "pop")
		return Pop;
	if (str == "add")
		return Add;
	if (str == "sub")
		return Sub;
	if (str == "mul")
		return Mul;
	if (str == "div")
		return Div;
	if (str == "mod")
		return Mod;
	if (str == "pow")
		return Pow;
	if (str == "sqrt")
		return Sqrt;
	if (str == "min")
		return Min;
	if (str == "max")
		return Max;
	if (str == "clear")
		return Clear;
	if (str == "dump")
		return Dump;
	if (str == "print")
		return Print;
	if (str == "exit")
		return Exit;
	if (str == "info")
		return Info;
	if (str == ";;")
		return Stop;
	return Exit;
}

void	Lexer::validation(std::vector<std::string> array, std::vector<std::string> array_time) {
	
	std::cmatch		result;
	bool			int_db_fl;
	Token			token;
	bool			stop;

	_error = false;
	_stop = false;
	_exit = false;

	std::regex rgx_int1("^\\s*(push|assert)\\s*.*");
	std::regex rgx_fl_db1("^\\s*(push|assert)\\s*.*");
	std::regex rgx_int2("^\\s*(push|assert)\\s*(int8|int16|int32)\\s*.*");
	std::regex rgx_fl_db2("^\\s*(push|assert)\\s*(float|double)\\s*.*");
	std::regex rgx_int3("^\\s*(push|assert)\\s*(int8|int16|int32)\\((-?[0-9]+)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_fl_db3("^\\s*(push|assert)\\s*(float|double)\\((-?[0-9]+\\.[0-9]*)\\)\\s*((?=;).*|\\s*)");
	std::regex rgx_command("^\\s*(add|sub|mul|div|mod|pop|pow|sqrt|min|max|clear|dump|print|exit|info)\\s*((?=;).*|\\s*)");
	std::regex rgx_stop("^\\s*(;;)\\s*((?=;).*|\\s*)");
	std::regex rgx_space_comment("^\\s*(\\s*|;.*)\\s*((?=;).*|\\s*)");

	try {
		for (i = 0; i < array.size(); i++) {
			if (_error == true)
				return ;
			if ((std::regex_match(array[i].c_str(), result, rgx_int1)) ||
				(std::regex_match(array[i].c_str(), result, rgx_fl_db1)) ||
				(std::regex_match(array[i].c_str(), result, rgx_command)) || 
				(std::regex_match(array[i].c_str(), result, rgx_stop))) {
				if ((std::regex_match(array[i].c_str(), result, rgx_int2)) ||
					(std::regex_match(array[i].c_str(), result, rgx_fl_db2)) ||
					(std::regex_match(array[i].c_str(), result, rgx_command)) ||
					(std::regex_match(array[i].c_str(), result, rgx_stop))) {
					if ((int_db_fl = std::regex_match(array[i].c_str(), result, rgx_int3)) || 
						(int_db_fl = std::regex_match(array[i].c_str(), result, rgx_fl_db3)) || 
									(std::regex_match(array[i].c_str(), result, rgx_command)) ||
									(stop = std::regex_match(array[i].c_str(), result, rgx_stop))) {
						token.value = "0";
						token.operation = getOperation(result[1]);
						if (int_db_fl)	{
							token.type = getType(result[2]);
							token.value = result[3];
						}
						if (result[1] == "exit")
							_exit = true;
						token.dt = array_time[i];
						vector.push_back(token);
					}
					else {
						std::cout << "Error: Line: " << i + 1 << ". Value must be for: int8(N), int16(N), int32(N) N :=[-]?[0..9]+ , float(Z), double(Z) Z := [-]?[0..9]+.[0..9]+." << std::endl;
						//exit(0);
					}
				}
				else {
					std::cout << "Error: Line: " << i + 1 << ". The assembly program includes one or several lexical errors or syntactic errors. Allowed only [int8, int16, int32, float, double]" << std::endl;
					//exit(0);
				}
			}
			else if (std::regex_match(array[i].c_str(), result, rgx_stop)) {
				_stop = true;
			}
			else if (std::regex_match(array[i].c_str(), result, rgx_space_comment)) {
				//std::cout << "space or comment = " << array[i] << std::endl;
			}
			else {
				std::cout << "Error: Line: " << i + 1 << ". An instruction is unknown" << std::endl;
				//exit(0);
			}
		}
		if (_exit == false)
			throw NotExitException();
	}
	catch (OverflowException &e) {
		std::cout << "Lexer error" << std::endl;
		//exit(0);
	}
}

std::vector<Token> Lexer::getToken() const {
	return vector;
}
