/**
 * @file LOGIN C++.cpp
 * @author Matthew Salazar, Dominique Salazar, Johnny Loachamin, Alisson Caiza
 * @brief login.cpp contains the login class and its functions.
 * @version 0.1
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstdlib>
#include <iostream>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "stdio.h"
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
#include <locale.h>
#include "bitmap_image.hpp"
#include "md5.h"

#define MAX 3
#define MIN 0
using namespace std;
// SISTEMA DE OPERACIONES ARITMETICAS

// CLASE
/**
 * @brief The login class.
 */
class CalcularExpresion
{
    // Variables

public:
    // Constructor

    // M�todos
    bool validarParentesis(string operacion);
    bool empiezaConOperador(string operacion);
    bool terminaConOperador(string operacion);
    bool alternaOperador(string operacion);
    bool validarExpresion(string operacion);

    int prioridad(char op);
    string convertir(string in);
    double evaluar(string p);
};
/**
 * @brief validarParentesis.
 *
 * @param operacion
 * @return true
 * @return false
 */
bool CalcularExpresion::validarParentesis(string operacion)
{
    stack<char> pila;
    for (int c = 0; c < operacion.size(); c++)
    {
        if (operacion[c] == '(')
        {
            pila.push(operacion[c]);
        }
        else if (operacion[c] == ')')
        {
            if (pila.empty())
            {
                return false;
            }
            else
            {
                pila.pop();
            }
        }
    }
    if (!pila.empty())
    {
        return false;
    }
    return true;
}
/**
 * @brief empiezaConOperador.
 *
 * @param operacion
 * @return true
 * @return false
 */
bool CalcularExpresion::empiezaConOperador(string operacion)
{
    for (int c = 0; c < operacion.size(); c++)
    {
        if (isdigit(operacion[c]))
        {
            return false;
        }
        else if (operacion[c] == '+' || operacion[c] == '-' || operacion[c] == '*' || operacion[c] == '/' || operacion[c] == '^')
        {
            return true;
        }
    }
    return false;
}
/**
 * @brief terminaConOperador.
 *
 * @param operacion
 * @return true
 * @return false
 */
bool CalcularExpresion::terminaConOperador(string operacion)
{
    for (int c = operacion.size() - 1; c > 0; c--)
    {
        if (isdigit(operacion[c]))
        {
            return false;
        }
        else if (operacion[c] == '+' || operacion[c] == '-' || operacion[c] == '*' || operacion[c] == '/' || operacion[c] == '^')
        {
            return true;
        }
    }
    return false;
}
/**
 * @brief alternaOperador.
 *
 * @param operacion
 * @return true
 * @return false
 */
bool CalcularExpresion::alternaOperador(string operacion)
{
    char ultimoElemento = operacion[0];
    // Se da por entendido que todas las expresiones son correctas hasta que se encuentre un error
    bool validacion = true;

    for (int c = 1; c < operacion.size(); c++)
    {
        if (isdigit(operacion[c]))
        {
            if (ultimoElemento == ')')
            {
                validacion = false;
            }
            else
            {
                ultimoElemento = operacion[c];
            }
        }
        else if (operacion[c] == '(')
        {
            if (ultimoElemento == '(')
            {
                ultimoElemento = operacion[c];
            }
            else if (ultimoElemento == '+' || ultimoElemento == '-' || ultimoElemento == '*' || ultimoElemento == '/' || ultimoElemento == '^')
            {
                ultimoElemento = operacion[c];
            }
            else
            {
                validacion = false;
            }
        }
        else if (operacion[c] == ')')
        {
            if (ultimoElemento == ')')
            {
                ultimoElemento = operacion[c];
            }
            else if (isdigit(ultimoElemento))
            {
                ultimoElemento = operacion[c];
            }
            else
            {
                validacion = false;
            }
        }
        else if (operacion[c] == '+' || operacion[c] == '-' || operacion[c] == '*' || operacion[c] == '/' || operacion[c] == '^')
        {
            if (ultimoElemento == ')')
            {
                ultimoElemento = operacion[c];
            }
            else if (isdigit(ultimoElemento))
            {
                ultimoElemento = operacion[c];
            }
            else
            {
                validacion = false;
            }
        }
    }
    return validacion;
}

