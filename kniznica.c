#define _GNU_SOURCE ;
#define _BSD_SOURCE ;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>
#include <sys/unistd.h>

#include "kniznica.h"


//malloc pola stringov:
//char **array;
//array = malloc(sizeofarray * sizeof(char*));  //su tu ulozene smerniky na char
//for(int i = 0; i < sizeofarray; i++) {
//malloc prvkov
//  array[i] = malloc((strlen(s) + 1) * sizeof(char));  //tu uz je string
//strcpy(array[i], string[i]);
//}


int delim_length;

void kniha_init(kniha_t *kniha) {
    kniha->autori = NULL;
    kniha->autori_size = 0;
    kniha->citatel = NULL;
    kniha->doba = 0;
    kniha->nazov = NULL;
    kniha->pozicana = 0;
}

void kniznica_init(kniznica_t *kniznica) {
    kniznica->knihy = NULL;
    kniznica->size = 0;
}

void map_init(mapa_t *mapa) {
    mapa->string_array = NULL;
    mapa->pocty_vyskytov = NULL;
    mapa->sucty_hodnot = NULL;
    mapa->size = 0;
}

void kniha_free(kniha_t *kniha) {
    free(kniha->nazov);
    int i = 0;
    for (i = 0; i < kniha->autori_size; i++) {
        free(kniha->autori[i]);
    }
    free(kniha->autori);
    kniha->autori_size = 0;
    if (kniha->pozicana == 1) {
        kniha->pozicana = 0;
        free(kniha->citatel);
        kniha->doba = 0;
    }
}

void kniznica_free(kniznica_t *kniznica) {
    int i;
    for (i = 0; i < kniznica->size; i++) {
        kniha_free(&kniznica->knihy[i]);
    }
    free(kniznica->knihy);
    kniznica->size = 0;
}

void mapa_free(mapa_t *mapa) {
    int i;
    for (i = 0; i < mapa->size; i++) {
        free(mapa->string_array[i]);
    }
    free(mapa->string_array);
    free(mapa->pocty_vyskytov);
    free(mapa->sucty_hodnot);
    mapa->size = 0;
}

void vyplnKnihu(char *nazov, char **autori, int pozicana, char *citatel, int doba, kniha_t *kniha) {
    kniha->nazov = malloc((strlen(nazov) + 1) * sizeof (char));
    strncpy(kniha->nazov, nazov, strlen(nazov) + 1);
    int count = 0;
    while (autori[count] != NULL) {
        count++;
    }
    kniha->autori = realloc(kniha->autori, sizeof (char*) * count);
    int i;
    for (i = 0; i < count; i++) {
        kniha->autori[i] = malloc((strlen(autori[i]) + 1) * sizeof (char));
        strncpy(kniha->autori[i], autori[i], strlen(autori[i]) + 1);
    }
    kniha->autori_size = count;
    kniha->pozicana = pozicana;
    if (citatel != NULL) {
        kniha->citatel = malloc((strlen(citatel) + 1) * sizeof (char));
        strncpy(kniha->citatel, citatel, strlen(citatel) + 1);
    } else {
        kniha->citatel = NULL;
    }
    kniha->doba = doba;
}

void rtrim(char* s) {
    int idx = strlen(s) - 1;
    while ((idx >= 0) && isspace(s[idx])) {
        s[idx] = 0;
        idx--;
    }
}

void pridaj_knihu(kniha_t *kniha, kniznica_t *kniznica) {
    kniznica->size = kniznica->size + 1;
    kniznica->knihy = realloc(kniznica->knihy, sizeof (kniha_t) * kniznica->size);
    kniznica->knihy[kniznica->size - 1] = *kniha;
}

