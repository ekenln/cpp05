/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 11:09:13 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/06 12:35:17 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public: 

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& old);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& S) = delete;

		void	execute(Bureaucrat const & executor) const;
};