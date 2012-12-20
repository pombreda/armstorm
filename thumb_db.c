/*
 thumb_db.c
 
 http://code.google.com/p/armstorm/
 distorm at gmail dot com
 Copyright (C) 2012 Gil Dabah
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include "armstorm.h"
#include "thumb_db.h"

_ThumbInstInfo ThumbInstructions[] = {
	{I_LSL, 0, OT_RD, OT_RM3, OT_IMM5},
	{I_LSR, 0, OT_RD, OT_RM3, OT_IMM5},
	{I_ASR, 0, OT_RD, OT_RM3, OT_IMM5},
	{I_MOV, 0, OT_RD8, OT_IMM8, OT_NONE},
	{I_CMP, 0, OT_RN8, OT_IMM8, OT_NONE},
	{I_ADD, 0, OT_RD8, OT_IMM8, OT_NONE},
	{I_SUB, 0, OT_RD8, OT_IMM8, OT_NONE},
	{I_LDR, 18, OT_RD8, OT_PC, OT_IMM8},
	{I_STR, 18, OT_RD, OT_RN3, OT_IMM5_6},
	{I_LDR, 18, OT_RD, OT_RN3, OT_IMM5_6},
	{I_STRB, 2, OT_RD, OT_RN3, OT_IMM5_6},
	{I_LDRB, 2, OT_RD, OT_RN3, OT_IMM5_6},
	{I_STRH, 18, OT_RD, OT_RN3, OT_IMM5_6},
	{I_LDRH, 18, OT_RD, OT_RN3, OT_IMM5_6},
	{I_STR, 18, OT_RD8, OT_SP, OT_IMM8},
	{I_LDR, 18, OT_RD8, OT_SP, OT_IMM8},
	{I_ADD, 16, OT_PC, OT_RD8, OT_IMM8},
	{I_ADD, 16, OT_SP, OT_RD8, OT_IMM8},
	{I_STMIA, 0, OT_RN8, OT_REGLIST, OT_NONE},
	{I_LDMIA, 0, OT_RN8, OT_REGLIST, OT_NONE},
	{I_B, 0, OT_OFF11, OT_NONE, OT_NONE},
	{I_STR, 2, OT_RD, OT_RN3, OT_RM6},
	{I_STRH, 2, OT_RD, OT_RN3, OT_RM6},
	{I_STRB, 2, OT_RD, OT_RN3, OT_RM6},
	{I_LDRSB, 2, OT_RD, OT_RN3, OT_RM6},
	{I_LDR, 2, OT_RD, OT_RN3, OT_RM6},
	{I_LDRH, 2, OT_RD, OT_RN3, OT_RM6},
	{I_LDRB, 2, OT_RD, OT_RN3, OT_RM6},
	{I_LDRSH, 2, OT_RD, OT_RN3, OT_RM6},
	{I_ADD, 0, OT_RD, OT_RN3, OT_RM6},
	{I_SUB, 0, OT_RD, OT_RN3, OT_RM6},
	{I_ADD, 0, OT_RD, OT_RN3, OT_IMM3_6},
	{I_SUB, 0, OT_RD, OT_RN3, OT_IMM3_6},
	{I_PUSH, 0, OT_REGLIST, OT_LR8, OT_NONE},
	{I_POP, 0, OT_REGLIST, OT_PC8, OT_NONE},
	{I_ADD, 0, OT_HRD, OT_HRM3, OT_NONE},
	{I_CMP, 0, OT_HRN0, OT_HRM3, OT_NONE},
	{I_MOV, 0, OT_HRD, OT_HRM3, OT_NONE},
	{I_BEQ, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BNE, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BCS, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BCC, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BMI, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BPL, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BVS, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BVC, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BHI, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BLS, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BGE, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BLT, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BGT, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BLE, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_BAL, 0, OT_OFF8, OT_NONE, OT_NONE},
	{I_SWI, 0, OT_IMM8, OT_NONE, OT_NONE},
	{I_BKPT, 0, OT_IMM8, OT_NONE, OT_NONE},
	{I_BX, 0, OT_HRM3, OT_SBZ3_0, OT_NONE},
	{I_BLX, 0, OT_HRM3, OT_SBZ3_0, OT_NONE},
	{I_ADD, 16, OT_SP, OT_IMM7, OT_NONE},
	{I_SUB, 16, OT_SP, OT_IMM7, OT_NONE},
	{I_AND, 0, OT_RD, OT_RM3, OT_NONE},
	{I_EOR, 0, OT_RD, OT_RM3, OT_NONE},
	{I_LSL, 0, OT_RD, OT_RS3, OT_NONE},
	{I_LSR, 0, OT_RD, OT_RS3, OT_NONE},
	{I_ASR, 0, OT_RD, OT_RS3, OT_NONE},
	{I_ADC, 0, OT_RD, OT_RM3, OT_NONE},
	{I_SBC, 0, OT_RD, OT_RM3, OT_NONE},
	{I_ROR, 0, OT_RD, OT_RS3, OT_NONE},
	{I_TST, 0, OT_RN0, OT_RM3, OT_NONE},
	{I_NEG, 0, OT_RD, OT_RM3, OT_NONE},
	{I_CMP, 0, OT_RN0, OT_RM3, OT_NONE},
	{I_CMN, 0, OT_RD, OT_RM3, OT_NONE},
	{I_ORR, 0, OT_RD, OT_RM3, OT_NONE},
	{I_MUL, 0, OT_RD, OT_RM3, OT_NONE},
	{I_BIC, 0, OT_RD, OT_RM3, OT_NONE},
	{I_MVN, 0, OT_RD, OT_RM3, OT_NONE},
	{I_SXTH, 0, OT_RD, OT_RM3, OT_NONE},
	{I_SXTB, 0, OT_RD, OT_RM3, OT_NONE},
	{I_UXTH, 0, OT_RD, OT_RM3, OT_NONE},
	{I_UXTB, 0, OT_RD, OT_RM3, OT_NONE},
	{I_REV, 0, OT_RD, OT_RN3, OT_NONE},
	{I_REV16, 0, OT_RD, OT_RN3, OT_NONE},
	{I_REVSH, 0, OT_RD, OT_RN3, OT_NONE},
};
unsigned char ThumbsIds[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a,
    0x23, 0x23, 0x23, 0x23, 0x24, 0x24, 0x24, 0x24, 0x25, 0x25, 0x25, 0x25, 0x37, 0x37, 0x38, 0x38,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
    0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a,
    0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
    0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
    0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
    0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
    0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
    0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
    0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
    0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x39, 0x39, 0x3a, 0x3a, 0xff, 0xff, 0xff, 0xff, 0x4b, 0x4c, 0x4d, 0x4e, 0xff, 0xff, 0xff, 0xff,
    0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4f, 0x50, 0xff, 0x51, 0xff, 0xff, 0xff, 0xff,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x36, 0x36, 0x36, 0x36, 0xff, 0xff, 0xff, 0xff,
    0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
    0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x26, 0x26, 0x26, 0x26, 0x27, 0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x28, 0x29, 0x29, 0x29, 0x29,
    0x2a, 0x2a, 0x2a, 0x2a, 0x2b, 0x2b, 0x2b, 0x2b, 0x2c, 0x2c, 0x2c, 0x2c, 0x2d, 0x2d, 0x2d, 0x2d,
    0x2e, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f, 0x2f, 0x2f, 0x30, 0x30, 0x30, 0x30, 0x31, 0x31, 0x31, 0x31,
    0x32, 0x32, 0x32, 0x32, 0x33, 0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x34, 0x35, 0x35, 0x35, 0x35,
    0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
    0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
