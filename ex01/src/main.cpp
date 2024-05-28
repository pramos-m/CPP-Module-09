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
