#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <stack>
# include <vector>

template <typename T>
class Stack : public std::stack <T>
{
public:
	class iterator {
		Stack		&rhs;
		unsigned int	i;
		iterator	&operator=(iterator const &rhs);
		iterator();
		public:
			iterator(iterator const &rhs) : rhs(rhs.rhs), i(rhs.i){}

			iterator(Stack &s, unsigned int i) : rhs(s), i(i){}

			~iterator(){}

			iterator	&operator++()
			{
				if (this->i < this->rhs.size())
					this->i++;
				return (*this);
			}

			iterator	&operator--()
			{
				if (this->i > 0)
					this->i--;
				return (*this);
			}
			
			bool		operator==(iterator const &rhs)
			{
				return (this->i == rhs.i);
			}
			
			bool		operator!=(iterator const &rhs)
			{
				return (this->i != rhs.i);
			}
			
			bool		operator<(iterator const &rhs)
			{
				return (this->i < rhs.i);
			}

			bool		operator>(iterator const &rhs)
			{
				return (this->i > rhs.i);
			}

			bool		operator<=(iterator const &rhs)
			{
				return (this->i <= rhs.i);
			}

			bool		operator>=(iterator const &rhs)
			{
				return (this->i >= rhs.i);
			}

			T			&operator*()
			{
				return this->rhs.c[this->i];
			}

			std::string	toString()
			{
				return this->rhs.i.toString();
			}
	};

	iterator	begin()
	{
		return (iterator(*this, 0));
	}

	iterator	end()
	{
		return (iterator(*this, this->size()));
	}
};

#endif
