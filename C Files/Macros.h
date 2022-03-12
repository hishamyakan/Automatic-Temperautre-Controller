/*
 * Macros.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Eng. Hisham
 */

#ifndef MACROS_H_
#define MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT_NUMBER) (REG) = (REG)|(1<<BIT_NUMBER)

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT_NUMBER) (REG) = (REG)&(~(1<<BIT_NUMBER))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT_NUMBER) (REG) = (REG)^(1<<BIT_NUMBER)

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,NUM) (REG) = ((REG>>NUM) | (REG<<8-NUM))

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,NUM) (REG) = ((REG<<NUM) | (REG>>8-NUM))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT_NUMBER) REG &(1<<BIT_NUMBER)

/* Check if a specific bit is cleared in any register and return true if yes */
#define  BIT_IS_CLEAR(REG,BIT_NUMBER) !( REG &(1<<BIT_NUMBER))

/* Get Certain bit from a register */
#define GET_BIT(REG,BIT_NUMBER) (REG)&(1<<BIT_NUMBER)?1:0


#endif /* MACROS_H_ */
