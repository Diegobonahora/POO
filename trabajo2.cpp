#include <iostream>
using namespace std;

// Declaraciones
void validarBinario(string binario);
int convertirBinarioADecimal(string binario);
int convertirDecimalAOctal(int decimal); 
string convertirDecimalAHexadecimal(int decimal);

int main() {
    string binario;

    //
    cout << "Ingrese un binario de 5 bits: ";
    cin >> binario;

    // si el usuario es medio pajero
    if (binario.length() != 5) {
        cout << "Debe ingresar exactamente 5 bits." << endl;
        return 1;
    }

    validarBinario(binario);  // Valida contenido

    int decimal = convertirBinarioADecimal(binario);
    int octal = convertirDecimalAOctal(decimal);
    string hexadecimal = convertirDecimalAHexadecimal(decimal);

    cout << "DECIMAL - " << decimal << endl;
    cout << "OCTAL   - " << octal << endl;
    cout << "HEXADECIMAL - " << hexadecimal << endl;
 
    return 0;
}

// Función para validar el binario del usuario
void validarBinario(string binario) {
    for (int i = 0; i < 5; i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            cout << "Solo se permiten ceros y unos." << endl; // usuario pelotudo
            exit(1); // cierra el programa.
        }
    }
}

// Función para convertir binario a decimal
int convertirBinarioADecimal(string binario) {
    int decimal = 0;
    int potencia = 16;  // 2^4 (16 es la mayor potencia de 2 en 5 bits)

    for (int i = 0; i < 5; i++) {
        int bit = binario[i] - '0';
        decimal = decimal + bit * potencia; // devuelve este valor
        potencia = potencia / 2;
    }

    return decimal;
}

// Función para convertir decimal a octal
int convertirDecimalAOctal(int decimal) {
    int octal = 0;
    int multiplicador = 1;

    for (int i = 0; i < 2; i++) {  // máximo dos cifras en octal para 5 bits
        int digito = decimal % 8;
        octal = octal + digito * multiplicador; // devuelve este valor
        decimal = decimal / 8;
        multiplicador = multiplicador * 10;
    }

    return octal;
}

string convertirDecimalAHexadecimal(int decimal) {
    if (decimal == 0) return "0";

    string hexadecimal = "";
    char hexDigits[] = "0123456789ABCDEF";//todos los numeros del decimal al hexa

    while (decimal > 0) {
        int resto = decimal % 16;
        hexadecimal = hexDigits[resto] + hexadecimal;  // concatenar al inicio
        decimal /= 16;
    }

    return hexadecimal;
}
