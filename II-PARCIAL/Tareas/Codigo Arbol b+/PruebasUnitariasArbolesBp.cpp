#include "pch.h"
#include "CppUnitTest.h"
#include "string"
#include "../ArbolBp/ArbolBp.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace PruebasUnitariasArbolesBp

{
TEST_CLASS(PruebasUnitariasArbolesBp)
195
{
public:
	
	{
	ArbolBp<int> arbolBpPrueba;
	arbolBpPrueba.insertar(9);
	arbolBpPrueba.insertar(2);
	arbolBpPrueba.insertar(1);
	arbolBpPrueba.insertar(7);
Assert::AreEqual(arbolBpPrueba.mostrar(9 2 1 7), 9 2 1 7); 
}