void pridaj_map(mapa_t *mapa, char* string, int hodnota) {
    int i;
    int new = 1;
    for (i = 0; i < mapa->size; i++) {
        if (strcmp(mapa->string_array[i], string) == 0) {
            mapa->pocty_vyskytov[i]++;
            mapa->sucty_hodnot[i] += hodnota;
            new = 0;
            break;
        }
    }
    if (new == 1) {
        mapa->size++;
        mapa->string_array = realloc(mapa->string_array, sizeof (char*) * mapa->size);
        mapa->string_array[mapa->size - 1] = malloc((strlen(string) + 1) * sizeof (char));
        strncpy(mapa->string_array[mapa->size - 1], string, strlen(string) + 1);
        mapa->pocty_vyskytov = realloc(mapa->pocty_vyskytov, sizeof (int*)*mapa->size);
        mapa->pocty_vyskytov[mapa->size - 1] = 1;
        mapa->sucty_hodnot = realloc(mapa->sucty_hodnot, sizeof (int*)*mapa->size);
        mapa->sucty_hodnot[mapa->size - 1] = hodnota;
    } else {
        new = 1;
    }

}

void utried(kniznica_t *kniznica) {
    int i = 0;
    int j = 0;
    kniha_t tmp;
    kniha_init(&tmp);
    for (i = 0; i < kniznica->size; i++) {
        for (j = i + 1; j < kniznica->size; j++) {
            if (strcmp(kniznica->knihy[i].autori[0], kniznica->knihy[j].autori[0]) > 0) {
                tmp = kniznica->knihy[i];
                kniznica->knihy[i] = kniznica->knihy[j];
                kniznica->knihy[j] = tmp;
            } else if ((strcmp(kniznica->knihy[i].autori[0], kniznica->knihy[j].autori[0]) > 0)&&(kniznica->knihy[i].nazov, kniznica->knihy[j].nazov)) {
                tmp = kniznica->knihy[i];
                kniznica->knihy[i] = kniznica->knihy[j];
                kniznica->knihy[j] = tmp;
            }
        }
    }
}

int compare(kniha_t *prva, kniha_t *druha) {// v<0 - prva je mensia, v>0 - druha je mensia
    if (strcmp(prva->autori[0], druha->autori[0]) != 0) {
        return strcmp(prva->autori[0], druha->autori[0]);
    } else return strcmp(prva->nazov, druha->nazov);
}

kniha_t zoStringu(char* s_kniha) {
    kniha_t kniha;
    kniha_init(&kniha);
    char** delimitovana = malloc(sizeof (char*) * strlen(s_kniha));
    char** s_autori = malloc(sizeof (char*) * strlen(s_kniha));
    int i;
    for (i = 0; i < 5; i++) {
        delimitovana[i] = NULL;
        s_autori[i]=NULL;
    }
    int is_pozicana = 0;
    delimitovana = split(s_kniha, '\t');
    if (delim_length > 3) {
        is_pozicana = 1;
    }
    s_autori = split(delimitovana[1], ',');
    char* nazov = malloc(sizeof (char)*(strlen(delimitovana[0]) + 1));
    strncpy(nazov, delimitovana[0], strlen(delimitovana[0]) + 1);
    if (is_pozicana == 1) {
        char* citatel = malloc(sizeof (char)*(strlen(delimitovana[3]) + 1));
        strncpy(citatel, delimitovana[3], strlen(delimitovana[3]) + 1);
        int doba = atoi(delimitovana[4]);
        vyplnKnihu(nazov, s_autori, is_pozicana, citatel, doba, &kniha);
        free(citatel);
            for (i = 0; i < 5; i++) {
        if (delimitovana[i] != NULL) {
            free(delimitovana[i]);
        }
    }
    } else {
        char* citatel = NULL;
        int doba = 0;
        vyplnKnihu(nazov, s_autori, is_pozicana, citatel, doba, &kniha);
            for (i = 0; i < 2; i++) {
        if (delimitovana[i] != NULL) {
            free(delimitovana[i]);
        }
    }
    }

    free(nazov);
//    for (i = 0; i < kniha.autori_size; i++) { 
//        if (s_autori[i] != NULL) {
//            free(s_autori[i]);
//        }
//    }
//    free(s_autori);
    free(delimitovana);
    return kniha;
}

