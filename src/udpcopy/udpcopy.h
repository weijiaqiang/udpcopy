#ifndef __UDPCOPY_H__
#define __UDPCOPY_H__ 


typedef struct {
    /* Online ip from the client perspective */
    uint32_t online_ip;
    uint32_t target_ip;
    uint16_t online_port;
    uint16_t target_port;
} ip_port_pair_mapping_t;


typedef struct {
    int                      num;
    ip_port_pair_mapping_t **mappings;
} ip_port_pair_mappings_t;


typedef struct xcopy_clt_settings {
    unsigned int  replica_num:10;       /* Replicated number of each request */
    unsigned int  factor:8;             /* Port shift factor */
    unsigned int  mtu:16;               /* MTU sent to backend */
    unsigned int  do_daemonize:1;       /* Daemon flag */
    unsigned int  max_rss:21;           /* Max memory size allowed for udpcopy
                                           client(max size 2G) */
    char         *raw_transfer;         /* Online_ip online_port target_ip
                                           target_port string */

    char         *pid_file;             /* Pid file */
    char         *log_path;             /* Error log path */
#if (UDPCOPY_OFFLINE)
    char         *pcap_file;            /* Pcap file */
#endif
    uint16_t      rand_port_shifted;    /* Random port shifted */
    uint32_t      lo_tf_ip;             /* Ip address from localhost to
                                           (localhost transfered ip) */
    ip_port_pair_mappings_t transfer;   /* Transfered online_ip online_port
                                           target_ip target_port */
    int           multiplex_io;
} xcopy_clt_settings;


extern xcopy_clt_settings clt_settings;

#include <util.h>
#include <manager.h>
#include <send.h>
#include <session.h>

#endif /* __UDPCOPY_H__ */
