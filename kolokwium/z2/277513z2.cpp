#include <iostream>

using namespace std;

class Pojazd{
protected:
    string model;
    int rok,przebieg;
public:
    Pojazd(string m, int r, int p = 0) : model(m), rok(r), przebieg(p){}
    void show(){
        cout << model << " " << rok << " " << przebieg << endl;
    }
    void przejazd(int n){
        przebieg += n;
    }

};

class Spalinowy : public Pojazd{
public:
    Spalinowy(string m, int r, int p = 0) : Pojazd(m,r,p){};
    void przejazd(int n, int t){
        przebieg += n;
        if(t >= 300){
            cout << "Rozważ zatankowanie samochodu" << endl;
        }
    }
};

class Elektryk : public Pojazd{
public:
    Elektryk(string m, int r, int p = 0) : Pojazd(m,r,p){};
    void przejazd(int n, int t){
        przebieg += n;
        if(t >= 100){
            cout << "Rozważ naladowanie samochodu" << endl;
        }
    }
};
int main(){
    string m;
    int r, p1,p2,p3,p4;
    int t = 0;
    int t2 = 0;
    cout << "Podaj 1 auto: " << endl;
    cin >> m;
    cin >> r;
    Spalinowy spal(m,r);
    cout << "Podaj 2 auto: " << endl;
    cin >> m;
    cin >> r;
    Elektryk ele(m,r);
    cout << "Podaj przejazd: " << endl;
    cin >> p1;
    t += p1;
    t2 += p1;
    spal.przejazd(p1,t);
    ele.przejazd(p1,t2);
    spal.show();
    ele.show();
    cout << "Podaj przejazd: " << endl;
    cin >> p2;
    if (t >= 300){
        t -= 300;
    }
    if (t2 >= 100){
        t2 -= 100;
    }
    t += p1;
    t2 += p1;
    spal.przejazd(p2,t);
    ele.przejazd(p2,t2);
    spal.show();
    ele.show();
    cout << "Podaj przejazd: " << endl;
    cin >> p3;
    if (t >= 300){
        t -= 300;
    }
    if (t2 >= 100){
        t2 -= 100;
    }
    t += p1;
    t2 += p1;
    spal.przejazd(p3,t);
    ele.przejazd(p3,t2);
    spal.show();
    ele.show();
    cout << "Podaj przejazd: " << endl;
    cin >> p4;
    if (t >= 300){
        t -= 300;
    }
    if (t2 >= 100){
        t2 -= 100;
    }
    t += p1;
    t2 += p1;
    spal.przejazd(p4,t);
    ele.przejazd(p4,t2);
    spal.show();
    ele.show();

    return 0;
}
