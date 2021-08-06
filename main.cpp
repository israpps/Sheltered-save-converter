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
#include <stdio.h>

#ifndef NO_COLOR
#include <windows.h>
#define COLOR(args)         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),stoi(#args,0,16));  //pass a hex value between 00 and ff (or integer equivalent)
#else
#define COLOR(args)
#endif // NO_COLOR

#include "exename.h"
#include "version.h"
#define DAT 0
#define XML 1
#define INV 99

using namespace std;

unsigned char magic[2] = {0x90, 0x3c};
unsigned char *buffer;
std::string encrypt(unsigned char *buf,int size);
std::string arv_fnames[2];
int sf_is;
bool must_pause;
int main(int argc, char* argv[])
{
    string exename = EXE_NAME(argv[0]);
    COLOR(0f)
    printf("Sheltered SaveFile Converter - By matias Israelson (AKA:El_isra)\n");
    printf("Version [%s] - 32bits \n",AutoVersion::FULLVERSION_STRING);
    COLOR(07)
	if(argc < 3) {
		COLOR(0d)
		printf("\tUsage: %s infile outfile\n\n",exename.c_str());
        COLOR(07)
        cin.ignore();
		return 1;
	} else {
	arv_fnames[0] = EXE_NAME(argv[1]);
	arv_fnames[1] = EXE_NAME(argv[2]);
        if ( (argc > 3) && (strcmp(argv[3],"--nopause")==0) )
        {
            must_pause = false;
        } else {
            must_pause = true;
        }
	}

    vector<unsigned char> bytes;

    ifstream file1(argv[1], ios_base::in | ios_base::binary);

    unsigned char ch = file1.get();
    COLOR(0e)
    if (ch==magic[DAT]) {sf_is = DAT; printf("\tDecrypting save file...\n");}///if file begins with encrypted '<'
    else if (ch==magic[XML]) {sf_is = XML; printf("\tEncrypting save file...\n");}///if files begins with '<'
    else///if none of the conditions before passed...
    {
        sf_is = INV;
        COLOR(0c)
        printf("WARNING! [%s] can't be recognized as encrypted or decrypted save file...\n\tpress any key to continue with conversion anyway (or close window)",arv_fnames[0].c_str());
        if (must_pause) cin.ignore();
    }
    COLOR(07)
    while (file1.good())
    {
        bytes.push_back(ch);
        ch = file1.get();
    }
    size_t n = bytes.size();

    unsigned char* buff = bytes.data();


    std::ofstream out(argv[2], ios_base::binary);
    out << encrypt(buff,n);
    out.close();


    if (must_pause){
    printf("Process completed, press any key to close program\n");
    cin.ignore();
    }
    return sf_is;
}


std::string encrypt(unsigned char *buf,int size)
{
  unsigned char encrypters[17] = {172, 115, 254, 242, 170, 186, 109, 171, 48, 58, 139, 167, 222, 13, 21, 33, 74};
  std::string output;
  for( int i = 0; i < size; i++)
  {
      unsigned char oldValue = buf[i];
      unsigned char encrypter = encrypters[i % 17];
      buf[i] = oldValue ^ encrypter;
      output += (char)buf[i];
   }
  return output;
}
