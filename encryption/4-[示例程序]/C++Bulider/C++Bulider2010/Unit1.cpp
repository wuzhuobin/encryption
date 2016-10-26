//---------------------------------------------------------------------------

#include <vcl.h>

#include <stdio.h>

#pragma hdrstop

typedef long __stdcall (*FunVikeyFind)(long* pdwCount);
typedef long __stdcall (*FunVikeyGetHID)(unsigned short Index, long *pdwHID);
typedef long __stdcall (*FunVikeyGetType)(unsigned short Index, unsigned char *pType);
typedef long __stdcall (*FunVikeyGetLevel)(unsigned short Index, unsigned char *pLevel);
typedef long __stdcall (*FunVikeySetPtroductName)(unsigned short Index, unsigned short szName[16]);
typedef long __stdcall (*FunVikeyGetPtroductName)(unsigned short Index, unsigned short szName[16]);

//登陆、注销加密狗
//加密狗密码长度8个字符 字母或数字
typedef long __stdcall (*FunVikeyUserLogin)(unsigned short Index, char * pUserPassWord);
typedef long __stdcall (*FunVikeyAdminLogin)(unsigned short Index, char * pAdminPassWord);
typedef long __stdcall (*FunVikeyLogoff)(unsigned short Index);

//设置密码尝试次数、修改密码
typedef long __stdcall (*FunVikeySetUserPassWordAttempt)(unsigned short Index, unsigned char cAttempt);
typedef long __stdcall (*FunVikeySetAdminPassWordAttempt)(unsigned short Index, unsigned char cAttempt);
typedef long __stdcall (*FunVikeyGetUserPassWordAttempt)(unsigned short Index, unsigned char *pcCurrentAttempt, unsigned char *pcMaxAttempt);
typedef long __stdcall (*FunVikeyGetAdminPassWordAttempt)(unsigned short Index, unsigned char *pcCurrentAttempt, unsigned char *pcMaxAttempt);
typedef long __stdcall (*FunVikeyResetPassword)(unsigned short Index, char * pNewUserPassWord,  char * pNewAdminPassWord);

//软件ID读写
//软件ID长度8个字符 字母或数字
typedef long __stdcall (*FunVikeySetSoftIDString)(unsigned short Index, char * pSoftIDString);
typedef long __stdcall (*FunVikeyGetSoftIDString)(unsigned short Index, char * pSoftIDString);

//读写数据
typedef long __stdcall (*FunVikeyReadData)(unsigned short Index, unsigned short Addr, unsigned short Length, unsigned char * buffer);
typedef long __stdcall (*FunVikeyWriteData)(unsigned short Index, unsigned short Addr, unsigned short Length, unsigned char * buffer);
typedef long __stdcall (*FunViKeyRandom)(unsigned short Index, unsigned short* pwRandom1, unsigned short* pwRandom2, unsigned short* pwRandom3, unsigned short* pwRandom4);

//计数器模块
typedef long __stdcall (*FunViKeyDecraseModule)(unsigned short Index, unsigned short wModuleIndex);
typedef long __stdcall (*FunViKeyGetModule)(unsigned short Index, unsigned short wModuleIndex, unsigned short* pwValue);
typedef long __stdcall (*FunViKeySetModule)(unsigned short Index, unsigned short wModuleIndex, unsigned short wValue, unsigned short wMode);
typedef long __stdcall (*FunViKeyCheckModule)(unsigned short Index, unsigned short wModuleIndex, unsigned short *IsZero, unsigned short* CanDecrase);

