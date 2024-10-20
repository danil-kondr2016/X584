object X584Form: TX584Form
  Left = 191
  Top = 110
  Caption = 'X584'
  ClientHeight = 710
  ClientWidth = 1090
  Color = clBtnFace
  Constraints.MinHeight = 680
  Constraints.MinWidth = 900
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnMouseDown = ControlsMouseDown
  OnResize = FormResize
  DesignSize = (
    1090
    710)
  TextHeight = 15
  object CodeListView: TListView
    Left = 3
    Top = 32
    Width = 532
    Height = 650
    Anchors = [akLeft, akTop, akRight, akBottom]
    Columns = <
      item
        Caption = #1042#1093#1055#1040#1051#1059
        MaxWidth = 55
        MinWidth = 55
        Width = 55
      end
      item
        Alignment = taCenter
        Caption = #1040#1076#1088
        MaxWidth = 100
        MinWidth = 40
        Width = 40
      end
      item
        Caption = #1052#1085#1077#1084#1086#1082#1086#1076' '#1080#1085#1089#1090#1088#1091#1082#1094#1080#1080
        MaxWidth = 300
        MinWidth = 100
        Width = 200
      end
      item
        Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
        MinWidth = 100
        Width = 200
      end>
    HideSelection = False
    MultiSelect = True
    SmallImages = EmptyImageList
    TabOrder = 0
    ViewStyle = vsReport
    OnAdvancedCustomDrawItem = CodeListViewAdvancedCustomDrawItem
    OnCustomDrawItem = CodeListViewCustomDrawItem
    OnDblClick = CodeListViewDblClick
    OnDragDrop = CodeListViewDragDrop
    OnDragOver = CodeListViewDragOver
    OnKeyDown = CodeListViewKeyDown
    OnMouseDown = CodeListViewMouseDown
  end
  object CodeTreeView: TTreeView
    Left = 544
    Top = 32
    Width = 312
    Height = 422
    Anchors = [akTop, akRight, akBottom]
    DragMode = dmAutomatic
    Images = TreeImageList
    Indent = 19
    ReadOnly = True
    TabOrder = 1
    OnChange = CodeTreeViewChange
    OnCollapsed = CodeTreeViewCollapsed
    OnDblClick = CodeTreeViewDblClick
    OnExpanded = CodeTreeViewExpanded
    OnKeyDown = CodeTreeViewKeyDown
  end
  object RegGroupBox: TGroupBox
    Left = 864
    Top = 32
    Width = 216
    Height = 326
    Anchors = [akTop, akRight]
    Caption = #1056#1077#1075#1080#1089#1090#1088#1099
    TabOrder = 4
    OnMouseDown = ControlsMouseDown
    object RLabel0: TLabel
      Left = 16
      Top = 26
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'0'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel1: TLabel
      Left = 16
      Top = 54
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'1'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel2: TLabel
      Left = 16
      Top = 82
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'2'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel3: TLabel
      Left = 16
      Top = 110
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'3'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel4: TLabel
      Left = 16
      Top = 138
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'4'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel5: TLabel
      Left = 16
      Top = 166
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'5'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel6: TLabel
      Left = 16
      Top = 194
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'6'
      OnMouseDown = ControlsMouseDown
    end
    object RLabel7: TLabel
      Left = 16
      Top = 222
      Width = 31
      Height = 15
      Caption = #1056#1054#1053'7'
      OnMouseDown = ControlsMouseDown
    end
    object WRLabel: TLabel
      Left = 16
      Top = 262
      Width = 14
      Height = 15
      Caption = #1056#1056
      OnMouseDown = ControlsMouseDown
    end
    object XWRLabel: TLabel
      Left = 16
      Top = 290
      Width = 21
      Height = 15
      Caption = #1056#1056#1056
      OnMouseDown = ControlsMouseDown
    end
    object RMaskEdit0: TMaskEdit
      Left = 72
      Top = 24
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 0
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit1: TMaskEdit
      Left = 72
      Top = 52
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 1
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit2: TMaskEdit
      Left = 72
      Top = 80
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 2
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit3: TMaskEdit
      Left = 72
      Top = 108
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 3
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit4: TMaskEdit
      Left = 72
      Top = 136
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 4
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit5: TMaskEdit
      Left = 72
      Top = 164
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 5
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit6: TMaskEdit
      Left = 72
      Top = 192
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 6
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit7: TMaskEdit
      Left = 72
      Top = 220
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 7
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit8: TMaskEdit
      Left = 72
      Top = 260
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 8
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
    object RMaskEdit9: TMaskEdit
      Left = 72
      Top = 288
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      TabOrder = 9
      Text = '0000 0000 0000 0000'
      OnChange = RegMaskEditChange
      OnDblClick = RegMaskEditDblClick
      OnKeyPress = RegMaskEditKeyPress
    end
  end
  object BusGroupBox: TGroupBox
    Left = 864
    Top = 364
    Width = 216
    Height = 90
    Anchors = [akTop, akRight]
    Caption = #1064#1080#1085#1099
    TabOrder = 5
    OnMouseDown = ControlsMouseDown
    object OutLabel: TLabel
      Left = 16
      Top = 26
      Width = 33
      Height = 15
      Caption = #1064#1042#1099#1093
      OnMouseDown = ControlsMouseDown
    end
    object AddrLabel: TLabel
      Left = 16
      Top = 54
      Width = 32
      Height = 15
      Caption = #1064#1040#1076#1088
      OnMouseDown = ControlsMouseDown
    end
    object RMaskEdit10: TMaskEdit
      Left = 72
      Top = 24
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      ReadOnly = True
      TabOrder = 0
      Text = '0000 0000 0000 0000'
    end
    object RMaskEdit11: TMaskEdit
      Left = 72
      Top = 52
      Width = 128
      Height = 23
      Alignment = taCenter
      EditMask = '0000 0000 0000 0000;1;_'
      MaxLength = 19
      ReadOnly = True
      TabOrder = 1
      Text = '0000 0000 0000 0000'
    end
  end
  object OutGroupBox: TGroupBox
    Left = 944
    Top = 460
    Width = 136
    Height = 136
    Anchors = [akTop, akRight]
    Caption = #1042#1099#1093#1086#1076#1099
    Enabled = False
    TabOrder = 7
    OnMouseDown = ControlsMouseDown
    object OutFlags0: TCheckBox
      Left = 8
      Top = 24
      Width = 65
      Height = 17
      Caption = #1055#1040#1051#1059'3'
      TabOrder = 0
    end
    object OutFlags1: TCheckBox
      Left = 72
      Top = 24
      Width = 61
      Height = 17
      Caption = '!'#1057#1044#1051'1'
      Checked = True
      State = cbChecked
      TabOrder = 6
    end
    object OutFlags2: TCheckBox
      Left = 72
      Top = 40
      Width = 61
      Height = 17
      Caption = '!'#1057#1044#1055'1'
      Checked = True
      State = cbChecked
      TabOrder = 7
    end
    object OutFlags3: TCheckBox
      Left = 72
      Top = 56
      Width = 57
      Height = 17
      Caption = '!'#1057#1044#1051'2'
      Checked = True
      State = cbChecked
      TabOrder = 8
    end
    object OutFlags4: TCheckBox
      Left = 72
      Top = 72
      Width = 57
      Height = 17
      Caption = '!'#1057#1044#1055'2'
      Checked = True
      State = cbChecked
      TabOrder = 9
    end
    object OutFlags5: TCheckBox
      Left = 8
      Top = 88
      Width = 49
      Height = 17
      Caption = #1056#1056#1056'0'
      TabOrder = 4
    end
    object OutFlags6: TCheckBox
      Left = 8
      Top = 104
      Width = 49
      Height = 17
      Caption = #1056#1056#1056'3'
      TabOrder = 5
    end
    object OutFlags9: TCheckBox
      Left = 8
      Top = 72
      Width = 58
      Height = 17
      Caption = #1055#1040#1051#1059'0'
      TabOrder = 3
    end
    object OutFlags10: TCheckBox
      Left = 8
      Top = 56
      Width = 58
      Height = 17
      Caption = #1055#1040#1051#1059'1'
      TabOrder = 2
    end
    object OutFlags11: TCheckBox
      Left = 8
      Top = 40
      Width = 58
      Height = 17
      Caption = #1055#1040#1051#1059'2'
      TabOrder = 1
    end
    object OutFlags7: TCheckBox
      Left = 72
      Top = 88
      Width = 41
      Height = 17
      Caption = 'A15'
      TabOrder = 10
    end
    object OutFlags8: TCheckBox
      Left = 72
      Top = 104
      Width = 41
      Height = 17
      Caption = 'B15'
      TabOrder = 11
    end
  end
  object FilterOpGroupBox: TGroupBox
    Left = 544
    Top = 460
    Width = 312
    Height = 96
    Anchors = [akRight, akBottom]
    Caption = #1060#1080#1083#1100#1090#1088' '#1084#1080#1082#1088#1086#1080#1085#1089#1090#1088#1091#1082#1094#1080#1081
    TabOrder = 2
    OnMouseDown = ControlsMouseDown
    object FilterOpRegButton: TButton
      Tag = 2
      Left = 9
      Top = 24
      Width = 54
      Height = 25
      Caption = #1056#1054#1053
      TabOrder = 0
      OnClick = FilterOpButtonClick
    end
    object FilterOpWRButton: TButton
      Left = 69
      Top = 24
      Width = 54
      Height = 25
      Caption = #1056#1056
      TabOrder = 1
      OnClick = FilterOpButtonClick
    end
    object FilterOpXWRButton: TButton
      Tag = 1
      Left = 129
      Top = 24
      Width = 54
      Height = 25
      Caption = #1056#1056#1056
      TabOrder = 2
      OnClick = FilterOpButtonClick
    end
    object FilterOpInButton: TButton
      Tag = 3
      Left = 189
      Top = 24
      Width = 54
      Height = 25
      Caption = #1064#1042#1093
      TabOrder = 3
      OnClick = FilterOpButtonClick
    end
    object FilterOpCarryButton: TButton
      Tag = 5
      Left = 249
      Top = 24
      Width = 54
      Height = 25
      Caption = #1055
      TabOrder = 4
      OnClick = FilterOpButtonClick
    end
    object FilterResRegButton: TButton
      Tag = 2
      Left = 9
      Top = 54
      Width = 54
      Height = 25
      Caption = #1056#1054#1053
      TabOrder = 5
      OnClick = FilterResButtonClick
    end
    object FilterResWRButton: TButton
      Left = 69
      Top = 54
      Width = 54
      Height = 25
      Caption = #1056#1056
      TabOrder = 6
      OnClick = FilterResButtonClick
    end
    object FilterResXWRButton: TButton
      Tag = 1
      Left = 129
      Top = 54
      Width = 54
      Height = 25
      Caption = #1056#1056#1056
      TabOrder = 7
      OnClick = FilterResButtonClick
    end
    object FilterResOutButton: TButton
      Tag = 4
      Left = 189
      Top = 54
      Width = 54
      Height = 25
      Caption = #1064#1042#1099#1093
      TabOrder = 8
      OnClick = FilterResButtonClick
    end
    object FilterResWRXWRButton: TButton
      Tag = 6
      Left = 249
      Top = 54
      Width = 54
      Height = 25
      Caption = #1056#1056','#1056#1056#1056
      TabOrder = 9
      OnClick = FilterResButtonClick
    end
  end
  object DescGroupBox: TGroupBox
    Left = 544
    Top = 562
    Width = 312
    Height = 120
    Anchors = [akRight, akBottom]
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1084#1080#1082#1088#1086#1082#1086#1084#1072#1085#1076#1099
    Enabled = False
    TabOrder = 3
    OnMouseDown = ControlsMouseDown
    object DescMemo: TMemo
      Left = 9
      Top = 24
      Width = 294
      Height = 80
      ReadOnly = True
      TabOrder = 0
    end
  end
  object InGroupBox: TGroupBox
    Left = 864
    Top = 460
    Width = 72
    Height = 136
    Anchors = [akTop, akRight]
    Caption = #1042#1093#1086#1076#1099
    TabOrder = 6
    OnMouseDown = ControlsMouseDown
    object InFlags1: TCheckBox
      Left = 8
      Top = 24
      Width = 33
      Height = 17
      Caption = 'P0'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object InFlags2: TCheckBox
      Left = 8
      Top = 51
      Width = 49
      Height = 17
      Caption = '!'#1055#1057#1095
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
    object InFlags3: TCheckBox
      Left = 8
      Top = 77
      Width = 61
      Height = 17
      Caption = #1048#1053#1050#1056
      TabOrder = 2
    end
    object InFlags4: TCheckBox
      Left = 8
      Top = 104
      Width = 41
      Height = 17
      Caption = #1055#1056
      TabOrder = 3
    end
  end
  object ToolBar: TToolBar
    Left = 0
    Top = 0
    Width = 1090
    Height = 31
    ButtonHeight = 24
    ButtonWidth = 24
    Images = ButtonsImageList
    TabOrder = 8
    OnMouseDown = ControlsMouseDown
    object NewToolButton: TToolButton
      Left = 0
      Top = 0
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1099#1081' '#1092#1072#1081#1083
      Caption = '&'#1053#1086#1074#1099#1081
      ImageIndex = 0
      ImageName = 'new'
      ParentShowHint = False
      ShowHint = True
      OnClick = NewItemClick
    end
    object OpenToolButton: TToolButton
      Left = 24
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
      Caption = '&'#1054#1090#1082#1088#1099#1090#1100'...'
      ImageIndex = 1
      ImageName = 'open'
      ParentShowHint = False
      ShowHint = True
      OnClick = OpenItemClick
    end
    object SaveToolButton: TToolButton
      Left = 48
      Top = 0
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083
      Caption = '&'#1057#1086#1093#1088#1072#1085#1080#1090#1100
      ImageIndex = 2
      ImageName = 'save'
      ParentShowHint = False
      ShowHint = True
      OnClick = SaveItemClick
    end
    object WordToolButton: TToolButton
      Left = 72
      Top = 0
      Hint = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1086#1090#1095#1077#1090' '#1074#1086' Word'
      Caption = 'WordToolButton'
      ImageIndex = 3
      ImageName = 'word'
      ParentShowHint = False
      ShowHint = True
      OnClick = WordItemClick
    end
    object ExitToolButton: TToolButton
      Left = 96
      Top = 0
      Hint = #1042#1099#1093#1086#1076
      Caption = '&'#1042#1099#1093#1086#1076
      ImageIndex = 4
      ImageName = 'exit'
      ParentShowHint = False
      ShowHint = True
      OnClick = ExitItemClick
    end
    object Separator1: TToolButton
      Left = 120
      Top = 0
      Width = 8
      ImageIndex = 4
      ImageName = 'exit'
      Style = tbsSeparator
    end
    object CutToolButton: TToolButton
      Left = 128
      Top = 0
      Hint = #1042#1099#1088#1077#1079#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
      Caption = '&'#1042#1099#1088#1077#1079#1072#1090#1100
      ImageIndex = 5
      ImageName = 'cut'
      ParentShowHint = False
      ShowHint = True
      OnClick = CutItemClick
    end
    object CopyToolButton: TToolButton
      Left = 152
      Top = 0
      Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
      Caption = '&'#1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
      ImageIndex = 6
      ImageName = 'copy'
      ParentShowHint = False
      ShowHint = True
      OnClick = CopyItemClick
    end
    object PasteToolButton: TToolButton
      Left = 176
      Top = 0
      Hint = #1042#1089#1090#1072#1074#1080#1090#1100' '#1092#1088#1072#1075#1084#1077#1085#1090
      Caption = #1042#1089#1090'&'#1072#1074#1080#1090#1100
      Enabled = False
      ImageIndex = 7
      ImageName = 'paste'
      ParentShowHint = False
      ShowHint = True
      OnClick = PasteItemClick
    end
    object DeleteToolButton: TToolButton
      Left = 200
      Top = 0
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
      Caption = '&'#1059#1076#1072#1083#1080#1090#1100
      ImageIndex = 8
      ImageName = 'delete'
      ParentShowHint = False
      ShowHint = True
      OnClick = DeleteItemClick
    end
    object Separator2: TToolButton
      Left = 224
      Top = 0
      Width = 8
      ImageIndex = 8
      ImageName = 'delete'
      Style = tbsSeparator
    end
    object RunToolButton: TToolButton
      Left = 232
      Top = 0
      Hint = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
      Caption = '&'#1055#1091#1089#1082
      ImageIndex = 9
      ImageName = 'run'
      ParentShowHint = False
      ShowHint = True
      OnClick = RunItemClick
    end
    object StepToolButton: TToolButton
      Left = 256
      Top = 0
      Hint = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1090#1077#1082#1091#1097#1091#1102' '#1084#1080#1082#1088#1086#1080#1085#1089#1090#1088#1091#1082#1094#1080#1102
      Caption = '&'#1064#1072#1075
      ImageIndex = 10
      ImageName = 'step'
      ParentShowHint = False
      ShowHint = True
      OnClick = StepItemClick
    end
    object RunToCursorToolButton: TToolButton
      Left = 280
      Top = 0
      Hint = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091' '#1076#1086' '#1082#1091#1088#1089#1086#1088#1072
      Caption = #1055#1091#1089#1082' '#1076#1086' &'#1082#1091#1088#1089#1086#1088#1072
      ImageIndex = 11
      ImageName = 'run_to_cursor'
      ParentShowHint = False
      ShowHint = True
      OnClick = RunToCursorItemClick
    end
    object Separator3: TToolButton
      Left = 304
      Top = 0
      Width = 8
      Caption = 'Separator3'
      ImageIndex = 14
      ImageName = 'help'
      Style = tbsSeparator
    end
    object BreakToolButton: TToolButton
      Left = 312
      Top = 0
      Hint = #1055#1088#1077#1088#1074#1072#1090#1100' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      Caption = '&'#1055#1072#1091#1079#1072
      ImageIndex = 12
      ImageName = 'break'
      ParentShowHint = False
      ShowHint = True
      OnClick = BreakItemClick
    end
    object ResetToolButton: TToolButton
      Left = 336
      Top = 0
      Hint = #1057#1073#1088#1086#1089#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
      Caption = '&'#1057#1073#1088#1086#1089
      ImageIndex = 13
      ImageName = 'reset'
      ParentShowHint = False
      ShowHint = True
      OnClick = ResetItemClick
    end
    object Separator4: TToolButton
      Left = 360
      Top = 0
      Width = 8
      Caption = 'Separator4'
      ImageIndex = 14
      ImageName = 'help'
      Style = tbsSeparator
    end
    object HelpToolButton: TToolButton
      Left = 368
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1089#1087#1088#1072#1074#1082#1080
      Caption = '&'#1057#1087#1088#1072#1074#1082#1072
      ImageIndex = 14
      ImageName = 'help'
      ParentShowHint = False
      ShowHint = True
      OnClick = HelpItemClick
    end
    object AboutToolButton: TToolButton
      Left = 392
      Top = 0
      Hint = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      ImageIndex = 15
      ImageName = 'about'
      ParentShowHint = False
      ShowHint = True
      OnClick = AboutItemClick
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 691
    Width = 1090
    Height = 19
    Panels = <
      item
        Width = 900
      end
      item
        Alignment = taCenter
        Width = 40
      end
      item
        Alignment = taCenter
        Width = 40
      end
      item
        Alignment = taCenter
        Width = 40
      end
      item
        Alignment = taCenter
        Width = 40
      end
      item
        Width = 40
      end>
  end
  object InputEdit: TEdit
    Left = 16
    Top = 139
    Width = 57
    Height = 21
    Constraints.MinWidth = 16
    Ctl3D = False
    MaxLength = 128
    ParentCtl3D = False
    TabOrder = 10
    Visible = False
    OnExit = InputEditExit
    OnKeyDown = InputEditKeyDown
  end
  object MainMenu: TMainMenu
    Images = ButtonsImageList
    Left = 16
    Top = 96
    object FileMenu: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      object NewItem: TMenuItem
        Caption = '&'#1053#1086#1074#1099#1081
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1099#1081' '#1092#1072#1081#1083
        ImageIndex = 0
        ImageName = 'new'
        ShortCut = 16462
        OnClick = NewItemClick
      end
      object OpenItem: TMenuItem
        Caption = '&'#1054#1090#1082#1088#1099#1090#1100'...'
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
        ImageIndex = 1
        ImageName = 'open'
        ShortCut = 16463
        OnClick = OpenItemClick
      end
      object SaveItem: TMenuItem
        Caption = '&'#1057#1086#1093#1088#1072#1085#1080#1090#1100
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083
        ImageIndex = 2
        ImageName = 'save'
        ShortCut = 16467
        OnClick = SaveItemClick
      end
      object SaveAsItem: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' &'#1082#1072#1082'...'
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1087#1086#1076' '#1076#1088#1091#1075#1080#1084' '#1080#1084#1077#1085#1077#1084
        OnClick = SaveAsItemClick
      end
      object Item1: TMenuItem
        Caption = '-'
      end
      object ExportItem: TMenuItem
        Caption = '&'#1069#1082#1089#1087#1086#1088#1090
        Hint = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1086#1090#1095#1077#1090
        object WordItem: TMenuItem
          Caption = '&Microsoft Word'
          Hint = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1086#1090#1095#1077#1090' '#1074#1086' Word'
          ImageIndex = 3
          ImageName = 'word'
          OnClick = WordItemClick
        end
      end
      object Item2: TMenuItem
        Caption = '-'
      end
      object ExitItem: TMenuItem
        Caption = '&'#1042#1099#1093#1086#1076
        Hint = #1042#1099#1093#1086#1076
        ImageIndex = 4
        ImageName = 'exit'
        OnClick = ExitItemClick
      end
    end
    object EditMenu: TMenuItem
      Caption = '&'#1055#1088#1072#1074#1082#1072
      object CutItem: TMenuItem
        Caption = '&'#1042#1099#1088#1077#1079#1072#1090#1100
        Hint = #1042#1099#1088#1077#1079#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
        ImageIndex = 5
        ImageName = 'cut'
        ShortCut = 16472
        OnClick = CutItemClick
      end
      object CopyItem: TMenuItem
        Caption = '&'#1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
        ImageIndex = 6
        ImageName = 'copy'
        OnClick = CopyItemClick
      end
      object PasteItem: TMenuItem
        Caption = #1042#1089#1090'&'#1072#1074#1080#1090#1100
        Enabled = False
        Hint = #1042#1089#1090#1072#1074#1080#1090#1100' '#1092#1088#1072#1075#1084#1077#1085#1090
        ImageIndex = 7
        ImageName = 'paste'
        ShortCut = 16470
        OnClick = PasteItemClick
      end
      object DeleteItem: TMenuItem
        Caption = '&'#1059#1076#1072#1083#1080#1090#1100
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1081' '#1092#1088#1072#1075#1084#1077#1085#1090
        ImageIndex = 8
        ImageName = 'delete'
        OnClick = DeleteItemClick
      end
      object Item3: TMenuItem
        Caption = '-'
      end
      object InsertItem: TMenuItem
        Caption = '&'#1056#1077#1078#1080#1084' '#1074#1089#1090#1072#1074#1082#1080
        Hint = #1055#1077#1088#1077#1082#1083#1102#1095#1080#1090#1100' '#1088#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
        OnClick = InsertItemClick
      end
    end
    object DebugMenu: TMenuItem
      Caption = '&'#1054#1090#1083#1072#1076#1082#1072
      object RunItem: TMenuItem
        Caption = '&'#1055#1091#1089#1082
        Hint = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
        ImageIndex = 9
        ImageName = 'run'
        ShortCut = 120
        OnClick = RunItemClick
      end
      object StepItem: TMenuItem
        Caption = '&'#1064#1072#1075
        Hint = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1090#1077#1082#1091#1097#1091#1102' '#1084#1080#1082#1088#1086#1080#1085#1089#1090#1088#1091#1082#1094#1080#1102
        ImageIndex = 10
        ImageName = 'step'
        ShortCut = 118
        OnClick = StepItemClick
      end
      object RunToCursorItem: TMenuItem
        Caption = #1055#1091#1089#1082' '#1076#1086' &'#1082#1091#1088#1089#1086#1088#1072
        Hint = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091' '#1076#1086' '#1082#1091#1088#1089#1086#1088#1072
        ImageIndex = 11
        ImageName = 'run_to_cursor'
        ShortCut = 115
        OnClick = RunToCursorItemClick
      end
      object Item4: TMenuItem
        Caption = '-'
      end
      object BreakItem: TMenuItem
        Caption = '&'#1055#1072#1091#1079#1072
        Hint = #1055#1088#1077#1088#1074#1072#1090#1100' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        ImageIndex = 12
        ImageName = 'break'
        OnClick = BreakItemClick
      end
      object ResetItem: TMenuItem
        Caption = '&'#1057#1073#1088#1086#1089
        Hint = #1057#1073#1088#1086#1089#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
        ImageIndex = 13
        ImageName = 'reset'
        ShortCut = 16497
        OnClick = ResetItemClick
      end
    end
    object HelpMenu: TMenuItem
      Caption = '&'#1055#1086#1084#1086#1097#1100
      object HelpItem: TMenuItem
        Caption = '&'#1057#1087#1088#1072#1074#1082#1072
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1089#1087#1088#1072#1074#1082#1080
        ImageIndex = 14
        ImageName = 'help'
        ShortCut = 112
        OnClick = HelpItemClick
      end
      object Item5: TMenuItem
        Caption = '-'
      end
      object AboutItem: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
        Hint = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        ImageIndex = 15
        ImageName = 'about'
        OnClick = AboutItemClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '584'
    Filter = 
      #1060#1072#1081#1083#1099' X584 (*.x584)|*.x584|'#1060#1072#1081#1083#1099' K584emu (*.Prj)|*.Prj|'#1042#1089#1077' '#1092#1072#1081#1083#1099 +
      ' (*.*)|*.*'
    Left = 48
    Top = 96
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '584'
    Filter = #1060#1072#1081#1083#1099' X584 (*.x584)|*.x584|'#1042#1089#1077' '#1092#1072#1081#1083#1099' (*.*)|*.*'
    Left = 80
    Top = 96
  end
  object ApplicationEvents: TApplicationEvents
    OnIdle = ApplicationEventsIdle
    OnHint = ApplicationEventsHint
    Left = 112
    Top = 96
  end
  object ClickTimer: TTimer
    Enabled = False
    Interval = 250
    OnTimer = ClickTimerTimer
    Left = 176
    Top = 64
  end
  object WordApplication: TWordApplication
    AutoConnect = False
    ConnectKind = ckNewInstance
    Left = 16
    Top = 168
  end
  object WordDocument: TWordDocument
    AutoConnect = False
    ConnectKind = ckNewInstance
    Left = 48
    Top = 168
  end
  object ImageCollection: TImageCollection
    Images = <
      item
        Name = 'empty'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000001E0000001802030000009007A5
              2C000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000009504C5445ACA899ECE9D8FFFFFF2517
              9EDD00000001624B474402660B7C640000000774494D4507E80A0609012C7D0A
              121F0000001063614E7600000078000000180000000000000000A4D9682C0000
              00114944415408D763100D05830686E1C50000EF933DC9CA93E2920000002574
              455874646174653A63726561746500323032342D30392D33305431373A35313A
              33302B30303A30302D82141A0000002574455874646174653A6D6F6469667900
              323032342D30392D33305431373A35313A33302B30303A30305CDFACA6000000
              2874455874646174653A74696D657374616D7000323032342D31302D30365430
              393A30313A34342B30303A303058D1750C0000000049454E44AE426082}
          end>
      end
      item
        Name = 'breakpoint'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000001E0000001804030000001F4750
              8C000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000012504C5445ACA899ECE9D8FFFFFF0000
              0000FF00FF0000B8AFD1A700000001624B474402660B7C640000000774494D45
              07E80A0609012C7D0A121F0000001063614E7600000078000000180000001E00
              0000007B0941CF000000404944415418D363601444060A0CF4E20B1B22F3858D
              4D9C91F9A6A121C8F2C2A1A12EC1A87C57547E082ADF252414851FE282C21734
              750D45B3DF98CEFE87F2012F5A1F33B32BE3CB0000002574455874646174653A
              63726561746500323032342D30392D33305431373A35313A33302B30303A3030
              2D82141A0000002574455874646174653A6D6F6469667900323032342D30392D
              33305431373A35313A33302B30303A30305CDFACA60000002874455874646174
              653A74696D657374616D7000323032342D31302D30365430393A30313A34342B
              30303A303058D1750C0000000049454E44AE426082}
          end>
      end
      item
        Name = 'cursor'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000001E0000001804030000001F4750
              8C000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000000F504C5445ACA899ECE9D8FFFFFF0000
              0000FF001138217C00000001624B474402660B7C640000000774494D4507E80A
              0609012C7D0A121F0000001063614E7600000078000000180000003C00000000
              C0083DAB000000384944415418D363601444060A0C34E20BA3F30DD1F8CE487C
              61636363174324BE0B1038A3F1C10A90F9CEF8E59D719B8F6E3F36F7D1287C00
              40031F6C69EC870D0000002574455874646174653A6372656174650032303234
              2D30392D33305431373A35313A33302B30303A30302D82141A00000025744558
              74646174653A6D6F6469667900323032342D30392D33305431373A35313A3330
              2B30303A30305CDFACA60000002874455874646174653A74696D657374616D70
              00323032342D31302D30365430393A30313A34342B30303A303058D1750C0000
              000049454E44AE426082}
          end>
      end
      item
        Name = 'cursor_and_breakpoint'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000001E0000001804030000001F4750
              8C000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000012504C5445ACA899ECE9D8FFFFFF0000
              0000FF00FF0000B8AFD1A700000001624B474402660B7C640000000774494D45
              07E80A0609012C7D0A121F0000001063614E7600000078000000180000005A00
              000000D67ABF46000000634944415418D3B5D0C10DC0200805503B027181AE40
              C009C4090AFBAF52ACDAD0436FED3FF1208A316D10B3A7FF8CB7732F81A63371
              ED661C2EA6084457D79DCDE400160F4EB7E93AACCB82DDA2F698AB583C0FA559
              BCDFF713C4FD2BF4FAFE0FFFE7041037275521C8BADA00000025744558746461
              74653A63726561746500323032342D30392D33305431373A35313A33302B3030
              3A30302D82141A0000002574455874646174653A6D6F6469667900323032342D
              30392D33305431373A35313A33302B30303A30305CDFACA60000002874455874
              646174653A74696D657374616D7000323032342D31302D30365430393A30313A
              34342B30303A303058D1750C0000000049454E44AE426082}
          end>
      end
      item
        Name = 'unchecked'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000000D0000000D0803000000453514
              4E000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000036504C54451C5180DCDCD7DEDED9E0E0
              DBE2E2DEE5E5E2E8E8E5ECECE9EFEFECF1F1EFF3F3F1F5F5F4F7F7F6F9F9F8FB
              FBFAFDFDFCFEFEFEFFFFFF644E4FD500000001624B474411E2B53DBA00000007
              74494D4507E80A060B0B11DC0962EA0000001063614E76000000340000000D00
              0000000000000065B947420000003F4944415408D75DCE490E80201005515A70
              4004B9FF69FD4D8215ADDDDB5508DFCC6C8969DDF6230F4D9CAE1745029704AA
              049A046E097409B8800BF4DFE5033E98043C0EDAFB4600000025744558746461
              74653A63726561746500323032342D30392D33305431373A35313A33302B3030
              3A30302D82141A0000002574455874646174653A6D6F6469667900323032342D
              30392D33305431373A35313A33302B30303A30305CDFACA60000002874455874
              646174653A74696D657374616D7000323032342D31302D30365431313A31313A
              31372B30303A3030275B8C2E0000000049454E44AE426082}
          end>
      end
      item
        Name = 'checked'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000000D0000000D0803000000453514
              4E000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000039504C54451C5180E2E2DDE3E3DFE5E5
              E1E7E7E3EAEAE6ECECE9EFEFECF1F1EFF3F3F1F5F5F321A121F7F7F6F9F9F8FA
              FAF9FCFCFBFDFDFDFEFEFEFFFFFF6EDDC04F00000001624B4744127BBC6C0000
              00000774494D4507E80A060B0B11DC0962EA0000001063614E76000000340000
              000D0000000D000000009D2983F3000000504944415408D75DCE4B0E80201003
              50908F4A41E0FE97B5C33831DADD4B9AA6CE7DE3BDDF424C793FCE2543113D40
              A99401B551216201EDA26202149D4A19500CCA6A7D4C4AA61522A22A442FE6EF
              E50D5547048BFC7628610000002574455874646174653A637265617465003230
              32342D30392D33305431373A35313A33302B30303A30302D82141A0000002574
              455874646174653A6D6F6469667900323032342D30392D33305431373A35313A
              33302B30303A30305CDFACA60000002874455874646174653A74696D65737461
              6D7000323032342D31302D30365431313A31313A31372B30303A3030275B8C2E
              0000000049454E44AE426082}
          end>
      end
      item
        Name = 'hovered'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000000D0000000D0803000000453514
              4E000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000048504C54451C5180FFF0CFFFEDC6FFE9
              BAFEE4ACFEDF9CFDD98CFDD684FCD37CFCD074FBCC6BFBC863FAC55AE7E7E3FA
              C254FAC04EF9BD48F9BB43F9B93EF9B73AF8B636F8B433F8B330FFFFFF8C3E29
              5B00000001624B4744170BD6988F0000000774494D4507E80A060B0B11DC0962
              EA0000001063614E76000000340000000D0000001A000000004FE9C861000000
              554944415408D75DCECB0E80200C4451144A0191F2D2FFFF5427B109D1BB3BAB
              1963BE6DBB75E439C474400B19B2EE7CCB0572A42A02915749853CAB6A8338A8
              5A874254F501C5A41A13C24E91DAFA9817B470FF5E3EC74C05B4732F988C0000
              002574455874646174653A63726561746500323032342D30392D33305431373A
              35313A33302B30303A30302D82141A0000002574455874646174653A6D6F6469
              667900323032342D30392D33305431373A35313A33302B30303A30305CDFACA6
              0000002874455874646174653A74696D657374616D7000323032342D31302D30
              365431313A31313A31372B30303A3030275B8C2E0000000049454E44AE426082}
          end>
      end
      item
        Name = 'checked_and_hovered'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D494844520000000D0000000D0803000000453514
              4E000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000009C504C54451C5180FFF0CFFFEDC6FFE9
              BAFEE4ACFEDF9CFDD98CFDD889FDDB95FDDC97FCD687FBCA6AFDE3ACFDE6B6FD
              DEA2FBD07AFFEABDFEE9BCF7F7F5F6F6F4F4F4F3F8F8F7FAFAF921A121FDE3AE
              FBD280FEECC4FDE1ABFBD07BFEE7B5FEECC7FDE0A8FBCE77FEE3A9FEEBC3FBD8
              92FAC867FEE0A3FEE9BFF9BC46F9B73AFCD27AF8B636FBCC6BFCDB99F8B433FB
              C863FAC55AFAC55BFBCC70F8B330FFFFFF4967F98600000001624B47443337D5
              7C5E0000000774494D4507E80A060B0B11DC0962EA0000001063614E76000000
              340000000D00000027000000001658B456000000794944415408D75DCED71282
              301404501495AA94907BEDB4400276FFFFE3DC30BEE8BE9DD9D999759CDFCCE6
              EE62B9F2FC208CA02FE2F52681D22C178590C4DB1D94ED495AF0E1089DCE4C16
              5C5650DD305B50ABA0AE671B924A437E3C355268030D2156406146E81225D7B2
              55DA8C37E8FE78BEAA09EFBF971F49140B556B4E864E00000025744558746461
              74653A63726561746500323032342D30392D33305431373A35313A33302B3030
              3A30302D82141A0000002574455874646174653A6D6F6469667900323032342D
              30392D33305431373A35313A33302B30303A30305CDFACA60000002874455874
              646174653A74696D657374616D7000323032342D31302D30365431313A31313A
              31372B30303A3030275B8C2E0000000049454E44AE426082}
          end>
      end
      item
        Name = 'new'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000014D504C5445000000A48250FFFFFFEFE5
              C4FBF9F1FFFFFFFFFFFFFFFFFFFFFFFFD1A51DC99E27C1982DA48250FFFFFFFD
              FDF7F2E4B8FDFBF3FAF6E5ECDBA2FAFAFAFEFDF9FBF7EBF9EFD7F9F0D8EAD289
              B48F3CC59D2BFAF4E3F8F0D7F6EACAF6EBCAE5C96DBA9337F5EAC8F4E9C4F4E5
              BDF0E0AFEBD086E2C363DDB33BD9AD2AF0DFAAF0DFACF1E0B2F0DFADEDD89BEB
              D28CE3C363DCB339EBD38CECD796EFDBA3F0E1ADECD897EEDA9FEAD28AE5C76E
              DFBB4ED1BC8EE8D9A6E6C871E9D084EDD99BF1E0AEEFDBA2EDD795F0E0ADECD7
              97E7D28FF4EFD7EBDBADE5C76DEED99DF0DEA9ECD593EFE6C1FCFAF3F1E8C8E8
              D69EDEB744E3C260E7CB77E8D498EDDEB2F5EBD6F4EDD7E4D396F1E7C6DFBA4D
              E6CA74F5EBD1FDF9F2F8F6E8F6EEDCF3EACFE0BD52E9D086E6CF93F6EFD9F4EA
              CEE2CA83F7EFD9AB8B5AE7D394FBF5E9E5D294EBDEACF8F2E0F1E6C6F4E7C8F0
              E4BDB39652A80000000974524E5300C040D52B1A344D6733EC05620000000162
              4B474402660B7C64000000097048597300000B1200000B1201D2DD7EFC000000
              0774494D4507E80A060D2A280B1E83B30000001063614E760000010000000010
              000000000000000062F984AB000000C04944415418D36360E0E4E4E4E2E6E161
              80034E5E5E5E3E7E4E1E64010141214E61B808A788A898B884A4305C444A5A46
              564E9E07081821020A8A4ACA2AAA6AEA1A1A5025929A5ADA3ABA7AFA061A3C4C
              1001432363135333730B4B2B6BB0008F8DAD9DBD83A393B38BAB1B3358C0D25D
              C2C3D3C3D3CBDBC7D78F0524E01F1028E12511141CC21B1A160E12308808708F
              748F8A06BA3826360E28A061E06F196F999098C49B9C920A52010569E9199959
              700FB1B2B17364E7E432A0823C10010080401DCD4440DDB30000002574455874
              646174653A63726561746500323032342D31302D30365431333A34313A30372B
              30303A3030DCB20CDA0000002574455874646174653A6D6F6469667900323032
              342D31302D30365431333A34313A30372B30303A3030ADEFB466000000287445
              5874646174653A74696D657374616D7000323032342D31302D30365431333A34
              323A34302B30303A303050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'open'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C000001B6504C5445000000EFE0AFFFFFFFD1A5
              1DD1CFEBF2F1F8C5C1E9CCC9EBE9E8F7CECBEDEEECF7F8F7FBDEDDF3F9F8FDD1
              A51DD2A724DCBB58EAD59AFDFCF7F4EBCCE5CD85D2A621DFC060594FBFC8A126
              FCFCF6FBF9ECF6F1DBEBDAA1DAB747F2F1F9F4F4FAC19A30FBF8EED7B544E3CA
              80F3E7C3F0E2B5ECDBA3C8C6E9C4C1E4DBDAEFAD8945F0E1B5F5ECCDE6CF85D1
              A61EE0C46A9C96D4A39ED8A19BD7685EC56C65C86660C26D66C3877FCD8881CD
              C6C7B1E2E0D3E7E6D9E7E6DBCCCDB7B2AFDF726CB7695FC46359C1A8A4E2C7C9
              B8E5E4DDE5E3DDDFDDDAC7C8BBAAA7E3BFBCDE7068CAB0ADE4CACCC4E2E3E4E2
              E2E3E2E1E3DDDCE1D3D1D9D1D0D4C6C6C88A85CB9E99DFB7B4E6C8CAD0D6D6E5
              D1D1E0CBCADCC6C5D9C2C1D1C3C2D2C4C3D29B97D76056C2C0BEE7BFBDE6BEBB
              E6BCBAE6BDBAE6BDBBE7BAB9E6B9B9E6B8B6E6B7B5E5B2B0E1A6A2C7867ED2C8
              C6E8C7C5E8C6C4E8C6C3E8C5C2E8C3C1E7BAB8E5B7B5E7A5A1DF7F7BD05D53C1
              A9A5DFD1D0E9D0D0E9CFCDE9CDCAE9C4C1E7B5B2E2928ED7786FCB6359C3C0BC
              E7C4C4E4B3B1DF857FD05E54C16259C35A50BFA5A0DD8F86CE827BCEC1BCE75C
              52C08B85D4DBD8F3FFFFFF80288A1C0000000E74524E5300C02BD5D52BD5E6B3
              D54D1AC02BF5774B7800000001624B474402660B7C6400000009704859730000
              0B1200000B1201D2DD7EFC0000000774494D4507E80A060D2A280B1E83B30000
              001063614E760000010000000010000000100000000002191329000000E04944
              415418D3636000023E7E01410664C027242C222AC6C804E68803818490A494B4
              8C2C1F3358404E4E5E41918F4F495945558D0F24A0AEA1A9A5CD27A4A3CBA7A7
              AF0014113730341207036363631353330671730B714B2B4B2B6B6B6B1B1B5B3B
              7B0671074727671767171717573737770F4FA02D5EDE3EBE3EBE7EFE018141C1
              21206B43C3C223C223A3A26362E3E2598002098949C929A969E9199959D939AC
              4081DCBCFC82C2A2E292D2B2F20A36903B2AABAA6B6AEBEA1B1A9BD839C02E6D
              AE6A696D6BEFE0E4E28678ACB3AB5BBCA7978717EED33EF1FE09C83E07008EBC
              30247EC6B3150000002574455874646174653A63726561746500323032342D31
              302D30365431333A34313A30372B30303A3030DCB20CDA000000257445587464
              6174653A6D6F6469667900323032342D31302D30365431333A34313A30372B30
              303A3030ADEFB4660000002874455874646174653A74696D657374616D700032
              3032342D31302D30365431333A34323A34302B30303A303050201ECE00000000
              49454E44AE426082}
          end>
      end
      item
        Name = 'save'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000009C504C544500000097BDE697BDE697BD
              E680B3E62079D20066CC6EA8E2FFFFFFBDD7F2BCD4EC408CD9AFCEEE9FC6EC8F
              BCE9F8FBFEEEF5FBE5EFFAD8E8F7CBE0F5BDD8F2AECFEF9FC6EB90BCE980B3E5
              EFF5FC3C8AD83A89D83888D73586D73184D62D81D5287ED46FA9E3E4EFF93083
              D660A0DFD9E8F71E6DC163A8E65197DCA3CEF287C3F2428ED91F79D23485D6AF
              CEEF70A9E35196DC428DD93485D7277DD4E35B1B170000000374524E5300D5C0
              9D5D373400000001624B47440886DE957A000000097048597300000B1200000B
              1201D2DD7EFC0000000774494D4507E80A060D2A280B1E83B30000001063614E
              7600000100000000100000002000000000A338ABAF0000008E4944415418D355
              8D5712C2300C050D986743482809BD841202840EF7BF1BCF469319EF9F563B92
              528E16D1A40DE3E786D5D6830EFE014537022C7A144DE67511C36FB9121211FD
              C1709466E3C9742662BE58AED69B7C8B1D94CFF707B9515030C731E25496279C
              29982375C5A5AA70A5608EEC265FEE14CCF18813FD2C5EEFCF9782B9418D5141
              EE08724790931FA0260C95646C22B10000002574455874646174653A63726561
              746500323032342D31302D30365431333A34313A30372B30303A3030DCB20CDA
              0000002574455874646174653A6D6F6469667900323032342D31302D30365431
              333A34313A30372B30303A3030ADEFB4660000002874455874646174653A7469
              6D657374616D7000323032342D31302D30365431333A34323A34302B30303A30
              3050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'word'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000024C504C54457496ED7294EB6F91E86D8F
              E4688CE16588DD6184D85C81D4587DCF5379CA5075C54C71C1486FBD456CBA34
              62AFC0CFF7BECEF6BCCCF5B8CAF4B5C7F4B1C4F2ADC1F2A9BEF0A5BBF0A1B8EF
              9DB5ED9AB3EC96B0EC94AEEB3260AD7293EBFFFFFFFEFFFFFDFEFFFCFDFEFBFC
              FDFAFAFEF9FAFDF8F8FCF6F7FCF4F5FB91ABE92F5DAA6E91E7BBCCF5FEFEFFFE
              FEFEFBFCFEFAFBFEF9F9FDF7F8FCF4F5FCF3F4FB8EAAE62D5BA76B8EE47F95D8
              738CD2758DD25675C8AEBBDF3957995475CA5D7BCB5B7ACE4A6CC68CA7E42858
              A4688ADF7C96DF91A8E4657AAD6986D1305091C2CBE298ACE16981C73A62B681
              9AD489A5E12554A06386DBFDFEFE88A0DC657FB7E0E4F5274988ABB9DD143B58
              EDF0F586A2DE21519C5E82D6FCFCFE7E97D8ACBBE66983C94476DE24468596AA
              E04775D1294F8D7C8FA0ECEFF983A0DA1C4D985A7FD1FBFBFE728ED3839BD14A
              6EC5D9DFE9EBEEF8809DD7184993557BCCFAFAFD7895E2CDD6E3587DDB778B99
              EAEDF9E9ECF87D9BD314458F5076C75E7BC4E6E9ECEFF2F53F68CDE8EBF77A98
              D110428B4C72C39DB5EEF7F8FD2651A9ABB8C0F1F3FAF0F1FA9CABB5E8EAF8E7
              E9F77796CD0C3F88496FBE9AB2EDF5F7FCF4F6FCF3F5FBF1F2FBEEF0F9EDEFF9
              EBEDF9E8EAF7E6E9F7E5E8F77493CA093B84456CBBF5F6FCF2F4FBEDF0F9ECEE
              F9EAEEF8E7EAF8E6EAF7E5E8F6E3E7F67291C80638814269B892ADEB90ABE98F
              A9E68BA7E488A4E085A2DD819ED87F9BD57B99D17796CE7594CB7391C87190C7
              03367F305EAA2C5BA82455A020509C1D4D981949931545900C3F8703357F0134
              7D2615D3CC00000001624B47441F050D10BD000000097048597300000B120000
              0B1201D2DD7EFC0000000774494D4507E80A060D2A280B1E83B3000000106361
              4E7600000100000000100000003000000000C3D83C2D0000011B4944415418D3
              011001EFFE0000000102030405060708090A0B0C0D0E00000F10111213141516
              1718191A1B1C1D001E101F1F1F202122232425262728292A002B2C1F1F2D2E22
              2F303132273334353600371238393A3B3C303D323E3F40414243004413454646
              471F48494A4B4C4D4E4F5000511452535455534B564A574D58595A5B005C155D
              5E545F60616263646566676869006A166B6C546D61656E604D586F7071720073
              1774607561657677616578797A7B7C007D18257E61657F808165586F7A828384
              008586878865898A8B88588C7A8D8E8F90009192939495968B9798997A9A9B9C
              9D9E009F1BA0A18A8BA2A3A47AA5A6A7A8A9AA00AB1CACADAEAFB0B1B2B3B4B5
              B6B7B8B9000E1DBABB43BCBDBEBFC084C19EAAC2C3B2965BBFF91ED25D000000
              2574455874646174653A63726561746500323032342D31302D30365431333A34
              313A30372B30303A3030DCB20CDA0000002574455874646174653A6D6F646966
              7900323032342D31302D30365431333A34313A30372B30303A3030ADEFB46600
              00002874455874646174653A74696D657374616D7000323032342D31302D3036
              5431333A34323A34302B30303A303050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'exit'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000004B504C5445000000FFFFFF4A5A732929
              29FFFFFFFFFFFFFFFFFF4A5A734A5A733963944A7BC62929296B94D673ADE794
              CEFFADD6F7FFFFFF7B84B5D6D6EF089C081010103973B55A7BB53973C6295294
              D91D3DDB0000000874524E53002BC0C05C3713D5B509ED6E00000001624B4744
              01FF022DDE000000097048597300000B1200000B1201D2DD7EFC000000077449
              4D4507E80A060D2A280B1E83B30000001063614E760000010000000010000000
              40000000003A0ADCE20000005F4944415418D395CFC90E80200C45519C6B5B40
              2D08FFFFA5820331C60D77F7CEA24995FAAD69A1EB87B1CC69462438CB1B8059
              33196BADBE20EF0F30631D20F2B292D1A902DB4A22CE15482510A9024F3BF273
              147C08FEF54BA618E9FEF400F2520866F69A717D000000257445587464617465
              3A63726561746500323032342D31302D30365431333A34313A30372B30303A30
              30DCB20CDA0000002574455874646174653A6D6F6469667900323032342D3130
              2D30365431333A34313A30372B30303A3030ADEFB46600000028744558746461
              74653A74696D657374616D7000323032342D31302D30365431333A34323A3430
              2B30303A303050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'cut'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000168504C5445000000D8DEEFCBD3E9FFFF
              FFF9FAFCE0E5F2D6DCF0046804529852F5F9F60569056283C16D8BC5AEBEDF6B
              A66BFFFFFFFFFFFFFFFFFFFFFFFFE0ECE0FEFEFEDAE9DAC4DBC4E6F0E6CEE2CE
              98C19899AED77C96CBD5DDEEACB7DBC0CFE7718DC699B1D7B5C4E0889FCFC0D0
              E7809ACC8BA4D0D8DFEF8FA6D2D7E7D72B802B016701A5B3DF6788C1B6C5E2DF
              E5F23C8A3C006600096C09649F6DA4B8CC5C78C9A4B9DA5C7CBD8EA1D07F99CC
              708DC65F7FBF6987C3809ACD297F29FBFDFC95BE9600500005641724608C5B86
              D6C4D5EAD7E0EFD0DBEDD3DCEDD5DEEEDDE4F196ACD5A9BADD03680314721401
              67030C61331C53932957B82C5BAD3560B04970B8567ABD1D771D96C09790B6A2
              0C546036679AD7DFF0A6CAA682B482C1DAC187B787016702036A03609A71E4EF
              E44B934B0066012C802CC5DCC5006400207220DDEBDD6BA46B2870280865086E
              A86EAECDAE0455043084301170118BB98B0E6E0E19751991BD91FFFFFF7DF511
              F00000001A74524E5300D5D52B2BD5D5D5AA2BD5EDC9A4AA5C37134DD51AD5E6
              2BB3D5E9A7B1B600000001624B474403110C4CF2000000097048597300000B12
              00000B1201D2DD7EFC0000000774494D4507E80A060D2A280B1E83B300000010
              63614E76000001000000001000000050000000005AEA4B60000000AD49444154
              18D3636080032969190664202B27CF88CC675250546246E2B3C82AABB0222B60
              5355538728D0D0D462E7E064D0D6D1D58348E91B6819181A199B989A995B585A
              59DB3018D8DAD93B383A39BBB8BAB97B787A793370F9F81AF8F9070406058784
              72F3F03230F01968858547444645F30B08420C89898D8B4F484C425828949C62
              90909A260C171049CFC8CCCACE11452811CBCDCB2F2814470848681918144922
              3BBBB8A4B40CCE0100F18B1DBC0776F9F30000002574455874646174653A6372
              6561746500323032342D31302D30365431333A34313A30372B30303A3030DCB2
              0CDA0000002574455874646174653A6D6F6469667900323032342D31302D3036
              5431333A34313A30372B30303A3030ADEFB4660000002874455874646174653A
              74696D657374616D7000323032342D31302D30365431333A34323A34302B3030
              3A303050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'copy'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C000001A1504C5445000000A4824FA48250A482
              50A48250E2C405E0C108DCBE0CD8BA10D4B616CFB01BE1C307FFFFFFFEFEFCC8
              A824C3A32ADDBF0BFDFBF8FCF8EEC1A12DF6EED5B79639E0B799DDB495D8AE90
              D2A98BCCA284C59B7EA48250F8F0DBBA9A36F1E5BEEFDFAEAC8B46DFB699FFFF
              FEBC9375B68C6FF8F2E0F6EDD2F3E7C4B3913EAE8D44AA8948A7864CDAB194FE
              FCFAFDF8F4B48B6DFAEFE4AB8064F1E4BBEEDEABEBD69BE7D18AE4C97AE0C369
              D3AA8DA87E61FAF0E6AE8467F7E4D4F5DEC9DFBF60DBB950FEFAF6FDF5EFFAF1
              E8F9EBDFF7E5D5A97F62E0C166DDBC56DAB547D7B03AC39A7CFAF1E9F9ECE0F8
              E6D7F6E0CDF4DAC3F2D3B8F0CDADEDC5A2EBBE96DBB84DD8B23FD5AD31D3A825
              BA9274F7E7D9E9B98DE7B283D2A51FD0A217B3896CF4DDC7F2D6BCF1CFB1EFC8
              A6ECC19BEABA8FE8B384E6AD7AE4A76FD3A723D1A31ACFA012AC8265F1D0B4EF
              C9A8EDC39DEBBC92E8B587E6AE7CE5A871E3A167E19C5FD0A115EDC4A0E09758
              DE924FE9B88BE7B180E5AA76E3A46CE19E62DF9859DE9351DD8F4ADC8B44E5AB
              78E4A56DE29F64E19A5BDF9552DE904BDC8C45DB8940903EDFAD000000057452
              4E530099B3CCE6EB1D37D900000001624B47440C81B351630000000970485973
              00000B1200000B1201D2DD7EFC0000000774494D4507E80A060D2A280B1E83B3
              0000001063614E7600000100000000100000006000000000FBCBF3E6000000DA
              4944415418D363600001565636760E4E2E0638E0E601025E3E7EB88000902F28
              242C220A648B89894B484A49CBC8C8C8CAC92B2832302881542BABA8AAA96B68
              6A69EB3032E802F97AFA068646C626A666E6164C0C963C565656D636B6765640
              5DF60ECC0C528E4ECE2EAE6E40512B770F4F2F16066F1F5F3FFF80C0A0E010AB
              D0B0F0081986C8282B30888E01EA898D9361884F484C4A4E494D4BCFB0CACCCA
              CE9661C8C9CDCB2F282C2A2E29B52ACB0609589543B4545482AC91010A5455D7
              D4D6D53734365941BC61D5DCD2DAD6DED1D9D505134000301F003C23335B38C7
              98920000002574455874646174653A63726561746500323032342D31302D3036
              5431333A34313A30372B30303A3030DCB20CDA0000002574455874646174653A
              6D6F6469667900323032342D31302D30365431333A34313A30372B30303A3030
              ADEFB4660000002874455874646174653A74696D657374616D7000323032342D
              31302D30365431333A34323A34302B30303A303050201ECE0000000049454E44
              AE426082}
          end>
      end
      item
        Name = 'paste'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000024F504C5445000000FFFFFFFCFCFED4D1
              ED784E31784E31784E317D522F825A3FB6A090D0C2B8E8E0DBA5A0DA8F89D1A5
              9FDC7B72CACECBEBA8A3DB8078CBDBDAF9DADAFFAFABEA6D63C1574DBA997F7D
              784E31EAE4DFDDD3CBCCBCB1BBA5957E74C0A5A0DDC1BFF0D0D0FFC0C0FFB1B1
              FFA0A0FE887188825B3F9B7B65A88A6DAB8D613326B5DCDBFBD5D5FFBFBEFBA4
              A2F28E8BE97C78E17873DD675FC69B7F6BFDFCFCD8C9B5C3AB85655CBF5D53BA
              695EB47567AB827094877187A78D72C09B41F8F5F3D4C4AFC3AB84A18D90BAA4
              88C5AB78C7AC74C9AD6EC7AA64C8A95BCAA851D7B140C09A3DF2EEEACCBAA0C7
              B18AF1E5C2E6D6A7DFCA93D8BF80D2B670CCAE63C7A657C29F4CD0A93BBF9839
              ECE6E0C9B69BC7AF86EFE2BBB99C6ABB9D68BB9D63BD9D5FBE9E59BF9D51C09C
              48CFA735BD9536E7DED7C6B196C6AE83EEE0B3EBD9A2E7D291E4CB80DFC26DD4
              B35BC8A54DCFA83ED4AA2ABA9235E1D7CEC3AD90C5AD80DECA99CCB27BC1A469
              B8985DB29256B79652BD994BCBA439D2A722BA9130DBCFC4BFA98BC4AC7DD2BB
              87C9AE75D1B573D8BC6CDCBD60DBB84ED7B13DD4AB2CD0A31CB78F31D6C8BBBA
              A181C8AF7EEAD79CE6D08BDEC477D4B664CAAA55BF9C4BB49048AD8948A6834A
              A58249D0C0B2B79D7CB39463B39461AA8956A68552A98856A88757A180589C7A
              5395714D8C6642855C37CBB9A9C4B09EB39776B3987BAF9479AB8F75A5866B9F
              7E619471518B6544835B3B81593A825A3DC5B19FBFA995B49B85A3856D947256
              8F6B508A654A815A3E87624796745D8E6A517F563B95735CB09786C6B5A9DFD5
              CEFFFFFFC0BA1E4F0000000C74524E53002B56D5EAD5C0AA95EDC9A490053717
              00000001624B474401FF022DDE000000097048597300000B1200000B1201D2DD
              7EFC0000000774494D4507E80A060D2A280B1E83B30000001063614E76000001
              000000001000000070000000009B2B6464000000FB4944415418D3636080021E
              5E3E7E01188791895950485844544C5C429281414A5A46565C4E5E4151495945
              5C1528A0A6AEA1A9A5ADA3ABA76F6068640C1490343135D33217B7B0B4B2B6B1
              B50309D83B383A39BBB8BAB97B787A7983047C7CFDFC030283824342C3C22340
              029151D131B171F1098949C929A92081B4F48CCCACEC9CDCBCFC82C222904071
              49695979456555754D6D5D3D0B50A0A1B1A9B9A5B5ADBDA3B3ABBB871528D0DB
              D73F61E2A4C953A64E9B3E63261B5060D6EC3973E7CD5FB070D1E2254B97B103
              0596AF58B96AF59AB5EBD66FD8B86933075060CBD66DDB77ECDCB57BCF5E4E2E
              6EA05725F7EDDF7FE0E0A1C3509F0300A2B64DB0B1B55C160000002574455874
              646174653A63726561746500323032342D31302D30365431333A34313A30372B
              30303A3030DCB20CDA0000002574455874646174653A6D6F6469667900323032
              342D31302D30365431333A34313A30372B30303A3030ADEFB466000000287445
              5874646174653A74696D657374616D7000323032342D31302D30365431333A34
              323A34302B30303A303050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'delete'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100403000000EDDDE2
              52000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000002A504C5445000000F73100F73100F731
              00FFFFFFDE3100EF3100DE3100F73100FF3100EF3100E73100DE3100FFFFFF6F
              E0CBB50000000874524E5300D5AAC02BD5D5C084D4881E00000001624B474404
              8F68D951000000097048597300000B1200000B1201D2DD7EFC0000000774494D
              4507E80A060D2A280B1E83B30000001063614E76000001000000001000000080
              00000000D31F3439000000574944415408D7636080012118A3A301CAE0E80093
              20A1090C0CCC2061CE150C0C33C0925D5B3C20EA7856AF80AADFBD0042F3ECDE
              03A659CE1C88390062E49C01B28134FB1920970784413C0620C11300D6700066
              F7190011591585A9A15AB30000002574455874646174653A6372656174650032
              3032342D31302D30365431333A34313A30372B30303A3030DCB20CDA00000025
              74455874646174653A6D6F6469667900323032342D31302D30365431333A3431
              3A30372B30303A3030ADEFB4660000002874455874646174653A74696D657374
              616D7000323032342D31302D30365431333A34323A34302B30303A303050201E
              CE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'run'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000100000001008060000001FF3FF
              61000000097048597300000B1200000B1201D2DD7EFC000001FF4944415438CB
              B5935148535118C7FF5773963A1429A564542442CD1504215268420AE9433D44
              19048191F89A6835A2884A09825E7A5A3D0451A064CB5E0C7B89841EAC465B97
              1472A6DB749B2E88D9EEBD70EEDDF9DA390F03D3CD7AE85CBE7BBFF371FEBFEF
              3BF79C0FF85FE3E9AD9324BE9E090FE55B57904B7CBAFF51167267FC36FD5366
              6624B2262A88679EBE177D1B4302CF1C64B1152914BEF6C34F83AF0724C01FF3
              D395979729E71684C0752628FD69EF41EC6C7A08D38861D948C8585979199A9D
              4DD873BD96D600A4B83388B495C2D7E74ED41C1A4068A21B2C15816959082DCD
              8371069BAD18DDC72FAE824880EB6CA85E1DAA8596F880AAFA4B58FC780D5BEB
              BA60A61691D47E821387CE7470108A6C45686B6CCD4236891711612ADC08F5B1
              07475A76A0DCD10EA6C76506CD30105E09A3A4D80E3353456569252AEC15D8EF
              7481DC448562D1BE926FCB277A6E626FC3318C0F8F627BB5016EE9D29ECC46B1
              65DB66A050819ED6E08BFAA046544CF9A63177EFBB22B7D0797548F13E7023CD
              92E8387F0193935CFAC2925A12BFCC14D4F81704A201CC446710F4CF62FEFE9C
              B2EA14CEDD18555E79EEC2D462683DD5814F9FED32CE4C06CEB9F4FF14AFB989
              02F266640C96BE80A3ED072424CDC5AFA375C5EB5E6501793B16C85412C7E1E6
              EA9C99F3F68280BC7FB7949DE712FF555FECEADD9DB7077E0374FC2220B38319
              800000000049454E44AE426082}
          end>
      end
      item
        Name = 'step'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000000100000001008060000001FF3FF
              61000000097048597300000B1200000B1201D2DD7EFC0000016E4944415438CB
              CD92B14E02411086671183891676FA02166A8C9DC4CA861663A2B1B79502DFC0
              406B65636285B531B1A0A0F00A3B63618C516CA438A248200A1C08B777B777EB
              CCC60D9E5840A593CCCE6473FFB7FFCE1EC05F07FBB9717514BDC4B246FDEAAE
              6023D1502C75503F8C26FA5D3CBF5E00AB62C0F9C106EEC430C5D0279FB65E2E
              24652E3D294771AD1D2CD24227EF1C76D9D9755541DAB68052BD0795960B75CB
              033F90207C0916F795E8261B671AB0207AB721F2E6CA2CE0B7D0E5023A2828BF
              B94AD8717CB06C1F8E0D33E4E091205AFCDCB4E1646F4AF573A92A0A05BC773C
              C0A2C46DDE9F4DE4AB166949A6F68166305D58523DC5FD2B8772C3830F0EE078
              81BA8644675CC6FA0EF0BDB773E98C249116EAA8B51D181F8B4004FF08BABF8D
              108E39F08C34BC1C6464622B1E02701705102888E707E022C411721080D68B89
              E40CFA344380FC5DF3D7E79B604E18404334F235DD37304B984F0FD965032B51
              4DC69809FF2E3E012037BD27448B05290000000049454E44AE426082}
          end>
      end
      item
        Name = 'run_to_cursor'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000126504C5445000000FFFFFFFFFFFFD1A5
              1DFAF6E89F6F0BFFFFFFACC9E7A1C1E499BDE18FB7DF7FADDA75A7DA6EA3D866
              9DD54D8ECF337EC9F5FAFFE6F0FAE1EDF9C4DBF2BAD5F0AECEED84B4E5D1A51D
              ADCAE7EAF4FBE5EFF8DFECF8CEE1F476AAE1FFFFFF9EC1E4E1ECF7D4E6F81C64
              B0C1DCF7A0C5EA75ABE12B7DD0F7F0DAC9DFF7C3DDF7A9CBEDA6C9EC7DB0E3BE
              9939F2E6C29F6F0B95BEE8A2C6EAA8CBECADCDEDAACBEDA3C7EB80B1E3C0A054
              EFDFB0FAEDC89CC3E9A5C8ECACCCED80B2E4B89A69E6D086EAD79CF7E7B7ABCC
              EDF1E4BCA48250EBD781E3C8608CB9E6ACCDEDA5C8EB2D7DCFDEB53183B3E4AA
              CCED2E7ECEDBAE18A2C6EBABCBEDA9CBEC7EB1E370A8E0A1C5EA347EC97AAEE2
              69A3DF79ADE27DAFE37EB0E37FB1E37DB0E26AA4DF4086CC2F80D16EB2A77900
              00000774524E53002B56D52BD540205DB5A600000001624B474401FF022DDE00
              0000097048597300000B1200000B1201D2DD7EFC0000000774494D4507E80A06
              0D2A280B1E83B30000001063614E760000010000000010000000B00000000072
              3E8CBF000000D74944415418D36DCEC95AC2500C86E12820385240342A4A2585
              239306C4836099B1056552994470B8FF9BB0D22EFD76799F7F11807FF37A7DDB
              3BBB7BFB077EC5814020180A1D868F8E1540448093D3B348E4DC820B0BA2081B
              EA658C48238A2704E015C2A69A4C691AA533F1AC80EB1B0417E7F2F95B2ADCC9
              A280FB12029639F7A053A1A25705D4EA0DE66693FFA0A55B8BF6A36118A66972
              87BA95A7EA3380DBC3DCEB715F5277A01787EBBF7864DD2FF4FA26C7620D1E9E
              48A22991CCDAB0359B48BBB90D307B5F7C2C57ABCFF99703DF3FC249F90526D6
              24567C4FA3880000002574455874646174653A63726561746500323032342D31
              302D30365431333A34313A30372B30303A3030DCB20CDA000000257445587464
              6174653A6D6F6469667900323032342D31302D30365431333A34313A30372B30
              303A3030ADEFB4660000002874455874646174653A74696D657374616D700032
              3032342D31302D30365431333A34323A34302B30303A303050201ECE00000000
              49454E44AE426082}
          end>
      end
      item
        Name = 'break'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100403000000EDDDE2
              52000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000030504C5445000000D1A51DC1982DB48D
              3EFFFFFFECD797A48250F8EFD5F3E5BBB48F3CE7CC79E5C76DE1BE56E7CB77E3
              C260D9AD2A9609170B0000000174524E530040E6D86600000001624B4744048F
              68D951000000097048597300000B1200000B1201D2DD7EFC0000000774494D45
              07E80A060D2A280B1E83B30000001063614E760000010000000010000000C000
              0000008BEC6C70000000504944415408D76360C002049519850C400C913046D7
              04148678186329982111C6D80A664C0DE30C0533B2C2D8968219D9616C5BC18C
              9C6B6C67218C676CE7608C3310C637B6F360465A1A5B5A02C26A00DE2B162D55
              BF5FBA0000002574455874646174653A63726561746500323032342D31302D30
              365431333A34313A30372B30303A3030DCB20CDA000000257445587464617465
              3A6D6F6469667900323032342D31302D30365431333A34313A30372B30303A30
              30ADEFB4660000002874455874646174653A74696D657374616D700032303234
              2D31302D30365431333A34323A34302B30303A303050201ECE0000000049454E
              44AE426082}
          end>
      end
      item
        Name = 'reset'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C000000F0504C5445000000E0B799D1A88ACBA2
              86C69E7FC1987BB58B6EB0876BAD8468AC8266A87E61FFFFFFFEFBF8FCF7F1FB
              F2E9F9ECE0F5DFCBF3D8C0F1D1B5EFC9A9E6AF7EE3A56DFCF4EEFAEFE6F9EADD
              F7E5D5F3D9C1F1D3B7F0CDADEDC6A3E5AC77E1A166CDA287FBEDE4FBF1E9F2D5
              BBEFCCACEEC9A9E7B180C49A7DF6DCC7F4DEC9F2D5BCEFCDAEEECAA9EDC7A5E7
              B181E3A56EBD9377ECC49DEFC9A8F0D0B3EFCEAFEEC9A8ECC29CE7AF7DE3A66E
              B88F72E9B78AEBBF97A86D43EEC9A7ECBE94E4A873B1866BE5AC79EABA8DECC4
              9EEDC8A7EBBC92E7AF7FE4A671EBC19BECC49FE09C5EE2A369E7AF7EE6B07FDF
              9756E3A46D6841EA280000000174524E530040E6D86600000001624B47440B1F
              D7C4C0000000097048597300000B1200000B1201D2DD7EFC0000000774494D45
              07E80A060D2A280B1E83B30000001063614E760000010000000010000000D000
              000000EB0CFBF2000000B04944415418D385CFC71282400C0050B01BAC28F68E
              AC6D05DB2A2A16EC82E2FFFF8DCBCAC5F1600E99C94B269970DCFFE079DEE70F
              0443E14814005C1084583C914CA5C54C56F220972F144BE54AB55677A1D16CC9
              B22CB61545416CA2D3EDF501061860A86A2E8CC693E98CAE03325FE82E2C576B
              8CB161E0CD76C7606F1E8EB4368CD3F9C200AE88D03E356F0748881072BBD3F4
              B902968D54F561AAE8695B0C1C4BD2745DD7A497E530F88ADF5FDFD3C118D248
              4F5E900000002574455874646174653A63726561746500323032342D31302D30
              365431333A34313A30372B30303A3030DCB20CDA000000257445587464617465
              3A6D6F6469667900323032342D31302D30365431333A34313A30372B30303A30
              30ADEFB4660000002874455874646174653A74696D657374616D700032303234
              2D31302D30365431333A34323A34302B30303A303050201ECE0000000049454E
              44AE426082}
          end>
      end
      item
        Name = 'help'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C0000025B504C5445000000BBCCD7C5D2D7FFFF
              FFC5D0D1CCD5D796B1CBB1C7D88EACCCA7C0D88DACCFA3BFD78CABCEABC3D68B
              A9CBC5D2D591ADC8C0CBCFBACBD4B2C7D7A2BFDAA5C1DE9FBCD9A1BBD3C7D1D4
              B0C9E3E6EEF4DFE5EEC3CEE1C0CCDFCED7E5EAEDF0BACDE09DB7D0B5C8D8C9DA
              ECE1E7EF7B98C4507FBA457BBC3D75B93E72B4557DB5BCC9DCDEE6EA90AFCDC0
              D5EBD0D9E75C86BD5D92CC87AFDBABC7E5B8CFE8A1BEE05F8FC73168AD98AECD
              DEE4E894B0CDA7C2DEE9EDF2668BBF5B92CE84AFDEFEFEFEFFFFFFF7F9FC79A1
              CF2D64AABBC7DBB3C6DAC7D9EDA1B5D3578CC85F98D57DABDE9DBDE14E89CC50
              8BCED6E4F3DAE5F21B5DAD4C75B0E5E8EBE4ECF36A8EC05B92D05C96D65591D6
              4989D24889D44587D3B3CDECD3E0F01A5DAF275FA7CDD5E1F1F4F6517EB9568F
              CF5691D5508FD6498AD54486D370A2DDF1F6FB759FD11A5EB21856A5B3C0D6F1
              F3F54D7AB74D88CB4E8CD14A89D44688D3D4E3F4FDFDFED4E1F16A99D02065BA
              175CB11553A3B2BFD5E2E9F16388BC427FC44584CC4384D03071C0256BC11C62
              B91256AC2259A4CBD3E0C3D5E99BAFCE3873B93979C3397BC8397BCA98B8E094
              B5DD2469BE1E64BC1459B10D4FA54771ADE3E5E99BBADAE2E7ED547DB62C6CB7
              2C6FBD2E71C2AFC9E8ADC7E61D62B81359B10C50A7B0C3D8B8CEE5C7D0E04774
              B12363B12465B51658AC0C4FA52058A490A6C7DAE0E789A7C7A4BCD1C1D2E6D7
              DDE66C8CBB3366AB255FAA205BA7225AA4B1BFD5D8E0E683A3C8ABC0D1A0BCDA
              DBE2EAD3DAE4B8C4D7B6C2D6C3CDDCE0E4E9B3C6DC8BA9C8D3D8D49AB4CE8AAC
              D191AFD492B1D48AAACF8AA9C9B9C6CE82B3B7680000001374524E5300D5D52B
              9CA4B8C9D5EDF1EDF1C9D5A4B89CD56997DF8500000001624B474403110C4CF2
              000000097048597300000B1200000B1201D2DD7EFC0000000774494D4507E80A
              060D2A280B1E83B30000001063614E760000010000000010000000E000000000
              4A2D4374000001034944415418D3636000016111515131710906286094949296
              919593575084F095945554D5D43534B5B47574417C263D7D0343236313533373
              0B4B2B0606666B1B5B3B7B074747472767175737160656770F4F2F6F1F5F3F7F
              C780C0A0603606F690D0B0F088C8A8E818C7D8B8F8040E06CEC4A4E494D4B4F4
              8C4C87ACEC9C5C2E06EEBCFC82C2A2E292D2B2F28ACAAA6A1E06DE9ADABAFA86
              0647C7C6A6E696D6363E06FEF68ECEAEEE9EDEBEFE0913274D9E22C0C03C75DA
              F4193367CD9E3377DEFCD6EA05820C0C420B172D5EB2D4D171D9F2152B57AD06
              3975CDDA75EB376CDCB479F296ADDB209ED9BE63E7AEDD7BF6EEDB7F00E6DD83
              870E1F397AECF809101B00CDCB52F8DCFFEEEC0000002574455874646174653A
              63726561746500323032342D31302D30365431333A34313A30372B30303A3030
              DCB20CDA0000002574455874646174653A6D6F6469667900323032342D31302D
              30365431333A34313A30372B30303A3030ADEFB4660000002874455874646174
              653A74696D657374616D7000323032342D31302D30365431333A34323A34302B
              30303A303050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'about'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C000000F0504C5445000000A3BDD37B9CBDFFFF
              FFA3BDD3A3BDD3A3BDD37B9CBDFFFFFFA3BDD37B9CBDDBEBF9DDEEFED7EAFDCC
              E5FCC6E1FBA1CBEFB7D5F2EDF6FE9BBDF200309CC8E0F8C2DFF9BCDBF8F4F9FE
              C3E0FABDDCF8B6D7F6EFF7FEF7FBFECDE5FCE5F2FEECF5FEF2F8FEE5EFF6ADCF
              F0DDEDFEE9F4FEDEEEFECBE4FCC1DEF9BBDAF8B4D5F5AACCEED4E9FDDAECFEDF
              EEFED5E9FE295ECCC9E2FBBEDCF9B9D9F7B1D3F3A6C9EBC9E3FCCEE5FDD0E6FD
              D1E7FDC6E0FABAD9F7ABCEEF9EC2E5A9CBECC6E2FBCAE4FCC3DFFAB7D7F6A4C6
              E997BADFBFDDF8AFD1F295B7DA8EADDC82A8E280A7E188ABDC9BBFE3A6C8EB6F
              89ABFFFFFF9555853C0000000974524E5300D5D52BA4C9EDC0403BF777390000
              0001624B474403110C4CF2000000097048597300000B1200000B1201D2DD7EFC
              0000000774494D4507E80A060D2A280B1E83B30000001063614E760000010000
              000010000000F0000000002ACDD4F6000000B44944415418D3558FE516824010
              46D786B188B505EC0E14B017135BDFFF715CF660DD7F73CF7C1308317817406F
              7C7C34164F2405F07BB52849329653E98CC04C8097B2598C712A972FB054502C
              2A0AED50A9105C13D24AE58A4AA1A2EA8A704DAB3768A4D96A77BA4CF4FA83C1
              50C7A3B1615A2C3299CE66731D2F9685157145D04EAED71B1D6F77E6FEC0D680
              E83874063E5A27EF58B08DF3E57AB3EE9FE32300F683C0F7198438200438F40B
              1040FF3C99780137DD1415552D04C10000002574455874646174653A63726561
              746500323032342D31302D30365431333A34313A30372B30303A3030DCB20CDA
              0000002574455874646174653A6D6F6469667900323032342D31302D30365431
              333A34313A30372B30303A3030ADEFB4660000002874455874646174653A7469
              6D657374616D7000323032342D31302D30365431333A34323A34302B30303A30
              3050201ECE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'collapsed'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C000000C9504C5445000000CC9934CB9833C794
              2FDFDFDFF6F6F6FFFFFFFFFFFFB3811BB07E18DFDFDFDFDFDFD6D6D6D6D6D6D6
              D6D6D6D6D6D6D6D6C99631CC9934FFFFFFC28F2AC8C8C8FFFF99BD8A25BA8722
              B7841FB5821DCB9833FFF791FFF48EAE7C168C8C8CDEDEDEFFEB85FFE681C592
              2DC08D28BC8924B88520B4811CB3811BDFDFDFC7942FFFE07BA3710BFFD46FF8
              C560A06E086E6E6EFFCC67EFBC579E6C066D6D6DE6B34E9C6A04BF8C27DCA944
              9A6802D3A03B996701B07E18AB7913A87610A5730D4C4C4C838383D6D6D6FD28
              D5B50000001174524E5300AAD5D5AA5C3713EDC9A492A4B6C9DBEDA0B1073D00
              000001624B4744066166B87D000000097048597300000B1200000B1201D2DD7E
              FC0000000774494D4507E80A060E351E0BB8A6ED0000001063614E7600000030
              000000100000000000000000F88F88F2000000A64944415418D365CF69134260
              1405E0DBBE5A5F6E0B915E89104A8BB4E9FFFFA868989AF17C3B77CE877301EA
              1A4DA1D5FECB22C94972A7DBAB32E6C8643A9BF707C3FCA0A88B4251239ABE04
              108C15FD32D7D6C6B61DD8BA945456C4D381FA225676188420450AAAA53D1E62
              30238A46E988A71826D119DDD2059318A691857EE98A6908CEDCBE69F7C7D30B
              0EA7247D65007216FF6472BE753466588E7FF31CCB8C47F5DF3F5068198DB92C
              F2910000002574455874646174653A63726561746500323032342D31302D3036
              5431343A35323A35322B30303A303091A04F820000002574455874646174653A
              6D6F6469667900323032342D31302D30365431343A35323A31352B30303A3030
              A110C74A0000002874455874646174653A74696D657374616D7000323032342D
              31302D30365431343A35333A33302B30303A303009DAA5710000000049454E44
              AE426082}
          end>
      end
      item
        Name = 'expanded'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C000000CC504C5445000000CEA222CEA222DDDD
              DDF5F5F5FFFFFFFFFFFFC69A19C69A19C69A19DDDDDDC5C5C589898971717171
              7171898989B9B9B9D1D1D1DDDDDDDDDDDDD1D1D1D1D1D1D1D1D1D1D1D1D1D1D1
              CEA222FFFFFFC69A19C5C5C5FFFF9CFFF39CFFF38C9D7B1AFFEB84E2C150B189
              19FFD784DABF6CFFFBF7FFE784A17E19FDD570F7F089FFC75BFBF9969B7B19E2
              B343C9A021FFFFA5FFF794E7BE53CEBC5CA5730DCFA226D7B840EFBA43656565
              C69A1AF0E47AFFE37CFFDF7CDEB243C79C1CFFD76CBF9929717171DDDDDD8989
              896690468E0000001974524E5300AAD5AA5C3713D5EDC9A49CB8D5F1F1D5B89C
              93A7BBCEE2F6F48C2E2B00000001624B474405F86FE9C7000000097048597300
              000B1200000B1201D2DD7EFC0000000774494D4507E80A060E351E0BB8A6ED00
              00001063614E7600000030000000100000001000000000986F1F700000009B49
              44415418D36DCFC71282401004D011730EE49D5D0513E688BA6691FFFF2797A0
              52A5EFD65D7D9801F895924C299DC826119066B2B928E70913080A85624914D8
              EE0448B8B3A828EC2E7EF5CA807D1C10320C170E195500C73861B1E96C5E055C
              2C57EBD866EBD600777B66479C03F23AE0F1C4CE91CBD5E20DC01BBBBF3D5CAF
              094F3781FB2D00EA7B1F3E0D8E971555D30D43D75445FEF3FB0B99271C99F37A
              8F770000002574455874646174653A63726561746500323032342D31302D3036
              5431343A35323A35322B30303A303091A04F820000002574455874646174653A
              6D6F6469667900323032342D31302D30365431343A35323A31352B30303A3030
              A110C74A0000002874455874646174653A74696D657374616D7000323032342D
              31302D30365431343A35333A33302B30303A303009DAA5710000000049454E44
              AE426082}
          end>
      end
      item
        Name = 'tree_item'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000010000000100803000000282D0F
              53000000206348524D00007A26000080840000FA00000080E8000075300000EA
              6000003A98000017709CBA513C00000039504C54450000008080808080808080
              8080808080808080808080808080808080808080808080808080808080808000
              0000808080FFFFFF0000800000005B123F1B0000000F74524E5300F1D5B89C95
              AAC0F7E6EAC4B3A291CC94F86600000001624B47441095B20D2C000000097048
              597300000B1200000B1201D2DD7EFC0000000774494D4507E80A060E351E0BB8
              A6ED0000001063614E7600000030000000100000002000000000394EA7F60000
              00544944415418D365CF490E80400844516C877666B8FF6125B4B1146BF9F312
              02D17FECEB4A3F20488C390761045515F37D84CFC697702336655123CC1025C2
              02B1462810EDF006D1C29EC591C569CF18EFDE23BA00BBA50A2597BA349F0000
              002574455874646174653A63726561746500323032342D31302D30365431343A
              35323A35322B30303A303091A04F820000002574455874646174653A6D6F6469
              667900323032342D31302D30365431343A35323A31352B30303A3030A110C74A
              0000002874455874646174653A74696D657374616D7000323032342D31302D30
              365431343A35333A33302B30303A303009DAA5710000000049454E44AE426082}
          end>
      end>
    Left = 208
    Top = 64
  end
  object LeftImageList: TVirtualImageList
    Images = <
      item
        CollectionIndex = 0
        CollectionName = 'empty'
        Name = 'empty'
      end
      item
        CollectionIndex = 1
        CollectionName = 'breakpoint'
        Name = 'breakpoint'
      end
      item
        CollectionIndex = 2
        CollectionName = 'cursor'
        Name = 'cursor'
      end
      item
        CollectionIndex = 3
        CollectionName = 'cursor_and_breakpoint'
        Name = 'cursor_and_breakpoint'
      end>
    ImageCollection = ImageCollection
    Width = 30
    Height = 24
    Left = 16
    Top = 64
  end
  object CheckImageList: TVirtualImageList
    Images = <
      item
        CollectionIndex = 4
        CollectionName = 'unchecked'
        Name = 'unchecked'
      end
      item
        CollectionIndex = 5
        CollectionName = 'checked'
        Name = 'checked'
      end
      item
        CollectionIndex = 6
        CollectionName = 'hovered'
        Name = 'hovered'
      end
      item
        CollectionIndex = 7
        CollectionName = 'checked_and_hovered'
        Name = 'checked_and_hovered'
      end>
    ImageCollection = ImageCollection
    Width = 13
    Height = 13
    Left = 48
    Top = 64
  end
  object EmptyImageList: TVirtualImageList
    Images = <>
    Width = 1024
    Height = 23
    Left = 80
    Top = 64
  end
  object ButtonsImageList: TVirtualImageList
    Images = <
      item
        CollectionIndex = 8
        CollectionName = 'new'
        Name = 'new'
      end
      item
        CollectionIndex = 9
        CollectionName = 'open'
        Name = 'open'
      end
      item
        CollectionIndex = 10
        CollectionName = 'save'
        Name = 'save'
      end
      item
        CollectionIndex = 11
        CollectionName = 'word'
        Name = 'word'
      end
      item
        CollectionIndex = 12
        CollectionName = 'exit'
        Name = 'exit'
      end
      item
        CollectionIndex = 13
        CollectionName = 'cut'
        Name = 'cut'
      end
      item
        CollectionIndex = 14
        CollectionName = 'copy'
        Name = 'copy'
      end
      item
        CollectionIndex = 15
        CollectionName = 'paste'
        Name = 'paste'
      end
      item
        CollectionIndex = 16
        CollectionName = 'delete'
        Name = 'delete'
      end
      item
        CollectionIndex = 17
        CollectionName = 'run'
        Name = 'run'
      end
      item
        CollectionIndex = 18
        CollectionName = 'step'
        Name = 'step'
      end
      item
        CollectionIndex = 19
        CollectionName = 'run_to_cursor'
        Name = 'run_to_cursor'
      end
      item
        CollectionIndex = 20
        CollectionName = 'break'
        Name = 'break'
      end
      item
        CollectionIndex = 21
        CollectionName = 'reset'
        Name = 'reset'
      end
      item
        CollectionIndex = 22
        CollectionName = 'help'
        Name = 'help'
      end
      item
        CollectionIndex = 23
        CollectionName = 'about'
        Name = 'about'
      end>
    ImageCollection = ImageCollection
    Left = 112
    Top = 64
  end
  object TreeImageList: TVirtualImageList
    Images = <
      item
        CollectionIndex = 24
        CollectionName = 'collapsed'
        Name = 'collapsed'
      end
      item
        CollectionIndex = 25
        CollectionName = 'expanded'
        Name = 'expanded'
      end
      item
        CollectionIndex = 26
        CollectionName = 'tree_item'
        Name = 'tree_item'
      end>
    ImageCollection = ImageCollection
    Left = 144
    Top = 64
  end
end
