#include <iostream>
using namespace std;

int main(){

    string binario;//mas facil recorrer bit x bit.

    cout << "Ingrese un binario de 5 bits: ";
    cin >> binario;

    //si el usuario es tarado vuelve para atras.
    for (int i = 0;i < 5;i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            cout << "Solo se permiten ceros y unos." << endl;
            return 1;
        }
    }
    int decimal = 0;
    int potencia = 16; // a partir del 5to digito/bit

    for (int i = 0; i < 5; i++) {
        char c = binario[i];
        int bit = c - '0';
        decimal += bit * potencia; //decimal + bit * potencia;
        potencia = potencia / 2; // siguiente potencia para sig bit.
    }
     int decimalvalor = decimal;
    // pasamos desde el decimal al octal pq es mas facil
    int octal = 0;
    int multiplicador = 1;

    for (int i = 0; i < 2; i++) {  // 2 iteraciones máximo para 5 bits
        int digito = decimal % 8;
        octal = octal + digito * multiplicador;
        decimal = decimal / 8;
        multiplicador = multiplicador * 10;
    }



    //VALORES YA DADOS.
    cout << "DECIMAL - " << decimalvalor << endl;
    cout << "OCTAL   - " << octal << endl;

    return 0;
}
