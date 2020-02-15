#include "DxForm.h"

void DxForm::Create(HINSTANCE hInstance) {
	this->hInstance = hInstance;
	NombreClase = "DxForm";
	//registrar la clase windows
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = Call_WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr; 
	wc.lpszMenuName = nullptr;
	wc.hIconSm = nullptr;
	wc.lpszClassName = "DxForm";
	//Registrar
	RegisterClassEx(&wc);

	cout << "INICIAR" << endl;
}


string DxForm::Get_Class() {
	return NombreClase;
}

HINSTANCE DxForm::Get_Instance()
{
	return this->hInstance;
}


//*********************************************
//*** CALLBACK								***
//*********************************************
LRESULT CALLBACK DxForm::Call_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//*********************************************
//*** LOOP									***
//*********************************************
int DxForm::Loop() {
	MSG msg;
	BOOL Result;
	while ((Result = GetMessage(&msg, nullptr, 0, 0)) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};
	if (Result == -1) {
		return -1;
	}
	else {
		return (int)msg.wParam;
	}
}