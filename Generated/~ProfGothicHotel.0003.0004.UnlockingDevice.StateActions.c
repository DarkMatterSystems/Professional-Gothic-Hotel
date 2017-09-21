
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Device State Actions */

void adm_state_action_unlocking_device_updating(
    adm_ent_unlocking_device_typ * const ent_unlocking_device)
{
    /* Entity Objects */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001;

    /* Relationship Relations */
    adm_rel_unlocking_device_sets_unlock_step_typ * rel_unlocking_device_sets_unlock_step_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_device_updating");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_unlocking_device(
        ent_unlocking_device,
        5, 15, 29);

    rel_unlocking_device_sets_unlock_step_0000000001 = ent_unlocking_device->rel_sets_unlock_step_head;

    if (rel_unlocking_device_sets_unlock_step_0000000001 != NULL) {

        while (rel_unlocking_device_sets_unlock_step_0000000001 != NULL) {

            ent_unlock_step_0000000001 = rel_unlocking_device_sets_unlock_step_0000000001->ent_unlock_step;

            /* GenerateEvent */

            adm_send_event_unlock_step_advance(
                ent_unlocking_device,
                ent_unlock_step_0000000001,
                5, 18, 33);

            rel_unlocking_device_sets_unlock_step_0000000001 = rel_unlocking_device_sets_unlock_step_0000000001->next;
        }

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            5, 15, 29,
            "Unlocking_Device",
            ent_unlocking_device->identity,
            "Sets",
            "Unlock_Step");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_device_updating");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */