/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/05 19:25:54 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 10:53:10 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
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
		Form();
		Form(const std::string name, const int gradeReqForSigning, const int gradeReqForExecution);
		~Form();
		Form(const Form& old);
		Form&		operator=(const Form& F) = delete;
		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeSign( void ) const;
		int			getGradeExec( void ) const;
		int			beSigned(const Bureaucrat& B);

		
};

std::ostream&	operator<<(std::ostream& stream, const Form& F);
