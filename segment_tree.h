#ifndef SEG_TREE_H
#define SEG_TREE_H

#include "Array.h"
#include "data.h"

class segment_tree
{
	Array<data> tree_;
	size_t size_;
	
	segment_tree();
	data _search_interval(size_t,size_t,size_t);

	public:
	segment_tree(const Array<data> &);
	data search_interval(size_t ,size_t);
	friend std::ostream & operator<<(std::ostream&,const segment_tree&);
};

#endif
