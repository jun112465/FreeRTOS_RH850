#if !defined(DERIVATIVE_H)
#define DERIVATIVE_H

#include "iodefine.h"
#include <builtin.h>

#define __NOP() __nop()
#define __STSR(regID, selID) __stsr_rh(regID, selID)
#define __LDSR(regID, selID, val) __ldsr_rh(regID, selID, val)

#define protected_write(preg, pstatus, reg, value) \
    do                                             \
    {                                              \
        (preg) = 0xa5u;                            \
        (reg) = (value);                           \
        (reg) = ~(value);                          \
        (reg) = (value);                           \
    } while ((pstatus) == 1u)

#define software_reset() protected_write(PROTCMD0, PROTS0, SWRESA, 1)

#endif // DERIVATIVE_H
