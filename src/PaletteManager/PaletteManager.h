#pragma once
#include "impl_format.h"
#include "../Game/CharPaletteHandle.h"
#include "../Game/CharHandle.h"
#include "../Game/characters.h"
#include <vector>

class PaletteManager
{
private:
	std::vector<std::vector<IMPL_data_t>> m_customPalettes;
	std::vector<std::vector<std::string>> m_paletteSlots;
	std::vector<int> m_donatorPalsStartIndex;
	bool loadDonatorPalettes = false;

public:
	PaletteManager();
	~PaletteManager();
	std::vector<std::vector<IMPL_data_t>> &GetCustomPalettesVector();

	void PushImplFileIntoVector(IMPL_t &filledPal);
	void PushImplFileIntoVector(CharIndex charIndex, IMPL_data_t &filledPalData);
	bool WritePaletteToFile(CharIndex charIndex, IMPL_data_t *filledPalData);

	void LoadAllPalettes();
	void ReloadAllPalettes();

	int GetDonatorPalsStartIndex(CharIndex charIndex);
	int FindCustomPalIndex(CharIndex charIndex, const char* palNameToFind);
	bool SwitchPalette(CharIndex charIndex, CharPaletteHandle& palHandle, int newCustomPalIndex);
	void ReplacePaletteFile(const char* newPalData, PaletteFile palFile, CharPaletteHandle& palHandle);
	char* GetPalFileAddr(PaletteFile palFile, CharPaletteHandle& palHandle);
	int GetCurrentCustomPalIndex(CharPaletteHandle& palHandle);
	const IMPL_data_t &GetCurrentPalData(CharPaletteHandle& palHandle);
	//Call it ONCE per frame 
	void OnUpdate(CharPaletteHandle& P1Ch1, CharPaletteHandle& P1Ch2, CharPaletteHandle& P2Ch1, CharPaletteHandle& P2Ch2);
	//Call it ONCE upon match start
	void OnMatchInit(CharHandle& P1Ch1, CharHandle& P1Ch2, CharHandle& P2Ch1, CharHandle& P2Ch2);
	void OnMatchEnd(CharHandle& P1Ch1, CharHandle& P1Ch2, CharHandle& P2Ch1, CharHandle& P2Ch2);

private:
	void CreatePaletteFolders();
	void InitCustomPaletteVector();
	void LoadPalettesIntoVector(CharIndex charIndex, std::wstring& wFolderPath);
	void LoadPalettesFromFolder();

	//bool CreatePaletteSlotsFile();
	void InitPaletteSlotsVector();
	void LoadPaletteSettingsFile();

	void InitDonatorPalsIndexVector();

	void ApplyDefaultCustomPalette(CharIndex charIndex, CharPaletteHandle& charPalHandle);
};