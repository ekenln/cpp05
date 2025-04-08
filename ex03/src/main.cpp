/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/08 14:02:03 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat eva("eva", 3);
		eva.signForm(*rrf);
		eva.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

