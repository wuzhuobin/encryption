<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> Partial Class ViKeySample
#Region "Windows 窗体设计器生成的代码 "
    <System.Diagnostics.DebuggerNonUserCode()> Public Sub New()
        MyBase.New()
        '此调用是 Windows 窗体设计器所必需的。
        InitializeComponent()
    End Sub
    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> Protected Overloads Overrides Sub Dispose(ByVal Disposing As Boolean)
        If Disposing Then
            If Not components Is Nothing Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(Disposing)
    End Sub
    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer
    Public ToolTip1 As System.Windows.Forms.ToolTip
    Public WithEvents Command1 As System.Windows.Forms.Button
    Public WithEvents List1 As System.Windows.Forms.ListBox
    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器来修改它。
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.ToolTip1 = New System.Windows.Forms.ToolTip(Me.components)
        Me.Command1 = New System.Windows.Forms.Button
        Me.List1 = New System.Windows.Forms.ListBox
        Me.SuspendLayout()
        '
        'Command1
        '
        Me.Command1.BackColor = System.Drawing.SystemColors.Control
        Me.Command1.Cursor = System.Windows.Forms.Cursors.Default
        Me.Command1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Command1.Location = New System.Drawing.Point(165, 292)
        Me.Command1.Name = "Command1"
        Me.Command1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Command1.Size = New System.Drawing.Size(113, 25)
        Me.Command1.TabIndex = 1
        Me.Command1.Text = "Test"
        Me.Command1.UseVisualStyleBackColor = False
        '
        'List1
        '
        Me.List1.BackColor = System.Drawing.SystemColors.Window
        Me.List1.Cursor = System.Windows.Forms.Cursors.Default
        Me.List1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.List1.ItemHeight = 16
        Me.List1.Location = New System.Drawing.Point(8, 8)
        Me.List1.Name = "List1"
        Me.List1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.List1.Size = New System.Drawing.Size(449, 276)
        Me.List1.TabIndex = 0
        '
        'ViKeySample
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.Control
        Me.ClientSize = New System.Drawing.Size(466, 329)
        Me.Controls.Add(Me.Command1)
        Me.Controls.Add(Me.List1)
        Me.Cursor = System.Windows.Forms.Cursors.Default
        Me.Font = New System.Drawing.Font("Tahoma", 10.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Location = New System.Drawing.Point(4, 24)
        Me.Name = "ViKeySample"
        Me.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Text = "ViKey加密锁VB调用示例"
        Me.ResumeLayout(False)

    End Sub
#End Region
End Class