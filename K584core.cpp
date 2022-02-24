//---------------------------------------------------------------------------
#pragma hdrstop

#include <stdio.h>
#include <string.h>
#include "K584core.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

#define INSTR_COUNT 50
InstrDesc iSet[INSTR_COUNT] = {
    //������ 1
    {TYPE_ALU, 2, {OP_REG, OP_WR},                  OP_REG,     "aaaa00rrr", true,      "�������� ��� ��� � ��, ��������� � ���"},                          //00
    {TYPE_ALU, 2, {OP_REG, OP_WR},                  OP_WR,      "aaaa01rrr", true,      "�������� ��� ��� � ��, ��������� � ��"},                           //01
    {TYPE_ALU, 2, {OP_IN, OP_WR},                   OP_OUT,     "aaaa11000", false,     "������ �� ���� ������ ��������� �������� ��� ����� ����� � ��"},   //02
    {TYPE_ALU, 2, {OP_IN, OP_WR},                   OP_WR,      "aaaa11001", false,     "�������� ��� ����� ����� � ��, ��������� � ��"},                   //03
    {TYPE_ALU, 2, {OP_IN, OP_XWR},                  OP_WR,      "aaaa11011", true,      "�������� ��� ����� ����� � ���, ��������� � ��"},                  //04
    {TYPE_ALU, 2, {OP_IN, OP_WR},                   OP_XWR,     "aaaa11100", true,      "�������� ��� ����� ����� � ��, ��������� � ���"},                  //05
    {TYPE_ALU, 2, {OP_IN, OP_XWR},                  OP_XWR,     "aaaa11110", true,      "�������� ��� ����� ����� � ���, ��������� � ���"},                 //06
    {TYPE_ALU, 2, {OP_IN, OP_XWR},                  OP_OUT,     "aaaa11111", true,      "������ �� ���� ������ ��������� �������� ��� ����� ����� � ���"},  //07
    //������ 2
    {TYPE_SUM, 3, {OP_REG, OP_WR, OP_CARRY},        OP_XWR,     "001110rrr", true,      "��������� � ��� ����� ����, �� � ����"},                           //08
    {TYPE_SUM, 3, {OP_REG, OP_IN, OP_CARRY},        OP_WR,      "010010rrr", true,      "��������� � �� ����� ����, ���� ����� � ����"},                    //09
    {TYPE_SUM, 3, {OP_REG, OP_IN, OP_CARRY},        OP_XWR,     "010110rrr", true,      "��������� � ��� ����� ����, ���� ����� � ����"},                   //10
    {TYPE_SUM, 3, {OP_REG, OP_IN, OP_CARRY},        OP_REG,     "011110rrr", true,      "��������� � ���� ����� ���� ����� � ����"},                        //11
    {TYPE_SUM, 3, {OP_REG, OP_XWR, OP_CARRY},       OP_WR,      "110010rrr", true,      "��������� � �� ����� ����, ��� � ����"},                           //12
    {TYPE_SUM, 3, {OP_REG, OP_XWR, OP_CARRY},       OP_XWR,     "110110rrr", true,      "��������� � ��� ����� ���� � ����"},                               //13
    {TYPE_SUM, 2, {OP_XWR, OP_CARRY},               OP_REG,     "111010rrr", true,      "��������� ���� ����� ��� � ����"},                                 //14
    {TYPE_SUM, 3, {OP_WR, OP_IN, OP_CARRY},         OP_XWR,     "001111010", true,      "��������� � ��� ����� ��, ���� ����� � ����"},                     //15
    {TYPE_SUM, 3, {OP_WR, OP_IN, OP_CARRY},         OP_OUT,     "011111010", true,      "������ �� ���� ������ ����� ��, ���� ����� � ����"},               //16
    {TYPE_SUM, 3, {OP_XWR, OP_IN, OP_CARRY},        OP_WR,      "110011010", true,      "��������� � �� ����� ���, ���� ����� � ����"},                     //17
    {TYPE_SUM, 3, {OP_XWR, OP_IN, OP_CARRY},        OP_XWR,     "110111010", true,      "��������� � ��� ����� ���� ����� � ����"},                         //18
    {TYPE_SUM, 2, {OP_XWR, OP_CARRY},               OP_OUT,     "111011010", true,      "������ �� ���� ������ ����� ��� � ����"},                          //19
    //������ 3
    {TYPE_SUM, 1, {OP_IN},                          OP_REG,     "111110rrr", true,      "��������� ����� �� ���� ����� � ���"},                             //20
    {TYPE_SUM, 1, {OP_REG},                         OP_OUT,     "000010rrr", true,      "��������� �������� ���� �� ���� ������"},                          //21
    {TYPE_SUM, 1, {OP_REG},                         OP_XWR,     "000110rrr", true,      "��������� �������� ���� � ���"},                                   //22
    {TYPE_SUM, 1, {OP_IN},                          OP_WR,      "011010xxx", true,      "��������� ����� �� ���� ����� � ��"},                              //23
    {TYPE_SUM, 1, {OP_IN},                          OP_WR,      "011011010", true,      "��������� ����� �� ���� ����� � ��"},                              //24
    {TYPE_SUM, 1, {OP_IN},                          OP_XWR,     "000111010", true,      "��������� ����� �� ���� ����� � ���"},                             //25
    {TYPE_SUM, 1, {OP_IN},                          OP_OUT,     "111111010", true,      "��������� ����� � ���� ����� �� ���� ������"},                     //26
    {TYPE_SUM, 1, {OP_IN},                          OP_OUT,     "000011010", true,      "��������� ����� � ���� ����� �� ���� ������"},                     //27
    //������ 4
    {TYPE_SCL, 4, {OP_WR, OP_IN | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   "100011010", true,      "����� ����������� ����� ������� �������� ����� ��, ���������� �������� ���� ����� � ����"},     //28
    {TYPE_SCL, 3, {OP_WR, OP_IN, OP_CARRY},         OP_WRXWR,   "100111010", true,      "����� ����������� ����� ������� �������� ����� ��, ���� ����� � ����"},                         //29
    {TYPE_SCL, 4, {OP_WR, OP_REG | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   "100010rrr", true,      "����� ����������� ����� ������� �������� ����� ��, ���������� �������� ���� � ����"},           //30
    {TYPE_SCL, 3, {OP_WR, OP_REG, OP_CARRY},        OP_WRXWR,   "100110rrr", true,      "����� ����������� ����� ������� �������� ����� ��, ���� � ����"},                               //31
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "101010xxx", true,      "����� �������������� ������ ������� �������� ����� �� � ����"},                                 //32
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "101011010", true,      "����� �������������� ������ ������� �������� ����� �� � ����"},                                 //33
    {TYPE_SAR, 4, {OP_WR, OP_IN | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   "001011010", true,      "����� �������������� ������ ������� �������� ����� ��, ���������� �������� ���� ����� � ����"}, //34
    {TYPE_SAR, 3, {OP_WR, OP_IN, OP_CARRY},         OP_WRXWR,   "101111010", true,      "����� �������������� ������ ������� �������� ����� ��, ���� ����� � ����"},                     //35
    {TYPE_SAR, 4, {OP_WR, OP_REG | F_MINUS,
                   OP_ONE | F_MINUS, OP_CARRY},     OP_WRXWR,   "001010rrr", true,      "����� �������������� ������ ������� �������� ����� ��, ���������� �������� ���� � ����"},       //36
    {TYPE_SAR, 3, {OP_WR, OP_REG, OP_CARRY},        OP_WRXWR,   "101110rrr", true,      "����� �������������� ������ ������� �������� ����� ��, ���� � ����"},                           //37
    //������ 5
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WR,      "000011101", true,      "��������� � �� ����� �������������� ������ ����� �� � ����"},      //38
    {TYPE_SCR, 2, {OP_WR, OP_CARRY},                OP_WR,      "x00111101", true,      "��������� � �� ����� ����������� ������ ����� �� � ����"},         //39
    {TYPE_SAL, 2, {OP_WR, OP_CARRY},                OP_WR,      "001011101", true,      "��������� � �� ����� �������������� ����� ����� �� � ����"},       //40
    {TYPE_SCL, 2, {OP_WR, OP_CARRY},                OP_WR,      "x01111101", true,      "��������� � �� ����� ����������� ����� ����� �� � ����"},          //41
    {TYPE_SLR, 2, {OP_WR, OP_CARRY},                OP_WR,      "100011101", true,      "��������� � �� ����� ���������� ������ ����� �� � ����"},          //42
    {TYPE_SLL, 2, {OP_WR, OP_CARRY},                OP_WR,      "101011101", true,      "��������� � �� ����� ���������� ����� ����� �� � ����"},           //43
    //������ 6
    {TYPE_SAR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "010011101", true,      "����� �������������� ������ ������� �������� ����� �� � ����"},    //44
    {TYPE_SCR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "x10111101", true,      "����� ����������� ������ ������� �������� ����� �� � ����"},       //45
    {TYPE_SAL, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "011011101", true,      "����� �������������� ����� ������� �������� ����� �� � ����"},     //46
    {TYPE_SCL, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "x11111101", true,      "����� ����������� ����� ������� �������� ����� �� � ����"},        //47
    {TYPE_SLR, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "110011101", true,      "����� ���������� ������ ������� �������� ����� �� � ����"},        //48
    {TYPE_SLL, 2, {OP_WR, OP_CARRY},                OP_WRXWR,   "111011101", true,      "����� ���������� ����� ������� �������� ����� �� � ����"}          //49
};

