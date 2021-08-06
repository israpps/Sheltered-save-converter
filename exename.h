/***************************************************************
 * Name:      exename.h
 * Purpose:   generic functions to retireve program filename
 * Author:    matias israelson (aka: El_isra) (israelson-matias@hotmail.com)
 * Created:   2021-03-31
 * Copyright: matias israelson (aka: El_isra) (https://github.com/israpps)
 * License:   GPL-3.0
 **************************************************************/


#ifndef EXENAME_H_INCLUDED
#define EXENAME_H_INCLUDED
#include <string>
  std::string EXE_NAME (char* _argv0)
  {
  std::string temporary = _argv0;
  return temporary.substr( temporary.find_last_of('\\')+ 1 );
  }

  std::string EXE_NAME (std::string _argv0)
  {
  return _argv0.substr(_argv0.find_last_of('\\') +1 );
  }

#endif // EXENAME_H_INCLUDED
