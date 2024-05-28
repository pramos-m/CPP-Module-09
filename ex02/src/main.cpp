#include <iostream>
#include "PmergeMe.hpp"

int main( int ac, char **argv )
{
	int	exitStatus;

	exitStatus = 0;
	if ( ac < 2 )
	{
		std::cerr << "Too few numbers to sort" << std::endl;
		return ( 1 );
	}
	try
	{
		PmergeMe::mergeInsertionSort( &argv[ 1 ] );
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
		if ( strstr( e.what(), "Is not sorted" ) != NULL )
			exitStatus = 1;
	}
	return ( exitStatus );
}
