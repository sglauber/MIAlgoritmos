typedef struct ListNode {
  int Content;
  struct ListNode *Next;
}List;

//Function that receives a VoterID and a Node from linked list and adds the received content to the list.
void addVoterIDToList(List **Node, int *ReceivedVoterID) {
  List *Head;
  Head = (List*) malloc(sizeof(List));

  Head->Content = *ReceivedVoterID;
  Head->Next = NULL;
  if (*Node == NULL) {
    *Node = Head;
  } else {
    Head->Next = *Node;
    *Node = Head;
  }
}//End addContent

//Function that receives a linked list and search for it's content in this case the entered VoterID.
//If this VoterID is already in the list user must type another ID.
int voterIDSearch(List **Node, int *ReceivedVoterID) {
  List *Search;
  Search = *Node;
  while (Search != NULL) {
    if (Search->Content == *ReceivedVoterID) {
      return 1;
    }
    Search = Search->Next;
  }
} //End voterIDSearch

//Function that receives votes from a candidate, and calculate it's percentual based on total of votes from this candidate category.
void calculateVotesPercentage (int *candidateToCount, int *totalVotesValids, float *candidatePercentage){
  if (*totalVotesValids == 0) {
    puts("OMG there's a 0 dude! What u doing to my life?\n");
  } else {
    *candidatePercentage = (float)(*candidateToCount * 100)/(*totalVotesValids);
  }
}

//Function that receives the quantity of votes from all 3 presidents and calculates if it'll be a second votation.
void calculateRoundTwo (int firstPresident, int secondPresident, int thirdPresident) {
  float percentFirstPresident, percentSecondPresident, percentThirdPresident;
  percentFirstPresident = (float)(firstPresident * 100)/(firstPresident+secondPresident+thirdPresident);
  percentSecondPresident = (float)(secondPresident * 100)/(firstPresident+secondPresident+thirdPresident);
  percentThirdPresident = (float)(thirdPresident * 100)/(firstPresident+secondPresident+thirdPresident);
  if ((percentFirstPresident == 50) && (percentSecondPresident == 50)) {
    puts("Round TWO! BETWEEEEEEN Mrs. Maeli Gente Boa and Mr. Antonio Brasil\n");
  } else if ((percentFirstPresident == 50) && (percentThirdPresident == 50)) {
    puts("Round TWO! BETWEEEEEEN Mrs. Maeli Gente Boa and Mr. Lissandro Progresso\n");
  } else if ((percentSecondPresident == 50) && (percentThirdPresident == 50)) {
    puts("Round TWO! BETWEEEEEEN Mr. Antonio Brasil and Mr. Lissandro Progresso\n");
  } else {
    puts("We have our winner!\n");
  }
}
