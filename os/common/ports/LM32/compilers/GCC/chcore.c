/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    templates/chcore.c
 * @brief   Port related template code.
 * @details This file is a template of the system driver functions provided by
 *          a port. Some of the following functions may be implemented as
 *          macros in chcore.h if the implementer decides that there is an
 *          advantage in doing so, for example because performance concerns.
 *
 * @addtogroup core
 * @details Non portable code templates.
 * @{
 */

#include "ch.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

bool __lm32_in_isr;

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*
565	                r_IE.IE  = (0x1 & wData)? 1: 0;
566	                r_IE.EIE = (0x2 & wData)? 1: 0;
567	                r_IE.BIE = (0x4 & wData)? 1: 0;

reg ie;                                         // Interrupt enable
reg eie;                                        // Exception interrupt enable
`ifdef CFG_DEBUG_ENABLED
reg bie;                                        // Breakpoint interrupt enable

*/

static inline unsigned int irq_getie(void)
{
  unsigned int ie;
  __asm__ __volatile__("rcsr %0, IE" : "=r" (ie));
  return ie;
}

static inline void irq_setie(unsigned int ie)
{
  __asm__ __volatile__("wcsr IE, %0" : : "r" (ie));
}

static inline unsigned int irq_getmask(void)
{
  unsigned int mask;
  __asm__ __volatile__("rcsr %0, IM" : "=r" (mask));
  return mask;
}

static inline void irq_setmask(unsigned int mask)
{
  __asm__ __volatile__("wcsr IM, %0" : : "r" (mask));
}

static inline unsigned int irq_pending(void)
{
  unsigned int pending;
  __asm__ __volatile__("rcsr %0, IP" : "=r" (pending));
  return pending;
}


/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Port-related initialization code.
 * @note    This function is usually empty.
 */
void _port_init(void) {
}

/**
 * @brief   Performs a context switch between two threads.
 * @details This is the most critical code in any port, this function
 *          is responsible for the context switch between 2 threads.
 * @note    The implementation of this code affects <b>directly</b> the context
 *          switch performance so optimize here as much as you can.
 *
 * @param[in] ntp       the thread to be switched in
 * @param[in] otp       the thread to be switched out
 */
void _port_switch(thread_t *ntp, thread_t *otp) {
}

/** @} */
