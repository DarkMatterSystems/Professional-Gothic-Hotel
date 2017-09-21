
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Unlock Step Acquire Identity Event */

void adm_sim_acquire_identity_event_unlock_step_reset(
    void)
{
    adm_ent_unlock_step_typ * ent_unlock_step;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_reset");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (
        entity_not_found &&
        ent_unlock_step != NULL) {

        if (ent_unlock_step->identity == identity) {

            adm_send_event_unlock_step_reset(
                NULL,
                ent_unlock_step,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlock_step = ent_unlock_step->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_reset");
    #endif
}

void adm_sim_acquire_identity_event_unlock_step_advance(
    void)
{
    adm_ent_unlock_step_typ * ent_unlock_step;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_advance");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (
        entity_not_found &&
        ent_unlock_step != NULL) {

        if (ent_unlock_step->identity == identity) {

            adm_send_event_unlock_step_advance(
                NULL,
                ent_unlock_step,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlock_step = ent_unlock_step->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_advance");
    #endif
}

void adm_sim_acquire_identity_event_unlock_step_select(
    void)
{
    adm_ent_unlock_step_typ * ent_unlock_step;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_select");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (
        entity_not_found &&
        ent_unlock_step != NULL) {

        if (ent_unlock_step->identity == identity) {

            adm_send_event_unlock_step_select(
                NULL,
                ent_unlock_step,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlock_step = ent_unlock_step->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_select");
    #endif
}

void adm_sim_acquire_identity_event_unlock_step_prime(
    void)
{
    adm_ent_unlock_step_typ * ent_unlock_step;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_prime");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (
        entity_not_found &&
        ent_unlock_step != NULL) {

        if (ent_unlock_step->identity == identity) {

            adm_send_event_unlock_step_prime(
                NULL,
                ent_unlock_step,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_unlock_step = ent_unlock_step->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_unlock_step_prime");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */