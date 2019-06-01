#include "s.h"
#include <windows.h>
void manual()
{
	printf("\nstr--------------------------------create street\n");
	printf("he-----------------------------------adds empty home\n");
	printf("+h-----------------------------------adds home\n");
	printf("rf-----------------------------------read file\n");
	printf("wf-----------------------------------write file\n");
	printf("pr-----------------------------------cmd printf\n");
	printf("er-----------------------------------erases chosen element\n");
	printf("pf-----------------------------------delete first element\n");
	printf("pb-----------------------------------delete last element\n");
	printf("sort---------------------------------sort list\n");
	printf("sbp----------------------------------search by <>\n");
	printf("edh----------------------------------edit home hint[eds parameter -> edh]\n");
	printf("eds----------------------------------edit street\n");
	printf("cls----------------------------------cmd cls\n");
	printf("cmd----------------------------------cmd\n");
	printf("q------------------------------------close session\n");
	printf("\n");
}
int main(int argc, char *argv[])
{
	printf("***********************************************************************************************************************\n");
	printf("    HW build v1.01\n");
	printf("***********************************************************************************************************************\n");
	s s_;
	while (1)
	{
		std::string str;
		getline(std::cin, str);
		if (str == "cmd")
		{
			system("cmd");
		}
		else if (str == "he")
		{
			h h_;
			s_ + h_;
		}
		else if (str == "+h")
		{
			printf("[number, condition, residents, debt]\n");
			h h_;
			std::cin >> h_;
			s_ + h_;
		}
		else if (str == "str")
		{
			printf("[street, index, condition]\n");
			std::cin >> s_;
		}
		else if (str == "man")
		{
			manual();
		}
		else if (str == "rf")
		{
			h h_;
			size_t numlist = (argc - 3) / 4;
			for(size_t iterator=0; iterator!=argc; ++iterator)
			{
				s_ + h_;
			}
			s_ + h_;
			rf(s_);
		}
		else if (str == "wf")
		{
			wf(s_);
		}
		else if (str == "pr")
		{
			s_.print();
		}
		else if (str == "er")
		{
			s_.erase();
		}
		else if (str == "pf")
		{
			s_.pop_front();
		}
		else if (str == "pb")
		{
			s_.pop_back();
		}
		else if (str == "sort")
		{
			s_.sort();
		}
		else if (str == "sbp")
		{
			s_.search();
		}
		else if (str == "eds")
		{
			s_.edit_street();
		}
		else if (str == "q")
		{
			return 0;
		}
		else if (str == "cls")
		{
			system("cls");
		}
	}
	system("pause");
}