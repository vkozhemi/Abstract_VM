# Abstract_VM

The purpose of this project is to create a simple virtual machine that can interpret programs written in a basic assembly language.

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions. These arithmetic expressions are provided to the machine as basic assembly programs.

## Example
As an example is still better that all the possible explanations in the world, this is an example of an assembly program that your machine will be able to compute:

![Image alt](https://github.com/vkozhemi/Abstract_VM/raw/master/img/0.png)

As for any assembly language, the language of AbstractVM is composed of a series of instructions, with one instruction per line. However, AbstractVM’s assembly language has a limited type system, which is a major difference from other real world assembly languages.
	
	• Comments: Comments start with a ’;’ and finish with a newline. 

	• push v: Pushes the value v at the top of the stack. The value v must have one of the following form:

		◦ int8(n) : Creates an 8-bit integer with value n. 
		◦ int16(n) : Creates a 16-bit integer with value n. 
		◦ int32(n) : Creates a 32-bit integer with value n. 
		◦ float(z) : Creates a float with value z.
		◦ double(z) : Creates a double with value z.

	• pop: Unstacks the value from the top of the stack. If the stack is empty, the program execution must stop with an error.
	• dump: Displays each value of the stack.
	• assert v: Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction.
	• add: Unstacks the first two values on the stack, adds them together and stacks the result. 
	• sub: ... subtracts them, then stacks the result. 
	• mul: ... multiplies them, then stacks the result. 
	• div: ... divides them, then stacks the result.
	• mod: ... calculates the modulus, then stacks the result. 
	• print: Asserts that the value at the top of the stack is an 8-bit integer.
	• exit: Terminate the execution of the current program.

## Grammar
![Image alt](https://github.com/vkozhemi/Abstract_VM/raw/master/img/1.png)

## Execution
Now let see some examples of execution:
![Image alt](https://github.com/vkozhemi/Abstract_VM/raw/master/img/2.png)

## The IOperand interface
AbstractVM uses 5 operand classes that you must declare and define:

	• Int8 : Representation of a signed integer coded on 8bits.
	• Int16 : Representation of a signed integer coded on 16bits. 
	• Int32 : Representation of a signed integer coded on 32bits. 
	• Float : Representation of a float.
	• Double : Representation of a double.

Each one of these operand classes MUST implement the following IOperand interface:

![Image alt](https://github.com/vkozhemi/Abstract_VM/raw/master/img/3.png)

## Creation of a new operand
New operands MUST be created via a "factory method". Search Google if you don’t know what it is. This member function must have the following prototype:

![Image alt](https://github.com/vkozhemi/Abstract_VM/raw/master/img/4.png)

The eOperandType type is an enum defining the following values: Int8, Int16, Int32, Float and Double.
Depending on the enum value passed as a parameter, the member function createOperand creates a new IOperand by calling one of the following private member functions:

![Image alt](https://github.com/vkozhemi/Abstract_VM/raw/master/img/5.png)

## The precision
When an operation happens between two operands of the same type, there is no problem. However, what about when the types are different ? The usual method is to order types using their precision. For this machine you should use the following order: Int8 < Int16 < Int32 < Float < Double. This order may be represented as an enum, as enum values evaluate to integers.
The pure method getPrecision from the interface IOperand allows to get the preci- sion of an operand. When an operation uses two operands from two different types, the comparison of theirs precisions allows to figure out the result type of the operation.


## The Stack
AbstractVM is a stack based virtual machine. Whereas the stack is an actual stack or another container that behaves like a stack is up to you. Whatever the container, it MUST only contain pointers to the abstract type IOperand.

