
#include "~ProfGothicHotel.0000.0000.Header.h"


/* System Main Program */

int main(
    int    argc,
    char * argv[])
{
    #if ADM_PROBE
    adm_probe_display.all            = FALSE;
    adm_probe_display.none           = FALSE;
    adm_probe_display.main_program   = TRUE;
    adm_probe_display.initialisation = TRUE;
    adm_probe_display.scheduler      = FALSE;
    adm_probe_display.dispatcher     = FALSE;
    adm_probe_display.state_action   = TRUE;
    adm_probe_display.data_access    = FALSE;
    adm_probe_display.event_sender   = TRUE;
    adm_probe_display.enumeration    = FALSE;
    adm_probe_display.library        = FALSE;
    adm_probe_display.identifier     = FALSE;
    adm_probe_display.error          = TRUE;
    adm_probe_display.simulator      = FALSE;
    adm_probe_display.level          = 0;
    #endif

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_MAIN_PROGRAM, "main");
    #endif

    adm_sim_main(
        argc,
        argv);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_MAIN_PROGRAM, "main");
    #endif

    return (ADM_ERROR_NO_ERROR);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */