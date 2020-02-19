#pragma once
#include <d3d11.h>

#pragma comment (lib, "d3d11.lib")  // Incorpora la libreria

class SwapChain;        // Declaracion adelantada

class DxEngine
{
public:
    bool init();        // Inicializar (Inicializa el motor y Dx 11 Device)
    bool release();     // Liberar
    // Metodo ESTATICO
    static DxEngine* get();
    SwapChain* createSwapChain();
private:
    ID3D11Device* pDevice;              // Puntero a la Device creada
    D3D_FEATURE_LEVEL pCaract_level;    // Puntero a la Caracteristica usada
    ID3D11DeviceContext* pContext;      // Puntero al Contexto
    IDXGIDevice* pDeviceDxGI;           // Puntero al Device DIRECT X INFRASTRUCTURE
    IDXGIAdapter* pAdaptadorDxGI;       // Puntero al Adaptador de Direct X
    IDXGIFactory* pFactoryDxGI;         // Punterio a Factory

    friend class SwapChain;
};

