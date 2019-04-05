// To Save Power On Arduino http://www.gammon.com.au/power

#include <chrono>
#include <iostream>

const int TICKS_PER_SECOND = 10;


__int64 getmillis() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void loop() {
	std::cout << "xD" << std::endl;
}

int main() {
	__int64 last_update = 0;

	while (1) {
		__int64 cur_millis = getmillis();

		// Use a timer here with callback instead of a busy poll to save energy and set energy consumption mode.
		if (cur_millis > last_update + (1000 / TICKS_PER_SECOND)) {
			last_update = cur_millis;

			loop();
		}
	}

	return 0;
}