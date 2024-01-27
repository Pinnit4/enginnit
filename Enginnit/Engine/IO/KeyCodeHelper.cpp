#include "KeyCode.h"

KeyCode KeyCodeHelper::FromGLFW(int key) {
	return static_cast<KeyCode>(key);
}

int KeyCodeHelper::ToGLFW(KeyCode key) {
	return static_cast<int>(key);
}