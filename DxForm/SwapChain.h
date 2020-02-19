#pragma once
#include <d3d11.h>

class SwapChain
{
public:
	bool init(HWND hwnd, UINT width, UINT height);		// Inicializa el Swapchange (buffers)
	bool release();

private:
	IDXGISwapChain* pSwapChain;		// Puntero al SwapChain
};
