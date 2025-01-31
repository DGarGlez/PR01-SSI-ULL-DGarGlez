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

int main() {

    return 0;
}