#include <iostream>

using namespace std;

int evaluaExpresion() {
    int r;
    char c;
    cin >> c;
    
    //es digito?
    if ((c >= '0') && (c <= '9')) {
        r = c - '0';
    } else {
        //caso recursivo, leer subexpresiones
        int expr1 = evaluaExpresion();
        int expr2 = evaluaExpresion();
        
        switch (c) {
            case '+':
                r = expr1 + expr2;
                break;
            case '-':
                r = expr1 - expr2;
                break;
            case '*':
                r = expr1 * expr2;
                break;
            case '/':
                r = expr1 / expr2;
                break;
            default:
                break;
        }
    }
    return r;
}

void resuelve() {
    cout << evaluaExpresion() << endl;
}


int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        resuelve();
    
    return 0;
}
