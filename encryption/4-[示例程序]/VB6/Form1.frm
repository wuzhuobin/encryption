VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5385
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   7425
   LinkTopic       =   "Form1"
   ScaleHeight     =   5385
   ScaleWidth      =   7425
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   375
      Left            =   2640
      TabIndex        =   1
      Top             =   4800
      Width           =   1695
   End
   Begin VB.ListBox List1 
      Height          =   3765
      Left            =   480
      TabIndex        =   0
      Top             =   480
      Width           =   6615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
        Dim Index As Integer
        Dim i, j As Integer
        Dim Data1, Data2, Data3, Data4 As Integer
        Dim HID, Count, retcode As Long
        Dim SoftID, addr, length As Integer
        Dim buffer(4096) As Byte      'allocat space here
        Dim tmp() As Byte
        Dim str As String
        Dim strMsg As String

        Index = 0

        List1.Clear
        'find ViKey
        retcode = VikeyFind(Count)
        If (retcode <> 0) Then
            strMsg = "���Ҽ��ܹ�����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If

        strMsg = "���ҵ����ܹ�����:" & Count & Chr(13)
            List1.AddItem strMsg

        retcode = VikeyGetHID(Index, HID)
        If (retcode <> 0) Then
            strMsg = "��ȡ���ܹ�Ӳ��ID:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If

        strMsg = "��ȡ���ܹ�Ӳ��ID " & HID & Chr(13)
            List1.AddItem strMsg

        'user logon ViKey
        buffer(0) = &H31
        buffer(1) = &H31
        buffer(2) = &H31
        buffer(3) = &H31
        buffer(4) = &H31
        buffer(5) = &H31
        buffer(6) = &H31
        buffer(7) = &H31
        retcode = VikeyUserLogin(Index, buffer(0))
        If (retcode <> 0) Then
            strMsg = "�û�Ȩ�޵�½���ܹ�����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "�û�Ȩ�޵�½���ܹ��ɹ�: " & Chr(13)
            List1.AddItem strMsg

        'admin logon ViKey
        buffer(0) = &H30
        buffer(1) = &H30
        buffer(2) = &H30
        buffer(3) = &H30
        buffer(4) = &H30
        buffer(5) = &H30
        buffer(6) = &H30
        buffer(7) = &H30
        retcode = VikeyAdminLogin(Index, buffer(0))
        If (retcode <> 0) Then
            strMsg = "����ԱȨ�޵�½���ܹ�����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "����ԱȨ�޵�½���ܹ��ɹ�: " & Chr(13)
            List1.AddItem strMsg

        'Set SoftID
        buffer(0) = &H31
        buffer(1) = &H32
        buffer(2) = &H33
        buffer(3) = &H34
        buffer(4) = &H35
        buffer(5) = &H36
        buffer(6) = &H37
        buffer(7) = &H38
        retcode = VikeySetSoftIDString(Index, buffer(0))
        If (retcode <> 0) Then
            strMsg = "�������ID����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "�������ID�ɹ�: " + Chr(13)
            List1.AddItem strMsg

        'Get SoftID
        retcode = VikeyGetSoftIDString(Index, buffer(0))
        If (retcode <> 0) Then
            strMsg = "��ȡ���ID����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "��ȡ���ID�ɹ�: " & Chr(13)
            List1.AddItem strMsg


        'Get Hardware Random

        retcode = ViKeyRandom(Index, Data1, Data2, Data3, Data4)
        If (retcode <> 0) Then
            strMsg = "��ȡ���������:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "��ȡ������ɹ�: " & Data1 & "-" & Data2 & "-" & Data3 & "-" & Data4 & Chr(13)
            List1.AddItem strMsg

        'Write data to vikey
        addr = 0
        length = 4
        buffer(0) = 1
        buffer(1) = 2
        buffer(2) = 3
        buffer(3) = 4
        retcode = VikeyWriteData(Index, addr, length, buffer(0))
        If (retcode <> 0) Then
            strMsg = "д���ݵ����ܹ�����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "д���ݵ����ܹ��ɹ�: " & buffer(0) & "-" & buffer(1) & "-" & buffer(2) & "-" & buffer(3) & Chr(13)
            List1.AddItem strMsg


        'Read data to vikey
        addr = 0
        length = 4
        buffer(0) = 0
        buffer(1) = 0
        buffer(2) = 0
        buffer(3) = 0
        retcode = VikeyReadData(Index, addr, length, buffer(0))
        If (retcode <> 0) Then
            strMsg = "�����ݵ����ܹ�����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "�����ݵ����ܹ��ɹ�: " & buffer(0) & "-" & buffer(1) & "-" & buffer(2) & "-" & buffer(3) & Chr(13)
            List1.AddItem strMsg


        '��ȡ�����еĵ�ǰʱ�䣬ֻ��ʱ�ӹ���֧�ִ˹���
        'retcode = VikeyGetTime(Index, buffer(0))
        'If (retcode <> 0) Then
        '    strMsg = "��ȡ���ܹ��е�ʱ��:" & Hex(retcode) & Chr(13)
        '    List1.AddItem strMsg
        '    Exit Sub
        'End If
        'strMsg = "��ȡ���ܹ��е�ʱ��ɹ�: " & buffer(0) & "��" & buffer(1) & "��" & buffer(2) & "��" & buffer(3) & "ʱ" & buffer(4) & "��" & buffer(5) & "��" & Chr(13)
        '    List1.AddItem strMsg


        retcode = VikeyLogoff(Index)
        If (retcode <> 0) Then
            strMsg = "ע�����ܹ�����:" & Hex(retcode) & Chr(13)
            List1.AddItem strMsg
            Exit Sub
        End If
        strMsg = "ע�����ܹ��ɹ��� " & Chr(13)
            List1.AddItem strMsg
End Sub