/**
 * @brief validarExpresion.
 *
 * @param operacion
 * @return true
 * @return false
 */
bool CalcularExpresion::validarExpresion(string operacion)
{
    if (validarParentesis(operacion))
    {
        if (empiezaConOperador(operacion) == false)
        {
            if (terminaConOperador(operacion) == false)
            {
                if (alternaOperador(operacion))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * @brief prioridad.
 *
 * @param op
 * @return int
 */
int CalcularExpresion::prioridad(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case ')':
        return -1;
    default:
        return 0;
    }
}
/**
 * @brief convertir.
 * 
 * @param in 
 * @return string 
 */
string CalcularExpresion::convertir(string in)
{
    stack<char> pila;
    string posf = "";
    for (int i = 0; i < in.size(); i++)
    {
        switch (in[i])
        {
        case '(':
            pila.push('(');
            break;
        case ')':
            while (!pila.empty() && pila.top() != '(')
            {
                posf += string(1, pila.top()) + " ";
                pila.pop();
            }
            pila.pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!pila.empty() && prioridad(in[i]) <= prioridad(pila.top()))
            {
                posf += string(1, pila.top()) + " ";
                pila.pop();
            }
            pila.push(in[i]);
            break;
        default:
            while (isdigit(in[i]) || in[i] == '.')
                posf += string(1, in[i++]);
            posf += " ";
            i--;
        }
    }
    while (!pila.empty())
    {
        posf += string(1, pila.top()) + " ";
        pila.pop();
    }
    return posf;
}
/**
 * @brief evaluar.
 * 
 * @param p 
 * @return double 
 */
double CalcularExpresion::evaluar(string p)
{
    stack<double> pila;
    double op1, op2;
    for (int i = 0; i < p.size(); i += 2)
    {
        switch (p[i])
        {
        case '^':
            op2 = pila.top();
            pila.pop();
            op1 = pila.top();
            pila.pop();
            pila.push(pow(op1, op2));
            break;
        case '*':
            op2 = pila.top();
            pila.pop();
            op1 = pila.top();
            pila.pop();
            pila.push(op1 * op2);
            break;
        case '/':
            op2 = pila.top();
            pila.pop();
            op1 = pila.top();
            pila.pop();
            pila.push(op1 / op2);
            break;
        case '+':
            op2 = pila.top();
            pila.pop();
            op1 = pila.top();
            pila.pop();
            pila.push(op1 + op2);
            break;
        case '-':
            op2 = pila.top();
            pila.pop();
            op1 = pila.top();
            pila.pop();
            /*IF(op2>op1){
                pila.push(0.000001);
            }*/
            pila.push(op1 - op2);
            break;
        default:
            string aux = "";
            while (p[i] != ' ')
                aux += string(1, p[i++]);
            pila.push(atof(aux.c_str()));
            i--;
        }
    }
    return pila.top();
}
// CONSTANTES

const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador = 0;
// TIPOS
typedef char TCadena[MAXCAD + 1]; // MAXCAD caracteres + FINCAD

struct Persona_R
{
    TCadena PASS;
};

// CABECERA DE PROCEDIMIENTOS Y FUNCIONES
/**
 * @brief pausa.
 * 
 * @param cad 
 * @return int 
 */
void test01();
void pausa();
/**
 * @brief finalizar_programa.
 * 
 * @param cad 
 * @return int 
 */
void finalizar_programa();
/**
 * @brief borrar_pantalla
 * 
 * @param cad 
 * @return int 
 */
void borrar_pantalla();
/**
 * @brief Ingresar_PASS
 * 
 * @param cad 
 * @return int 
 */
void Ingresar_PASS(Persona_R &p);
/**
 * @brief confirmar_PASS
 * 
 * @param cad 
 * @return int 
 */
void confirmar_PASS(Persona_R &p);
// Algoritmos de Manejo de Ficheros de Texto
/**
 * @brief insertarPersonaTXT
 * 
 * @param cad 
 * @return int 
 */
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p);
/**
 * @brief EscribePersonaFicheroTXT
 * 
 * @param cad 
 * @return int 
 */
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p);
/**
 * @brief verificar_existencia_fichero
 
 * 
 * @param cad 
 * @return int 
 */
