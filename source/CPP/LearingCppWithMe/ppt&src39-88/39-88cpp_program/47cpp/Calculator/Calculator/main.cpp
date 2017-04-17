#include <iostream>
#include <string>
#include "Scanner.h"
#include "Parser.h"
#include "Calc.h"

int main(void)
{
	Calc calc;
	STATUS status = STATUS_OK;
	do 
	{
		std::cout<<"> ";
		std::string buf;
		std::getline(std::cin, buf);
		//std::cout<<buf<<std::endl;
		Scanner scanner(buf);
		Parser parser(scanner, calc);
		parser.Parse();
		std::cout<<parser.Calculate()<<std::endl;
	} while (status != STATUS_QUIT);
	return 0;
}