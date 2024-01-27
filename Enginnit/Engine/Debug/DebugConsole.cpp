#include "DebugConsole.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include "DebugCodes.h"

char DebugConsole::inputBuffer[2048] = "";
vector<DebugConsole::ConsoleLine> DebugConsole::output = {};

DebugConsole::DebugConsole() : UIElement() {
	enabled = false;
}

void DebugConsole::Tick(double deltaTime) {
	if (Keyboard::GetKey(GLFW_KEY_LEFT_SHIFT) && Keyboard::GetKeyDown(GLFW_KEY_TAB))
		enabled = !enabled;
}

vector<string> GetLineSplitted(string line, char value) {
	stringstream test(line);
	string segment = "";
	vector<string> seglist = {};

	while (getline(test, segment, value))
	{
		seglist.push_back(segment);
	}

	return seglist;
}

void DebugConsole::RenderInternal() {
	if (ImGui::Begin("Debug Console", nullptr, ImGuiWindowFlags_NoCollapse)) {

		ImGui::BeginChild("##scrolling", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
		for (auto line : output) RenderOutputLine(line);
		ImGui::EndChild();

		ImGui::PushItemWidth(-1);
		bool commandEntered = ImGui::InputText("##label", inputBuffer, IM_ARRAYSIZE(inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue);
		ImGui::PopItemWidth();
		if (commandEntered) {
			ProcessConsoleCommand(inputBuffer);
			ClearConsoleInput();

			ImGui::BeginChild("##scrolling");
			ImGui::SetScrollHereY(1.0);
			ImGui::EndChild();
		}
	}
	ImGui::End();

	UIElement::RenderInternal();
}

void DebugConsole::ProcessConsoleCommand(string value) {
	try {
		vector<string> command = GetLineSplitted(value, ' ');
		if (command.size() == 0 || command.size() == 1) {
			LogWarning("Couldn't parse command: " + value);
			return;
		}
		string code = command[0];
		string valueSt = command[1];
		string valueType = "int";
		if (command.size() > 2)
			valueType = command[2];

		if (valueType == "int")
			DebugCodes::SetInt(code, stoi(valueSt));
		else if (valueType == "string")
			DebugCodes::SetString(code, valueSt);
		else if (valueType == "float")
			DebugCodes::SetFloat(code, stof(valueSt));
		else if (valueType == "bool")
			DebugCodes::SetBool(code, (valueSt == "true"));
		else if (valueType == "double")
			DebugCodes::SetDouble(code, stod(valueSt));

		Log("Setting \"" + code + "\" to " + valueSt);
	}
	catch(...) {
		LogError("Exception trying to parse command: " + value);
	}
}

void DebugConsole::RenderOutputLine(DebugConsole::ConsoleLine line) {
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 255, 255));
	ImGui::Text(line.TimeFormatted());
	ImGui::PopStyleColor();

	ImGui::SameLine();

	ImGui::PushStyleColor(ImGuiCol_Text, line.color);
	ImGui::Text((char*)line.message.c_str());
	ImGui::PopStyleColor();
}

void DebugConsole::ClearConsoleInput() {
	strncpy_s(inputBuffer, "", IM_ARRAYSIZE(inputBuffer));
}

void DebugConsole::Log(string message) {
	unsigned int color = IM_COL32(255, 255, 255, 255);
	output.push_back(ConsoleLine(message, color));
	cout << message << endl;
}

void DebugConsole::LogError(string message) {
	unsigned int color = IM_COL32(255, 50, 50, 255);
	output.push_back(ConsoleLine(message, color));
	cout << message << endl;
}

void DebugConsole::LogWarning(string message) {
	unsigned int color = IM_COL32(255, 255, 10, 255);
	output.push_back(ConsoleLine(message, color));
	cout << message << endl;
}