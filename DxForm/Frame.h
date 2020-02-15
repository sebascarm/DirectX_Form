#pragma once
#include <string>
#include "DxForm.h"

using namespace std;

class Frame
{
public:
	void Create(DxForm *DxForm, string Titulo, int x, int y, int ancho, int alto);	
	void Draw();
	void Show();
	// Propiedades
	HWND hWnd = nullptr;
	// Metodos
	HWND Get_hWnd();
protected:
	HINSTANCE hInstance = nullptr;
	string NombreClase;
	string Titulo;
	int x, y, ancho, alto;

};