K584::K584(int _BitsCount)
: BitsCount(_BitsCount), WR(0), XWR(0), BufDA(0), BufXWR(0)
{
    memset(Reg, 0, sizeof(Reg));
    BitMask = (1 << BitsCount) - 1;
    //��������� ������� ����� ���������������
    for (int i = 0; i < INSTR_COUNT; i++) {
        iSet[i].BitMask = 0;
        for (int j = 0; j < 9; j++)
            if (iSet[i].BitField[j] == '0' || iSet[i].BitField[j] == '1') {
                iSet[i].BitValue |= (iSet[i].BitField[j] == '1' ? 1 : 0) << 8 - j;
                iSet[i].BitMask |= 1 << 8 - j;
            }
    }
}

void K584::FormatOp(unsigned Op, char *A, char *B, char *Str)
{
    if (Op & 0x08)
        //���������� ��������
        switch (Op & 0x07) {
        case 0x00:
            sprintf(Str, "%s and %s", A, B);
            break;
        case 0x01:
            sprintf(Str, "%s xor %s", A, B);
            break;
        case 0x02:
            sprintf(Str, "!(%s xor %s)", A, B);
            break;
        case 0x03:
            sprintf(Str, "!%s and %s", A, B);
            break;
        case 0x04:
            sprintf(Str, "%s and !%s", A, B);
            break;
        case 0x05:
            sprintf(Str, "%s or !%s", A, B);
            break;
        case 0x06:
            sprintf(Str, "!%s or %s", A, B);
            break;
        case 0x07:
            sprintf(Str, "%s or %s", A, B);
            break;
        }
    else
        //�������������� ��������
        switch (Op & 0x07) {
        case 0x00:
            strcpy(Str, "!�");
            break;
        case 0x01:
            sprintf(Str, "%s - %s - 1 + �", B, A);
            break;
        case 0x02:
            sprintf(Str, "%s - %s - 1 + �", A, B);
            break;
        case 0x03:
            sprintf(Str, "%s + %s + �", A, B);
            break;
        case 0x04:
            sprintf(Str, "%s + �", B);
            break;
        case 0x05:
            sprintf(Str, "!%s + �", B);
            break;
        case 0x06:
            sprintf(Str, "%s + �", A);
            break;
        case 0x07:
            sprintf(Str, "!%s + �", A);
            break;
        }
}

