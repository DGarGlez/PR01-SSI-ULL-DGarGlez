#include <iostream>
#include <vector>
#include <string>

// Función que convierte un string a bits
std::vector<bool> stringToBits(const std::string& input) {
    std::vector<bool> bits;
    for (char c : input) {
        for (int i = 7; i >= 0; --i) {
            bits.push_back((c >> i) & 1);
        }
    }
    return bits;
}

// Función que convierte bits a string
std::string bitsToString(const std::vector<bool>& bits) {
    std::string output;
    for (size_t i = 0; i < bits.size(); i += 8) {
        char c = 0;
        for (size_t j = 0; j < 8; ++j) {
            c = (c << 1) | bits[i + j];
        }
        output += c;
    }
    return output;
}

// Sumador de bits mod 2 sin acarreo
std::vector<bool> sumadorBits(const std::vector<bool>& bits, const std::vector<bool>& key) {
    std::vector<bool> result;
    for (size_t i = 0; i < bits.size(); ++i) {
        result.push_back(bits[i] ^ key[i % key.size()]);
    }
    return result;
}

// String en binario a bits
std::vector<bool> stringBinarioToBits(const std::string& input) {
    std::vector<bool> bits;
    for (char c : input) {
        if (c == '0') {
            bits.push_back(0);
        } else if (c == '1') {
            bits.push_back(1);
        }
    }
    return bits;
}

int main() {

    // MENÚ DE OPCIONES
    std::cout << "\n1.\tCifrar mensaje" << std::endl;
    std::cout << "2.\tDescifrar mensaje" << std::endl;
    std::cout << "0.\tSalir" << std::endl;
    std::cout << "Seleccione una opción:\t";
    int opcion;
    
    while (!(std::cin >> opcion) || opcion < 0 || opcion > 2) {
        std::cout << "Opción inválida.\nSeleccione una opción:\t";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } 
    std::cout << std::endl;

    std::string mensaje;
    std::vector<bool> bits_m;
    std::string clave;
    std::vector<bool> key;
    std::vector<bool> result;

    switch (opcion)
    {
        case 0: 
        {
            std::cout << "SALIENDO...\n" << std::endl;
            break;
        }
        case 1: 
        {
            std::cout << "Mensaje original: " << std::endl;
            std::cin >> mensaje;
            bits_m = stringToBits(mensaje);
            std::cout << "Mensaje original en binario:\t";
            for (bool bit : bits_m) {
                std::cout << bit;
            }
            std::cout << "\n";
            std::cout << "Longitud del mensaje binario:\t" << bits_m.size() << std::endl;


            std::cout << "Clave aleatoria: " << std::endl;

            while (!(std::cin >> clave) && clave.size() != bits_m.size()) {
                std::cout << "Clave inválida. Introduzca una clave de " << bits_m.size() << " bits:\t";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            std::cout << std::endl;

            key = stringBinarioToBits(clave);
            result = sumadorBits(bits_m, key);

            std::cout << "Mensaje cifrado en binario: ";
            for (bool bit : result) {
                std::cout << bit;
            }
            std::cout << "\n";
            std::cout << "Mensaje cifrado en texto: " << bitsToString(result) << std::endl;

            std::cout << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Mensaje cifrado: " << std::endl;
            std::cin >> mensaje;
            bits_m = stringToBits(mensaje);
            std::cout << "Mensaje cifrado en binario:\t";
            for (bool bit : bits_m) {
                std::cout << bit;
            }
            std::cout << "\n";
            std::cout << "Longitud del mensaje binario:\t" << bits_m.size() << std::endl;


            std::cout << "Clave aleatoria: " << std::endl;

            while (!(std::cin >> clave) && clave.size() != bits_m.size()) {
                std::cout << "Clave inválida. Introduzca una clave de " << bits_m.size() << " bits:\t";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            std::cout << std::endl;

            std::vector<bool> key = stringBinarioToBits(clave);
            std::vector<bool> result = sumadorBits(bits_m, key);

            std::cout << "Mensaje original en binario: ";
            for (bool bit : result) {
                std::cout << bit;
            }
            std::cout << "\n";
            std::cout << "Mensaje original en texto: " << bitsToString(result) << std::endl;

            std::cout << std::endl;
            break;
        }

    }

    return 0;
}