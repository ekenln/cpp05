/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/08 14:52:41 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat funBoy("funBoy", 130);
		std::cout << funBoy;
		funBoy.incrementGrade();
		std::cout << funBoy;
		funBoy.decrementGrade();
		std::cout << funBoy;
		Bureaucrat boy(1);
		boy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "caught exception: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat boy(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "caught exception: " << e.what() << '\n';
	}
	return 0;
}