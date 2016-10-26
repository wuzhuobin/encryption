//#ifndef VIKEY_API
//#define VIKEY_API

typedef enum 
{
	ViKeyAPP,		//实用型加密狗
	ViKeySTD,		//标准型加密狗
	ViKeyNET,		//网络型加密狗
	ViKeyPRO,		//专业型加密狗
	ViKeyWEB,		//身份认证型加密狗
	ViKeyTIME,		//时钟型加密狗，内部独立时钟
	ViKeyInvalid		//无效类型
} VikeyType;


#define ViKeyNoLevel		0	//匿名权限(没有登录过加密狗时，此时权限为匿名权限)
#define ViKeyUserLevel		1	//用户权限(调用VikeyUserLogin登录加密狗成功后，此时权限为用户权限)
#define ViKeyAdminLevel		2	//管理员权限(调用VikeyAdminLogin登录加密狗成功后，此时权限为管理员权限)

#define VIKEY_SUCCESS						0x00000000 //成功
#define VIKEY_ERROR_NO_VIKEY				0x80000001 //没有找到ViKey加密锁
#define VIKEY_ERROR_INVALID_PASSWORD		0x80000002 //密码错误
#define VIKEY_ERROR_NEED_FIND				0x80000003 //请先查找加密锁
#define VIKEY_ERROR_INVALID_INDEX			0x80000004 //无效的句柄
#define VIKEY_ERROR_INVALID_VALUE			0x80000005 //数值错误
#define VIKEY_ERROR_INVALID_KEY				0x80000006 //秘钥无效
#define VIKEY_ERROR_GET_VALUE				0x80000007 //读取信息错误
#define VIKEY_ERROR_SET_VALUE				0x80000008 //设置信息错误
#define VIKEY_ERROR_NO_CHANCE				0x80000009 //没有机会
#define VIKEY_ERROR_NO_TAUTHORITY			0x8000000A //权限不足
#define VIKEY_ERROR_INVALID_ADDR_OR_SIZE	0x8000000B //地址或长度错误
#define VIKEY_ERROR_RANDOM					0x8000000C //获取随机数错误
#define VIKEY_ERROR_SEED					0x8000000D //获取种子错误
#define VIKEY_ERROR_CONNECTION				0x8000000E //通信错误
#define VIKEY_ERROR_CALCULATE				0x8000000F //算法或计算错误
#define VIKEY_ERROR_MODULE					0x80000010 //计数器错误
#define VIKEY_ERROR_GENERATE_NEW_PASSWORD	0x80000011 //产生密码错误
#define VIKEY_ERROR_ENCRYPT_FAILED			0x80000012 //加密数据错误
#define VIKEY_ERROR_DECRYPT_FAILED			0x80000013 //解密数据错误
#define VIKEY_ERROR_ALREADY_LOCKED			0x80000014 //ViKey加密锁已经被锁定
#define VIKEY_ERROR_UNKNOWN_COMMAND			0x80000015 //无效的命令
#define VIKEY_ERROR_NO_SUPPORT				0x80000016 //当前ViKey加密锁不支持此功能
#define VIKEY_ERROR_UNKNOWN_ERROR			0xFFFFFFFF //未知错误

#ifdef __cplusplus
extern "C"{
#endif

/*********For ViKeyAPP、ViKeySTD、ViKeyNet、ViKeyPRO、ViKeyTime APIs**********/

DWORD VikeyFind(DWORD* pdwCount);
DWORD VikeyGetHID(WORD Index, DWORD *pdwHID);
DWORD VikeyGetType(WORD Index, VikeyType * pType);
DWORD VikeyGetLevel(WORD Index, BYTE *pLevel);
DWORD VikeySetPtroductName(WORD Index, WCHAR szName[16]);
DWORD VikeyGetPtroductName(WORD Index, WCHAR szName[16]);

//登陆、注销加密狗
//加密狗密码长度8个字符 字母或数字
DWORD VikeyUserLogin(WORD Index, char * pUserPassWord);
DWORD VikeyAdminLogin(WORD Index, char * pAdminPassWord);
DWORD VikeyLogoff(WORD Index);

//设置密码尝试次数、修改密码
DWORD VikeySetUserPassWordAttempt(WORD Index, BYTE cAttempt);
DWORD VikeySetAdminPassWordAttempt(WORD Index, BYTE cAttempt);
DWORD VikeyGetUserPassWordAttempt(WORD Index, BYTE *pcCurrentAttempt, BYTE *pcMaxAttempt);
DWORD VikeyGetAdminPassWordAttempt(WORD Index, BYTE *pcCurrentAttempt, BYTE *pcMaxAttempt);
DWORD VikeyResetPassword(WORD Index, char * pNewUserPassWord, char * pNewAdminPassWord);

//软件ID读写
//软件ID长度8个字符 字母或数字
DWORD VikeySetSoftIDString(WORD Index, char * pSoftIDString);
DWORD VikeyGetSoftIDString(WORD Index, char * pSoftIDString);

//读写数据
DWORD VikeyReadData(WORD Index, WORD Addr, WORD Length, BYTE * buffer);
DWORD VikeyWriteData(WORD Index, WORD Addr, WORD Length, BYTE * buffer);
DWORD ViKeyRandom(WORD Index, WORD* pwRandom1, WORD* pwRandom2, WORD* pwRandom3, WORD* pwRandom4);
DWORD VikeySeed(WORD Index, DWORD dwSeed, WORD* pwData1, WORD* pwData2, WORD* pwData3, WORD* pwData4);

//计数器模块
DWORD ViKeyDecraseModule(WORD Index, WORD wModuleIndex);
DWORD ViKeyGetModule(WORD Index, WORD wModuleIndex, WORD* pwValue);
DWORD ViKeySetModule(WORD Index, WORD wModuleIndex, WORD wValue, WORD wMode);
DWORD ViKeyCheckModule(WORD Index, WORD wModuleIndex, WORD *IsZero, WORD* CanDecrase);

//加解密
DWORD Vikey3DesSetKey(WORD Index, BYTE * pMD5key);
DWORD Vikey3DesEncrypt(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD Vikey3DesDecrypt(WORD Index, WORD length, BYTE * pText, BYTE* pResult);

//For ViKeyNET、ViKeyPRO
DWORD VikeySetMaxClientCount(WORD Index, WORD dwCount);
DWORD VikeyGetMaxClientCount(WORD Index, WORD* pdwCount);

//For ViKeyWEB、ViKeyPRO
DWORD VikeyMD5(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD VikeySetMD5Key(WORD Index, BYTE * pMD5key);
DWORD VikeyHmacMD5(WORD Index, WORD length, BYTE * pText, BYTE* pResult);

DWORD VikeySHA1(WORD Index, WORD length, BYTE * pText, BYTE* pResult);
DWORD VikeySetSHA1Key(WORD Index, BYTE * pSHA1key);
DWORD VikeyHmacSHA1(WORD Index, WORD length, BYTE * pText, BYTE* pResult);


//For ViKeyTIME
//获取时钟型加密狗中的内部时间
DWORD VikeyGetTime(WORD Index, BYTE* pTime);

#ifdef __cplusplus
} //  extern "C"{
#endif

//#endif
