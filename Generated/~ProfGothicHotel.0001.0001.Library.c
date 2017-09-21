
#include "~ProfGothicHotel.0000.0000.Header.h"


/* System Library */

/* Allocate Memory */

void * adm_allocate_memory(
    adm_base_integer_typ amount)
{
    void * memory;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_allocate_memory");
    #endif

    memory = malloc(amount);

    if (memory == NULL) {

        adm_error_report(
            ADM_ERROR_OUT_OF_MEMORY,
            0, 0, 0, NULL, null, NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_allocate_memory");
    #endif

    return (memory);
}


/* Dellocate Memory */

void adm_deallocate_memory(
    const void * memory)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_deallocate_memory");
    #endif

    free((void*)memory);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_deallocate_memory");
    #endif
}


/* Open Stream File */

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    errno_t file_error;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_open_stream_file");
    #endif

    if (adm_stream.streaming) {

        adm_close_stream_file(
            error_file,
            error_line,
            error_rank);
    }

    file_error = fopen_s(&adm_stream.channel, adm_stream.pathname, "w");

    if (file_error) {

        adm_error_report(
            ADM_ERROR_CREATE_STREAM_FILE_FAILED,
            error_file, error_line, error_rank,
            adm_stream.pathname,
            null, NULL, NULL);

    } else {

        adm_stream.active    = TRUE;
        adm_stream.streaming = TRUE;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_open_stream_file");
    #endif
}


/* Close Stream File */

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_close_stream_file");
    #endif

    if (adm_stream.streaming) {

        if (fclose(adm_stream.channel) == EOF) {

            adm_error_report(
                ADM_ERROR_CLOSE_STREAM_FILE_FAILED,
                error_file, error_line, error_rank,
                adm_stream.pathname,
                null, NULL, NULL);

        } else {

            adm_stream.streaming = FALSE;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_close_stream_file");
    #endif
}


/* Write Integer */

void adm_write_int(
    adm_base_integer_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_int");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%d", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%d", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_int");
    #endif
}


/* Write Boolean */

void adm_write_bln(
    adm_base_boolean_typ value)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_bln");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%s", adm_indent.tab, adm_boolean[value]) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%s", adm_indent.tab, adm_boolean[value]);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_bln");
    #endif
}


/* Write Fixed */

void adm_write_fxd(
    adm_base_fixed_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_fxd");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%f", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%f", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_fxd");
    #endif
}


/* Write Float */

void adm_write_flt(
    adm_base_float_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_flt");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%E", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%E", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_flt");
    #endif
}


/* Write String */

