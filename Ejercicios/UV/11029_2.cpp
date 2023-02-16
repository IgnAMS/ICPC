#include <iostream>
#include <iomanip>
using namespace std ;

#include <cmath>

inline int find_last_digits( int n_remainder , int k )
{
	int temp ;
	if( k == 0 )
	{
		return 1 ;
	}
	else if( k == 1 )
	{
		return n_remainder ;
	}
	else if( k % 2 == 1 )
	{
		temp = find_last_digits( n_remainder , k / 2 ) ;
		temp = ( temp * temp ) % 1000 ;
		temp = ( temp * n_remainder ) % 1000 ;
		return temp ;
	}
	else
	{
		temp = find_last_digits( n_remainder , k / 2 ) ;
		temp = ( temp * temp ) % 1000 ;
		return temp ;
	}
}

int main()
{
	int T , n , k , n_remainder, last_digits , first_digits ;
	double log_n , log_10 = log( 10.0 ) ;

	cin >> T ;

	for( int i = 1 ; i <= T ; i++ )
	{
		cin >> n >> k ;

		n_remainder = n % 1000 ;

		last_digits = find_last_digits( n_remainder , k ) ;

		log_n = log( n ) / log_10 ;
		log_n -= static_cast<int>( log_n ) ;

		log_n *= k ;
		log_n -= static_cast<int>( log_n ) ;

		first_digits = static_cast<int>( pow( 10 , log_n ) * 100.0 ) ;

		cout << first_digits << "..." << setw( 3 ) << setfill( '0' ) << last_digits << endl ;
	}

	return 0 ;
}