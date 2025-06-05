#include <iostream>
using namespace std;
int n = 5; // se cambia segun la cant d bits pedida.

// Declaraciones
bool validarBinario(string binario);
int convertirBinarioADecimal(string binario);
int convertirDecimalAOctal(int decimal);
string convertirDecimalAHexadecimal(int decimal);

int main() {
    string binario;

    while (true) {
        cout << "Ingrese un binario de 5 bits: ";
        cin >> binario;

        if (binario.length() != n) {
            cout << "Error: Debe ingresar exactamente 5 bits." << endl;
            continue;  // vuelve a pedir la entrada
        }

        if (!validarBinario(binario)) {
            cout << "Error: Solo se permiten ceros y unos." << endl;
            continue;  // vuelve a pedir la entrada
        }

        break;  // si pasa ambas validaciones, salir del ciclo
    }

    int decimal = convertirBinarioADecimal(binario);
    int octal = convertirDecimalAOctal(decimal);
    string hexadecimal = convertirDecimalAHexadecimal(decimal);

    cout << "DECIMAL     - " << decimal << endl;
    cout << "OCTAL       - " << octal << endl;
    cout << "HEXADECIMAL - " << hexadecimal << endl;

    return 0;
}

// Función para validar el binario del usuario
bool validarBinario(string binario) {
    for (int i = 0; i < n; i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            return false;
        }
    }
    return true;
}

// Función para convertir binario a decimal
int convertirBinarioADecimal(string binario) {
    int decimal = 0;
    int potencia = 16;  // 2^4 (mayor potencia en 5 bits)

    for (int i = 0; i < n; i++) {
        int bit = binario[i] - '0';
        decimal += bit * potencia;
        potencia /= 2;
    }

    return decimal;
}

// Función para convertir decimal a octal
int convertirDecimalAOctal(int decimal) {
    int octal = 0;
    int multiplicador = 1;

    for (int i = 0; i < 2; i++) {  // máximo dos cifras en octal para 5 bits
        int digito = decimal % 8;
        octal += digito * multiplicador;
        decimal /= 8;
        multiplicador *= 10;
    }

    return octal;
}

// Función para convertir decimal a hexadecimal
string convertirDecimalAHexadecimal(int decimal) {
    if (decimal == 0) return "0";

    string hexadecimal = "";
    char hexDigits[] = "0123456789ABCDEF";

    while (decimal > 0) {
        int residuo = decimal % 16;
        hexadecimal = hexDigits[residuo] + hexadecimal;  // agregamos al inicio
        decimal /= 16;
    }

    return hexadecimal;
}

