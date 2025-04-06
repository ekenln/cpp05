/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 10:56:35 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 13:48:24 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeReqForSigning;
		const int			_gradeReqForExecution;

	public:

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};
		AForm();
		AForm(const std::string name, const int gradeReqForSigning, const int gradeReqForExecution);
		~AForm();
		AForm(const AForm& old);
		AForm&			operator=(const AForm& F) = delete;
		std::string		getName( void ) const;
		bool			getSigned( void ) const;
		int				getGradeSign( void ) const;
		int				getGradeExec( void ) const;
		int				beSigned(const Bureaucrat& B);
		int				checkGrade(const Bureaucrat& B) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;		
};

std::ostream&	operator<<(std::ostream& stream, const AForm& F);
