package ViKey;


public class ViKeyJavaObj
{

	public ViKeyJavaObj()
	{
        System.loadLibrary("ViKeyJavaObj"); 
	}

    final public int VIKEY_SUCCESS						= 00; //成功
    final public int VIKEY_ERROR_NO_VIKEY				= 01; //没有找到ViKey加密锁
    final public int VIKEY_ERROR_INVALID_PASSWORD		= 02; //密码错误
    final public int VIKEY_ERROR_NEED_FIND				= 03; //请先查找加密锁
    final public int VIKEY_ERROR_INVALID_INDEX			= 04; //无效的句柄
    final public int VIKEY_ERROR_INVALID_VALUE			= 05; //数值错误
    final public int VIKEY_ERROR_INVALID_KEY			= 06; //秘钥无效
    final public int VIKEY_ERROR_GET_VALUE				= 07; //读取信息错误
    final public int VIKEY_ERROR_SET_VALUE				= 8; //设置信息错误
    final public int VIKEY_ERROR_NO_CHANCE				= 9; //没有机会
    final public int VIKEY_ERROR_NO_TAUTHORITY			= 10; //权限不足
    final public int VIKEY_ERROR_INVALID_ADDR_OR_SIZE	= 11; //地址或长度错误
    final public int VIKEY_ERROR_RANDOM					= 12; //获取随机数错误
    final public int VIKEY_ERROR_SEED					= 13; //获取种子错误
    final public int VIKEY_ERROR_CONNECTION				= 14; //通信错误
    final public int VIKEY_ERROR_CALCULATE				= 15; //算法或计算错误
    final public int VIKEY_ERROR_MODULE					= 16; //计数器错误
    final public int VIKEY_ERROR_GENERATE_NEW_PASSWORD	= 17; //产生密码错误
    final public int VIKEY_ERROR_ENCRYPT_FAILED			= 18; //加密数据错误
    final public int VIKEY_ERROR_DECRYPT_FAILED			= 19; //解密数据错误
    final public int VIKEY_ERROR_ALREADY_LOCKED			= 20; //ViKey加密锁已经被锁定
    final public int VIKEY_ERROR_UNKNOWN_COMMAND		= 21; //无效的命令
    final public int VIKEY_ERROR_NO_SUPPORT				= 22; //当前ViKey加密锁不支持此功能
//    final public int VIKEY_ERROR_UNKNOWN_ERROR			= 0xFFFFFFFF //未知错误


    public native int ViKeyFind(int[] lpdwCount);
    public native int ViKeyGetType(short Index, byte[] pType);
	
    public native int ViKeyGetHID(short Index, int[] pdwHID);
    public native int VikeyGetLevel(short Index, byte[] pLevel);
    public native int ViKeyUserLogin(short Index, byte[] pPassWord);
    public native int ViKeyAdminLogin(short Index,  byte[] pPassWord);
    public native int ViKeyLogoff(short Index);

    public native int VikeySetUserPassWordAttempt(short Index, byte cAttempt);
    public native int VikeySetAdminPassWordAttempt(short Index, byte cAttempt);
    public native int VikeyGetUserPassWordAttempt(short Index, byte[] pcAttempt);
    public native int VikeyGetAdminPassWordAttempt(short Index, byte[] pcAttempt);

    public native int VikeyResetPassword(short Index, byte[] NewUserPassword, byte[] NewAdminPassword);

    public native int ViKeySetSoftIDString(short Index, byte[] pSoftIDString);
    public native int ViKeyGetSoftIDString(short Index, byte[] pSoftIDString);

    public native int ViKeyGetUpdateTag(short Index, int[] pdwUpdateTag);
    public native int ViKeySetUpdateTag(short Index, int dwUpdateTag);

    public native int ViKeyGetVersionFlag(short Index, int[] pdwVersionFlag);
    public native int ViKeySetVersionFlag(short Index, int dwVersionFlag);

    public native int ViKeyReadData(short Index, short Addr, short Length, byte[] buffer);
    public native int ViKeyWriteData(short Index, short Addr, short Length, byte[] buffer);
    public native int ViKeyRandom(short Index, short[] pwRandom1, short[] pwRandom2, short[] pwRandom3, short[] pwRandom4);
    public native int ViKeySeed(short Index, int dwSeed, short[] pwData1, short[] pwData2, short[] pwData3, short[] pwData4);

    public native int ViKeyDecraseModule(short Index, short wModuleIndex);
    public native int ViKeyGetModule(short Index, short wModuleIndex, short[] pwValue);
    public native int ViKeySetModule(short Index, short wModuleIndex, short wValue, short wMode);
    public native int ViKeyCheckModule(short Index, short wModuleIndex, short[] IsZero, short[] CanDecrase);

//For ViKeyNET、ViKeyPRO
    public native int ViKeySetMaxClientCount(short Index, short dwCount);
    public native int ViKeyGetMaxClientCount(short Index, short[] pdwCount);

//For ViKeyWEB、ViKeyPRO
    public native int ViKeySetMD5Key(short Index, byte[] pMD5key);
    public native int ViKeyHmacMD5(short Index, short length, byte[] pText, byte[] pResult); 
}



