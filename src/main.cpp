
#include <iostream>
#include <map>
#include <windows.h>

typedef std::pair<int, int> PairXY;

void setWindowSize()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect( console, &r ); //stores the console's current dimensions

	const int width = 600;
	const int height = 400;
	MoveWindow( console, r.left, r.top, width, height, TRUE ); // 800 width, 100 heigh
}

void printHelp()
{
	std::cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n";
	std::cout << "弛    MappingKeyboardToMouseClick    弛\n";
	std::cout << "弛 1. Print Cursor Position          弛\n";
	std::cout << "弛 2. Mapping Keyboard To Mouseclick 弛\n";
	std::cout << "弛 3. Show Mapping List              弛\n";
	std::cout << "弛 4. Run                            弛\n";
	std::cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n";
}

int input()
{
	int ret = 0;
	std::cout << " select ( 1 ~ 4 ) : "; std::cin >> ret;
	if ( std::cin.fail() )
	{
		std::cin.clear();
		std::cin.ignore( 10, '\n' );
		std::cout << " You should select 1 ~ 4\n";
		return 0;
	}

	if ( ret < 1 || ret > 4 )
	{
		std::cout << " You should select 1 ~ 4\n";
		return 0;
	}
	return ret;
}

PairXY printCursorPosition()
{
	POINT cursor;
	GetCursorPos( &cursor );
	std::cout << " Current Cursor Position \n";
	std::cout << "  - x : " << cursor.x << " y : " << cursor.y << '\n';
	return { cursor.x, cursor.y };
}

void printCursorPosition( int& last_x, int& last_y )
{
	PairXY pxy = printCursorPosition();
	last_x = pxy.first;
	last_y = pxy.second;
}

void mapKeyboardToMouseclick(
	int& last_x, int& last_y,
	std::map< char, PairXY >& mapKeyboardToMousePosition )
{

	std::cout << " Last Printed Cursor Position \n";
	std::cout << "  - x : " << last_x << " y : " << last_y << '\n';

	char key;
	int x, y;
	std::cout << " Input key (ex : a or A) : ";  std::cin >> key;

	printCursorPosition();

	std::cout << " Input X Position ";      std::cin >> x;
	std::cout << " Input Y Position ";      std::cin >> y;
	key = toupper( key );
	mapKeyboardToMousePosition[ key ] = { x, y };

	std::cout << " Success!\n";
}

void printMapKeyboardToMouseclick( std::map< char, PairXY >& mapKeyboardToMousePosition )
{
	for ( auto& e : mapKeyboardToMousePosition )
	{
		std::cout << "Key : " << e.first <<
			" >> Position { x : " << e.second.first << ", y : " << e.second.second << " }\n";
	}
}

void run( std::map< char, PairXY >& mapKeyboardToMousePosition )
{

	if ( mapKeyboardToMousePosition.size() == 0 )
	{
		std::cout << " No mapping information\n";
		return;
	}

	std::map< char, int > pressOnceFlag;
	for ( auto& e : mapKeyboardToMousePosition )
	{
		pressOnceFlag[ e.first ] = 0;
	}

	std::cout << " If you want to stop, press F10\n";
	while ( true )
	{
		if ( GetKeyState( VK_F10 ) < 0 )
		{
			// stop
			break;
		}
		for ( auto& e : mapKeyboardToMousePosition )
		{
			int key = e.first;
			int keyLower = tolower( key );
			int x = e.second.first;
			int y = e.second.second;

			if (
				( GetKeyState( key ) & 0x8000 ) ||
				( GetKeyState( keyLower ) & 0x8000 ) )
			{

				if ( pressOnceFlag[ key ] == 0 )
				{
					pressOnceFlag[ key ] = 1;
				}
				else
				{
					break;
				}
				SetCursorPos( x, y );
				mouse_event( MOUSEEVENTF_LEFTDOWN, x, y, 0, 0 );
				Sleep( 1 );
				mouse_event( MOUSEEVENTF_LEFTUP, x, y, 0, 0 );
				Sleep( 1 );
			}
			else
			{
				pressOnceFlag[ key ] = 0;
			}
		}
		Sleep( 10 );
	}
}

int main()
{

	setWindowSize();
	printHelp();

	int last_x = 0;
	int last_y = 0;

	std::map< char, PairXY > mapKeyboardToMousePosition;

	while ( true )
	{
		// Get Input
		fflush( stdin );
		std::cin.clear();
		int op = input();
		if ( !op ) continue;

		// Refresh Screen
		system( "CLS" );
		printHelp();

		// Do Operation
		switch ( op )
		{
		case 1:
			printCursorPosition( last_x, last_y );
			break;
		case 2:
			mapKeyboardToMouseclick( last_x, last_y, mapKeyboardToMousePosition );
			break;
		case 3:
			printMapKeyboardToMouseclick( mapKeyboardToMousePosition );
			break;
		case 4:
			run( mapKeyboardToMousePosition );
			break;
		}
	}
}
