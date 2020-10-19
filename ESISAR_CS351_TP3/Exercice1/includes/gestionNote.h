#ifndef __GESTIONNOTE_H__
#define __GESTIONNOTE_H__
void afficherNotes(double *table, int size);

double minimumNote(double *table, int size);
double maximumNote(double *table, int size);
double calculeMoyenne(double *table, int size);
double calculeVariance(double *table, int size);
double calculeEcartType(double *table, int size);

int rechercherValeur(double *table, int size, double value);

void afficherHistogrammeHO(double* table, int size);

#endif