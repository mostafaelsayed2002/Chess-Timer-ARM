#include "systick.h"
#include "reg.h"
#include "common_macros.h"

void SYSTICK_initialize(uint32 second)
{
    CLEAR_PORT(SYST_CSR);
    SYST_RVR = second * 92000000;
    SYST_CVR = 0;
    SET_BIT(SYST_CSR, 2);
    SET_BIT(SYST_CSR, 1);
}

void SYSTICK_stop()
{
    CLEAR_BIT(SYST_CSR, 0);
}
void SYSTICK_start()
{
    SET_BIT(SYST_CSR, 0);
}

void SYSTICK_reset()
{
    SYST_CVR = 0;
}