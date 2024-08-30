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
#define COLOR(args)    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), std::stoi(#args,0,16))  //pass a hex value between 00 and ff (or integer equivalent)
#else
#define PATHCOMP strcmp
void COLOR(int arg);
#endif
uint8_t *buffer;
std::string xor_data(uint8_t *buf, int size);
int main(int argc, char* argv[])
{
    std::cout;
    COLOR(0x0f);
    printf("Sheltered SaveFile Converter - By matias Israelson (AKA:El_isra)\n");
    printf("Version [%s]\n",AutoVersion::FULLVERSION_STRING);
    COLOR(0x07);
	if (argc < 3) {
        COLOR(0x0d);
        fprintf(stderr, "Sintax errror.\n\tUsage: %s infile outfile\n",argv[0]);
        COLOR(0x07);
		return 1;
	}
	
    if (!PATHCOMP(argv[1], argv[2])) {
        COLOR(0x0C);
        fprintf(stderr, "error: input and output are the same!\n");
        COLOR(0x07);
        return -1;
    }
    std::vector<uint8_t> bytes;

    std::ifstream file1(argv[1], std::ios_base::in | std::ios_base::binary);
    if (!file1.is_open()) {
        COLOR(0x0C);
        fprintf(stderr, "Could not open %s for input\n", argv[1]);
        COLOR(0x07);
        return 1;
    }
    COLOR(0x07);
    uint8_t ch = file1.get();
    while (file1.good())
    {
        bytes.push_back(ch);
        ch = file1.get();
    }
    size_t n = bytes.size();
    uint8_t *buff = bytes.data();
    printf("input file size: 0x%02lx\n", n);
    std::ofstream out(argv[2], std::ios_base::binary);
    if (!out.is_open()) {
        COLOR(0x0C);
        fprintf(stderr, "Could not open %s for output\n", argv[2]);
        COLOR(0x07);
        return 1;
    }
    out << xor_data(buff, n);
    out.close();
    return 0;
}


std::string xor_data(uint8_t *buf, int size)
{
    int a = 0xAC;
    uint8_t encrypters[17] = {
        0xAC, 0x73, 0xFE, 0xF2, 0xAA, 0xBA, 0x6D, 0xAB,
        0x30, 0x3A, 0x8B, 0xA7, 0xDE, 0x0D, 0x15, 0x21,
        0x4A
    };
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


#if defined(_WIN32) || defined(WIN32)
#else
void COLOR(int arg) {
    switch (arg)
    {
    case 0x0F:
        puts("\e[0;97m"); //strong white
        break;
    case 0x0D:
        puts("\e[0;95m"); //strong magenta
        break;
    case 0x0C:
        puts("\e[0;91m"); //strong red
        break;
    
    case 0x07:
    default:
        puts("\e[0m");
        break;
    }
}
#endif