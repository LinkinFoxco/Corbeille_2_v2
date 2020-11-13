#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "CLcrypt.h"

class CLfile
{
public:
	static void ecrire(const std::string&, const std::string&);
	static void ecrireBinary(const std::string&, const char *);
	std::string lire(const std::string&);
	std::string lireBinary(const std::string&);
	void crypter(int, std::string&, CLcrypt&, std::string&);
	void decrypter(int, std::string&, CLcrypt&, std::string&);
	void setSizeFile(int);

private:
	static int fileSize(const std::string&);
	static int sizeFile;
};