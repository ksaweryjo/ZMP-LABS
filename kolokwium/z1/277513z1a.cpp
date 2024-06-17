#include <iostream>

using namespace std;

int n;

void trojki_pitagorejskie(){
    int a,b;
    for (int i = 1; i < n;i++){
        for (int j = 1; j <=n;j++){
            if (i < j){
                a = j*j - i*i;
                b = 2*i*j;
                if (n*n == a*a + b*b){
                    cout << a << " " << b << " " << n << endl;
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