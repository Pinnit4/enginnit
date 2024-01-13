#ifndef ENGINNIT_DEBUG_CONSOLE
#define ENGINNIT_DEBUG_CONSOLE

#include "../Math/Math.h"
#include "../Graphics/UI/UI.h"
#include "../IO/Input.h"

#include <iostream>
#include <map>

#include "time.h"

using namespace std;

class DebugConsole : public UIElement {
public:
	DebugConsole();

	void Tick(double deltaTime);
	void Render() override;

	static void Log(string message);
	static void LogWarning(string message);
	static void LogError(string message);
private:
	struct ConsoleLine {
		string message;
		unsigned int color;
		time_t ltime;

		ConsoleLine(string _message, unsigned int _color) {
			message = _message;
			color = _color;
			time(&ltime);
		};

		char* TimeFormatted() {
			return ctime(&ltime);
		}
	};

	bool visible;

	static vector<ConsoleLine> output;

	static char inputBuffer[2048];

	static void ProcessConsoleCommand(string value);
	static void ClearConsoleInput();

	void RenderOutputLine(ConsoleLine line);
};
#endif