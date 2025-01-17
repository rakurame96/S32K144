/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 * 
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with  
 * the terms contained in the written license agreement between you and ArcCore, 
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as 
 * published by the Free Software Foundation and appearing in the file 
 * LICENSE.GPL included in the packaging of this file or here 
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/
/** @reqSettings DEFAULT_SPECIFICATION_REVISION=4.0.3 */
#ifndef MEMIF_H_
#define MEMIF_H_

#define MEMIF_MODULE_ID			22u
#define MEMIF_VENDOR_ID			60u
/* @req MemIf064 */
#define MEMIF_SW_MAJOR_VERSION	1u
#define MEMIF_SW_MINOR_VERSION	0u
#define MEMIF_SW_PATCH_VERSION	0u
#define MEMIF_AR_MAJOR_VERSION  4u
#define MEMIF_AR_MINOR_VERSION  0u
#define MEMIF_AR_PATCH_VERSION  3u
#define MEMIF_AR_RELEASE_MAJOR_VERSION      MEMIF_AR_MAJOR_VERSION
#define MEMIF_AR_RELEASE_MINOR_VERSION      MEMIF_AR_MINOR_VERSION
#define MEMIF_AR_RELEASE_REVISION_VERSION   MEMIF_AR_PATCH_VERSION

/* Service ids */
#define MEMIF_SETMODE_ID                0x01u
#define MEMIF_READ_ID                   0x02u
#define MEMIF_WRITE_ID                  0x03u
#define MEMIF_CANCEL_ID                 0x04u
#define MEMIF_GETSTATUS_ID              0x05u
#define MEMIF_GETJOBRESULT_ID           0x06u
#define MEMIF_INVALIDATEBLOCK_ID        0x07u
#define MEMIF_GETVERSIONINFO_ID         0x08u
#define MEMIF_ERASEIMMEDIATEBLOCK_ID    0x09u


/* Error Ids */
/* @req MemIf030 */
#define MEMIF_E_PARAM_DEVICE    0x01u
#define MEMIF_E_PARAM_POINTER   0x02u

/* @req MemIf037 */
#include "Std_Types.h"
#include "Fee.h"


#if defined(USE_EA)
#include "Ea.h"
#endif

/* @req MemIf061 */
#if (MEMIF_NUMBER_OF_DEVICES > 2)
#error "MemIf: Only 2 devices supported"
#endif

/* @req MemIf057 */
#if (MEMIF_VERSION_INFO_API == STD_ON)
/* @req MemIf045 */
/* !req MemIf063 */
#define MemIf_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi, MEMIF)
#endif /* MEMIF_VERSION_INFO_API */



#define MemIf_SetMode(_mode)	Fee_SetMode(_mode)
#define MemIf_Read(_deviceIndex,_blockNumber,_blockOffset,_dataBufferPtr,_length)	Fee_Read(_blockNumber,_blockOffset,_dataBufferPtr,_length)
#define MemIf_Write(_deviceIndex,_blockNumber,_dataBufferPtr)	Fee_Write(_blockNumber,_dataBufferPtr)
#define MemIf_Cancel(_deviceIndex)	Fee_Cancel()
#define MemIf_GetStatus(_deviceIndex)	Fee_GetStatus()
#define MemIf_GetJobResult(_deviceIndex)	Fee_GetJobResult()
#define MemIf_InvalidateBlock(_deviceIndex,_blockNumber)	Fee_InvalidateBlock(_blockNumber)
#define MemIf_EraseImmediateBlock(_deviceIndex,_blockNumber)	Fee_EraseImmediateBlock(_blockNumber)




 

#endif /*MEMIF_H_*/
