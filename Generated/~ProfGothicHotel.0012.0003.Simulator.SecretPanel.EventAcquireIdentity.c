
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Secret Panel Acquire Identity Event */

void adm_sim_acquire_identity_event_secret_panel_unlock_panel(
    void)
{
    adm_ent_secret_panel_typ * ent_secret_panel;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_secret_panel_unlock_panel");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_secret_panel = adm_entity_system.ent_secret_panel.live_list_head;

    while (
        entity_not_found &&
        ent_secret_panel != NULL) {

        if (ent_secret_panel->identity == identity) {

            adm_send_event_secret_panel_unlock_panel(
                NULL,
                ent_secret_panel,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_secret_panel = ent_secret_panel->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_secret_panel_unlock_panel");
    #endif
}

void adm_sim_acquire_identity_event_secret_panel_panel_closed(
    void)
{
    adm_ent_secret_panel_typ * ent_secret_panel;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_secret_panel_panel_closed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_secret_panel = adm_entity_system.ent_secret_panel.live_list_head;

    while (
        entity_not_found &&
        ent_secret_panel != NULL) {

        if (ent_secret_panel->identity == identity) {

            adm_send_event_secret_panel_panel_closed(
                NULL,
                ent_secret_panel,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_secret_panel = ent_secret_panel->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_secret_panel_panel_closed");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */