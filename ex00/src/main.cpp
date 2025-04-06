/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/05 19:23:39 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main( void )
{
	// try
	// {
	// 	Bureaucrat boy(0);
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
	// } 
	// catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Caught exception: " << e.what() << std::endl;
	// }
	try
	{
		Bureaucrat boy2("funBoy", 130);
		std::cout << boy2;
		boy2.incrementGrade();
		std::cout << boy2;
		Bureaucrat boy(0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "caught exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "caught exception: " << e.what() << '\n';
	}
	return 0;
}