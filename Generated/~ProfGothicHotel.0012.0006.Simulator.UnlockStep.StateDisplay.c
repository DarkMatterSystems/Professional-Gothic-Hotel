
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Unlock Step Display State */

void adm_sim_display_state_unlock_step_wrong_step(
    adm_pool_target_unlock_step_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_wrong_step");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (9:14:26) - Unlock_Step[");
        printf("%d", (pool_target->ent_unlock_step)->identity);
        printf("] ");
        printf("Wrong_Step");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlock_step[(pool_target->ent_unlock_step)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_wrong_step");
    #endif
}

void adm_sim_display_state_unlock_step_locked(
    adm_pool_target_unlock_step_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_locked");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (9:34:26) - Unlock_Step[");
        printf("%d", (pool_target->ent_unlock_step)->identity);
        printf("] ");
        printf("Locked");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlock_step[(pool_target->ent_unlock_step)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_locked");
    #endif
}

void adm_sim_display_state_unlock_step_selected(
    adm_pool_target_unlock_step_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_selected");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (9:46:26) - Unlock_Step[");
        printf("%d", (pool_target->ent_unlock_step)->identity);
        printf("] ");
        printf("Selected");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlock_step[(pool_target->ent_unlock_step)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_selected");
    #endif
}

void adm_sim_display_state_unlock_step_primed(
    adm_pool_target_unlock_step_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_primed");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (9:57:26) - Unlock_Step[");
        printf("%d", (pool_target->ent_unlock_step)->identity);
        printf("] ");
        printf("Primed");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlock_step[(pool_target->ent_unlock_step)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_primed");
    #endif
}

void adm_sim_display_state_unlock_step_unlocked(
    adm_pool_target_unlock_step_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_unlocked");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (9:68:26) - Unlock_Step[");
        printf("%d", (pool_target->ent_unlock_step)->identity);
        printf("] ");
        printf("Unlocked");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_unlock_step[(pool_target->ent_unlock_step)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_unlock_step_unlocked");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */