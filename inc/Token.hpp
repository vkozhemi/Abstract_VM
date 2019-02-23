#ifndef TOKEN_HPP
#define TOKEN_HPP

enum eOperandType {Int8, Int16, Int32, Float, Double};
enum eOperation {Push, Assert, Pop, Add, Sub, Mul, Div, Mod, Pow, Sqrt, Min, Max, Clear, Dump, Print, Exit, Info, Stop};

struct Token {
	eOperandType	type;
	std::string		value;
	eOperation		operation;
	std::string		dt;
};

#endif