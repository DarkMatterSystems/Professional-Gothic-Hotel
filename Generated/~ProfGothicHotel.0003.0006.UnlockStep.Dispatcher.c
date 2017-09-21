
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlock Step Dispatcher */

/* Dispatcher */

void adm_dispatcher_unlock_step(
    void)
{
    adm_pool_target_unlock_step_typ * pool_target_unlock_step;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_unlock_step");
    #endif

    pool_target_unlock_step = adm_find_away_target_event_unlock_step();

    adm_dispatch_state_action_unlock_step(pool_target_unlock_step);

    adm_dispatch_home_pool_unlock_step();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_unlock_step");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_unlock_step(
    void)
{
    adm_pool_target_unlock_step_typ * pool_target_unlock_step;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_unlock_step");
    #endif

    while (adm_entity_system.ent_unlock_step.home_pool_head != NULL) {

        pool_target_unlock_step = adm_find_home_target_event_unlock_step();

        adm_dispatch_state_action_unlock_step(pool_target_unlock_step);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_unlock_step");
    #endif
}


/* Find Home Target Event */

adm_pool_target_unlock_step_typ * adm_find_home_target_event_unlock_step(
    void)
{
    adm_pool_target_unlock_step_typ * pool_target_unlock_step;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_unlock_step");
    #endif

    pool_target_unlock_step = adm_entity_system.ent_unlock_step.home_pool_head;

    adm_entity_system.ent_unlock_step.home_pool_head = pool_target_unlock_step->next;

    if (adm_entity_system.ent_unlock_step.home_pool_head == NULL) {

        adm_entity_system.ent_unlock_step.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_unlock_step");
    #endif

    return (pool_target_unlock_step);
}


/* Find Away Target Event */

adm_pool_target_unlock_step_typ * adm_find_away_target_event_unlock_step(
    void)
{
    adm_pool_target_unlock_step_typ * pool_target_unlock_step;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_unlock_step");
    #endif

    pool_target_unlock_step = adm_entity_system.ent_unlock_step.away_pool_head;

    adm_entity_system.ent_unlock_step.away_pool_head = pool_target_unlock_step->next;

    if (adm_entity_system.ent_unlock_step.away_pool_head == NULL) {

        adm_entity_system.ent_unlock_step.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_unlock_step");
    #endif

    return (pool_target_unlock_step);
}


/* Dispatch State Action */

void adm_dispatch_state_action_unlock_step(
    adm_pool_target_unlock_step_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_unlock_step");
    #endif

    if (pool_target->ent_unlock_step != NULL) {

        adm_object_existent_unlock_step(
            pool_target->ent_unlock_step,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_UNLOCK_STEP_RESET :

            switch ((pool_target->ent_unlock_step)->status) {

                case ADM_STATUS_UNLOCK_STEP_WRONG_STEP :

                    adm_sim_display_state_unlock_step_locked(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_LOCKED;

                break;

                case ADM_STATUS_UNLOCK_STEP_SELECTED :

                    adm_sim_display_state_unlock_step_locked(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_LOCKED;

                break;

                case ADM_STATUS_UNLOCK_STEP_PRIMED :

                    adm_sim_display_state_unlock_step_locked(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_LOCKED;

                break;

                case ADM_STATUS_UNLOCK_STEP_UNLOCKED :

                    adm_sim_display_state_unlock_step_locked(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_LOCKED;

                break;
            }

        break;

        case ADM_EVENT_UNLOCK_STEP_ADVANCE :

            switch ((pool_target->ent_unlock_step)->status) {

                case ADM_STATUS_UNLOCK_STEP_SELECTED :

                    adm_sim_display_state_unlock_step_wrong_step(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_WRONG_STEP;

                    adm_state_action_unlock_step_wrong_step(
                        pool_target->ent_unlock_step);

                break;

                case ADM_STATUS_UNLOCK_STEP_PRIMED :

                    adm_sim_display_state_unlock_step_unlocked(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_UNLOCKED;

                    adm_state_action_unlock_step_unlocked(
                        pool_target->ent_unlock_step);

                break;

                case ADM_STATUS_UNLOCK_STEP_UNLOCKED :

                    adm_sim_display_state_unlock_step_wrong_step(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_WRONG_STEP;

                    adm_state_action_unlock_step_wrong_step(
                        pool_target->ent_unlock_step);

                break;
            }

        break;

        case ADM_EVENT_UNLOCK_STEP_SELECT :

            switch ((pool_target->ent_unlock_step)->status) {

                case ADM_STATUS_UNLOCK_STEP_WRONG_STEP :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Select",
                        "State:Wrong_Step");

                break;

                case ADM_STATUS_UNLOCK_STEP_LOCKED :

                    adm_sim_display_state_unlock_step_selected(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_SELECTED;

                break;

                case ADM_STATUS_UNLOCK_STEP_SELECTED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Select",
                        "State:Selected");

                break;

                case ADM_STATUS_UNLOCK_STEP_PRIMED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Select",
                        "State:Primed");

                break;

                case ADM_STATUS_UNLOCK_STEP_UNLOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Select",
                        "State:Unlocked");

                break;
            }

        break;

        case ADM_EVENT_UNLOCK_STEP_PRIME :

            switch ((pool_target->ent_unlock_step)->status) {

                case ADM_STATUS_UNLOCK_STEP_WRONG_STEP :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Prime",
                        "State:Wrong_Step");

                break;

                case ADM_STATUS_UNLOCK_STEP_LOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Prime",
                        "State:Locked");

                break;

                case ADM_STATUS_UNLOCK_STEP_SELECTED :

                    adm_sim_display_state_unlock_step_primed(pool_target);

                    (pool_target->ent_unlock_step)->status = ADM_STATUS_UNLOCK_STEP_PRIMED;

                break;

                case ADM_STATUS_UNLOCK_STEP_PRIMED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Prime",
                        "State:Primed");

                break;

                case ADM_STATUS_UNLOCK_STEP_UNLOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Unlock_Step",
                        (pool_target->ent_unlock_step)->identity,
                        "Event:Prime",
                        "State:Unlocked");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_unlock_step");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */