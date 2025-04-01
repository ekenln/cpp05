/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 17:18:26 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/01 17:18:48 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const noexcept
				{
					return "Grade is too high..\n";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const noexcept {
					return "Grade is too Low..\n";
				}
		};

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat( std::string name, int grade );
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat&	operator=(const Bureaucrat& B);

		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		decrementGrade( void );
		void		incrementGrade( void );

};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& B);