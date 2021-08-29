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
  |  last modified:  29.08.2021 se                                      |
  |                                                                     |
  |---------------------------------------------------------------------|*/

#include "StdAfx.h"


int APIENTRY wWinMain ( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow )
{

    DWORD   dwReturnValue = 0;
    BOOL    ok;

    //SendMessageW ( HWND_BROADCAST, WM_SETTINGCHANGE, 0, ( LPARAM ) L"Environment" );

    ok
        =
            SendMessageTimeoutW
            (
                HWND_BROADCAST,
                WM_SETTINGCHANGE,
                0,
                ( LPARAM ) L"Environment",
                SMTO_ABORTIFHUNG,
                6000,
                ( PDWORD_PTR ) & dwReturnValue
            )
            !=
            0
    ;
    
    return !ok;

}
