
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Sequence Process Includes */

void adm_ent_pro_unlocking_sequence_0106_process_reset_unlock_steps(
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001,
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence)
{
    /* Entity Objects */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000003;

    /* Relationship Relations */
    adm_rel_unlock_step_followed_by_unlock_step_typ * rel_unlock_step_followed_by_unlock_step_0000000003;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_unlocking_sequence_0106_process_reset_unlock_steps");
    #endif

    /* GenerateEvent */

    adm_send_event_unlock_step_reset(
        ent_unlocking_sequence,
        ent_unlock_step_0000000001,
        7, 7, 9);

    /* Traverse - TraverseSelection */

    adm_object_existent_unlock_step(
        ent_unlock_step_0000000001,
        7, 10, 13);

    rel_unlock_step_followed_by_unlock_step_0000000003 = ent_unlock_step_0000000001->rel_followed_by_unlock_step_head;

    if (rel_unlock_step_followed_by_unlock_step_0000000003 != NULL) {

        ent_unlock_step_0000000003 = rel_unlock_step_followed_by_unlock_step_0000000003->ent_unlock_step;

        /* ProcessEntityInclude - Recursive - Procedure: 0106_Process_Reset_Unlock_Steps */

        adm_ent_pro_unlocking_sequence_0106_process_reset_unlock_steps(
            ent_unlock_step_0000000003,
            ent_unlocking_sequence);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_unlocking_sequence_0106_process_reset_unlock_steps");
    #endif
}

void adm_ent_pro_unlocking_sequence_0106_process_select_unlock_steps(
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001,
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence)
{
    /* Entity Objects */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000003;

    /* Relationship Relations */
    adm_rel_unlock_step_followed_by_unlock_step_typ * rel_unlock_step_followed_by_unlock_step_0000000003;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_unlocking_sequence_0106_process_select_unlock_steps");
    #endif

    /* GenerateEvent */

    adm_send_event_unlock_step_select(
        ent_unlocking_sequence,
        ent_unlock_step_0000000001,
        8, 7, 9);

    /* Traverse - TraverseSelection */

    adm_object_existent_unlock_step(
        ent_unlock_step_0000000001,
        8, 10, 13);

    rel_unlock_step_followed_by_unlock_step_0000000003 = ent_unlock_step_0000000001->rel_followed_by_unlock_step_head;

    if (rel_unlock_step_followed_by_unlock_step_0000000003 != NULL) {

        ent_unlock_step_0000000003 = rel_unlock_step_followed_by_unlock_step_0000000003->ent_unlock_step;

        /* ProcessEntityInclude - Recursive - Procedure: 0106_Process_Select_Unlock_Steps */

        adm_ent_pro_unlocking_sequence_0106_process_select_unlock_steps(
            ent_unlock_step_0000000003,
            ent_unlocking_sequence);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_ent_pro_unlocking_sequence_0106_process_select_unlock_steps");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */