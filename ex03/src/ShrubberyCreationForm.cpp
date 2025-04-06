/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 11:10:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 13:45:09 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubbyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubbyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& old) : AForm(old), _target(old._target) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	if (AForm::checkGrade(executor))
	{
		std::string fileName = _target + "_shrubbery";
		std::ofstream fileStream (fileName);
		fileStream << "       ###\n"
				<< "      #o###\n"
				<< "    #####o###\n"
				<< "   #o#\\#|#/###\n"
				<< "    ###\\|/#o#\n"
				<< "     # }|{  #\n"
				<< "       }|{\n";
		fileStream.close();
	}
	
}		
