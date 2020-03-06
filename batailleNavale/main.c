#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#pragma set_character_execution

int choixMenu;

void afficherTitre() {
    printf("                     .:°       | |\n");
    printf("                 ___|____      | |\n");
    printf("                / ° ° ° /      | |\n");
    printf("         ---------------------------------\n");
    printf("        <=========Bataille Navale=========>\n");
    printf("          <=============================>\n");
    printf("            <=========================>\n\n");

}

void afficherChoixMenu() {
    printf("                  1 - Jouer\n");
    printf("                  2 - Règles\n");
    printf("                  3 - Scores\n");
    printf("                  4 - Quitter\n\n");
}

void demanderChoixMenu() {
    printf("                     Choix: ");

    fflush(stdin);
    scanf("%d", &choixMenu);
}

int main() {

    SetConsoleOutputCP(65001);

    do {

        system("cls");

        afficherTitre();

        afficherChoixMenu();

        demanderChoixMenu();

    } while (choixMenu != 4);

    //a degager apres
    system("pause");

    return 0;
}