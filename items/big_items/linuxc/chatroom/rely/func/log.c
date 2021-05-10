// void LOG(char *filename, FORMAT, ...)
// {
//     if (WRITE_LOG)
//     {
//         char *t = strrchr(__FILE__, '/');
//         int fp = open(filename, O_WRONLY | O_APPEND | O_CREAT | O_NONBLOCK, 0644);
//         struct tm *pt;
//         time_t timer;
//         time(&timer);
//         pt = localtime(&timer);
//         char logstring[1024];
//         memset(logstring, 0, sizeof(logstring));
//         sprintf(logstring,
//                 "[%02d:%02d][%s][%3d]" FORMAT
//                 "\r\n",
//                 pt->tm_min,
//                 pt->tm_sec,
//                 __FUNCTION__,
//                 __LINE__,
//                 ##__VA_ARGS__);
//         write(fp, logstring, strlen(logstring));
//         close(fp);
//     }
// }