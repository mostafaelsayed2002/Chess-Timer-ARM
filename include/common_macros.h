#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

#define SET_BIT(REG_NAME, BIT_NUMBER) REG_NAME |= (1 << BIT_NUMBER)
#define CLEAR_BIT(REG_NAME, BIT_NUMBER) REG_NAME &= (~(1 << BIT_NUMBER))
#define TOGGLE_BIT(REG_NAME, BIT_NUMBER) REG_NAME ^= (1 << BIT_NUMBER)
#define READ_BIT(REG_NAME, BIT_NUM) (REG_NAME >> BIT_NUM) & 1
#define CLEAR_PORT(PORT_NAME) PORT_NAME &= 0x00000000
#define SET_PORT(PORT_NAME) PORT_NAME |= 0xffffffff
#define READ_PORT(PORT_NAME) PORT_NAME & 0xffffffff

#endif
