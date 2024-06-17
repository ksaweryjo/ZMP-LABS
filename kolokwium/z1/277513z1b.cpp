
#include <iostream>

using namespace std;

int n;

int NWD(int a, int b)
{
    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
    return a;
}

int NWD2(int a, int c)
{
    while(a!=c)
        if(a>c)
            a-=c;
        else
            c-=a;
    return a;
}

void trojki_pitagorejskie(){
    int a,b;
    int c = n;
    int nwd, nwd2;
    for (int i = 1; i < n;i++){
        for (int j = 1; j <=n;j++){
            if (i < j){
                a = j*j - i*i;
                b = 2*i*j;
                if(n*n == a*a + b*b) {
                    nwd = NWD(a, b);
                    nwd2 = NWD2(nwd, c);
                    cout << a / nwd2 << " " << b / nwd2 << " " << n / nwd2 << endl;
                }
            }
        }

    }
}
int main(){
    cout << "Enter a Natural number: "<<endl;
    cin >> n;
    trojki_pitagorejskie();
    return 0;
}
