/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 19:25:42 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 10:53:15 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _gradeReqForSigning(100), _gradeReqForExecution(100) {}

Form::Form(const std::string name, const int gradeReqForSigning, const int gradeReqForExecution) : 
_name(name), _signed(false), _gradeReqForSigning(gradeReqForSigning), _gradeReqForExecution(gradeReqForExecution) 
{
	if (_gradeReqForSigning < 1 || _gradeReqForExecution < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (_gradeReqForSigning > 150 || _gradeReqForExecution > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::~Form() {};

Form::Form(const Form& old) : _name(old._name), _signed(old._signed), 
_gradeReqForSigning(old._gradeReqForSigning), _gradeReqForExecution(old._gradeReqForExecution) {}

std::string	Form::getName( void ) const
{
	return (_name);
}

bool		Form::getSigned( void ) const
{
	return(_signed);
}

int	Form::getGradeSign( void ) const {
	return (_gradeReqForSigning);
}

int	Form::getGradeExec( void ) const {
	return (_gradeReqForExecution);
}

int		Form::beSigned(const Bureaucrat& B)
{
	if (B.getGrade() <= this->getGradeSign() && this->getSigned() != true)
	{
		this->_signed = !this->_signed;
		return (1);
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
