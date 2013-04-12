/*
*
*   2D Engine
*		Nahuel Lelouche
*		Defines.h Creado 9/4/2013
*
*/

//----------------------------------------------------------------
#ifndef DEFINES_H
#define DEFINES_H
//----------------------------------------------------------------

// Import / Export Engine Libs
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_EXPORTS

//----------------------------------------------------------------
// Includes Standar
#include <windows.h>
#include <string>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
//----------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------
#endif // DEFINES_H
