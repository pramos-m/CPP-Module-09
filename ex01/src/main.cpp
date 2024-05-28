/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:51:27 by pramos-m          #+#    #+#             */
/*   Updated: 2024/05/28 16:51:28 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main( int ac, char **argv )
{
	if ( ac != 2 )
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return ( 1 );
	}
	try
	{
		RPN::calculate( argv[ 1 ] );
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
		return ( 1 );
	}
	return ( 0 );
}
