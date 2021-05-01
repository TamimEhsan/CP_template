#include<bits/stdc++.h>
using namespace std;


class Fraction{
	int	num, den;
public:
	void reduce( void );

	// constructors
	Fraction() { num = 0; den = 1; }	// default constructor
	Fraction( int m ) { num = m; den = 1; }
	Fraction( int m, int n ) { num = m; den = n; }

	// access functions
	int Num( void ) const { return this->num; }
	int Den( void ) const { return this->den; }
	int ipart( void );			// integer part
	Fraction fpart( void );			// fractional part

	// unary and binary operators
	Fraction operator -() const { return Fraction( -num, den ); }

	Fraction operator +( const Fraction& ) const;
	Fraction operator -( const Fraction& ) const;
	Fraction operator *( const Fraction& ) const;
	Fraction operator /( const Fraction& ) const;

	// assignment operators
	Fraction operator +=( const Fraction& );
	Fraction operator -=( const Fraction& );
	Fraction operator *=( const Fraction& );
	Fraction operator /=( const Fraction& );

	Fraction operator =( const int );

	// friend functions
	friend int operator ==( const Fraction&, const Fraction& );
	friend int operator !=( const Fraction&, const Fraction& );
	friend int operator < ( const Fraction&, const Fraction& );
	friend int operator > ( const Fraction&, const Fraction& );
	friend int operator <=( const Fraction&, const Fraction& );
	friend int operator >=( const Fraction&, const Fraction& );

	friend int operator ==( const Fraction&, const int& );
	friend int operator !=( const Fraction&, const int& );

	friend Fraction operator / ( const int, const Fraction );
	friend Fraction operator * ( const int, const Fraction );

	friend ostream& operator <<( ostream& s, Fraction& f );
	friend istream& operator >>( istream& s, Fraction& f );

	// output length
	int len( void );
};


int gcd( int m, int n )
{
	int	p = ( m < 0 ) ? -m : m;
	int	q = ( n < 0 ) ? -n : n;
	while ( q ) { int r = p % q; p = q; q = r; }
	return	p;
}


void Fraction::reduce( void )
{
	int	g = gcd( this->num, this->den );
	if ( this->den < 0 ) g = -g;
	if ( g != 0 ) { this->num /= g; this->den /= g; }
}


int Fraction::ipart( void )
{
	int	quot = this->num / this->den;
	int	rem = this->num % this->den;
	if ( rem < 0 ) --quot;
	return	quot;
}


Fraction Fraction::fpart( void )
{
	Fraction	f = *this;
	f -= f.ipart();
	return	f;
}


Fraction Fraction::operator +( const Fraction& f ) const
{
	Fraction	sum;

	sum.num = this->num * f.den + this->den * f.num;
	sum.den = this->den * f.den;
	sum.reduce();
	return	sum;
}


Fraction Fraction::operator -( const Fraction& f ) const
{
	Fraction	diff;

	diff.num = this->num * f.den - this->den * f.num;
	diff.den = this->den * f.den;
	diff.reduce();
	return	diff;
}


Fraction Fraction::operator *( const Fraction& f ) const
{
	Fraction	prod;

	prod.num = this->num * f.num;
	prod.den = this->den * f.den;
	prod.reduce();
	return	prod;
}


Fraction Fraction::operator /( const Fraction& f ) const
{
	Fraction	quot;

	if ( f.num == 0 ) { cerr << "\nDivision by zero!\n"; exit(1); }
	quot.num = this->num * f.den;
	quot.den = this->den * f.num;
	quot.reduce();
	return	quot;
}


Fraction Fraction::operator +=( const Fraction& f )
{
	return *this = *this + f;
}


Fraction Fraction::operator -=( const Fraction& f )
{
	return *this = *this - f;
}


Fraction Fraction::operator *=( const Fraction& f )
{
	return *this = *this * f;
}


Fraction Fraction::operator /=( const Fraction& f )
{
	return *this = *this / f;
}


Fraction Fraction::operator =( const int c )
{
	this->num = c;
	this->den = 1;
	return	*this;
}


int operator ==( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den == f.den * g.num );
}


int operator !=( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den != f.den * g.num );
}


int operator < ( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den < f.den * g.num );
}


int operator > ( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den > f.den * g.num );
}


int operator <=( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den <= f.den * g.num );
}


int operator >=( const Fraction& f, const Fraction& g )
{
	return	( f.num * g.den >= f.den * g.num );
}


int operator ==( const Fraction& f, const int& i )
{
	Fraction	g( i );
	return	( f.num * g.den == f.den * g.num );
}


int operator !=( const Fraction& f, const int& i )
{
	Fraction	g( i );
	return	( f.num * g.den != f.den * g.num );
}


Fraction operator / ( const int i, const Fraction f )
{
		Fraction	recip;
		recip.num = f.den;
		recip.den = f.num * i;
		recip.reduce();
		return	recip;
}


Fraction operator * ( const int i, const Fraction f )
{
		Fraction	prod;
		prod.num = f.num * i;
		prod.den = f.den;
		prod.reduce();
		return	prod;
}


ostream& operator <<( ostream& s, Fraction& f )
{
	if ( f.num < 0 ) s << f.num;
	else	s << ' ' << f.num;
	if ( f.den != 1 ) s << "/" << f.den;
	s << ' ';
	return	s;
}


istream& operator >>( istream& s, Fraction& f )
{
	int	u = 0, v = 1;
	char	c = 0;

	s >> c;
	if ( c == '(' )
		{
		s >> u >> c;
		if ( c == '/' ) s >> v >> c;
		if ( c != ')' ) s.clear( ios::badbit );
		}
	else	{
		s.putback( c );
		s >> u;
		c = s.peek();
		if ( c == '/' ) s >> c >> v;
		}

	if ( s ) { f.num = u; f.den = v; }
	return	s;
}


int Fraction::len( void )
{
	char	line[40];
	int	retval = 0;

	int	n = ( num < 0 ) ? -num : num;
	int	d = den;
	retval += 1 + sprintf( line, "%d", n );
	if ( d != 1 ) retval += 1 + sprintf( line, "%d", d );
	retval += 1;
	return	retval;
}


int main(){

}
