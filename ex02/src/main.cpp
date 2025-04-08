/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/08 14:18:27 by eeklund       ########   odam.nl         */
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
		Bureaucrat john("john", 130);
		ShrubberyCreationForm form("home");
		std::cout << form;
		form.beSigned(john);
		form.execute(john);
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::srand(std::time(nullptr));
		Bureaucrat celine("celine", 44);
		RobotomyRequestForm form2("Robot");
		celine.signForm(form2);
		celine.executeForm(form2);
		std::cout << form2;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat björn("björn", 3);
		PresidentialPardonForm form3("Benny");
		björn.executeForm(form3);
		std::cout << form3;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

