#include "DxEngine.h"
#include "SwapChain.h"

//************************************//
// INICIALIZACION					  //
//************************************//
bool DxEngine::init(){
	// TIPOS DE DRIVERS
	D3D_DRIVER_TYPE tipos_driver[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,	// Driver por Hardware
		D3D_DRIVER_TYPE_WARP,		// Driver por CPU
		D3D_DRIVER_TYPE_REFERENCE	// Driver por Software
	};
	UINT cant_driver = ARRAYSIZE(tipos_driver);
	// NIVEL DE CARACTERISTICAS
	D3D_FEATURE_LEVEL Caract_level[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};
	UINT cant_caract = ARRAYSIZE(Caract_level);
	// CREACION                                            
	HRESULT res = 0;
	for (UINT indice = 0; indice < cant_driver;) {
		res = D3D11CreateDevice(
			NULL,
			tipos_driver[indice],	// Tipo de Driver
			NULL,
			NULL,
			Caract_level,			// Caracteristicas
			cant_caract,			// Cantidad de caracteristicas
			D3D11_SDK_VERSION,
			&pDevice,				// Referencia al Device
			&pCaract_level,			// Referencia al nivel de caracteristicas
			&pContext				// Referencia al Contexto
		);
		if (SUCCEEDED(res))
			// Si esta ok sale de la inicializacion
			break;
		// Incrementar el indice
		++indice;
	};
	if (FAILED(res)) {
		return false;
	}
	
	pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&pDeviceDxGI);
	pDeviceDxGI->GetParent(__uuidof(IDXGIAdapter), (void**)&pAdaptadorDxGI);
	pAdaptadorDxGI->GetParent(__uuidof(IDXGIFactory), (void**)&pFactoryDxGI);


	
	return true;
} 

//************************************//
// METODO GET    					  //
//************************************//

DxEngine* DxEngine::get()	// Devuelve referencia unica al engine
{
	static DxEngine engine;
	return &engine;	
}


//************************************//
// CREAR SWAPCHAIN					  //
//************************************//
SwapChain* DxEngine::createSwapChain()
{
	return new SwapChain();
}

//************************************//
// RELEASE	    					  //
//************************************//

bool DxEngine::release()
{
	this->pContext->Release();
	this->pDevice->Release();
	return true;
}

