
#include <iostream>
#include <windows.h>

void setWindowSize() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect( console, &r ); //stores the console's current dimensions

	const int width = 600;
	const int height = 400;
	MoveWindow( console, r.left, r.top, width, height, TRUE ); // 800 width, 100 heigh
}

void printHelp() {
	std::cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	std::cout << "弛    MappingKeyboardToMouseClick    弛\n";
	std::cout << "弛 1. Print Cursor Position          弛\n";
	std::cout << "弛 2. Mapping Keyboard To Mouseclick 弛\n";
	std::cout << "弛 3. Show Mapping List              弛\n";
	std::cout << "弛 4. Run                            弛\n";
	std::cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
}

int input() {
	int ret = 0;
	std::cout << " select ( 1 ~ 4 ) : "; std::cin >> ret;
	if ( ret < 1 || ret > 4 ) {
		std::cout << " You should select 1 ~ 4\n";
		return 0;
	}
	return ret;
}

void printCursorPosition() {
	POINT cursor;
	GetCursorPos( &cursor );
	std::cout << " Current Cursor Position \n";
	std::cout << "  - x : " << cursor.x << " y : " << cursor.y << '\n';
}

int main() {
	
	setWindowSize();
	printHelp();

	while( true )
	{
		// Get Input
		int op = input();
		if ( !op ) continue;

		// Refresh Screen
		system( "CLS" );
		printHelp();

		// Do Operation
		if ( op == 1 ) {
			printCursorPosition();
		}
	}
}
