#ifndef S_H
#define S_H
#include "h.h"
class s : public h
{
protected:
	std::string street;
	std::string street_index;
	bool condition;
	std::list<h> home_list;
public:
	s();
	s(std::string street, std::string street_index, bool condition, std::list<h> home_list);
	s & operator +(h & h_);
	friend void rf(s & s_);
	friend void wf(s & s_);
	void print();
	void erase();
	void pop_front();
	void pop_back();
	friend std::istream & operator >>(std::istream &in, s &s_);
	friend std::ostream & operator <<(std::ostream &out, const s & s_);
	void sort();
	void sort_alg();
	void edit_street();
	void search();
	~s();
};
#endif
