#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <time.h>

#define PARTEIEN 6
#define MAXWAHLEN 20
#define MAXGENAUIGKEIT 10000

int main(int argc, char *argv[ ]) {
  int zahl , anz_befragte ;
  
  int befragte , Umfrage , Partei;
  int ProzentPartei [PARTEIEN + 1] ;
  int MaxProzent [PARTEIEN + 1] ;
  int MinProzent [PARTEIEN + 1] ;
  int Stimmen [PARTEIEN + 1] ;

  ProzentPartei[0] = 0;
  ProzentPartei[1] = 3500;
  ProzentPartei[2] = 6700;
  ProzentPartei[3] = 8000;
  ProzentPartei[4] = 9000;
  ProzentPartei[5] = 9550;
  ProzentPartei[6] = 10000;

  if (argc > 1 ) {
     anz_befragte = atoi(argv[1]);
  }
  else {  
    anz_befragte = 2500;
  }
  
  // Initialisieren der Statistiken Felder
  
  for ( Partei = 0 ; Partei <= PARTEIEN ; Partei++ ) { 
    MaxProzent[Partei]= 0; 
    MinProzent[Partei]= MAXGENAUIGKEIT;
  }  
  // Zufallsgenerator initialisieren.
  srand(time(NULL));

  printf( "<p>Ergebnis der 20 simulierten Sonntagsfragen aus <b>%d</b> Befragten</p>\n" , anz_befragte );
  
  printf( "<table style:\"border-style:  dotted; border-width:1px\" >" );

  printf ( "<tr><th>Umfrage-Nr</th>" );
  for ( Partei = 1 ; Partei <= PARTEIEN ; Partei++ ) {
    printf ( "<th>Partei %1d<br />%6.2f%</th>", Partei, (float) (ProzentPartei[Partei]-ProzentPartei[Partei-1]) / MAXGENAUIGKEIT * 100); 
  };
  
  for (Umfrage = 1 ; Umfrage <= MAXWAHLEN ; Umfrage++ ) {

	// Stimmen initialisieren
	for ( Partei = 1 ; Partei <= PARTEIEN ; Partei++ ) { Stimmen[Partei]= 0; }
	
	// Wahl mit #befragte simulieren 
	for ( befragte = 0 ; befragte < anz_befragte ; befragte++ ) {
	   
	   // Einen zufaelligen Wähler befragen
	   zahl = rand() % MAXGENAUIGKEIT; 
	   // Gewaehlte Partei bestimmen  
	   Partei = 1 ; 
	   while (( zahl >= ProzentPartei[Partei] ) && ( Partei < PARTEIEN )) {
	     Partei++; 
	   };
	   // Stimme zaehlen
	   Stimmen[Partei]++;
	}

	// Ergebnis Simulation Wahl auswerten und drucken
	printf ( "<tr><td>%2d</td>", Umfrage );
	for ( Partei = 1 ; Partei <= PARTEIEN ; Partei++ ) {
	  if (Stimmen[Partei] < MinProzent[Partei]) { MinProzent[Partei] = Stimmen[Partei]; }
	  if (Stimmen[Partei] > MaxProzent[Partei]) { MaxProzent[Partei] = Stimmen[Partei]; }
	  printf ( "<td style:\"text-align : right\">%6.2f</td>", (float) Stimmen[Partei] / anz_befragte * 100); 
	};

	// Zeilen Abschluss drucken
	printf("</tr>\n");
  }
  printf ( "<tr><th>Min %</th>" );
  for ( Partei = 1 ; Partei <= PARTEIEN ; Partei++ ) {
    printf ( "<th style:\"text-align : right\">%6.2f</th>", (float) (MinProzent[Partei]) / anz_befragte * 100); 
  };

  printf ( "<tr><th>Max %</th>" );
  for ( Partei = 1 ; Partei <= PARTEIEN ; Partei++ ) {
    printf ( "<th style:\"text-align : right\">%6.2f</th>", (float) (MaxProzent[Partei]) / anz_befragte * 100); 
  };
  
  printf ("</table>\n");
}


