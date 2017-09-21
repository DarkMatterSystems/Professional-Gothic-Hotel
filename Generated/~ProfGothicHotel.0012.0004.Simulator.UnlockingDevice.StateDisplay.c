
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Unlocking Device Display State */

void adm_sim_display_state_unlocking_device_updating(
    adm_pool_target_unlocking_device_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_device_updating");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (5:11:26) - Unlocking_Device[");
        printf("%d", (pool_target->ent_unlocking_device)->identity);
        printf("] ");
        printf("Updating");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_DEVICE, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlocking_device[(pool_target->ent_unlocking_device)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_device_updating");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */