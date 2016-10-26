Option Strict Off
Option Explicit On
Module Module1
	

    'Error Code
    Public Const VIKEY_SUCCESS As Integer = &H0  '成功
    Public Const VIKEY_ERROR_NO_VIKEY As Integer = &H80000001 '没有找到ViKey加密锁
    Public Const VIKEY_ERROR_INVALID_PASSWORD As Integer = &H80000002 '密码错误
    Public Const VIKEY_ERROR_NEED_FIND As Integer = &H80000003 '请先查找加密锁
    Public Const VIKEY_ERROR_INVALID_INDEX As Integer = &H80000004 '无效的句柄
    Public Const VIKEY_ERROR_INVALID_VALUE As Integer = &H80000005 '读取信息错误
    Public Const VIKEY_ERROR_INVALID_KEY As Integer = &H80000006 '秘钥无效
    Public Const VIKEY_ERROR_GET_VALUE As Integer = &H80000007 '读取信息错误
    Public Const VIKEY_ERROR_SET_VALUE As Integer = &H80000008 '设置信息错误
    Public Const VIKEY_ERROR_NO_CHANCE As Integer = &H80000009 '没有机会
    Public Const VIKEY_ERROR_NO_TAUTHORITY As Integer = &H8000000A '权限不足
    Public Const VIKEY_ERROR_INVALID_ADDR_OR_SIZE As Integer = &H8000000B '地址或长度错误
    Public Const VIKEY_ERROR_RANDOM As Integer = &H8000000C '获取随机数错误
    Public Const VIKEY_ERROR_SEED As Integer = &H8000000D '获取种子错误
    Public Const VIKEY_ERROR_CONNECTION As Integer = &H8000000E '通信错误
    Public Const VIKEY_ERROR_CALCULATE As Integer = &H8000000F '算法或计算错误
    Public Const VIKEY_ERROR_MODULE As Integer = &H80000010 '计数器错误
    Public Const VIKEY_ERROR_GENERATE_NEW_PASSWORD As Integer = &H80000011 '产生密码错误
    Public Const VIKEY_ERROR_ENCRYPT_FAILED As Integer = &H80000012 '加密数据错误
    Public Const VIKEY_ERROR_DECRYPT_FAILED As Integer = &H80000013 '解密数据错误
    Public Const VIKEY_ERROR_ALREADY_LOCKED As Integer = &H80000014 'ViKey加密锁已经被锁定
    Public Const VIKEY_ERROR_UNKNOWN_COMMAND As Integer = &H80000015 '无效的命令
    Public Const VIKEY_ERROR_UNKNOWN_ERROR As Integer = &HFFFFFFFF '未知错误

    Declare Function VikeyFind Lib "ViKey.DLL" (ByRef Count As Integer) As Integer
    Declare Function VikeyGetHID Lib "ViKey.DLL" (ByVal Index As Integer, ByRef pHID As Integer) As Integer

    Declare Function VikeyUserLogin Lib "ViKey.DLL" (ByVal Index As Integer, ByVal UserPassWord() As Byte) As Integer
    Declare Function VikeyAdminLogin Lib "ViKey.DLL" (ByVal Index As Integer, ByVal AdminPassWord() As Byte) As Integer
    Declare Function VikeyLogoff Lib "ViKey.DLL" (ByVal Index As Integer) As Integer

    Declare Function VikeySetSoftIDString Lib "ViKey.DLL" (ByVal Index As Integer, ByVal SoftID() As Byte) As Integer
    Declare Function VikeyGetSoftIDString Lib "ViKey.DLL" (ByVal Index As Integer, ByVal lpSoftID() As Byte) As Integer
    Declare Function VikeyReadData Lib "ViKey.DLL" (ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByVal buffer() As Byte) As Integer
    Declare Function VikeyWriteData Lib "ViKey.DLL" (ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByVal buffer() As Byte) As Integer
    Declare Function ViKeyRandom Lib "ViKey.DLL" (ByVal Index As Integer, ByRef p1 As Integer, ByRef p2 As Integer, ByRef p3 As Integer, ByRef p4 As Integer) As Integer
    Declare Function VikeyResetPassword Lib "ViKey.DLL" (ByVal Index As Integer, ByVal NewUserPassWord As String, ByVal NewAdminPassWord As String) As Integer

    Declare Function VikeyDesEncrypt Lib "ViKey.DLL" (ByVal Index As Integer, ByVal InLength As Integer, ByVal pText() As Byte, ByVal pResult() As Byte, ByRef OutLength As Integer) As Integer
    Declare Function VikeyDesDecrypt Lib "ViKey.DLL" (ByVal Index As Integer, ByVal InLength As Integer, ByVal pText() As Byte, ByVal pResult() As Byte, ByRef OutLength As Integer) As Integer

End Module