
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Room Door Display State */

void adm_sim_display_state_room_door_open(
    adm_pool_target_room_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_open");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:16:26) - Room_Door[");
        printf("%d", (pool_target->ent_room_door)->identity);
        printf("] ");
        printf("Open");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_room_door[(pool_target->ent_room_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_open");
    #endif
}

void adm_sim_display_state_room_door_closed(
    adm_pool_target_room_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_closed");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:44:26) - Room_Door[");
        printf("%d", (pool_target->ent_room_door)->identity);
        printf("] ");
        printf("Closed");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_room_door[(pool_target->ent_room_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_closed");
    #endif
}

void adm_sim_display_state_room_door_locked(
    adm_pool_target_room_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_locked");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:72:26) - Room_Door[");
        printf("%d", (pool_target->ent_room_door)->identity);
        printf("] ");
        printf("Locked");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_room_door[(pool_target->ent_room_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_locked");
    #endif
}

void adm_sim_display_state_room_door_unlocked(
    adm_pool_target_room_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_unlocked");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("STATE (3:91:26) - Room_Door[");
        printf("%d", (pool_target->ent_room_door)->identity);
        printf("] ");
        printf("Unlocked");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_room_door[(pool_target->ent_room_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_room_door_unlocked");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */