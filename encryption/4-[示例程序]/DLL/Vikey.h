#ifndef VIKEY_API
#define VIKEY_API

enum VikeyType
{
	ViKeyAPP = 0,						//ʵ���ͼ��ܹ�
	ViKeySTD = 1,						//��׼�ͼ��ܹ�
	ViKeyNET = 2,						//�����ͼ��ܹ�
	ViKeyPRO = 3,						//רҵ�ͼ��ܹ�
	ViKeyWEB = 4,						//�����֤�ͼ��ܹ�
	ViKeyTIME = 5,						//ʱ���ͼ��ܹ����ڲ�����ʱ��
	ViKeyMultiFunctional = 0x0A,		//�๦�ܼ��ܹ�  ֧��������� ֧���ĵ�����
	ViKeyMultiFunctionalTime = 0x0B,	//�๦��ʱ�Ӽ��ܹ�
	ViKeyInvalid	//��Ч����
};


#define ViKeyNoLevel		0	//����Ȩ��(û�е�¼�����ܹ�ʱ����ʱȨ��Ϊ����Ȩ��)
#define ViKeyUserLevel		1	//�û�Ȩ��(����VikeyUserLogin��¼���ܹ��ɹ��󣬴�ʱȨ��Ϊ�û�Ȩ��)
#define ViKeyAdminLevel		2	//����ԱȨ��(����VikeyAdminLogin��¼���ܹ��ɹ��󣬴�ʱȨ��Ϊ����ԱȨ��)

#define VIKEY_SUCCESS						0x00000000 //�ɹ�
#define VIKEY_ERROR_NO_VIKEY				0x80000001 //û���ҵ�ViKey������
#define VIKEY_ERROR_INVALID_PASSWORD		0x80000002 //�������
#define VIKEY_ERROR_NEED_FIND				0x80000003 //���Ȳ��Ҽ�����
#define VIKEY_ERROR_INVALID_INDEX			0x80000004 //��Ч�ľ��
#define VIKEY_ERROR_INVALID_VALUE			0x80000005 //��ֵ����
#define VIKEY_ERROR_INVALID_KEY				0x80000006 //��Կ��Ч
#define VIKEY_ERROR_GET_VALUE				0x80000007 //��ȡ��Ϣ����
#define VIKEY_ERROR_SET_VALUE				0x80000008 //������Ϣ����
#define VIKEY_ERROR_NO_CHANCE				0x80000009 //û�л���
#define VIKEY_ERROR_NO_TAUTHORITY			0x8000000A //Ȩ�޲���
#define VIKEY_ERROR_INVALID_ADDR_OR_SIZE	0x8000000B //��ַ�򳤶ȴ���
#define VIKEY_ERROR_RANDOM					0x8000000C //��ȡ���������
#define VIKEY_ERROR_SEED					0x8000000D //��ȡ���Ӵ���
#define VIKEY_ERROR_CONNECTION				0x8000000E //ͨ�Ŵ���
#define VIKEY_ERROR_CALCULATE				0x8000000F //�㷨��������
#define VIKEY_ERROR_MODULE					0x80000010 //����������
#define VIKEY_ERROR_GENERATE_NEW_PASSWORD	0x80000011 //�����������
#define VIKEY_ERROR_ENCRYPT_FAILED			0x80000012 //�������ݴ���
#define VIKEY_ERROR_DECRYPT_FAILED			0x80000013 //�������ݴ���
#define VIKEY_ERROR_ALREADY_LOCKED			0x80000014 //ViKey�������Ѿ�������
#define VIKEY_ERROR_UNKNOWN_COMMAND			0x80000015 //��Ч������
#define VIKEY_ERROR_NO_SUPPORT				0x80000016 //��ǰViKey��������֧�ִ˹���
#define VIKEY_ERROR_UNKNOWN_ERROR			0xFFFFFFFF //δ֪����

