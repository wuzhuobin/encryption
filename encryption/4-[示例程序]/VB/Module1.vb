Option Strict Off
Option Explicit On
Module Module1
	

    'Error Code
    Public Const VIKEY_SUCCESS As Integer = &H0  '�ɹ�
    Public Const VIKEY_ERROR_NO_VIKEY As Integer = &H80000001 'û���ҵ�ViKey������
    Public Const VIKEY_ERROR_INVALID_PASSWORD As Integer = &H80000002 '�������
    Public Const VIKEY_ERROR_NEED_FIND As Integer = &H80000003 '���Ȳ��Ҽ�����
    Public Const VIKEY_ERROR_INVALID_INDEX As Integer = &H80000004 '��Ч�ľ��
    Public Const VIKEY_ERROR_INVALID_VALUE As Integer = &H80000005 '��ȡ��Ϣ����
    Public Const VIKEY_ERROR_INVALID_KEY As Integer = &H80000006 '��Կ��Ч
    Public Const VIKEY_ERROR_GET_VALUE As Integer = &H80000007 '��ȡ��Ϣ����
    Public Const VIKEY_ERROR_SET_VALUE As Integer = &H80000008 '������Ϣ����
    Public Const VIKEY_ERROR_NO_CHANCE As Integer = &H80000009 'û�л���
    Public Const VIKEY_ERROR_NO_TAUTHORITY As Integer = &H8000000A 'Ȩ�޲���
    Public Const VIKEY_ERROR_INVALID_ADDR_OR_SIZE As Integer = &H8000000B '��ַ�򳤶ȴ���
    Public Const VIKEY_ERROR_RANDOM As Integer = &H8000000C '��ȡ���������
    Public Const VIKEY_ERROR_SEED As Integer = &H8000000D '��ȡ���Ӵ���
    Public Const VIKEY_ERROR_CONNECTION As Integer = &H8000000E 'ͨ�Ŵ���
    Public Const VIKEY_ERROR_CALCULATE As Integer = &H8000000F '�㷨��������
    Public Const VIKEY_ERROR_MODULE As Integer = &H80000010 '����������
    Public Const VIKEY_ERROR_GENERATE_NEW_PASSWORD As Integer = &H80000011 '�����������
    Public Const VIKEY_ERROR_ENCRYPT_FAILED As Integer = &H80000012 '�������ݴ���
    Public Const VIKEY_ERROR_DECRYPT_FAILED As Integer = &H80000013 '�������ݴ���
    Public Const VIKEY_ERROR_ALREADY_LOCKED As Integer = &H80000014 'ViKey�������Ѿ�������
    Public Const VIKEY_ERROR_UNKNOWN_COMMAND As Integer = &H80000015 '��Ч������
    Public Const VIKEY_ERROR_UNKNOWN_ERROR As Integer = &HFFFFFFFF 'δ֪����

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