//加解密
typedef long __stdcall (*FunVikey3DesSetKey)(unsigned short Index, unsigned char * pMD5key);
typedef long __stdcall (*FunVikey3DesEncrypt)(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
typedef long __stdcall (*FunVikey3DesDecrypt)(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);

//For ViKeyNET、ViKeyPRO
typedef long __stdcall (*FunVikeySetMaxClientCount)(unsigned short Index, unsigned short dwCount);
typedef long __stdcall (*FunVikeyGetMaxClientCount)(unsigned short Index, unsigned short* pdwCount);

//For ViKeyWEB、ViKeyPRO
typedef long __stdcall (*FunVikeyMD5)(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
typedef long __stdcall (*FunVikeySetMD5Key)(unsigned short Index, unsigned char * pMD5key);
typedef long __stdcall (*FunVikeyHmacMD5)(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);

typedef long __stdcall (*FunVikeySHA1)(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
typedef long __stdcall (*FunVikeySetSHA1Key)(unsigned short Index, unsigned char * pSHA1key);
typedef long __stdcall (*FunVikeyHmacSHA1)(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);


FunVikeyFind VikeyFind;
FunVikeyGetHID VikeyGetHID;
FunVikeyGetType VikeyGetType;
FunVikeyGetLevel VikeyGetLevel;
FunVikeySetPtroductName VikeySetPtroductName;
FunVikeyGetPtroductName VikeyGetPtroductName;



FunVikeyUserLogin VikeyUserLogin;
FunVikeyAdminLogin VikeyAdminLogin;
FunVikeyLogoff VikeyLogoff;

FunVikeySetUserPassWordAttempt VikeySetUserPassWordAttempt;
FunVikeySetAdminPassWordAttempt VikeySetAdminPassWordAttempt;
FunVikeyGetUserPassWordAttempt VikeyGetUserPassWordAttempt;
FunVikeyGetAdminPassWordAttempt VikeyGetAdminPassWordAttempt;
FunVikeyResetPassword VikeyResetPassword;


FunVikeySetSoftIDString VikeySetSoftIDString;
FunVikeyGetSoftIDString VikeyGetSoftIDString;


FunVikeyReadData VikeyReadData;
FunVikeyWriteData VikeyWriteData;
FunViKeyRandom ViKeyRandom;


FunViKeyDecraseModule ViKeyDecraseModule;
FunViKeyGetModule ViKeyGetModule;
FunViKeySetModule ViKeySetModule;
FunViKeyCheckModule ViKeyCheckModule;


FunVikey3DesSetKey Vikey3DesSetKey;
FunVikey3DesEncrypt Vikey3DesEncrypt;
FunVikey3DesDecrypt Vikey3DesDecrypt;


FunVikeySetMaxClientCount VikeySetMaxClientCount;
FunVikeyGetMaxClientCount VikeyGetMaxClientCount;


FunVikeyMD5 VikeyMD5;
FunVikeySetMD5Key VikeySetMD5Key;
FunVikeyHmacMD5 VikeyHmacMD5;

FunVikeySHA1 VikeySHA1;
FunVikeySetSHA1Key VikeySetSHA1Key;
FunVikeyHmacSHA1 VikeyHmacSHA1;

//---------------------------------------------------------------------------

#pragma argsused


void InitializeViKeyFunction()
{
	HINSTANCE hInst;
	hInst=LoadLibrary("ViKey.dll");
	VikeyFind=(FunVikeyFind)GetProcAddress(hInst,"VikeyFind");

	VikeyGetHID=(FunVikeyGetHID)GetProcAddress(hInst,"VikeyGetHID");
	VikeyGetType=(FunVikeyGetType)GetProcAddress(hInst,"VikeyGetType");
	VikeyGetLevel=(FunVikeyGetLevel)GetProcAddress(hInst,"VikeyGetLevel");
	VikeySetPtroductName=(FunVikeySetPtroductName)GetProcAddress(hInst,"VikeySetPtroductName");
	VikeyGetPtroductName=(FunVikeyGetPtroductName)GetProcAddress(hInst,"VikeyGetPtroductName");

	VikeyUserLogin=(FunVikeyUserLogin)GetProcAddress(hInst,"VikeyUserLogin");
	VikeyAdminLogin=(FunVikeyAdminLogin)GetProcAddress(hInst,"VikeyAdminLogin");
	VikeyLogoff=(FunVikeyLogoff)GetProcAddress(hInst,"VikeyLogoff");

	VikeySetUserPassWordAttempt=(FunVikeySetUserPassWordAttempt)GetProcAddress(hInst,"VikeySetUserPassWordAttempt");
	VikeySetAdminPassWordAttempt=(FunVikeySetAdminPassWordAttempt)GetProcAddress(hInst,"VikeySetAdminPassWordAttempt");
	VikeyGetUserPassWordAttempt=(FunVikeyGetUserPassWordAttempt)GetProcAddress(hInst,"VikeyGetUserPassWordAttempt");
	VikeyGetAdminPassWordAttempt=(FunVikeyGetAdminPassWordAttempt)GetProcAddress(hInst,"VikeyGetAdminPassWordAttempt");
	VikeyResetPassword=(FunVikeyResetPassword)GetProcAddress(hInst,"VikeyResetPassword");


	VikeySetSoftIDString=(FunVikeySetSoftIDString)GetProcAddress(hInst,"VikeySetSoftIDString");
	VikeyGetSoftIDString=(FunVikeyGetSoftIDString)GetProcAddress(hInst,"VikeyGetSoftIDString");


	VikeyReadData=(FunVikeyReadData)GetProcAddress(hInst,"VikeyReadData");
	VikeyWriteData=(FunVikeyWriteData)GetProcAddress(hInst,"VikeyWriteData");
	ViKeyRandom=(FunViKeyRandom)GetProcAddress(hInst,"ViKeyRandom");


	ViKeyDecraseModule=(FunViKeyDecraseModule)GetProcAddress(hInst,"ViKeyDecraseModule");
	ViKeyGetModule=(FunViKeyGetModule)GetProcAddress(hInst,"ViKeyGetModule");
	ViKeySetModule=(FunViKeySetModule)GetProcAddress(hInst,"ViKeySetModule");
	ViKeyCheckModule=(FunViKeyCheckModule)GetProcAddress(hInst,"ViKeyCheckModule");


	Vikey3DesSetKey=(FunVikey3DesSetKey)GetProcAddress(hInst,"Vikey3DesSetKey");
	Vikey3DesEncrypt=(FunVikey3DesEncrypt)GetProcAddress(hInst,"Vikey3DesEncrypt");
	Vikey3DesDecrypt=(FunVikey3DesDecrypt)GetProcAddress(hInst,"Vikey3DesDecrypt");

	VikeySetMaxClientCount=(FunVikeySetMaxClientCount)GetProcAddress(hInst,"VikeySetMaxClientCount");
	VikeyGetMaxClientCount=(FunVikeyGetMaxClientCount)GetProcAddress(hInst,"VikeyGetMaxClientCount");

	VikeyMD5=(FunVikeyMD5)GetProcAddress(hInst,"VikeyMD5VikeyMD5");
	VikeySetMD5Key=(FunVikeySetMD5Key)GetProcAddress(hInst,"VikeySetMD5Key");
	VikeyHmacMD5=(FunVikeyHmacMD5)GetProcAddress(hInst,"VikeyHmacMD5");

	VikeySHA1=(FunVikeySHA1)GetProcAddress(hInst,"VikeySHA1");
	VikeySetSHA1Key=(FunVikeySetSHA1Key)GetProcAddress(hInst,"VikeySetSHA1Key");
	VikeyHmacSHA1=(FunVikeyHmacSHA1)GetProcAddress(hInst,"VikeyHmacSHA1");
}

int main(int argc, char* argv[])
{
    long dwRetCode;
	unsigned short Index;
	long dwCount;
	long dwHID;
	InitializeViKeyFunction();
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


        for(int i=0; i<9; i++)
	{
		szSoftID[i] = 0;
	}
	dwRetCode = VikeyGetSoftIDString(Index, szSoftID);
	if(dwRetCode)
	{
		printf("设置软件ID失败!\n");
	}
	else
	{
		printf("设置软件ID成功：%s!\n", szSoftID);
	}

		unsigned short  p1;
		unsigned short  p2;
		unsigned short  p3;
		unsigned short  p4;

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
        system("pause");
	return 0;
}
//---------------------------------------------------------------------------
 