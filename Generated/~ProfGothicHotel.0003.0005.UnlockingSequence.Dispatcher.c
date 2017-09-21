
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Sequence Dispatcher */

/* Dispatcher */

void adm_dispatcher_unlocking_sequence(
    void)
{
    adm_pool_target_unlocking_sequence_typ * pool_target_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_unlocking_sequence");
    #endif

    pool_target_unlocking_sequence = adm_find_away_target_event_unlocking_sequence();

    adm_dispatch_state_action_unlocking_sequence(pool_target_unlocking_sequence);

    adm_dispatch_home_pool_unlocking_sequence();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_unlocking_sequence");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_unlocking_sequence(
    void)
{
    adm_pool_target_unlocking_sequence_typ * pool_target_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_unlocking_sequence");
    #endif

    while (adm_entity_system.ent_unlocking_sequence.home_pool_head != NULL) {

        pool_target_unlocking_sequence = adm_find_home_target_event_unlocking_sequence();

        adm_dispatch_state_action_unlocking_sequence(pool_target_unlocking_sequence);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_unlocking_sequence");
    #endif
}


/* Find Home Target Event */

adm_pool_target_unlocking_sequence_typ * adm_find_home_target_event_unlocking_sequence(
    void)
{
    adm_pool_target_unlocking_sequence_typ * pool_target_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_unlocking_sequence");
    #endif

    pool_target_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.home_pool_head;

    adm_entity_system.ent_unlocking_sequence.home_pool_head = pool_target_unlocking_sequence->next;

    if (adm_entity_system.ent_unlocking_sequence.home_pool_head == NULL) {

        adm_entity_system.ent_unlocking_sequence.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_unlocking_sequence");
    #endif

    return (pool_target_unlocking_sequence);
}


/* Find Away Target Event */

adm_pool_target_unlocking_sequence_typ * adm_find_away_target_event_unlocking_sequence(
    void)
{
    adm_pool_target_unlocking_sequence_typ * pool_target_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_unlocking_sequence");
    #endif

    pool_target_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.away_pool_head;

    adm_entity_system.ent_unlocking_sequence.away_pool_head = pool_target_unlocking_sequence->next;

    if (adm_entity_system.ent_unlocking_sequence.away_pool_head == NULL) {

        adm_entity_system.ent_unlocking_sequence.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_unlocking_sequence");
    #endif

    return (pool_target_unlocking_sequence);
}


/* Dispatch State Action */

void adm_dispatch_state_action_unlocking_sequence(
    adm_pool_target_unlocking_sequence_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_unlocking_sequence");
    #endif

    if (pool_target->ent_unlocking_sequence != NULL) {

        adm_object_existent_unlocking_sequence(
            pool_target->ent_unlocking_sequence,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_UNLOCKING_SEQUENCE_ACTIVATE :

            switch ((pool_target->ent_unlocking_sequence)->status) {

                case ADM_STATUS_UNLOCKING_SEQUENCE_IDLE :

                    adm_sim_display_state_unlocking_sequence_active(pool_target);

                    (pool_target->ent_unlocking_sequence)->status = ADM_STATUS_UNLOCKING_SEQUENCE_ACTIVE;

                    adm_state_action_unlocking_sequence_active(
                        pool_target->ent_unlocking_sequence);

                break;

                case ADM_STATUS_UNLOCKING_SEQUENCE_ACTIVE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlocking_Sequence",
                        (pool_target->ent_unlocking_sequence)->identity,
                        "Event:Activate",
                        "State:Active");

                break;

                case ADM_STATUS_UNLOCKING_SEQUENCE_COMPLETE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlocking_Sequence",
                        (pool_target->ent_unlocking_sequence)->identity,
                        "Event:Activate",
                        "State:Complete");

                break;
            }

        break;

        case ADM_EVENT_UNLOCKING_SEQUENCE_RESET :

            switch ((pool_target->ent_unlocking_sequence)->status) {

                case ADM_STATUS_UNLOCKING_SEQUENCE_ACTIVE :

                    adm_sim_display_state_unlocking_sequence_idle(pool_target);

                    (pool_target->ent_unlocking_sequence)->status = ADM_STATUS_UNLOCKING_SEQUENCE_IDLE;

                    adm_state_action_unlocking_sequence_idle(
                        pool_target->ent_unlocking_sequence);

                break;

                case ADM_STATUS_UNLOCKING_SEQUENCE_COMPLETE :

                    adm_sim_display_state_unlocking_sequence_idle(pool_target);

                    (pool_target->ent_unlocking_sequence)->status = ADM_STATUS_UNLOCKING_SEQUENCE_IDLE;

                    adm_state_action_unlocking_sequence_idle(
                        pool_target->ent_unlocking_sequence);

                break;
            }

        break;

        case ADM_EVENT_UNLOCKING_SEQUENCE_COMPLETE :

            switch ((pool_target->ent_unlocking_sequence)->status) {

                case ADM_STATUS_UNLOCKING_SEQUENCE_IDLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlocking_Sequence",
                        (pool_target->ent_unlocking_sequence)->identity,
                        "Event:Complete",
                        "State:Idle");

                break;

                case ADM_STATUS_UNLOCKING_SEQUENCE_ACTIVE :

                    adm_sim_display_state_unlocking_sequence_complete(pool_target);

                    (pool_target->ent_unlocking_sequence)->status = ADM_STATUS_UNLOCKING_SEQUENCE_COMPLETE;

                    adm_state_action_unlocking_sequence_complete(
                        pool_target->ent_unlocking_sequence);

                break;

                case ADM_STATUS_UNLOCKING_SEQUENCE_COMPLETE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlocking_Sequence",
                        (pool_target->ent_unlocking_sequence)->identity,
                        "Event:Complete",
                        "State:Complete");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_unlocking_sequence");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */