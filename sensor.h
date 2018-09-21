#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>

#include "segment_tree.h"
#include "Array.h"
#include "data.h"
#include "utis.h"

class sensor
{
private:
	std::string name_;
	segment_tree data_tree_;

public:
	sensor();
	sensor(const std::string&);
	sensor(const std::string&,const Array<data>&);
	data search_interval(size_t,size_t) const;
	std::string name() const;
	friend std::ostream & operator<<(std::ostream&,const sensor&);
};

#endif
