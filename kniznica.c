#define _GNU_SOURCE ;
#define _BSD_SOURCE ;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

#include "kniznica.h"


int delim_length;

void kniha_init(kniha_t *kniha) {
    kniha->autori = NULL;
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

void vyplnKnihu(char *nazov, char **autori, int pozicana, char *citatel, int doba, kniha_t *kniha) {
    kniha->nazov = nazov;
    kniha->autori = realloc(kniha->autori, sizeof (char*) * sizeof (autori));
    kniha->autori = autori;
    kniha->pozicana = pozicana;
    kniha->citatel = citatel;
    kniha->doba = doba;
}

void pridaj_knihu(kniha_t *kniha, kniznica_t *kniznica) {
    kniznica->size = kniznica->size + 1;
    kniznica->knihy = realloc(kniznica->knihy, sizeof (kniha_t*) * kniznica->size);
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
        mapa->string_array[mapa->size - 1] = strdup(string);
        mapa->pocty_vyskytov = realloc(mapa->pocty_vyskytov, sizeof (int)*mapa->size);
        mapa->pocty_vyskytov[mapa->size - 1] = 1;
        mapa->sucty_hodnot = realloc(mapa->sucty_hodnot, sizeof (int)*mapa->size);
        mapa->sucty_hodnot[mapa->size - 1] = hodnota;
    } else {
        new = 1;
    }

}

void utried(kniznica_t *kniznica) {
    int i = 0;
    int j = 0;
    for (i = 0; i < kniznica->size; i++) {
        for (j = i + 1; j < kniznica->size; j++) {
            if (strcmp(kniznica->knihy[i].autori[0], kniznica->knihy[j].autori[0]) > 0) {
                kniha_t tmp = kniznica->knihy[i];
                kniznica->knihy[i] = kniznica->knihy[j];
                kniznica->knihy[j] = tmp;
            } else if ((strcmp(kniznica->knihy[i].autori[0], kniznica->knihy[j].autori[0]) > 0)&&(kniznica->knihy[i].nazov, kniznica->knihy[j].nazov)) {
                kniha_t tmp = kniznica->knihy[i];
                kniznica->knihy[i] = kniznica->knihy[j];
                kniznica->knihy[j] = tmp;
            }
        }
    }
}

int compare(kniha_t *prva, kniha_t *druha) {
    if (strcmp(prva->autori[0], druha->autori[0]) != 0) {
        return strcmp(prva->autori[0], druha->autori[0]);
    } else return strcmp(prva->nazov, druha->nazov);
}

kniha_t zoStringu(char* s_kniha) {
    kniha_t kniha;
    kniha_init(&kniha);
    char** delimitovana = malloc(sizeof (char*) * sizeof (*s_kniha));
    char** s_autori = malloc(sizeof (char*) * sizeof (*s_kniha));
    int is_pozicana = 0;
    delimitovana = split2(s_kniha, '\t');
    if (delim_length > 4) {
        is_pozicana = 1;
    }
    s_autori = split2(delimitovana[2], ',');
    char* nazov = strdup(delimitovana[1]);
    if (is_pozicana == 1) {
        char* citatel = strdup(delimitovana[4]);
        int doba = atoi(delimitovana[5]);
        vyplnKnihu(nazov, s_autori, is_pozicana, citatel, doba, &kniha);
    } else {
        char* citatel = NULL;
        int doba = 0;
        vyplnKnihu(nazov, s_autori, is_pozicana, citatel, doba, &kniha);
    }

    return kniha;
}

kniha_t zoStringuPreSubor(char* s_kniha) {
    kniha_t kniha;
    kniha_init(&kniha);
    char** delimitovana = malloc(sizeof (char*) * sizeof (*s_kniha));
    char** s_autori = malloc(sizeof (char*) * sizeof (*s_kniha));
    int is_pozicana = 0;
    delimitovana = split2(s_kniha, '\t');
    if (delim_length > 3) {
        is_pozicana = 1;
    }
    s_autori = split2(delimitovana[1], ',');
    int i;
    char* nazov = strdup(delimitovana[0]);
    if (is_pozicana == 1) {
        char* citatel = strdup(delimitovana[3]);
        int doba = atoi(delimitovana[4]);
        vyplnKnihu(nazov, s_autori, is_pozicana, citatel, doba, &kniha);
    } else {
        char* citatel = NULL;
        int doba = 0;
        vyplnKnihu(nazov, s_autori, is_pozicana, citatel, doba, &kniha);
    }

    return kniha;
}

