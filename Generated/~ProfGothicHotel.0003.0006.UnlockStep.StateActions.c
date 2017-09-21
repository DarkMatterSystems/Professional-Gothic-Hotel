
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlock Step State Actions */

void adm_state_action_unlock_step_wrong_step(
    adm_ent_unlock_step_typ * const ent_unlock_step)
{
    /* Entity Objects */
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000001;

    /* Relationship Relations */
    adm_rel_unlock_step_part_of_unlocking_sequence_typ * rel_unlock_step_part_of_unlocking_sequence_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlock_step_wrong_step");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_unlock_step(
        ent_unlock_step,
        9, 19, 29);

    rel_unlock_step_part_of_unlocking_sequence_0000000001 = ent_unlock_step->rel_part_of_unlocking_sequence_head;

    if (rel_unlock_step_part_of_unlocking_sequence_0000000001 != NULL) {

        ent_unlocking_sequence_0000000001 = rel_unlock_step_part_of_unlocking_sequence_0000000001->ent_unlocking_sequence;

        /* GenerateEvent */

        adm_send_event_unlocking_sequence_reset(
            ent_unlock_step,
            ent_unlocking_sequence_0000000001,
            9, 22, 33);

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            9, 19, 29,
            "Unlock_Step",
            ent_unlock_step->identity,
            "Part_of",
            "Unlocking_Sequence");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlock_step_wrong_step");
    #endif
}

void adm_state_action_unlock_step_unlocked(
    adm_ent_unlock_step_typ * const ent_unlock_step)
{
    /* Entity Objects */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001;
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000003;

    /* Relationship Relations */
    adm_rel_unlock_step_followed_by_unlock_step_typ * rel_unlock_step_followed_by_unlock_step_0000000001;
    adm_rel_unlock_step_part_of_unlocking_sequence_typ * rel_unlock_step_part_of_unlocking_sequence_0000000003;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlock_step_unlocked");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_unlock_step(
        ent_unlock_step,
        9, 73, 29);

    traverse_not_found_0000000002 = TRUE;

    rel_unlock_step_followed_by_unlock_step_0000000001 = ent_unlock_step->rel_followed_by_unlock_step_head;

    if (rel_unlock_step_followed_by_unlock_step_0000000001 != NULL) {

        ent_unlock_step_0000000001 = rel_unlock_step_followed_by_unlock_step_0000000001->ent_unlock_step;

        traverse_not_found_0000000002 = FALSE;

        /* GenerateEvent */

        adm_send_event_unlock_step_prime(
            ent_unlock_step,
            ent_unlock_step_0000000001,
            9, 77, 33);
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Traverse - TraverseSelection */

        adm_object_existent_unlock_step(
            ent_unlock_step,
            9, 83, 37);

        rel_unlock_step_part_of_unlocking_sequence_0000000003 = ent_unlock_step->rel_part_of_unlocking_sequence_head;

        if (rel_unlock_step_part_of_unlocking_sequence_0000000003 != NULL) {

            ent_unlocking_sequence_0000000003 = rel_unlock_step_part_of_unlocking_sequence_0000000003->ent_unlocking_sequence;

            /* GenerateEvent */

            adm_send_event_unlocking_sequence_complete(
                ent_unlock_step,
                ent_unlocking_sequence_0000000003,
                9, 86, 41);

        } else {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                9, 83, 37,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Part_of",
                "Unlocking_Sequence");
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlock_step_unlocked");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */