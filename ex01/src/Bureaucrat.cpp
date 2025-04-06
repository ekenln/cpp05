/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 17:27:48 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/06 10:49:01 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("stiffBoy"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}
Bureaucrat::Bureaucrat( int grade ) : _name("stiffBoy")
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150 )
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150 )
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "bureaucrat: " << _name << " destructor called\n";
}

Bureaucrat::Bureaucrat( const Bureaucrat& old ) : _name(old._name), _grade(old._grade) {};

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& B )
{
	if (this != &B)
	{
		// _name = B.getName(); // _name is const??? what to do?? 
		_grade = B._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName( void ) const {
	return (_name);
}

int	Bureaucrat::getGrade( void ) const {
	return (_grade);
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "\n"; 

	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
}


void	Bureaucrat::decrementGrade( void )
{
	if (_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;

}
void	Bureaucrat::incrementGrade( void )
{
	if (_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& B)
{
	stream << B.getName() << ", bureaucrat grade " << B.getGrade() << std::endl; 
	return (stream);
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
		return "Grade is too high..\n";
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
		return "Grade is too Low..\n";
}