#ifdef __cplusplus
extern "C"{
#endif

//��˵����Ϊ���ó���Ա�����º���һĿ��Ȼ������ֻ�г�������ԭ�ͣ����ں������ܺͲ����Ľ����ڰ����ֲ����г���
//��˵�����뵽��1-[��Ʒ�ĵ�]��Ŀ¼�²鿴��ViKeyϵ�м��ܹ�ʹ��˵���ֲᡷ�ĵ���

/*********For ViKeyAPP��ViKeySTD��ViKeyNet��ViKeyPRO��ViKeyTime APIs**********/

DWORD __stdcall VikeyFind(DWORD* pdwCount);
DWORD __stdcall VikeyGetHID(WORD Index, DWORD *pdwHID);
DWORD __stdcall VikeyGetType(WORD Index, VikeyType *pType);
DWORD __stdcall VikeyGetLevel(WORD Index, BYTE *pLevel);
DWORD __stdcall VikeySetPtroductName(WORD Index, WCHAR szName[16]);
DWORD __stdcall VikeyGetPtroductName(WORD Index, WCHAR szName[16]);
DWORD __stdcall VikeyGetPtroductNameA(WORD Index, CHAR szName[16]);

//��½��ע�����ܹ�
//���ܹ����볤��8���ַ� ��ĸ������
DWORD __stdcall VikeyUserLogin(WORD Index, char * pUserPassWord);
DWORD __stdcall VikeyAdminLogin(WORD Index, char * pAdminPassWord);
DWORD __stdcall VikeyLogoff(WORD Index);

//�������볢�Դ������޸�����
DWORD __stdcall VikeySetUserPassWordAttempt(WORD Index, BYTE cAttempt);
DWORD __stdcall VikeySetAdminPassWordAttempt(WORD Index, BYTE cAttempt);
DWORD __stdcall VikeyGetUserPassWordAttempt(WORD Index, BYTE *pcCurrentAttempt, BYTE *pcMaxAttempt);
DWORD __stdcall VikeyGetAdminPassWordAttempt(WORD Index, BYTE *pcCurrentAttempt, BYTE *pcMaxAttempt);
DWORD __stdcall VikeyResetPassword(WORD Index, char * pNewUserPassWord, char * pNewAdminPassWord);

//���ID��д
//���ID����8���ַ� ��ĸ������
DWORD __stdcall VikeySetSoftIDString(WORD Index, char * pSoftIDString);
DWORD __stdcall VikeyGetSoftIDString(WORD Index, char * pSoftIDString);

//��д����
DWORD __stdcall VikeyReadData(WORD Index, WORD Addr, WORD Length, BYTE * buffer);
DWORD __stdcall VikeyWriteData(WORD Index, WORD Addr, WORD Length, BYTE * buffer);
DWORD __stdcall ViKeyRandom(WORD Index, WORD* pwRandom1, WORD* pwRandom2, WORD* pwRandom3, WORD* pwRandom4);

//������ģ��
DWORD __stdcall ViKeyDecraseModule(WORD Index, WORD wModuleIndex);
DWORD __stdcall ViKeyGetModule(WORD Index, WORD wModuleIndex, WORD* pwValue);
DWORD __stdcall ViKeySetModule(WORD Index, WORD wModuleIndex, WORD wValue, WORD wMode);
DWORD __stdcall ViKeyCheckModule(WORD Index, WORD wModuleIndex, WORD *IsZero, WORD* CanDecrase);

//�ӽ���
enum Des3KeyLengthType
{
	Des3KeyLength16,
	Des3KeyLength24
};

DWORD __stdcall Vikey3DesSetKey(WORD Index, BYTE * pKey, Des3KeyLengthType KeyType);
DWORD __stdcall Vikey3DesEncrypt(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD __stdcall Vikey3DesDecrypt(WORD Index, WORD length, BYTE * pText, BYTE* pResult);

DWORD __stdcall VikeyDesSetKey(WORD Index, BYTE * pKey);
DWORD __stdcall VikeyDesEncrypt(WORD Index, WORD InLength, BYTE * pText, BYTE* pResult, WORD *OutLength);
DWORD __stdcall VikeyDesDecrypt(WORD Index, WORD InLength, BYTE * pText, BYTE* pResult, WORD *OutLength);

//�Զ�����ҳ�ӿ�
DWORD __stdcall VikeySetAutoRunUrl(WORD Index, BYTE *pUrl);
DWORD __stdcall VikeyGetAutoRunUrl(WORD Index, BYTE *pUrl);

//For ViKeyNET��ViKeyPRO
DWORD __stdcall VikeySetMaxClientCount(WORD Index, WORD dwCount);
DWORD __stdcall VikeyGetMaxClientCount(WORD Index, WORD* pdwCount);

//For ViKeyWEB��ViKeyPRO
DWORD __stdcall VikeyMD5(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD __stdcall VikeySetMD5Key(WORD Index, BYTE * pMD5key);
DWORD __stdcall VikeyHmacMD5(WORD Index, WORD length, BYTE * pText, BYTE* pResult);

DWORD __stdcall VikeySHA1(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD __stdcall VikeySetSHA1Key(WORD Index, BYTE * pSHA1key);
DWORD __stdcall VikeyHmacSHA1(WORD Index, WORD length, BYTE * pText, BYTE* pResult);


//For ViKeyTIME
typedef struct _VIKEY_TIME 
{ 
	BYTE cYear; 
	BYTE cMonth; 
	BYTE cDay; 
	BYTE cHour; 
	BYTE cMinute; 
	BYTE cSecond; 

	bool operator < (const _VIKEY_TIME &another) const;
	bool operator > (const _VIKEY_TIME &another) const;
} SVikeyTime, *PVIKEYTIME;

//��ȡʱ���ͼ��ܹ��е��ڲ�ʱ��
DWORD __stdcall VikeyGetTime(WORD Index, PVIKEYTIME pTime);


#ifdef __cplusplus
} //  extern "C"{
#endif

#endif
