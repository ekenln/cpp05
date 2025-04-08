/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 12:46:17 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/08 12:11:32 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& old) : AForm(old), _target(old._target) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	if (AForm::checkGrade(executor))
	std::cout << "*drilling noises*\n";
	std::cout << this->_target << " has been robotomized\n";
	std::cout << this->_target << " failed to become robotomized\n";

}

