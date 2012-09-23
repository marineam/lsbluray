#include <stdio.h>
#include <assert.h>
#include <libbluray/bluray.h>
#include <libbluray/log_control.h>
#include <libbluray/meta_data.h>

static void logit(const char *msg) {
    printf("%s", msg);
}


int main(int argc, char *argv[]) {
    char *dev;
    if (argc >= 2) {
        dev = argv[1];
    }
    else {
        dev = "/mnt/cdrom";
    }

    bd_set_debug_handler(logit);
    bd_set_debug_mask(0xFFFFF);

    BLURAY *br = bd_open(dev, NULL);
    assert(br);

    const BLURAY_DISC_INFO *info = bd_get_disc_info(br);
    assert(info);

    printf("bluray_detected %d\n", info->bluray_detected);
    printf("first_play_supported %d\n", info->first_play_supported);
    printf("top_menu_supported %d\n", info->top_menu_supported);
    printf("num_hdmv_titles %d\n", info->num_hdmv_titles);
    printf("num_bdj_titles %d\n", info->num_bdj_titles);
    printf("num_unsupported_titles %d\n", info->num_unsupported_titles);
    printf("aacs_detected %d\n", info->aacs_detected);
    printf("libaacs_detected %d\n", info->libaacs_detected);
    printf("aacs_handled %d\n", info->aacs_handled);
    printf("bdplus_detected %d\n", info->bdplus_detected);
    printf("libbdplus_detected %d\n", info->libbdplus_detected);
    printf("bdplus_handled %d\n", info->bdplus_handled);

    META_DL* meta = bd_get_meta(br);
    assert(meta);

    return 0;
}
