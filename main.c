#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#include "kniznica.h"

int main(int argc, char** argv) {
    printf("%s\n", "******************");
    kniha_t kniha1;
    kniha_t kniha2;
    kniznica_t kniznica;
    mapa_t mapa;
    kniha_init(&kniha1);
    kniha_init(&kniha2);
    kniznica_init(&kniznica);
    map_init(&mapa);
    char** autori = malloc(sizeof (char*)*50);
    autori[0] = "michael moorcock";
    char**a2 = malloc(sizeof (char*)*50);
    a2[0] = "michael moorcock";
    a2[1] = "peter chomic";
    vyplnKnihu("sailor on the seas of the fate", autori, 1, "michael moorcock", 21, &kniha1);
    vyplnKnihu("weird of the white wolf", a2, 0, NULL, 0, &kniha2);
    pridaj_knihu(&kniha1, &kniznica);
    pridaj_knihu(&kniha2, &kniznica);
    printf("%s\n", kniznica.knihy[0].nazov);
    printf("%s\n", kniznica.knihy[0].autori[0]);
    printf("%d\n", kniznica.knihy[0].pozicana);
    printf("%s\n", kniznica.knihy[0].citatel);
    printf("%d\n", kniznica.knihy[0].doba);
    
    printf("%s\n", kniznica.knihy[1].nazov);
    printf("%s\n", kniznica.knihy[1].autori[0]);
     printf("%s\n", kniznica.knihy[1].autori[1]);
    printf("%d\n", kniznica.knihy[1].pozicana);


    //uloz(&kniznica);// ak bol projekt v userovi tak sa v mene usera pridal znak / co sposobilo ze cygwin nemohol najst exe subor na spustenie
    //ak som to dal do public priecinka tak som zase bez admin spustenia nemohol pridavat do suboru

    //kniznica_t k2 = zoSuboru("C:\\Users\\Peťo Chomič\\Desktop\\materialy skola\\kniznica.txt"); //detto
    //char* s_k2 = kniznica_toString(&kniznica);
    //printf("%s\n", s_k2);

    //    //ostatne metody su funkcne

    //    char k3[] = "sailor on the seas of the fate\tmichael moorcock\t1\tpeter\t20";
    //kniha_t kniha3 = zoStringu(k3);
    //        printf("%s\n", kniha3.nazov);
    //        printf("%s\n", kniha3.autori[0]);
    //        printf("%d\n", kniha3.pozicana);
    //        printf("%s\n", kniha3.citatel);
    //        printf("%d\n", kniha3.doba);
    //    char k4[]="sailor on the seas of the fate\tmichael moorcock,peter chomic\t1\tpeter\t20";
    //    char k5[]="sailor on the seas of the fate\tmichael moorcock,peter chomic\t0";
    //    kniha_t kniha4 = zoStringu(k5); 
    //    printf("%s\n", kniha4.nazov);
    //    printf("%s\n", kniha4.autori[0]);
    //    printf("%s\n", kniha4.autori[1]);
    //    printf("%d\n", kniha4.pozicana);
    //    printf("%s\n", kniha4.citatel);
    //    printf("%d\n", kniha4.doba);
    //

    //    utried(&kniznica);
    //    int comparement = compare(&kniha1, &kniha2);
    //    printf("%s\n", "ciselne porovnanie knih:");
    //    printf("%d\n", comparement);
    //    char* s_kniha1 = kniha_toString(&kniha1);
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
    //    printf("%s\n", "pocet nepozicanych s menom weird of the white wolf. ma byt 1");
    //    printf("%d\n", poc_nep2);
    //    pozicka("weird of the white wolf", "michael moorcock", &kniznica);
    //    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 1");
    //    printf("%d\n", kniznica.knihy[0].pozicana);
    //    vratenie("weird of the white wolf", "michael moorcock", &kniznica);
    //    printf("%s\n", "zobrazi ci je kniha pozicana. ma byt 0");
    //    printf("%d\n", kniha2.pozicana);
    //    int najdlhsia = najdlhsiaVypozicka(&kniznica);
    //    printf("%s\n", "najdlhsia vypozicka: ma byt 24");
    //    printf("%d\n", najdlhsia);
    //    int poc_tit = pocetTitulov(&kniznica);
    //    printf("%s\n", "pocet titulov: ma byt 2");
    //    printf("%d\n", poc_tit);
    //    mapa = poctyVypozicanychKnih(&kniznica);
    //    printf("%s\n", "pocet vypozicanych titulov pre kazdeho citatela: ma byt michael moorcock \n 1");
    //    int i = 0;
    //    for (i = 0; i < mapa.size; i++) {
    //        printf("%s\n", mapa.string_array[i]);
    //        printf("%d\n", mapa.pocty_vyskytov[i]);
    //    }
    //    char** autorove_knihy = zoznamNazvovKnihAutora("michael moorcock", &kniznica);
    //    printf("%s\n", "zoznam knih autora. malo by vypisat nazvy oboch knih");
    //    printf("%s\n", autorove_knihy[0]);
    //    printf("%s\n", autorove_knihy[1]);
    //    char** slavni = slavniCitatelia(&kniznica);
    //    printf("%s\n", "slavni citatelia. vrati michael moorcock");
    //    int i = 0;
    //    for (i = 0; i < 1; i++) {
    //        printf("%s\n", slavni[i]);
    //    }
    //    char* najoblubenjsia = najOblubenejsiaKniha(&kniznica);
    //    printf("%s\n", "najoblubenejsia kniha. ma byt sailor on the seas of the fate");
    //    printf("%s\n", najoblubenjsia);
    //    pozicka("weird of the white wolf", "michael moorcock", &kniznica);
    //    kniznica.knihy[1].doba = 50;
    //    kniznica.knihy[1].pozicana = 1;
    //    najoblubenjsia = najOblubenejsiaKniha(&kniznica);
    //    printf("%s\n", "najoblubenejsia kniha. ma byt weird of the white wolf");
    //    printf("%s\n", najoblubenjsia);

    printf("%s\n", "******************");
    return (EXIT_SUCCESS);
}
