#include <stdio.h>
#include <stdlib.h>

#include  <windows.h>
   LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
       #define ID_MYBUTTON_1 1
       #define ID_MYBUTTON_2 2
       #define ID_MYBUTTON_3 3
       #define ID_MYBUTTON_4 4

       int WINAPI WinMain(HINSTANCE hInst,  HINSTANCE qwe,LPSTR qwer, int ss)
       {
            WNDCLASS wc;
            wc.style=0;
            wc.lpfnWndProc=MainWinProc;
            wc.cbClsExtra=0;
            wc.cbWndExtra=0;
            wc.hInstance=hInst;
            wc.hIcon=NULL;
            wc.hCursor=NULL;
            wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
            wc.lpszMenuName=NULL;
            wc.lpszClassName="window";

            if (!RegisterClass(&wc)) return FALSE;

            HWND hMainWnd=CreateWindow("window",
             "GAME 2048",
             WS_OVERLAPPEDWINDOW,
             CW_USEDEFAULT,
             CW_USEDEFAULT,
             850,
             500,
             NULL,
             NULL,
             hInst,
             NULL
             );

            if (!hMainWnd) return FALSE;
            ShowWindow(hMainWnd,ss);
            UpdateWindow(hMainWnd);

            MSG msg;
            while (GetMessage(&msg,NULL,0,0))
            {
                 TranslateMessage(&msg);
                 DispatchMessage(&msg);
            }
            return msg.wParam;
       }


       LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
            switch (msg)
            {
                 case WM_CREATE:
                      CreateWindow("button","НАЧАТЬ ИГРУ",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
                       250,50,350,60,hw,(HMENU)ID_MYBUTTON_1,NULL,NULL);
                      CreateWindow("button","РЕКОРДЫ",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
                       250,150,350,60,hw,(HMENU)ID_MYBUTTON_2,NULL,NULL);
                      CreateWindow("button","НАСТРОЙКИ",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
                       250,250,350,60,hw,(HMENU)ID_MYBUTTON_3,NULL,NULL);
                      CreateWindow("button","ВЫЙТИ",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
                       250,350,350,60,hw,(HMENU)ID_MYBUTTON_4,NULL,NULL);
                      return 0;
                 case WM_COMMAND:
                      if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON_1))
                       MessageBox(hw,"Когда-нибудь поиграем!","GAME 2048",MB_OK|MB_ICONWARNING);
                      if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON_2))
                       MessageBox(hw,"Здесь могли быть ваши рекорды!","GAME 2048",MB_OK|MB_ICONWARNING);
                      if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON_3))
                       MessageBox(hw,"Вы успешно нажали на кнопку настройки!","GAME 2048",MB_OK|MB_ICONWARNING);
                      if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON_4))
                       {MessageBox(hw,"Выход","GAME 2048",MB_OK|MB_ICONWARNING);
                       PostQuitMessage(0);
                       return 0;
                       }
                      return 0;
                 case WM_DESTROY:
                      PostQuitMessage(0);
                      return 0;
            }
            return DefWindowProc(hw,msg,wp,lp);
       }