char** split(char* a_str, const char a_delim) {
    delim_length = 0;
    char *str = strdup(a_str);
    char *token;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    char** result = malloc(sizeof (char*) * (strlen(a_str)+1));
    int i;
    for (i = 0; i < (strlen(a_str)+1); i++) {
        result[i]=NULL;
    }

    token = strtok(a_str, delim);
    result[delim_length] = malloc((strlen(token) + 1) * sizeof (char));
    strncpy(result[delim_length], token, strlen(token) + 1);
    delim_length++;
    while ((token = strtok(NULL, delim))) {
        result[delim_length] = malloc((strlen(token) + 1) * sizeof (char));
        strncpy(result[delim_length], token, strlen(token) + 1);
        delim_length++;
    }
    free(str);
    return result; 
}

char* kniha_toString(kniha_t *kniha) {
    char* result = malloc(sizeof (char) * sizeof (kniha_t));
    char tmp[128]; //predpokl. max velkost jedneho prvku knihy
    strncpy(tmp, kniha->nazov, strlen(kniha->nazov) + 1);
    strncpy(result, tmp, strlen(tmp) + 1);
    strncat(result, "\t", 2);
    int i;
    for (i = 0; i < kniha->autori_size; i++) {
        strncat(result, kniha->autori[i], strlen(kniha->autori[i]) + 1);
        strncat(result, ",", 1);
    }
    result[strlen(result) - 1] = 0;
    if (kniha->pozicana == 1) {
        strncat(result, "\t", 2);
        snprintf(tmp, 10, "%d", kniha->pozicana);
        strncat(result, tmp, strlen(tmp) + 1);
        strncat(result, "\t", 2);
        strncpy(tmp, kniha->citatel, strlen(kniha->citatel) + 1);
        strncat(result, tmp, strlen(tmp) + 1);
        strncat(result, "\t", 2);
        snprintf(tmp, 10, "%d", kniha->doba);
        strncat(result, tmp, strlen(tmp) + 1);
    } else {
        strncat(result, "\t", 2);
        snprintf(tmp, 10, "%d", kniha->pozicana);
        strncat(result, tmp, strlen(tmp) + 1);
    }
    return result;
}

char* kniznica_toString(kniznica_t *kniznica) {
    char* result = malloc(sizeof (char) * kniznica->size * 512); //predpokl. max velkost knihy
    int i;
    char* result_k;
    for (i = 0; i < kniznica->size; i++) {
        result_k = kniha_toString(&kniznica->knihy[i]);
        strncat(result_k, "\n", 2);
        if (i == 0) {
            strncpy(result, result_k, strlen(result_k) + 1);
        } else {
            strncat(result, result_k, strlen(result_k) + 1);
        }
    }
    result[strlen(result) - 1] = 0;
    free(result_k);
    return result; 
}

void uloz(kniznica_t *kniznica) {
    FILE *f;
    kniha_t kniha;
    char* s_kn;
    f = fopen("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt", "w");
    if (f) {
        int i;
        for (i = 0; i < kniznica->size; i++) {
            kniha = kniznica->knihy[i];
            s_kn = kniha_toString(&kniha);
            fwrite(s_kn, strlen(s_kn), sizeof (char), f);
            fprintf(f, "\n");
        }
        fclose(f);
        free(s_kn);
    }
}

kniznica_t zoSuboru(char* file) { 
    FILE *f;
    kniznica_t kniznica;
    kniha_t kniha;
    kniznica_init(&kniznica);
    kniha_init(&kniha);
    f = fopen(file, "r");
    char buffer[512];
    while (fgets(buffer, sizeof (buffer), f)) {// fgets konci pri '\n'
        kniha = zoStringu(buffer);
        pridaj_knihu(&kniha, &kniznica);
    }
    fclose(f);
    return kniznica;
}

// metody kniznice

void novyDen(int n, kniznica_t *kniznica) {
    int i;
    for (i = 0; i < kniznica->size; i++) {
        if (kniznica->knihy[i].pozicana == 1) {
            kniznica->knihy[i].doba += n;
        }
    }
}

