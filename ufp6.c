//
// Created by frede on 22/12/2023.
//

#include "ufp6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ufp6(char* str) {
    int len = strlen(str);
    char* str2 = (char*)malloc(sizeof(char) * len * 6 + 1); // +1 para o caractere nulo
    int j = 0;

    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '0':
                str2[j++] = '0';
                break;
            case '1':
                str2[j++] = '1';
                break;
            case '2':
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case '3':
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case '4':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case '5':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case '6':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case '7':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case '8':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case '9':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'a':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'b':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'c':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'd':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'e':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'f':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'g':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'h':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'i':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'j':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'k':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'l':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'm':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'n':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'o':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'p':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'q':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'r':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 's':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 't':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'u':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'v':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'w':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'x':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'y':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'z':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'A':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;

            case 'B':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;

            case 'C':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;

            case 'D':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;

            case 'E':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;

            case 'F':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;

            case 'G':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;

            case 'H':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;

            case 'I':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;

            case 'J':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;

            case 'K':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;

            case 'L':
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;

            case 'M':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;

            case 'N':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'O':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'P':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'Q':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'R':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'S':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'T':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'U':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'V':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '0';
                break;
            case 'W':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '0';
                str2[j++] = '1';
                break;
            case 'X':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '0';
                break;
            case 'Y':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            case 'Z':
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '1';
                str2[j++] = '0';
                str2[j++] = '1';
                str2[j++] = '1';
                break;
            default:
                printf("error\n");
                return NULL;
                break;
        }
    }

    str2[j] = '\0'; // adiciona caractere nulo no fim
    return str2;
}