unsigned K584::Adc(unsigned op1, unsigned op2, unsigned Carry, unsigned &OutFlags)
{
    unsigned OldCarry = Carry &= 0x01;
    OutFlags = F_INVSL1 | F_INVSR1 | F_INVSL2 | F_INVSR2;
    //����������� ��������
    for (int i = 0; i < BitsCount / 4; i++) {
        Carry = ((op1 >> i * 4 & 0x0F) + (op2 >> i * 4 & 0x0F) + Carry) >> 4 & 0x01;
        OutFlags |= Carry ? F_C0 << i : 0;
    }
    OutFlags |= Carry ? F_CO : 0;
    return op1 + op2 + OldCarry & BitMask;
}

unsigned K584::ExecuteOp(unsigned Op, unsigned A, unsigned B, unsigned InFlags, unsigned &OutFlags)
{
    unsigned Carry = (InFlags & F_CI) != 0;
    OutFlags = F_INVSL1 | F_INVSR1 | F_INVSL2 | F_INVSR2;
    if (Op & 0x08)
        //���������� ��������
        switch (Op & 0x07) {
        case 0x00:
            return A & B;
        case 0x01:
            return A ^ B;
        case 0x02:
            return ~(A ^ B);
        case 0x03:
            return ~A & B;
        case 0x04:
            return A & ~B;
        case 0x05:
            return A | ~B;
        case 0x06:
            return ~A | B;
        case 0x07:
            return A | B;
        }
    else
        //�������������� ��������
        switch (Op & 0x07) {
        case 0x00:
            return Carry ? 0 : BitMask;
        case 0x01:
            return Adc(~A, B, Carry, OutFlags);
        case 0x02:
            return Adc(A, ~B, Carry, OutFlags);
        case 0x03:
            return Adc(A, B, Carry, OutFlags);
        case 0x04:
            return Adc(B, 0, Carry, OutFlags);
        case 0x05:
            return Adc(~B, 0, Carry, OutFlags);
        case 0x06:
            return Adc(A, 0, Carry, OutFlags);
        case 0x07:
            return Adc(~A, 0, Carry, OutFlags);
        }
    return 0;
}

