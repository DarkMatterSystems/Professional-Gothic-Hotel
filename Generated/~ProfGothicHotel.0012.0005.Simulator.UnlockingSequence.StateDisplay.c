
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Unlocking Sequence Display State */

void adm_sim_display_state_unlocking_sequence_idle(
    adm_pool_target_unlocking_sequence_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_sequence_idle");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (6:14:26) - Unlocking_Sequence[");
        printf("%d", (pool_target->ent_unlocking_sequence)->identity);
        printf("] ");
        printf("Idle");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlocking_sequence[(pool_target->ent_unlocking_sequence)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_sequence_idle");
    #endif
}

void adm_sim_display_state_unlocking_sequence_active(
    adm_pool_target_unlocking_sequence_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_sequence_active");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (6:35:26) - Unlocking_Sequence[");
        printf("%d", (pool_target->ent_unlocking_sequence)->identity);
        printf("] ");
        printf("Active");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlocking_sequence[(pool_target->ent_unlocking_sequence)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_sequence_active");
    #endif
}

void adm_sim_display_state_unlocking_sequence_complete(
    adm_pool_target_unlocking_sequence_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_sequence_complete");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (6:67:26) - Unlocking_Sequence[");
        printf("%d", (pool_target->ent_unlocking_sequence)->identity);
        printf("] ");
        printf("Complete");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlocking_sequence[(pool_target->ent_unlocking_sequence)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlocking_sequence_complete");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */