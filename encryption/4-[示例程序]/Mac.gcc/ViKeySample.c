// ViKeySample.c
//

typedef 	unsigned short WORD;
typedef 	unsigned short USHORT;
typedef 	unsigned int   DWORD;
typedef   	unsigned char  BYTE;
typedef   	int  		INT;
typedef   	unsigned int  UINT;
typedef 	unsigned short WCHAR;

typedef   	unsigned char *  LPSTR;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vikey.h"


int main()
{
	int i;
	DWORD dwRetCode;
	WORD Index;
	DWORD dwCount;
	DWORD dwHID;
	dwRetCode = VikeyFind(&dwCount);
	if(dwRetCode)
	{
		printf("No found Vikey in this system!\n");
	}

	char UserPassWord[] = "11111111";
	char AdminPassWord[] = "00000000";
	Index = 0;

	dwRetCode = VikeyGetHID(Index, &dwHID);
	if(dwRetCode)
	{
		printf("VikeyGetHID Error:%08x!\n", dwRetCode);
	}
	else
	{
		printf("VikeyGetHID:%u\n", dwHID);
	}

	dwRetCode = VikeyUserLogin(Index , UserPassWord);
	if(dwRetCode)
	{
		printf("VikeyUserLogin Error:%08x!\n", dwRetCode);
	}

	dwRetCode = VikeyAdminLogin(Index , AdminPassWord);
	if(dwRetCode)
	{
		printf("VikeyAdminLogin Error:%08x!\n", dwRetCode);
	}

	char szSoftID[9] = {"12345678"};
	dwRetCode = VikeySetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("VikeySetSoftIDString Error:%08x!\n", dwRetCode);
	}
	else
	{
		printf("Set SoftID String:%s to Vikey Success!\n", szSoftID);
	}

	memset(szSoftID, 0, 9);
	dwRetCode = VikeyGetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("VikeyGetSoftIDString Error:%08x!\n", dwRetCode);
	}
	else
	{
		printf("Get SoftID String:%s from Vikey Success!\n", szSoftID);
	}

	WORD p1;
	WORD p2;
	WORD p3;
	WORD p4;

	dwRetCode = ViKeyRandom(Index, &p1, &p2, &p3, &p4);
	if(dwRetCode)
	{
		printf("ViKeyRandom Error:%08x!\n", dwRetCode);
	}
	else
	{
		printf("Get 4 rand data from ViKey Success !1:%04X 2:%04X 3:%04X 4:%04X\n",
			p1, p2, p3, p4);
	}
	
	WORD wAddr = 0;
	WORD wLen = 32;
	BYTE buffer[1024];
	for(i=0; i<wLen; i++)
	{
		buffer[i] = (BYTE)i;
	}

	dwRetCode = VikeyWriteData(Index, wAddr, wLen, buffer);
	if(dwRetCode)
	{
		printf("VikeyWriteData Error:%08x!\n", dwRetCode);
	}

	dwRetCode = VikeyReadData(Index, wAddr, wLen, buffer);
	if(dwRetCode)
	{
		printf("VikeyReadData Error:%08x!\n", dwRetCode);
	}
	else
	{
		printf("Get data from ViKey success!\n");
		for(i=0; i<wLen; i++)
		{
			printf("%02x ", buffer[i]);
			if((i+1)%16 == 0)
			{
				printf("\n");
			}
		}
		printf("\n");
	}

	dwRetCode = VikeyLogoff(Index);
	if(dwRetCode)
	{
		printf("VikeyLogoff Error:%08x!\n", dwRetCode);
	}
	else
	{
		printf("Logoff ViKey success!\n");
	}

	return 0;
}

