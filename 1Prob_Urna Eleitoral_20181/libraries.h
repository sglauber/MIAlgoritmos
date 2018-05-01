#include "libraries_headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidateName {
  char presidentName[30];
  char governorName[30];
  char senatorName[30];
  char stateDeputyName[30];
  char federalDeputyName[30];
}candidateName;

typedef struct CandidateNumbers {
  candidateName voterChoicesNames;
  int president;
  int gubernaturial;
  int stateDept;
  int federalDept;
  int senator;
}voteNumber;

typedef struct VoterDetails {
  voteNumber voterChoices;
  int voterID;
  int sex; //Acess a struct inside
}VoterDetails;

typedef struct ListNode {
  Voter VoterDetails;
  struct ListNode *Next;
}List;

void addContent(List **Node, Voter *ReceivedDetails) {
  List *Head;
  Head = (List*) malloc(sizeof(List));
  if (Head == NULL) {
    puts("Aloc error.");
  }
  Head->VoterDetails = *ReceivedDetails;
  Head->Next = NULL;
  if (*Node == NULL) {
    *Node = Head;
  } else {
    Head->Next = *Node;
    *Node = Head;
  }
} //End addContent

void bufferWipeOut(int scanValue) { //Receives scanf's return value and cleans the buffer if the return is "false"
  int wipe;
  if (scanValue == 0) {
    puts("It'll not loop dawg, but I expected an integer :(\n");
    while((wipe = fgetc(stdin)) != EOF && wipe != '\n');
  }
}

void printVote(List *calc_list, int *maeli) {
  int totalPresident = 0, totalGuber = 0;
  float percentPresident = 1;
  if (calc_list == NULL) {
      printf("I'm empty, you should try vote in someone first :)\n");
  }
  while(calc_list != NULL) {
    totalPresident = calc_list->VoterDetails.president + calc_list->Next->VoterDetails.president;
    percentPresident = (*maeli * 100)/(totalPresident);
    calc_list = calc_list->Next;
  }
  printf("President total votes: %d, for maeli: %.2f\n",totalPresident, percentPresident);
  printf("Governor total votes: %d\n",totalGuber);

}//End PrintList

void printPresident(List *print_list) {
  if (print_list == NULL) {
      printf("I'm empty, you should try vote in someone first :)\n");
  }
  while(print_list != NULL) {
      printf("This dude %d voted in: %s for president.\n",print_list->VoterDetails.voterID, print_list->VoterDetails.presidentName);
      printf("Currently with: %d votes.\n\n", print_list->VoterDetails.president);
      print_list = print_list->Next;
  }
}//End printPresident

void printGovernor(List *print_list) {
  if (print_list == NULL) {
      printf("I'm empty, you should try vote in someone first :)\n");
  }
  while(print_list != NULL) {
    printf("This dude %d voted in: %s.\n", print_list->VoterDetails.voterID, print_list->VoterDetails.guberName);
    printf("Currently with: %d votes.\n\n", print_list->VoterDetails.gubernaturial);
    print_list = print_list->Next;
  }
}//End printPresident

int voterIDSearch(List **Node, int *number) {
  List *Search;
  Search = *Node;
  while (Search != NULL) {
    if (Search->VoterDetails.voterID == *number) {
      puts("You've already voted. Can't vote again...\n");
      return 1;
    }
    Search = Search->Next;
  }
} //End voterIDSearch
