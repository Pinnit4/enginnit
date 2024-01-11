#include "MessageBus.h"

vector<function<void(string)>> MessageBus::listeners = vector<function<void(string)>>();

void MessageBus::SendMessage(string message) {
	for(auto cb : listeners)
		cb(message);
}

void MessageBus::AddListener(function<void(string)> callback) {
	listeners.push_back(callback);
}