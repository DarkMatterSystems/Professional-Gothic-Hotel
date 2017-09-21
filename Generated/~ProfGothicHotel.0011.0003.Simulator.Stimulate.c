
#include "~ProfGothicHotel.0000.0000.Header.h"


/* System Stimulate */

void adm_sim_simulate(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_simulate");
    #endif

    if (adm_sim_err_success) {

        while (
            adm_entity_system.ent_room_device.away_pool_head != NULL ||
            adm_entity_system.ent_room_door.away_pool_head != NULL ||
            adm_entity_system.ent_secret_panel.away_pool_head != NULL ||
            adm_entity_system.ent_unlocking_device.away_pool_head != NULL ||
            adm_entity_system.ent_unlocking_sequence.away_pool_head != NULL ||
            adm_entity_system.ent_unlock_step.away_pool_head != NULL) {

            adm_scheduler_dom_gothic_security();
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_simulate");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */