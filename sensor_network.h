#ifndef SENSOR_NETWORK_H
#define SENSOR_NETWORK_H

#include <iostream>
#include <string>

#include "segment_tree.h"
#include "Array.h"
#include "data.h"
#include "utis.h"

class sensor_network
{
private:
	Array<sensor> sensors;
public:
	sensor_network();
	sensor_network(const std::istream &);
	data search(std::string,size_t,size_t);
	//data search(query);
}

#endif
