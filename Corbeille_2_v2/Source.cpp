#include <iostream>
#include <fstream>
#include "CLfile.h"
#include "CLcrypt.h"

int main()
{
	std::string key("MIDI LES ZOULOUS");
	std::string path("C:/Users/Linkin/source/repos/Corbeille_2_v2/Corbeille_2_v2/Text.txt");
	//std::string path("C:/Users/Linkin/Desktop/Screenshot_2.png");

	CLfile fichier;
	CLcrypt dictionary{ 5 };
	CLcrypt dictionary2{ 21 };

	fichier.crypter(3, path, dictionary, key);
	//fichier.setSizeFile(1438);// SI ON VEUT LE FAIRE EN DEUX FOIS
	fichier.decrypter(3, path, dictionary2, key);


	return 0;
}