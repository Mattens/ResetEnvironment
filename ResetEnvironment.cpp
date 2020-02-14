/*|---------------------------------------------------------------------|
  |                                                                     |
  |  ResetEnvironment.cpp   © DVSeck http://emesco.de                   |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |                                                                     |
  |---------------------------------------------------------------------|
  |                                                                     |
  |  created:        09.12.2015 se                                      |
  |  last modified:  13.07.2019 se                                      |
  |                                                                     |
  |---------------------------------------------------------------------|*/

#include "StdAfx.h"


int APIENTRY wWinMain ( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow )
{

    DWORD   dwReturnValue;
    BOOL    ok;

    //SendMessageW ( HWND_BROADCAST, WM_SETTINGCHANGE, 0, ( LPARAM ) L"Environment" );

    ok =
        SendMessageTimeoutW
        (
            HWND_BROADCAST,
            WM_SETTINGCHANGE,
            0,
            ( LPARAM ) L"Environment",
            SMTO_ABORTIFHUNG,
            5000,
            ( PDWORD_PTR ) & dwReturnValue
        );
    
    return 0;

}
