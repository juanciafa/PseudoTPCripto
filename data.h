#ifndef DATA_H
#define DATA_H

class data
{
	double sum_;
	size_t num_;
	double max_ , min_;
	size_t start_,end_;

	data(double);

	public:
	data();
	data(double,size_t);
	data(const data &);
	data(const data &,const data&);
	void merge(data &);
	double avr() const;
	double sum() const;
	double max() const;
	double min() const;
	size_t num() const;
	size_t start() const;
	size_t end() const;
	friend std::ostream & operator<<(std::ostream&,const data&);
	const data& operator=(const data &);
	// friend data merge(data&,data&);
};

#endif
