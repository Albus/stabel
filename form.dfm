object SelfTabel: TSelfTabel
  Left = 0
  Top = 0
  Margins.Left = 0
  Margins.Top = 0
  Margins.Right = 0
  Margins.Bottom = 0
  BorderStyle = bsNone
  Caption = 'SelfTabel'
  ClientHeight = 906
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
  OldCreateOrder = False
  Position = poDesigned
  PrintScale = poPrintToFit
  WindowState = wsMaximized
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    AlignWithMargins = True
    Left = 50
    Top = 425
    Width = 997
    Height = 39
    Margins.Left = 0
    Margins.Top = 50
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Alignment = taCenter
    Caption = #1053#1059#1046#1053#1054' '#1042#1042#1045#1057#1058#1048' '#1064#1058#1056#1048#1061'-'#1050#1054#1044
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -32
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 484
  end
  object LabelResult: TLabel
    AlignWithMargins = True
    Left = 50
    Top = 664
    Width = 997
    Height = 25
    Margins.Left = 0
    Margins.Top = 50
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ExplicitWidth = 7
  end
  object dxStatusBar1: TdxStatusBar
    Left = 50
    Top = 886
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
        PanelStyle.Alignment = taCenter
        PanelStyle.Font.Charset = DEFAULT_CHARSET
        PanelStyle.Font.Color = clWindowText
        PanelStyle.Font.Height = -9
        PanelStyle.Font.Name = 'Tahoma'
        PanelStyle.Font.Style = []
        PanelStyle.ParentFont = False
        MinWidth = 150
        Width = 150
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
    TabOrder = 2
    TextHint = #1064#1058#1056#1048#1061'-'#1050#1054#1044
    OnChange = ShtrihChange
  end
  object ButtonGo: TButton
    AlignWithMargins = True
    Left = 50
    Top = 514
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
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonGoClick
  end
  object ButtonClose: TButton
    AlignWithMargins = True
    Left = 50
    Top = 836
    Width = 997
    Height = 50
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alBottom
    Cancel = True
    Caption = #1047#1040#1050#1056#1067#1058#1068' '#1055#1056#1054#1043#1056#1040#1052#1052#1059' [Esc]'
    Constraints.MaxHeight = 50
    Constraints.MinHeight = 50
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    TabStop = False
    OnClick = ButtonCloseClick
  end
  object grpOperationMode: TGroupBox
    AlignWithMargins = True
    Left = 50
    Top = 224
    Width = 997
    Height = 151
    Margins.Left = 0
    Margins.Top = 50
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099' ('#1090#1080#1087' '#1088#1072#1073#1086#1095#1077#1081' '#1089#1084#1077#1085#1099')'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    Padding.Left = 20
    Padding.Top = 20
    Padding.Right = 20
    Padding.Bottom = 20
    ParentFont = False
    TabOrder = 0
    TabStop = True
    object btnNight: TSpeedButton
      Left = 622
      Top = 47
      Width = 353
      Height = 82
      Cursor = crHandPoint
      Hint = #1042#1099#1073#1088#1072#1090#1100' '#1088#1072#1073#1086#1090#1091' '#1074' '#1053#1054#1063#1053#1059#1070' '#1089#1084#1077#1085#1091
      Margins.Left = 0
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alRight
      Anchors = []
      BiDiMode = bdLeftToRight
      GroupIndex = 1
      Caption = #1053#1054#1063#1053#1040#1071
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = True
      Spacing = 0
      OnClick = btnNightClick
      ExplicitTop = 49
    end
    object btnDay: TSpeedButton
      Left = 22
      Top = 47
      Width = 300
      Height = 82
      Cursor = crHandPoint
      Hint = #1042#1099#1073#1088#1072#1090#1100' '#1088#1072#1073#1086#1090#1091' '#1074' '#1044#1053#1045#1042#1053#1059#1070' '#1089#1084#1077#1085#1091
      Margins.Left = 0
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alLeft
      Anchors = []
      BiDiMode = bdLeftToRight
      GroupIndex = 1
      Caption = #1044#1053#1045#1042#1053#1040#1071
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = True
      Spacing = 0
      OnClick = btnDayClick
    end
    object btnAllDay: TSpeedButton
      Left = 322
      Top = 47
      Width = 300
      Height = 82
      Cursor = crHandPoint
      Hint = #1042#1099#1073#1088#1072#1090#1100' '#1088#1072#1073#1086#1090#1091' '#1074' '#1057#1059#1058#1054#1063#1053#1059#1070' '#1089#1084#1077#1085#1091
      Margins.Left = 0
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alClient
      Anchors = []
      BiDiMode = bdLeftToRight
      GroupIndex = 1
      Caption = #1057#1059#1058#1054#1063#1053#1040#1071
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = True
      Spacing = 0
      OnClick = btnAllDayClick
      ExplicitTop = 49
    end
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
