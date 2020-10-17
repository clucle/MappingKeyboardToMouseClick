
#include <iostream>
#include <windows.h>

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
