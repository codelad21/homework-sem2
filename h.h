#ifndef H_H
#define H_H
#include "hlib.h"
class h
{
protected:
	int number;
	bool condition;
	int residents;
	double debt;
public:
	h();
	h(int number, bool condition, int residents, double debt);
	int get_number();
	bool get_condition();
	int get_residents();
	double get_debt();
	h & operator=(h & h_);
	void edit_home();
	friend bool operator >(const h h_, const h & h__);
	friend std::istream & operator >>(std::istream &in, h & h_);
	friend std::ostream & operator <<(std::ostream &out, const h & h_);
	~h();
};
#endif
