#ifndef ENGINNIT_MESSAGEBUS
#define ENGINNIT_MESSAGEBUS

#include <string>
#include <vector>
#include <functional>

using namespace std;

class MessageBus {
public:
	static void SendMessage(string message);
	static void AddListener(function<void(string)> callback);
private:
	static vector<function<void(string)>> listeners;
};

#endif