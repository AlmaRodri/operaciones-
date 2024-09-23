/*
AUTOR: Alma Rodriguez 
CURSO:  LENGUAJES Y AUTOMATAS I 
PROGRAMA: Operaciones con lenguajes
FECHA: 18/09/24
*/
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <set>
#include <string>
using namespace std;

typedef set<string> lenguaje;

//Declaracion de funciones generar cadenas
lenguaje generarLe(int, int, char, char );
void print(const lenguaje&, const string );
lenguaje uni(const lenguaje& , const lenguaje& );
lenguaje intersection(const lenguaje& , const lenguaje& );
lenguaje difference(const lenguaje& , const lenguaje& );
lenguaje concatenation(const lenguaje& , const lenguaje& );
lenguaje power(const lenguaje& , int );

//Aqui comienza el main 
int main() {
srand(time(0)); //se usa como semilla para los ramdons
int m,n,p;
char alfa, beta;

cout << "Ingresa datos: " << endl;
cin >> m >> n >> p >> alfa >> beta;

//Se generan lenguajes 
lenguaje LeA =  generarLe(m,n,alfa,beta);
lenguaje LeB = generarLe(m,n,alfa,beta);

cout << "Cadenas generadas: "<<endl;
print(LeA, "A: ");
print(LeB, "B: ");

cout << "Union: " << endl;
print(uni(LeA, LeB), " ");

cout << "Interseccion: " << endl;
print(intersection(LeA, LeB), " ");

cout << "Diferencia: " << endl;
print(difference(LeA, LeB), " ");

cout << "Concatenacion: " << endl;
print(concatenation(LeA, LeB), " ");

cout << "Potencias: " << endl;
print(power(LeA,p),"A: ");
print(power(LeB,p),"B: ");

  return 0;
}

lenguaje generarLe(int m, int n, char alfa, char beta){
    lenguaje lenguajes;

    // Generar una cantidad aleatoria de cadenas no mayor a m
    int nCadAlea = rand() % (m + 1);
    if(nCadAlea == 0){
        lenguajes.insert(""); 
    }

    for (int i = 0; i < nCadAlea; i++) {
        string cadena;

        // Generar la longitud aleatoria de la cadena no mayor a n
        int longitud = rand() % (n + 1);
        if(longitud == 0){
            lenguajes.insert(""); 
        } else {
            // Generar la cadena aleatoria con símbolos entre alfa y beta
            for (int j = 0; j < longitud; j++) {
                char simbolo = alfa + rand() % (beta - alfa + 1);
                cadena += simbolo;
            }
            lenguajes.insert(cadena);  
        }
    }

    return lenguajes;
}
//imprimir el resultado de las funciones en formato []
void print(const lenguaje& lenguaje, string letra) {
    cout << letra << "[";
    for (const auto& cadena : lenguaje) {
        if (cadena =="") {
            cout << "<void> ";  // Imprime <void> si es una cadena vacía
        } else {
            cout << cadena << " ";
        }
    } 
    cout << "]" << endl;
}
//funcion para unir 2 lengujes 
lenguaje uni(const lenguaje& LeA, const lenguaje& LeB) {
    lenguaje unionAB = LeA;
    //se usa la funcion insert del set para agregar las cadenas leb a unionAB 
    unionAB.insert(LeB.begin(), LeB.end());
    return unionAB;
}
//funcion para la interseccion de los lenguajes
lenguaje intersection(const lenguaje& LeA, const lenguaje& LeB) {
    lenguaje interAB;
    for (const string& cadena : LeA) {
      /*se usa find para buscar la cadena, sino lo encuentra apunta a end
      si el apuntador no es end lo guardamos porque si lo encontro*/
        if (LeB.find(cadena) != LeB.end()) { 
            interAB.insert(cadena);
        }
    }
    return interAB;
}
//funcion de diferencia de conjuntos
lenguaje difference(const lenguaje& LeA, const lenguaje& LeB) {
    lenguaje difAB;
    for (const string& cadena : LeA) {
      /*se usa find para buscar la cadena, sino lo encuentra apunta a end
      lo guardamos porque no lo encontro*/
        if (LeB.find(cadena) == LeB.end()) {
            difAB.insert(cadena);
        }
    }
    return difAB;
}
//funcion para concatenar conjuntos
lenguaje concatenation(const lenguaje& LeA, const lenguaje& LeB) {
  lenguaje concatAB;
    for (const string& cadA : LeA) {
        for (const string& cadB : LeB) {
             concatAB.insert(cadA + cadB);
        }
    }
    return concatAB;
}
//funcion para la potencia del conjunto
lenguaje power(const lenguaje& Le, int p) {
lenguaje potencia = {""};  
    if (p == 0) {
        return potencia;  
    }

    potencia = Le;  
    for (int i = 1; i < p; i++) {
        lenguaje result;
        for (const string& cad1 : potencia) {
            for (const string& cad2 : Le) {
                result.insert(cad1 + cad2);  
            }
        }
        potencia = result; 
    }

    return potencia;
}