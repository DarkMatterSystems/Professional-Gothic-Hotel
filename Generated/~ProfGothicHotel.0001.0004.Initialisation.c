
#include "~ProfGothicHotel.0000.0000.Header.h"


/* System - Initialisation */

void adm_initialisation(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation");
    #endif

    /* Indent Initialisation */
    adm_indent.width          = 0;
    adm_indent.width_template = 0;
    adm_indent.width_display  = 0;
    INIT_STR(adm_indent.tab);

    /* Stream Initialisation */
    adm_stream.active    = TRUE;
    adm_stream.streaming = FALSE;

    /* Domain Initialisation */
    adm_initialisation_gothic_security();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */