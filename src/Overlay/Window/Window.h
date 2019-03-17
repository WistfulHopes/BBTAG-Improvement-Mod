#pragma once
#include <imgui.h>

#include <string>

class Window
{
public:
	Window(const std::string& windowTitle, bool windowClosable, ImGuiWindowFlags windowFlags = 0)
		: m_windowTitle(windowTitle),
		m_windowClosable(windowClosable),
		m_windowFlags(windowFlags) {}

	virtual ~Window() = default;
	virtual void Update();
	void Open();
	void Close();
	void ToggleOpen();
	bool IsOpen() const;
protected:
	virtual void BeforeDraw() {}
	virtual void Draw() = 0;
	virtual void AfterDraw() {}
private:
	bool* GetWindowOpenPointer();

protected:
	std::string       m_windowTitle;
	bool              m_windowClosable;
	ImGuiWindowFlags  m_windowFlags;
	bool              m_windowOpen = false;
};
