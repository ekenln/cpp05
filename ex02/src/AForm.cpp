/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 19:25:42 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/09 17:27:10 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _gradeSignature(100), _gradeExec(100) {}

AForm::AForm(const std::string name, const int gradeSignature, const int gradeExec) : 
_name(name), _signed(false), _gradeSignature(gradeSignature), _gradeExec(gradeExec) 
{
	if (_gradeSignature < 1 || _gradeExec < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (_gradeSignature > 150 || _gradeExec > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {};

AForm::AForm(const AForm& old) : _name(old._name), _signed(old._signed), 
_gradeSignature(old._gradeSignature), _gradeExec(old._gradeExec) {}

std::string	AForm::getName( void ) const
{
	return (_name);
}

bool		AForm::getSigned( void ) const
{
	return(_signed);
}

int	AForm::getGradeSign( void ) const {
	return (_gradeSignature);
}

int	AForm::getGradeExec( void ) const {
	return (_gradeExec);
}

void	AForm::beSigned(const Bureaucrat& B)
{
	if (this->_signed == true)
	{
		throw (std::logic_error("Form already signed"));
	}
	if (B.getGrade() <= this->getGradeSign())
	{
		this->_signed = true;
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
	return "Form not signed";
}

void	AForm::checkGrade(const Bureaucrat& B) const
{
	if (!this->_signed)
	{
		throw AForm::FormNotSignedException();
	}
	if (B.getGrade() >= this->_gradeExec)
	{
		throw AForm::GradeTooLowException();
	}
}

