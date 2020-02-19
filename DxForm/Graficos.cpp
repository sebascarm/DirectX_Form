#include "Graficos.h"

void Graficos::Create(Frame *Frame) {	
	this->hWnd = Frame->Get_hWnd();
	DXGI_SWAP_CHAIN_DESC sd = Desc_Estructura();
	// Creacion de Device y Front y Back Buffer, 
	// SwapChain y Contexto de renderizado
	D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,						// 0 O D3D11_CREATE_DEVICE_DEBUG,
		nullptr,				// feature level
		0,						// 1 
		D3D11_SDK_VERSION,
		&sd,
		&pSwap,
		&pDevice,
		nullptr,
		&pContext
	);
	ID3D11Resource* pBackBuffer = nullptr;
	pSwap->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
	pDevice->CreateRenderTargetView(
		pBackBuffer,
		nullptr,
		&pTarget
	);
	pBackBuffer->Release();
	//pbackBuffer = 0;
		
}

// Retorna el Descriptor de estructura
DXGI_SWAP_CHAIN_DESC Graficos::Desc_Estructura() {
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 640;
	sd.BufferDesc.Height = 280;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 1;
	sd.OutputWindow = this->hWnd;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = 0;
	return sd;
}

void Graficos::ClearBuffer(float red, float green, float blue) {
	float color[4];
	// Setup the color to clear the buffer to.
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = 1.0f;	//Alfa
	// Clear the back buffer.
	pContext->ClearRenderTargetView(pTarget, color);
}

void Graficos::EndFrame() {
	this->pSwap->Present(1u, 0u);
}

// matar (release la clase)
Graficos::~Graficos(){
	if (this->pTarget != nullptr) {
		pTarget->Release();
	}
	if (this->pContext != nullptr) {
		pContext->Release();
	}
	if (this->pSwap != nullptr) {
		pSwap->Release();
	}
	if (this->pDevice != nullptr) {
		pDevice->Release();
	}
}