object SelfTabel: TSelfTabel
  Left = 0
  Top = 0
  Margins.Left = 0
  Margins.Top = 0
  Margins.Right = 0
  Margins.Bottom = 0
  BorderStyle = bsNone
  Caption = 'SelfTabel'
  ClientHeight = 628
  ClientWidth = 804
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Comfortaa'
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
  TextHeight = 14
  object Label1: TLabel
    AlignWithMargins = True
    Left = 50
    Top = 311
    Width = 704
    Height = 29
    Margins.Left = 0
    Margins.Top = 30
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Alignment = taCenter
    Caption = #1053#1059#1046#1053#1054' '#1042#1042#1045#1057#1058#1048' '#1064#1058#1056#1048#1061'-'#1050#1054#1044
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clGreen
    Font.Height = -24
    Font.Name = 'Comfortaa'
    Font.Style = [fsBold]
    Font.Quality = fqProof
    ParentFont = False
    ExplicitWidth = 347
  end
  object LabelResult: TLabel
    AlignWithMargins = True
    Left = 50
    Top = 475
    Width = 704
    Height = 27
    Margins.Left = 0
    Margins.Top = 30
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Alignment = taCenter
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Comfortaa'
    Font.Style = []
    Font.Quality = fqProof
    ParentFont = False
    ExplicitWidth = 7
  end
  object dxStatusBar1: TdxStatusBar
    Left = 50
    Top = 608
    Width = 704
    Height = 20
    Panels = <
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Color = clBtnFace
        PanelStyle.Font.Charset = RUSSIAN_CHARSET
        PanelStyle.Font.Color = clRed
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Comfortaa'
        PanelStyle.Font.Style = [fsBold]
        PanelStyle.Font.Quality = fqProof
        PanelStyle.ParentFont = False
        Fixed = False
        Text = 'VPN'
        Width = 50
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Font.Charset = RUSSIAN_CHARSET
        PanelStyle.Font.Color = clRed
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Comfortaa'
        PanelStyle.Font.Style = [fsBold]
        PanelStyle.Font.Quality = fqProof
        PanelStyle.ParentFont = False
        Fixed = False
        Text = 'WWW'
        Width = 50
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Font.Charset = RUSSIAN_CHARSET
        PanelStyle.Font.Color = clRed
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Comfortaa'
        PanelStyle.Font.Style = [fsBold]
        PanelStyle.Font.Quality = fqProof
        PanelStyle.ParentFont = False
        Fixed = False
        Text = '----'
        Width = 50
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Alignment = taCenter
        PanelStyle.Font.Charset = RUSSIAN_CHARSET
        PanelStyle.Font.Color = clWindowText
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Comfortaa'
        PanelStyle.Font.Style = [fsBold]
        PanelStyle.Font.Quality = fqProof
        PanelStyle.ParentFont = False
        Fixed = False
        MinWidth = 20
        Width = 50
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Font.Charset = RUSSIAN_CHARSET
        PanelStyle.Font.Color = clWindowText
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Comfortaa'
        PanelStyle.Font.Style = [fsBold]
        PanelStyle.Font.Quality = fqProof
        PanelStyle.ParentFont = False
        Fixed = False
        Width = 50
      end
      item
        PanelStyleClassName = 'TdxStatusBarTextPanelStyle'
        PanelStyle.Font.Charset = RUSSIAN_CHARSET
        PanelStyle.Font.Color = clWindowText
        PanelStyle.Font.Height = -11
        PanelStyle.Font.Name = 'Comfortaa'
        PanelStyle.Font.Style = [fsBold]
        PanelStyle.Font.Quality = fqProof
        PanelStyle.ParentFont = False
        Fixed = False
        Width = 200
      end>
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Comfortaa'
    Font.Style = [fsBold]
    Font.Quality = fqProof
    ExplicitTop = 886
    ExplicitWidth = 997
  end
  object Shtrih: TEdit
    AlignWithMargins = True
    Left = 50
    Top = 50
    Width = 704
    Height = 75
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
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -68
    Font.Name = 'Comfortaa'
    Font.Style = [fsBold]
    Font.Quality = fqProof
    MaxLength = 13
    NumbersOnly = True
    ParentFont = False
    TabOrder = 2
    TextHint = #1064#1058#1056#1048#1061'-'#1050#1054#1044
    OnChange = ShtrihChange
    ExplicitWidth = 997
  end
  object ButtonGo: TButton
    AlignWithMargins = True
    Left = 50
    Top = 370
    Width = 704
    Height = 75
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 30
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Constraints.MaxHeight = 75
    Constraints.MinHeight = 75
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -42
    Font.Name = 'Comfortaa'
    Font.Style = [fsBold]
    Font.Quality = fqProof
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonGoClick
    ExplicitWidth = 997
  end
  object ButtonClose: TButton
    AlignWithMargins = True
    Left = 50
    Top = 558
    Width = 704
    Height = 50
    Cursor = crHandPoint
    Margins.Left = 0
    Margins.Top = 30
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alBottom
    Cancel = True
    Caption = #1047#1040#1050#1056#1067#1058#1068' '#1055#1056#1054#1043#1056#1040#1052#1052#1059' [Esc]'
    Constraints.MaxHeight = 50
    Constraints.MinHeight = 50
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Comfortaa'
    Font.Style = []
    Font.Quality = fqProof
    ParentFont = False
    TabOrder = 4
    TabStop = False
    OnClick = ButtonCloseClick
    ExplicitTop = 836
    ExplicitWidth = 997
  end
  object grpOperationMode: TGroupBox
    AlignWithMargins = True
    Left = 50
    Top = 155
    Width = 704
    Height = 126
    Margins.Left = 0
    Margins.Top = 30
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alTop
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099' ('#1090#1080#1087' '#1088#1072#1073#1086#1095#1077#1081' '#1089#1084#1077#1085#1099')'
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Comfortaa'
    Font.Style = []
    Font.Quality = fqProof
    Padding.Left = 20
    Padding.Top = 20
    Padding.Right = 20
    Padding.Bottom = 20
    ParentFont = False
    TabOrder = 0
    TabStop = True
    ExplicitWidth = 997
    object btnNight: TSpeedButton
      Left = 482
      Top = 49
      Width = 200
      Height = 55
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
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Comfortaa'
      Font.Style = [fsBold]
      Font.Quality = fqProof
      ParentFont = False
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = True
      Spacing = 0
      OnClick = btnNightClick
      ExplicitLeft = 519
    end
    object btnDay: TSpeedButton
      Left = 22
      Top = 49
      Width = 200
      Height = 55
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
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Comfortaa'
      Font.Style = [fsBold]
      Font.Quality = fqProof
      ParentFont = False
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = True
      Spacing = 0
      OnClick = btnDayClick
    end
    object btnAllDay: TSpeedButton
      Left = 222
      Top = 49
      Width = 260
      Height = 55
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
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Comfortaa'
      Font.Style = [fsBold]
      Font.Quality = fqProof
      ParentFont = False
      ParentShowHint = False
      ParentBiDiMode = False
      ShowHint = True
      Spacing = 0
      OnClick = btnAllDayClick
      ExplicitLeft = 322
      ExplicitWidth = 300
      ExplicitHeight = 82
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
