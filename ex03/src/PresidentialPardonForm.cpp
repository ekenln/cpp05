/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 13:29:09 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 13:44:34 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 45), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 45), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& old) : AForm(old), _target(old._target) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	if (AForm::checkGrade(executor))
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}