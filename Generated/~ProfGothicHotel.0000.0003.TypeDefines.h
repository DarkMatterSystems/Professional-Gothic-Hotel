
/* System Type Defines Header */

/* Base Type Defines */

typedef int    adm_base_integer_typ;
typedef int    adm_base_boolean_typ;
typedef float  adm_base_fixed_typ;
typedef double adm_base_float_typ;
typedef char   adm_base_string_typ;


/* System Type Defines */

typedef adm_base_integer_typ adm_int_number_typ;

typedef adm_base_string_typ  adm_str_text_typ;


/* Indent Type Define */

typedef struct {
    adm_base_integer_typ width;
    adm_base_integer_typ width_template;
    adm_base_integer_typ width_display;
    adm_base_string_typ  tab [ADM_INDENT_MAXIMUM_INDENT+1];
} adm_indent_typ;


/* Stream Type Define */

typedef struct {
    FILE                 * channel;
    adm_base_integer_typ   index;
    adm_base_boolean_typ   active;
    adm_base_boolean_typ   streaming;
    adm_base_boolean_typ   template_active;
    adm_base_boolean_typ   template_streaming;
    adm_base_string_typ    pathname [ADM_SYSTEM_PATHNAME_SIZE];
} adm_stream_typ;


/* Error Type Defines */

typedef adm_base_integer_typ adm_err_file_typ;
typedef adm_base_integer_typ adm_err_line_typ;
typedef adm_base_integer_typ adm_err_rank_typ;
typedef adm_base_integer_typ adm_err_number_typ;

typedef adm_base_string_typ adm_err_problem_typ;
typedef adm_base_string_typ adm_err_message_typ;
typedef adm_base_string_typ adm_err_script_typ;


#if ADM_PROBE

/* Probe Group Type Defines */

typedef enum {
    ADM_PROBE_GROUP_MAIN_PROGRAM,
    ADM_PROBE_GROUP_INITIALISATION,
    ADM_PROBE_GROUP_SCHEDULER,
    ADM_PROBE_GROUP_DISPATCHER,
    ADM_PROBE_GROUP_STATE_ACTION,
    ADM_PROBE_GROUP_DATA_ACCESS,
    ADM_PROBE_GROUP_EVENT_SENDER,
    ADM_PROBE_GROUP_ENUMERATION,
    ADM_PROBE_GROUP_LIBRARY,
    ADM_PROBE_GROUP_IDENTIFIER,
    ADM_PROBE_GROUP_ERROR,
    ADM_PROBE_GROUP_SIMULATOR
} adm_probe_group_typ;

typedef struct { 
    adm_base_boolean_typ all;
    adm_base_boolean_typ none;
    adm_base_boolean_typ main_program;
    adm_base_boolean_typ initialisation;
    adm_base_boolean_typ scheduler;
    adm_base_boolean_typ dispatcher;
    adm_base_boolean_typ state_action;
    adm_base_boolean_typ data_access;
    adm_base_boolean_typ event_sender;
    adm_base_boolean_typ enumeration;
    adm_base_boolean_typ library;
    adm_base_boolean_typ identifier;
    adm_base_boolean_typ error;
    adm_base_boolean_typ simulator;
    adm_base_integer_typ level;
} adm_probe_display_typ;

#endif

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */