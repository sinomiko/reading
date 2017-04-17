#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"

int main(void)
{
	Calc calc;
	STATUS status;
	do 
	{
		std::cout<<"> ";
		std::string buf;
		std::getline(std::cin, buf);
		//std::cout<<buf<<std::endl;
		Scanner scanner(buf);
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, calc);
			status = parser.Parse();
			if (status == STATUS_OK)
			{
				std::cout<<parser.Calculate()<<std::endl;
			}
			else
				std::cout<<"Syntax Error."<<std::endl;
			
		}
		else
			std::cout<<"Expression is empty."<<std::endl;
		
	} while (status != STATUS_QUIT);
	return 0;
}