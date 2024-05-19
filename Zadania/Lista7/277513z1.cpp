// Ksawery Józefowski nr 277513 zadanie 1

#include <iostream>
#include <string>
#include <cstdio>

class Zwierz {
public:
    std::string imie;
    std::string rasa;

    Zwierz(const std::string& imie = "", const std::string& rasa = "") : imie(imie), rasa(rasa) {}

    virtual std::string sound() const = 0;
    virtual ~Zwierz() = default;
};

class Kot : public Zwierz {
public:
    using Zwierz::Zwierz;

    std::string sound() const override {
        return "miau";
    }

    friend std::ostream& operator<<(std::ostream& os, const Kot& kot) {
        os << "Kot: " << kot.imie << ", rasa: " << kot.rasa << ", dzwiek: " << kot.sound();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Kot& kot) {
        is >> kot.imie >> kot.rasa;
        return is;
    }
};

class Pies : public Zwierz {
public:
    using Zwierz::Zwierz;

    std::string sound() const override {
        return "hau";
    }

    friend std::ostream& operator<<(std::ostream& os, const Pies& pies) {
        os << "Pies: " << pies.imie << ", rasa: " << pies.rasa << ", dzwiek: " << pies.sound();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Pies& pies) {
        is >> pies.imie >> pies.rasa;
        return is;
    }
};

int main() {
    Kot kot;
    Pies pies;

    printf("Podaj imie i rase kota: ");
    std::cin >> kot; // Wygodniejsze w tym przypadku od scanf

    printf("Podaj imie i rase psa: ");
    std::cin >> pies;

    printf("Kot: %s, rasa: %s, dzwiek: %s\n", kot.imie.c_str(), kot.rasa.c_str(), kot.sound().c_str());
    printf("Pies: %s, rasa: %s, dzwiek: %s\n", pies.imie.c_str(), pies.rasa.c_str(), pies.sound().c_str());

    return 0;
}
