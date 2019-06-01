#include "h.h"
h::h() : number(0), condition(0), residents(0), debt(0)
{ }
h::h(int number, bool condition, int residents, double debt) :
	number(number), condition(condition), residents(residents), debt(debt)
{ }
int h::get_number()
{
	return number;
}
bool h::get_condition()
{
	return condition;
}
int h::get_residents()
{
	return residents;
}
double h::get_debt()
{
	return debt;
}
h & h::operator =(h &h_)
{
	number = h_.number;
	condition = h_.condition;
	residents = h_.residents;
	debt = h_.debt;
	return (*this);
}
void h::edit_home()
{
	printf("parameter\n");
	std::cin.ignore();
	std::string str;
	getline(std::cin, str);
	try
	{
		if (str == "number")
		{
			std::cin >> number;
			return;
		}
		else if (str == "condition")
		{
			std::cin >> condition;
			return;
		}
		else if (str == "residents")
		{
			std::cin >> residents;
			return;
		}
		else if (str == "debt")
		{
			std::cin >> debt;
			return;
		}
		else
		{
			throw "WRONG_ARGUEMENT\n";
		}
	}
	catch (char &exception_name)
	{
		printf("EXCEPTION_");
		printf(&exception_name);
	}
}
bool operator >(const h h_, const h & h__)
{
	return (h_.number > h__.number);
}
std::istream & operator >>(std::istream &in, h & h_)
{
	in >> h_.number;
	in >> h_.condition;
	in >> h_.residents;
	in >> h_.debt;
	return in;
}
std::ostream & operator <<(std::ostream &out, const h & h_)
{
	printf("\n####");
	printf("\nnumber: ");
	out << h_.number;
	printf("\ncondition: ");
	if (h_.condition == true)
	{
		printf("<acceptable>");
	}
	else
	{
		printf("<unacceptable>");
	}
	printf("\nresidents: ");
	out << h_.residents;
	printf("\ndebt: ");
	out << h_.debt;
	return out;
}
h::~h()
{ }