void K584::Shift(InstrType Op, int ResType, unsigned &Result, unsigned InFlags, unsigned &OutFlags)
{
    OutFlags |= F_INVSL1 | F_INVSR1 | F_INVSL2 | F_INVSR2;
    Result &= BitMask;
    XWR &= BitMask;
    unsigned bit, sign = Result & 1 << BitsCount - 1;
    switch (Op) {
    case TYPE_SAL:
        OutFlags ^= sign ? F_INVSL1 : 0;
        Result <<= 1;
        if (ResType == OP_WRXWR) {
            bit = (InFlags & F_P0 ? XWR >> BitsCount - 1 : XWR >> BitsCount - 2) & 0x01;
            XWR <<= 1;
            Result |= bit;
            OutFlags ^= bit ? F_INVSL2 | F_INVSR1 : 0;
            if (!(InFlags & F_P0))
                XWR = XWR & ~(1 << BitsCount - 1) | (Result & 1 << BitsCount - 1);
        }
        break;

    case TYPE_SAR:
        bit = Result & 0x01;
        OutFlags ^= bit ? F_INVSR1 : 0;
        Result = Result >> 1 | sign;
        if (ResType == OP_WRXWR) {
            OutFlags ^= (XWR & 0x01 ? F_INVSR2 : 0) | (bit ? F_INVSL2 : 0);
            XWR >>= 1;
            if (InFlags & F_P0)
                XWR |= bit << BitsCount - 1;
            else {
                XWR |= sign;
                XWR = XWR & ~(1 << BitsCount - 2) | (bit << BitsCount - 2);
            }
        }
        break;

    case TYPE_SLL:
        OutFlags ^= sign ? F_INVSL1 : 0;
        Result <<= 1;
        if (ResType == OP_WRXWR) {
            bit = XWR >> BitsCount - 1 & 0x01;
            OutFlags ^= bit ? F_INVSL2 | F_INVSR1 : 0;
            XWR <<= 1;
            Result |= bit;
        }
        break;

    case TYPE_SLR:
        bit = Result & 0x01;
        OutFlags ^= bit ? F_INVSR1 : 0;
        Result >>= 1;
        if (ResType == OP_WRXWR) {
            OutFlags ^= (XWR & 0x01 ? F_INVSR2 : 0) | (bit ? F_INVSL2 : 0);
            XWR >>= 1;
            XWR |= bit << BitsCount - 1;
        }
        break;

    case TYPE_SCL:
        if (ResType == OP_WRXWR) {
            bit = XWR >> BitsCount - 1 & 0x01;
            OutFlags ^= (sign ? F_INVSL1 | F_INVSR2 : 0) | (bit ? F_INVSR1 | F_INVSL2 : 0);
            Result = Result << 1 | bit;
            XWR = XWR << 1 | sign >> BitsCount - 1;
        } else {
            OutFlags ^= sign ? F_INVSL1 | F_INVSR1 : 0;
            Result = Result << 1 | sign >> BitsCount - 1;
        }
        break;

    case TYPE_SCR:
        sign = Result & 0x01;
        if (ResType == OP_WRXWR) {
            bit = XWR & 0x01;
            OutFlags ^= (sign ? F_INVSR1 | F_INVSL2 : 0) | (bit ? F_INVSR2 | F_INVSL1 : 0);
            Result = Result >> 1 | bit << BitsCount - 1;
            XWR = XWR >> 1 | sign << BitsCount - 1;
        } else {
            OutFlags ^= sign ? F_INVSL1 | F_INVSR1 : 0;
            Result = Result >> 1 | sign << BitsCount - 1;
        }
        break;
    }
}

