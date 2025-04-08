/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/08 13:00:06 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat boy2("funBoy", 130);
		std::cout << boy2;
		boy2.incrementGrade();
		std::cout << boy2;
		Bureaucrat boy(1);
		boy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "caught exception: " << e.what() << '\n';
	}
	return 0;
}