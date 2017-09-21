
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Unlocking Sequence Acquire Identity Event */

void adm_sim_acquire_identity_event_unlocking_sequence_activate(
    void)
{
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlocking_sequence_activate");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.live_list_head;

    while (
        entity_not_found &&
        ent_unlocking_sequence != NULL) {

        if (ent_unlocking_sequence->identity == identity) {

            adm_send_event_unlocking_sequence_activate(
                NULL,
                ent_unlocking_sequence,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlocking_sequence = ent_unlocking_sequence->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlocking_sequence_activate");
    #endif
}

void adm_sim_acquire_identity_event_unlocking_sequence_reset(
    void)
{
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlocking_sequence_reset");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.live_list_head;

    while (
        entity_not_found &&
        ent_unlocking_sequence != NULL) {

        if (ent_unlocking_sequence->identity == identity) {

            adm_send_event_unlocking_sequence_reset(
                NULL,
                ent_unlocking_sequence,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlocking_sequence = ent_unlocking_sequence->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlocking_sequence_reset");
    #endif
}

void adm_sim_acquire_identity_event_unlocking_sequence_complete(
    void)
{
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlocking_sequence_complete");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.live_list_head;

    while (
        entity_not_found &&
        ent_unlocking_sequence != NULL) {

        if (ent_unlocking_sequence->identity == identity) {

            adm_send_event_unlocking_sequence_complete(
                NULL,
                ent_unlocking_sequence,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlocking_sequence = ent_unlocking_sequence->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlocking_sequence_complete");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */