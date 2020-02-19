//******************************************************************************************************************//
// CONFIGURACION APLICADA																							//
//******************************************************************************************************************//
// All Configuration // All Platform (La base es un Empty Proyect)													//
//																													//
// General	>	Dir Salida		> $(SolutionDir)Bin\																//
//			>	Dir Intermed	> $(SolutionDir)Tmp\																//
//			>	Nomb Destino	> $(ProjectName)		- (Release / 64 Bits)										//
//			>	Nomb Destino	> $(ProjectName)_d		- (Debug   / 64 Bits)										//
//			>	Nomb Destino	> $(ProjectName)_32		- (Release / 32 Bits)										//
//			>	Nomb Destino	> $(ProjectName)_32d	- (Debug   / 32 Bits)										//
//																													//
// Advanced >	Juego de caract	> Multibyte																			//
// C/C++	>	General			> Multi-Proc Compilation	> YES													//
//				Optimization	> Favor Size or Speed		> FAVOR FAST CODE										//
//				Preprocessor	> Prepr Definitions			> ....; NDEBUG(Solo en Release)							//
//				Code Generation > Runtime Library			> Multi - threaded(/ MT)  - Estatico(Solo en Release)	//
//								> Runtime Library			> Multi - threaded(/ MTd) - Estatico(Solo en Debug)		//
//								> Floating Point Model		> FAST													//
//			Languaje			> C++ Lang Standard			> LAST COMPILER											//
//																													//
// Linker	>	System			> SubSystem					> Windows												//
//******************************************************************************************************************//
// Plantilla con la configuración minima necesaria recomendada por chilli, se incuyen los directores de salida,		//
// especial para crear proyectos C++																				//
//******************************************************************************************************************//

#include <Windows.h>

#include "DxForm.h"
#include "Frame.h"
#include "Graficos.h"

DxForm form;
Frame frame1;
Graficos grafico;


int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpszCmdParam,
	_In_ int nCmdShow)
{
	form.Create(hInstance);
	frame1.Create(&form, "Titulo", 10, 10, 640, 480);

	
	frame1.Draw();
	frame1.Show();

	grafico.Create(&frame1);

	grafico.ClearBuffer(0.2f, 0.0f, 0.2f);
	grafico.EndFrame();

	form.Loop();

	return 0;
}