int pocetNepozicanych(char *nazov, kniznica_t *kniznica) {
    int i;
    int poc = 0;
    for (i = 0; i < kniznica->size; i++) {
        if ((strcmp(kniznica->knihy[i].nazov, nazov) == 0)&& (kniznica->knihy[i].pozicana == 0)) {
            poc++;
        }
    }
    return poc;
}

void pozicka(char* nazov, char* citatel, kniznica_t *kniznica) {
    int i;
    for (i = 0; i < kniznica->size; i++) {
        if ((strcmp(kniznica->knihy[i].nazov, nazov) == 0)&& (kniznica->knihy[i].pozicana == 0)) {
            kniznica->knihy[i].pozicana = 1;
            kniznica->knihy[i].citatel = malloc((strlen(citatel) + 1) * sizeof (char));
            strncpy(kniznica->knihy[i].citatel, citatel, strlen(citatel) + 1);
            kniznica->knihy[i].doba = 0;
            break;
        }
    }
}

int vratenie(char* nazov, char* citatel, kniznica_t *kniznica) {
    int i = 0;
    int poc_dni = 0;
    for (i = 0; i < kniznica->size; i++) {
        if ((strcmp(kniznica->knihy[i].nazov, nazov) == 0)&& (strcmp(kniznica->knihy[i].citatel, citatel) == 0)) {
            poc_dni = kniznica->knihy[i].doba;
            kniznica->knihy[i].doba = 0;
            kniznica->knihy[i].pozicana = 0;
            kniznica->knihy[i].citatel = NULL;
            break;
        }
    }
    return poc_dni;
}

int najdlhsiaVypozicka(kniznica_t *kniznica) { //vrati cas najdlshsie vypozicanej knihy. ak nie je jedna kniha ktora ma najv. cas (je ich viac) vrati -1
    int i;
    int naj = -1;
    int poc;
    for (i = 0; i < kniznica->size; i++) {
        if (kniznica->knihy[i].doba >= naj) {
            naj = kniznica->knihy[i].doba;
        }
    }
    for (i = 0; i < kniznica->size; i++) {
        if (kniznica->knihy[i].doba == naj) {
            poc++;
        }
    }
    if (poc == 1) {
        return naj;
    } else {
        return -1;
    }
}

int pocetTitulovSRoznymNazvom(kniznica_t *kniznica) { //nahradzam set
    int i;
    int j;
    int poc_k;
    int duplicita = 0;
    kniznica_t distinct;
    kniznica_init(&distinct);
    for (i = 0; i < kniznica->size; i++) {
        for (j = 0; j < distinct.size; j++) {
            if (strcmp(kniznica->knihy[i].nazov, distinct.knihy[j].nazov) == 0) {
                duplicita = 1;
                break;
            }
        }
        if (duplicita == 0) {
            pridaj_knihu(&kniznica->knihy[i], &distinct);
            poc_k++;
        } else {
            duplicita = 0;
        }
    }
//    kniznica_free(&distinct);  
    return poc_k;
}

mapa_t poctyVypozicanychKnih(kniznica_t *kniznica) {
    mapa_t pocty_vyp;
    map_init(&pocty_vyp);
    int i;
    for (i = 0; i < kniznica->size; i++) {
        if (kniznica->knihy[i].pozicana == 1) {
            pridaj_map(&pocty_vyp, kniznica->knihy[i].citatel, 0);
        }
    }
    return pocty_vyp;
}

char** zoznamNazvovKnihAutora(char* meno, kniznica_t *kniznica) {
    int i;
    int j;
    int k;
    int duplicita = 0;
    char** autorove_knihy = malloc(sizeof (char*) * kniznica->size);
    for (i = 0; i < kniznica->size; i++) {
        autorove_knihy[i] = NULL;
    }

    int autor_size = 0;
    i = 0;
    for (i = 0; i < kniznica->size; i++) {
        for (k = 0; k < kniznica->knihy[i].autori_size; k++) {
            if (strcmp(kniznica->knihy[i].autori[k], meno) == 0) {
                for (j = 0; j < kniznica->size; j++) {
                    if ((autorove_knihy[j] != NULL) &&(strcmp(kniznica->knihy[i].nazov, autorove_knihy[j]) == 0)) {
                        duplicita = 1;
                        break;
                    }
                }
                if (duplicita == 0) {
                    autorove_knihy[autor_size] = malloc(sizeof (char)*(strlen(kniznica->knihy[i].nazov) + 1));
                    strncpy(autorove_knihy[autor_size], kniznica->knihy[i].nazov, strlen(kniznica->knihy[i].nazov) + 1);
                    autor_size++;
                } else {
                    duplicita = 0;
                }
            }
        }
    }
    return autorove_knihy;
}

