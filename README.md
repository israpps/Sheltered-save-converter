# Sheltered save converter

![GitHub all releases](https://img.shields.io/github/downloads/israpps/Sheltered-save-converter/total?style=for-the-badge)
![License](https://img.shields.io/github/license/israpps/Sheltered-save-converter?style=for-the-badge)

Sheltered-save-converter is an open-source command-line utility written in C++ specifically designed to encrypt/decrypt [Sheltered](https://en.wikipedia.org/wiki/Sheltered_(video_game)) save files

## How to use
the usage is simple (and program will remind you if you don't enter enough argumments)
```bash
Sheltered_save_file_converter.exe <SAVE_FILE> <CONVERTED_SAVE_FILE_NAME>
```
> also, a batch file was provided for those that don't like/know how to use command line, just drag and drop your save file into the .BAT file located along the program.


### Why you made this?
this tool was created as a workaround to the issues regarding the [original javascrypt file](https://jsfiddle.net/mjnpr2ac/18/) used by the sheltered comunity to do this conversion.

As you may know, some sort of JavaScript issue is conflicting on save encryption and download




## what can i use this tool for?
to decrypt your game save file into xml format, allowing you to edit/see the save 

users usually want this to do some "cheating"
- take a look at the M16 Hatch code (useful for Android users with small screens)
- enable hatch code
- add food without using cheat engine

_Or maybe to fix some mistakes you made:_

- change family surname
- change character name

### encrypt save file again

After you're done manipulating your XML save file, you can go ahead and encrypt it again.
Simply run the program again, but passing the XML file instead of DAT file this time.

Have fun!

## And don't forget to backup your saves before using this program

# [DOWNLOAD](https://github.com/israpps/Sheltered-save-converter/releases/latest)
