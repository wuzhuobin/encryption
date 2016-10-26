//#ifndef VIKEY_API
//#define VIKEY_API

enum VikeyType
{
	ViKeyAPP,		//ʵ���ͼ��ܹ�
	ViKeySTD,		//��׼�ͼ��ܹ�
	ViKeyNET,		//�����ͼ��ܹ�
	ViKeyPRO,		//רҵ�ͼ��ܹ�
	ViKeyWEB,		//�����֤�ͼ��ܹ�
	ViKeyTIME,		//ʱ���ͼ��ܹ����ڲ�����ʱ��
	ViKeyInvalid	//��Ч����
};


#define ViKeyNoLevel		0	//����Ȩ��(û�е�¼�����ܹ�ʱ����ʱȨ��Ϊ����Ȩ��)
#define ViKeyUserLevel		1	//�û�Ȩ��(����VikeyUserLogin��¼���ܹ��ɹ��󣬴�ʱȨ��Ϊ�û�Ȩ��)
#define ViKeyAdminLevel		2	//����ԱȨ��(����VikeyAdminLogin��¼���ܹ��ɹ��󣬴�ʱȨ��Ϊ����ԱȨ��)

#define VIKEY_SUCCESS						0x00000000 //�ɹ�
#define VIKEY_ERROR_NO_VIKEY				0x80000001 //û���ҵ�ViKey������
#define VIKEY_ERROR_INVALID_PASS			0x80000002 //�������
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
#define VIKEY_ERROR_GENERATE_NEW_PASS		0x80000011 //�����������
#define VIKEY_ERROR_ENCRYPT_FAILED			0x80000012 //�������ݴ���
#define VIKEY_ERROR_DECRYPT_FAILED			0x80000013 //�������ݴ���
#define VIKEY_ERROR_ALREADY_LOCKED			0x80000014 //ViKey�������Ѿ�������
#define VIKEY_ERROR_UNKNOWN_COMMAND			0x80000015 //��Ч������
#define VIKEY_ERROR_NO_SUPPORT				0x80000016 //��ǰViKey��������֧�ִ˹���
#define VIKEY_ERROR_UNKNOWN_ERROR			0xFFFFFFFF //δ֪����

//#ifdef __cplusplus
extern "C"{
//#endif

//��˵����Ϊ���ó���Ա�����º���һĿ��Ȼ������ֻ�г�������ԭ�ͣ����ں������ܺͲ����Ľ����ڰ����ֲ����г���
//��˵�����뵽��1-[��Ʒ�ĵ�]��Ŀ¼�²鿴��ViKeyϵ�м��ܹ�ʹ��˵���ֲᡷ�ĵ���

/*********For ViKeyAPP��ViKeySTD��ViKeyNet��ViKeyPRO��ViKeyTime APIs**********/

long __stdcall VikeyFind(long* pdwCount);
long __stdcall VikeyGetHID(unsigned short Index, long *pdwHID);
long __stdcall VikeyGetType(unsigned short Index, VikeyType *pType);
long __stdcall VikeyGetLevel(unsigned short Index, unsigned char *pLevel);
long __stdcall VikeySetPtroductName(unsigned short Index, unsigned short szName[16]);
long __stdcall VikeyGetPtroductName(unsigned short Index, unsigned short szName[16]);

//��½��ע�����ܹ�
//���ܹ����볤��8���ַ� ��ĸ������
long __stdcall VikeyUserLogin(unsigned short Index, char * pUserPassWord);
long __stdcall VikeyAdminLogin(unsigned short Index, char * pAdminPassWord);
long __stdcall VikeyLogoff(unsigned short Index);

//�������볢�Դ������޸�����
long __stdcall VikeySetUserPassWordAttempt(unsigned short Index, unsigned char cAttempt);
long __stdcall VikeySetAdminPassWordAttempt(unsigned short Index, unsigned char cAttempt);
long __stdcall VikeyGetUserPassWordAttempt(unsigned short Index, unsigned char *pcCurrentAttempt, unsigned char *pcMaxAttempt);
long __stdcall VikeyGetAdminPassWordAttempt(unsigned short Index, unsigned char *pcCurrentAttempt, unsigned char *pcMaxAttempt);
long __stdcall VikeyResetPassword(unsigned short Index, char * pNewUserPassWord,  char * pNewAdminPassWord);

//���ID��д
//���ID����8���ַ� ��ĸ������
long __stdcall VikeySetSoftIDString(unsigned short Index, char * pSoftIDString);
long __stdcall VikeyGetSoftIDString(unsigned short Index, char * pSoftIDString);

//��д����
long __stdcall VikeyReadData(unsigned short Index, unsigned short Addr, unsigned short Length, unsigned char * buffer);
long __stdcall VikeyWriteData(unsigned short Index, unsigned short Addr, unsigned short Length, unsigned char * buffer);
long __stdcall ViKeyRandom(unsigned short Index, unsigned short* pwRandom1, unsigned short* pwRandom2, unsigned short* pwRandom3, unsigned short* pwRandom4);

//������ģ��
long __stdcall ViKeyDecraseModule(unsigned short Index, unsigned short wModuleIndex);
long __stdcall ViKeyGetModule(unsigned short Index, unsigned short wModuleIndex, unsigned short* pwValue);
long __stdcall ViKeySetModule(unsigned short Index, unsigned short wModuleIndex, unsigned short wValue, unsigned short wMode);
long __stdcall ViKeyCheckModule(unsigned short Index, unsigned short wModuleIndex, unsigned short *IsZero, unsigned short* CanDecrase);

//�ӽ���
long __stdcall Vikey3DesSetKey(unsigned short Index, unsigned char * pMD5key);
long __stdcall Vikey3DesEncrypt(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
long __stdcall Vikey3DesDecrypt(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);

//For ViKeyNET��ViKeyPRO
long __stdcall VikeySetMaxClientCount(unsigned short Index, unsigned short dwCount);
long __stdcall VikeyGetMaxClientCount(unsigned short Index, unsigned short* pdwCount);

//For ViKeyWEB��ViKeyPRO
long __stdcall VikeyMD5(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
long __stdcall VikeySetMD5Key(unsigned short Index, unsigned char * pMD5key);
long __stdcall VikeyHmacMD5(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);

long __stdcall VikeySHA1(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
long __stdcall VikeySetSHA1Key(unsigned short Index, unsigned char * pSHA1key);
long __stdcall VikeyHmacSHA1(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);


//For ViKeyTIME
typedef struct _VIKEY_TIME 
{ 
	unsigned char cYear; 
	unsigned char cMonth; 
	unsigned char cDay; 
	unsigned char cHour; 
	unsigned char cMinute; 
	unsigned char cSecond; 

	bool operator < (const _VIKEY_TIME &another) const;
	bool operator > (const _VIKEY_TIME &another) const;
} SVikeyTime, *PVIKEYTIME;

//��ȡʱ���ͼ��ܹ��е��ڲ�ʱ��
long __stdcall VikeyGetTime(unsigned short Index, PVIKEYTIME pTime);

long __stdcall VikeyGetCurrentPcChkData(unsigned short Index, unsigned char* pChkData);
long __stdcall VikeySetPcChkData(unsigned short Index, unsigned char* pChkData);
long __stdcall VikeyClearPcChkData(unsigned short Index);

long __stdcall VikeyIsThisPc(unsigned short Index);

//#ifdef __cplusplus
} //  extern "C"{
//#endif

//#endif
