#include <Windows.h>
#include "other.h"
#include <thread>
#include <iostream>
#include <thread>
#include "keyauth.hpp"
#include <filesystem>
#include <fstream>
#include "Discord RPC/dsc.h"
#include "enc.h"

using namespace KeyAuth;

std::string name = (std::string)E("Paste Here"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = (std::string)E("Paste Here"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = (std::string)E("Paste Here"); // app secret, the blurred text on licenses tab and other tabs
std::string version = (std::string)E("1.0"); // leave alone unless you've changed version on website
std::string url = (std::string)E("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

Discord* g_Discord;

int main()
{
	std::thread(check).detach();
	std::thread(mempatch);
	if (CheckVTBlacklist(pcusername(), (std::string)E("https://raw.githubusercontent.com/6nz/virustotal-vm-blacklist/main/pc_name_list.txt")))
	{
		abort();
	}

	if (CheckVTBlacklist(pcusername(), (std::string)E("https://raw.githubusercontent.com/6nz/virustotal-vm-blacklist/main/pc_username_list.txt")))
	{
		abort();
	}

	g_Discord->Initialize();
	g_Discord->Update();

	// Hide the console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	LI_FN(GetConsoleCursorInfo)(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	LI_FN(SetConsoleCursorInfo)(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;

	std::thread(changetitle).detach();
	LI_FN(system)(E("color 1"));
	HWND hwnd = LI_FN(GetConsoleWindow)();
	HWND console = LI_FN(GetConsoleWindow)();
	RECT ConsoleRect;
	LI_FN(GetWindowRect)(console, &ConsoleRect);

	HANDLE hOut = LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	LI_FN(GetConsoleScreenBufferInfo)(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	// Set the window transparency
	LI_FN(SetWindowLongA)(hwnd, GWL_EXSTYLE, LI_FN(GetWindowLongA)(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	LI_FN(SetLayeredWindowAttributes)(hwnd, 0, 200, LWA_ALPHA);

	HWND consoleWindow = LI_FN(GetConsoleWindow)();
	LI_FN(SetWindowLongA)(consoleWindow, GWL_STYLE, LI_FN(GetWindowLongA)(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MINIMIZEBOX);

	int Status = LI_FN(SetConsoleScreenBufferSize)(hOut, newSize);

	LI_FN(SetWindowPos)(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

	LI_FN(SetWindowLongA)(hwnd, GWL_STYLE,
		LI_FN(GetWindowLongA)(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

a:

	std::string autologinkey = ReadFromFile((std::string)E("C:\\Windows\\krpermspooferlogin.txt"));

	std::string key;

	KeyAuthApp.init();

	if (std::filesystem::exists((std::string)E("C:\\Windows\\krpermspooferlogin.txt")))
	{
		KeyAuthApp.license(autologinkey);
		if (!KeyAuthApp.data.success)
		{
			LI_FN(system)(E("cls"));
			text((std::string)E("Error Logging Into Saved Key."));
			std::remove(E("C:\\Windows\\krpermspooferlogin.txt"));
			text((std::string)E("Deleted Saved Key."));
			text((std::string)E("Returning To Main."));
			goto a;
		}
	}

	if (!std::filesystem::exists((std::string)E("C:\\Windows\\krpermspooferlogin.txt")))
	{
		text((std::string)E("Key: "));
		std::cin >> key;
		KeyAuthApp.license(key);
		if (!KeyAuthApp.data.success)
		{
			text((std::string)E("Invalid Key Please Try Again!"));
			LI_FN(Sleep)(1500);
			key.clear();
			LI_FN(exit)(0);
		}
		if (KeyAuthApp.data.success)
		{
			ofstream myfile;
			myfile.open(E("C:\\Windows\\krpermspooferlogin.txt"));
			myfile << key;
			myfile.close();
		}
	}

	int eg;

	printf(E("\n\n\n"));
	printf(E("  [1] Temp Spoof Fortnite\n"));
	printf(E("  [2] Temp Spoof Valorant\n"));
	printf(E("  [3] Perm Spoof Valorant\n"));
	printf(E("  [4] Perm Spoof Fortnite\n"));

	printf(E("\n  -> "));

	// Hide the console cursor
	LI_FN(GetConsoleCursorInfo)(LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = true;
	LI_FN(GetConsoleCursorInfo)(LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE), &cursorInfo);

	std::cin >> eg;

	// Hide the console cursor

	LI_FN(GetConsoleCursorInfo)(LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	LI_FN(GetConsoleCursorInfo)(LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE), &cursorInfo);

	switch (eg)
	{
	case 1:
		g_Discord->UpdateSpoofing();
		tempspooffn();
		g_Discord->Update();
		break;

	case 2:
		g_Discord->UpdateSpoofing();
		tempspoofval();
		g_Discord->Update();
		break;

	case 3:
		g_Discord->UpdateSpoofing();
		permspoof();
		g_Discord->Update();
		break;

	case 4:
		g_Discord->UpdateSpoofing();
		permspoof();
		g_Discord->Update();
		break;

	default:
		text((std::string)E("Invalid Option!!"));
		LI_FN(Sleep)(1500);
		LI_FN(exit)(0);
	}
}
