/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 10:56:49 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 13:58:49 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

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

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat( std::string name, int grade );
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat&	operator=(const Bureaucrat& B);

		std::string		getName( void ) const;
		int				getGrade( void ) const;
		void			decrementGrade( void );
		void			incrementGrade( void );
		void			signForm(AForm& form);
		void			executeForm(AForm const & form) const;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& B);