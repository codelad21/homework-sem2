#include "s.h"
s::s() : street(" "), street_index(" "), condition(0), home_list(0)
{ }
s::s(std::string street, std::string street_index, bool condition, std::list<h> home_list) :
	street(street), street_index(street_index), condition(condition), home_list(home_list)
{ }
s & s::operator +(h & h_)
{
	home_list.push_back(h_);
	return *this;
}
void rf(s & s_)
{
	std::string str;
	printf("file:");
	getline(std::cin, str);
	std::ifstream in(str);
	if (in.is_open())
	{
		in >> s_;
		for (auto iterator = s_.home_list.begin(); iterator != s_.home_list.end(); ++iterator)
		{
			in >> *iterator;
		}
	}
	in.close();
}
void wf(s & s_)
{
	std::string str;
	printf("file:");
	getline(std::cin, str);
	std::ofstream out;
	out.open(str);
	if (out.is_open())
	{
		out << s_.street
			<< '\n'
			<< s_.street_index
			<< '\n'
			<< s_.condition
			<< '\n';
		for (auto iterator = s_.home_list.begin(); iterator != s_.home_list.end(); ++iterator)
		{
			out << *iterator;
		}
	}
	out.close();
}
void s::print()
{
	std::cout << (*this);
}
void s::erase()
{
	int pos;
	std::cin >> pos;
	std::list<h>::iterator erase_iterator = home_list.begin();
	std::advance(erase_iterator, pos);
	home_list.erase(erase_iterator);
}
void s::pop_front()
{
	if (!home_list.empty())
	{
		home_list.pop_front();
	}
}
void s::pop_back()
{
	if (!home_list.empty())
	{
		home_list.pop_back();
	}
}
std::istream & operator >>(std::istream &in, s &s_)
{
	std::getline(in, s_.street);
	std::getline(in, s_.street_index);
	in >> s_.condition;
	return in;
}
std::ostream & operator <<(std::ostream &out, const s & s_)
{
	printf("\nstreet: ");
	out << s_.street;
	printf("\nindex: ");
	out << s_.street_index;
	printf("\ncondition: ");
	if (s_.condition == true)
	{
		printf("<acceptable>");
	}
	else
	{
		printf("<unacceptable>");
	}
	for (auto iterator = s_.home_list.begin(); iterator != s_.home_list.end(); ++iterator)
	{
			out << *iterator;
	}
	return out;
}
void s::sort()
{
	std::string str;
	printf("parameter\n");
	getline(std::cin, str);
	if (str == "number")
	{
		sort_alg();
	}
	else
	{
		printf("developing");
	}
}
void s::sort_alg()
{
	home_list.sort(std::greater<h>());
	printf("check? [yes/no]\n");
	std::string str;
	getline(std::cin, str);
	try
	{
		if (str == "yes")
		{
			copy(home_list.begin(), home_list.end(), std::ostream_iterator<h>(std::cout, "\n"));
		}
		else if (str == "no")
		{
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
void s::edit_street()
{
	printf("parameter\n");
	std::string str;
	getline(std::cin, str);
	try
	{
		if (str == "street")
		{
			std::cin >> street;
			return;
		}
		else if (str == "condition")
		{
			std::cin >> condition;
		}
		else if (str == "street index")
		{
			std::cin >> street_index;
			return;
		}
		else if (str == "edh")
		{
			printf("number [list]?\n");
			size_t h;
			std::cin >> h;
			size_t iterator_ = 0;
			for (auto iterator = home_list.begin(); iterator != home_list.end(); ++iterator)
			{
				if (iterator_ == h)
				{
					iterator->edit_home();
				}
				++iterator_;
			}
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
void s::search()
{
	std::string str;
	printf("parameter\n");
	getline(std::cin, str);
	try
	{
		if (str == "number")
		{
			int number_;
			std::cin >> number_;
			for (auto iterator = home_list.begin(); iterator != home_list.end(); ++iterator)
			{
				if (iterator->get_number() == number_)
				{
					std::cout << *iterator;
					return;
				}
			}
			printf("not found");
		}
		else if (str == "condition")
		{
			std::cin >> condition;
			for (auto iterator = home_list.begin(); iterator != home_list.end(); ++iterator)
			{
				if (iterator->get_condition() == condition)
				{
					std::cout << *iterator;
					return;
				}
				printf("not found");
				return;
			}
		}
		else if (str == "residents")
		{
			int residents_;
			std::cin >> residents_;
			for (auto iterator = home_list.begin(); iterator != home_list.end(); ++iterator)
			{
				if (iterator->get_residents() == residents_)
				{
					std::cout << *iterator;
					return;
				}
				printf("not found");
				return;
			}
		}
		else if (str == "debt")
		{
			double debt_;
			std::cin >> debt_;
			for (auto iterator = home_list.begin(); iterator != home_list.end(); ++iterator)
			{
				if (iterator->get_debt() == debt_)
				{
					std::cout << *iterator;
					return;
				}
				printf("not found");
				return;
			}
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
s::~s()
{ }