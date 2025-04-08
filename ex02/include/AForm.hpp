/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 10:56:35 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/08 13:15:02 by eeklund       ########   odam.nl         */
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
		const int			_gradeSignature;
		const int			_gradeExec;

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
		AForm(const std::string name, const int gradeSignature, const int gradeExec);
		virtual ~AForm();
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
