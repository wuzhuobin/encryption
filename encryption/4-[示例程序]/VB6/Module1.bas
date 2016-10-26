Attribute VB_Name = "Module1"

    'Error Code
    Public Const VIKEY_SUCCESS As Long = &H0  '�ɹ�
    Public Const VIKEY_ERROR_NO_VIKEY As Long = &H80000001 'û���ҵ�ViKey������
    Public Const VIKEY_ERROR_INVALID_PASSWORD As Long = &H80000002 '�������
    Public Const VIKEY_ERROR_NEED_FIND As Long = &H80000003 '���Ȳ��Ҽ�����
    Public Const VIKEY_ERROR_INVALID_INDEX As Long = &H80000004 '��Ч�ľ��
    Public Const VIKEY_ERROR_INVALID_VALUE As Long = &H80000005 '��ȡ��Ϣ����
    Public Const VIKEY_ERROR_INVALID_KEY As Long = &H80000006 '��Կ��Ч
    Public Const VIKEY_ERROR_GET_VALUE As Long = &H80000007 '��ȡ��Ϣ����
    Public Const VIKEY_ERROR_SET_VALUE As Long = &H80000008 '������Ϣ����
    Public Const VIKEY_ERROR_NO_CHANCE As Long = &H80000009 'û�л���
    Public Const VIKEY_ERROR_NO_TAUTHORITY As Long = &H8000000A 'Ȩ�޲���
    Public Const VIKEY_ERROR_INVALID_ADDR_OR_SIZE As Long = &H8000000B '��ַ�򳤶ȴ���
    Public Const VIKEY_ERROR_RANDOM As Long = &H8000000C '��ȡ���������
    Public Const VIKEY_ERROR_SEED As Long = &H8000000D '��ȡ���Ӵ���
    Public Const VIKEY_ERROR_CONNECTION As Long = &H8000000E 'ͨ�Ŵ���
    Public Const VIKEY_ERROR_CALCULATE As Long = &H8000000F '�㷨��������
    Public Const VIKEY_ERROR_MODULE As Long = &H80000010 '����������
    Public Const VIKEY_ERROR_GENERATE_NEW_PASSWORD As Long = &H80000011 '�����������
    Public Const VIKEY_ERROR_ENCRYPT_FAILED As Long = &H80000012 '�������ݴ���
    Public Const VIKEY_ERROR_DECRYPT_FAILED As Long = &H80000013 '�������ݴ���
    Public Const VIKEY_ERROR_ALREADY_LOCKED As Long = &H80000014 'ViKey�������Ѿ�������
    Public Const VIKEY_ERROR_UNKNOWN_COMMAND As Long = &H80000015 '��Ч������
    Public Const VIKEY_ERROR_UNKNOWN_ERROR As Long = &HFFFFFFFF 'δ֪����

    Declare Function VikeyFind Lib "ViKey.DLL" (ByRef Count As Long) As Long
    Declare Function VikeyGetHID Lib "ViKey.DLL" (ByVal Index As Integer, ByRef pHID As Long) As Long

    Declare Function VikeyUserLogin Lib "ViKey.DLL" (ByVal Index As Integer, ByRef UserPassWord As Byte) As Integer
    Declare Function VikeyAdminLogin Lib "ViKey.DLL" (ByVal Index As Integer, ByRef AdminPassWord As Byte) As Integer
    Declare Function VikeyLogoff Lib "ViKey.DLL" (ByVal Index As Integer) As Integer

    Declare Function VikeySetSoftIDString Lib "ViKey.DLL" (ByVal Index As Integer, ByRef SoftID As Byte) As Integer
    Declare Function VikeyGetSoftIDString Lib "ViKey.DLL" (ByVal Index As Integer, ByRef lpSoftID As Byte) As Integer
    Declare Function VikeyReadData Lib "ViKey.DLL" (ByVal Index As Integer, ByVal addr As Integer, ByVal length As Integer, ByRef buffer As Byte) As Long
    Declare Function VikeyWriteData Lib "ViKey.DLL" (ByVal Index As Integer, ByVal addr As Integer, ByVal length As Integer, ByRef buffer As Byte) As Long
    Declare Function ViKeyRandom Lib "ViKey.DLL" (ByVal Index As Integer, ByRef p1 As Integer, ByRef p2 As Integer, ByRef p3 As Integer, ByRef p4 As Integer) As Long
    Declare Function VikeyResetPassword Lib "ViKey.DLL" (ByVal Index As Integer, ByRef NewUserPassWord As Byte, ByRef NewAdminPassWord As Byte) As Integer

    Declare Function VikeyGetTime Lib "ViKey.DLL" (ByVal Index As Integer, ByRef buffer As Byte) As Long


