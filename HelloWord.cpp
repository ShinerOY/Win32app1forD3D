//.................................................
//File:HelloWord.cpp
//.................................................
#include<windows.h>                                //应用程序头文件
wchar_t*g_pClassName=L"HelloWord";                  //窗口类名
wchar_t*g_pWindowName=L"我的窗口";                 //窗口标题名



//窗口消息处理函数声明
LRESULT		CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//...................................................
//Name:WinMain();
//Desc:Windows应用程序入口函数
//...................................................
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR IpCmdLine,int nShowCmd)
{
  /*初始化窗口类*/
	WNDCLASS wndclass;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);      //窗口背景
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);                     //光标形状
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);                  //窗口小图标
	wndclass.hInstance=hInstance;
	wndclass.lpfnWndProc=WndProc;                                  //消息处理函数
	wndclass.lpszClassName=g_pClassName;                           //窗口类名
	wndclass.lpszMenuName=NULL;
	wndclass.style=CS_HREDRAW|CS_VREDRAW;                          //窗口样式
	/*注册窗口类*/
	if(!RegisterClass(&wndclass))
		return 0;
	/*初始化窗口类，注册窗口类*/
	/*创建窗口*/
	HWND hWnd=CreateWindow(
		g_pClassName,                            //窗口类名
		g_pWindowName,                          //窗口标题
		WS_OVERLAPPEDWINDOW,                    //窗口样式
		CW_USEDEFAULT,                         //窗口最初的X位置
		CW_USEDEFAULT,                         //窗口最初的y位置
		CW_USEDEFAULT,                        //窗口的宽度
		CW_USEDEFAULT,                        //窗口的高度
		NULL,                                  //父窗口句柄
		NULL,                                //窗口菜单句柄
		hInstance,                           //应用程序实例句柄
		NULL                                //创建窗口的参数
		);
	/*显示窗口，更新窗口*/
	ShowWindow(hWnd,nShowCmd);
	UpdateWindow(hWnd);
	
	/*初始化窗口类，注册窗口类*/
	/*创建，显示并更新窗口*/
	/*消息循环*/
	MSG msg;
	//WNDCLASS wndclass;
	while(GetMessage(&msg,NULL,0,0))    //取得消息
	{
	 TranslateMessage(&msg);           //转换消息
	 DispatchMessage(&msg);           //投递消息
	}
	UnregisterClass(L"HelloMsg",wndclass.hInstance);
	return 0;

}

//...........................................................
//Name:WndProc()
//Desc:窗口消息处理函数
//..........................................................
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:                                //鼠标左键按下消息
		 MessageBox(NULL,L"欢迎走进Direct3D",L"问候",0);
		 
	 case WM_DESTROY:                                   //窗口销毁消息
		 PostQuitMessage(0);                          //退出程序
		 break;
	}
	//默认的消息处理
	return DefWindowProc(hWnd,message,wParam,lParam);
}
