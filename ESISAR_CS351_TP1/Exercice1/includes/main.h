#ifndef MAIN_H
#define MAIN_H
enum Note
{
    A,
    B,
    C,
    D,
    E
};

char *appreciation[6] = {
    "Tres bien",
    "Bien",
    "Assez bien",
    "Passable",
    "Insufisant"};

void V1(char note);
void V2(char note);
void V3(char note);
void flushScanf();
#endif