void verificar_existencia_fichero(TCadena nombreFichero);
/**
 * @brief verificar_existencia_de_usuario
 * 
 * @param cad 
 * @return int 
 */
void verificar_existencia_de_usuario(TCadena nombreFichero);
/**
 * @brief verificar_contrasena
 * 
 * @param cad 
 * @return int 
 */
void verificar_contrasena(TCadena nombreFichero, Persona_R &password);

// PROGRAMA PRINCIPAL
/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    Persona_R p;
    ;
    Persona_R password;
    ;
    char opcion;
    int num;
    bool fin, encontrado;
    TCadena nombre_usuario_registrado;

    do
    {
        borrar_pantalla();
        cout << "\n BIENVENIDO AL PROGRAMA PARA CALCULAR UNA EXPRESION ALGEBRAICA!!! \n"
             << endl;
        Sleep(2500);
        cout << "----------------------------" << endl;
        cout << "1. Ingresar como Usuario" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Pixelar Imagen." << endl;
        cout << "4. Salir del Programa." << endl;
        cout << "----------------------------\n\n"
             << endl;
        do
        {
            printf("\n   Introduzca opcion (1-4): ", 162);
            fflush(stdin);
            scanf("%c", &opcion);

        } while (opcion < '1' || opcion > '3');

        switch (opcion)
        {
        case '1':
            cout << "\nDigite su Nombre de Usuario:     "; // INGRESAR COMO USUARIO
            cin >> nombre_usuario_registrado;
            verificar_existencia_fichero(nombre_usuario_registrado);
            // confirmar_PASS(password);
            verificar_contrasena(nombre_usuario_registrado, password);
            Sleep(1000);
            borrar_pantalla();
            main();
            break;

        case '2':
            cout << "\nEscriba su Nuevo Nombre de Usuario:    "; // REGISTRO
            cin >> nombre_usuario_registrado;
            verificar_existencia_de_usuario(nombre_usuario_registrado);
            Ingresar_PASS(p);
            insertarPersonaTXT(nombre_usuario_registrado, p);
            Sleep(1000);
            borrar_pantalla();
            main();
            break;

        case '3':
            cout << "\nProcesando Imagen por favor espere...:    ";
            Sleep(1000);
            test01();
            cout << "\n!!!Guardada. Imagen Procesada con exito!!!! ";
            Sleep(1000);
            borrar_pantalla();
            main();
            break;
        case '4':
            cout << "\nGracias por utilizar nuestro sistema:    ";
            Sleep(1000);
            finalizar_programa();
            break;
        }

    } while (opcion != '3');
    return 0;
}

// IMPLEMENTACI�N DE PROCEDIMIENTOS Y FUNCIONES
/**
 * @brief finalizar_programa
 * 
 * @param cad 
 * @return int 
 */
 
void test01()
{
  bitmap_image base("image.bmp");

   cartesian_canvas canvas(base.width(),base.height());
   canvas.image() = base;

   const int pixel_count  = base.width() * base.height();
   const int N            = static_cast<int>(pixel_count * 0.03); // 3% of pixels
   const double rnd_ratio = pixel_count / (1.0 + RAND_MAX);

   ::srand(0xA57A57A5);

   for (int i = 0; i < N; ++i)
   {
      const int    r  = static_cast<int>(rand() * rnd_ratio);
      const int    x  = (r % base.width());
      const int    y  = (r / base.width());
      const double cx = x - (base.width() / 2.0);
      const double cy = (base.height() / 2.0) - y;
      const double radius = 1.0 + (r % 7);

      canvas.pen_color(base.get_pixel(x, y));
      canvas.fill_circle(cx, cy, radius);
   }

   canvas.image().save_image("ImagenPixelada.bmp"); 
}
void finalizar_programa()
{
    borrar_pantalla();
    printf("El Programa se cerrara en un momento");
    Sleep(2000);
    exit(0);
}
void pausa()
{
    system("PAUSE");
}
void borrar_pantalla()
{
    system("CLS");
}
void Ingresar_PASS(Persona_R &p)
{
    cout << "Escriba su Nuevo PASS:                 ";
    cin >> p.PASS;
    cout << "\nSE HA REGISTRADO CORRECTAMENTE" << endl;
    Sleep(2500);
}
void confirmar_PASS(Persona_R &password)
{
    cout << "Escriba su PASS:                 ";
    cin >> password.PASS;
}

// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p)
{
    ofstream out;
    out.open(nombreFichero, ios::app);
    // Abro el fichero para a�adir
    if (out.bad())
    {
        // El fichero no existe ... lo creo
        out.open(nombreFichero);
    }
    EscribePersonaFicheroTXT(out, p);
    out.close();
}

void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p)
{
    fichero << md5(p.PASS) << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nNombre de Usuario INCORRECTO.....INTENTELO DE NUEVO\n"
             << endl;
        Sleep(1500);
        borrar_pantalla();
        main();
    }
    else
    {
        cout << "\nNombre de Usuario CORRECTO..!!!\n"
             << endl;
        Sleep(1000);
    }
}

void verificar_existencia_de_usuario(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nNombre de Usuario DISPONIBLE\n"
             << endl;
        Sleep(2500);
    }
    else
    {
        cout << "\n Este Nombre de Usuario ya Existe.....INTENTELO DE NUEVO" << endl;
        Sleep(1500);
        borrar_pantalla();
        main();
    }
}

void verificar_contrasena(TCadena nombreFichero, Persona_R &password)
{
    string cadena;
    string contrase;
    cout << "Escriba su PASS:                 ";
    cin >> password.PASS;
    ifstream fichero(nombreFichero, ios::in);
    while (!fichero.eof())
    {
        fichero >> cadena;
    }
    if (cadena != md5(password.PASS))
    {
        cout << "\n PASS es INCORRECTO.....INTENTELO DE NUEVO\n"
             << endl;
        Sleep(1000);
        fichero.close();
    }

    if (cadena == md5(password.PASS))
    {
        cout << "\n Su PASS es CORRECTA..!!! \n"
             << endl;
        Sleep(1000);
        string s, p;
        char opSec;
        char opTer;
        do
        {
            borrar_pantalla();
            cout << "\n BIENVENIDO AL PROGRAMA PARA CALCULAR UNA EXPRESION ALGEBRAICA!!! \n"
                 << endl;
            Sleep(1000);
            cout << "----------------------------" << endl;
            cout << "1. Calcular expresion" << endl;
            cout << "2. Cerrar sesion" << endl;
            cout << "----------------------------\n\n"
                 << endl;
            do
            {
                printf("\n   Introduzca opcion (1-2): ", 162);
                fflush(stdin);
                scanf("%c", &opSec);

            } while (opSec < '1' || opSec > '2');

            switch (opSec)
            {
            case '1':
                do
                {
                    borrar_pantalla();
                    cout << "\n BIENVENIDO AL PROGRAMA PARA CALCULAR UNA EXPRESION ALGEBRAICA!!! \n"
                         << endl;
                    Sleep(1000);
                    CalcularExpresion Calcular;
                    cout << "Ingrese la expresion:" << endl;
                    cin >> s;
                    bool resp = Calcular.validarExpresion(s);
                    if (resp)
                    {
                        p = Calcular.convertir(s);
                        cout << "Posfija: " << p << endl;
                        cout << "Evaluada: " << Calcular.evaluar(p) << endl;
                    }
                    else
                    {
                        cout << "La expresion ingresa es incorrecta" << endl;
                    }
                    cout << "" << endl;
                    Sleep(1000);
                    cout << "Desea ingresar otra expresion? " << endl;
                    cout << "1. SI" << endl;
                    cout << "2. NO" << endl;
                    do
                    {
                        printf("\n   Introduzca opcion (1-2): ", 162);
                        fflush(stdin);
                        scanf("%c", &opTer);

                    } while (opTer < '1' || opTer > '2');
                } while (opTer != '2');
                if (opTer = '2')
                {
                    cout << "\n Gracias por usa el aplicativo!!! \n"
                         << endl;
                    Sleep(1000);
                    cout << "\n Regresando al menu anterior..!!! \n"
                         << endl;
                }
                break;

            case '2':
                cout << "\n Regresando al menu principal..!!! \n"
                     << endl;
                Sleep(1000);
                break;
            }

        } while (opSec != '2');

        main();
    }
}
