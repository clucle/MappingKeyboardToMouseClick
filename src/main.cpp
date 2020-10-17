
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
	std::cout << "��������������������������������������������������������������������������\n";
	std::cout << "��    MappingKeyboardToMouseClick    ��\n";
	std::cout << "�� 1. Print Cursor Position          ��\n";
	std::cout << "�� 2. Mapping Keyboard To Mouseclick ��\n";
	std::cout << "�� 3. Show Mapping List              ��\n";
	std::cout << "�� 4. Run                            ��\n";
	std::cout << "��������������������������������������������������������������������������\n";
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
