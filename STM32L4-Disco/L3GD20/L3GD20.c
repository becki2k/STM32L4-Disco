/*******************************************************************************************
 * @file L3GD20.c
 * @author Matthias Becker
 * @version V1.0.0.0
 * @date 31-May-2016
 * @brief this file implements .....
 *
 * @verbatim
     
 ==========================================================================================
                               ##### How to use this driver #####
 ==========================================================================================
  [1] Include Header File to the Project
  [2] Register a L3GD20 handle type definition
  [3] <Step3>

 @endverbatim
 *******************************************************************************************
 * @attention 
 *
 * <h2><center></center></h2>
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted.
 *
 *******************************************************************************************
 */
 
/* Includes ------------------------------------------------------------------------------*/
#include "L3GD20.h"

/** @addtogroup L3GD20 Group Name
  * @{
  */
   
/* Defines -------------------------------------------------------------------------------*/
#define DEBUG 1
/* Private macro -------------------------------------------------------------------------*/
/* Private types -------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------*/
uint8_t Dummy = 0xFF;
/* Private function prototypes -----------------------------------------------------------*/
/* Exported functions --------------------------------------------------------------------*/
/**
 * @brief Initialize the L3GD20 handle
 * 
 * @param p_par_hL3GD20 Pointer to a L3GD20 handle type definition structure
 *
 * @retval L3GD20_RET_OK init successful
 * @retval L3GD20_RET_ERROR_HANDLE_NULL handle is null
 * @retval L3GD20_RET_ERROR_POINTER_NULL pointer to variable is null
 */
int32_t L3GD20_Init( L3GD20_HandleTypeDef* p_par_hL3GD20 )
{
  if(DEBUG) printf("Start Init\n");
  /* check the handle pointers and return with error if null */
  if( p_par_hL3GD20 == NULL ) return L3GD20_RET_ERROR_HANDLE_NULL;
  if( p_par_hL3GD20->hSPI == NULL ) return L3GD20_RET_ERROR_POINTER_NULL;
  
  // TODO Initialization Stuff
  
  /* Init ok, quit */
  if(DEBUG) printf("Ende Init\n");
  if(DEBUG) printf("------------------------\n");
  return L3GD20_RET_OK;
}

/**
 * @brief ..
 * @details ...
 *
 * @param ...
 * @retval ...
 */
uint32_t L3GD20_ReadRegister(L3GD20_HandleTypeDef *p_par_hGyro, uint8_t par_Reg, uint8_t *p_par_Rx, uint8_t par_Size)
{
	if(DEBUG) printf("Read Register: %X\n", par_Reg);
	uint8_t TxBuf[par_Size+1];
	uint8_t RxBuf[par_Size+1];
	uint8_t * pTxBuf = TxBuf;
	uint8_t * pRxBuf = RxBuf;
	
	TxBuf[0] = par_Reg & L3GD20_READ;
	for(int i=1; i<=par_Size; i++){
		TxBuf[i] = Dummy;
	}
	HAL_SPI_TransmitReceive(p_par_hGyro->hSPI, pTxBuf, pRxBuf, par_Size+1, 1);
	for(int i=1;i<=par_Size;i++){
		p_par_Rx[i-1] = RxBuf[i];
	}
	if(DEBUG) printf("Content: %X\n", p_par_Rx[0]);
	if(DEBUG) printf("------------------------\n");
	return L3GD20_RET_OK;
}

/**
 * @brief ..
 * @details ...
 *
 * @param ...
 * @retval ...
 */
uint32_t L3GD20_WriteRegister(L3GD20_HandleTypeDef *p_par_hGyro, uint8_t *p_par_Tx, uint8_t par_Size){
	
	return L3GD20_RET_OK;
}


/* Private functions ---------------------------------------------------------------------*/
/**
 * @brief <tag or short description>
 * 
 * <description> 
 *
 * @param <parameter>
 *
 * @retval <return value>
 */
 

/**
  * @}
  */

  
/**************** ******END OF FILE******/
