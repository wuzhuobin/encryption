//#ifndef VIKEY_API
//#define VIKEY_API

enum VikeyType
{
	ViKeyAPP,		//实用型加密狗
	ViKeySTD,		//标准型加密狗
	ViKeyNET,		//网络型加密狗
	ViKeyPRO,		//专业型加密狗
	ViKeyWEB,		//身份认证型加密狗
	ViKeyTIME,		//时钟型加密狗，内部独立时钟
	ViKeyInvalid	//无效类型
};


#define ViKeyNoLevel		0	//匿名权限(没有登录过加密狗时，此时权限为匿名权限)
#define ViKeyUserLevel		1	//用户权限(调用VikeyUserLogin登录加密狗成功后，此时权限为用户权限)
#define ViKeyAdminLevel		2	//管理员权限(调用VikeyAdminLogin登录加密狗成功后，此时权限为管理员权限)

#define VIKEY_SUCCESS						0x00000000 //成功
#define VIKEY_ERROR_NO_VIKEY				0x80000001 //没有找到ViKey加密锁
#define VIKEY_ERROR_INVALID_PASS			0x80000002 //密码错误
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
#define VIKEY_ERROR_GENERATE_NEW_PASS		0x80000011 //产生密码错误
#define VIKEY_ERROR_ENCRYPT_FAILED			0x80000012 //加密数据错误
#define VIKEY_ERROR_DECRYPT_FAILED			0x80000013 //解密数据错误
#define VIKEY_ERROR_ALREADY_LOCKED			0x80000014 //ViKey加密锁已经被锁定
#define VIKEY_ERROR_UNKNOWN_COMMAND			0x80000015 //无效的命令
#define VIKEY_ERROR_NO_SUPPORT				0x80000016 //当前ViKey加密锁不支持此功能
#define VIKEY_ERROR_UNKNOWN_ERROR			0xFFFFFFFF //未知错误

//#ifdef __cplusplus
extern "C"{
//#endif

//【说明】为了让程序员对以下函数一目了然，这里只列出函数的原型，对于函数功能和参数的解释在帮助手册中列出。
//【说明】请到“1-[产品文档]”目录下查看《ViKey系列加密狗使用说明手册》文档。

/*********For ViKeyAPP、ViKeySTD、ViKeyNet、ViKeyPRO、ViKeyTime APIs**********/

long __stdcall VikeyFind(long* pdwCount);
long __stdcall VikeyGetHID(unsigned short Index, long *pdwHID);
long __stdcall VikeyGetType(unsigned short Index, VikeyType *pType);
long __stdcall VikeyGetLevel(unsigned short Index, unsigned char *pLevel);
long __stdcall VikeySetPtroductName(unsigned short Index, unsigned short szName[16]);
long __stdcall VikeyGetPtroductName(unsigned short Index, unsigned short szName[16]);

//登陆、注销加密狗
//加密狗密码长度8个字符 字母或数字
long __stdcall VikeyUserLogin(unsigned short Index, char * pUserPassWord);
long __stdcall VikeyAdminLogin(unsigned short Index, char * pAdminPassWord);
long __stdcall VikeyLogoff(unsigned short Index);

//设置密码尝试次数、修改密码
long __stdcall VikeySetUserPassWordAttempt(unsigned short Index, unsigned char cAttempt);
long __stdcall VikeySetAdminPassWordAttempt(unsigned short Index, unsigned char cAttempt);
long __stdcall VikeyGetUserPassWordAttempt(unsigned short Index, unsigned char *pcCurrentAttempt, unsigned char *pcMaxAttempt);
long __stdcall VikeyGetAdminPassWordAttempt(unsigned short Index, unsigned char *pcCurrentAttempt, unsigned char *pcMaxAttempt);
long __stdcall VikeyResetPassword(unsigned short Index, char * pNewUserPassWord,  char * pNewAdminPassWord);

//软件ID读写
//软件ID长度8个字符 字母或数字
long __stdcall VikeySetSoftIDString(unsigned short Index, char * pSoftIDString);
long __stdcall VikeyGetSoftIDString(unsigned short Index, char * pSoftIDString);

//读写数据
long __stdcall VikeyReadData(unsigned short Index, unsigned short Addr, unsigned short Length, unsigned char * buffer);
long __stdcall VikeyWriteData(unsigned short Index, unsigned short Addr, unsigned short Length, unsigned char * buffer);
long __stdcall ViKeyRandom(unsigned short Index, unsigned short* pwRandom1, unsigned short* pwRandom2, unsigned short* pwRandom3, unsigned short* pwRandom4);

//计数器模块
long __stdcall ViKeyDecraseModule(unsigned short Index, unsigned short wModuleIndex);
long __stdcall ViKeyGetModule(unsigned short Index, unsigned short wModuleIndex, unsigned short* pwValue);
long __stdcall ViKeySetModule(unsigned short Index, unsigned short wModuleIndex, unsigned short wValue, unsigned short wMode);
long __stdcall ViKeyCheckModule(unsigned short Index, unsigned short wModuleIndex, unsigned short *IsZero, unsigned short* CanDecrase);

//加解密
long __stdcall Vikey3DesSetKey(unsigned short Index, unsigned char * pMD5key);
long __stdcall Vikey3DesEncrypt(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);
long __stdcall Vikey3DesDecrypt(unsigned short Index, unsigned short length, unsigned char * pText, unsigned char* pResult);

//For ViKeyNET、ViKeyPRO
long __stdcall VikeySetMaxClientCount(unsigned short Index, unsigned short dwCount);
long __stdcall VikeyGetMaxClientCount(unsigned short Index, unsigned short* pdwCount);

//For ViKeyWEB、ViKeyPRO
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

//获取时钟型加密狗中的内部时间
long __stdcall VikeyGetTime(unsigned short Index, PVIKEYTIME pTime);

long __stdcall VikeyGetCurrentPcChkData(unsigned short Index, unsigned char* pChkData);
long __stdcall VikeySetPcChkData(unsigned short Index, unsigned char* pChkData);
long __stdcall VikeyClearPcChkData(unsigned short Index);

long __stdcall VikeyIsThisPc(unsigned short Index);

//#ifdef __cplusplus
} //  extern "C"{
//#endif

//#endif
