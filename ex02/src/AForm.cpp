/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 19:25:42 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 13:50:21 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _gradeReqForSigning(100), _gradeReqForExecution(100) {}

AForm::AForm(const std::string name, const int gradeReqForSigning, const int gradeReqForExecution) : 
_name(name), _signed(false), _gradeReqForSigning(gradeReqForSigning), _gradeReqForExecution(gradeReqForExecution) 
{
	if (_gradeReqForSigning < 1 || _gradeReqForExecution < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (_gradeReqForSigning > 150 || _gradeReqForExecution > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {};

AForm::AForm(const AForm& old) : _name(old._name), _signed(old._signed), 
_gradeReqForSigning(old._gradeReqForSigning), _gradeReqForExecution(old._gradeReqForExecution) {}

std::string	AForm::getName( void ) const
{
	return (_name);
}

bool		AForm::getSigned( void ) const
{
	return(_signed);
}

int	AForm::getGradeSign( void ) const {
	return (_gradeReqForSigning);
}

int	AForm::getGradeExec( void ) const {
	return (_gradeReqForExecution);
}

int		AForm::beSigned(const Bureaucrat& B)
{
	if (B.getGrade() <= this->getGradeSign() && this->getSigned() != true)
	{
		this->_signed = !this->_signed;
		return (1);
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& stream, const AForm& F)
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

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high..\n";
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too Low..\n";
}

const char*	AForm::FormNotSignedException::what() const noexcept
{
	return "Cannot grant execution, form not signed\n";
}

int		AForm::checkGrade(const Bureaucrat& B) const
{
	if (!this->_signed)
	{
		throw AForm::FormNotSignedException();
	}
	if (B.getGrade() >= this->_gradeReqForExecution)
	{
		throw AForm::GradeTooLowException();
	}
	return (1);
}

