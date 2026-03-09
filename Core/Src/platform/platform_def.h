/*
 * platform_def.h
 * @brief   This file contains HAL common defines, enumeration, macros and
 * structures definitions.
 */

#ifndef SRC_PLATFORM_PLATFORM_DEF_H_
#define SRC_PLATFORM_PLATFORM_DEF_H_

typedef enum
{
  PLT_OK       = 0x00U,
  PLT_ERROR    = 0x01U,
  PLT_BUSY     = 0x02U,
  PLT_TIMEOUT  = 0x03U
} plt_status_t;

#endif /* SRC_PLATFORM_PLATFORM_DEF_H_ */
