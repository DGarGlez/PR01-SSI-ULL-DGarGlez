# Documentación del Código

## Descripción General

Este programa permite cifrar y descifrar mensajes utilizando una clave aleatoria. El cifrado se realiza mediante una operación XOR bit a bit entre el mensaje y la clave. El programa ofrece un menú de opciones para cifrar, descifrar o salir.

## Funciones

### `std::vector<bool> stringToBits(const std::string& input)`

Convierte un string en una secuencia de bits.

- **Parámetros**: 
  - `input`: El string de entrada a convertir.
- **Retorno**: Un vector de bits que representa el string de entrada.

### `std::string bitsToString(const std::vector<bool>& bits)`

Convierte una secuencia de bits en un string.

- **Parámetros**: 
  - `bits`: El vector de bits a convertir.
- **Retorno**: Un string que representa la secuencia de bits de entrada.

### `std::vector<bool> sumadorBits(const std::vector<bool>& bits, const std::vector<bool>& key)`

Realiza una operación XOR bit a bit entre dos vectores de bits.

- **Parámetros**: 
  - `bits`: El vector de bits del mensaje.
  - `key`: El vector de bits de la clave.
- **Retorno**: Un vector de bits resultante de la operación XOR entre el mensaje y la clave.

### `std::vector<bool> stringBinarioToBits(const std::string& input)`

Convierte un string binario en un vector de bits.

- **Parámetros**: 
  - `input`: El string binario de entrada a convertir.
- **Retorno**: Un vector de bits que representa el string binario de entrada.

## Función Principal

### `int main()`

Función principal del programa que presenta un menú de opciones al usuario y realiza las operaciones de cifrado y descifrado según la opción seleccionada.

**Menú de Opciones**:
   - `1`: Cifrar mensaje.
   - `2`: Descifrar mensaje.
   - `0`: Salir.

1. **Cifrar Mensaje**:
   - Solicita al usuario que introduzca un mensaje.
   - Convierte el mensaje a una secuencia de bits.
   - Solicita una clave aleatoria del mismo tamaño que el mensaje en bits.
   - Realiza la operación XOR entre el mensaje y la clave.
   - Muestra el mensaje cifrado en binario y en texto.

2. **Descifrar Mensaje**:
   - Solicita al usuario que introduzca un mensaje cifrado.
   - Convierte el mensaje cifrado a una secuencia de bits.
   - Solicita una clave aleatoria del mismo tamaño que el mensaje en bits.
   - Realiza la operación XOR entre el mensaje cifrado y la clave.
   - Muestra el mensaje original en binario y en texto.

0. **Salir**:
   - Muestra un mensaje de salida y termina el programa.

## Manejo de Errores

El programa maneja errores de entrada utilizando `std::cin.clear()` y `std::cin.ignore(10000, '\n')` para limpiar el estado de error y el búfer de entrada, asegurando que las siguientes operaciones de entrada no se vean afectadas por entradas inválidas previas.