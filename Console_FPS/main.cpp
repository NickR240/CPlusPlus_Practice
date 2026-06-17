#include <iostream>	
#include <Windows.h>
#include <chrono>

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fDepth = 16.0f;

float fFOV = 3.14159 / 4.0;

int main() {

	//Screen Buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	std::wstring map;
	map += L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";

	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	while (1) {

		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();

		if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
			fPlayerA -= (0.8f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
			fPlayerA += (0.8f) * fElapsedTime;

		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {
			fPlayerX += sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * 5.0f * fElapsedTime;
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
			fPlayerX -= sinf(fPlayerA) * 5.0f * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * 5.0f * fElapsedTime;
		}


		for (int i = 0; i < nScreenWidth; i++) {

			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)i / (float)nScreenWidth) * fFOV;

			float fDistanceToWall = 0;
			bool bHitWall = false;

			float fEyeX = sinf(fRayAngle);
			float fEyeY = cosf(fRayAngle);

				while (!bHitWall && fDistanceToWall < fDepth) {
					fDistanceToWall += 0.1f;

					int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
					int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

					if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
						bHitWall = true;
						fDistanceToWall = fDepth;
					}
					else {
						if (map[nTestY * nMapWidth + nTestX] == '#') {
							bHitWall = true;
						}
					}
			}

				int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
				int nFloor = nScreenHeight - nCeiling;
				
				short nShade = ' ';

				if (fDistanceToWall <= fDepth / 4.0f)		nShade = 0x2588; // Very close
				else if (fDistanceToWall < fDepth / 3.0f)	nShade = 0x2593;
				else if (fDistanceToWall < fDepth / 2.0f)	nShade = 0x2592;
				else if (fDistanceToWall < fDepth)			nShade = 0x2591;
				else										nShade = ' '; // Too far away

				for (int j = 0; j < nScreenHeight; j++) {

					if (j < nCeiling) 
						screen[j * nScreenWidth + i] = ' ';
					else if (j > nCeiling && j <= nFloor)
						screen[j * nScreenWidth + i] = nShade;
					else
						screen[j * nScreenWidth + i] = ' ';

				}

		}

		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}

		return 0;
}
