/*******************************************************************************
Autor: Glauber da S. Santana
Componente Curricular: Algoritmos I
Concluido em: 24/04/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/

#ifdef _WIN32 //Se for Windows ambas arquiteturas x86 e x64
  #define CLEAR system("cls");
#else //In any other OS
  #define CLEAR system("clear");
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void addVoterIDToList(List **Node, int *ReceivedVoterID);
void bufferWipeOut(int scanValue);
int voterIDSearch(List **Node, int *ReceivedVoterID);
void calculateVotesPercentage (int *presidentToCount, int *totalPresidentVotesValids, float *candidatePercentage);
void calculateRoundTwo();

int main() {

  List *Elections = NULL;
  int activateSearch = 0, Confirmation = 0, scanValue, candidateOption, IDsearchResult, menuOption = 0, voteAgain = 1, printChoice, VoterID; //Control and menus variables.
  int womenCounter = 0, menCounter = 0; //Sex counter variables

  float candidatePercentage;

  int maeliVoteCounter = 0, antonioBrasilVoteCounter = 0, lissandroProgressoVoteCounter = 0, blankPresidentVoteCounter = 0, nullPresidentVoteCounter = 0 ; //Presidents variables
  int maiaAnaVoteCounter = 0, mrGentilVoteCounter = 0, selmaSilvaVoteCounter = 0, blankGovernorVoteCounter = 0, nullGovernorVoteCounter = 0; //Governor variables
  int gutembergSilvaVoteCounter = 0, fernandoFernandesVoteCounter = 0, nullSenatorVoteCounter = 0, blankSenatorVoteCounter = 0; //Senator variables
  int anaVitoriaVoteCounter = 0, pauloGuilhermeVoteCounter = 0, nullFederalDeputyVoteCounter = 0, blankFederalDeputyVoteCounter = 0; //Federal Deputy variables
  int anaRitaVoteCounter = 0, anaGuilhermeVoteCounter = 0, adalbertoCamposVoteCounter = 0, blankStateDeputyVoteCounter = 0, nullStateDeputyVoteCounter = 0; //State Deputy variables

  char governorName[30], presidentName[30], senatorName[30], stateDeputyName[30], federalDeputyName[30]; //Names variables

  do {
    //I'm using a linked list, in this way a person can't vote twice with the same VoterID.
    //Calls to printf() without args. turns into puts(), knowing that I chose to use puts(); on those strings without arguments like ("%d, %f, %s");
    puts("[1] To Vote [2] Total Votes [3] Exit");
    scanValue = scanf("%d", &menuOption);
    //This function receives a scanf() return value that's stored on scanValue and wipes the stdin buffer if this return is EOF, false/'0'.
    CLEAR;
    bufferWipeOut(scanValue);
    if (menuOption == 1) {
      if (voteAgain == 1) {
        do{
          do {
            puts("Enter your Voter ID card. 4 Digits.\n");
            scanValue = scanf("%d", &VoterID);
            CLEAR;
            bufferWipeOut(scanValue);
            if (activateSearch == 1) {
              //Function that receives my LinkedList as parameter and searchs for a VoterID on the List. If it returns 1 means that the ID have been used to vote.
              //Knowing that if the VoterID exists this persons can't vote with this ID.
              IDsearchResult = voterIDSearch(&Elections, &VoterID);
            }
            //I chose for not use the "official" 12 Digits VoterID length.
            //This makes my search for a ID easier, since 12 Digits tresspass the maximum value allowed for an integer.
            if (VoterID > 9999 || VoterID < 1000) {
              puts("You've entered an invalid voterID!\n");
            }
          }while(IDsearchResult == 1);
        }while(VoterID > 9999 || VoterID < 1000);
        //Control variable. It was inicialized with '0'. Here it's value is set to 1.
        //From now the program will be able to search for an ID after the first loop.
        activateSearch = 1;

        //Now, each do/while block from here it's associated to the "Voting Step".
        //Each one of these blocks means a candidate category.

        //President voting block
        do {
          puts("Select your Presidential candidate.\n");
          puts("[17] Mrs. Maeli Gente Boa\n[22] Mr. Antonio do Brasil\n[33] PhD. Lissandro Progresso\n[99] Blank\n[Any other] NULL\n");
          scanValue = scanf("%d", &candidateOption);
          if (candidateOption == 17) {
            strcpy(presidentName, "Mrs. Maeli Gente Boa");
            maeliVoteCounter++;
            womenCounter++;
          } else if (candidateOption == 22) {
            strcpy(presidentName, "Mr. Antonio do Brasil");
            antonioBrasilVoteCounter++;
            menCounter++;
          } else if (candidateOption == 31) {
            strcpy(presidentName,"PhD. Lissandro Progresso");
            lissandroProgressoVoteCounter++;
            menCounter++;
          } else if (candidateOption == 99) {
            strcpy(presidentName, "Blank");
            blankPresidentVoteCounter++;
          } else {
            strcpy(presidentName, "NULL");
            nullPresidentVoteCounter++;
          }
          CLEAR;
          bufferWipeOut(scanValue);
        }while((scanValue == 0));
        //President voting block end...

        //Governor voting block
        do {
          puts("Select your Governor candidate.\n");
          puts("[38] Mr. Maia da Ana\n[40] Mr. Gentil\n[18] Mrs. Dona Selma Silva\n[99] Blank\n[Any other] NULL\n");
          scanValue = scanf("%d", &candidateOption);
          if (candidateOption == 38) {
            strcpy(governorName, "Mr. Maia da Ana");
            maiaAnaVoteCounter++;
            menCounter++;
          } else if (candidateOption == 40) {
            strcpy(governorName, "Mr. Gentil");
            mrGentilVoteCounter++;
            menCounter++;
          } else if (candidateOption == 18) {
            strcpy(governorName, "Mrs. Dona Selma Silva");
            selmaSilvaVoteCounter++;
            womenCounter++;
          } else if (candidateOption == 99) {
            strcpy(governorName,"Blank");
            blankGovernorVoteCounter++;
          } else {
            strcpy(governorName,"NULL");
            nullGovernorVoteCounter++;
          }
          CLEAR;
          bufferWipeOut(scanValue);
        }while((scanValue == 0));
        //Governor voting block end...

        //Senator voting block
        do {
          puts("Select your Senator candidate.\n");
          puts("[04] Mr. Gutemberg Silva\n[67] Mr. Fernando Fernandes\n[99] Blank\n[Any other] NULL\n");
          scanValue = scanf("%d", &candidateOption);
          if (candidateOption == 4) {
            strcpy(senatorName, "Mr. Gutemberg Silva");
            gutembergSilvaVoteCounter++;
            menCounter++;
          } else if (candidateOption == 67) {
            strcpy(senatorName, "Mr. Fernando Fernandes");
            fernandoFernandesVoteCounter++;
            menCounter++;
          } else if (candidateOption == 99) {
            strcpy(senatorName, "Blank");
            blankSenatorVoteCounter++;
          } else {
            strcpy(senatorName, "NULL");
            nullSenatorVoteCounter++;
          }
          CLEAR;
          bufferWipeOut(scanValue);
        }while((scanValue == 0));
        //Senator voting block end...

        //Federal Deputy voting block
        do {
          puts("Select your Federal Deputy candidate.\n");
          puts("[56] Mrs. Ana Vitoria\n[33] Mr. Paulo Guilherme\n[99] Blank\n[Any other] NULL\n");
          scanValue = scanf("%d", &candidateOption);
          if (candidateOption == 56) {
            strcpy(federalDeputyName, "Mrs. Ana Vitoria");
            anaVitoriaVoteCounter++;
            womenCounter++;
          } else if (candidateOption == 33) {
            strcpy(federalDeputyName, "Mr. Paulo Guilherme");
            pauloGuilhermeVoteCounter++;
            menCounter++;
          } else if (candidateOption == 99) {
            strcpy(federalDeputyName, "Blank");
            blankFederalDeputyVoteCounter++;
          } else {
            strcpy(federalDeputyName, "NULL");
            nullFederalDeputyVoteCounter++;
          }
          CLEAR;
          bufferWipeOut(scanValue);
        }while((scanValue == 0));
        //Federal Deputy voting block end...

        //State Deputy voting block
        do {
          puts("Select your State Deputy candidate.\n");
          puts("[51] PhD. Ana Rita Pacheco\n[34] Mrs. Ana Guilherme\n[11] Mr. Adalberto Campos\n[99] Blank\n[Any other] NULL\n");
          scanValue = scanf("%d", &candidateOption);
          if (candidateOption == 51) {
            strcpy(stateDeputyName, "PhD. Ana Rita Pacheco");
            anaRitaVoteCounter++;
            womenCounter++;
          } else if (candidateOption == 34) {
            strcpy(stateDeputyName, "Mrs. Ana Guilherme");
            anaGuilhermeVoteCounter++;
            womenCounter++;
          } else if (candidateOption == 11){
            strcpy(stateDeputyName, "Mr. Adalberto Campos");
            adalbertoCamposVoteCounter++;
            menCounter++;
          } else if (candidateOption == 99) {
            strcpy(stateDeputyName, "Blank");
            blankStateDeputyVoteCounter++;
          } else {
            strcpy(stateDeputyName, "NULL");
            nullStateDeputyVoteCounter++;
          }
          CLEAR;
          bufferWipeOut(scanValue);
        }while((scanValue == 0));
        //State Deputy voting block end...

        //Call to function that adds the ID to the LinkedList, receive as parameter the LinkedList and a integer in this case, it's the VoterID
        addVoterIDToList(&Elections, &VoterID);

        //End of votes, in this part the program shows the mirror with all the choices from this person.
        puts("This is your mirror.\n");
        printf("President choice: %s\nGovernor choice: %s\nSenator choice: %s\n", presidentName, governorName, senatorName);
        printf("State Deputy choice: %s\nFederal Deputy choice: %s\n\n", stateDeputyName, federalDeputyName);
        puts("Do you want to vote again? [1] YES [Any Other] NO \n");
        scanValue = scanf("%d",&voteAgain);
        bufferWipeOut(scanValue);
        CLEAR;
      } else
        puts("Votes already ended.\n");
    } else if (menuOption == 2) {
      puts("[1] Presidents\n[2] Governor\n[3] Senator\n[4] Federal Deputy\n[5] State Deputy\n[Any Other] Male & Females Votes\n");
      scanValue = scanf("%d",&printChoice);

      int totalPresidentVotesValids = maeliVoteCounter + antonioBrasilVoteCounter + lissandroProgressoVoteCounter;
      int totalGovernorVotesValids = maiaAnaVoteCounter + mrGentilVoteCounter + selmaSilvaVoteCounter;
      int totalSenatorVotesValids = gutembergSilvaVoteCounter + fernandoFernandesVoteCounter;
      int federalDeputyVotesValids = anaVitoriaVoteCounter + pauloGuilhermeVoteCounter;
      int stateDeputyVotesValids = anaRitaVoteCounter + anaGuilhermeVoteCounter + adalbertoCamposVoteCounter;

      int totalPresidentInvalidVotes = blankPresidentVoteCounter + nullPresidentVoteCounter;
      int totalGovernorInvalidVotes = blankGovernorVoteCounter + nullGovernorVoteCounter;
      int totalSenatorInvalidVotes = blankSenatorVoteCounter + nullSenatorVoteCounter;
      int totalStateDeputyInvalidVotes = blankStateDeputyVoteCounter + nullStateDeputyVoteCounter;
      int totalFederalDeputyInvalidVotes = blankFederalDeputyVoteCounter + nullFederalDeputyVoteCounter;

      //Menu for printing results
      if (printChoice == 1) {
        CLEAR;

        calculateVotesPercentage(&maeliVoteCounter, &totalPresidentVotesValids, &candidatePercentage);
        printf("Mrs. Maeli Gente Boa\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",maeliVoteCounter, candidatePercentage);
        calculateVotesPercentage(&antonioBrasilVoteCounter, &totalPresidentVotesValids, &candidatePercentage);
        printf("Mr. Antonio do Brasil\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",antonioBrasilVoteCounter, candidatePercentage);
        calculateVotesPercentage(&lissandroProgressoVoteCounter, &totalPresidentVotesValids, &candidatePercentage);
        printf("PhD. Lissandro Progresso\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",lissandroProgressoVoteCounter,candidatePercentage);

        calculateVotesPercentage(&nullPresidentVoteCounter, &totalPresidentInvalidVotes, &candidatePercentage);
        printf("NULL votes\nTotal Votes: %d\nCorresponds to: %.2f%|of invalid votes\n\n",nullPresidentVoteCounter, candidatePercentage);
        calculateVotesPercentage(&blankPresidentVoteCounter, &totalPresidentInvalidVotes, &candidatePercentage);
        printf("Blank votes\nTotal Votes: %d\nCorresponds to: %.2f%|of invalid votes\n\n",blankPresidentVoteCounter, candidatePercentage);
        if (voteAgain != 1){
          calculateRoundTwo(maeliVoteCounter, antonioBrasilVoteCounter, lissandroProgressoVoteCounter);
        }
      } else if (printChoice == 2) {
        CLEAR;
        calculateVotesPercentage(&maiaAnaVoteCounter, &totalGovernorVotesValids, &candidatePercentage);
        printf("Mr. Maia da Ana\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",maiaAnaVoteCounter, candidatePercentage);
        calculateVotesPercentage(&mrGentilVoteCounter, &totalGovernorVotesValids, &candidatePercentage);
        printf("Mr. Gentil\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",mrGentilVoteCounter, candidatePercentage);
        calculateVotesPercentage(&selmaSilvaVoteCounter, &totalGovernorVotesValids, &candidatePercentage);
        printf("Mrs. Dona Selma da Silva\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",selmaSilvaVoteCounter, candidatePercentage);

        calculateVotesPercentage(&nullGovernorVoteCounter, &totalGovernorInvalidVotes, &candidatePercentage);
        printf("NULL votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",nullGovernorVoteCounter, candidatePercentage);
        calculateVotesPercentage(&blankGovernorVoteCounter, &totalGovernorInvalidVotes, &candidatePercentage);
        printf("Blank votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",blankGovernorVoteCounter, candidatePercentage);

      } else if (printChoice == 3) {
        CLEAR;
        calculateVotesPercentage(&gutembergSilvaVoteCounter, &totalSenatorVotesValids, &candidatePercentage);
        printf("Mr. Gutemberg Silva\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",gutembergSilvaVoteCounter, candidatePercentage);
        calculateVotesPercentage(&fernandoFernandesVoteCounter, &totalSenatorVotesValids, &candidatePercentage);
        printf("Mr. Fernando Fernandes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",fernandoFernandesVoteCounter, candidatePercentage);

        calculateVotesPercentage(&nullSenatorVoteCounter, &totalSenatorInvalidVotes, &candidatePercentage);
        printf("NULL votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",nullSenatorVoteCounter, candidatePercentage);
        calculateVotesPercentage(&blankSenatorVoteCounter, &totalSenatorInvalidVotes, &candidatePercentage);
        printf("Blank votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",blankSenatorVoteCounter, candidatePercentage);
      } else if (printChoice == 4) {
        CLEAR;
        calculateVotesPercentage(&anaVitoriaVoteCounter, &federalDeputyVotesValids, &candidatePercentage);
        printf("Mrs. Ana Vitoria\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",anaVitoriaVoteCounter, candidatePercentage);
        calculateVotesPercentage(&pauloGuilhermeVoteCounter, &federalDeputyVotesValids, &candidatePercentage);
        printf("Mr. Paulo Guilherme\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",pauloGuilhermeVoteCounter, candidatePercentage);

        calculateVotesPercentage(&nullFederalDeputyVoteCounter, &totalFederalDeputyInvalidVotes, &candidatePercentage);
        printf("NULL votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",nullFederalDeputyVoteCounter, candidatePercentage);
        calculateVotesPercentage(&blankFederalDeputyVoteCounter, &totalFederalDeputyInvalidVotes, &candidatePercentage);
        printf("Blank votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",blankFederalDeputyVoteCounter, candidatePercentage);
      } else if (printChoice == 5) {
        CLEAR;
        calculateVotesPercentage(&anaRitaVoteCounter, &stateDeputyVotesValids, &candidatePercentage);
        printf("PhD. Ana Rita Pacheco\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",anaRitaVoteCounter, candidatePercentage);
        calculateVotesPercentage(&anaGuilhermeVoteCounter, &stateDeputyVotesValids, &candidatePercentage);
        printf("Mrs. Ana Guilherme\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",anaGuilhermeVoteCounter, candidatePercentage);
        calculateVotesPercentage(&adalbertoCamposVoteCounter, &stateDeputyVotesValids, &candidatePercentage);
        printf("Mr. Adalberto Campos\nTotal Votes: %d\nCorresponds to: %.2f%\n\n", adalbertoCamposVoteCounter, candidatePercentage);

        calculateVotesPercentage(&nullStateDeputyVoteCounter, &totalStateDeputyInvalidVotes, &candidatePercentage);
        printf("NULL votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",nullFederalDeputyVoteCounter, candidatePercentage);
        calculateVotesPercentage(&blankStateDeputyVoteCounter, &totalStateDeputyInvalidVotes, &candidatePercentage);
        printf("Blank votes\nTotal Votes: %d\nCorresponds to: %.2f%\n\n",blankFederalDeputyVoteCounter, candidatePercentage);
      } else {
        CLEAR;
        int totalVotesValids = totalPresidentVotesValids + totalSenatorVotesValids + totalGovernorVotesValids + stateDeputyVotesValids + federalDeputyVotesValids;
        calculateVotesPercentage(&menCounter, &totalVotesValids, &candidatePercentage);
        printf("%d votes were in men, it corresponds to: %.2f%\n\n",menCounter, candidatePercentage);
        calculateVotesPercentage(&womenCounter, &totalVotesValids, &candidatePercentage);
        printf("%d votes were in women, it corresponds to: %.2f%\n\n",womenCounter, candidatePercentage);
      }
    }
  }while(!(menuOption == 3));
}//End main
