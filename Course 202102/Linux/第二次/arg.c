#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rec = 0, all = 0;
int lb = -1, ub = -1;
int day = -1;

void visit(const char*);

int isDir(const char* path) //判断该路径是否对应一个目录
{       
        struct stat st;
        if(stat(path, &st) == 0)
                if(S_ISDIR(st.st_mode)) return 1;
        return 0;
}

int getFileSize(const char* path) //获取文件大小
{
        struct stat stFile;
        if(stat(path, &stFile) == 0) return (int)stFile.st_size;
}

int getFileModTime(const char* path) //获取文件修改时间
{
        struct stat stFile;
        if(stat(path, &stFile) == 0) return (int)stFile.st_mtime;
}

void visitFile(const char* path) //访问一个文件
{
        int size = getFileSize(path);
        int able = 1;
        if(lb != -1 && size <= lb) able = 0;
        if(ub != -1 && size >= ub) able = 0;
        if(day != -1)
        {       
                int mtime = getFileModTime(path);
                time_t now;
                time(&now);
                if(now - day * 86400 > mtime) able = 0;
        }
        if(able && size != -1) printf("%s\n", path);
}

void visitDir(const char* path) //访问一个目录
{
        struct stat st;
        DIR* dir;
        struct dirent* file;
        char filepath[255];

        dir = opendir(path);
        if(dir == NULL) return;

        while((file = readdir(dir)) != NULL)
        {
                memset(filepath, 0, 255);
                strcat(filepath, path);
                strcat(filepath, "/");
                strcat(filepath, file->d_name);

                if(*(char*)(file->d_name) == '.') //第一个char为'.'
                {
                        if(all && lb == -1 && ub == -1 && day == -1) visitFile(filepath);
                }
                else
                {
                        if(isDir(filepath))
                        {
                                if(lb == -1 && ub == -1 && day == -1) printf("%s\n", filepath);
                                if(rec) visitDir(filepath); //递归访问子目录
                        }
                        else visitFile(filepath);
                }
        }
}

void visit(const char* path)
{
        if(isDir(path)) visitDir(path);
        else visitFile(path);
}

int main(int argc, char** argv)
{
        static struct option long_options[] =
        {
                {"recursive", no_argument, 0, 'r'},
                {"all", no_argument, 0, 'a'},
                {"low", required_argument, 0, 'l'},
                {"high", required_argument, 0, 'h'},
                {"modtime", required_argument, 0, 'm'},
                {NULL, 0, NULL, 0}
        };

        int argv_cnt = 1;
        while(1)
        {
                int opt_idx = 0;
                int c = getopt_long(argc, argv, "ral:h:m:", long_options, &opt_idx);
                if(c == -1) break;

                ++argv_cnt;

                switch(c)
                {
                        case 0:
                                printf("long option %s", long_options[opt_idx].name);
                                if(optarg) printf(" with arg %s", optarg);
                                printf("\n");
                                break;

                        case 'r':
                                rec = 1;
                                break;

                        case 'a':
                                all = 1;
                                break;

                        case 'l':
                                lb = atoi(optarg);
                                ++argv_cnt;
                                break;

                        case 'h':
                                ub = atoi(optarg);
                                ++argv_cnt;
                                break;

                        case 'm':
                                day = atoi(optarg);
                                ++argv_cnt;
                                break;

                        default:
                                printf("default %s\n", long_options[opt_idx].name);
                                break;
                }
        }

        if(argv_cnt == argc) //默认路径为
        {
                visitDir(".");
        }
        else //遍历指定的目录
        {
                for(int i = argv_cnt; i < argc; ++i)
                {
                        if(strcmp(argv[i], "--") == 0) continue;
                        visit(argv[i]);
                }
        }
}


