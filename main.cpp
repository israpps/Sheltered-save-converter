/***************************************************************
 * Name:      Sheltered save file converter
 * Purpose:   decrypt/encrypt sheltered save files
 * Author:    matias israelson (aka: El_isra) (israelson-matias@hotmail.com)
 * Created:   2021-08-06
 * Copyright: matias israelson (aka: El_isra) (https://github.com/israpps)
 * License:   GPL-3.0
 **************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

#include <string>
#include <stdint.h>
#include <sys/stat.h>
#include <stdio.h>
#include <cstring>

#include "version.h"

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#define PATHCOMP strcasecmp //windows is case insensitive!
#define COLOR(args)    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),stoi(#args,0,16));  //pass a hex value between 00 and ff (or integer equivalent)
#else
#define PATHCOMP strcmp
#define COLOR(args)
#endif

uint8_t *buffer;
std::string xor_data(uint8_t *buf, int size);
int main(int argc, char* argv[])
{
    COLOR(0f)
    printf("Sheltered SaveFile Converter - By matias Israelson (AKA:El_isra)\n");
    printf("Version [%s]\n",AutoVersion::FULLVERSION_STRING);
    COLOR(07)
	if(argc < 3) {
        COLOR(0d)
        fprintf(stderr, "Sintax errror.\n\tUsage: %s infile outfile\n",argv[0]);
        COLOR(07)
		return 1;
	}
	
    if (!PATHCOMP(argv[1], argv[2]) {
        fprintf(stderr, "error: input and output are the same!\n");
        return -1
    }
    vector<uint8_t> bytes;

    ifstream file1(argv[1], ios_base::in | ios_base::binary);
    if (!file1.is_open()) {
        COLOR(0C)
        fprintf(stderr, "Could not open %s for input\n", argv[1]);
        COLOR(07)
        return 1;
    }
    COLOR(07)
    while (file1.good())
    {
        bytes.push_back(file1.get());
    }
    size_t n = bytes.size();
    uint8_t* buff = bytes.data();

    std::ofstream out(argv[2], ios_base::binary);
    if (!out.is_open()) {
        COLOR(0C)
        fprintf(stderr, "Could not open %s for output\n", argv[2]);
        COLOR(07)
        return 1;
    }
    out << xor_data(buff, n);
    out.close();
    return 0;
}


std::string xor_data(uint8_t *buf,int size)
{
    uint8_t encrypters[17] = {172, 115, 254, 242, 170, 186, 109, 171, 48, 58, 139, 167, 222, 13, 21, 33, 74};
    std::string output;
    for(int i = 0; i < size; i++)
    {
        uint8_t oldValue = buf[i];
        uint8_t encrypter = encrypters[i % 17];
        buf[i] = oldValue ^ encrypter;
        output += (uint8_t)buf[i];
    }
    return output;
}
