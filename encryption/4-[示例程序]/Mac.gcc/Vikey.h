//#ifndef VIKEY_API
//#define VIKEY_API

typedef enum 
{
	ViKeyAPP,		//ʵ���ͼ��ܹ�
	ViKeySTD,		//��׼�ͼ��ܹ�
	ViKeyNET,		//�����ͼ��ܹ�
	ViKeyPRO,		//רҵ�ͼ��ܹ�
	ViKeyWEB,		//�����֤�ͼ��ܹ�
	ViKeyTIME,		//ʱ���ͼ��ܹ����ڲ�����ʱ��
	ViKeyInvalid		//��Ч����
} VikeyType;


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

/*********For ViKeyAPP��ViKeySTD��ViKeyNet��ViKeyPRO��ViKeyTime APIs**********/

DWORD VikeyFind(DWORD* pdwCount);
DWORD VikeyGetHID(WORD Index, DWORD *pdwHID);
DWORD VikeyGetType(WORD Index, VikeyType * pType);
DWORD VikeyGetLevel(WORD Index, BYTE *pLevel);
DWORD VikeySetPtroductName(WORD Index, WCHAR szName[16]);
DWORD VikeyGetPtroductName(WORD Index, WCHAR szName[16]);

//��½��ע�����ܹ�
//���ܹ����볤��8���ַ� ��ĸ������
DWORD VikeyUserLogin(WORD Index, char * pUserPassWord);
DWORD VikeyAdminLogin(WORD Index, char * pAdminPassWord);
DWORD VikeyLogoff(WORD Index);

//�������볢�Դ������޸�����
DWORD VikeySetUserPassWordAttempt(WORD Index, BYTE cAttempt);
DWORD VikeySetAdminPassWordAttempt(WORD Index, BYTE cAttempt);
DWORD VikeyGetUserPassWordAttempt(WORD Index, BYTE *pcCurrentAttempt, BYTE *pcMaxAttempt);
DWORD VikeyGetAdminPassWordAttempt(WORD Index, BYTE *pcCurrentAttempt, BYTE *pcMaxAttempt);
DWORD VikeyResetPassword(WORD Index, char * pNewUserPassWord, char * pNewAdminPassWord);

//���ID��д
//���ID����8���ַ� ��ĸ������
DWORD VikeySetSoftIDString(WORD Index, char * pSoftIDString);
DWORD VikeyGetSoftIDString(WORD Index, char * pSoftIDString);

//��д����
DWORD VikeyReadData(WORD Index, WORD Addr, WORD Length, BYTE * buffer);
DWORD VikeyWriteData(WORD Index, WORD Addr, WORD Length, BYTE * buffer);
DWORD ViKeyRandom(WORD Index, WORD* pwRandom1, WORD* pwRandom2, WORD* pwRandom3, WORD* pwRandom4);
DWORD VikeySeed(WORD Index, DWORD dwSeed, WORD* pwData1, WORD* pwData2, WORD* pwData3, WORD* pwData4);

//������ģ��
DWORD ViKeyDecraseModule(WORD Index, WORD wModuleIndex);
DWORD ViKeyGetModule(WORD Index, WORD wModuleIndex, WORD* pwValue);
DWORD ViKeySetModule(WORD Index, WORD wModuleIndex, WORD wValue, WORD wMode);
DWORD ViKeyCheckModule(WORD Index, WORD wModuleIndex, WORD *IsZero, WORD* CanDecrase);

//�ӽ���
DWORD Vikey3DesSetKey(WORD Index, BYTE * pMD5key);
DWORD Vikey3DesEncrypt(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD Vikey3DesDecrypt(WORD Index, WORD length, BYTE * pText, BYTE* pResult);

//For ViKeyNET��ViKeyPRO
DWORD VikeySetMaxClientCount(WORD Index, WORD dwCount);
DWORD VikeyGetMaxClientCount(WORD Index, WORD* pdwCount);

//For ViKeyWEB��ViKeyPRO
DWORD VikeyMD5(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD VikeySetMD5Key(WORD Index, BYTE * pMD5key);
DWORD VikeyHmacMD5(WORD Index, WORD length, BYTE * pText, BYTE* pResult);

DWORD VikeySHA1(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD VikeySetSHA1Key(WORD Index, BYTE * pSHA1key);
DWORD VikeyHmacSHA1(WORD Index, WORD length, BYTE * pText, BYTE* pResult);


//For ViKeyTIME
//��ȡʱ���ͼ��ܹ��е��ڲ�ʱ��
DWORD VikeyGetTime(WORD Index, BYTE* pTime);

#ifdef __cplusplus
} //  extern "C"{
#endif

//#endif