bool K584::Format(unsigned MI, char *Str, bool FormatALU, bool FormatReg, bool ShowCarry)
{
    char fmt[][10] = {"��", "���", "���%d", "�����", "������", "�", "(��, ���)", "1"};
    char shift[][5] = {"���(", "���(", "���(", "���(", "���(", "���("};
    if (!FormatReg)
        strcpy(fmt[2], "���");
    //���� ��������������� � ���� ������
    char A[16], B[16], C[32];
    for (int i = 0; i < INSTR_COUNT; i++)
        if ((MI & iSet[i].BitMask) == iSet[i].BitValue) {
            //��������� ��������
            sprintf(Str, fmt[iSet[i].Result], MI & 0x07);
            strcat(Str, " := ");
            switch (iSet[i].Type) {
            case TYPE_SUM:
                //��������� ������ ���������, ����������� �������
                for (int j = 0; j < iSet[i].OpCount; j++) {
                    if (j)
                        strcat(Str, iSet[i].Operands[j] & F_MINUS ? " - " : " + ");
                    sprintf(A, fmt[iSet[i].Operands[j] & F_MMASK], MI & 0x07);
                    strcat(Str, A);
                }
                break;

            case TYPE_ALU:
                //����������� �������� ��������
                sprintf(A, fmt[iSet[i].Operands[0]], MI & 0x07);
                sprintf(B, fmt[iSet[i].Operands[1]], MI & 0x07);
                if (FormatALU)
                    FormatOp(MI >> 5, A, B, C);
                else
                    sprintf(C, "%s � %s", A, B);
                strcat(Str, C);
                break;

            default:
                //���������� ��� ��������
                strcat(Str, shift[iSet[i].Type - TYPE_SAL]);
                //��������� ������ ���������, ����������� �������
                for (int j = 0; j < iSet[i].OpCount; j++) {
                    if (j)
                        strcat(Str, iSet[i].Operands[j] & F_MINUS ? " - " : " + ");
                    sprintf(A, fmt[iSet[i].Operands[j] & F_MMASK], MI & 0x07);
                    strcat(Str, A);
                }
                //��������� ������
                strcat(Str, iSet[i].Result == OP_WRXWR ? ", ���)" : ")");
                break;
            }
            //����������, ���� �� ������������� �������
            if (ShowCarry && (MI & ATTR_CUSED) != 0)
                strcat(Str, MI & ATTR_CARRY ? " (�=1)" : " (�=0)");
            return true;
        }
    //���������������� ����������
    strcpy(Str, NOP_TEXT);
    return false;
}