char** split(char* a_str, const char a_delim) {
    delim_length = 0;
    char *str = strdup(a_str);
    char *token;
    char** result = malloc(sizeof (char*) * sizeof (*a_str));
    while ((token = strsep(&str, &a_delim))) {
        result[delim_length] = strdup(token);
        delim_length++;
    }
    free(str);
    return result;
}

char** split2(char* a_str, const char a_delim) {
    delim_length = 0;
    char *str = strdup(a_str);
    char *token;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    char** result = malloc(sizeof (char*) * strlen(a_str));
    token = strtok(a_str, delim);
    printf(">>> %s \n", token);
    result[delim_length] = strdup(token);
    delim_length++;
    while ((token = strtok(NULL, delim))) {
        result[delim_length] = strdup(token);
        delim_length++;
    }
    free(str);
    return result;
}

char* kniha_toString(kniha_t *kniha) {
    char* result = malloc(sizeof (char*) * sizeof (kniha_t*));
    char tmp[256];
    strcpy(tmp, kniha->nazov);
    strcpy(result, tmp);
    strcat(result, "\t");
    int i;
    for (i = 0; i < sizeof (*kniha->autori) / sizeof (char*); i++) {
        strcat(result, kniha->autori[i]);
        strcat(result, ",");
    }
    result[strlen(result) - 1] = 0;
    if (kniha->pozicana == 1) {
        strcat(result, "\t");
        snprintf(tmp, 10, "%d", kniha->pozicana);
        strcat(result, tmp);
        strcat(result, "\t");
        strcpy(tmp, kniha->citatel);
        strcat(result, tmp);
        strcat(result, "\t");
        snprintf(tmp, 10, "%d", kniha->doba);
        strcat(result, tmp);
        strcat(result, "\t");
    } else {
        strcat(result, "\t");
        snprintf(tmp, 10, "%d", kniha->pozicana);
        strcat(result, tmp);
    }
    return result;
}

char* kniznica_toString(kniznica_t *kniznica) {
    char* result = malloc(sizeof (char*)*kniznica->size * 500);
    int i;
    for (i = 0; i < kniznica->size; i++) {
        char* result_k = kniha_toString(&kniznica->knihy[i]);
        strcat(result_k, "\n");
        if (i == 0) {
            strcpy(result, result_k);
        } else {
            strcat(result, result_k);
            strcat(result, ",");
        }
    }
    result[strlen(result) - 1] = 0;
    return result;
}

void uloz(kniznica_t *kniznica) {
    FILE *f;
    kniha_t kniha;
    f = fopen("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt", "w");
    if (f) {
        int i;
        for (i = 0; i < kniznica->size; i++) {
            kniha = kniznica->knihy[i];
            char* s_kn = kniha_toString(&kniha);
            fwrite(s_kn, strlen(s_kn), sizeof(char), f);
            fprintf(f, "\n");
        }
        fclose(f);
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
        kniha = zoStringuPreSubor(buffer);
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
            kniznica->knihy[i].citatel = strdup(citatel);
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

int pocetTitulov(kniznica_t *kniznica) { //nahradzam set
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
    int autor_size = 0;
    for (i = 0; i < kniznica->size; i++) {
        autorove_knihy[i] = NULL;
    }
    i = 0;
    for (i = 0; i < kniznica->size; i++) {
        for (k = 0; k < sizeof (*kniznica->knihy[i].autori) / sizeof (char*); k++) {
            if (strcmp(kniznica->knihy[i].autori[k], meno) == 0) {
                for (j = 0; j < kniznica->size; j++) {
                    if ((autorove_knihy[j] != NULL) &&(strcmp(kniznica->knihy[i].nazov, autorove_knihy[j]) == 0)) {
                        duplicita = 1;
                        break;
                    }
                }
                if (duplicita == 0) {
                    autorove_knihy[autor_size] = strdup(kniznica->knihy[i].nazov);
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
    i = 0;
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
                citatelia[idx] = strdup(kniznica->knihy[i].citatel);
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
            for (k = 0; k < sizeof (*kniznica->knihy[i].autori) / sizeof (char*); k++) {
                if (strcmp(kniznica->knihy[i].autori[k], citatelia[i]) == 0) {
                    slavni[idx2] = strdup(citatelia[i]);
                    idx2++;
                    break;
                }
            }
        }
    }
    return slavni;
}

char* najOblubenejsiaKniha(kniznica_t *kniznica) {
    mapa_t oblubenost;
    map_init(&oblubenost);
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
            return oblubenost.string_array[j];
        }
    }
}

