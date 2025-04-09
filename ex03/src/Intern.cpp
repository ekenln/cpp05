/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 14:14:44 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/09 18:06:51 by eeklund       ########   odam.nl         */
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

Intern&	Intern::operator=(const Intern& B)
{
	(void)B;
	return (*this);
}

const char	*Intern::FormNonExistentException::what() const noexcept
{
	return("The form does not exist and can therefore not be created");
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
	throw(FormNonExistentException());
}
