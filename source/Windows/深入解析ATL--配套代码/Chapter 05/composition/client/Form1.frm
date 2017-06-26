VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2556
   ClientLeft      =   48
   ClientTop       =   276
   ClientWidth     =   3744
   LinkTopic       =   "Form1"
   ScaleHeight     =   2556
   ScaleWidth      =   3744
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   372
      Left            =   1440
      TabIndex        =   0
      Top             =   1080
      Width           =   972
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim ace As AcePowell

Private Sub Command1_Click()
    Dim artist As IArtist
    Set artist = ace
    artist.Draw
    
    Dim cowboy As ICowboy
    Set cowboy = ace
    cowboy.Draw
    
    Dim cbex As ICowboyEx
    Set cbex = cowboy
    cbex.Draw
    cbex.QuickDraw
    
    Set artist = cbex
    artist.Draw
End Sub

Private Sub Form_Load()
    Set ace = New AcePowell
End Sub
