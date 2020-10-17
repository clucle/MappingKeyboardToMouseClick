
#include <iostream>
#include <map>
#include <windows.h>

typedef std::pair<int, int> PairXY;

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

PairXY printCursorPosition() {
	POINT cursor;
	GetCursorPos( &cursor );
	std::cout << " Current Cursor Position \n";
	std::cout << "  - x : " << cursor.x << " y : " << cursor.y << '\n';
	return { cursor.x, cursor.y };
}

void printCursorPosition( int& last_x, int& last_y ) {
	PairXY pxy = printCursorPosition();
	last_x = pxy.first;
	last_y = pxy.second;
}

void mapKeyboardToMouseclick(
	int& last_x, int& last_y,
	std::map< char, PairXY >& mapKeyboardToMousePosition ) {

	std::cout << " Last Printed Cursor Position \n";
	std::cout << "  - x : " << last_x << " y : " << last_y << '\n';
	
	printCursorPosition();

	char key;
	int x, y;
	std::cout << " Input key (ex : a) : ";  std::cin >> key;
	std::cout << " Input X Position ";      std::cin >> x;
	std::cout << " Input Y Position ";      std::cin >> y;
	mapKeyboardToMousePosition[key] = { x, y };
	
	std::cout << " Success!\n";
}

void printMapKeyboardToMouseclick( std::map< char, PairXY >& mapKeyboardToMousePosition ) {
	for ( auto& e : mapKeyboardToMousePosition )
	{
		std::cout << "Key : " << e.first <<
			" >> Position { x : " << e.second.first << ", y : " << e.second.second << " }\n";
	}
}

int main() {
	
	setWindowSize();
	printHelp();

	int last_x = 0;
	int last_y = 0;
	
	std::map< char, PairXY > mapKeyboardToMousePosition;

	while( true )
	{
		// Get Input
		int op = input();
		if ( !op ) continue;

		// Refresh Screen
		system( "CLS" );
		printHelp();

		// Do Operation
		switch ( op ) {
		case 1:
			printCursorPosition( last_x, last_y );
			break;
		case 2:
			mapKeyboardToMouseclick( last_x, last_y, mapKeyboardToMousePosition );
			break;
		case 3:
			printMapKeyboardToMouseclick( mapKeyboardToMousePosition );
			break;
		}
	}
}
