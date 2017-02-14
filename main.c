#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

#include "kniznica.h"

#define STOP_COMMAND "STOP"

int main(int argc, char** argv) {
    printf("%s\n", "******************");
//    kniha_t kniha0;
//    kniha_t kniha1;
//    kniha_t kniha2;
//    kniha_t kniha3;
//    kniznica_t kniznica;
//    mapa_t mapa;
//    kniznica_init(&kniznica);
//    map_init(&mapa);
//    char k0[] = "weird of the white wolf\tmichael moorcock\t0";
//    char k1[] = "sailor on the seas of the fate\tmichael moorcock\t1\tmichael moorcock\t21";
//    char k2[] = "weird of the white wolf\tmichael moorcock,peter chomic\t0";
//    char k3[] = "sailor on the seas of the fate\tmichael moorcock,peter chomic\t1\tpeter\t20";
//    kniha0 = zoStringu(k0);
//    kniha1 = zoStringu(k1);
//    kniha2 = zoStringu(k2);
//    kniha3 = zoStringu(k3);
//    pridaj_knihu(&kniha1, &kniznica);
//    pridaj_knihu(&kniha0, &kniznica);
//    pridaj_knihu(&kniha2, &kniznica);
//    pridaj_knihu(&kniha3, &kniznica);
//    char k4[] = "sailor on the seas of the fate\tmichael moorcock,peter chomic\t1\tpavol\t40";
//    kniha_t kniha4 = zoStringu(k4);
//    pridaj_knihu(&kniha4, &kniznica);
//    int i = 0;
//    char* citatel = "michael moorcock";
//    printf("%s\n", "ukladanie kniznice do suboru");
//    uloz(&kniznica);
//    printf("%s\n", "vypis kniznice zo suboru");
//    kniznica_t kn2 = zoSuboru("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt");
//    char* s_k2 = kniznica_toString(&kn2);
//    printf("%s\n", s_k2);
//    char* s_kniha1 = kniha_toString(&kniznica.knihy[0]);
//    printf("%s\n", "vypis prvej knihy");
//    printf("%s\n", s_kniha1);
//    char* s_kniha2 = kniha_toString(&kniznica.knihy[1]);
//    printf("%s\n", "vypis druhej knihy");
//    printf("%s\n", s_kniha2);
//    char* s_kniznica = kniznica_toString(&kniznica);
//    printf("%s\n", "vypis kniznice");
//    printf("%s\n", s_kniznica);
//    int comparement = compare(&kniznica.knihy[0], &kniznica.knihy[1]);
//    printf("%s\n", "ciselne porovnanie knih:");
//    printf("%d\n", comparement);
//    printf("%s\n", "pocet dni prvej knihy pred novym dnom");
//    printf("%d\n", kniznica.knihy[0].doba);
//    novyDen(3, &kniznica);
//    printf("%s\n", "pocet dni prvej knihy po 3 dnoch");
//    printf("%d\n", kniznica.knihy[0].doba);
//    int poc_nep1 = pocetNepozicanych(kniznica.knihy[0].nazov, &kniznica);
//    int poc_nep2 = pocetNepozicanych(kniznica.knihy[1].nazov, &kniznica);
//    printf("%s\n", "pocet nepozicanych s menom prvej knihy");
//    printf("%d\n", poc_nep1);
//    printf("%s\n", "pocet nepozicanych s menom druhej knihy");
//    printf("%d\n", poc_nep2);
//    printf("%s\n", "ide sa pozicat druha kniha");
//    pozicka(kniznica.knihy[1].nazov, citatel, &kniznica);
//    printf("%s\n", "zobrazi ci je druha kniha pozicana. ma byt 1");
//    printf("%d\n", kniznica.knihy[1].pozicana);
//    printf("%s\n", "ide sa vratit druha kniha");
//    int v = vratenie(kniznica.knihy[1].nazov, kniznica.knihy[1].citatel, &kniznica);
//    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 0");
//    printf("%d\n", kniznica.knihy[1].pozicana);
//    int najdlhsia = najdlhsiaVypozicka(&kniznica);
//    printf("%s\n", "najdlhsia vypozicka");
//    printf("%d\n", najdlhsia);
//    int poc_tit = pocetTitulovSRoznymNazvom(&kniznica);
//    printf("%s\n", "pocet titulov s roznym nazvom");
//    printf("%d\n", poc_tit);
//    mapa = poctyVypozicanychKnih(&kniznica);
//    printf("%s\n", "pocet vypozicanych titulov pre kazdeho citatela");
//    i = 0;
//    for (i = 0; i < mapa.size; i++) {
//        printf("%s\n", mapa.string_array[i]);
//        printf("%d\n", mapa.pocty_vyskytov[i]);
//    }
//    char* najoblubenjsia = najOblubenejsiaKniha(&kniznica);
//    printf("%s\n", "najoblubenejsia kniha");
//    printf("%s\n", najoblubenjsia);
//    printf("%s\n", "knihy napisane prvym autorom prvej knihy");
//    char** autorove_knihy = zoznamNazvovKnihAutora(kniznica.knihy[0].autori[0], &kniznica);
//    i = 0;
//    while (autorove_knihy[i] != NULL) {
//        printf("%s\n", autorove_knihy[i]);
//        i++;
//    }
//    char** slavni = slavniCitatelia(&kniznica);
//    printf("%s\n", "slavni citatelia");
//    i = 0;
//    while (slavni[i] != NULL) {
//        printf("%s\n", slavni[i]);
//        i++;
//    }
//    utried(&kniznica);
//    s_kniznica = kniznica_toString(&kniznica);
//    printf("%s\n", "vypis utriedenej kniznice");
//    printf("%s\n", s_kniznica);
//    kniznica_free(&kniznica);
//    kniznica_free(&kn2);
//    mapa_free(&mapa);
//    free(s_kniha1);
//    free(s_kniha2);
//    free(s_kniznica);
//    free(autorove_knihy);
//    free(najoblubenjsia);
//    free(slavni);
    printf("%s\n", "******************");
    char line[512];
    kniznica_t kniznica;
    kniha_t kniha;
    mapa_t mapa;
    kniznica_init(&kniznica);
    kniha_init(&kniha);
    map_init(&mapa);
    int casNaCitatela = 0;
    char* citatel;
    printf("%s\n", "vitajte v programe na spravu kniznice");
    printf("%s\n", "prevedieme vas jeho funkcionalitou");
    printf("%s\n", "teraz pridavajte knihy. pre ukazanie niektorych funkcionalit je potrebne aby ste zadali aspon 2 knihy, prvvu pozicanu a druhu nie, zvysne mozu byt ako chcete. ak ste zadali knihy napiste STOP");
    printf("%s\n", "teraz zadajte meno citatela");
    printf("%s\n", "teraz vam ukazeme co vsetko program dokaze urobit s kniznicou naplnenou vasimi knihami");
    while (fgets(line, 512, stdin) != NULL) {
        rtrim(line);
        if ((strcmp(line, STOP_COMMAND) != 0)&&(casNaCitatela == 0)) {
            kniha = zoStringu(line);
            pridaj_knihu(&kniha, &kniznica);
        }
        if (casNaCitatela == 1) {
            citatel = line;
            break;
        }

        if (strcmp(line, STOP_COMMAND) == 0) {
            casNaCitatela = 1;
        }
    }
    printf("%s\n", "triedim kniznicu");
    int i = 0;
    char* s_kniha1 = kniha_toString(&kniznica.knihy[0]);
    printf("%s\n", "vypis prvej knihy");
    printf("%s\n", s_kniha1);
    char* s_kniha2 = kniha_toString(&kniznica.knihy[1]);
    printf("%s\n", "vypis druhej knihy");
    printf("%s\n", s_kniha2);
    char* s_kniznica = kniznica_toString(&kniznica);
    printf("%s\n", "vypis kniznice");
    printf("%s\n", s_kniznica);
    int comparement = compare(&kniznica.knihy[0], &kniznica.knihy[1]);
    printf("%s\n", "ciselne porovnanie knih:");
    printf("%d\n", comparement);
    printf("%s\n", "pocet dni prvej knihy pred novym dnom");
    printf("%d\n", kniznica.knihy[0].doba);
    novyDen(3, &kniznica);
    printf("%s\n", "pocet dni prvej knihy po 3 dnoch");
    printf("%d\n", kniznica.knihy[0].doba);
    int poc_nep1 = pocetNepozicanych(kniznica.knihy[0].nazov, &kniznica);
    int poc_nep2 = pocetNepozicanych(kniznica.knihy[1].nazov, &kniznica);
    printf("%s\n", "pocet nepozicanych s menom prvej knihy");
    printf("%d\n", poc_nep1);
    printf("%s\n", "pocet nepozicanych s menom druhej knihy");
    printf("%d\n", poc_nep2);
    printf("%s\n", "ide sa pozicat druha kniha");
    pozicka(kniznica.knihy[1].nazov, citatel, &kniznica);
    printf("%s\n", "zobrazi ci je druha kniha pozicana. ma byt 1");
    printf("%d\n", kniznica.knihy[1].pozicana);
    printf("%s\n", "ide sa vratit druha kniha");
    int v = vratenie(kniznica.knihy[1].nazov, kniznica.knihy[1].citatel, &kniznica);
    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 0");
    printf("%d\n", kniznica.knihy[1].pozicana);
    int najdlhsia = najdlhsiaVypozicka(&kniznica);
    printf("%s\n", "najdlhsia vypozicka");
    printf("%d\n", najdlhsia);
    int poc_tit = pocetTitulovSRoznymNazvom(&kniznica);
    printf("%s\n", "pocet titulov s roznym nazvom");
    printf("%d\n", poc_tit);
    mapa = poctyVypozicanychKnih(&kniznica);
    printf("%s\n", "pocet vypozicanych titulov pre kazdeho citatela");
    i = 0;
    for (i = 0; i < mapa.size; i++) {
        printf("%s\n", mapa.string_array[i]);
        printf("%d\n", mapa.pocty_vyskytov[i]);
    }
    char* najoblubenjsia = najOblubenejsiaKniha(&kniznica);
    printf("%s\n", "najoblubenejsia kniha");
    printf("%s\n", najoblubenjsia);
    printf("%s\n", "knihy napisane prvym autorom prvej knihy");
    char** autorove_knihy = zoznamNazvovKnihAutora(kniznica.knihy[0].autori[0], &kniznica);
    i = 0;
    while (autorove_knihy[i] != NULL) {
        printf("%s\n", autorove_knihy[i]);
        i++;
    }
    char** slavni = slavniCitatelia(&kniznica);
    printf("%s\n", "slavni citatelia");
    i = 0;
    while (slavni[i] != NULL) {
        printf("%s\n", slavni[i]);
        i++;
    }
    printf("%s\n", "ukladanie kniznice do suboru");
    uloz(&kniznica);
    printf("%s\n", "vypis kniznice zo suboru");
    kniznica_t k2 = zoSuboru("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt");
    char* s_k2 = kniznica_toString(&k2);
    printf("%s\n", s_k2);
    //    utried(&kniznica);
    //    s_kniznica = kniznica_toString(&kniznica);
    //    printf("%s\n", "vypis utriedenej kniznice");
    //    printf("%s\n", s_kniznica);
    //  kniznica_free(&kniznica);
    //  kniznica_free(&k2);
    kniha_free(&kniha);
    mapa_free(&mapa);
    free(s_kniha1);
    //  free(s_kniha2);
    free(s_kniznica);
    free(autorove_knihy);
    free(najoblubenjsia);
    //  free(slavni);
    printf("%s\n", "koniec");
    return (EXIT_SUCCESS);

    //chyby:
    //v kniha zo stringu ked uvolnujem s_autori po prvku tak mi to ovplyvni metodu uloz kde ulozi chybne data
    //v metode pocetTitulovSRoznymNazvom ked som uvolnoval lokalnu kniznicu tak mi to sposobilo segmentation fault alebo menilo data na inych miestach
    //len vtedy ked mam vstup z konzoly vsetky zakomentovane free mi robia fail aj ked je vstup taky isty ako v skusobnom vstupe
    //utried pomeni data v kniznici
}
