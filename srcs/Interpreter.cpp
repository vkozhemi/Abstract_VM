#include "../inc/Interpreter.hpp"

Interpreter::Interpreter() { size = 0; }
Interpreter::~Interpreter() {}

std::string	Interpreter::convertType(eOperandType type) {
	if (type == 0)
		return "int8";
	if (type == 1)
		return "int16";
	if (type == 2)
		return "int32";
	if (type == 3)
		return "float";
	if (type == 4)
		return "double";
	return "type";
}

void	Interpreter::push(eOperandType type, std::string value, std::string dt) {
	stack.push_back(factory.createOperand(type, value));
	stack_time.push_back(dt);
	size++;
}

void	Interpreter::assert(eOperandType type, std::string value) {
	if (stack.empty())
		throw AssertEmptyStackException();
	if (stack.back()->toString() != value)
		throw AssertValueException();
	if (stack.back()->getType() != type)
		throw AssertTypeException();
}

void	Interpreter::pop() {
	if (stack.empty())
		throw PopEmptyStackException();
	stack.pop_back();
	size--;
}

void	Interpreter::dump() {
	if (stack.empty())
		throw DumpEmptyStackException();
	for (int i = stack.size() - 1; i >= 0; i--)
		std::cout << (stack[i])->toString() << std::endl;
}


void	Interpreter::print() {
	if (stack.empty())
		throw EmptyStackException();
	if ( stack[stack.size() - 1]->getType() != Int8)
		throw NotCharException();
	std::cout << (char)std::stoi(stack[stack.size() - 1]->toString()) << std::endl;
}

int	Interpreter::calcWidh() {
	int a = 0;
	int b = 0;

	for (auto it = stack.begin(); it != stack.end(); it++) {
		std::string str = std::string((*it)->toString());
		a = strlen(str.c_str());
		if (a > b)
			b = a;
	}
	return b;
}

void 	Interpreter::operations(eOperation operation) {
	IOperand const *operand = nullptr;
	if (stack.empty())
		throw EmptyStackException();
	if (size < 2)
		throw OperationException();
	operand = stack[stack.size() - 1];
	stack.pop_back();
	if (operation == Add)	{
		operand = *stack[stack.size() - 1] + *operand;
	}
	else if (operation == Sub)	{
		operand = *stack[stack.size() - 1] - *operand;
	}
	else if (operation == Mul)	{
		operand = *stack[stack.size() - 1] * *operand;
	}
	else if (operation == Div)	{
		if (std::stod(operand->toString()) == 0)
			throw DivisionByZeroException();
		operand = *stack[stack.size() - 1] / *operand;
	}
	else if (operation == Mod)	{
		if (std::stod(operand->toString()) == 0)
			throw DivisionByZeroException();
		operand = *stack[stack.size() - 1] % *operand;
	}
	else if (operation == Pow)	{

		operand = factory.createOperand(
				(eOperandType)std::max(stack[stack.size() - 1]->getPrecision(), operand->getPrecision()),
				std::to_string( pow( std::stod(stack[stack.size() - 1]->toString()), std::stod(operand->toString()) ))
				);
	}
	stack.pop_back();
	stack.push_back(operand);
	size--;
}

void	Interpreter::ssqrt() {
	IOperand const *operand = nullptr;
	if (stack.empty())
		throw PopEmptyStackException();
	if (size < 1)
		throw OperationException();
	operand = stack[stack.size() - 1];
	stack.pop_back();

	operand  =  factory.createOperand((eOperandType)operand->getPrecision(), std::to_string(std::sqrt(std::stod(operand->toString()))));
	
	stack.push_back(operand);
}

void	Interpreter::min() {
	if (stack.empty())
		throw EmptyStackException();
	IOperand const *min = *stack.begin();

	for (unsigned int i = 0; i < stack.size() - 1; i++) {
		if (std::stod(min->toString()) > std::stod((stack[i])->toString()))
			min = stack[i];
	}
	std::cout << "min = " << min->toString() << std::endl;
}

void	Interpreter::max() {
	if (stack.empty())
		throw EmptyStackException();
	IOperand const *max = *stack.begin();

	for (unsigned int i = 0; i < stack.size() - 1; i++) {
		if (std::stod(max->toString()) < std::stod((stack[i])->toString()))
			max = stack[i];
	}
	std::cout << "max = " << max->toString() << std::endl;
}

void	Interpreter::clear() {
	if (stack.empty())
		throw EmptyStackException();
	stack.clear();
	std::cout << "Stack is empty" << std::endl;
}

void	Interpreter::stop() {
	Lexer l;
	if (l._exit == false)
		throw NotExitException();
	std::cout << "Program has been stopped" << std::endl;
	exit(0);
}

void	Interpreter::info() {
	width = calcWidh();
	std::cout<<"|----------------------INFO-STACK---------------";
	for(int head = 0; head < width; head++) {std::cout << "-";}
	std::cout <<"|"<< std::endl;
	std::cout<<"|  № |   TYPE   |VALUE";
	for(int head = 1; head < width; head++) {std::cout << " ";}
	std::cout<<"|           TIME           ";
	std::cout << "|"<< std::endl;
	std::cout<<"|-----------------------------------------------";
	for(int head = 0; head < width; head++) {std::cout << "-";}
	std::cout << "|"<< std::endl;
	int n = 0;

	for (int i = stack.size() - 1; i >= 0; i--) {
		n++;
		std::cout	<< std::internal << "| "
					<< std::setw(2) << n
					<< " | ["
					<< std::setw(6) <<convertType(stack[i]->getType())
					<< "] | ["
					<< std::setw(width) <<stack[i]->toString()
					<<"] | " 
					<< stack_time[i];
		std::cout<<"|-----------------------------------------------";
		for(int head = 0; head < width; head++) {std::cout << "-";}
		std::cout << "|"<< std::endl;
	}
}
