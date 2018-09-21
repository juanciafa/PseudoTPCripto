#include <iostream>

#include "segment_tree.h"
#include "Array.h"
#include "data.h"
#include "utis.h"

segment_tree::segment_tree()
{
	size_ = 0;
	tree_ = Array<data>();
};

size_t upper_power_of_two(size_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;

}

segment_tree::segment_tree(const segment_tree & other)
{
	tree_ = other.tree_;
	size_ = other.size_;
}

segment_tree::segment_tree(const Array<data> & arr)
{
	// El arbol tendra la forma:
	// __________________
	//|_|__|____|________|
	// Es decir, tree_[0] es el nodo en el mayor nivel, y después van 
	// los hijos.
	// El arreglo original se encuentra desde tree_.size() hasta el final

	size_t final_size;

	final_size = 2 * upper_power_of_two( arr.size() ) - 1;
	tree_ = Array<data> (final_size);
	size_ = (final_size + 1)/2;
	for (size_t i= tree_.size()-size_; i-size_+1<arr.size() ; i++)
	{
		tree_[i] = arr[i-size_+1];
	}
	for (size_t i= tree_.size()-size_+arr.size() ; i<tree_.size(); i++)
	{
		data d;
		tree_[i] = d;
	}
	for (int i=tree_.size()-size_-1 ; i>=0 ; i--)
	{
		tree_[i] = data( tree_[i*2+1] , tree_[i*2+2] ); // hijos
		// Esto es como estaba antes
		// tree_[i] = data( tree_[(i-size_)*2],tree_[(i-size_)*2+1] );
	}
}

data segment_tree::search_interval(size_t start, size_t end) const
{
	data root,left,right;
	size_t pos_root,pos_l,pos_r;

	// Reviso si el nodo está completamente contenido en la query. Si lo es, me sirve, si no, sigo buscando	
	root = tree_[0];
	pos_root = 0;
	if( start > root.end() || end < root.start() )
		return data();
	if( start == root.start() && end == root.end() )
		return root;
	else
	{
		// nodo izquierdo
		pos_l = pos_root*2+1 ;
		left = this->_search_interval( pos_l, start, MIN(end,tree_[pos_l].end() ));

		// nodo derecho
		pos_r = pos_l + 1;
		right = this->_search_interval( pos_r, MAX(start,tree_[pos_r].start()),end);

		return data(left,right);
	}
}
data segment_tree::_search_interval(size_t pos, size_t start, size_t end) const
{
	data root,left,right;
	size_t pos_l,pos_r;
	// Me fijo si es hoja
	if(pos >= tree_.size()-size_)
	{
		if( start == tree_[pos].start() && end == tree_[pos].end())
		
			return tree_[pos];
		else
			return data();
	}
	root = tree_[pos];
	if( start == root.start() && end == root.end() )
		return root;
	else
	{
		pos_l = pos*2+1 ;
		left = this->_search_interval( pos_l, start, MIN(end,tree_[pos_l].end() ));

		// nodo derecho
		pos_r = pos_l + 1;
		right = this->_search_interval( pos_r, MAX(start,tree_[pos_r].start()),end);
		
		return data(left,right);
	}
	
	
} 

std::ostream & operator<<(std::ostream& os,const segment_tree& stree)
{
	for( size_t i=0 ; i<stree.tree_.size() ; i++)
	{
		std::cout << stree.tree_[i] << std::endl;
	}
	return os;
}
