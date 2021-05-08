#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <string.h>
#include <time.h>

int rec = 0, all = 0;
int lb = -1, ub = -1;
int day = -1;

void visit(const char*);

int isDir(const char* path)
{       
        struct stat st;
        if(stat(path, &st) == 0)
                if(S_ISDIR(st.st_mode)) return 1;
        return 0;
}

int getFileSize(const char* path) //is file
{
        struct stat stFile;
        if(stat(path, &stFile) == 0) return (int)stFile.st_size;
}

int getFileModTime(const char* path)
{
        struct stat stFile;
        if(stat(path, &stFile) == 0) return (int)stFile.st_mtime;
}

void visitFile(const char* path) // is file
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

void visitDir(const char* path)
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

                if(*(char*)(file->d_name) == '.')
                {
                        if(all && lb == -1 && ub == -1 && day == -1) visitFile(filepath);
                }
                else
                {
                        if(isDir(filepath))
                        {
                                if(lb == -1 && ub == -1 && day == -1) printf("%s\n", filepath);
                                if(rec) visitDir(filepath);
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

char optarg[255];
int mygetopt(int argc, char** argv, int cnt)
{
        if(cnt >= argc) return -1;

        if(strcmp(argv[cnt], "-r") == 0) return 'r';
        else if(strcmp(argv[cnt], "-a") == 0) return 'a';
        else if(strcmp(argv[cnt], "-l") == 0)
        {
                strcpy(optarg, argv[cnt + 1]);
                return 'l';
        }
        else if(strcmp(argv[cnt], "-h") == 0)
        {
                strcpy(optarg, argv[cnt + 1]);
                return 'h';
        }
        else if(strcmp(argv[cnt], "-m") == 0)
        {
                strcpy(optarg, argv[cnt + 1]);
                return 'm';
        }
        else if(strcmp(argv[cnt], "--") == 0) return -1;
        else return -1;
}

int main(int argc, char** argv)
{
        int argv_cnt = 1;
        while(1)
        {
                int opt_idx = 0;
                int c = mygetopt(argc, argv, argv_cnt);

                if(c == -1) break;
  
                ++argv_cnt;

                switch(c)
                {
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
                }
        }

        if(argv_cnt == argc) //default local addr
        {
                visitDir(".");
        }
        else //typed addr
        {
                for(int i = argv_cnt; i < argc; ++i)
                {
                        if(strcmp(argv[i], "--") == 0) continue;
                        visit(argv[i]);
                }
        }
}

