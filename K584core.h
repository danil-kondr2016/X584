//---------------------------------------------------------------------------
#ifndef K584coreH
#define K584coreH
//---------------------------------------------------------------------------

//������� �������
#define F_CI        0x00001         //������� ��� ������� ������
#define F_P0        0x00002         //������� ��� ������� ������� ������
#define F_INVPC     0x00004         //��������� ������� ������� ������������ ��������
#define F_INC       0x00008         //��������� ������������ ��������
#define F_PR        0x00010         //��������� R7 �� ���� �������

//�������� �������
#define F_CO        0x00001         //������� �� ������� ������
#define F_INVSL1    0x00002         //��������� ������ ��������������� ������� � WR
#define F_INVSR1    0x00004
#define F_INVSL2    0x00008         //��������� ������ ��������������� ������� � XWR
#define F_INVSR2    0x00010
#define F_XWR0      0x00020         //������� ��� XWR ������� ������
#define F_XWR3      0x00040         //������� ��� XWR ������� ������
#define F_A3        0x00080         //������� ��� ���� A
#define F_B3        0x00100         //������� ��� ���� B
#define F_C0        0x00200         //����������� �������� �� 8 ������
#define F_C1        0x00400
#define F_C2        0x00800
#define F_C3        0x01000
#define F_C4        0x02000
#define F_C5        0x04000
#define F_C6        0x08000
#define F_C7        0x10000

//��� ����������
enum InstrType {TYPE_SUM, TYPE_ALU, TYPE_SAL, TYPE_SAR, TYPE_SLL, TYPE_SLR, TYPE_SCL, TYPE_SCR};

//���� ���������
enum {OP_WR, OP_XWR, OP_REG, OP_IN, OP_OUT, OP_CARRY, OP_WRXWR, OP_ONE};
#define F_MINUS 0x80
#define F_MMASK 0x7F

//���������������� ���������������
#define NOP         154
#define NOP2        186
#define NOP_TEXT    "<�����>"

//�������� ���������������
#define ATTR_BREAKPOINT 0x8000
#define ATTR_CARRY      0x4000
#define ATTR_CUSED      0x2000

struct InstrDesc
{
    InstrType   Type;           //��� ����������
    int         OpCount;        //���������� ���������
    int         Operands[4];    //������ ���������
    int         Result;         //��������� �������� (��������)
    char        BitField[10];   //������ ���������������
    bool        OutWR;          //���� ������ WR �� ���� �������
    char        Help[128];      //������� �� ���������������    
    unsigned    BitValue;       //�������� ���� ���������������
    unsigned    BitMask;        //����� �������� �����
};

#define INSTR_COUNT 50
extern InstrDesc iSet[INSTR_COUNT];

//������� �����
class K584
{
private:
    int BitsCount;                  // ����������� (������ 4, 32 ���� ��������)
    unsigned BitMask;               // ����� �������� �����
    unsigned BufDA, BufXWR;         // �������� �������� ���� ������ � �������� XWR
    void FormatOp(unsigned Op, char *A, char *B, char *Str);
    unsigned Adc(unsigned op1, unsigned op2, unsigned Carry, unsigned &OutFlags);
    unsigned ExecuteOp(unsigned Op, unsigned A, unsigned B, unsigned InFlags, unsigned &OutFlags);
    void Shift(InstrType Op, int ResType, unsigned &Result, unsigned InFlags, unsigned &OutFlags);
public:
    unsigned Reg[8];                // ����
    unsigned WR, XWR;               // ������� ������� � �����������
    K584(int _BitsCount);
    bool Format(unsigned MI, char *Str, bool FormatALU = true, bool FormatReg = true, bool ShowCarry = true);
    bool FindOperand(int Index, int Type, unsigned MI);
    bool Execute(unsigned MI, unsigned DI, unsigned &DO, unsigned &DA, unsigned InFlags, unsigned &OutFlags);
};

#endif
