#pragma once
#include <Windows.h>
#include <string>

#include <iostream>

using namespace std;	// string

class DxForm
{
public:
	void Create(HINSTANCE hInstance);	// Contructor
	int Loop();
	// Propiedades
	HINSTANCE hInstance;
	string NombreClase;
	// Metodos
	HINSTANCE Get_Instance();
	string Get_Class();
protected:
	WNDCLASSEX wc = { 0 };
	static LRESULT CALLBACK Call_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