void adm_write_str(
    const adm_base_string_typ * const string)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_str");
    #endif

    if (adm_stream.active) {

        if (!NULL_STR(string)) {

            if (adm_stream.streaming) {

                if (fprintf(adm_stream.channel, "%s%s", adm_indent.tab, string) < 0) {

                    adm_error_report(
                        ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                        0, 0, 0,
                        adm_stream.pathname,
                        null, NULL, NULL);
                }

            } else {

                printf("%s%s", adm_indent.tab, string);
            }

            INIT_STR(adm_indent.tab);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_str");
    #endif
}


/* Write Newline */

void adm_write_newline(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_newline");
    #endif

    if (adm_stream.active) {

        INIT_STR(adm_indent.tab);

        adm_write_str(NEWLINE);

        memset(adm_indent.tab, ' ', adm_indent.width);

        adm_indent.tab[adm_indent.width] = '\0';
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_newline");
    #endif
}


/* Set Template Tab In */

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_in");
    #endif

    if (adm_stream.active) {

        adm_indent.width += ADM_INDENT_TAB_TEMPLATE_INDENT_SIZE;

        if (adm_indent.width > ADM_INDENT_TEMPLATE_MAXIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_TEMPLATE_MAXIMUM_TAB_INDENT_EXCEEDED,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_in");
    #endif
}


/* Set Template Tab Out */

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_out");
    #endif

    if (adm_stream.active) {

        adm_indent.width -= ADM_INDENT_TAB_TEMPLATE_INDENT_SIZE;

        if (adm_indent.width < ADM_INDENT_TEMPLATE_MINIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_TEMPLATE_MINIMUM_TAB_INDENT_OFFPAGE,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_out");
    #endif
}


/* Set Display Tab In */

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_in");
    #endif

    if (adm_stream.active) {

        adm_indent.width += ADM_INDENT_TAB_DISPLAY_INDENT_SIZE;

        if (adm_indent.width > ADM_INDENT_DISPLAY_MAXIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_DISPLAY_MAXIMUM_TAB_INDENT_EXCEEDED,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_in");
    #endif
}


/* Set Display Tab Out */

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_out");
    #endif

    if (adm_stream.active) {

        adm_indent.width -= ADM_INDENT_TAB_DISPLAY_INDENT_SIZE;

        if (adm_indent.width < ADM_INDENT_DISPLAY_MINIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_DISPLAY_MINIMUM_TAB_INDENT_OFFPAGE,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_out");
    #endif
}


/* String - Convert Upper Case */

void adm_convert_string_upper_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_upper_case");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        target_string[index] = toupper(source_string[index]);

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_upper_case");
    #endif
}


/* String - Convert Lower Case */

void adm_convert_string_lower_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_lower_case");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        target_string[index] = tolower(source_string[index]);

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_lower_case");
    #endif
}


/* String - Convert Sentence Case */

void adm_convert_string_sentence_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_sentence_case");
    #endif

    adm_convert_string_lower_case(
        source_string,
        target_string);

    target_string[0] = toupper(target_string[0]);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_sentence_case");
    #endif
}


/* Convert Capital Case */

void adm_convert_string_capital_case(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ capitalise;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_capital_case");
    #endif

    capitalise = TRUE;

    index = 0;

    while (source_string[index] != '\0') {

        if (
            source_string[index] == ' ' ||
            source_string[index] == '_') {

            capitalise = TRUE;

            target_string[index] = source_string[index];

        } else {

            if (capitalise) {

                capitalise = FALSE;

                target_string[index] = toupper(source_string[index]);

            } else {

                target_string[index] = tolower(source_string[index]);
            }
        }

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_capital_case");
    #endif
}


/* String - Convert Remove Spaces */

void adm_convert_string_remove_spaces(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string)
{
    adm_base_integer_typ source_index;
    adm_base_integer_typ target_index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_remove_spaces");
    #endif

    source_index = 0;
    target_index = 0;

    while (source_string[source_index] != '\0') {

        if (source_string[source_index] != ' ') {

            target_string[target_index] = source_string[source_index];

            ++target_index;
        }

        ++source_index;
    }

    target_string[target_index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_remove_spaces");
    #endif
}


/* String - Convert Underlines */

void adm_convert_string_convert_underlines(
    const adm_base_string_typ * const source_string,
    adm_base_string_typ * const target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_convert_underlines");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        if (source_string[index] == '_') {

            target_string[index] = ' ';

        } else {

            target_string[index] = source_string[index];
        }

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_convert_underlines");
    #endif
}


/* Integrity Check */

void adm_integrity_check(
    void)
{
    adm_ent_room_device_typ * ent_room_device;
    adm_ent_room_door_typ * ent_room_door;
    adm_ent_secret_panel_typ * ent_secret_panel;
    adm_ent_unlocking_device_typ * ent_unlocking_device;
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    adm_ent_unlock_step_typ * ent_unlock_step;
    adm_ent_room_typ * ent_room;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_integrity_check");
    #endif

    ent_room_device = adm_entity_system.ent_room_device.live_list_head;

    while (ent_room_device != NULL) {

        if (ent_room_device->rel_contained_in_room_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                2, 10, 13,
                "Room_Device",
                ent_room_device->identity,
                "Contained_in",
                "Room");
        }

        if (
            ent_room_device->rel_contained_in_room_head != 
            ent_room_device->rel_contained_in_room_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                2, 10, 13,
                "Room_Device",
                ent_room_device->identity,
                "Contained_in",
                "Room");
        }

        if (
            ent_room_device->rel_generalisation_room_door_head != 
            ent_room_device->rel_generalisation_room_door_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                2, 11, 13,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Room_Door");
        }

        if (
            ent_room_device->rel_generalisation_secret_panel_head != 
            ent_room_device->rel_generalisation_secret_panel_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                2, 12, 13,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Secret_Panel");
        }

        if (
            ent_room_device->rel_generalisation_unlocking_device_head != 
            ent_room_device->rel_generalisation_unlocking_device_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                2, 13, 13,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Unlocking_Device");
        }

        ent_room_device = ent_room_device->next;
    }

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (ent_room_door != NULL) {

        if (ent_room_door->rel_specialisation_room_device_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                3, 8, 13,
                "Room_Door",
                ent_room_door->identity,
                "Specialisation",
                "Room_Device");
        }

        if (
            ent_room_door->rel_specialisation_room_device_head != 
            ent_room_door->rel_specialisation_room_device_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                3, 8, 13,
                "Room_Door",
                ent_room_door->identity,
                "Specialisation",
                "Room_Device");
        }

        ent_room_door = ent_room_door->next;
    }

    ent_secret_panel = adm_entity_system.ent_secret_panel.live_list_head;

    while (ent_secret_panel != NULL) {

        if (ent_secret_panel->rel_opened_by_unlocking_sequence_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                4, 8, 13,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Opened_by",
                "Unlocking_Sequence");
        }

        if (ent_secret_panel->rel_specialisation_room_device_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                4, 9, 13,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Specialisation",
                "Room_Device");
        }

        if (
            ent_secret_panel->rel_specialisation_room_device_head != 
            ent_secret_panel->rel_specialisation_room_device_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                4, 9, 13,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Specialisation",
                "Room_Device");
        }

        ent_secret_panel = ent_secret_panel->next;
    }

    ent_unlocking_device = adm_entity_system.ent_unlocking_device.live_list_head;

    while (ent_unlocking_device != NULL) {

        if (ent_unlocking_device->rel_sets_unlock_step_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                5, 8, 13,
                "Unlocking_Device",
                ent_unlocking_device->identity,
                "Sets",
                "Unlock_Step");
        }

        ent_unlocking_device = ent_unlocking_device->next;
    }

    ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.live_list_head;

    while (ent_unlocking_sequence != NULL) {

        if (ent_unlocking_sequence->rel_opens_secret_panel_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                6, 8, 13,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Opens",
                "Secret_Panel");
        }

        if (
            ent_unlocking_sequence->rel_opens_secret_panel_head != 
            ent_unlocking_sequence->rel_opens_secret_panel_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                6, 8, 13,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Opens",
                "Secret_Panel");
        }

        if (ent_unlocking_sequence->rel_starts_at_unlock_step_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                6, 9, 13,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Starts_at",
                "Unlock_Step");
        }

        if (
            ent_unlocking_sequence->rel_starts_at_unlock_step_head != 
            ent_unlocking_sequence->rel_starts_at_unlock_step_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                6, 9, 13,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Starts_at",
                "Unlock_Step");
        }

        ent_unlocking_sequence = ent_unlocking_sequence->next;
    }

    ent_unlock_step = adm_entity_system.ent_unlock_step.live_list_head;

    while (ent_unlock_step != NULL) {

        if (
            ent_unlock_step->rel_followed_by_unlock_step_head != 
            ent_unlock_step->rel_followed_by_unlock_step_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                9, 8, 13,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Followed_by",
                "Unlock_Step");
        }

        if (ent_unlock_step->rel_part_of_unlocking_sequence_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                9, 9, 13,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Part_of",
                "Unlocking_Sequence");
        }

        if (
            ent_unlock_step->rel_part_of_unlocking_sequence_head != 
            ent_unlock_step->rel_part_of_unlocking_sequence_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                9, 9, 13,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Part_of",
                "Unlocking_Sequence");
        }

        ent_unlock_step = ent_unlock_step->next;
    }

    ent_room = adm_entity_system.ent_room.live_list_head;

    while (ent_room != NULL) {

        if (ent_room->rel_contains_room_device_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 49, 29,
                "Room",
                ent_room->identity,
                "Contains",
                "Room_Device");
        }

        ent_room = ent_room->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_integrity_check");
    #endif
}


