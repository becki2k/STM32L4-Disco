/********************************************************************************************
 * @file L3GD20.h
 * @author Matthias Becker
 * @version V1.0.0.0
 * @date 31-May-2016
 * @brief Headerfile for module ... Implementation...
 *
 ********************************************************************************************
 * @attention 
 *
 * <h2><center></center></h2>
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted.
 *
 ********************************************************************************************
 */
#include "gpio.h"

#ifndef __L3GD20_H__
#define __L3GD20_H__
 
 
#ifdef __cplusplus
 extern "C" {
#endif
 

/* Includes ------------------------------------------------------------------------------*/

/** @addtogroup L3GD20 Group Name
  * @{
  */
  
/* Defines -------------------------------------------------------------------------------*/
#define L3GD20_RET_OK                       0x00   /**< Function succeeded with no errors */
#define L3GD20_RET_ERROR_HANDLE_NULL        0x01   /**< Init Error: Handle null pointer error */
#define L3GD20_RET_ERROR_POINTER_NULL		0x02   /**< Init Error: Member Handle null pointer error */

#define L3GD20_READ			0x80
#define L3GD20_WRITE		0x00
#define L3GD20_READ_MULTI	0xC0
#define L3GD20_WRITE_MULTI	0x00

#define L3GD20_REG_WHO_AM_I			0x0F	//r
#define L3GD20_REG_CTRL_REG1		0x20	//rw
#define L3GD20_REG_CTRL_REG2		0x21	//rw
#define L3GD20_REG_CTRL_REG3		0x22	//rw
#define L3GD20_REG_CTRL_REG4		0x23	//rw
#define L3GD20_REG_CTRL_REG5		0x24	//rw
#define L3GD20_REG_REFERENCE		0x25	//rw
#define L3GD20_REG_OUT_TEMP			0x26	//r
#define L3GD20_REG_STATUS			0x27	//r
#define L3GD20_REG_OUT_X_L			0x28	//r
#define L3GD20_REG_OUT_X_H			0x29	//r
#define L3GD20_REG_OUT_Y_L			0x2A	//r
#define L3GD20_REG_OUT_Y_H			0x2B	//r
#define L3GD20_REG_OUT_Z_L			0x2C	//r
#define L3GD20_REG_OUT_Z_H			0x2D	//r
#define L3GD20_REG_FIFO_CTRL		0x2E	//rw
#define L3GD20_REG_FIFO_SRC			0x2F	//r
#define L3GD20_REG_INT1_CFG			0x30	//rw
#define L3GD20_REG_INT1_SRC			0x31	//r
#define L3GD20_REG_INT1_TSH_XH		0x32	//rw
#define L3GD20_REG_INT1_TSH_XL		0x33	//rw
#define L3GD20_REG_INT1_TSH_YH		0x34	//rw
#define L3GD20_REG_INT1_TSH_YL		0x35	//rw
#define L3GD20_REG_INT1_TSH_ZH		0x36	//rw
#define L3GD20_REG_INT1_TSH_ZL		0x37	//rw
#define L3GD20_REG_INT1_DURATION	0x38	//rw

/* Exported types ------------------------------------------------------------------------*/
/**
 * @brief <structure or typedef description>
 */
//typedef enum
//{
//  modENUM1 = 0,              /**< Enumerator 1 */
//  modENUM2                   /**< Enumerator 2 */
//} eL3GD20_Enumeration_t; /**< L3GD20 enum type */


/**
 * @brief <structure or typedef description>
 */
//typedef struct
//{
//  eL3GD20_Enumeration_t   Enumerable;  /**< Enumerable */
//} L3GD20_Member_t; /**< Member Type */


/**
 * @brief <structure or typedef description>
 */
typedef struct
{
	SPI_HandleTypeDef	*	hSPI;
  GPIO_TypeDef			*	CS_Port;
  uint32_t						CS_Pin;
  GPIO_TypeDef			* INT1_Port;
  uint32_t						INT1_Pin;
  GPIO_TypeDef			*	INT2_Port;
  uint32_t						INT2_Pin;
} L3GD20_HandleTypeDef; /**< L3GD20 Handle Type Definition */

/* Exported Variables --------------------------------------------------------------------*/
/* External variables --------------------------------------------------------------------*/
/* Exported Functions --------------------------------------------------------------------*/
/* Initialization Function */
int32_t L3GD20_Init (L3GD20_HandleTypeDef* p_par_hL3GD20);
uint32_t L3GD20_ReadRegister(L3GD20_HandleTypeDef *p_par_hGyro, uint8_t par_Reg, uint8_t *p_par_Rx, uint8_t par_Size);


/**
  * @}
  */

  
#ifdef __cplusplus
}
#endif


#endif /* __L3GD20_H__ */


/****************  ******END OF FILE******/