bool K584::FindOperand(int Index, int Type, unsigned MI)
{
    //���� ��������� ������� � ������
    for (int i = 0; i < iSet[Index].OpCount; i++)
        if ((iSet[Index].Operands[i] & F_MMASK) == Type)
            if (iSet[Index].Type == TYPE_ALU) {
                //�������� ��� - ���������, ������������ �� ������� �������
                unsigned op = MI >> 5 & 0x0F;
                if (op & 0x08)
                    //���������� �������� - ��� ��������
                    return true;
                switch (op) {
                case 0x01:
                case 0x02:
                case 0x03:
                    return true;
                case 0x04:
                case 0x05:
                    return (iSet[Index].Operands[1] & F_MMASK) == Type;
                case 0x06:
                case 0x07:
                    return (iSet[Index].Operands[0] & F_MMASK) == Type;
                default:
                    return false;
                }
            } else
                return true;
    //���� ������� - ����, �� ���������, �� ����������� �� �� � �������������� ��������
    if (Type == OP_CARRY && iSet[Index].Type == TYPE_ALU)
        return (MI >> 5 & 0x0F) < 8;
    return false;
}

bool K584::Execute(unsigned MI, unsigned DI, unsigned &DO, unsigned &DA, unsigned InFlags, unsigned &OutFlags)
{
    unsigned Carry = (InFlags & F_CI) != 0;
    //���� ��������������� � ���� ������
    for (int i = 0; i < INSTR_COUNT; i++)
        if ((MI & iSet[i].BitMask) == iSet[i].BitValue) {
            //��������� ������ ���������
            unsigned Ops[3] = {0, 0, 0};
            int count = 0;
            for (int j = 0; j < iSet[i].OpCount; j++) {
                switch (iSet[i].Operands[j] & F_MMASK) {
                case OP_WR:
                    Ops[count++] = WR;
                    break;
                case OP_XWR:
                    Ops[count++] = XWR;
                    break;
                case OP_REG:
                    Ops[count++] = Reg[MI & 0x07];
                    break;
                case OP_IN:
                    Ops[count++] = DI;
                    break;
                case OP_CARRY:
                    Ops[2] = Carry;
                    break;
                default:
                    continue;
                }
                if (iSet[i].Operands[j] & F_MINUS)
                    Ops[count - 1] = ~Ops[count - 1];
            }
            //�������� ����� ���������
            unsigned *result;
            switch (iSet[i].Result) {
            case OP_WR:
            case OP_WRXWR:
                result = &WR;
                break;
            case OP_XWR:
                result = &XWR;
                break;
            case OP_REG:
                result = Reg + (MI & 0x07);
                break;
            case OP_OUT:
                result = &DO;
                break;
            }
            //��������� ��������
            switch (iSet[i].Type) {
            case TYPE_SUM:
                //��������� ��������
                *result = Adc(Ops[0], Ops[1], Ops[2], OutFlags);
                break;
            case TYPE_ALU:
                //��������� �������� ��������
                *result = ExecuteOp(MI >> 5, Ops[0], Ops[1], InFlags, OutFlags);
                break;
            default:
                //��������� ��������
                *result = Adc(Ops[0], Ops[1], Ops[2], OutFlags);
                //���������� ������ �����
                Shift(iSet[i].Type, iSet[i].Result, *result, InFlags, OutFlags);
            }
            *result &= BitMask;
            //�������������� ����������� �������
            if (!(InFlags & F_INVPC))
                Reg[7] = Reg[7] + (InFlags & F_INC ? 2 : 1) & BitMask;
            //������ ���������� �������� ��������� ���� ������ � XWR
            DA = BufDA;
            OutFlags |= BufXWR & 0x01 ? F_XWR0 : 0;
            OutFlags |= BufXWR & 1 << BitsCount - 1 ? F_XWR3 : 0;
            //������ ������� ���� ��� A � B
            OutFlags |= (Ops[0] & 1 << BitsCount - 1 ? F_A3 : 0) |
                        (Ops[1] & 1 << BitsCount - 1 ? F_B3 : 0);
            //��������� �������� ��������
            BufDA = InFlags & F_PR ? Reg[7] : (iSet[i].OutWR ? WR : XWR);
            BufXWR = XWR;
            return true;
        }
    return false;
}
