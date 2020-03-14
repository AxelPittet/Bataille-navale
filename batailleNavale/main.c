#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#pragma set_character_execution

#define NOMBRE_COLONNES 9
#define NOMBRE_LIGNES 9

char carte[NOMBRE_COLONNES][NOMBRE_LIGNES], cibleLigne, b;
int choixMenu, cibleColonne;


void clear() {
    system("cls");
}

void pause() {
    system("pause");
}

void afficherTitre() {
    printf("                       .:°       | |\n");
    printf("                   ___|____      | |\n");
    printf("                  / ° ° ° /      | |\n");
    printf("           ---------------------------------\n");
    printf("          <=========Bataille Navale=========>\n");
    printf("            <=============================>\n");
    printf("              <=========================>\n\n");

}

void afficherChoixMenu() {
    printf("                     1 - Jouer\n");
    printf("                     2 - Règles\n");
    printf("                     3 - Scores\n");
    printf("                     4 - Quitter\n\n");
}

void demanderChoixMenu() {
    printf("                       Choix: ");

    fflush(stdin);
    scanf("%d", &choixMenu);
}

void quitter() {
    clear();

    afficherTitre();

    printf("\n                À une prochaine fois!\n\n\n\n");
    printf("     ");
    pause();
}

void regles() {
    clear();

    printf("                        Règles\n\n");
    printf("  Sur la carte il y a :      Un bateau de 5 cases\n");
    printf("                             Un bateau de 4 cases\n");
    printf("                             Deux bateaux de 4 cases\n");
    printf("                             Un bateau de 2 cases\n\n");

    printf("  Le joueur doit tirer des obus sur des cases de la carte\n  pour essayer de toucher un bateau\n");
    printf("  Un bateau est touché quand un obus aterrit sur une\n  des cases du bateau.\n");
    printf("  Un bateau est coulé quand toutes ses cases sont touchées.\n");
    printf("  Une partie se termine quand un joueur coule tout les\n  bateaux adverses\n\n");

    printf("                  ");

    pause();
}

void remplirCarte() {
    for (int i = 0; i < 10; i++) {
        for (int a = 0; a < 10; a++) {
            carte[i][a] = ' ';
        }
    }
}

void afficherCarte() {
    printf("    1  2  3  4  5  6  7  8  9  10\n");

    for (int i = 0, b = 'A'; i < 10, b < 'K'; i++, b++) {
        printf(" %c ", b);
        for (int a = 0; a < 10; a++) {
            printf("[%c]", carte[a][i]);
        }
        printf("\n");
    }
}

void indicationsJeu() {
    printf("  O = tir dans l'eau\n");
    printf("  X = tir touché\n");
    printf("  C = bateau coulé\n\n\n");
}

void tirer() {
    printf("Colonne de la cible : ");
    fflush(stdin);
    scanf("%d", &cibleColonne);

    printf("Ligne de la cible : ");
    fflush(stdin);
    scanf("%c", &cibleLigne);
}

void convertirLigne() {
    if ((cibleLigne >= 'a') && (cibleLigne <= 'j')) {
        cibleLigne -= 97;
    } else if ((cibleLigne >= 'A') && (cibleLigne <= 'J')) {
        cibleLigne -= 65;
    }
}

void changerValeurCarte() {
    if ((cibleColonne = 4) && (cibleLigne = 1)) {
        carte[cibleColonne - 1][cibleLigne] = 'X';
        printf("Touché !\n\n");
    }
}

void verfierTir() {
    if ((cibleColonne < 1) || (cibleColonne > 10) || (cibleLigne < 0) || (cibleLigne > 9)) {
        printf("Tir non valide\n\n");
    } else {
        changerValeurCarte();
    }
}

void jouer() {
    remplirCarte();

    do {
        clear();

        indicationsJeu();

        afficherCarte();

        tirer();

        convertirLigne();

        verfierTir();

        pause();
    } while (cibleColonne != 20000000);

}

int main() {

    SetConsoleOutputCP(65001);

    do {

        clear();

        afficherTitre();

        afficherChoixMenu();

        demanderChoixMenu();

        switch (choixMenu) {
            case 1:
                jouer();
                break;
            case 2:
                regles();

                break;
            case 3:

                break;
            case 4:
                quitter();
                break;
        }

    } while (choixMenu != 4);

    return 0;
}
