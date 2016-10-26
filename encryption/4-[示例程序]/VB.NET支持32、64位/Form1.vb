Imports System.Runtime.InteropServices
Public Class Form1
    Inherits System.Windows.Forms.Form


#Region " Windows  "

    Public Sub New()
        MyBase.New()


        InitializeComponent()



    End Sub


    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub


    Private components As System.ComponentModel.IContainer


    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents RichTextBox1 As System.Windows.Forms.RichTextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox()
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(172, 307)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(88, 32)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "Test"
        '
        'RichTextBox1
        '
        Me.RichTextBox1.Location = New System.Drawing.Point(12, 12)
        Me.RichTextBox1.Name = "RichTextBox1"
        Me.RichTextBox1.Size = New System.Drawing.Size(412, 289)
        Me.RichTextBox1.TabIndex = 1
        Me.RichTextBox1.Text = ""
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 14)
        Me.ClientSize = New System.Drawing.Size(436, 347)
        Me.Controls.Add(Me.RichTextBox1)
        Me.Controls.Add(Me.Button1)
        Me.Name = "Form1"
        Me.Text = "ViKey Sample VB.Net"
        Me.ResumeLayout(False)

    End Sub

#End Region


    '������
    Const VIKEY_SUCCESS = &H0  '�ɹ�
    Const VIKEY_ERROR_NO_VIKEY = &H80000001 'û���ҵ�ViKey���ܹ�
    Const VIKEY_ERROR_INVALID_PASSWORD = &H80000002 '�������
    Const VIKEY_ERROR_NEED_FIND = &H80000003 '���Ȳ��Ҽ��ܹ�
    Const VIKEY_ERROR_INVALID_INDEX = &H80000004 '��Ч�ľ��
    Const VIKEY_ERROR_INVALID_VALUE = &H80000005 '��ȡ��Ϣ����
    Const VIKEY_ERROR_INVALID_KEY = &H80000006 '��Կ��Ч
    Const VIKEY_ERROR_GET_VALUE = &H80000007 '��ȡ��Ϣ����
    Const VIKEY_ERROR_SET_VALUE = &H80000008 '������Ϣ����
    Const VIKEY_ERROR_NO_CHANCE = &H80000009 'û�л���
    Const VIKEY_ERROR_NO_TAUTHORITY = &H8000000A 'Ȩ�޲���
    Const VIKEY_ERROR_INVALID_ADDR_OR_SIZE = &H8000000B '��ַ�򳤶ȴ���
    Const VIKEY_ERROR_RANDOM = &H8000000C '��ȡ���������
    Const VIKEY_ERROR_SEED = &H8000000D '��ȡ���Ӵ���
    Const VIKEY_ERROR_CONNECTION = &H8000000E 'ͨ�Ŵ���
    Const VIKEY_ERROR_CALCULATE = &H8000000F '�㷨��������
    Const VIKEY_ERROR_MODULE = &H80000010 '����������
    Const VIKEY_ERROR_GENERATE_NEW_PASSWORD = &H80000011 '�����������
    Const VIKEY_ERROR_ENCRYPT_FAILED = &H80000012 '�������ݴ���
    Const VIKEY_ERROR_DECRYPT_FAILED = &H80000013 '�������ݴ���
    Const VIKEY_ERROR_ALREADY_LOCKED = &H80000014 'ViKey���ܹ��Ѿ�������
    Const VIKEY_ERROR_UNKNOWN_COMMAND = &H80000015 '��Ч������
    Const VIKEY_ERROR_UNKNOWN_ERROR = &HFFFFFFFF 'δ֪����


    '���ܹ�

    <DllImport("kernel32.dll")> _
    Private Shared Function LoadLibrary(ByVal DllName As String) As IntPtr
    End Function

    <DllImport("kernel32")> _
    Private Shared Function FreeLibrary(ByVal hModule As IntPtr) As Boolean
    End Function

    <DllImport("kernel32.dll")> _
    Private Shared Function GetProcAddress(ByVal hModule As IntPtr, ByVal ProcName As String) As IntPtr
    End Function

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyFindType(ByRef Count As Integer) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyGetHIDType(ByVal Index As Integer, ByRef pHID As Integer) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyUserLoginType(ByVal Index As Integer, ByVal UserPassword As String) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyAdminLoginType(ByVal Index As Integer, ByVal AdminPassword As String) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyLogoffType(ByVal Index As Integer) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyResetPasswordType(ByVal Index As Integer, ByRef NewUserPassword As Byte, ByRef AdminUserPassword As Byte) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeySetSoftIDStringType(ByVal Index As Integer, ByVal SoftID As String) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyGetSoftIDStringType(ByVal Index As Integer, ByVal lpSoftID As System.Text.StringBuilder) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyReadDataType(ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByVal buffer As System.Text.StringBuilder) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function VikeyWriteDataType(ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByVal buffer As String) As Integer

    <UnmanagedFunctionPointer(CallingConvention.StdCall)> _
    Private Delegate Function ViKeyRandomType(ByVal Index As Integer, ByRef p1 As Integer, ByRef p2 As Integer, ByRef p3 As Integer, ByRef p4 As Integer) As Integer

    Private hTod As IntPtr

    Private Shared VikeyFind As VikeyFindType
    Private Shared VikeyGetHID As VikeyGetHIDType
    Private Shared VikeyUserLogin As VikeyUserLoginType
    Private Shared VikeyAdminLogin As VikeyAdminLoginType
    Private Shared VikeyLogoff As VikeyLogoffType
    Private Shared VikeyResetPassword As VikeyResetPasswordType

    Private Shared VikeySetSoftIDString As VikeySetSoftIDStringType
    Private Shared VikeyGetSoftIDString As VikeyGetSoftIDStringType
    Private Shared VikeyReadData As VikeyReadDataType
    Private Shared VikeyWriteData As VikeyWriteDataType
    Private Shared ViKeyRandom As ViKeyRandomType

    'Declare Function VikeyFind Lib "API.DLL" (ByRef Count As Integer) As Integer
    'Declare Function VikeyGetHID Lib "API.DLL" (ByVal Index As Integer, ByRef pHID As Integer) As Integer

    'Declare Function VikeyUserLogin Lib "API.DLL" (ByVal Index As Integer, ByRef UserPassword As Byte) As Integer
    'Declare Function VikeyAdminLogin Lib "API.DLL" (ByVal Index As Integer, ByRef AdminPassword As Byte) As Integer
    'Declare Function VikeyLogoff Lib "API.DLL" (ByVal Index As Integer) As Integer
    'Declare Function VikeyResetPassword Lib "API.DLL" (ByVal Index As Integer, ByRef NewUserPassword As Byte, ByRef AdminUserPassword As Byte) As Integer

    'Declare Function VikeySetSoftIDString Lib "API.DLL" (ByVal Index As Integer, ByRef SoftID As Byte) As Integer
    'Declare Function VikeyGetSoftIDString Lib "API.DLL" (ByVal Index As Integer, ByRef lpSoftID As Byte) As Integer
    'Declare Function VikeyReadData Lib "API.DLL" (ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByRef buffer As Byte) As Integer
    'Declare Function VikeyWriteData Lib "API.DLL" (ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByRef buffer As Byte) As Integer
    'Declare Function ViKeyRandom Lib "API.DLL" (ByVal Index As Integer, ByRef p1 As Integer, ByRef p2 As Integer, ByRef p3 As Integer, ByRef p4 As Integer) As Integer
    '���ܹ�




    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        RichTextBox1.Text = ""
        Dim Index As Integer
        Dim i, j As Integer
        Dim Data1, Data2, Data3, Data4 As Integer
        Dim HID, Count, retcode As Integer
        Dim addr, len As Integer
        Dim buffer(4096) As Byte      'allocat space here
        Dim tmp() As Byte
        Dim str As String
        Dim PassWord As String = "11111111"
        Dim SoftIDString As String = "11223344"
        Dim DataString As String = "aabbccdd"

        Dim RetSoftIDBuffer = New System.Text.StringBuilder(255)
        Dim RetDataBuffer = New System.Text.StringBuilder(255)



        Index = 0

        'find ViKey
        retcode = VikeyFind(Count)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("���Ҽ��ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If

        RichTextBox1.AppendText("���ҵ����ܹ�����:" & Count & Chr(13))

        retcode = VikeyGetHID(Index, HID)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("��ȡ���ܹ�Ӳ��ID:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If

        RichTextBox1.AppendText("��ȡ���ܹ�Ӳ��ID " & HID & Chr(13))

        'user logon ViKey
        '�û�Ĭ������Ϊ8���ַ�1
        PassWord = "11111111"
        retcode = VikeyUserLogin(Index, PassWord)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("�û�Ȩ�޵�½���ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("�û�Ȩ�޵�½���ܹ��ɹ�: " & Chr(13))

        'admin logon ViKey
        '����ԱĬ������Ϊ8���ַ�0
        PassWord = "000000000"
        retcode = VikeyAdminLogin(Index, PassWord)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("����ԱȨ�޵�½���ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("����ԱȨ�޵�½���ܹ��ɹ�: " & Chr(13))

        'Set SoftID 
        retcode = VikeySetSoftIDString(Index, SoftIDString)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("�������ID����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("�������ID�ɹ���" & SoftIDString)
        RichTextBox1.AppendText(Chr(13))

        'Get SoftID   
        RetSoftIDBuffer.Length = 8
        retcode = VikeyGetSoftIDString(Index, RetSoftIDBuffer)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("��ȡ���ID����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("��ȡ���ID�ɹ�:" & RetSoftIDBuffer.ToString() & Chr(13))


        addr = 0
        len = 8
        retcode = VikeyWriteData(Index, addr, len, DataString)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("д���ݵ����ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("д���ݵ����ܹ��ɹ�: " & DataString & Chr(13))


        'Read data to vikey
        addr = 0
        len = 8
        RetDataBuffer.Length = len
        retcode = VikeyReadData(Index, addr, len, RetDataBuffer)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("�����ݵ����ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If

        RichTextBox1.AppendText("�����ݵ����ܹ��ɹ�:" & RetDataBuffer.ToString() & Chr(13))



        'retcode = VikeyLogoff(Index)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("ע�����ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("ע�����ܹ��ɹ��� " & Chr(13))

    End Sub

    Private Sub RichTextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RichTextBox1.TextChanged

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        '���ܹ�
        If (IntPtr.Size = 4) Then
            Me.hTod = Form1.LoadLibrary("ViKey32.dll")
            RichTextBox1.AppendText("32λ���У� " & Chr(13))

        ElseIf (IntPtr.Size = 8) Then
            Me.hTod = Form1.LoadLibrary("ViKey64.dll")
            RichTextBox1.AppendText("64λ���У� " & Chr(13))

        End If

        VikeyFind = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyFind"), GetType(VikeyFindType)), VikeyFindType)
        VikeyGetHID = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyGetHID"), GetType(VikeyGetHIDType)), VikeyGetHIDType)
        VikeyUserLogin = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyUserLogin"), GetType(VikeyUserLoginType)), VikeyUserLoginType)
        VikeyAdminLogin = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyAdminLogin"), GetType(VikeyAdminLoginType)), VikeyAdminLoginType)
        VikeyLogoff = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyLogoff"), GetType(VikeyLogoffType)), VikeyLogoffType)
        VikeyResetPassword = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyResetPassword"), GetType(VikeyResetPasswordType)), VikeyResetPasswordType)

        VikeySetSoftIDString = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeySetSoftIDString"), GetType(VikeySetSoftIDStringType)), VikeySetSoftIDStringType)
        VikeyGetSoftIDString = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyGetSoftIDString"), GetType(VikeyGetSoftIDStringType)), VikeyGetSoftIDStringType)
        VikeyReadData = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyReadData"), GetType(VikeyReadDataType)), VikeyReadDataType)
        VikeyWriteData = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "VikeyWriteData"), GetType(VikeyWriteDataType)), VikeyWriteDataType)
        ViKeyRandom = DirectCast(Marshal.GetDelegateForFunctionPointer(GetProcAddress(hTod, "ViKeyRandom"), GetType(ViKeyRandomType)), ViKeyRandomType)
        '���ܹ�
    End Sub
End Class

