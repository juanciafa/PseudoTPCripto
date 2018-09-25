// Implementación de data

#include <iostream>

#include "data.h"
#include "utis.h"


data::data()
{
	sum_ = max_ = min_ = num_ = start_ = end_ = 0;
}

data::data(double point)
{
	sum_ = max_ = min_ = point;
	num_ = 1;
}

data::data(bool flag, size_t time)
{
	sum_ = max_ = min_ = num_ = 0;
	start_ = time;
	end_ = time+1;
}

data::data(double value,size_t time)
{
	sum_ = max_ = min_ = value;
	num_ = 1;
	start_ = time;
	end_ = time+1;
}

data::data(const data & other)
{
	sum_ = other.sum();
	num_ = other.num();
	max_ = other.max();
	min_ = other.min();
	start_ = other.start();
	end_ = other.end();
}

void data::merge(data & other)
{
	// Asume data contigua

	if( other.num()!=0 && this->num()!=0 )
	{
		sum_ += other.sum();
		num_ += other.num();
		max_ = MAX(this->max(),other.max());
		min_ = MIN(this->min(),other.min());
	}else if( this-> num() == 0 )
	{
		sum_ = other.sum();
		num_ = other.num();
		max_ = other.max();
		min_ = other.min();
	}
	start_ = MIN( start_,other.start() );
	end_ = MAX( end_,other.end() );
}

double data::avr() const{ return sum_/(double)num_; }
double data::sum() const{ return sum_; } 
double data::max() const{ return max_; }
double data::min() const{ return min_; }
size_t data::num() const{ return num_; }
size_t data::start() const{ return start_; }
size_t data::end() const{ return end_; }

data::data(const data & d1,const data& d2)
{
	// Caso que se hayan creado sin argumentos, data()
	if( d1.start() == d1.end() )
	{
		sum_ = d2.sum();
		num_ = d2.num();
		max_ = d2.max();
		min_ = d2.min();
		start_ = d2.start();
		end_ = d2.end();
	}else if( d2.start() == d2.end() )
	{
		sum_ = d1.sum();
		num_ = d1.num();
		max_ = d1.max();
		min_ = d1.min();
		start_ = d1.start();
		end_ = d1.end();
	}else if( d1.num() == 0)
	// Casos que haya un dato faltante, pero está en el tiempo
	{
		sum_ = d2.sum();
		num_ = d2.num();
		max_ = d2.max();
		min_ = d2.min();
		start_ = MIN( d1.start(),d2.start() );
		end_ = MAX( d1.end(),d2.end() );
	}else if( d2.num() == 0)
	{
		sum_ = d1.sum();
		num_ = d1.num();
		max_ = d1.max();
		min_ = d1.min();
		start_ = MIN( d1.start(),d2.start() );
		end_ = MAX( d1.end(),d2.end() );
	}else{
		sum_ = d1.sum() + d2.sum();
		num_ = d1.num() + d2.num();
		max_ = MAX(d1.max(),d2.max());
		min_ = MIN(d1.min(),d2.min());
		start_ = MIN( d1.start(),d2.start() );
		end_ = MAX( d1.end(),d2.end() );
	}
}

std::ostream & operator<<(std::ostream& os,const data& d)
{
	os << d.avr()
	   << ","
	   << d.min()
	   << ","
	   << d.max()
	   << ","
	   << d.num();

	return os;
}
const data& data::operator=(const data & other)
{
	sum_ = other.sum();
	num_ = other.num();
	max_ = other.max();
	min_ = other.min();
	start_ = other.start();
	end_ = other.end();

	return *this;
}
