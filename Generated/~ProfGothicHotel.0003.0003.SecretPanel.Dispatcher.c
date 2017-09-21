
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Secret Panel Dispatcher */

/* Dispatcher */

void adm_dispatcher_secret_panel(
    void)
{
    adm_pool_target_secret_panel_typ * pool_target_secret_panel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_secret_panel");
    #endif

    pool_target_secret_panel = adm_find_away_target_event_secret_panel();

    adm_dispatch_state_action_secret_panel(pool_target_secret_panel);

    adm_dispatch_home_pool_secret_panel();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_secret_panel");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_secret_panel(
    void)
{
    adm_pool_target_secret_panel_typ * pool_target_secret_panel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_secret_panel");
    #endif

    while (adm_entity_system.ent_secret_panel.home_pool_head != NULL) {

        pool_target_secret_panel = adm_find_home_target_event_secret_panel();

        adm_dispatch_state_action_secret_panel(pool_target_secret_panel);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_secret_panel");
    #endif
}


/* Find Home Target Event */

adm_pool_target_secret_panel_typ * adm_find_home_target_event_secret_panel(
    void)
{
    adm_pool_target_secret_panel_typ * pool_target_secret_panel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_secret_panel");
    #endif

    pool_target_secret_panel = adm_entity_system.ent_secret_panel.home_pool_head;

    adm_entity_system.ent_secret_panel.home_pool_head = pool_target_secret_panel->next;

    if (adm_entity_system.ent_secret_panel.home_pool_head == NULL) {

        adm_entity_system.ent_secret_panel.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_secret_panel");
    #endif

    return (pool_target_secret_panel);
}


/* Find Away Target Event */

adm_pool_target_secret_panel_typ * adm_find_away_target_event_secret_panel(
    void)
{
    adm_pool_target_secret_panel_typ * pool_target_secret_panel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_secret_panel");
    #endif

    pool_target_secret_panel = adm_entity_system.ent_secret_panel.away_pool_head;

    adm_entity_system.ent_secret_panel.away_pool_head = pool_target_secret_panel->next;

    if (adm_entity_system.ent_secret_panel.away_pool_head == NULL) {

        adm_entity_system.ent_secret_panel.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_secret_panel");
    #endif

    return (pool_target_secret_panel);
}


/* Dispatch State Action */

void adm_dispatch_state_action_secret_panel(
    adm_pool_target_secret_panel_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_secret_panel");
    #endif

    if (pool_target->ent_secret_panel != NULL) {

        adm_object_existent_secret_panel(
            pool_target->ent_secret_panel,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_SECRET_PANEL_UNLOCK_PANEL :

            switch ((pool_target->ent_secret_panel)->status) {

                case ADM_STATUS_SECRET_PANEL_CLOSED :

                    adm_sim_display_state_secret_panel_opened(pool_target);

                    (pool_target->ent_secret_panel)->status = ADM_STATUS_SECRET_PANEL_OPENED;

                    adm_state_action_secret_panel_opened(
                        pool_target->ent_secret_panel);

                break;

                case ADM_STATUS_SECRET_PANEL_OPENED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Secret_Panel",
                        (pool_target->ent_secret_panel)->identity,
                        "Event:Unlock_panel",
                        "State:Opened");

                break;
            }

        break;

        case ADM_EVENT_SECRET_PANEL_PANEL_CLOSED :

            switch ((pool_target->ent_secret_panel)->status) {

                case ADM_STATUS_SECRET_PANEL_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Secret_Panel",
                        (pool_target->ent_secret_panel)->identity,
                        "Event:Panel_closed",
                        "State:Closed");

                break;

                case ADM_STATUS_SECRET_PANEL_OPENED :

                    adm_sim_display_state_secret_panel_closed(pool_target);

                    (pool_target->ent_secret_panel)->status = ADM_STATUS_SECRET_PANEL_CLOSED;

                    adm_state_action_secret_panel_closed(
                        pool_target->ent_secret_panel);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_secret_panel");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */