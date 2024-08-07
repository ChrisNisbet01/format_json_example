#include <libubox/blobmsg_json.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static char const *
format_some_json(void)
{
    struct blob_buf resp_buf = {0};

    blob_buf_init(&resp_buf, 0);

    blobmsg_add_string(&resp_buf, "a_string", "some string value");

    void * const obj_cookie = blobmsg_open_table(&resp_buf, "some_table");

    blobmsg_add_u32(&resp_buf, "some_int", 42);
    blobmsg_add_u8(&resp_buf, "some_bool", true);

    void * const cookie2 = blobmsg_open_table(&resp_buf, "inner_table");

    blobmsg_add_string(&resp_buf, "key", "another string");

    blobmsg_close_table(&resp_buf, cookie2);

    blobmsg_close_table(&resp_buf, obj_cookie);

    void * const arr_cookie = blobmsg_open_array(&resp_buf, "some_array");

    blobmsg_add_double(&resp_buf, NULL, 69.0);
    blobmsg_add_double(&resp_buf, NULL, 42.0);

    blobmsg_close_array(&resp_buf, arr_cookie);

    char const * const ret = blobmsg_format_json(resp_buf.head, true);

    blob_buf_free(&resp_buf);

    return ret;
}

int main(void)
{
    char const * const some_json_str = format_some_json();

    printf("some json: %s\n", some_json_str);

    free((void *)some_json_str);

    return EXIT_SUCCESS;
}
