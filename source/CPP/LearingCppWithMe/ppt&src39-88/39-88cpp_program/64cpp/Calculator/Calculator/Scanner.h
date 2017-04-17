#ifndef _SCANNER_H_
#define _SCANNER_H_
#include <string>
//#include <iostream>

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
public:
	explicit Scanner(std::istream& in);
	void Accept();
	bool IsEmpty() const;
	bool IsDone() const;
	double Number() const;
	std::string GetSymbol() const;
	EToken Token() const;
private:
	void ReadChar();
	//const std::string buf_;
	std::istream& in_;
	int look_;
	EToken token_;
	double number_;
	std::string symbol_;
	bool isEmpty_;
};

#endif // _SCANNER_H_
