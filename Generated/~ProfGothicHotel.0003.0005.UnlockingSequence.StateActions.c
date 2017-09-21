
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Sequence State Actions */

void adm_state_action_unlocking_sequence_idle(
    adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence)
{
    /* Entity Objects */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001;

    /* Relationship Relations */
    adm_rel_unlocking_sequence_starts_at_unlock_step_typ * rel_unlocking_sequence_starts_at_unlock_step_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_sequence_idle");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        6, 21, 29);

    rel_unlocking_sequence_starts_at_unlock_step_0000000001 = ent_unlocking_sequence->rel_starts_at_unlock_step_head;

    if (rel_unlocking_sequence_starts_at_unlock_step_0000000001 != NULL) {

        ent_unlock_step_0000000001 = rel_unlocking_sequence_starts_at_unlock_step_0000000001->ent_unlock_step;

        /* ProcessEntityInclude - Procedure: 0106_Process_Reset_Unlock_Steps */

        adm_ent_pro_unlocking_sequence_0106_process_reset_unlock_steps(
            ent_unlock_step_0000000001,
            ent_unlocking_sequence);

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            6, 21, 29,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            "Starts_at",
            "Unlock_Step");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_sequence_idle");
    #endif
}

void adm_state_action_unlocking_sequence_active(
    adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence)
{
    /* Entity Objects */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000001;
    adm_ent_unlock_step_typ * ent_unlock_step_0000000004;

    /* Relationship Relations */
    adm_rel_unlocking_sequence_starts_at_unlock_step_typ * rel_unlocking_sequence_starts_at_unlock_step_0000000001;
    adm_rel_unlocking_sequence_starts_at_unlock_step_typ * rel_unlocking_sequence_starts_at_unlock_step_0000000004;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_sequence_active");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        6, 42, 29);

    rel_unlocking_sequence_starts_at_unlock_step_0000000001 = ent_unlocking_sequence->rel_starts_at_unlock_step_head;

    if (rel_unlocking_sequence_starts_at_unlock_step_0000000001 != NULL) {

        ent_unlock_step_0000000001 = rel_unlocking_sequence_starts_at_unlock_step_0000000001->ent_unlock_step;

        /* ProcessEntityInclude - Procedure: 0106_Process_Select_Unlock_Steps */

        adm_ent_pro_unlocking_sequence_0106_process_select_unlock_steps(
            ent_unlock_step_0000000001,
            ent_unlocking_sequence);

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            6, 42, 29,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            "Starts_at",
            "Unlock_Step");
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        6, 54, 29);

    rel_unlocking_sequence_starts_at_unlock_step_0000000004 = ent_unlocking_sequence->rel_starts_at_unlock_step_head;

    if (rel_unlocking_sequence_starts_at_unlock_step_0000000004 != NULL) {

        ent_unlock_step_0000000004 = rel_unlocking_sequence_starts_at_unlock_step_0000000004->ent_unlock_step;

        /* GenerateEvent */

        adm_send_event_unlock_step_prime(
            ent_unlocking_sequence,
            ent_unlock_step_0000000004,
            6, 57, 33);

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            6, 54, 29,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            "Starts_at",
            "Unlock_Step");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_sequence_active");
    #endif
}

void adm_state_action_unlocking_sequence_complete(
    adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence)
{
    /* Entity Objects */
    adm_ent_secret_panel_typ * ent_secret_panel_0000000001;

    /* Relationship Relations */
    adm_rel_unlocking_sequence_opens_secret_panel_typ * rel_unlocking_sequence_opens_secret_panel_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_sequence_complete");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        6, 75, 29);

    rel_unlocking_sequence_opens_secret_panel_0000000001 = ent_unlocking_sequence->rel_opens_secret_panel_head;

    if (rel_unlocking_sequence_opens_secret_panel_0000000001 != NULL) {

        ent_secret_panel_0000000001 = rel_unlocking_sequence_opens_secret_panel_0000000001->ent_secret_panel;

        /* GenerateEvent */

        adm_send_event_secret_panel_unlock_panel(
            ent_unlocking_sequence,
            ent_secret_panel_0000000001,
            6, 78, 33);

    } else {

        adm_error_report(
            ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
            6, 75, 29,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            "Opens",
            "Secret_Panel");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_unlocking_sequence_complete");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */