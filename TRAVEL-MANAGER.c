#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXD 100 // MAXIMUM DESTINATION LENGTH
#define MAXN 50  // MAXIMUM NAME LENGTH


struct Trip {
  char destination[MAXD];
  char nom[MAXN];      // TRIP NAME
  int prix;            // PRICE
  int debut;           // START DATE
  int fin;             // END DATE
  struct Trip *next;
};


struct Trip *first_trip = NULL;


// ADDING A TRIP
void ajouter(struct Trip trip) {
  struct Trip *new_trip;
  new_trip = (struct Trip*)malloc(sizeof(struct Trip));
  *new_trip = trip;
  new_trip->next = first_trip;
  first_trip = new_trip;
}


// DELETING A TRIP
void supprimer(char *nom) {
  struct Trip *current_trip;
  struct Trip *prev_trip;
  current_trip = first_trip;
  prev_trip = NULL;
  while (current_trip != NULL) {
    if (strcmp(current_trip->nom, nom) == 0) {
      if (prev_trip == NULL) {
        first_trip = current_trip->next;
      } else {
        prev_trip->next = current_trip->next;
      }
      free(current_trip);
      break;
    }
    prev_trip = current_trip;
    current_trip = current_trip->next;
  }
}


// MODIFYING A TRIP
void modifier(char *nom) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (strcmp(current_trip->nom, nom) == 0) {
      printf("Entrez les nouvelles informations sur le voyage :\n");
      printf("Nom : ");
      scanf("%s", current_trip->nom);
      printf("Destination : ");
      scanf("%s", current_trip->destination);
  printf("Date de debut (jjmmaaaa) : ");
  scanf("%d", &current_trip->debut);
  printf("Date de fin (jjmmaaaa) : ");
  scanf("%d", &current_trip->fin);
  printf("Prix : ");
  scanf("%d", &current_trip->prix);
  break;
}
current_trip = current_trip->next;
}
}


// FINDING AVAILABLE TRIPS BETWEEN TWO DATES
void recherche(int debut, int fin) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (current_trip->debut >= debut && current_trip->fin <= fin) {
      printf("Nom : %s\n", current_trip->nom);
      printf("Destination : %s\n", current_trip->destination);
      printf("Dates : %d - %d\n", current_trip->debut, current_trip->fin);
      printf("Prix : %d\n", current_trip->prix);
    }
    current_trip = current_trip->next;
  }
}


// DISPLAYING THE TRIP DESCRIPTION
void description(char *nom) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (strcmp(current_trip->nom, nom) == 0) {
      printf("Nom : %s\n", current_trip->nom);
      printf("Destination : %s\n", current_trip->destination);
      printf("Dates : %d - %d\n", current_trip->debut, current_trip->fin);
      printf("Prix : %d\n", current_trip->prix);
      break;
    }
    current_trip = current_trip->next;
  }
}


// DISPLAYING THE LIST OF ALL TRIPS
void afficher() {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    printf("Nom : %s\n", current_trip->nom);
    printf("Destination : %s\n", current_trip->destination);
    printf("Dates : %d - %d\n", current_trip->debut, current_trip->fin);
    printf("Prix : %d\n", current_trip->prix);
    current_trip = current_trip->next;
  }
}


int main() {
  int choice;
    printf("** BIENVENUE A TRAVEL-MANAGER **\n\n"); 
    printf("Veuillez saisir votre commande s'il vous plait.\n\n");
  do {
    printf("Menu :\n");
    printf("1. Ajouter un voyage\n");
    printf("2. Afficher la description d'un voyage\n");
    printf("3. Supprimer un voyage\n");
    printf("4. Modifier un voyage\n");
    printf("5. Rechercher des voyages disponibles entre deux dates\n");
    printf("6. Afficher la liste de tous les voyages\n");
    printf("7. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        struct Trip trip;
        printf("Entrez les informations sur le voyage à ajouter :\n");
        printf("Nom : ");
        scanf("%s", trip.nom);
        printf("Destination : ");
        scanf("%s", trip.destination);
        printf("Date de debut (jjmmaaaa) : ");
        scanf("%d", &trip.debut);
        printf("Date de fin (jjmmaaaa) : ");
        scanf("%d", &trip.fin);
        printf("Prix : ");
        scanf("%d", &trip.prix);
        ajouter(trip);
        break;
      }
      case 2: {
        char nom[MAXN];
                printf("Entrez le nom du voyage a afficher : ");
        scanf("%s", nom);
        description(nom);
        break;
      }
      case 3: {
        char nom[MAXN];
        printf("Entrez le nom du voyage a supprimer : ");
        scanf("%s", nom);
        supprimer(nom);
        break;
      }
      case 4: {
        char nom[MAXN];
        printf("Entrez le nom du voyage a modifier : ");
        scanf("%s", nom);
        modifier(nom);
        break;
      }
      case 5: {
        int debut, fin;
        printf("Entrez la date de debut (jjmmaaaa) : ");
        scanf("%d", &debut);
        printf("Entrez la date de fin (jjmmaaaa) : ");
        scanf("%d", &fin);
        recherche(debut, fin);
        break;
      }
      case 6: {
        afficher();
        break;
      }
      case 7: {
        printf("AU REVOIR.\n");
        break;
      }
      default: {
        printf("CHOIX INCORRECT.\n");
        break;
      }
    }
  } while (choice != 7);
  return 0;
}
