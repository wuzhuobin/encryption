//---------------------------------------------------------------------------

#include <vcl.h>

#include "ViKey.h"     
#include <stdio.h>

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        long dwRetCode;
	unsigned short Index;
	long dwCount;
	long dwHID;
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


        for(int i=0; i<9; i++)
	{
		szSoftID[i] = 0;
	}
	dwRetCode = VikeyGetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("�������IDʧ��!\n");
	}
	else
	{
		printf("�������ID�ɹ���%s!\n", szSoftID);
	}

		unsigned short  p1;
		unsigned short  p2;
		unsigned short  p3;
		unsigned short  p4;

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
	
	unsigned short wAddr = 0;
	unsigned short wLen = 32;
	unsigned char buffer[1024];
	for(int i=0; i<wLen; i++)
	{
		buffer[i] = (unsigned char)i;
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
        system("pause");
	return 0;
}
//---------------------------------------------------------------------------
 