#include "netio.h"

ssize_t readn(int fd, void *buf, size_t len)
{
    ssize_t nread = 0;
    char *ptr = buf;
    int isagain = 0;
    while (isagain)
    {
        if ((nread = read(fd, ptr, len - nread)) < 0)
        {
            if (errno == EINTR)
            {
                isagain = 1; //中断继续读
            }
            else
                return -1;
        }
        else if (nread == 0)
        {
            return -1;
        }
        ptr += nread; //继续读
    }
    return len;
}

ssize_t writen(int fd, const void *buf, size_t len)
{
    ssize_t nwrite = 0;
    char *ptr = buf;
    int isagain = 0;
    while (isagain)
    {
        if ((nwrite = write(fd, ptr, len - nwrite)) < 0)
        {
            if (errno == EINTR)
            {
                isagain = 1; //中断继续读
            }
            else
                return -1;
        }
        else if (nwrite == 0)
        {
            return -1;
        }
        ptr += nwrite; //继续读
    }
    return len;
}

// ssize_t readline(int fd, void *buf, size_t len)
// {
//     ssize_t nread = 0;
//     char *ptr = buf;
//     int isagain = 0, i;
//     for (i = 0; i < len; i++)
//     {
//         if ((nread = (fd, ptr, 1)) < 0)
//         {
//             if (errno == EINTR)
//                 isagain = 1;
//             else
//                 return -1;
//         }
//         else if (nread == 1)
//         {
//             if (*ptr != 0)
//             {
//                 ptr++;
//                 nread = 0;
//             }
//             else
//             {

//             }
//         }
//         else
//         {
//         }
//     }
//     return len;
// }