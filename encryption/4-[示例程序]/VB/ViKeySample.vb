Option Strict Off
Option Explicit On
Friend Class ViKeySample
    Inherits System.Windows.Forms.Form

    Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
        Dim Index As Integer
        Dim Data1, Data2, Data3, Data4 As Integer
        Dim HID, Count, retcode As Integer
        Dim addr, len As Integer
        Dim buffer(4096) As Byte
        Dim curline As Short
        Dim i, j As Integer

        Dim UserPassWord(8) As Byte
        Dim AdminPassWord(8) As Byte
        Dim SoftID(8) As Byte
        Dim DataString As String
        Index = 0

        List1.Items.Clear()
        curline = 0
        VB6.SetItemString(List1, curline, "*******ViKey加密狗VB调用示例*******")
        curline = curline + 1

        Index = 0

        'find ViKey
        retcode = VikeyFind(Count)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "查找加密狗错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If

        VB6.SetItemString(List1, curline, "查找到加密狗个数:" & Count & Chr(13))
        curline = curline + 1

        retcode = VikeyGetHID(Index, HID)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "获取加密狗硬件ID:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If

        VB6.SetItemString(List1, curline, "获取加密狗硬件ID " & HID & Chr(13))
        curline = curline + 1

        'user logon ViKey
        '用户默认密码为8个字符1
        UserPassWord = System.Text.Encoding.Default.GetBytes("11111111")
        retcode = VikeyUserLogin(Index, UserPassWord)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "用户权限登陆加密狗错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If
        VB6.SetItemString(List1, curline, "用户权限登陆加密狗成功: " & Chr(13))
        curline = curline + 1

        'admin logon ViKey
        '管理员默认密码为8个字符0
        AdminPassWord = System.Text.Encoding.Default.GetBytes("00000000")
        retcode = VikeyAdminLogin(Index, AdminPassWord)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "管理员权限登陆加密狗错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If
        VB6.SetItemString(List1, curline, "管理员权限登陆加密狗成功: " & Chr(13))
        curline = curline + 1

        'Set SoftID 
        SoftID = System.Text.Encoding.Default.GetBytes("1234ABCD")
        retcode = VikeySetSoftIDString(Index, SoftID)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "设置软件ID错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If
        VB6.SetItemString(List1, curline, "设置软件ID成功" & System.Text.Encoding.Default.GetString(buffer) & Chr(13))
        curline = curline + 1

        'Get SoftID 
        retcode = VikeyGetSoftIDString(Index, buffer)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "获取软件ID错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If

        DataString = ""
        For i = 0 To 7
            DataString += " "
            DataString += Hex(buffer(i)).ToString()
        Next

        VB6.SetItemString(List1, curline, "获取软件ID成功-字符串: " & System.Text.Encoding.Default.GetString(buffer) & Chr(13))
        curline = curline + 1
        VB6.SetItemString(List1, curline, "获取软件ID成功-16进制:" & DataString & Chr(13))
        curline = curline + 1


        'Get Hardware Random

        retcode = ViKeyRandom(Index, Data1, Data2, Data3, Data4)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "获取随机数错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If
        VB6.SetItemString(List1, curline, "获取随机数成功: " & Data1 & "-" & Data2 & "-" & Data3 & "-" & Data4 & Chr(13))
        curline = curline + 1

        'Write data to vikey
        addr = 0
        len = 8
        buffer(0) = &H31
        buffer(1) = &H32
        buffer(2) = &H33
        buffer(3) = &H34
        buffer(4) = &H35
        buffer(5) = &H36
        buffer(6) = &H37
        buffer(7) = &H38
        retcode = VikeyWriteData(Index, addr, len, buffer)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "写数据到加密狗错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If

        DataString = ""
        For i = 0 To len - 1
            DataString += " "
            DataString += Hex(buffer(i)).ToString()
        Next

        VB6.SetItemString(List1, curline, "写数据到加密狗成功-字符串: " & System.Text.Encoding.Default.GetString(buffer) & Chr(13))
        curline = curline + 1
        VB6.SetItemString(List1, curline, "写数据到加密狗成功-16进制:" & DataString & Chr(13))
        curline = curline + 1


        'Read data to vikey
        addr = 0
        len = 8
        retcode = VikeyReadData(Index, addr, len, buffer)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "读数据到加密狗错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If
        DataString = ""
        For i = 0 To len - 1
            DataString += " "
            DataString += Hex(buffer(i)).ToString()
        Next

        VB6.SetItemString(List1, curline, "读取数据成功-字符串: " & System.Text.Encoding.Default.GetString(buffer) & Chr(13))
        curline = curline + 1
        VB6.SetItemString(List1, curline, "读取数据成功-16进制:" & DataString & Chr(13))
        curline = curline + 1

        retcode = VikeyLogoff(Index)
        If (retcode <> 0) Then
            VB6.SetItemString(List1, curline, "注销加密狗错误:" & Hex(retcode) & Chr(13))
            curline = curline + 1
            Exit Sub
        End If
        VB6.SetItemString(List1, curline, "注销加密狗成功！ " & Chr(13))
        curline = curline + 1

    End Sub

    Private Sub List1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles List1.SelectedIndexChanged

    End Sub
End Class