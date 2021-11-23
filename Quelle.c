#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)
#define uint unsigned int
#define uchar unsigned char
#define MAX 3
#define MAXV 10
#define MAXN 20
#define MAXL 1
typedef enum { false, true } bool;

//#define Aufgabe1
//#define Aufgabe2


//Aufgabe 1
int ist_symmetrisch(int mtrx[MAX][MAX]) {

	int y = 0;

	for (int x = 0; x < MAX; x++, y = 0) {
		for (; y < MAX; y++) {
			if (mtrx[x][y] != mtrx[y][x])
				return 0;
		}
	}

	return 1;
}

//Aufgabe 2
typedef struct Student {
	uint matrikelnummer;
	uchar fachsemester;
	char vorname[MAXV];
	char nachname[MAXN];

	struct Student* next;

} student;


//Initialisert Elemente der Studentenliste
void init(student sl[MAXL]) {

	for (int i = 0; i < MAXL; i++) {

		sl[i].matrikelnummer = 0;
		sl[i].fachsemester = 0;

		strcpy(sl[i].vorname, "n.n.");
		strcpy(sl[i].nachname, "n.n.");

	}
}


//Gibt die Liste der Studenten aus
void print(student sl[MAXL]) {

	printf("Studenten:\n\n%-15s%-15s%-15s%-15s\n", "Matrikelnr.", "Vorname", "Nachname", "Fachsemester");

	for (int i = 0; i < MAXL; i++) {
		printf("%-15d%-15s%-15s%-15d\n", sl[i].matrikelnummer, sl[i].vorname, sl[i].nachname, sl[i].fachsemester);
	}
}

void eingeben(student sl[MAXL]) {
	int p = -1; 

	while (++p < MAXL && sl[p].matrikelnummer != 0);
	p == MAXL ? exit(-1) : --p;

	int rgw;
	printf("Bitte Matrikelnr. eingeben: ");
	rgw = scanf("%d", &sl[p].matrikelnummer);
	printf("Bitte Vorname eingeben: ");
	rgw = scanf("%s", &sl[p].vorname);
	printf("Bitte Nachname eingeben: ");
	rgw = scanf("%s", &sl[p].nachname);
	printf("Bitte Fachsemster eingeben: ");
	rgw = scanf("%s", &sl[p].vorname);
}

int main() {

	student sl[MAXL];

	init(sl);
	
	eingeben(sl);



#ifdef Aufgabe1
	int mtrx[MAX][MAX] = { {1, 2, 3},
						   {2, 1, 2},
						   {3, 2, 1} };


	printf("Matrix ist%s\n", ist_symmetrisch(mtrx) ? "symmetrisch." : "nicht symmetrisch.");

#endif //Aufgabe1

#ifdef Aufgabe2

	bool ende = false;
	int input = 0;

	//while (!ende) {
	const char* menue[] = { "Student eingeben\n", "Student suchen\n", "Student loeschen\n", "Liste drucken\n", "Liste initialisieren\n", "Programm beenden\n" };
	int p = 0;

	printf("Bitte waehlen Sie:\n");
	while (p < 6) {
		printf("%d\t%s", p + 1, menue[p]);
		p++;
	}
	p = 0;

	int rgw = scanf("%d", &input);

	switch (input) {
	case 1:
		eingeben()
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		print(sl);
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		printf("Keine gueltige Eingabe.\n");
	}

	//}
#endif // Aufgabe2


}