#if ADM_PROBE

/* Probe Enter */

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name)
{
    adm_base_string_typ probe_message [ADM_PROBE_MESSAGE_SIZE];

    if (
        !adm_probe_display.none &&
        (adm_probe_display.all                                                        ||
        (adm_probe_display.main_program   && group == ADM_PROBE_GROUP_MAIN_PROGRAM)   ||
        (adm_probe_display.initialisation && group == ADM_PROBE_GROUP_INITIALISATION) ||
        (adm_probe_display.scheduler      && group == ADM_PROBE_GROUP_SCHEDULER)      ||
        (adm_probe_display.dispatcher     && group == ADM_PROBE_GROUP_DISPATCHER)     ||
        (adm_probe_display.state_action   && group == ADM_PROBE_GROUP_STATE_ACTION)   ||
        (adm_probe_display.data_access    && group == ADM_PROBE_GROUP_DATA_ACCESS)    ||
        (adm_probe_display.event_sender   && group == ADM_PROBE_GROUP_EVENT_SENDER)   ||
        (adm_probe_display.enumeration    && group == ADM_PROBE_GROUP_ENUMERATION)    ||
        (adm_probe_display.library        && group == ADM_PROBE_GROUP_LIBRARY)        ||
        (adm_probe_display.identifier     && group == ADM_PROBE_GROUP_IDENTIFIER)     ||
        (adm_probe_display.error          && group == ADM_PROBE_GROUP_ERROR)          ||
        (adm_probe_display.simulator      && group == ADM_PROBE_GROUP_SIMULATOR))) {

        INIT_STR(probe_message);

        adm_add_spaces(probe_message, adm_probe_display.level);

        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, "ENTER: ");
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, procedure_name);
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, NEWLINE);

        printf(probe_message);

        fprintf(adm_file_channel, probe_message);

        adm_probe_display.level += ADM_PROBE_INDENT;
    }
}