char** slavniCitatelia(kniznica_t *kniznica) {
    int i;
    int j;
    int duplicita = 0;
    int idx = 0;
    char** citatelia = malloc(sizeof (char*) * kniznica->size);
    char** slavni = malloc(sizeof (char*) * kniznica->size);
    for (i = 0; i < kniznica->size; i++) {
        citatelia[i] = NULL;
    }
    for (i = 0; i < kniznica->size; i++) {
        slavni[i] = NULL;
    }
    i = 0;
    for (i = 0; i < kniznica->size; i++) {
        if (kniznica->knihy[i].pozicana == 1) {
            for (j = 0; j < kniznica->size; j++) {
                if ((citatelia[j] != NULL)&&((strcmp(kniznica->knihy[i].citatel, citatelia[j])) == 0)) {
                    duplicita = 1;
                    break;
                }

            }
            if (duplicita == 0) {
                citatelia[idx] = malloc(sizeof (char)* (strlen(kniznica->knihy[i].citatel) + 1));
                strncpy(citatelia[idx], kniznica->knihy[i].citatel, strlen(kniznica->knihy[i].citatel) + 1);
                idx++;
            } else {
                duplicita = 0;
            }
        }
    }
    i = 0;
    j = 0;
    int k = 0;
    int idx2 = 0;
    for (i = 0; i < idx; i++) {
        for (j = 0; j < kniznica->size; j++) {
            for (k = 0; k < kniznica->knihy[j].autori_size; k++) {
                if (strcmp(kniznica->knihy[j].autori[k], citatelia[i]) == 0) {
                    slavni[idx2] = malloc(sizeof (char)* (strlen(citatelia[i]) + 1));
                    strncpy(slavni[idx2], citatelia[i], strlen(citatelia[i]) + 1);
                    break;
                }
            }
        }
        idx2++;
    }

    i = 0;
    for (i = 0; i < idx; i++) {
        free(citatelia[idx]);
    }
    free(citatelia);
    return slavni;
}

char* najOblubenejsiaKniha(kniznica_t *kniznica) {
    mapa_t oblubenost;
    map_init(&oblubenost);
    char *result;
    int i;
    int max_obl = 0;
    int max_pozic = 0;
    for (i = 0; i < kniznica->size; i++) {
        if (kniznica->knihy[i].pozicana == 1) {
            pridaj_map(&oblubenost, kniznica->knihy[i].nazov, kniznica->knihy[i].doba);
        }
    }
    int j;
    for (j = 0; j < oblubenost.size; j++) {
        if (oblubenost.pocty_vyskytov[j] >= max_obl) {
            max_obl = oblubenost.pocty_vyskytov[j];
        }
    }
    j = 0;
    for (j = 0; j < oblubenost.size; j++) {
        if (oblubenost.pocty_vyskytov[j] == max_obl) {
            if (oblubenost.sucty_hodnot[j] >= max_pozic) {
                max_pozic = oblubenost.sucty_hodnot[j];
            }
        }
    }
    j = 0;
    for (j = 0; j < oblubenost.size; j++) {
        if ((oblubenost.pocty_vyskytov[j] == max_obl)&&(oblubenost.sucty_hodnot[j] == max_pozic)) {
            result = malloc(sizeof (char)*(strlen(oblubenost.string_array[j]) + 1));
            strncpy(result, oblubenost.string_array[j], strlen(oblubenost.string_array[j]) + 1);
            break;
        }
    }
    mapa_free(&oblubenost);
    return result;
}