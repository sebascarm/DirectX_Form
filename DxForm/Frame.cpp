#include "Frame.h"

void Frame::Create(DxForm* DxForm, string Titulo, int x, int y, int ancho, int alto) 
{
	this->hInstance = DxForm->Get_Instance();
	this->NombreClase = DxForm->Get_Class();
	this->Titulo = Titulo;
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
}

void Frame::Draw() {
	DWORD Estilo = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	this->hWnd = CreateWindowEx(
		0,
		(LPSTR)NombreClase.c_str(),
		(LPSTR)Titulo.c_str(),
		Estilo,
		x, y,
		ancho + 16, alto + 59, //tamaños q roba la aplicacion
		nullptr,
		nullptr,
		this->hInstance,
		nullptr);
}

void Frame::Show() {
	ShowWindow(this->hWnd, SW_SHOW);
}

//METODOS
HWND Frame::Get_hWnd() {
	return this->hWnd;
}