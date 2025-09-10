#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_MAX 100
#define MAX_HISTO 20

  char  questions[MAX_HISTO][TAILLE_MAX];
  char reponses[MAX_HISTO][TAILLE_MAX];
  int compteur = 0;
  void to_lowercase(char *str) {

    for (int i=0; str[i]; i++) {
        if (str[i]>='A' && str[i]<='Z') {
            str[i] += 32;
        }
    }
}

   int contient(const char *phrase, const char *mot_cle) {
         return strstr(phrase, mot_cle) != NULL;
}

  int main() {
    char entree[TAILLE_MAX];
    char reponse[TAILLE_MAX];
      printf("Chatbot simple en C (tapez 'exit' pour quitter, 'history' pour historique)\n");
     while (1) {
        printf("Vous : ");
        fgets(entree, TAILLE_MAX, stdin);
        entree[strcspn(entree, "\n")] = 0; // enlever \n
        to_lowercase(entree);

        if (strcmp(entree, "exit") == 0) {
            printf("Bot : Au revoir !\n");
            break;
        }

        if (strcmp(entree, "history") == 0) {
            if (compteur == 0) {
                printf("Aucun historique.\n");
            } else {
                for (int i=0; i<compteur; i++) {
                    printf("Vous : %s\nBot : %s\n", questions[i], reponses[i]);
                }
            }
            continue;
        }
        if (contient(entree, "bien") || contient(entree, "heureux") || contient(entree, "content")) {
            strcpy(reponse, "Je suis content que tu ailles bien !");
        } else if (contient(entree, "mal") || contient(entree, "triste") || contient(entree, "fatigue")) {
            strcpy(reponse, "Oh, je suis désolé. Ça ira mieux bientôt.");
        } else if (contient(entree, "bonjour") || contient(entree, "salut")) {
            strcpy(reponse, "Bonjour ! Comment ça va ?");
        } else {
            strcpy(reponse, "Je ne comprends pas, peux-tu reformuler ?");
        }

        printf("Bot : %s\n", reponse);

        if (compteur < MAX_HISTO) {
            strcpy(questions[compteur], entree);
            strcpy(reponses[compteur], reponse);
            compteur++;
        }
    }

    return 0;
}
