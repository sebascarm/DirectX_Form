#include "SwapChain.h"
#include "DxEngine.h"

bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{
	// Obtenemos el Device
	ID3D11Device* Device = DxEngine::get()->pDevice;
	// Creamos el Descriptor (Detalles del buffer)
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1;									// Cantidad de BackBuffer
	desc.BufferDesc.Width = width;							// Ancho
	desc.BufferDesc.Height = height;						// Alto
	desc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;	// Formato de colores (Red, Green, Blue, Alfa)
	desc.BufferDesc.RefreshRate.Numerator = 60;				// Refrezco en Hrz
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hwnd;								// Ventana de salida
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;
	// Creacion de SwapChain (buffer)
	HRESULT res = DxEngine::get()->pFactoryDxGI->CreateSwapChain(Device, &desc, &pSwapChain);
	// Revisamos si fallo o no
	if (FAILED(res)) {
		return false;
	}
	// Devolvemos OK 
	return true;
}

bool SwapChain::release()
{
	this->pSwapChain->Release();
	delete this;
	return true;
}
