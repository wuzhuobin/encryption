// ViKeySample.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#include "ViKey.h"

#pragma comment (lib, "Vikey.x86.MT.VC6.lib")

int main(int argc, char* argv[])
{
	DWORD dwRetCode;
	WORD Index;
	DWORD dwCount;
	DWORD dwHID;
	dwRetCode = VikeyFind(&dwCount);
	if(dwRetCode)
	{
		printf("没有发现Vikey!\n");
	}

	char UserPassWord[] = "11111111";
	char AdminPassWord[] = "00000000";
	Index = 0;

	dwRetCode = VikeyGetHID(Index, &dwHID);
	if(dwRetCode)
	{
		printf("VikeyGetHID 失败!\n");
	}
	printf("VikeyGetHID:%u\n", dwHID);

	dwRetCode = VikeyUserLogin(Index , UserPassWord);
	if(dwRetCode)
	{
		printf("用户权限登录失败!\n");
	}

	dwRetCode = VikeyAdminLogin(Index , AdminPassWord);
	if(dwRetCode)
	{
		printf("管理员权限登录失败!\n");
	}

	char szSoftID[9] = {"12345678"};
	dwRetCode = VikeySetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("设置软件ID失败!\n");
	}
	else
	{
		printf("设置软件ID成功：%s!\n", szSoftID);
	}

	memset(szSoftID, 0, 9);
	dwRetCode = VikeyGetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("设置软件ID失败!\n");
	}
	else
	{
		printf("设置软件ID成功：%s!\n", szSoftID);
	}

	WORD p1;
	WORD p2;
	WORD p3;
	WORD p4;

	dwRetCode = ViKeyRandom(Index, &p1, &p2, &p3, &p4);
	if(dwRetCode)
	{
		printf("获取硬件随机数失败!\n");
	}
	else
	{
		printf("获取硬件随机数：1、%08X 2、%08X 3、%08X 4、%08X!\n",
			p1, p2, p3, p4);
	}
	
	WORD wAddr = 0;
	WORD wLen = 32;
	BYTE buffer[1024];
	for(int i=0; i<wLen; i++)
	{
		buffer[i] = (BYTE)i;
	}

	dwRetCode = VikeyWriteData(Index, wAddr, wLen, buffer);
	if(dwRetCode)
	{
		printf("写ViKey数据失败!\n");
	}

	dwRetCode = VikeyReadData(Index, wAddr, wLen, buffer);
	if(dwRetCode)
	{
		printf("读ViKey数据失败!\n");
	}
	else
	{
		printf("读ViKey数据成功!\n");
		for(int i=0; i<wLen; i++)
		{
			printf("%02x ", buffer[i]);
			if((i+1)%16 == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	VikeyLogoff(Index);
	return 0;
}

