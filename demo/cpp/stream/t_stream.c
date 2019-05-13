#include <stdio.h>
#include "l_sdk.h"
#include "proto/l_nspp.h"
#include "proto/l_net.h"
#include "proto/l_media.h"
#include "proto/l_md_buf.h"


#ifdef __L_WIN__
#include <windows.h>
int wsa_startup()
{
    //windows��ʹ��socket, ��Ҫ��WS2_32.DLL����г�ʼ��
    WSADATA wsa;
    if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
    {
        return 1;
    }

    return 0;
}
#else
int wsa_startup() { return 0; }
#endif


// https://github.com/lishaoliang/l_sdk_doc/blob/master/protocol/auth.md
#define T_LOGIN_STR     "{\"ip\":\"%s\",\"port\":%d,\"cmd\":\"login\",\"login\":{\"username\":\"%s\",\"passwd\":\"%s\"}}"

// https://github.com/lishaoliang/l_sdk_doc/blob/master/protocol/stream.md
#define T_REQ_STREAM_STR   "{\"cmd\":\"open_stream\",\"open_stream\":{\"chnn\":%d,\"idx\":%d}}"


static int cb_sdk_media(void* p_obj, int protocol, int id, int chnn, int idx, int md_id, l_md_buf_t* p_data)
{
    // p_obj �ǵ��� l_sdk_md_add_listener�����ĵ���������ָ��, ����û���õ�
    // protocol Ϊ proto/l_nspp.h �ļ��ж�������Э������
    // id Ϊ��¼ID
    // chnn �豸ͨ��
    // idx �����к� �μ� "proto/l_media.h" l_md_idx_e

    int proto_main = L_NET_PROTO_MAIN(protocol);
    int proto_sub = L_NET_PROTO_SUB(protocol);

    if (p_data->ver == L_MD_F_VER)
    {
        printf("fmt:%d,type:%d,len:%d\n", p_data->f_v1.fmt, p_data->f_v1.v_type, p_data->f_v1.len);

        if (L_FMT_H264 == p_data->f_v1.fmt)
        {
            if (L_MVT_I == p_data->f_v1.v_type)
            {
                // �ؼ�֡
            }
            else
            {
                // �ǹؼ�֡
            }

            // H264
            int h264_len = p_data->f_v1.len;
            unsigned char* p_h264 = p_data->p_buf + p_data->start;

            printf("h264 [%x,%x,%x,%x,%x]\n", p_h264[0], p_h264[1], p_h264[2], p_h264[3], p_h264[4]);
        }
        else if (L_FMT_H265 == p_data->f_v1.fmt)
        {

        }
        else if (L_FMT_AUDIO_B < p_data->f_v1.fmt && p_data->f_v1.fmt < L_FMT_AUDIO_E)
        {

        }
        else if (L_FMT_PIC_B < p_data->f_v1.fmt && p_data->f_v1.fmt < L_FMT_PIC_E)
        {

        }
    }

    return 0;
}

static int request_stream(id, chnn, idx)
{
    // ��������
    char req_stream[128] = { 0 };
    snprintf(req_stream, 124, T_REQ_STREAM_STR, chnn, idx);

    char* p_res = NULL;
    int ret = l_sdk_request(id, req_stream, &p_res);
    printf("(%s.%d)ret=%d,res=%s\n", __FILE__, __LINE__, ret, (NULL != p_res) ? p_res : "error!");

    if (NULL != p_res)
    {
        l_sdk_free(p_res);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    // win socket����
    wsa_startup();

    // sdk��ʼ��
    int ret = l_sdk_init("");
    printf("(%s.%d)sdk init,ret=%d\n", __FILE__, __LINE__, ret);


    // ���ý�����ݼ�����
    l_sdk_md_add_listener("my listener 1", cb_sdk_media, NULL);


    // �����¼
    char req_login[128] = { 0 };
    snprintf(req_login, 124, T_LOGIN_STR, "192.168.1.247", 80, "admin", "123456");

    int id = 0;
    ret = l_sdk_login(&id, req_login);
    printf("(%s.%d)sdk login,ret=%d,id=%d\n", __FILE__, __LINE__, ret, id);

    if (0 == ret)
    {
        // ��¼�ɹ�, ��������
        request_stream(id, 0, 0);

        // 
        for (int i = 0; i < 10; i++)
        {
            Sleep(1000);
        }
    }

    // ����ǳ�
    l_sdk_logout(id);

    // sdk�˳�
    l_sdk_quit();
    return 0;
}
