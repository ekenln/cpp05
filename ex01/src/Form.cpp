/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 19:25:42 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/08 15:02:54 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _gradeSignature(100), _gradeExec(100) {}

Form::Form(const std::string name, const int gradeSignature, const int gradeExec) : 
_name(name), _signed(false), _gradeSignature(gradeSignature), _gradeExec(gradeExec) 
{
	if (_gradeSignature < 1 || _gradeExec < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (_gradeSignature > 150 || _gradeExec > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::~Form() {};

Form::Form(const Form& old) : _name(old._name), _signed(old._signed), 
_gradeSignature(old._gradeSignature), _gradeExec(old._gradeExec) {}

std::string	Form::getName( void ) const
{
	return (_name);
}

bool	Form::getSigned( void ) const
{
	return(_signed);
}

int	Form::getGradeSign( void ) const {
	return (_gradeSignature);
}

int	Form::getGradeExec( void ) const {
	return (_gradeExec);
}

void	Form::beSigned(const Bureaucrat& B)
{
	if (B.getGrade() <= this->getGradeSign())
	{
		this->_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& stream, const Form& F)
{
	stream << F.getName() << "\n";
	if (F.getSigned() == true)
	{
		stream << "Signed\n";
	}
	else
	{
		stream << "Not signed\n";
	}
	stream << "Grade required to sign: " << F.getGradeSign() << "\n";
	stream << "Grade required to execute: " << F.getGradeExec() << "\n";
	return (stream);
}

const char*	Form::GradeTooHighException::what() const noexcept
{
		return "Grade is too high..\n";
}

const char*	Form::GradeTooLowException::what() const noexcept
{
		return "Grade is too Low..\n";
}
