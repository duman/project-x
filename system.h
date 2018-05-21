#ifndef SYSTEM_H
#define SYSTEM_H

#include "monster.h"
#include "player.h"
#include <string>
#include <fstream>
using namespace std;

class systemclass
{
	string sysmsg_;
public:
	static void battle_information(player&, monster&);
};

inline string xor_encrypt_decrypt_spec(string to_encrypt, const char key) {
	auto output = to_encrypt;
    
    for (auto i = 0; i < static_cast<int>(to_encrypt.size()); i++)
        output[i] = to_encrypt[i] ^ key;

    return output;
}

inline string init_settings(const string& file_name, const int setting_pos, const char key)
{
	ifstream dumanif;
	dumanif.open(file_name);
	string line;
	auto counter = 0;
	if (dumanif.is_open())
	{
		while (getline(dumanif, line))
		{
			if(counter == setting_pos)
			{
				dumanif.close();
				return xor_encrypt_decrypt_spec(line, key);
			}

			counter++;
		}
		dumanif.close();
	}
	return "";
}

#endif
