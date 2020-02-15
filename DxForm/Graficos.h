#pragma once
#include <d3d11.h>
#include "Frame.h"

#pragma comment (lib, "d3d11.lib")

class Graficos
{
public:
	void Create(Frame *Frame);
	void BeginScene(float red, float green, float blue, float alpha);
	void EndFrame();
	~Graficos();

protected:
	HWND hWnd = nullptr;
	// Parameros del DX11
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* pTarget = nullptr;


};


