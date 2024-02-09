#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>

using namespace std;

bool loop = true;

class Buch
{
public:
    string titel;
    string vorname;
    string nachname;
    string herausgeber;
    string uebersetzer;
    string verlag;
    string jahr;
    string ort;
    string auflage;
    string untertitel;

    Buch(string n, string vorn, string nachn, string h, string ue, string ver, string ja, string o, string auf, string untert)
    {
        titel = n;
        vorname = vorn;
        nachname = nachn;
        herausgeber = h;
        uebersetzer = ue;
        verlag = ver;
        jahr = ja;
        ort = o;
        auflage = auf;
        untertitel = untert;
    }

    friend ostream &operator<<(ostream &o, const Buch &b)
    {
        o << "[" << b.nachname << ", " << b.vorname << ": " << b.titel;
        if (b.untertitel.size() > 1)
        {
            o << ". " << b.untertitel;
        }

        if (b.herausgeber.size() > 1)
        {
            o << ". Herausgegeben von " << b.herausgeber;
        }
        if (b.uebersetzer.size() > 1)
        {
            o << ". Übersetzt von " << b.uebersetzer;
        }
        if (b.auflage.size() > 1)
        {
            o << ". " << b.auflage;
        }

        return o << ". " << b.verlag << ": " << b.ort << " " << b.jahr << ".]";
    }
};

vector<Buch> buecher;

void print_info(std::string a, std::string b, std::string c, string d, string e, string f, string g, string h, string i, string j)
{
    Buch hilfe{a, b, c, d, e, f, g, h, i, j};
    buecher.push_back(hilfe);
}
// Titel, Autor, Herausgeber, Übersetzer, Verlag, Jahr, Ort, Auflage

void author_suche()
{
    bool eintrag = false;
    string nachname;
    cout << "-----" << endl;
    cout << "\x1B[35mAuthor Suche\033[0m" << endl;
    cout << "-----" << endl;
    cout << "Nachname: ";
    cin >> nachname;
    cout << endl;
    for (auto b : buecher)
    {

        if (b.nachname == nachname)
        {
            cout << b << endl;
            eintrag = true;
        }
    }
    if (!eintrag)
    {
        cout << "[Kein Eintrag]" << endl;
    }
}

void titel_suche()
{
    bool eintrag = false;
    usleep(100);
    cout << "-----" << endl;
    cout << "\x1B[93mTitel-Suche\033[0m" << endl;
    cout << "-----" << endl;
    string titel;
    cout << "Titel: ";
    usleep(100);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, titel);
    usleep(100);
    cout << endl;
    for (auto b : buecher)
    {

        if (b.titel == titel)
        {
            cout << b << endl;
            eintrag = true;
        }
    }
    if (!eintrag)
    {
        cout << "[Kein Eintrag]" << endl;
    }
}
void buecher_anzahl()
{
    int count{0};
    for (auto b : buecher)
    {
        count++;
    }
    cout << "----------------------" << endl;
    cout << "Sie besitzen " << count << " Bücher" << endl;
    cout << "----------------------" << endl;
}
void buecher_anzeige()
{
    system("clear");
    cout << "-----" << endl;
    cout << "\033[3;43;30mImZeichen\033[0m" << endl;
    cout << "-----" << endl
         << endl;

    for (auto b : buecher)
    {
        cout << "[" << b.nachname << ", " << b.vorname << ": " << b.titel << "]" << endl;
    }
}
void author_anzeige()
{
    system("clear");
    cout << "-----" << endl;
    cout << "\033[3;43;30mImZeichen\033[0m" << endl;
    cout << "-----" << endl
         << endl;
    for (auto b : buecher)
    {
        cout << "[" << b.nachname << ", " << b.vorname << "]" << endl;
    }
}
void sonstiges()
{
    int auswahl;

    cout << "-----" << endl;
    cout << "Sonstiges" << endl;
    cout << "-----" << endl
         << endl;
    cout << "Optionen:" << endl;
    cout << "1: Anzahl der Bücher" << endl;
    cout << "2: Alle Bücher anzeigen" << endl;
    cout << "3: Alle Author/innen anzeigen" << endl
         << endl;
    cout << "-----" << endl;
    cout << "Eingabe: ";
    cin >> auswahl;
    system("clear");
    switch (auswahl)
    {
    case 1:
        buecher_anzahl();
        break;
    case 2:
        buecher_anzeige();
        break;
    case 3:
        author_anzeige();
        break;

    default:
        cout << "Falsche Eingabe" << endl;
        break;
    }
}
void main_menu()
{
    string loopweiter;
    int auswahl;

    cout << "-----" << endl;
    cout << "\033[3;43;30mImZeichen\033[0m" << endl;
    cout << "-----" << endl
         << endl;
    cout << "Optionen:" << endl;
    cout << "\x1B[35m1\033[0m: Author Suchen" << endl;
    cout << "\x1B[93m2\033[0m: Titel Suchen" << endl;
    cout << "3: Sonstiges" << endl
         << endl;
    cout << "-----" << endl;
    cout << "Eingabe: ";
    cin >> auswahl;
    system("clear");
    switch (auswahl)
    {
    case 1:
        author_suche();
        break;
    case 2:
        titel_suche();
        break;
    case 3:
        sonstiges();
        break;

    default:
        cout << "Falsche Eingabe" << endl;
        break;
    }
    cout << endl;
    cout << "Nochmal?(j/n): ";
    cin >> loopweiter;
    if (loopweiter == "j")
    {
        loop = true;
    }
    else
    {
        loop = false;
    }
}
int main()
{
    /* Irgendwo ist diese Datei aber ka wo, musst noch suchen (Pfad und so)
    ofstream myfile("example.txt");
    myfile << "test";
    myfile.close();
    */
    string ersteZeile;
    // Datei öffnen
    std::ifstream infile("Buecher.txt");

    // Schleife über die Datei
    while (std::getline(infile, ersteZeile))
    {

        // Stringstream zum Zerlegen der Zeile in Tokens
        std::stringstream ss(ersteZeile);

        // Variablen zum Speichern der 3 Strings
        std::string a, b, c, d, e, f, g, h, i, j;

        // Trennzeichen definieren
        char delimiter = ',';

        // Extrahieren der Tokens
        std::getline(ss, a, delimiter);
        std::getline(ss, b, delimiter);
        std::getline(ss, c, delimiter);
        std::getline(ss, d, delimiter);
        std::getline(ss, e, delimiter);
        std::getline(ss, f, delimiter);
        std::getline(ss, g, delimiter);
        std::getline(ss, h, delimiter);
        std::getline(ss, i, delimiter);
        std::getline(ss, j);

        // Funktion aufrufen
        print_info(a, b, c, d, e, f, g, h, i, j);
    }

    // Datei schließen
    infile.close();
    while (loop)
    {
        system("clear");
        main_menu();
    }
    system("clear");
    cout << "     ---------------------     " << endl;
    cout << "-----";
    cout << "Danke für den Besuch!";
    cout << "-----" << endl;
    cout << "     ---------------------     ";

  
    usleep(2000000);

    return 0;
}