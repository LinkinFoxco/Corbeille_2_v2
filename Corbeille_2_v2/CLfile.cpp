#include <iostream>
#include <fstream>
#include <string>
#include "CLfile.h"
#include "CLcrypt.h"


int CLfile::sizeFile = 0;

void CLfile::ecrire(const std::string& path , const std::string& texte)
{
	std::ofstream file(path);

	file << texte;

	file.close();
	std::cout << std::endl;
}

void CLfile::ecrireBinary(const std::string& path, const char* tab)
{
	std::string tempPath = path;
	//tempPath.append(".txt");

	FILE* fileWrite = fopen(tempPath.c_str(), "w+b");
	fwrite(tab, 1, sizeFile, fileWrite);

	delete[] tab;
	fclose(fileWrite);
}

std::string CLfile::lire(const std::string& path)
{
	std::string line;
	std::string texte;
	std::ifstream file( path );

	while (std::getline(file, line))
	{
		texte.append(line);
		texte.append("\n");
	}

	file.close();
	return texte;
}

std::string CLfile::lireBinary(const std::string& path)
{
	sizeFile = fileSize(path);
	std::string text;
	FILE* file = fopen(path.c_str(), "r+b");

	char c = fgetc(file);
	while (c != EOF)
	{
		text.append(1, c);
		c = fgetc(file);
	}
	text.append(1, '\0');

	fclose(file);
	return text;
}


//std::string CLfile::lireBinary(const std::string& path)
//{
//	int size = fileSize(path);
//	char* data = new char[size+1];
//	FILE* file = fopen(path.c_str(), "r+b");
//	char c = fgetc(file);
//
//	char* head = data;
//	while (c != EOF)
//	{
//		*head = (char)c;
//		head++;
//		c = fgetc(file);
//	}
//	*head = '\0';
//
//	fclose(file);
//	delete[] data;
//}


int CLfile::fileSize(const std::string& path)
{
	std::ifstream file(path, std::ios::binary | std::ios::ate);
	int fileSize = file.tellg();

	file.close();
	sizeFile = fileSize;
	return fileSize;
}

void CLfile::setSizeFile(int size)
{
	sizeFile = size;
}

void CLfile::crypter(int type, std::string& path, CLcrypt& dictionary, std::string& key)
{
	if (type == 1)
		ecrire(path, CLcrypt::Cesar(lire(path), dictionary));
	else if (type == 2)
		ecrireBinary(path, CLcrypt::xOR(lireBinary(path),key));
	else if (type == 3)
		ecrireBinary(path, CLcrypt::xOR(CLcrypt::Cesar(lireBinary(path),dictionary),key));
	else
		std::cout << "\aError" << std::endl;
}

void CLfile::decrypter(int type, std::string& path, CLcrypt& dictionary, std::string& key)
{
	if (type == 1)
		ecrire(path, CLcrypt::Cesar(lire(path), dictionary));
	else if (type == 2)
		ecrireBinary(path, CLcrypt::xOR(lireBinary(path), key));
	else if (type == 3)
		ecrireBinary(path, CLcrypt::Cesar(CLcrypt::xOR(lireBinary(path), key), sizeFile, dictionary));
	else
		std::cout << "\aError" << std::endl;
}