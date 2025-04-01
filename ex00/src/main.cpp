/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:02:35 by eeklund       #+#    #+#                 */
/*   Updated: 2025/04/01 18:19:54 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat boy(0);
	}
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}