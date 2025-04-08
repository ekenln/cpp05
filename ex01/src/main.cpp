/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/08 15:12:41 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat Zalazar("Zalazar", 3);
		Bureaucrat Pettigrew("Pettigrew", 50);
		Bureaucrat Sirius("Sirius", 40);

		std::cout << "\nconstructing forms.....\n";
		Form clownForm("clownForm", 10, 50);
		Form hogsmeadePermit("hogsmeadePermit", 100, 120);
		Form theForm("theForm", 4, 1);

		std::cout << "----Forms before signing ---\n";
		std::cout << clownForm << std::endl;
		std::cout << hogsmeadePermit << std::endl;
		std::cout << theForm << std::endl;

		std::cout << "\n--- Signing attempts ---\n";
		Zalazar.signForm(clownForm);
		Sirius.signForm(hogsmeadePermit);
		Pettigrew.signForm(theForm);

		std::cout << "\n--- Forms after signing ---\n";
		std::cout << clownForm << std::endl;
		std::cout << hogsmeadePermit << std::endl;
		std::cout << theForm << std::endl;
	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n---trying to create form with out of bounds grade----\n";
		Form crazyForm("CrayCray", 0, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	return 0;
}
