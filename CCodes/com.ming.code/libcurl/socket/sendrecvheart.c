//
// Created by shanlovana on 19-1-17.
//

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

enum Type {
    HEART = 0, MSG = 1, EXIT = 2, OTHER = 3
};

/* Auxiliary function that waits on the socket. */
static int wait_on_socket(curl_socket_t sockfd, int for_recv, long timeout_ms) {
    struct timeval tv;
    fd_set infd, outfd, errfd;
    int res;

    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;

    FD_ZERO(&infd);
    FD_ZERO(&outfd);
    FD_ZERO(&errfd);

    FD_SET(sockfd, &errfd); /* always check for error */

    if (for_recv) {
        FD_SET(sockfd, &infd);
    } else {
        FD_SET(sockfd, &outfd);
    }

    /* select() returns the number of signalled sockets or -1 */
    res = select((int) sockfd + 1, &infd, &outfd, &errfd, &tv);
    return res;
}

int recieve_send(void) {
    CURL *curl;
    CURLcode res;
    /* Minimalistic http request */
    const char *request = "I`m groot!\r\n";

    size_t request_len = strlen(request);
    curl_socket_t sockfd;
    size_t nsent_total = 0;

    /* A general note of caution here: if you're using curl_easy_recv() or
       curl_easy_send() to implement HTTP or _any_ other protocol libcurl
       supports "natively", you're doing it wrong and you should stop.

       This example uses HTTP only to show how to use this API, it does not
       suggest that writing an application doing this is sensible.
    */

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "10.6.191.177");
        curl_easy_setopt(curl, CURLOPT_PORT, 12345);

        /* Do not do the transfer - only connect to host */
        curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);

        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPIDLE, 3L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPINTVL, 2L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            return 1;
        }

        /* Extract the socket from the curl handle - we'll need it for waiting. */
        res = curl_easy_getinfo(curl, CURLINFO_ACTIVESOCKET, &sockfd);

        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            return 1;
        }

        printf("Sending request.\n");
        //建立通道成功后，将循环发送心跳包，但是区分工作状态,空闲状态
        for (;;) {
            do {
                size_t nsent;
                nsent_total = 0;
                do {
                    nsent = 0;
                    res = curl_easy_send(curl, request + nsent_total,
                                         request_len - nsent_total, &nsent);
                    nsent_total += nsent;

                    if (res == CURLE_AGAIN && !wait_on_socket(sockfd, 0, 30 * 1000L)) {
                        printf("Error: timeout.\n");
                        return 1;
                    }
                } while (res == CURLE_AGAIN);

                if (res != CURLE_OK) {
                    printf("Error: %s\n", curl_easy_strerror(res));
                    return 1;
                }
                printf("Sent %" CURL_FORMAT_CURL_OFF_T " bytes.\n",
                       (curl_off_t) nsent);

            } while (nsent_total < request_len);

            printf("Reading response.\n");

            char buf[1024];
            size_t nread;
            do {
                nread = 0;
                res = curl_easy_recv(curl, buf, sizeof(buf), &nread);

                if (res == CURLE_AGAIN && !wait_on_socket(sockfd, 1, 30 * 1000L)) {
                    printf("Error: timeout.\n");
                    return 1;
                }
            } while (res == CURLE_AGAIN);

            if (res != CURLE_OK) {
                printf("Error: %s\n", curl_easy_strerror(res));
                break;
            }

            if (nread == 0) {
                /* end of the response */
                break;
            }
            printf("Received sentence is %s\n",
                   buf);
            printf("Received %" CURL_FORMAT_CURL_OFF_T " bytes.\n",
                   (curl_off_t) nread);

            sleep(3);
        }
        /* always cleanup */
        printf("Received curl_easy_cleanup is curl_easy_cleanup ");
        curl_easy_cleanup(curl);
    }
    return 0;
}
