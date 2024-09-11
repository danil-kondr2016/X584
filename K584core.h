//---------------------------------------------------------------------------
#ifndef K584coreH
#define K584coreH
//---------------------------------------------------------------------------

//Входные сигналы
#define F_CI        0x00001         //перенос АЛУ младшей секции
#define F_P0        0x00002         //младший бит позиции старшей секции
#define F_INVPC     0x00004         //инверсный входной перенос программного счетчика
#define F_INC       0x00008         //инкремент программного счетчика
#define F_PR        0x00010         //индикация R7 на шине адресов

//Выходные сигналы
#define F_CO        0x00001         //перенос из старшей секции
#define F_INVSL1    0x00002         //инверсные выходы распространения сдвигов в WR
#define F_INVSR1    0x00004
#define F_INVSL2    0x00008         //инверсные выходы распространения сдвигов в XWR
#define F_INVSR2    0x00010
#define F_XWR0      0x00020         //младший бит XWR младшей секции
#define F_XWR3      0x00040         //старший бит XWR старшей секции
#define F_A3        0x00080         //старший бит шины A
#define F_B3        0x00100         //старший бит шины B
#define F_C0        0x00200         //потетрадные переносы из 8 секций
#define F_C1        0x00400
#define F_C2        0x00800
#define F_C3        0x01000
#define F_C4        0x02000
#define F_C5        0x04000
#define F_C6        0x08000
#define F_C7        0x10000

//Тип инструкции
enum InstrType {TYPE_SUM, TYPE_ALU, TYPE_SAL, TYPE_SAR, TYPE_SLL, TYPE_SLR, TYPE_SCL, TYPE_SCR};

//Типы операндов
enum {OP_WR, OP_XWR, OP_REG, OP_IN, OP_OUT, OP_CARRY, OP_WRXWR, OP_ONE};
#define F_MINUS 0x80
#define F_MMASK 0x7F

//Неподдерживаемые микроинструкции
#define NOP         154
#define NOP2        186
#define NOP_TEXT    "<ПУСТО>"

//Атрибуты микроинструкции
#define ATTR_BREAKPOINT 0x8000
#define ATTR_CARRY      0x4000
#define ATTR_CUSED      0x2000

struct InstrDesc
{
    InstrType   Type;           //тип инструкции
    int         OpCount;        //количество операндов
    int         Operands[4];    //список операндов
    int         Result;         //результат операции (приемник)
    char        BitField[10];   //формат микроинструкции
    bool        OutWR;          //флаг выдачи WR на шину адресов
    char        Help[128];      //справка по микроинструкции    
    unsigned    BitValue;       //значащие биты микроинструкции
    unsigned    BitMask;        //маска значащих битов
};

#define INSTR_COUNT 50
extern InstrDesc iSet[INSTR_COUNT];

//Главный класс
class K584
{
private:
    int BitsCount;                  // разрядность (кратна 4, 32 бита максимум)
    unsigned BitMask;               // маска значащих битов
    unsigned BufDA, BufXWR;         // буферные регистры шины адреса и регистра XWR
    void FormatOp(unsigned Op, char *A, char *B, char *Str);
    unsigned Adc(unsigned op1, unsigned op2, unsigned Carry, unsigned &OutFlags);
    unsigned ExecuteOp(unsigned Op, unsigned A, unsigned B, unsigned InFlags, unsigned &OutFlags);
    void Shift(InstrType Op, int ResType, unsigned &Result, unsigned InFlags, unsigned &OutFlags);
public:
    unsigned Reg[8];                // РОНы
    unsigned WR, XWR;               // рабочий регистр и расширитель
    K584(int _BitsCount);
    bool Format(unsigned MI, char *Str, bool FormatALU = true, bool FormatReg = true, bool ShowCarry = true);
    bool FindOperand(int Index, int Type, unsigned MI);
    bool Execute(unsigned MI, unsigned DI, unsigned &DO, unsigned &DA, unsigned InFlags, unsigned &OutFlags);
};

#endif
