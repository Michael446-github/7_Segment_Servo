#define INTERVAL 1000  // Delay before showing next symbol

#define SERVO_DOWN 0  // minimal 
#define SERVO_UP 90  // and maximal positions of servo motor

#define TEXT "Michaels Github is great"  // Any kinda text

unsigned short servo_pins[] = {2, 3, 4, 5, 6, 7, 8};

#include <Servo.h>
Servo motors[7];

// Here is a "Hash table" data structure
// Please follow the order, for each symbol to be displayed correctly. So hash_values[n] must be a number for hash_keys[n]

char hash_keys[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned short hash_values[] = {0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x74, 0x6, 0x1e, 0x76, 0x38, 0x15, 0x37, 0x5c, 0x73, 0x67, 0x50, 0x6d, 0x78, 0x1c, 0x3e, 0x2a, 0x76, 0x6e, 0x5b, 0x3d, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x7f, 0x6f};

uint16_t length_of_arrays = sizeof(hash_keys) / sizeof(hash_keys[0]);

String text = String(TEXT);

void setup()
{
	
	for (unsigned short i = 0; i < 7; ++i)
	{
		motors[i].attach(servo_pins[i]);
	}
	
	
	text.trim();
	text.toLowerCase();
	
	update('0');
	delay(2000
}

void loop()
{
	for (unsigned short i = 0; i < text.length(); ++i)
	{
		update(text[i]);
		delay(INTERVAL);

		// If there are repeating symbols like 'Running', uncomment this:
		// update('0');
		// delay(300);
	}

	// If you want to use BT or Serial port, then uncomment this, and comment the above code:
	//serial();
}


int bin_search(char arr[], int low, int high, char val) {  // binary search implementation

	if (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == val)
			return mid;
		else if (arr[mid] > val)
			return bin_search(arr, low, mid - 1, val);
		else if (arr[mid] < val)
			return bin_search(arr, mid + 1, high, val);
	}
	return -1;
}

void update(char val) {
	unsigned short index = bin_search(hash_keys, 0, n - 1, val);
	for (unsigned short i = 0; i < 7; i++) {
		
		unsigned short state = (bitRead(hash_values[index], i)) ? SERVO_UP : SERVO_DOWN;
		
		motors[i].write(state);
	}
}

void serial() {
	if (Serial.available())
	{
		char val = Serial.read();
		update(val);
	}
}
