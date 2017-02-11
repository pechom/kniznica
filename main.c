#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

#include "kniznica.h"

#define STOP_COMMAND "STOP"
#define END_COMMAND "END"

int main(int argc, char** argv) {
    printf("%s\n", "******************");
    //    kniha_t kniha0;
    //    kniha_t kniha1;
    //    kniha_t kniha2;
    //    kniha_t kniha3;
    //    kniznica_t kniznica;
    //    mapa_t mapa;
    //    kniha_init(&kniha0);
    //    kniha_init(&kniha1);
    //    kniha_init(&kniha2);
    //    kniha_init(&kniha3);
    //    kniznica_init(&kniznica);
    //    map_init(&mapa);
    //    pridaj_map(&mapa, "peter chomic", 1);
    //    char** autori = malloc(sizeof (char*)*50);
    //    autori[0] = "michael moorcock";
    //    char**a2 = malloc(sizeof (char*)*50);
    //    a2[0] = "michael moorcock";
    //    a2[1] = "peter chomic";
    //    vyplnKnihu("weird of the white wolf", autori, 0, NULL, 0, &kniha0);
    //    vyplnKnihu("sailor on the seas of the fate", autori, 1, "michael moorcock", 21, &kniha1);
    //    vyplnKnihu("weird of the white wolf", a2, 0, NULL, 0, &kniha2);
    //    vyplnKnihu("sailor on the seas of the fate", a2, 1, "peter", 20, &kniha3);
    //    pridaj_knihu(&kniha1, &kniznica);
    //    pridaj_knihu(&kniha0, &kniznica);
    //    pridaj_knihu(&kniha2, &kniznica);
    //    pridaj_knihu(&kniha3, &kniznica);
    //    char k3[] = "sailor on the seas of the fate\tmichael moorcock\t1\tpeter\t20";
    //    char k4[] = "sailor on the seas of the fate\tmichael moorcock,peter chomic\t1\tpavol\t40";
    //    char k5[] = "sailor on the seas of the fate\tmichael moorcock,peter chomic\t0";
    //    kniha_t kniha4 = zoStringu(k4);
    //    pridaj_knihu(&kniha4, &kniznica);
    //    int i = 0;
    //
    //    uloz(&kniznica);
    //    kniznica_t k2 = zoSuboru("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt");
    //    char* s_k2 = kniznica_toString(&k2);
    //    printf("%s\n", s_k2);
    //    utried(&kniznica);
    //    char* s_kniha1 = kniha_toString(&kniha0);
    //    printf("%s\n", "vypis prvej knihy");
    //    printf("%s\n", s_kniha1);
    //    char* s_kniha2 = kniha_toString(&kniha2);
    //    printf("%s\n", "vypis druhej knihy");
    //    printf("%s\n", s_kniha2);
    //    char* s_kniznica = kniznica_toString(&kniznica);
    //    printf("%s\n", "vypis kniznice");
    //    printf("%s\n", s_kniznica);
    //    printf("%s\n", "pocet dni knihy pred novym dnom: ma byt 21");
    //    printf("%d\n", kniznica.knihy[0].doba);
    //    novyDen(3, &kniznica);
    //    printf("%s\n", "pocet dni knihy po 3 dnoch: ma byt 24");
    //    printf("%d\n", kniznica.knihy[0].doba);
    //    int poc_nep1 = pocetNepozicanych("sailor on the seas of the fate", &kniznica);
    //    int poc_nep2 = pocetNepozicanych("weird of the white wolf", &kniznica);
    //    printf("%s\n", "pocet nepozicanych s menom sailor on the seas of the fate. ma byt 0");
    //    printf("%d\n", poc_nep1);
    //    printf("%s\n", "pocet nepozicanych s menom weird of the white wolf. ma byt 2");
    //    printf("%d\n", poc_nep2);
    //    pozicka(kniznica.knihy[1].nazov, "michael moorcock", &kniznica);
    //    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 1");
    //    printf("%d\n", kniznica.knihy[1].pozicana);
    //    vratenie(kniznica.knihy[1].nazov, kniznica.knihy[1].citatel, &kniznica);
    //    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 0");
    //    printf("%d\n", kniznica.knihy[1].pozicana);
    //    int najdlhsia = najdlhsiaVypozicka(&kniznica);
    //    printf("%s\n", "najdlhsia vypozicka: ma byt 43");
    //    printf("%d\n", najdlhsia);
    //    int poc_tit = pocetTitulovSRoznymNazvom(&kniznica);
    //    printf("%s\n", "pocet titulov: ma byt 2");
    //    printf("%d\n", poc_tit);
    //    mapa = poctyVypozicanychKnih(&kniznica);
    //    printf("%s\n", "pocet vypozicanych titulov pre kazdeho citatela");
    //    i = 0;
    //    for (i = 0; i < mapa.size; i++) {
    //        printf("%s\n", mapa.string_array[i]);
    //        printf("%d\n", mapa.pocty_vyskytov[i]);
    //    }
    //    char* najoblubenjsia = najOblubenejsiaKniha(&kniznica);
    //    printf("%s\n", "najoblubenejsia kniha. ma byt sailor on the seas of the fate");
    //    printf("%s\n", najoblubenjsia);
    //    char** autorove_knihy = zoznamNazvovKnihAutora("michael moorcock", &kniznica);
    //    printf("%s\n", "zoznam knih autora. malo by vypisat nazvy oboch knih");
    //    i = 0;
    //    while (autorove_knihy[i] != NULL) {
    //        printf("%s\n", autorove_knihy[i]);
    //        i++;
    //    }
    //    char** slavni = slavniCitatelia(&kniznica);
    //    printf("%s\n", "slavni citatelia, ma byt jeden michael moorcock");
    //    i = 0;
    //    while (slavni[i] != NULL) {
    //        printf("%s\n", slavni[i]);
    //        i++;
    //    }


    //      kniznica_free(&kniznica); //program skonci failom
    //        kniznica_free(&k2);
    //            mapa_free(&mapa);
    //            free(s_kniha1);
    //            free(s_kniha2);
    //            free(s_kniznica);
    //            free(autorove_knihy);
    //            free(najoblubenjsia);
    //            free(slavni);

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
    printf("%s\n", "nakoniec napiste END");
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
    utried(&kniznica);
    char* s_kniznica = kniznica_toString(&kniznica);
    printf("%s\n", "vypis kniznice");
    printf("%s\n", s_kniznica);
    int comparement = compare(&kniznica.knihy[0], &kniznica.knihy[1]);
    printf("%s\n", "ciselne porovnanie knih:");
    printf("%d\n", comparement);
    char* s_kniha1 = kniha_toString(&kniznica.knihy[0]);
    printf("%s\n", "vypis prvej knihy");
    printf("%s\n", s_kniha1);
    char* s_kniha2 = kniha_toString(&kniznica.knihy[1]);
    printf("%s\n", "vypis druhej knihy");
    printf("%s\n", s_kniha2);
    printf("%s\n", "ukladanie kniznice do suboru");
    uloz(&kniznica);
    printf("%s\n", "vypis kniznice zo suboru");
    kniznica_t k2 = zoSuboru("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt");
    char* s_k2 = kniznica_toString(&k2);
    printf("%s\n", s_k2);
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
    vratenie(kniznica.knihy[1].nazov, kniznica.knihy[1].citatel, &kniznica); 
    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 0");
    printf("%d\n", kniznica.knihy[0].pozicana);
    int najdlhsia = najdlhsiaVypozicka(&kniznica);
    printf("%s\n", "najdlhsia vypozicka");
    printf("%d\n", najdlhsia);
    int poc_tit = pocetTitulovSRoznymNazvom(&kniznica);
    printf("%s\n", "pocet titulov");
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
    printf("%s\n", "pocet kniha napisanych prvym autorom prvej knihy");
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
              
                //kniznica_free(&kniznica);
                kniznica_free(&k2);
                kniha_free(&kniha);
                mapa_free(&mapa); 
                free(s_kniha1);
                free(s_kniha2);
                free(s_kniznica);
                free(autorove_knihy);
                free(najoblubenjsia);
                free(slavni);
                printf("%s\n", "koniec");
    return (EXIT_SUCCESS);
}
