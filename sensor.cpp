
#include <iostream>
#include <string>

#include "sensor.h"
#include "segment_tree.h"
#include "Array.h"
#include "data.h"
#include "utis.h"

sensor::sensor()
{
	name_ = "NO_NAME";
	data_tree_ = segment_tree();
}

sensor::sensor(const std::string & name, const Array<data> & arr_data)
{
	name_ = name;
	data_tree_ = segment_tree(arr_data);
}

data sensor::search_interval(size_t start, size_t end) const
{
	return data_tree_.search_interval(start,end);
}

std::string sensor::name() const
{
	return name_;
}


std::ostream & operator<<(std::ostream& os,const sensor& sen)
{
	os << sen.name() << std::endl;
	os << sen.data_tree_ << std::endl;

	return os;
}
