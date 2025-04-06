/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/06 10:51:03 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/Bureaucrat.hpp"

// int main( void )
// {
// 	// try
// 	// {
// 	// 	Bureaucrat boy(0);
// 	// }
// 	// catch (const Bureaucrat::GradeTooHighException& e) {
// 	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
// 	// } 
// 	// catch (const Bureaucrat::GradeTooLowException& e) {
// 	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
// 	// }
// 	try
// 	{
// 		Bureaucrat boy2("funBoy", 130);
// 		std::cout << boy2;
// 		boy2.incrementGrade();
// 		std::cout << boy2;
// 		Bureaucrat boy(0);
// 	}
// 	catch(const Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cerr << "caught exception: " << e.what() << '\n';
// 	}
// 	catch(const Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cerr << "caught exception: " << e.what() << '\n';
// 	}
// 	return 0;
// }

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		// Create Bureaucrats with different grades
		Bureaucrat john("John", 3);
		Bureaucrat bob("Bob", 50);
		Bureaucrat jim("Jim", 150);

		// Create Forms with different required grades
		Form taxForm("TaxForm", 10, 50);
		Form travelPermit("TravelPermit", 100, 120);
		Form launchCode("LaunchCode", 4, 1);

		std::cout << "\n--- Forms before signing ---\n";
		std::cout << taxForm << std::endl;
		std::cout << travelPermit << std::endl;
		std::cout << launchCode << std::endl;

		std::cout << "\n--- Signing attempts ---\n";
		john.signForm(taxForm);         // should succeed
		bob.signForm(travelPermit);     // should succeed
		jim.signForm(launchCode);       // should fail

		std::cout << "\n--- Another signing attempt ---\n";
		john.signForm(launchCode);      // should succeed

		// Display forms after signing
		std::cout << "\n--- Forms after signing ---\n";
		std::cout << taxForm << std::endl;
		std::cout << travelPermit << std::endl;
		std::cout << launchCode << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	return 0;
}

