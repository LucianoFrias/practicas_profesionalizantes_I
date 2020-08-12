/*
Vamos a hacer un ejemplo completo que use arreglos (“arrays”), y estructuras 
(“struct”) y que además manipule strings.

La idea va a ser la siguiente: Crearemos un programa que pueda almacenar datos de
hasta 1000 archivos (archivos de computadora). Para cada archivo, debe guardar los 
siguientes datos: Nombre del archivo (max 40 letras), Tamaño (en KB, número de 0 
a 2.000.000.000). El programa mostrará un menú que permita al usuario las 
siguientes operaciones:

1- Añadir datos de un nuevo archivo
2- Mostrar los nombres de todos los archivos almacenados
3- Mostrar archivos que sean de más de un cierto tamaño (por ejemplo, 2000 KB).
4- Ver todos los datos de un cierto archivo (a partir de su nombre)
5- Salir de la aplicación (como todavía no sabemos almacenar los datos, éstos se 
perderán).

No debería resultar difícil. Vamos a ver directamente una de las formas en que se
podría plantear y luego comentaremos alguna de las mejoras que se podría 
(incluso se debería) hacer.

Una opción que podemos a tomar para resolver este problema es la de contar el 
número de archivos que tenemos almacenados, y así podremos añadir de uno en uno. 
Si tenemos 0 archivos, deberemos almacenar la siguiente (la primera) en la 
posición 0; si tenemos dos archivos, serán la 0 y la 1, luego añadiremos en la 
posición 2; en general, si tenemos “n” archivos, añadiremos cada nueva ficha en la 
posición “n”. Por otra parte, para revisar todas las archivos, recorreremos desde 
la posición 0 hasta la n-1, haciendo algo como

for (i=0; i<=n-1; i++) { //... más órdenes ... }

O algo como:

for (i=0; i<n; i++) { //... más órdenes ... }

El resto del programa no es difícil: sabemos leer y comparar textos y números. 
Sólo haremos dos consideraciones:

-No se comportará correctamente si los textos (nombre del archivo, por ejemplo) 
contienen espacios, porque aún no sabemos leer textos con espacios.

-Hemos limitado el número de archivos a 1000, así que, si nos piden añadir, 
deberíamos asegurarnos antes de que todavía tenemos hueco disponible.

Con todo esto, nuestro fuente quedaría así:
*/

// Array con muchos structs y menú para manejarla
 
#include <iostream>
#include <string>
using namespace std;
 
struct FileData
{
    string name;// Nombre del archivo
    long size;// El tamaño en bytes
};
 
int numberOfFiles=0;// Número de archivos que ya tenemos
int i;// Para bucles
int option;// La option del menu que elija el usuario
 
string tempText;// Para pedir datos al usuario
int tempNumber;
 
int main()
{
    //FileData* files = new FileData[1000];
    FileData files[1000];
 
    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;
 
        cin >> option;
 
        // Hacemos una cosa u otra según la opción escogida
        switch(option)
        {
            case 1: // Añadir un dato nuevo
                if (numberOfFiles < 1000)   // Si queda hueco
                {
                    cout << "Introduce el nombre del archivo: ";
                    cin >> files[numberOfFiles].name;
                    cout << "Introduce el tamaño en KB: ";
                    cin >> files[numberOfFiles].size;
                    numberOfFiles++;  // Y tenemos una ficha más
                }
                else   // Si no hay hueco para más archivos, avisamos
                    cout << "Máximo de archivos alcanzado (1000)!" << endl;
                break;
 
            case 2: // Mostrar todos
                for (i=0; i<numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                        << "; Tamaño: " << files[i].size
                        << "Kb" << endl;
                break;
 
            case 3: // Mostrar según el tamaño
                cout << "¿A partir de que tamaño quieres que te muestre? ";
                cin >> tempNumber;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].size >= tempNumber)
                        cout << "Nombre: " << files[i].name
                            << "; Tamaño: " << files[i].size
                            << " Kb" << endl;
                break;
 
            case 4: // Ver todos los datos (pocos) de un archivo
                cout << "¿De qué archivo quieres ver todos los datos?";
                cin >> tempText;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].name == tempText)
                        cout << "Nombre: " << files[i].name
                            << "; Tamaño: " << files[i].size
                            << " Kb" << endl;
                break;
 
            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opción: no válida
                cout << "Opción desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opción es 5, terminamos
 
    return 0;
}