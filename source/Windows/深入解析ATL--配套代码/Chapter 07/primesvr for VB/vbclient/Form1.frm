VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   1800
      TabIndex        =   0
      Top             =   1200
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
    Dim primes As IPrimeNumbers
    Set primes = New PrimeNumbers
    primes.CalcPrimes 0, 1000
    
    MsgBox "Primes: " & primes.Count
    
    Dim sPrimes As String
    Dim prime As Variant
    For Each prime In primes
        sPrimes = sPrimes & prime & " "
    Next prime
    
    'Dim i As Long
    'For i = 1 To primes.Count
    '    sPrimes = sPrimes & primes(i) & " "
    'Next i
    
    MsgBox sPrimes
End Sub
