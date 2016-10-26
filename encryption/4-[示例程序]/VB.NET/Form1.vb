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
        Me.Button1 = New System.Windows.Forms.Button
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox
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

    '���ܹ�����
    Const ViKeyAPP = &H0                    'ʵ���ͼ��ܹ�
    Const ViKeySTD = &H1                    '��׼�ͼ��ܹ�
    Const ViKeyNET = &H2                    '�����ͼ��ܹ�
    Const ViKeyPRO = &H3                    'רҵ�ͼ��ܹ�
    Const ViKeyWEB = &H4                    '�����֤�ͼ��ܹ�
    Const ViKeyTIME = &H5                   'ʱ���ͼ��ܹ����ڲ�����ʱ��
    Const ViKeyMultiFunctional = &HA   '�๦�ܼ��ܹ�  ֧��������� ֧���ĵ�����
    
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

    Declare Function VikeyFind Lib "ViKey.DLL" (ByRef Count As Integer) As Integer
    Declare Function VikeyGetHID Lib "ViKey.DLL" (ByVal Index As Integer, ByRef pHID As Integer) As Integer
    Declare Function VikeyGetType Lib "ViKey.DLL" (ByVal Index As Integer, ByRef pType As Byte) As Integer

    Declare Function VikeyUserLogin Lib "ViKey.DLL" (ByVal Index As Integer, ByVal UserPassword() As Byte) As Integer
    Declare Function VikeyAdminLogin Lib "ViKey.DLL" (ByVal Index As Integer, ByVal AdminPassword() As Byte) As Integer
    Declare Function VikeyLogoff Lib "ViKey.DLL" (ByVal Index As Integer) As Integer
    Declare Function VikeyResetPassword Lib "ViKey.DLL" (ByVal Index As Integer, ByRef NewUserPassword As Byte, ByRef AdminUserPassword As Byte) As Integer

    Declare Function VikeySetSoftIDString Lib "ViKey.DLL" (ByVal Index As Integer, ByVal SoftID() As Byte) As Integer
    Declare Function VikeyGetSoftIDString Lib "ViKey.DLL" (ByVal Index As Integer, ByVal lpSoftID() As Byte) As Integer
    Declare Function VikeyReadData Lib "ViKey.DLL" (ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByVal buffer() As Byte) As Integer
    Declare Function VikeyWriteData Lib "ViKey.DLL" (ByVal Index As Integer, ByVal Addr As Integer, ByVal Length As Integer, ByVal buffer() As Byte) As Integer
    Declare Function ViKeyRandom Lib "ViKey.DLL" (ByVal Index As Integer, ByRef p1 As Integer, ByRef p2 As Integer, ByRef p3 As Integer, ByRef p4 As Integer) As Integer

    Declare Function VikeyGetTime Lib "ViKey.DLL" (ByVal Index As Integer, ByRef buffer As Byte) As Integer



    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        RichTextBox1.Text = ""
        Dim Index As Integer
        Dim i, j As Integer
        Dim Data1, Data2, Data3, Data4 As Integer
        Dim HID, Count, retcode As Integer
        Dim addr, len As Integer
        Dim buffer(4096) As Byte      'allocat space here
        Dim time(6) As Byte      'allocat space here
        Dim tmp() As Byte
        Dim str As String
        Dim PassWord As String = "11111111"
        Dim vikeytype As Byte
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


        retcode = VikeyGetType(Index, vikeytype)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("��ȡ���ܹ����ʹ���:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        If (vikeytype = ViKeyTIME) Then
            RichTextBox1.AppendText("�˼��ܹ���ʱ���ͼ��ܹ�" & Chr(13))

            retcode = VikeyGetTime(Index, time(0))
            If (retcode <> 0) Then
                RichTextBox1.AppendText("��ȡ���ܹ�ʱ�����:" & Hex(retcode) & Chr(13))
                Exit Sub
            End If
            RichTextBox1.AppendText("���ܹ�ʱ��: " & time(0) & "��" & time(1) & "��" & time(2) & "��" & time(3) & "ʱ" & time(3) & "��" & time(3) & "��" & Chr(13))


        End If


        'Get Hardware Random

        retcode = ViKeyRandom(Index, Data1, Data2, Data3, Data4)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("��ȡ���������:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("��ȡ������ɹ�: " & Data1 & "-" & Data2 & "-" & Data3 & "-" & Data4 & Chr(13))

        'Write data to vikey
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

        retcode = VikeyLogoff(Index)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("ע�����ܹ�����:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("ע�����ܹ��ɹ��� " & Chr(13))

    End Sub

    Private Sub RichTextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RichTextBox1.TextChanged

    End Sub
End Class

