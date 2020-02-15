#include "Graficos.h"

void Graficos::Create(Frame *Frame) 
{
	this->hWnd = Frame->Get_hWnd();
	
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 640;
	sd.BufferDesc.Height = 480;
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
	// Creacion de Device y Front y Back Buffer, 
	// SwapChain y Contexto de renderizado
	HRESULT result;
	
	// Set the feature level to DirectX 11.
	D3D_FEATURE_LEVEL featureLevel;
	featureLevel = D3D_FEATURE_LEVEL_11_0;

	result =  D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		&featureLevel,				// feature level
		1,
		D3D11_SDK_VERSION,
		&sd,
		&pSwap,
		&pDevice,
		nullptr,
		&pContext
	);

	ID3D11Resource* pBackBuffer = nullptr;
	result = pSwap->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
	result = pDevice->CreateRenderTargetView(
		pBackBuffer,
		nullptr,
		&pTarget
	);
	pBackBuffer->Release();
	//pbackBuffer = 0;
		
}

void Graficos::BeginScene(float red, float green, float blue, float alpha) {
	float color[4];
	// Setup the color to clear the buffer to.
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = alpha;
	// Clear the back buffer.
	pContext->ClearRenderTargetView(pTarget, color);
	// Clear the depth buffer.
	//pContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	//return;
}

void Graficos::EndFrame() {
	this->pSwap->Present(1u, 0u);
	//this->pSwap->Present(1, 0);

}

// matar (release la clase
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