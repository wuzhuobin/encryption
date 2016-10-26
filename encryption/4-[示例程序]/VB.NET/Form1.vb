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

    '加密狗类型
    Const ViKeyAPP = &H0                    '实用型加密狗
    Const ViKeySTD = &H1                    '标准型加密狗
    Const ViKeyNET = &H2                    '网络型加密狗
    Const ViKeyPRO = &H3                    '专业型加密狗
    Const ViKeyWEB = &H4                    '身份认证型加密狗
    Const ViKeyTIME = &H5                   '时钟型加密狗，内部独立时钟
    Const ViKeyMultiFunctional = &HA   '多功能加密狗  支持软件加密 支持文档加密
    
    '错误码
    Const VIKEY_SUCCESS = &H0  '成功
    Const VIKEY_ERROR_NO_VIKEY = &H80000001 '没有找到ViKey加密狗
    Const VIKEY_ERROR_INVALID_PASSWORD = &H80000002 '密码错误
    Const VIKEY_ERROR_NEED_FIND = &H80000003 '请先查找加密狗
    Const VIKEY_ERROR_INVALID_INDEX = &H80000004 '无效的句柄
    Const VIKEY_ERROR_INVALID_VALUE = &H80000005 '读取信息错误
    Const VIKEY_ERROR_INVALID_KEY = &H80000006 '秘钥无效
    Const VIKEY_ERROR_GET_VALUE = &H80000007 '读取信息错误
    Const VIKEY_ERROR_SET_VALUE = &H80000008 '设置信息错误
    Const VIKEY_ERROR_NO_CHANCE = &H80000009 '没有机会
    Const VIKEY_ERROR_NO_TAUTHORITY = &H8000000A '权限不足
    Const VIKEY_ERROR_INVALID_ADDR_OR_SIZE = &H8000000B '地址或长度错误
    Const VIKEY_ERROR_RANDOM = &H8000000C '获取随机数错误
    Const VIKEY_ERROR_SEED = &H8000000D '获取种子错误
    Const VIKEY_ERROR_CONNECTION = &H8000000E '通信错误
    Const VIKEY_ERROR_CALCULATE = &H8000000F '算法或计算错误
    Const VIKEY_ERROR_MODULE = &H80000010 '计数器错误
    Const VIKEY_ERROR_GENERATE_NEW_PASSWORD = &H80000011 '产生密码错误
    Const VIKEY_ERROR_ENCRYPT_FAILED = &H80000012 '加密数据错误
    Const VIKEY_ERROR_DECRYPT_FAILED = &H80000013 '解密数据错误
    Const VIKEY_ERROR_ALREADY_LOCKED = &H80000014 'ViKey加密狗已经被锁定
    Const VIKEY_ERROR_UNKNOWN_COMMAND = &H80000015 '无效的命令
    Const VIKEY_ERROR_UNKNOWN_ERROR = &HFFFFFFFF '未知错误

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
            RichTextBox1.AppendText("查找加密狗错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If

        RichTextBox1.AppendText("查找到加密狗个数:" & Count & Chr(13))

        retcode = VikeyGetHID(Index, HID)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("获取加密狗硬件ID:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If

        RichTextBox1.AppendText("获取加密狗硬件ID " & HID & Chr(13))

        'user logon ViKey
        '用户默认密码为8个字符1
        PassWord = "11111111"
        retcode = VikeyUserLogin(Index, PassWord)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("用户权限登陆加密狗错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("用户权限登陆加密狗成功: " & Chr(13))

        'admin logon ViKey
        '管理员默认密码为8个字符0
        PassWord = "000000000"
        retcode = VikeyAdminLogin(Index, PassWord)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("管理员权限登陆加密狗错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("管理员权限登陆加密狗成功: " & Chr(13))

        'Set SoftID 
        retcode = VikeySetSoftIDString(Index, SoftIDString)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("设置软件ID错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("设置软件ID成功：" & SoftIDString)
        RichTextBox1.AppendText(Chr(13))

        'Get SoftID 
        RetSoftIDBuffer.Length = 8
        retcode = VikeyGetSoftIDString(Index, RetSoftIDBuffer)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("获取软件ID错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("获取软件ID成功:" & RetSoftIDBuffer.ToString() & Chr(13))


        retcode = VikeyGetType(Index, vikeytype)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("获取加密狗类型错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        If (vikeytype = ViKeyTIME) Then
            RichTextBox1.AppendText("此加密狗是时钟型加密狗" & Chr(13))

            retcode = VikeyGetTime(Index, time(0))
            If (retcode <> 0) Then
                RichTextBox1.AppendText("获取加密狗时间错误:" & Hex(retcode) & Chr(13))
                Exit Sub
            End If
            RichTextBox1.AppendText("加密狗时间: " & time(0) & "年" & time(1) & "月" & time(2) & "日" & time(3) & "时" & time(3) & "分" & time(3) & "秒" & Chr(13))


        End If


        'Get Hardware Random

        retcode = ViKeyRandom(Index, Data1, Data2, Data3, Data4)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("获取随机数错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("获取随机数成功: " & Data1 & "-" & Data2 & "-" & Data3 & "-" & Data4 & Chr(13))

        'Write data to vikey
        addr = 0
        len = 8
        retcode = VikeyWriteData(Index, addr, len, DataString)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("写数据到加密狗错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("写数据到加密狗成功: " & DataString & Chr(13))


        'Read data to vikey
        addr = 0
        len = 8
        RetDataBuffer.Length = len
        retcode = VikeyReadData(Index, addr, len, RetDataBuffer)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("读数据到加密狗错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If

        RichTextBox1.AppendText("读数据到加密狗成功:" & RetDataBuffer.ToString() & Chr(13))

        retcode = VikeyLogoff(Index)
        If (retcode <> 0) Then
            RichTextBox1.AppendText("注销加密狗错误:" & Hex(retcode) & Chr(13))
            Exit Sub
        End If
        RichTextBox1.AppendText("注销加密狗成功！ " & Chr(13))

    End Sub

    Private Sub RichTextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RichTextBox1.TextChanged

    End Sub
End Class

