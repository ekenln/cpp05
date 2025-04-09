/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/06 14:09:37 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/04/09 17:39:02 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& old);
		Intern&	operator=(const Intern& B);
		AForm	*makeForm(std::string form, std::string target);
};