/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/09 17:55:19 by eeklund       ########   odam.nl         */
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
	std::srand(std::time(nullptr));
	try
	{
		Bureaucrat john("john", 130);
		ShrubberyCreationForm form("Shrubby");
		std::cout << form;
		john.executeForm(form);

		Bureaucrat celine("celine", 130);
		RobotomyRequestForm form2("Robot");
		std::cout << form2;
		celine.executeForm(form2);
		celine.signForm(form2);
		celine.executeForm(form2);

		Bureaucrat björn("björn", 3);
		PresidentialPardonForm form3("Benny");
		std::cout << form3;
		björn.executeForm(form3);
		// form3.execute(björn);

		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential ardon", "Bender");
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

