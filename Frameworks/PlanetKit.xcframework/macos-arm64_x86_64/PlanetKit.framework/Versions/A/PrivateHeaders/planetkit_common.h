/**
 * @file planetkit_common.h
 * @brief write some brief information here.
 *
 * @date 2019-12-20
 *
 * Generated by author
 *
 */
#ifndef __PLANETKIT_COMMON_H__
#define __PLANETKIT_COMMON_H__

/*************************************************************************
* INCLUDE
*************************************************************************/
#include "planetkit_common_type.h"

#if defined(__cplusplus)
extern "C" {
#endif
/*************************************************************************
* DATA STRUCTURE
*************************************************************************/

#define PLANETKIT_MY_SCREEN_SHARE_MAX_FPS_DEFAULT           PLANETKIT_VIDEO_FPS_10
#define PLANETKIT_MY_SCREEN_SHARE_MAX_RESOLUTION_DEFAULT    PLANETKIT_VIDEO_RESOLUTION_MAX

typedef struct planetkit_cpu_info {
    float       clock_speed;            /** CPU clock speed (Giga hz) */
    uint32_t    core_num;               /** The number of core in the cpu */
} planetkit_cpu_info_t;
typedef struct planetkit_dev_spec {
    uint32_t        mem_sz;                 /** Memory size (Giga bytes) */
    uint32_t        cpu_cnt;                /** The count of cpu */

#define PLANETKIT_DEV_SPEC_MAX_CPU_INFO  4
    planetkit_cpu_info_t    cpu_info[PLANETKIT_DEV_SPEC_MAX_CPU_INFO];
} planetkit_dev_spec_t;

typedef struct planetkit_init_param {
    /* HAVE TO call "planetkit_init_param_init" first before use it */
    int _init;

    const char * NULLABLE base_path;
    const char * NULLABLE log_pathname;
    const char * NULLABLE config_filename;
    
    /* device info */
    const char * NULLABLE os_name;
    const char * NULLABLE os_ver;
    const char * NULLABLE dev_name;
    const char * NULLABLE manufacturer;

    const char * NULLABLE kit_ver;

    /* device access network info */
    const char * NULLABLE mcc;                /**< MCC of this device */
    const char * NULLABLE mnc;                /**< MNC of this device */

    const char * NULLABLE curr_country;               /**< MCC(Mobile Country Code) of currently registered operator */
    const char * NULLABLE curr_operator;              /**< MNC(Mobile Network Code) of currently registered operator */
    const char * NULLABLE sim_country;                /**< MCC of SIM provider */
    const char * NULLABLE sim_operator;               /**< MNC of SIM provider */
    const char * NULLABLE dev_radio_type;             /**< Device Radio Type */

    const char * NULLABLE app_ver;                    /**< App version
                                                       *   Maximum size of app_ver is 32 bytes including null termination
                                                       *   Any trailing part of the string that exceeds the maximum size is discarded */

    planetkit_network_type_e   network_type;    /**< Radio technology (network type) currently in use on this device for data transmission */
    kit_bool_t  roaming;                        /**< Indicator that this device is in roaming network */
    int32_t     log_options;

    const char  * NULLABLE db_path;
    const char  * NULLABLE db_enckey;


    planetkit_audio_codec_complexity_level_e    audio_codec_complexity_level;        /**< the higher complex will be more enhanced quality */
    planetkit_audio_bw_type_e                   audio_bw_type;
    kit_bool_t                                  support_aec3_mlaec;

    const char* NULLABLE ca_path;                       /** [Android only] Curl need CA certificate in order to have https communication **/

    kit_bool_t                                  allow_multi_conf;   /**< If false, prevent join conference from multiple instance */
} planetkit_init_param_t;

/**
 * Log size limit
 * - SMALL:   16MB
 * - MEDIUM:  64MB
 * - LARGE:   256MB
 * - UNLIMITED: No limit
 */
typedef enum planetkit_log_size_limit_e {
    PLANETKIT_LOG_SIZE_LIMIT_SMALL = 0,
    PLANETKIT_LOG_SIZE_LIMIT_MEDIUM,
    PLANETKIT_LOG_SIZE_LIMIT_LARGE,
    PLANETKIT_LOG_SIZE_LIMIT_UNLIMITED,
} planetkit_log_size_limit_e;

typedef void (*planetkit_task_handler_t)(void *NULLABLE user_ptr);

/*************************************************************************
* API DEFINITION
*************************************************************************/
void        planetkit_async_task(planetkit_task_handler_t NONNULL task_handler, void *NULLABLE user_ptr);

kit_bool_t  planetkit_init(const planetkit_init_param_t * NONNULL param);
void        planetkit_init_param_init(planetkit_init_param_t * NONNULL param);

void        planetkit_release(void);
kit_bool_t  planetkit_is_init(void);


int32_t     planetkit_make_log_options(int32_t log_level,
                                       kit_bool_t enable_log,
                                       planetkit_log_size_limit_e size_limit);
const char* NONNULL planetkit_get_kitver(void);
const char* NONNULL planetkit_get_ua_str(void);
const char* NONNULL planetkit_get_base_path(void);
kit_bool_t  planetkit_is_valid_id(planetkit_str_t NONNULL id);

#define     planetkit_is_valid_room_id(_room_id_) planetkit_is_valid_id(_room_id_)
#define     planetkit_is_valid_user_id(_user_id_) planetkit_is_valid_id(_user_id_)
kit_bool_t  planetkit_is_valid_service_id(planetkit_str_t NONNULL service_id);
kit_bool_t  planetkit_is_valid_api_key(planetkit_str_t NONNULL api_key);

kit_bool_t planetkit_disconnect_reason_is_normal(planetkit_disconnect_reason_e reason);

/**
 * APIs to update settings
 */
void        planetkit_update_server_url(const char * NONNULL server_url);
void        planetkit_update_network_type(planetkit_network_type_e network_type);
void        planetkit_update_audio_codec_complexity_level(planetkit_audio_codec_complexity_level_e rx_level, planetkit_audio_codec_complexity_level_e tx_level);
void        planetkit_update_audio_bw_type(planetkit_audio_bw_type_e rx_type, planetkit_audio_bw_type_e tx_type);

kit_bool_t  planetkit_get_local_ip(char * NONNULL buf_ptr, int32_t buf_sz);
kit_bool_t  planetkit_get_network_interface(const char * NONNULL address, char * NONNULL buf_ptr, int32_t buf_sz);

int8_t      planetkit_calc_float_pcm_lv_db(const float * NONNULL samples, uint32_t samples_cnt);
int8_t      planetkit_calc_short_pcm_lv_db(const int16_t * NONNULL samples, uint32_t samples_cnt);
 
/**
 * Normalize audio level in dB for better visual representation
 * @param lv_db     Audio level in dB
 * @return normalized value ranges between 0 to 100
 */
int8_t      planetkit_normalize_audio_lv_db(int8_t lv_db);

/**
 * Revert audio level in percentage to dB
 * @param lv        Audio level in pertentage (rangees from 0 to 100, and extra 100 ~ 110 for level boost)
 * @return denormalized value in dB
 */
float       planetkit_denormalize_audio_lv_to_db(int8_t lv);

void        planetkit_log(int32_t log_level, planetkit_str_t NONNULL file,  planetkit_str_t NONNULL func, int32_t line, planetkit_str_t NONNULL message);


/**
 * For planet_comm_param_t
 */
void        planetkit_comm_param_init_by_default(planetkit_comm_param_t * NONNULL param);

/**
 * Get video H/W codec capability
 * @return KIT_TRUE if H/W codec is supported, KIT_FALSE otherwise
 */
kit_bool_t  planetkit_get_video_hw_codec_support(void);

/**
 *
 * Get device maximum video attribute (resolution and fps)
 *
 * @param spec_type     video type
 * @param tx_res[out]   Device maximum resolution to send
 * @param tx_fps[out]   Device maximum fps to send
 * @param rx_res[out]   Device maximum resolution to receive
 * @param rx_fps[out]   Device maximum fps to receive
 */
/**
 * Get device maximum video attribute (resolution and fps)
 *
 * @param spec_type         Video type to get attribute
 * @param prefer_hw_codec   Flag to enable hw codec if possible
 * @param tx_res[out]       Device maximum resolution to send
 * @param tx_fps[out]       Device maximum fps to send
 * @param rx_res[out]       Device maximum resolution to receive
 * @param rx_fps[out]       Device maximum fps to receive
 */
void        planetkit_get_device_maximum_video_attribute(planetkit_video_spec_type_e spec_type,
                                                         kit_bool_t prefer_hw_codec,
                                                         planetkit_video_spec_resolution_e * NULLABLE tx_res,
                                                         int32_t * NULLABLE tx_fps,
                                                         planetkit_video_spec_resolution_e * NULLABLE rx_res,
                                                         int32_t * NULLABLE rx_fps);
/**
 * Get default preferred maximum video attribute (resolution and fps)
 *
 * @param spec_type         Video type to get attribute
 * @param prefer_hw_codec   Flag to enable hw codec if possible
 * @param tx_res[out]       Preferred maximum resolution to send
 * @param tx_fps[out]       Preferred maximum fps to send
 * @param rx_res[out]       Preferred maximum resolution to receive
 * @param rx_fps[out]       Preferred maximum fps to receive
 */
void        planetkit_get_default_preferred_video_attribute(planetkit_video_spec_type_e spec_type,
                                                            kit_bool_t prefer_hw_codec,
                                                            planetkit_video_spec_resolution_e * NULLABLE tx_res,
                                                            int32_t * NULLABLE tx_fps,
                                                            planetkit_video_spec_resolution_e * NULLABLE rx_res,
                                                            int32_t * NULLABLE rx_fps);

planetkit_video_resolution_e        planetkit_video_resolution_from_spec_resolution(planetkit_video_spec_resolution_e spec_res);
planetkit_video_spec_resolution_e   planetkit_video_resolution_to_spec_resolution(planetkit_video_resolution_e res);

/**
 * Helper APIs for planet_statistics_t
 */
planetkit_statistics_peer_video_t * NULLABLE planetkit_statistics_get_peer_video_by_id(planetkit_statistics_t *NONNULL statistics,
                                                                                       planetkit_str_t NONNULL peer_id,
                                                                                       planetkit_str_t NONNULL peer_service_id,
                                                                                       planetkit_str_t NULLABLE subgroup_name);
planetkit_statistics_peer_screen_share_t * NULLABLE planetkit_statistics_get_peer_screen_share_by_id(planetkit_statistics_t *NONNULL statistics,
                                                                                                     planetkit_str_t NONNULL peer_id,
                                                                                                     planetkit_str_t NONNULL peer_service_id,
                                                                                                     planetkit_str_t NULLABLE subgroup_name);
planetkit_statistics_peer_video_t * NULLABLE planetkit_statistics_get_peer_video(planetkit_statistics_t * NONNULL statistics, uint32_t index);
planetkit_statistics_peer_screen_share_t * NULLABLE planetkit_statistics_get_peer_screen_share(planetkit_statistics_t * NONNULL statistics, uint32_t index);

typedef enum planetkit_initial_my_video_state_e {
    PLANETKIT_INITIAL_MY_VIDEO_STATE_RESUME = 0,
    PLANETKIT_INITIAL_MY_VIDEO_STATE_PAUSE = 1,
} planetkit_initial_my_video_state_e;

/**
 * My media source state
 */
 typedef enum planetkit_my_media_source_kind_e
{
    PLANETKIT_MY_MEDIA_SOURCE_AUDIO = 0,
    PLANETKIT_MY_MEDIA_SOURCE_VIDEO = 1,
    PLANETKIT_MY_MEDIA_SOURCE_COUNT = 2,
} planetkit_my_media_source_kind_e;
 
typedef enum planetkit_my_media_source_state_e
{
    PLANETKIT_MY_MEDIA_SOURCE_STATE_NOT_REQUIRED = 0,
    PLANETKIT_MY_MEDIA_SOURCE_STATE_REQUIRED = 1,
} planetkit_my_media_source_state_e;
 
typedef struct planetkit_my_media_source_event_t
{
    planetkit_my_media_source_kind_e    kind;
    planetkit_my_media_source_state_e   state;
    planetkit_str_t         NULLABLE    reason;
} planetkit_my_media_source_event_t;
 
typedef void (*planetkit_my_media_source_evt_cb_t)(void *NULLABLE user_ptr, planetkit_my_media_source_event_t *NONNULL evt);
typedef void (*planetkit_get_my_media_source_result_cb_t)(void *NULLABLE user_ptr, planetkit_my_media_source_kind_e kind, planetkit_my_media_source_state_e state);

/**
 * APIs to stringify debug monitoring info
 */
int32_t     planetkit_dbg_mon_info_comm_stringify(char * NONNULL string_buffer, size_t buffer_size, const plantkit_dbg_mon_info_comm_t * NONNULL info);
int32_t     planetkit_dbg_mon_info_audio_tx_stringify(char * NONNULL string_buffer, size_t buffer_size, const planetkit_dbg_mon_info_audio_tx_t * NONNULL info);
int32_t     planetkit_dbg_mon_info_audio_rx_stringify(char * NONNULL string_buffer, size_t buffer_size, const planetkit_dbg_mon_info_audio_rx_t * NONNULL info);
int32_t     planetkit_dbg_mon_info_video_tx_stringify(char * NONNULL string_buffer, size_t buffer_size, const planetkit_dbg_mon_info_video_tx_t * NONNULL info);
int32_t     planetkit_dbg_mon_info_video_rx_stringify(char * NONNULL string_buffer, size_t buffer_size, const planetkit_dbg_mon_info_video_rx_t * NONNULL info);
int32_t     planetkit_dbg_mon_info_stringify(char * NONNULL string_buffer, size_t buffer_size, const planetkit_dbg_mon_info_t * NONNULL info);
const planetkit_dbg_mon_info_video_rx_t * NULLABLE planetkit_dbg_mon_info_get_video_rx(const planetkit_dbg_mon_info_t * NONNULL info, uint32_t index);
#if defined(__cplusplus)
}
#endif

#endif