
#include "~ProfGothicHotel.0000.0000.Header.h"


/* System - Scheduler */

void adm_scheduler(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler");
    #endif

    /* Domain Scheduler */
    adm_scheduler_dom_gothic_security();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler");
    #endif
}

void adm_scheduler_initialisation(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation");
    #endif

    /* Domain Scheduler Initialisation */
    adm_scheduler_initialisation_gothic_security();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation");
    #endif
}

adm_base_boolean_typ adm_scheduler_determine_termination(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination");
    #endif

    /* Domain Scheduler Determine Termination */
    return (adm_scheduler_determine_termination_dom_gothic_security());

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */