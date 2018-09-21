#ifndef SEG_TREE_H
#define SEG_TREE_H

#include "Array.h"
#include "data.h"

class segment_tree
{
	Array<data> tree_;
	size_t size_;
	
	data _search_interval(size_t,size_t,size_t) const;

	public:
	segment_tree();
	segment_tree(const Array<data> &);
	segment_tree(const segment_tree & );
	data search_interval(size_t ,size_t) const;
	friend std::ostream & operator<<(std::ostream&,const segment_tree&);
};

#endif
