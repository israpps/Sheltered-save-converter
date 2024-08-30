# Sheltered save converter

![GitHub all releases](https://img.shields.io/github/downloads/israpps/Sheltered-save-converter/total?style=for-the-badge)
![License](https://img.shields.io/github/license/israpps/Sheltered-save-converter?style=for-the-badge)

Sheltered-save-converter is an open-source command-line utility written in C++ specifically designed to encrypt/decrypt [Sheltered](https://store.steampowered.com/app/356040/Sheltered) and [Sheltered 2](https://store.steampowered.com/app/1289380/Sheltered_2) save files

## How to use
the usage is simple (and program will remind you if you don't enter enough argumments)
```bash
Sheltered_save_file_converter.exe <SAVE_FILE> <CONVERTED_SAVE_FILE_NAME>
```

## The "Encryption" of the file
the file is just xor'ed with a 17 bytes vector back and forth
```c
0xAC, 0x73, 0xFE, 0xF2, 0xAA, 0xBA, 0x6D, 0xAB, 0x30, 0x3A, 0x8B, 0xA7, 0xDE, 0x0D, 0x15, 0x21, 0x4A
```
wich of these `17` bytes is used to xor one byte of the file? it's decided purely by it's possition on the file itself, The remainder of the division between the current file offset and the ammount of bytes in the "encryption" vector.  
literally just this:
```c
uint8_t enc = vec[i % 17];
```

> [!WARNING]
> the file is using CRLF line returns (windows).  
> dont change the file to LF line returns (linux)  
> since that halves the ammount of bytes consumed by each newline, resulting in erroneous encryption of the file

### Why you made this?
this tool was created as a workaround to the issues regarding the [original javascrypt file](https://jsfiddle.net/mjnpr2ac/18/) used by the sheltered comunity years ago to do this conversion.

As you may know, some sort of JavaScript issue is conflicting on save encryption and download

I'm clearly aware of the existense of superior tools that even have UIs for doing this. however, some people might still like the idea of touching the XML file with their own hands

## what can i use this tool for?
to decrypt your game save file into xml format, allowing you to edit/see the save 

users usually want this to do some "cheating"
- take a look at the M16 Hatch code (useful for Android users with small screens)
- enable hatch code
- add food without using cheat engine

_Or maybe to fix some mistakes you made:_

- change family surname
- change character name

_Or maybe to use this rudimentary xor'ing to hide information from someone???_

it's up to you

### encrypt save file again

After you're done manipulating your XML save file, you can go ahead and encrypt it again.
Simply run the program again, but passing the XML file instead of DAT file this time.

Have fun!

## And don't forget to backup your saves before using this program

# [DOWNLOAD](https://github.com/israpps/Sheltered-save-converter/releases/latest)
