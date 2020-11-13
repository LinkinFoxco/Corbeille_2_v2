#pragma once
#include <iostream>

class CLcrypt
{
public:
	CLcrypt();
	CLcrypt(int);
	char* getClear() { return Clear; }
	char* getCrypted() { return Crypted; }
	friend class CLfile;

private:
	static std::string Cesar(std::string, CLcrypt&);
	static char* Cesar(char*, int, CLcrypt&);
	static char* xOR(std::string, std::string);
	void initialiser(int);
	char Clear[96] = { 0 };
	char Crypted[97] = { 0 };
};

