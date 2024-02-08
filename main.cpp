#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>

using namespace std;

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

    Buch(string n, string vorn, string nachn, string h, string ue, string ver, string ja, string o, string auf)
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
    }

    friend ostream &operator<<(ostream &o, const Buch &b)
    {
        return o << "[" << b.titel << ", " << b.vorname << ", " << b.nachname << ", " << b.herausgeber << ", " << b.uebersetzer << ", " << b.verlag << ", " << b.jahr << ", " << b.ort << ", " << b.auflage << "]";
    }
};

vector<Buch> buecher;

void print_info(std::string a, std::string b, std::string c, string d, string e, string f, string g, string h, string i)
{
    Buch hilfe{a, b, c, d, e, f, g, h, i};
    buecher.push_back(hilfe);
}
// Titel, Autor, Herausgeber, Übersetzer, Verlag, Jahr, Ort, Auflage

void author_suche()
{
    string nachname;
    system("cls");
    cout << "Nachname: ";
    cin >> nachname;
    cout << endl
         << endl;
    for (auto b : buecher)
    {

        if (b.nachname == nachname)
        {
            cout << b << endl;
        }
    }
}

void titel_suche()
{
    usleep(1000000);
    string titel;
    cout << "Titel: ";
    usleep(1000000);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline (cin, titel);
    usleep(1000000);
    for (auto b : buecher)
    {

        if (b.titel == titel)
        {
            cout << b << endl;
        }
    }
}

void main_menu()
{
    int auswahl;
    cout << "-----" << endl;
    cout << "ImZeichen" << endl;
    cout << "-----" << endl;
    cout << "Optionen:" << endl;
    cout << "1: Author Suchen" << endl;
    cout << "2: Titel Suchen" << endl
         << endl;
    cout << "-----" << endl;
    cout << "Eingabe: ";
    cin >> auswahl;

    switch (auswahl)
    {
    case 1:
        author_suche();
        break;
    case 2:
        titel_suche();
        break;

    default:
        cout << "false Eingabe";
        break;
    }
    cout << "Nochwas suchen?: ";
    cin >> auswahl;
}
int main()
{
    string ersteZeile;
    // Datei öffnen
    std::ifstream infile("Buecher.txt");

    // Schleife über die Datei
    while (std::getline(infile, ersteZeile))
    {

        // Stringstream zum Zerlegen der Zeile in Tokens
        std::stringstream ss(ersteZeile);

        // Variablen zum Speichern der 3 Strings
        std::string a, b, c, d, e, f, g, h, i;

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
        std::getline(ss, i);

        // Funktion aufrufen
        print_info(a, b, c, d, e, f, g, h, i);
    }

    // Datei schließen
    infile.close();
    main_menu();
    usleep(1000000);

    return 0;
}