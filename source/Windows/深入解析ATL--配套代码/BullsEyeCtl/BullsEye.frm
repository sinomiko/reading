VERSION 5.00
Object = "{C8B7D8C8-8D62-11D2-BD9C-00A0C9C8E50D}#1.0#0"; "BullsEyeCtl.dll"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   3135
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   4680
   FillStyle       =   2  'Horizontal Line
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3135
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Help About"
      Default         =   -1  'True
      Height          =   1095
      Left            =   120
      TabIndex        =   0
      Top             =   1800
      Width           =   615
   End
   Begin BullsEyeLibCtl.BullsEye BullsEye1 
      Height          =   2895
      Left            =   840
      Top             =   120
      Width           =   3735
      _cx             =   6588
      _cy             =   5106
      BackStyle       =   0
      Beep            =   -1  'True
      Enabled         =   -1  'True
      RingCount       =   5
      AlternateColor  =   0
      BackColor       =   -2147483633
      CenterColor     =   255
      ForeColor       =   -2147483630
      RingValue1      =   512
      RingValue2      =   256
      RingValue3      =   128
      RingValue4      =   64
      RingValue5      =   32
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub BullsEye1_OnRingHit(ByVal ringNumber As Integer)
    MsgBox "Ring " & ringNumber & " hit"
End Sub

Private Sub Command1_Click()
    BullsEye1.AboutBox
End Sub

