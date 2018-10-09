#ifndef FUNCTIONS_HEADERS_H
#define FUNCTIONS_HEADERS_H

#ifdef _WIN32
  #define CLEAR system("cls");
#else
  #define CLEAR system("clear");
#endif
#define MAX 32

#define true 1
#define false 0

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef int bool;

typedef struct Player {
  bool  is_sorted;
  int id;
  char name[MAX];
  int  birth_year;
  char nation[20];
  int  shirt_number;
  char position[20];
}player_t;

typedef struct Node {
  player_t  content;
  struct   Node *next;
}node_t;

player_t registerPlayer();
void modifyShirt();
void removePlayer();
void sortPlayers();
void showByPosition();
void showPlayers();
void listInsertion();
void showSorted();
int listSize();

#endif

int main() {

  node_t    *head = NULL;
  player_t  player;
  int option;
  int counterID = -1;
  int n;
  do {
    printf("[1] Register Player\n[2] Modify T-Shirt\n[3] Remove Player\n[4] Sort Players\n[5] Show by Position\n[6] Show Players\n[7] Show sorted\n[8] Exit\nOption: ");
    scanf("%d", &option);
    setbuf(stdin,NULL);
    if (option == 1) {
      counterID++;
      listInsertion(&head, counterID);
    } else if (option == 2) {
      modifyShirt(head);
    } else if (option == 3) {
      removePlayer(&head);
    } else if (option == 4) {
      sortPlayers(head);
    } else if (option == 5) {
      showByPosition(head);
    } else if (option == 6) {
      showPlayers(head);
    } else if (option == 7) {
      showSorted(head);
    } else if (option == 8) {
      exit(EXIT_SUCCESS);
    }
  }while(option < 8);
  return(EXIT_SUCCESS);
}

player_t registerPlayer(int id) {
  player_t player;
  player.id = id;
  player.is_sorted = false;
  printf("Register...\n");
  printf("Name: ");
  gets(player.name);
  printf("Birth year: ");
  fscanf(stdin, "%d", &player.birth_year);
  setbuf(stdin,NULL);
  printf("Nation: ");
  gets(player.nation);
  printf("Shirt number: ");
  fscanf(stdin, "%d", &player.shirt_number);
  setbuf(stdin,NULL);
  printf("Position: ");
  gets(player.position);
  return player;
}

node_t* createNode(player_t content) {
  node_t *new = (node_t*)malloc(sizeof(node_t));
  new->content = content;
  new->next = NULL;
  return new;
}

void listInsertion(node_t **head, int counter) {
  player_t content = registerPlayer(counter);
  node_t *new = createNode(content);
  new->content = content;
  new->next = NULL;
  if (*head == NULL) {
    *head = new;
  } else {
    new->next = *head;
    *head = new;
  }
}

void showByPosition(node_t *head) {
  if(!head) {
    printf("I'm empty.\n");
    return;
  }
  char position[MAX];
  setbuf(stdin,NULL);
  printf("\nPosition: ");
  gets(position);
  while (head != NULL) {
    if (strcmp(head->content.position, position) == 0) {
        printf("\n%s\n", position);
        printf("%s  %s\n",head->content.name, head->content.nation);
    }
    head = head->next;
  }
}

void showPlayers(node_t *head) {
  if(!head) {
    printf("I'm empty.\n");
    return;
  }
  printf("\n");
  while(head != NULL) {
    printf("%s  %d  %s  %d  %s\n",head->content.name, head->content.birth_year, head->content.nation, head->content.shirt_number, head->content.position);
    head = head->next;
  }
}

void showSorted(node_t *head) {
  while(head != NULL) {
    if(head->content.is_sorted == true) {
      printf("%s %s %s\n", head->content.name, head->content.nation, head->content.position);
    }
    head = head->next;
  }
}

void modifyShirt(node_t *head) {
  if (!head) {
    printf("I'm empty.\n");
    return;
  }
  char name[MAX];
  setbuf(stdin, NULL);
  printf("\nPlayer name: ");
  gets(name);

  while(head != NULL) {
    if (strncmp(head->content.name, name, sizeof(name)) == 0) {
      printf("Shirt number: %d\n", head->content.shirt_number);
      printf("Modify to: ");
      scanf("%d", &head->content.shirt_number);
      printf("New number: %d\n", head->content.shirt_number);
      return;
    }
    head = head->next;
  }
  return;
}

void removePlayer(node_t **head) {
  node_t *current = *head;
  node_t *tmp;
  if (current == NULL) {
    printf("I'm empty.\n");
    return;
  }
  char name[MAX];
  setbuf(stdin, NULL);
  printf("\nPlayer name: ");
  gets(name);

  if(strcmp(current->content.name, name) == 0) {
    tmp = current;
    *head = current->next;
    free(tmp);
  } else {
    while(current->next != NULL) {
      if (strcmp(current->next->content.name, name) == 0) {
        tmp = current->next;
        current->next = current->next->next;
        free(tmp);
        return;
      }
      current = current->next;
    }
  }
} //end removePlayer();

void sortPlayers(node_t *head) {
  srand(time(0));
  node_t *aux = head;
  int n;
  int quantity = listSize(head);
  if (quantity == 0) {
    printf("No players to sort.\n");
    return;
  }
  printf("Quantity to sort: ");
  scanf("%d", &n);
  if (n > quantity) {
    n = quantity;
  }
  int nrandom = rand()%n;
  int i = -1;
  while(head != NULL && i < n) {
    if(head->content.is_sorted == false) {
      printf("\n%s %s\n", head->content.name, head->content.position);
      head->content.is_sorted = true;
      i++;
    }
    head = head->next;
  }
}

int listSize(node_t *head) {
  int counter = 0;
  while(head != NULL) {
    if (head->content.is_sorted == false) {
      ++counter;
    }
    head = (head)->next;
  }
  return counter;
}
