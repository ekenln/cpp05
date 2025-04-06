/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/06 14:04:18 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/Bureaucrat.hpp"

// int main( void )
// {
// 	// try
// 	// {
// 	// 	Bureaucrat boy(0);
// 	// }
// 	// catch (const Bureaucrat::GradeTooHighException& e) {
// 	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
// 	// } 
// 	// catch (const Bureaucrat::GradeTooLowException& e) {
// 	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
// 	// }
// 	try
// 	{
// 		Bureaucrat boy2("funBoy", 130);
// 		std::cout << boy2;
// 		boy2.incrementGrade();
// 		std::cout << boy2;
// 		Bureaucrat boy(0);
// 	}
// 	catch(const Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cerr << "caught exception: " << e.what() << '\n';
// 	}
// 	catch(const Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cerr << "caught exception: " << e.what() << '\n';
// 	}
// 	return 0;
// }

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat john("john", 130);
		ShrubberyCreationForm form("Shrubby");
		form.execute(john);
		std::cout << form;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat celine("celine", 130);
		RobotomyRequestForm form2("Robot");
		form2.execute(celine);
		std::cout << form2;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat björn("björn", 3);
		PresidentialPardonForm form3("Benny");
		björn.executeForm(form3);
		// form3.execute(björn);
		std::cout << form3;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

