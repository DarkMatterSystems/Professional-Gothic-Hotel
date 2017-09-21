
#include "~ProfGothicHotel.0000.0000.Header.h"


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ          error,
    adm_err_file_typ            file,
    adm_err_line_typ            line,
    adm_err_rank_typ            rank,
    adm_err_problem_typ       * source,
    adm_base_integer_typ        identity,
    adm_err_problem_typ       * relation,
    const adm_err_problem_typ * target)
{
    adm_base_string_typ report_message [ADM_ERROR_REPORT_MESSAGE_SIZE];

    const adm_err_script_typ * error_script[] = {
        SNULL,
        /**/
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\$Main\\System.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\$Main\\0101_Entity_Room_Device.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\$Main\\0102_Entity_Room_Door.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\$Main\\0103_Entity_Secret_Panel.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\$Main\\0104_Entity_Unlocking_Device.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\$Main\\0105_Entity_Unlocking_Sequence.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\Unlock_Step\\02Process\\0106_Process_Reset_Unlock_Steps.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\Unlock_Step\\02Process\\0106_Process_Select_Unlock_Steps.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\Gothic_Security\\$Main\\0106_Entity_Unlock_Step.matrix",
        "M:\\Matrix\\Models\\Prof_Gothic_Hotel\\02Matrix\\0200_Silo_Real_World_Objects.matrix",
        /**/
        SNULL
    };

    const adm_err_message_typ * error_message[] = {
        "Error logger invoked with no error",             /* ADM_ERROR_NO_ERROR */
        "Invalid integer argument on command line",       /* ADM_ERROR_INVALID_INTEGER_ARGUMENT */
        "Too many arguments on command line",             /* ADM_ERROR_ERROR_TOO_MANY_ARGUMENTS */
        "Out of memory",                                  /* ADM_ERROR_OUT_OF_MEMORY */
        "Transition Cannot Happen",                       /* ADM_ERROR_TRANSITION_CANNOT_HAPPEN */
        "Object has existing relation",                   /* ADM_ERROR_OBJECT_HAS_EXISTING_RELATION */
        "Objects are already related",                    /* ADM_ERROR_OBJECTS_ALREADY_RELATED */
        "No relations exist",                             /* ADM_ERROR_NO_RELATIONS_EXIST */
        "Incremented enumeration out of bounds",          /* ADM_ERROR_ENUMERATION_INCREMENTED_OUT_OF_BOUNDS */
        "Decremented enumeration out of bounds",          /* ADM_ERROR_ENUMERATION_DECREMENTED_OUT_OF_BOUNDS */
        "Attempt to delete own object",                   /* ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT */
        "Attempt to use deleted object",                  /* ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT */
        "Relationship has already been unrelated",        /* ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED */
        "Conditionality integrity violation",             /* ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION */
        "Multiplicity integrity violation",               /* ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION */
        "Only one self directed event allowed at a time", /* ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED */
        "Source value outside range for target type",     /* ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE */
        "System result file create failed",               /* ADM_ERROR_CREATE_RESULT_FILE_FAILED */
        "System result file close failed",                /* ADM_ERROR_CLOSE_RESULT_FILE_FAILED */
        "System result file write failed",                /* ADM_ERROR_FILE_RESULT_WRITE_FAILED */
        "System stream file create failed",               /* ADM_ERROR_CREATE_STREAM_FILE_FAILED */
        "System stream file close failed",                /* ADM_ERROR_CLOSE_STREAM_FILE_FAILED */
        "System stream file write failed",                /* ADM_ERROR_FILE_STREAM_WRITE_FAILED */
        "Foreign key identifier relation invalid",        /* ADM_ERROR_FOREIGN_KEY_IDENTIFIER_RELATION_INVALID */
        "Object with same identifier already exists",     /* ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE */
        "Maximum template tab indent exceeded",           /* ADM_ERROR_TEMPLATE_MAXIMUM_TAB_INDENT_EXCEEDED */
        "Template tab indent below minimum offpage",      /* ADM_ERROR_TEMPLATE_MINIMUM_TAB_INDENT_OFFPAGE */
        "Maximum display tab indent exceeded",            /* ADM_ERROR_DISPLAY_MAXIMUM_TAB_INDENT_EXCEEDED */
        "Display tab indent below minimum offpage",       /* ADM_ERROR_DISPLAY_MINIMUM_TAB_INDENT_OFFPAGE */
        /**/
        SNULL                                             /* ADM_ERROR_MESSAGE_NULL */
    };

    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_ERROR, "adm_error_report");
    #endif

    index = 0;

    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, "\n");
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, "\n");
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, "*** ERROR: ==> ");
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, "%s", error_message[error]);

    if (source   != NULL) index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, " - %s", source);
    if (identity != 0)    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index,  "[%d]", identity);
    if (relation != NULL) index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, " : %s", relation);
    if (target   != NULL) index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, " : %s", target);

    if (
        source   == NULL &&
        identity == 0    &&
        relation == NULL &&
        target   == NULL) {

        index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, ".");
    }

    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, NEWLINE);
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, "***");
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, NEWLINE);
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, "***");
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, " %d", line);
    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, ":%d", rank);

    if (file != null) {

        index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, ":");
        index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, QUOTE);
        index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, error_script[file]);
        index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, QUOTE);
    }

    index += sprintf_s(report_message+index, ADM_ERROR_REPORT_MESSAGE_SIZE-index, NEWLINE);

    printf(report_message);

    if (adm_stream.streaming) fclose(adm_stream.channel);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_ERROR, "adm_error_report");
    #endif

    exit (error);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */