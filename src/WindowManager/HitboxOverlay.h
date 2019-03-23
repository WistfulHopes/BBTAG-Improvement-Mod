#pragma once
#include "Game/CharInfo.h"

#include <imgui.h>

#include <d3dx9.h>

typedef unsigned int uint32_t;

class HitboxOverlay
{
public:
	bool windowOpen = false;

	HitboxOverlay() = default;
	void Update();
	void DrawOriginLine(ImVec2 screenPos);
	void DrawCollisionAreas(const CharInfo* charObj, const ImVec2 playerWorldPos);
	float& GetScale();
	void DrawRectThicknessSlider();
	void DrawRectFillTransparencySlider();
	bool HasNullptrInData();

private:
	void BeforeDraw();
	void Draw();
	void AfterDraw();

	bool WorldToScreen(LPDIRECT3DDEVICE9 pDevice, D3DXMATRIX* view, D3DXMATRIX* proj, D3DXVECTOR3* pos, D3DXVECTOR3* out);
	ImVec2 CalculateObjWorldPosition(const CharInfo * charObj);
	ImVec2 CalculateScreenPosition(ImVec2 worldPos);
	ImVec2 RotatePoint(ImVec2 center, float angleInRad, ImVec2 point);

	void RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f, uint32_t segments = 16);
	void RenderCircleFilled(const ImVec2& position, float radius, uint32_t color, uint32_t segments = 16);
	void RenderRect(const ImVec2& pointA, const ImVec2& pointB, const ImVec2& pointC, const ImVec2& pointD, uint32_t color, float thickness = 1.0f);
	void RenderRect(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All, float thickness = 1.0f);
	void RenderRectFilled(const ImVec2& from, const ImVec2& to, uint32_t color, float rounding = 0.0f, uint32_t roundingCornersFlags = ImDrawCornerFlags_All);
	void RenderRectFilled(const ImVec2& pointA, const ImVec2& pointB, const ImVec2& pointC, const ImVec2& pointD, uint32_t color);

	// Literally a magic number as of now
	float m_scale = 0.368f;
	float m_rectThickness = 2.5f;
	float m_rectFillTransparency = 0.5f;

	ImGuiWindowFlags m_windowFlags = ImGuiWindowFlags_NoTitleBar
		| ImGuiWindowFlags_NoInputs
		| ImGuiWindowFlags_NoBringToFrontOnFocus
		| ImGuiWindowFlags_NoFocusOnAppearing;
};
