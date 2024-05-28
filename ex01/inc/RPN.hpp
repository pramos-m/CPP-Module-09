#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

#define ALLOWED_OPERATIONS_SIZE 4

class RPN
{
	private:
		RPN( void );
		RPN( const RPN& rpn );
		~RPN( void );
		RPN&		operator=( const RPN& rpn );
		static void	checkRes( std::stack< int >& storage );
		static bool	isOperation( char c, std::stack< int >& storage );
		static void	doAddition( std::stack< int >& storage );
		static void	doSubstraction( std::stack< int >& storage );
		static void	doMultiplication( std::stack< int >& storage );
		static void	doDivision( std::stack< int >& storage );
	public:
		static void	calculate( std::string operation );
};
