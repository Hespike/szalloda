#include <string>

using namespace std;

class Szoba {
    string vendeg;
    unsigned int sorszam;
    unsigned int meret;

public:
    Szoba() = default;

    Szoba(const string &vendeg, unsigned int sorszam, unsigned int meret) :
        vendeg(vendeg), sorszam(sorszam), meret(meret) {}

    friend class Emelet;
};

class Emelet {
    int emelet_szam;
    Szoba szobak[4];
    int aktualis_szobak;

public:
    Emelet(int emeletSzam) : emelet_szam(emeletSzam), aktualis_szobak(0) {}

    Emelet& operator+=(const Szoba& sz) {
        if (aktualis_szobak<=3) {
            szobak[aktualis_szobak] = sz;
            aktualis_szobak++;
        }

        return *this;
    }

     string& operator[](unsigned int index)  {
        if (index < aktualis_szobak) {
            return szobak[index].vendeg;
        }

        return szobak[0].vendeg;
    }

    const string& operator[](unsigned int index) const {
        if (index < aktualis_szobak) {
            return szobak[index].vendeg;
        }

        return szobak[0].vendeg;
    }

};
