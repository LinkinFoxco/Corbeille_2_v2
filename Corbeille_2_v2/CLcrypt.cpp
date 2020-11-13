#include "CLcrypt.h"
#include <iostream>

CLcrypt::CLcrypt()
{
	initialiser(0);
}
CLcrypt::CLcrypt(int decalage)
{
	initialiser(decalage);
}

void CLcrypt::initialiser(int decalage)
{
	int i = 0;
	int letter(32);
	for (i = 0; i < 94; i++)
	{
		Clear[i] = (char)letter;
		letter++;
	}
	Clear[94] = '\n';
	Clear[95] = '\a';
	Clear[95] = '\0';
	
	for (i = 0; i < 96; i++)
		Crypted[i] = Clear[i];

	int place;
	for (i = 33; i < 59; i++)
	{
		if ((i+decalage) >= 59)
			place = (i+decalage) % 59 + 33;
		else 
			place = i + decalage;

		Crypted[i] = Clear[place];
	}
	for (i = 65; i < 91; i++)
	{
		if ((i + decalage) >= 91)
			place = (i + decalage) % 91 + 65;
		else 
			place = i + decalage;

		Crypted[i] = Clear[place];
	}
}

std::string CLcrypt::Cesar(std::string text, CLcrypt& obj)
{
	int j = 0;
	std::string textCesar;
	for (int i = 0; i <= (text.length()-1); i++)
	{
		while (text[i] != obj.Clear[j])
		{
				j++;
		}
		textCesar.append(1, obj.Crypted[j]);
		j = 0;
	}

	return textCesar;
}

char* CLcrypt::Cesar(char* text, int sizeFile, CLcrypt& obj)
{

	int j = 0;
	for (int i = 0; i <= (sizeFile - 1); i++)
	{
		while (text[i] != obj.Clear[j])
		{
				j++;
		}
		text[i] = obj.Crypted[j];
		j = 0;
	}

	return text;
}

char* CLcrypt::xOR(std::string text, std::string key)
{
	char c;
	char* tab = new char[text.length()+1];
	memset(tab, 0, text.length() + 1);
	for (int i = 0; i < text.length(); i++)
	{
		c = text[i];
		for (int j = 0; j <= key.length(); j++)
		{
			c = c ^ key[j];
		}
		tab[i] = c;
	}
	tab[text.length()] = '\0';

	return tab;
}