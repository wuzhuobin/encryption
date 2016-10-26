package ViKey;


public class ViKeyJavaObj
{

	public ViKeyJavaObj()
	{
        System.loadLibrary("ViKeyJavaObj"); 
	}

    final public int VIKEY_SUCCESS						= 00; //�ɹ�
    final public int VIKEY_ERROR_NO_VIKEY				= 01; //û���ҵ�ViKey������
    final public int VIKEY_ERROR_INVALID_PASSWORD		= 02; //�������
    final public int VIKEY_ERROR_NEED_FIND				= 03; //���Ȳ��Ҽ�����
    final public int VIKEY_ERROR_INVALID_INDEX			= 04; //��Ч�ľ��
    final public int VIKEY_ERROR_INVALID_VALUE			= 05; //��ֵ����
    final public int VIKEY_ERROR_INVALID_KEY			= 06; //��Կ��Ч
    final public int VIKEY_ERROR_GET_VALUE				= 07; //��ȡ��Ϣ����
    final public int VIKEY_ERROR_SET_VALUE				= 8; //������Ϣ����
    final public int VIKEY_ERROR_NO_CHANCE				= 9; //û�л���
    final public int VIKEY_ERROR_NO_TAUTHORITY			= 10; //Ȩ�޲���
    final public int VIKEY_ERROR_INVALID_ADDR_OR_SIZE	= 11; //��ַ�򳤶ȴ���
    final public int VIKEY_ERROR_RANDOM					= 12; //��ȡ���������
    final public int VIKEY_ERROR_SEED					= 13; //��ȡ���Ӵ���
    final public int VIKEY_ERROR_CONNECTION				= 14; //ͨ�Ŵ���
    final public int VIKEY_ERROR_CALCULATE				= 15; //�㷨��������
    final public int VIKEY_ERROR_MODULE					= 16; //����������
    final public int VIKEY_ERROR_GENERATE_NEW_PASSWORD	= 17; //�����������
    final public int VIKEY_ERROR_ENCRYPT_FAILED			= 18; //�������ݴ���
    final public int VIKEY_ERROR_DECRYPT_FAILED			= 19; //�������ݴ���
    final public int VIKEY_ERROR_ALREADY_LOCKED			= 20; //ViKey�������Ѿ�������
    final public int VIKEY_ERROR_UNKNOWN_COMMAND		= 21; //��Ч������
    final public int VIKEY_ERROR_NO_SUPPORT				= 22; //��ǰViKey��������֧�ִ˹���
//    final public int VIKEY_ERROR_UNKNOWN_ERROR			= 0xFFFFFFFF //δ֪����


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

//For ViKeyNET��ViKeyPRO
    public native int ViKeySetMaxClientCount(short Index, short dwCount);
    public native int ViKeyGetMaxClientCount(short Index, short[] pdwCount);

//For ViKeyWEB��ViKeyPRO
    public native int ViKeySetMD5Key(short Index, byte[] pMD5key);
    public native int ViKeyHmacMD5(short Index, short length, byte[] pText, byte[] pResult); 
}



