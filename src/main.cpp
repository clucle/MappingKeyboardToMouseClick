
#include <iostream>
#include <windows.h>

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

int main() {
	
	printHelp();

	while( true )
	{
		// Get Input
		int op = input();
		if ( !op ) continue;
		system( "CLS" );
		printHelp();

		if ( op == 1 ) {
			POINT cursor;
			GetCursorPos( &cursor );
			std::cout << " Current Cursor Position \n";
			std::cout << "  - x : " << cursor.x << " y : " << cursor.y << '\n';
		}
	}
}
