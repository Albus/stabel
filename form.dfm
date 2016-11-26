object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'Form2'
  ClientHeight = 816
  ClientWidth = 1097
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Padding.Left = 50
  Padding.Top = 50
  Padding.Right = 50
  Padding.Bottom = 50
  OldCreateOrder = False
  Position = poDesigned
  PrintScale = poPrintToFit
  WindowState = wsMaximized
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    AlignWithMargins = True
    Left = 50
    Top = 224
    Width = 997
    Height = 80
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 50
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    AllowAllUp = True
    GroupIndex = 1
    Caption = '>> '#1053#1054#1063#1053#1040#1071'/'#1044#1053#1045#1042#1053#1040#1071' '#1057#1052#1045#1053#1040' <<'
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -53
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    OnClick = SpeedButton1Click
    ExplicitLeft = 20
    ExplicitTop = 126
    ExplicitWidth = 595
  end
  object Label1: TLabel
    AlignWithMargins = True
    Left = 50
    Top = 354
    Width = 997
    Height = 39
    Margins.Left = 0
    Margins.Top = 50
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Alignment = taCenter
    Caption = 'Label1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -32
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 106
  end
  object dxStatusBar1: TdxStatusBar
    Left = 50
    Top = 746
    Width = 997
    Height = 20
    Panels = <
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Color = clBtnFace
        PanelStyle.Font.Charset = DEFAULT_CHARSET
        PanelStyle.Font.Color = clRed
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Tahoma'
        PanelStyle.Font.Style = []
        PanelStyle.ParentFont = False
        Text = 'VPN'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Font.Charset = DEFAULT_CHARSET
        PanelStyle.Font.Color = clRed
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Tahoma'
        PanelStyle.Font.Style = []
        PanelStyle.ParentFont = False
        Text = 'WWW'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Font.Charset = DEFAULT_CHARSET
        PanelStyle.Font.Color = clRed
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Tahoma'
        PanelStyle.Font.Style = []
        PanelStyle.ParentFont = False
        Text = '----'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
      end>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
  end
  object Shtrih: TEdit
    AlignWithMargins = True
    Left = 50
    Top = 50
    Width = 997
    Height = 124
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Alignment = taCenter
    AutoSelect = False
    BorderStyle = bsNone
    CharCase = ecUpperCase
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -96
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    MaxLength = 13
    NumbersOnly = True
    ParentFont = False
    TabOrder = 1
    TextHint = #1064#1058#1056#1048#1061'-'#1050#1054#1044
    OnChange = ShtrihChange
  end
  object ButtonGo: TButton
    AlignWithMargins = True
    Left = 50
    Top = 443
    Width = 997
    Height = 100
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 50
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Constraints.MaxHeight = 100
    Constraints.MinHeight = 100
    Default = True
    Enabled = False
    TabOrder = 2
  end
  object ButtonClose: TButton
    AlignWithMargins = True
    Left = 50
    Top = 596
    Width = 997
    Height = 100
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 50
    Align = alBottom
    Cancel = True
    Caption = #1047#1040#1050#1056#1067#1058#1068' '#1055#1056#1054#1043#1056#1040#1052#1052#1059
    Constraints.MaxHeight = 100
    Constraints.MinHeight = 100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -53
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    TabStop = False
    OnClick = ButtonCloseClick
  end
  object Connection: TPgConnection
    LoginPrompt = False
    Left = 1032
  end
  object PgQuery: TPgQuery
    Connection = Connection
    Left = 944
  end
end
