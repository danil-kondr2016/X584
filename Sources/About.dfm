object AboutForm: TAboutForm
  Left = 190
  Top = 110
  BorderStyle = bsDialog
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  ClientHeight = 397
  ClientWidth = 424
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object VersionLabel: TLabel
    Left = 56
    Top = 64
    Width = 199
    Height = 15
    Caption = 'X584 '#1074#1077#1088#1089#1080#1103' 2.0.0-beta.5 (2024-10-23)'
  end
  object Label2: TLabel
    Left = 56
    Top = 88
    Width = 318
    Height = 15
    Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1085#1086'-'#1083#1086#1075#1080#1095#1077#1089#1082#1072#1103' '#1084#1086#1076#1077#1083#1100' '#1084#1080#1082#1088#1086#1087#1088#1086#1094#1077#1089#1089#1086#1088#1072' '#1050'584'
  end
  object Label3: TLabel
    Left = 56
    Top = 112
    Width = 200
    Height = 15
    Caption = #1056#1072#1079#1088#1072#1073#1086#1090#1072#1083#1080' '#1089#1090#1091#1076#1077#1085#1090#1099' '#1082#1072#1092#1077#1076#1088#1099' '#1048#1042#1058
  end
  object Label4: TLabel
    Left = 56
    Top = 128
    Width = 309
    Height = 15
    Caption = #1054#1084#1089#1082#1086#1075#1086' '#1043#1086#1089#1091#1076#1072#1088#1089#1090#1074#1077#1085#1085#1086#1075#1086' '#1058#1077#1093#1085#1080#1095#1077#1089#1082#1086#1075#1086' '#1059#1085#1080#1074#1077#1088#1089#1080#1090#1077#1090#1072
  end
  object DeveloperLabel1: TLabel
    Left = 72
    Top = 152
    Width = 87
    Height = 15
    Caption = #1040#1088#1090#1091#1088' '#1050#1072#1089#1080#1084#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DeveloperLabel2: TLabel
    Left = 72
    Top = 168
    Width = 103
    Height = 15
    Caption = #1056#1086#1084#1072#1085' '#1056#1086#1084#1072#1085#1077#1085#1082#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 56
    Top = 240
    Width = 322
    Height = 15
    Caption = #1055#1088#1077#1076#1083#1086#1078#1077#1085#1080#1103' '#1080' '#1086#1090#1095#1077#1090#1099' '#1086#1073' '#1086#1096#1080#1073#1082#1072#1093' '#1087#1088#1086#1089#1100#1073#1072' '#1086#1090#1087#1088#1072#1074#1083#1103#1090#1100' '#1074
  end
  object RepositoryLabel: TLabel
    Left = 72
    Top = 280
    Width = 218
    Height = 17
    Cursor = crHandPoint
    Caption = 'https://github.com/kodemeister/X584'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = RepositoryLabelClick
  end
  object MemCaptionLabel: TLabel
    Left = 56
    Top = 336
    Width = 171
    Height = 15
    Caption = #1044#1086#1089#1090#1091#1087#1085#1072#1103' '#1092#1080#1079#1080#1095#1077#1089#1082#1072#1103' '#1087#1072#1084#1103#1090#1100':'
  end
  object MemLabel: TLabel
    Left = 240
    Top = 336
    Width = 53
    Height = 15
    Caption = '131072 '#1050#1041
  end
  object Label7: TLabel
    Left = 56
    Top = 192
    Width = 178
    Height = 15
    Caption = #1048#1089#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1080' '#1091#1083#1091#1095#1096#1077#1085#1080#1103' '#1074#1085#1077#1089
  end
  object DeveloperLabel3: TLabel
    Left = 72
    Top = 216
    Width = 121
    Height = 15
    Caption = #1044#1072#1085#1080#1083#1072' '#1050#1086#1085#1076#1088#1072#1090#1077#1085#1082#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupLabel1: TLabel
    Left = 288
    Top = 152
    Width = 52
    Height = 15
    Caption = #1075#1088'. '#1042'-313'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupLabel2: TLabel
    Left = 288
    Top = 168
    Width = 61
    Height = 15
    Caption = #1075#1088'. '#1048#1042'-313'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupLabel3: TLabel
    Left = 288
    Top = 216
    Width = 68
    Height = 15
    Caption = #1075#1088'. '#1048#1042#1058'-221'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object IconImage: TVirtualImage
    Left = 8
    Top = 64
    Width = 32
    Height = 32
    ImageCollection = ImageCollection
    ImageWidth = 0
    ImageHeight = 0
    ImageIndex = 1
    ImageName = 'icon'
  end
  object Label10: TLabel
    Left = 56
    Top = 256
    Width = 160
    Height = 15
    Caption = 'GitHub '#1088#1077#1087#1086#1079#1080#1090#1086#1088#1080#1081' '#1087#1088#1086#1077#1082#1090#1072
  end
  object HeaderPanel: TPanel
    Left = 0
    Top = 0
    Width = 424
    Height = 49
    Align = alTop
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    object AboutLabel: TLabel
      Left = 168
      Top = 16
      Width = 76
      Height = 15
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object InfoImage: TVirtualImage
      Left = 384
      Top = 8
      Width = 32
      Height = 32
      ImageCollection = ImageCollection
      ImageWidth = 0
      ImageHeight = 0
      ImageIndex = 0
      ImageName = 'info'
    end
  end
  object Panel1: TPanel
    Left = 40
    Top = 312
    Width = 344
    Height = 2
    BevelOuter = bvLowered
    TabOrder = 1
  end
  object OKButton: TButton
    Left = 336
    Top = 360
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 2
  end
  object ImageCollection: TImageCollection
    Images = <
      item
        Name = 'info'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000020000000200806000000737A7A
              F4000000097048597300000B1200000B1201D2DD7EFC0000075B4944415458C3
              C5575B6C1C5719FEE6BEB33BBBDE8D1D27F1A6494AA246C411116A5A54144840
              2D0221554885563C546A9FFAD002425482371E408212D10768A50621215EDA88
              4A382D2A8524821494DEE2262AEDBAA4491C2738762EEBBDCDEEDC670EFF39B3
              BB5EDB71E48004473A7B6666CFFCFFF77FFFED8C84358CB61BB0961B210A3C18
              0A83A6482BF678B18C209161660CE4740996A94B6B917DCB4D379A0E431C2189
              436434DA2AABD0550DAA4E5351FAFBA2384618C6B44660498C8E9FA0DD6AA330
              3C8C8D4553BA6D009766E799A41AC8A80C3A2992350D3A4D4591FB8A3FBA308B
              8FCFCEE0AE9DDBF0C9ED9BC5B33061088208719220F003847182B9EB2DEC1DDF
              B22636C498AD3A8C03A856ABACD96A31CF0F58CC968E432F1D67851D8F320C3D
              24D617FFF8CE92FF8338616D2F629CC1B91B0D3659B9CCDE3A739EDD4C9F3C78
              3373ADC54267817C2C43CF983073160CA29B6F4ABAB3DA7271E8D77F41CB1B03
              CA9F17EBC15F9DC47CDD45C4DD41539325E40C05F95C86D833303A6CC12A16F1
              CAF1336C55005C39F39B30341D5A368F8C690A419108309A2110D0AAAB32587E
              04C80E61CF67F662FBBEFBC9D765728F028F36DB1ED0F2D3770C0AD652CEA0D0
              C9C0A418DABCB50CCEDE0A004479C5B19B9029C834C314C8B972A138E0414693
              CC27F71230034F3FF9258C6D1DC61D6316F97F144F3D761F0A391D3E818C9314
              2807D1A27B5525100513924E8C1A2AEED8BA0513137FAFF400A8FCA7E345BB54
              49020F3C339B1569E684A9D2DE88F90F4B2D7CF0C038F67D7A27E6EA0EC64A59
              E42D15E41931926E68531CC28E5230C50C688F41C644D8B0BE883F9CFC701785
              CAB8244915F5D89BEF33CFF3296F33945E64B9AEC00978447705F608A37B9912
              4023C821175A50691684C5316788F6B101727BD8DB5E7A9D352883741D703DDC
              F3C57BF1DD279EF91D3D1E170C2864B14CD4EB14701C31A79275ADE8FB8A76BE
              7DE61C265E7BA7FF2CB01DFCF3F23C3E35BE1D4F7FE71BB0A80871E03D204917
              54CBE14A287E74158942854A0B50CF94760917285458E298F5B5089FB394EE41
              21064FD19A8F89BFCEA27A95F8A6C012C37111E006C587042E86C74B8F88B82B
              872F8495E261B178EDD831861F7DFF3926C751282C0E1249A0E77EE74A39B5FC
              5E08A5D9A1A0FAF2E776E3E8E16F63FF17C6495A0E288C02439BA16647841141
              776FD495C381C75D595497841E0ED0767DCA2609A7DFADA459E086415A52BB4A
              7B538088D395BFC8AFCB1BB3F8CAFE6D249D5860493AB93B98D457D69B3D0362
              B69845FE40644724548DC8D19C9898DEE04A7A41D7F3E3123AE95D975B129029
              52BC2888647006922805DACF1A2CCAA224E36D65C550A9C141954342972C4D3B
              B634987A82A268F5322E2A211BC882C192C3D2A0A6D28EB6CFB32385A8768200
              12954B9B4CD3E94F952AE1721692816B0E2C88572AE7CFC22805DB4FDD81F7A9
              AE91729F980A91F82E9A5E6A896A37EDF4427360981EB2797D85F0413606595A
              3E18C30A160508297D6E3B1E6C8A66875C78FECC59189415A20E70104CCB8119
              36142323FA41B48CFEFE7A1300F14006F500C4CBE8F7A9D8B9CD165CD7C57CAD
              83A9D78F6264B408F9896FDE2F215380632FA0516BA046D3A7AC48B0989283D3
              4B6E7E94589EB683D9E0517169346AC4400B7532F6F41BEF0BE593D34724C140
              BDB13045CBAE4181F9E23A2ABDEAA225DD82626544EFA01BCAE030147FCDCDCE
              A14331B4AE64C0EF2CB5DEA7C068D7EBB01716684F1BE7A6AFE3C3D7FE84A2A9
              4C2D31E3A7BF795DBC6659164AC5128AEB8A308746A1D149A837B892970EFF19
              C74ECE53F52BA1BCB92C9E5F99BD424DC9C5835FDD837D9FDD435D3575954F01
              DE6A706617E0B69BB846CDEBF80B87A1B56BC2FA153C3E73E818F3D510EB0A79
              18593A44E40BC4C430351113464647BD6EE327078F60C39D7BA8B92C06C3C8E8
              46B156AF5FC5A30FEFA6336402BBDD21A52D788EDD573EF9F2515C3A358999F6
              0969D533E10F0FFE9E45C4B395D590211039D342BE90A53698231059944AF974
              A3B2288177435E8438DDF55A1DBEEB08C50EAD4EA7836BD76CBCF5E22B684E4F
              2F51BEEAA1F4172FBCCA3EF857139BB6AD8749ED592106344A9944A5D5C85153
              91E9CCA0C0B40AC8E60A694FEAB4D06AD6E1766CC45E9BE2840A0E1DE52F9C3E
              277C3E9451F0DEC523D29A8FE504A2F2C6DB1F8BC02CDF75271DBB4C6AD16ADA
              34C5C949478EE2A530521620B972BB5145ADDE44279030FDB753B872F6BCB07A
              FF03F74EFD76E267E3B7FD5DC04F2D5F7FFCE7CF8FC9FEFE7F5CAC6364EB4658
              141F7A3E8BE1F27A2A5A168AC31B60E68B6836EA385FF90893478EA37169069D
              1B5594B76C983A7561E2617EF2594D877ACB8F86F4C5035D30077EFC83E7BF47
              B977F7F5F9CB9B7C6A22DACEED0829EF38003E2EBF578145A7EA2BA47C2E7C73
              377F5F926EFD49A0AEF57B81049DA0E544170C9DC971F7B32F9F7ED5A526C0A3
              20920CB1EFECD445AEFC915B59FD1F015806668ED71F7EF9D42F8FB10C1DE341
              00AED6DABD2D95B5CA92F15F8EE7BEF58034576D52510C96BBEE7F03808F671F
              BF479A9999C7FF7DECFDC4D7D826F53E763BEFFC1B11500D36C613AD10000000
              0049454E44AE426082}
          end>
      end
      item
        Name = 'icon'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000020000000200806000000737A7A
              F4000000097048597300000B1200000B1201D2DD7EFC000002DB4944415458C3
              ED56B16A225114BD4F244D44635042B44963A396A96CB40882659AD8AC904AFF
              C10F50D264BB05AD522DB85B58EC4220CD2601C1229226B31084346242204694
              58C46676EE5DEFF07C99712689DB2C3930BEE79B19CF39F7DC3723C0073EB05C
              FCA8D58AB7954AE516E76E6E10CB60D5753D53AD567FE13C994CC2E3E398D6F7
              F73F3972BC57C0A9E1383D186CCD11CB70122196E11881E4EBEBFE578B10EF71
              CC90C95511CFCF131A4BA592259F788B63BFDF4FEBE3F1F885089EAB40215622
              845BC7D96C169E9E9ECC13488E4264118BA2B0AB847072BCBBBB0BDD6E172291
              0809F0F97C8E425E2342D839CEE7F3A0691A11CBB023775B8DBF223A8688FA77
              63B2E7E513C6C343C7717333093B3B09984EA7108BC5E8DC643231C9B90238CA
              225458939F43A7637E4DE0877746FEAD502810A90A245F5D5DA571636303EEEF
              EFE762901B92AB20372413DFDC04613804A8D7EB502C1671396E0A4035E17018
              FAFDBE79D3CACA0A09627216A35600E76A044C7E77F7938801907C48E4171735
              D8DEA61EF88D1F9E195FBCDD6E43341AB5DC0A28020F864C2E578181C4AD568B
              C80F0E0E682D180CD2787232E0CB345900A961118D46838EA3A3A317512C824C
              8C407274CC22949DF6C514301A8D343E71787888DF69176056CD66D3AC024721
              372496FDFAFA2B1C1F1FCF3966B063755D08716A0A304EEE6532199889814020
              00BD5E8FAA904AA5A81F5884BC053B9DBA6BC7CA963FE38947BE004520398A90
              89D47E40E2ABAB2BD331DE83879563F9B790A35C2EE398E105AFAAD2B800E388
              E772395A48A7D3F0F0F040F3F3F3CF441A086CCD39C6AE36B6B24A888EF599B0
              33BBC7BFC7A25409A341921CC9E5E525844221EA057C42DA653C736656C2CEB1
              0A8F655842682882DDA0082641C74CE62663A7179ED7F69F8A2102B7A711457C
              91638B8CF5458E5D55408E83A3585B5BB3CA189C325E16B01AE84C9FBDB474F9
              99F29E1FF6B8BC8E1AF32D19FF0BE8F081FF097F003D4BDF61D089D1A4000000
              0049454E44AE426082}
          end>
      end>
    Left = 8
    Top = 8
  end
end
