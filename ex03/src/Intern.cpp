/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 14:14:44 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/08 14:29:13 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& old) {
	(void)old;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	struct formTable
	{
		std::string	formType;
		AForm*	(*create)(const std::string& target);
	};

	static const formTable forms[] =
	{
		{"shrubbery request", [] (const std::string& t) -> AForm* {return (new ShrubberyCreationForm(t));}},
		{"robotomy request", [] (const std::string& t) -> AForm* {return (new RobotomyRequestForm(t)); }},
		{"presidential pardon", [] (const std::string& t) -> AForm* {return (new PresidentialPardonForm(t)); }}	
	};

	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i].formType)
		{
			std::cout << "Intern creates a " << forms[i].formType << std::endl;
			AForm* createdForm = forms[i].create(target);
			return (createdForm); 
		}
	}
	std::cout << "The form " << form << " does not exist and can therfore not be created\n";
	return (nullptr);
}
