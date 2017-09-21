
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Door Dispatcher */

/* Dispatcher */

void adm_dispatcher_room_door(
    void)
{
    adm_pool_target_room_door_typ * pool_target_room_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_room_door");
    #endif

    pool_target_room_door = adm_find_away_target_event_room_door();

    adm_dispatch_state_action_room_door(pool_target_room_door);

    adm_dispatch_home_pool_room_door();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_room_door");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_room_door(
    void)
{
    adm_pool_target_room_door_typ * pool_target_room_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_room_door");
    #endif

    while (adm_entity_system.ent_room_door.home_pool_head != NULL) {

        pool_target_room_door = adm_find_home_target_event_room_door();

        adm_dispatch_state_action_room_door(pool_target_room_door);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_room_door");
    #endif
}


/* Find Home Target Event */

adm_pool_target_room_door_typ * adm_find_home_target_event_room_door(
    void)
{
    adm_pool_target_room_door_typ * pool_target_room_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_room_door");
    #endif

    pool_target_room_door = adm_entity_system.ent_room_door.home_pool_head;

    adm_entity_system.ent_room_door.home_pool_head = pool_target_room_door->next;

    if (adm_entity_system.ent_room_door.home_pool_head == NULL) {

        adm_entity_system.ent_room_door.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_room_door");
    #endif

    return (pool_target_room_door);
}


/* Find Away Target Event */

adm_pool_target_room_door_typ * adm_find_away_target_event_room_door(
    void)
{
    adm_pool_target_room_door_typ * pool_target_room_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_room_door");
    #endif

    pool_target_room_door = adm_entity_system.ent_room_door.away_pool_head;

    adm_entity_system.ent_room_door.away_pool_head = pool_target_room_door->next;

    if (adm_entity_system.ent_room_door.away_pool_head == NULL) {

        adm_entity_system.ent_room_door.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_room_door");
    #endif

    return (pool_target_room_door);
}


/* Dispatch State Action */

void adm_dispatch_state_action_room_door(
    adm_pool_target_room_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_room_door");
    #endif

    if (pool_target->ent_room_door != NULL) {

        adm_object_existent_room_door(
            pool_target->ent_room_door,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_ROOM_DOOR_DOOR_CLOSED :

            switch ((pool_target->ent_room_door)->status) {

                case ADM_STATUS_ROOM_DOOR_OPEN :

                    adm_sim_display_state_room_door_closed(pool_target);

                    (pool_target->ent_room_door)->status = ADM_STATUS_ROOM_DOOR_CLOSED;

                    adm_state_action_room_door_closed(
                        pool_target->ent_room_door);

                break;

                case ADM_STATUS_ROOM_DOOR_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Door_closed",
                        "State:Closed");

                break;

                case ADM_STATUS_ROOM_DOOR_LOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Door_closed",
                        "State:Locked");

                break;

                case ADM_STATUS_ROOM_DOOR_UNLOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Door_closed",
                        "State:Unlocked");

                break;
            }

        break;

        case ADM_EVENT_ROOM_DOOR_DOOR_OPENED :

            switch ((pool_target->ent_room_door)->status) {

                case ADM_STATUS_ROOM_DOOR_OPEN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Door_opened",
                        "State:Open");

                break;

                case ADM_STATUS_ROOM_DOOR_CLOSED :

                    adm_sim_display_state_room_door_open(pool_target);

                    (pool_target->ent_room_door)->status = ADM_STATUS_ROOM_DOOR_OPEN;

                    adm_state_action_room_door_open(
                        pool_target->ent_room_door);

                break;

                case ADM_STATUS_ROOM_DOOR_LOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Door_opened",
                        "State:Locked");

                break;

                case ADM_STATUS_ROOM_DOOR_UNLOCKED :

                    adm_sim_display_state_room_door_open(pool_target);

                    (pool_target->ent_room_door)->status = ADM_STATUS_ROOM_DOOR_OPEN;

                    adm_state_action_room_door_open(
                        pool_target->ent_room_door);

                break;
            }

        break;

        case ADM_EVENT_ROOM_DOOR_LOCK_DOOR :

            switch ((pool_target->ent_room_door)->status) {

                case ADM_STATUS_ROOM_DOOR_OPEN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Lock_door",
                        "State:Open");

                break;

                case ADM_STATUS_ROOM_DOOR_CLOSED :

                    adm_sim_display_state_room_door_locked(pool_target);

                    (pool_target->ent_room_door)->status = ADM_STATUS_ROOM_DOOR_LOCKED;

                    adm_state_action_room_door_locked(
                        pool_target->ent_room_door);

                break;

                case ADM_STATUS_ROOM_DOOR_LOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Lock_door",
                        "State:Locked");

                break;

                case ADM_STATUS_ROOM_DOOR_UNLOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Lock_door",
                        "State:Unlocked");

                break;
            }

        break;

        case ADM_EVENT_ROOM_DOOR_UNLOCK_DOOR :

            switch ((pool_target->ent_room_door)->status) {

                case ADM_STATUS_ROOM_DOOR_OPEN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Unlock_door",
                        "State:Open");

                break;

                case ADM_STATUS_ROOM_DOOR_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Unlock_door",
                        "State:Closed");

                break;

                case ADM_STATUS_ROOM_DOOR_LOCKED :

                    adm_sim_display_state_room_door_unlocked(pool_target);

                    (pool_target->ent_room_door)->status = ADM_STATUS_ROOM_DOOR_UNLOCKED;

                    adm_state_action_room_door_unlocked(
                        pool_target->ent_room_door);

                break;

                case ADM_STATUS_ROOM_DOOR_UNLOCKED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Room_Door",
                        (pool_target->ent_room_door)->identity,
                        "Event:Unlock_door",
                        "State:Unlocked");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_room_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */