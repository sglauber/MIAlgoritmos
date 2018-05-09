#ifdef _WIN32 //Se for Windows ambas arquiteturas x86 e x64
  #define CLEAR system("cls");
#else //In any other OS
  #define CLEAR system("clear");
#endif

#include "functions.h"

int main () {
  menuSelecao();
  return 0;
} //End main();
