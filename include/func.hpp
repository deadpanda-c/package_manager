#pragma once
#define URL "http://localhost:8000/"

class Kekpm {
    public:
        Kekpm(char **, int);
        ~Kekpm(void);
        void display_help(void);
        int exec_cmd(void);
    private:
        std::string cmd;
};

int parse_args(int, char **);