/* Probe Leave */

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name)
{
    adm_base_string_typ probe_message [ADM_PROBE_MESSAGE_SIZE];

    if (
        !adm_probe_display.none &&
        (adm_probe_display.all                                                        ||
        (adm_probe_display.main_program   && group == ADM_PROBE_GROUP_MAIN_PROGRAM)   ||
        (adm_probe_display.initialisation && group == ADM_PROBE_GROUP_INITIALISATION) ||
        (adm_probe_display.scheduler      && group == ADM_PROBE_GROUP_SCHEDULER)      ||
        (adm_probe_display.dispatcher     && group == ADM_PROBE_GROUP_DISPATCHER)     ||
        (adm_probe_display.state_action   && group == ADM_PROBE_GROUP_STATE_ACTION)   ||
        (adm_probe_display.data_access    && group == ADM_PROBE_GROUP_DATA_ACCESS)    ||
        (adm_probe_display.event_sender   && group == ADM_PROBE_GROUP_EVENT_SENDER)   ||
        (adm_probe_display.enumeration    && group == ADM_PROBE_GROUP_ENUMERATION)    ||
        (adm_probe_display.library        && group == ADM_PROBE_GROUP_LIBRARY)        ||
        (adm_probe_display.identifier     && group == ADM_PROBE_GROUP_IDENTIFIER)     ||
        (adm_probe_display.error          && group == ADM_PROBE_GROUP_ERROR)          ||
        (adm_probe_display.simulator      && group == ADM_PROBE_GROUP_SIMULATOR))) {

        adm_probe_display.level -= ADM_PROBE_INDENT;

        INIT_STR(probe_message);

        adm_add_spaces(probe_message, adm_probe_display.level);

        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, "LEAVE: ");
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, procedure_name);
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, NEWLINE);

        printf(probe_message);

        fprintf(adm_file_channel, probe_message);
    }
}


/* Add Spaces */

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number)
{
    adm_base_integer_typ index;

    for (index=0; index<space_number; ++index) {

        strcat_s(space_string, ADM_PROBE_MESSAGE_SIZE, " ");
    }
}

#endif

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */