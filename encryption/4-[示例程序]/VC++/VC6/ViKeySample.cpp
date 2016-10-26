// ViKeySample.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("û�з���Vikey!\n");
	}

	char UserPassWord[] = "11111111";
	char AdminPassWord[] = "00000000";
	Index = 0;

	dwRetCode = VikeyGetHID(Index, &dwHID);
	if(dwRetCode)
	{
		printf("VikeyGetHID ʧ��!\n");
	}
	printf("VikeyGetHID:%u\n", dwHID);

	dwRetCode = VikeyUserLogin(Index , UserPassWord);
	if(dwRetCode)
	{
		printf("�û�Ȩ�޵�¼ʧ��!\n");
	}

	dwRetCode = VikeyAdminLogin(Index , AdminPassWord);
	if(dwRetCode)
	{
		printf("����ԱȨ�޵�¼ʧ��!\n");
	}

	char szSoftID[9] = {"12345678"};
	dwRetCode = VikeySetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("�������IDʧ��!\n");
	}
	else
	{
		printf("�������ID�ɹ���%s!\n", szSoftID);
	}

	memset(szSoftID, 0, 9);
	dwRetCode = VikeyGetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("�������IDʧ��!\n");
	}
	else
	{
		printf("�������ID�ɹ���%s!\n", szSoftID);
	}

	WORD p1;
	WORD p2;
	WORD p3;
	WORD p4;

	dwRetCode = ViKeyRandom(Index, &p1, &p2, &p3, &p4);
	if(dwRetCode)
	{
		printf("��ȡӲ�������ʧ��!\n");
	}
	else
	{
		printf("��ȡӲ���������1��%08X 2��%08X 3��%08X 4��%08X!\n",
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
		printf("дViKey����ʧ��!\n");
	}

	dwRetCode = VikeyReadData(Index, wAddr, wLen, buffer);
	if(dwRetCode)
	{
		printf("��ViKey����ʧ��!\n");
	}
	else
	{
		printf("��ViKey���ݳɹ�!\n");
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

