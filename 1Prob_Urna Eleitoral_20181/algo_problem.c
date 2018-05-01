/*******************************************************************************
Autor: Glauber da S. Santana
Componente Curricular: Algoritmos I
Concluido em: 240/04/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include "libraries.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  Voter VoterDetails;
  List *Elections = NULL;
  int searchFlag = 0, Confirmation = 0, scanValue, menuOpt = 0, Option, getReturn;
  int maeliVotes = 0, vote = 0, antonioBrasil = 0, lissandroProgresso = 0, blankVotes = 0,  nullVotes = 0;
  int maiaAna = 0, mrGentil = 0, selmaSilva = 0;

  do {
    puts("[1] To Vote [2] Watch results [3] Exit");
    scanValue = scanf("%d", &menuOpt);
    system ("clear");
    bufferWipeOut(scanValue);
    if (menuOpt == 1) {
      //The compiler converts calls to printf() without args. to puts(), knowing that
      //I chose to use puts for making my code slight better since I'm not using any args like (%d, %f, %c).
      do{
        do {
          puts("Enter your Voter ID card. 4 Digits.\n");
          scanValue = scanf("%d", &VoterDetails.voterID);
          system ("clear");
          bufferWipeOut(scanValue);
          if (searchFlag == 1) {
            getReturn = voterIDSearch (&Elections, &VoterDetails.voterID);
          }
          //Not using the "official" 12 Digits voterID length.
          if (VoterDetails.voterID > 9999 || VoterDetails.voterID < 1000) {
            puts("You've entered an invalid voterID!\n");
          }
        }while(VoterDetails.voterID > 9999 || VoterDetails.voterID < 1000);
      }while(getReturn == 1);
      searchFlag = 1;

      do {
        puts("Select your presidential candidate.\n");
        puts("[17] Sra. Maeli Gente Boa\n[22] Sr. Antonio do Brasil\n[33] Dr. Lissandro Progresso\n[99] Blank\n[Any other] NULL\n");
        scanValue = scanf("%d", &Option);
        if (Option == 17) {
          strcpy(VoterDetails.presidentName,"Sra. Maeli Gente Boa");
          VoterDetails.president = ++maeliVotes;
          //++womenCounter;
        } else if (Option == 22) {
            strcpy(VoterDetails.presidentName,"Sr. Antonio do Brasil");
            VoterDetails.president = ++antonioBrasil;
          //  ++menCounter;
        } else if (Option == 33) {
            strcpy(VoterDetails.presidentName,"Dr. Lissandro Progresso");
              VoterDetails.president = ++lissandroProgresso;
          //  ++menCounter;
        } else if (Option == 99) {
            strcpy(VoterDetails.presidentName,"Blank");
            VoterDetails.president = ++blankVotes;
          //  ++menCounter;
        } else {
            strcpy(VoterDetails.presidentName,"NULL");
            VoterDetails.president = ++nullVotes;
        }
        system("clear");
        bufferWipeOut(scanValue);
      }while((scanValue == 0));

      do {
        puts("Select your Gubernaturial (what? - ask) candidate.\n");
        puts("[38] Sr. Maia da Ana\n[40] Sr. Gentil\n[18] Sra. Dona Selma Silva\n[99] Blank\n[Any other] NULL\n");
        scanValue = scanf("%d", &Option);
        if (Option == 38) {
          strcpy(VoterDetails.guberName,"Sr. Maia da Ana");
          VoterDetails.gubernaturial = ++maiaAna;
          //++womenCounter;
        } else if (Option == 40) {
            strcpy(VoterDetails.guberName,"Sr. Gentil");
            VoterDetails.gubernaturial = ++mrGentil;
          //  ++menCounter;
        } else if (Option == 18) {
            strcpy(VoterDetails.guberName,"Sra. Dona Selma Silva");
              VoterDetails.gubernaturial = ++selmaSilva;
          //  ++menCounter;
        } else if (Option == 99) {
            strcpy(VoterDetails.guberName,"Blank");
            VoterDetails.gubernaturial = ++blankVotes;
          //  ++menCounter;
        } else {
            strcpy(VoterDetails.guberName,"NULL");
            VoterDetails.gubernaturial = ++nullVotes;
        }
        system("clear");
        bufferWipeOut(scanValue);
      }while((scanValue == 0));
        addContent(&Elections, &VoterDetails);
    } else if (menuOpt == 2) {
      system("clear");
      //menu para chamar diferentes "prints"
      printList(Elections);
    }
  }while(!(menuOpt == 3));
} //End main
