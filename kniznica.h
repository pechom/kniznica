#ifndef KNIZNICA_H_
#define KNIZNICA_H_

typedef struct Kniha {
    char *nazov;
    char **autori; //pole pointerov na stringy
    int autori_size;
    int pozicana;
    char *citatel;
    int doba;
} kniha_t;

typedef struct Kniznica {
    kniha_t *knihy;
    int size;
} kniznica_t;

typedef struct Mapa {
    char** string_array;
    int* pocty_vyskytov;
    int* sucty_hodnot;
    int size;
} mapa_t;

void kniha_init(kniha_t *kniha);

void kniznica_init(kniznica_t *kniznica);

void map_init(mapa_t *mapa);

void kniha_free(kniha_t *kniha);

void kniznica_free(kniznica_t *kniznica);

void mapa_free(mapa_t *mapa);

void vyplnKnihu(char *nazov, char **autori, int pozicana, char *citatel, int doba, kniha_t *kniha);

void pridaj_knihu(kniha_t *kniha, kniznica_t *kniznica);

void pridaj_map(mapa_t *mapa, char* citatel, int hodnota);

void utried(kniznica_t *kniznica);

int compare(kniha_t *prva, kniha_t *druha);

//kniha_t zoStringu(char *skniha);

kniha_t zoStringu(char* s_kniha);

//char** split(char* a_str, const char a_delim);

char** split(char* a_str, const char a_delim);

char* kniha_toString(kniha_t *kniha);

char* kniznica_toString(kniznica_t *kniznica);

void uloz(kniznica_t *kniznica);

kniznica_t zoSuboru(char* file);

void novyDen(int n, kniznica_t *kniznica);

int pocetNepozicanych(char *nazov, kniznica_t *kniznica);

void pozicka(char* nazov, char* citatel, kniznica_t *kniznica);

int vratenie(char* nazov, char* citatel, kniznica_t *kniznica);

int najdlhsiaVypozicka(kniznica_t *kniznica);

int pocetTitulov(kniznica_t *kniznica);

mapa_t poctyVypozicanychKnih(kniznica_t *kniznica);

char** zoznamNazvovKnihAutora(char* meno, kniznica_t *kniznica);

char** slavniCitatelia(kniznica_t *kniznica);

char* najOblubenejsiaKniha(kniznica_t *kniznica);

#endif /* KNIZNICA_H */


