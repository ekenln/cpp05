/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/09 17:32:44 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
		std::srand(std::time(nullptr));
		Bureaucrat celine("celine", 44);
		RobotomyRequestForm form2("Robot");
		std::cout << form2;
		celine.signForm(form2);
		celine.executeForm(form2);
		std::cout << std::endl;

		Bureaucrat john("john", 130);
		ShrubberyCreationForm form("home");
		std::cout << form;
		john.signForm(form);
		john.signForm(form);
		john.executeForm(form);
		std::cout << std::endl;

		Bureaucrat björn("björn", 3);
		PresidentialPardonForm form3("Benny");
		std::cout << form3;
		std::cout << std::endl;
		björn.executeForm(form3);
		björn.signForm(form3);
		björn.executeForm(form3);
		std::cout << std::endl;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

