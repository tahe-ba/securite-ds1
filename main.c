#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

// fonction principale
int main()
{
    clearScreen();
    menu();
}

void menu()
{
    clearScreen();
    printf("  +-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("  |O|u|t|i|l| |d|e| |c|o|d|a|g|e| |e|t| |c|h|i|f|f|r|e|m|e|n|t|\n");
    printf("  +-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+-+-+\n");
    int choice;
    while (1)
    {
        printf("\t1. Algorithme Cesar\n");
        printf("\t2. Algorithme Vigenere\n");
        printf("\t3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cesar();
            break;
        case 2:
            vigenere();
            break;
        case 3:
            printf("Au revoir !\n");
            exit(0);
        default:
            printf("Choix invalide !\n");
            break;
        }
    }
}

void cesar()
{
    clearScreen();
    int choice = 0;
    while (1)
    {
        printf("\t+-+-+-+-+-+\n");
        printf("\t|C|e|s|a|r|\n");
        printf("\t+-+-+-+-+-+\n");
        printf("\t1. Chiffrer\n");
        printf("\t2. Dechiffrer\n");
        printf("\t3. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            chiffrementCesar();
            break;
        case 2:
            deChiffrementCesar();
            break;
        case 3:
            menu();
            break;
        default:
            printf("Choix invalide !\n");
            break;
        }
    }
}

int clef()
{
    while (1)
    {
        int clef;
        printf("Entrez la clef entre 30 et 1000: ");
        scanf("%d", &clef);
        if (clef >= 30 && clef <= 1000)
        {
            return clef;
        }
        else
        {
            printf("Clef invalide !\n");
        }
    }
}

char *clefCipher()
{
    char clef[100];
    printf("Entrez la clef de chiffrement: ");
    while (getchar() != '\n')
        ;
    scanf("%[^\n]", clef);
    fflush(stdin);
    char *rtnPtr = clef;
    return rtnPtr;
}

void chiffrementCesar()
{
    clearScreen();
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t|C|h|i|f|f|r|e|m|e|n|t| |C|e|s|a|r|\n");
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    int c = clef();
    char msg[100];
    printf("Message à chiffrer: ");
    scanf("%s", msg);
    encryptCesar(msg, c);
    printf("Message chiffré: %s\n", msg);
    myPause();
    cesar();
}

void deChiffrementCesar()
{
    clearScreen();
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t|D|e|c|h|i|f|f|r|e|m|e|n|t| |C|e|s|a|r|\n");
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    int c = clef();
    char msg[100];
    printf("Message à déchiffrer: ");
    scanf("%s", msg);
    decryptCesar(msg, c);
    printf("Message déchiffré: %s\n", msg);
    myPause();
    cesar();
}
void decryptCesar(char *text, int shift)
{
    char *ch = text;
    int i = 0;

    while (*ch != '\0')
    {
        // crypter seulement les les lettres de l'alphabets
        if (text[i] != ' ' && isAlpha(text[i]))
        {
            // check if character is uppercase
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                // decrypt uppercase characters
                text[i] = (text[i] - 'A' - shift) % 26 + 'A';
                if (text[i] < 'A')
                {
                    text[i] = text[i] + 'Z' - 'A' + 1;
                }
            }
            else
            {
                // decrypt lowercase characters
                text[i] = (text[i] - 'a' - shift) % 26 + 'a';
                if (text[i] < 'a')
                {
                    text[i] = text[i] + 'z' - 'a' + 1;
                }
            }
        }
        i += 1;
        ch++;
    }
}

void encryptCesar(char *text, int shift)
{
    char *ch = text;
    int i = 0;

    while (*ch != '\0')
    {
        // crypter seulement les les lettres de l'alphabets
        if (text[i] != ' ' && isAlpha(text[i]))
        {
            // check if character is uppercase
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                // convert to lowercase
                text[i] = 'A' + (text[i] - 'A' + shift) % 26;
            }
            else
            {
                text[i] = 'a' + (text[i] - 'a' + shift) % 26;
            }
        }
        i += 1;
        ch++;
    }
}

void vigenere()
{
    clearScreen();
    printf("\t+-+-+-+-+-+-+-+-+\n");
    printf("\t|V|i|g|e|n|e|r|e|\n");
    printf("\t+-+-+-+-+-+-+-+-+\n");
    int choice = 0;
    while (1)
    {
        printf("\t1. Chiffrer\n");
        printf("\t2. Dechiffrer\n");
        printf("\t3. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            chiffrementVigenere();
            break;
        case 2:
            dechiffrementVigenere();
            break;
        case 3:
            menu();
            break;
        default:
            printf("Choix invalide !\n");
            break;
        }
    }
}

void chiffrementVigenere()
{
    clearScreen();
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t|C|h|i|f|f|r|e|m|e|n|t| |V|i|g|e|n|e|r|e|\n");
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    char *clef = clefCipher();
    char msg[100];
    char crypt[100];
    printf("Message à chiffrer: ");
    fflush(stdin);
    while (getchar() != '\n')
        ;
    scanf("%[^\n]s", msg);
    encryptVigenere(msg, clef, crypt);
    printf("Message chiffré: %s\n", crypt);
    myPause();
    vigenere();
}

void encryptVigenere(char *text, char *cle, char *out)
{

    int i, taille = strlen(cle);
    for (i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'A') && (text[i] <= 'Z'))
        {
            int indice = (text[i] + cle[i % taille] - 6) % 26;
            out[i] = 'A' + indice;
        }
        else if ((text[i] >= 'a') && (text[i] <= 'z'))
        {
            int indice = (text[i] + cle[i % taille] - 12) % 26;
            out[i] = 'a' + indice;
        }
        else
            out[i] = text[i];
    }
    out[i] = '\0';
}

void dechiffrementVigenere()
{
    clearScreen();
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t|D|e|c|h|i|f|f|r|e|m|e|n|t| |V|i|g|e|n|e|r|e|\n");
    printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    char *clef = clefCipher();
    char msg[100];
    char decrypt[100];
    printf("Message à déchiffrer: ");
    fflush(stdin);
    while (getchar() != '\n')
        ;
    scanf("%[^\n]s", msg);

    decryptVigenere(msg, clef, decrypt);
    printf("Message déchiffré: %s\n", decrypt);
    myPause();
    vigenere();
}

void decryptVigenere(char *text, char *cle, char *out)
{
    int i, taille = strlen(cle);
    int indice;
    for (i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'A') && (text[i] <= 'Z'))
        {
            indice = ((text[i] - cle[i % taille]) % 26) + 6;
            out[i] = 'A' + indice;
        }
        else if ((text[i] >= 'a') && (text[i] <= 'z'))
        {
            indice = (text[i] - cle[i % taille] + 26) % 26;
            out[i] = 'a' + indice;
        }
        else
            out[i] = text[i];
    }
    out[i] = '\0';
}

void clearScreen()
{
    printf("\033[2J\033[1;1H");
}

int isAlpha(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    return 0;
}

void myPause()
{
    printf("Appuyez sur une touche pour continuer...");
    while (getchar() != '\n')
        ;
    getchar();
}
